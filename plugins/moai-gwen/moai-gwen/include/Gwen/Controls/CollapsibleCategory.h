/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_COLLAPSIBLECATEGORY_H
#define GWEN_CONTROLS_COLLAPSIBLECATEGORY_H

#include "Gwen/Controls/Base.h"
#include "Gwen/Controls/Button.h"
#include "Gwen/Gwen.h"
#include "Gwen/Skin.h"


namespace Gwen
{
	namespace Controls
	{
		class CollapsibleList;

		class GWEN_EXPORT CategoryButton : public Button
		{
			GWEN_CONTROL_INLINE(CategoryButton, Button)
			{
				SetAlignment(Pos::Left | Pos::CenterV);
				m_bAlt = false;
			}

			virtual void Render(Skin::Base* skin)
			{
				if (m_bAlt)
				{
					if (IsDepressed() || GetToggleState()) { skin->GetRender()->SetDrawColor(skin->Colors.Category.LineAlt.Button_Selected); }
					else if (IsHovered()) { skin->GetRender()->SetDrawColor(skin->Colors.Category.LineAlt.Button_Hover); }
					else { skin->GetRender()->SetDrawColor(skin->Colors.Category.LineAlt.Button); }
				}
				else
				{
					if (IsDepressed() || GetToggleState()) { skin->GetRender()->SetDrawColor(skin->Colors.Category.Line.Button_Selected); }
					else if (IsHovered()) { skin->GetRender()->SetDrawColor(skin->Colors.Category.Line.Button_Hover); }
					else { skin->GetRender()->SetDrawColor(skin->Colors.Category.Line.Button); }
				}

				skin->GetRender()->DrawFilledRect(this->GetRenderBounds());
			}

			void UpdateColours()
			{
				if (m_bAlt)
				{
					if (IsDepressed() || GetToggleState())	{ return SetTextColor(GetSkin()->Colors.Category.LineAlt.Text_Selected); }

					if (IsHovered())							{ return SetTextColor(GetSkin()->Colors.Category.LineAlt.Text_Hover); }

					return SetTextColor(GetSkin()->Colors.Category.LineAlt.Text);
				}

				if (IsDepressed() || GetToggleState())	{ return SetTextColor(GetSkin()->Colors.Category.Line.Text_Selected); }

				if (IsHovered())							{ return SetTextColor(GetSkin()->Colors.Category.Line.Text_Hover); }

				return SetTextColor(GetSkin()->Colors.Category.Line.Text);
			}

			bool m_bAlt;
		};

		class GWEN_EXPORT CategoryHeaderButton : public Button
		{
			GWEN_CONTROL_INLINE(CategoryHeaderButton, Button)
			{
				SetShouldDrawBackground(false);
				SetIsToggle(true);
				SetAlignment(Pos::Center);
			}

			void UpdateColours()
			{
				if (IsDepressed() || GetToggleState())	{ return SetTextColor(GetSkin()->Colors.Category.Header_Closed); }

				return SetTextColor(GetSkin()->Colors.Category.Header);
			}

		};

		class GWEN_EXPORT CollapsibleCategory : public Gwen::Controls::Base
		{
			public:

				GWEN_CONTROL( CollapsibleCategory, Gwen::Controls::Base );

				virtual void Render( Skin::Base* skin );

				virtual void SetText( const TextObject & text );

				virtual Button* Add( const TextObject & name );

				virtual void PostLayout( Skin::Base* /*skin*/ );

				virtual void SetList( Controls::CollapsibleList* p ) { m_pList = p; }

				virtual void UnselectAll();
				virtual Button* GetSelected();

			public:

				Gwen::Event::Caller	onSelection;

			protected:

				virtual void OnSelection( Controls::Base* control );

				Controls::Button*			m_pButton;
				Controls::CollapsibleList*	m_pList;
		};

	}
}
#endif
