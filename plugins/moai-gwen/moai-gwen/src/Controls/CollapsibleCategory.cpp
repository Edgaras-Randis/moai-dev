/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#include "Gwen/Controls/CollapsibleCategory.h"
#include "Gwen/Controls/CollapsibleList.h"

using namespace Gwen;
using namespace Gwen::Controls;

GWEN_CONTROL_CONSTRUCTOR( CollapsibleCategory )
{
	m_pList = NULL;
	m_pButton = new CategoryHeaderButton( this );
	m_pButton->SetText( "Category Title" );
	m_pButton->Dock( Pos::Top );
	m_pButton->SetHeight( 20 );
	SetPadding( Padding( 1, 0, 1, 5 ) );
	SetSize( 512, 512 );
}

Button* CollapsibleCategory::Add( const TextObject & name )
{
	CategoryButton* pButton = new CategoryButton( this );
	pButton->SetText( name );
	pButton->Dock( Pos::Top );
	pButton->SizeToContents();
	pButton->SetSize( pButton->Width() + 4, pButton->Height() + 4 );
	pButton->SetPadding( Padding( 5, 2, 2, 2 ) );
	pButton->onPress.Add( this, &ThisClass::OnSelection );
	return pButton;
}

void CollapsibleCategory::OnSelection( Controls::Base* control )
{
	CategoryButton* pChild = gwen_cast<CategoryButton> ( control );

	if ( !pChild ) { return; }

	if ( m_pList )
	{
		m_pList->UnselectAll();
	}
	else
	{
		UnselectAll();
	}

	pChild->SetToggleState( true );
	onSelection.Call( this );
}

void CollapsibleCategory::Render( Skin::Base* skin )
{
	skin->DrawCategoryInner( this, m_pButton->GetToggleState() );
}

void CollapsibleCategory::SetText( const TextObject & text )
{
	m_pButton->SetText( text );
}

void CollapsibleCategory::UnselectAll()
{
	Base::List & children = GetChildren();

	for ( Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
	{
		CategoryButton* pChild = gwen_cast<CategoryButton> ( *iter );

		if ( !pChild ) { continue; }

		pChild->SetToggleState( false );
	}
}

void CollapsibleCategory::PostLayout( Skin::Base* /*skin*/ )
{
	if ( m_pButton->GetToggleState() )
	{
		SetHeight( m_pButton->Height() );
	}
	else
	{
		SizeToChildren( false, true );
	}

	Base::List & children = GetChildren();
	bool b = true;

	for ( Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
	{
		CategoryButton* pChild = gwen_cast<CategoryButton> ( *iter );

		if ( !pChild ) { continue; }

		pChild->m_bAlt = b;
		pChild->UpdateColours();
		b = !b;
	}
};

Button* CollapsibleCategory::GetSelected()
{
	Base::List & children = GetChildren();

	for ( Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
	{
		CategoryButton* pChild = gwen_cast<CategoryButton> ( *iter );

		if ( !pChild ) { continue; }

		if ( pChild->GetToggleState() )
		{ return pChild; }
	}

	return NULL;
}