// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenRadioButtonWithLabel_H
#define MOAIGwenRadioButtonWithLabel_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

template<typename T>
class MOAIGwenRadioButtonWithLabelBase : public MOAIGwenControlBase<T>
{
public:
	MOAIGwenRadioButtonWithLabelBase(Gwen::Controls::Base* pParent, const Gwen::String & Name = "", MOAIGwenBase* Base = NULL) : MOAIGwenControlBase<T>(pParent, Name, Base)
	{
		
	}

	virtual void Override()
	{
		MOAIGwenRadioButton* button = new MOAIGwenRadioButton();
		button->CreateControl(Cannary);
		m_RadioButton = button->Control();
		m_RadioButton->Dock( Gwen::Pos::Left );
		m_RadioButton->SetMargin( Gwen::Margin( 0, 2, 2, 2 ) );
		m_RadioButton->SetTabable( false );
		m_RadioButton->SetKeyboardInputEnabled( false );

		MOAIGwenLabelClickable* label = new MOAIGwenLabelClickable();
		label->CreateControl(Cannary);
		m_Label = label->Control();
		m_Label->SetAlignment( Gwen::Pos::CenterV | Gwen::Pos::Left );
		m_Label->SetText( "Radio Button" );
		m_Label->Dock(Gwen::Pos::Fill );
		m_Label->onPress.Add( m_RadioButton, &Gwen::Controls::CheckBox::OnPress );
		m_Label->SetTabable( false );
		m_Label->SetKeyboardInputEnabled( false );
	}
};

class MOAIGwenRadioButtonWithLabel : public MOAIGwenControl<Gwen::Controls::LabeledRadioButton, MOAIGwenRadioButtonWithLabelBase>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenRadioButtonWithLabel)

	//----------------------------------------------------------------//
	MOAIGwenRadioButtonWithLabel()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::LabeledRadioButton));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterRadioButtonWithLabel::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterRadioButtonWithLabel::RegisterLuaFuncs(state);
	}
};

#endif
