// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenRadioButtonController_H
#define MOAIGwenRadioButtonController_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

template<typename T>
class MOAIGwenRadioButtonControllerBase : public MOAIGwenControlBase<T>
{
public:
	MOAIGwenRadioButtonControllerBase(Gwen::Controls::Base* pParent, const Gwen::String & Name = "", MOAIGwenBase* Base = NULL) : MOAIGwenControlBase<T>(pParent, Name, Base)
	{

	}

	Gwen::Controls::LabeledRadioButton* AddOption(const Gwen::UnicodeString & strText, const Gwen::String & strOptionName)
	{
		MOAIGwenRadioButtonWithLabel* button = new MOAIGwenRadioButtonWithLabel();
		button->CreateControl(Cannary);
		Gwen::Controls::LabeledRadioButton* lrb = button->Control();
		lrb->SetName(strOptionName);
		lrb->GetLabel()->SetText(strText);
		lrb->GetRadioButton()->onChecked.Add(this, &MOAIGwenRadioButtonControllerBase<T>::OnRadioClicked);
		lrb->Dock(Gwen::Pos::Top);
		lrb->SetMargin(Gwen::Margin(0, 1, 0, 1));
		lrb->SetKeyboardInputEnabled(false);
		lrb->SetTabable(false);
		Invalidate();
		return lrb;
	}

};

class MOAIGwenRadioButtonController : public MOAIGwenControl<Gwen::Controls::RadioButtonController, MOAIGwenRadioButtonControllerBase>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenRadioButtonController)

	//----------------------------------------------------------------//
	MOAIGwenRadioButtonController()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::RadioButtonController));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterRadioButtonController::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterRadioButtonController::RegisterLuaFuncs(state);
	}
};

#endif
