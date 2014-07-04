// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCheckBoxWithLabel_H
#define MOAIGwenCheckBoxWithLabel_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

template<typename T>
class MOAIGwenCheckBoxWithLabelBase : public MOAIGwenControlBase<T>
{
public:
	MOAIGwenCheckBoxWithLabelBase(Gwen::Controls::Base* pParent, const Gwen::String & Name = "", MOAIGwenBase* Base = NULL) : MOAIGwenControlBase<T>(pParent, Name, Base)
	{
		
	}

	virtual void Override()
	{
		MOAIGwenCheckBox* box = new MOAIGwenCheckBox();
		box->CreateControl(Cannary);
		m_Checkbox = box->Control();
		m_Checkbox->Dock(Gwen::Pos::Left);
		m_Checkbox->SetMargin(Gwen::Margin(0, 2, 2, 2));
		m_Checkbox->SetTabable(false);

		MOAIGwenLabelClickable* label = new MOAIGwenLabelClickable();
		label->CreateControl(Cannary);
		m_Label = label->Control();
		m_Label->Dock(Gwen::Pos::Fill);
		m_Label->onPress.Add(m_Checkbox, &Gwen::Controls::CheckBox::OnPress);
		m_Label->SetTabable(false);

		SetTabable(false);
	}
};

class MOAIGwenCheckBoxWithLabel : public MOAIGwenControl<Gwen::Controls::CheckBoxWithLabel, MOAIGwenCheckBoxWithLabelBase>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenCheckBoxWithLabel)

	//----------------------------------------------------------------//
	MOAIGwenCheckBoxWithLabel()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::CheckBoxWithLabel));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterCheckBoxWithLabel::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterCheckBoxWithLabel::RegisterLuaFuncs(state);
	}
};

#endif
