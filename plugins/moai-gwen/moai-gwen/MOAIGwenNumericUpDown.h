// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenNumericUpDown_H
#define MOAIGwenNumericUpDown_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenNumericUpDown : public MOAIGwenControl<Gwen::Controls::NumericUpDown>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenNumericUpDown)

	//----------------------------------------------------------------//
	MOAIGwenNumericUpDown()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TextBox));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TextBoxNumeric));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::NumericUpDown));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterLabel::RegisterLuaClass(state);
		MOAIGwenRegisterTextBox::RegisterLuaClass(state);
		MOAIGwenRegisterTextBoxNumeric::RegisterLuaClass(state);
		MOAIGwenRegisterNumericUpDown::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
		MOAIGwenRegisterTextBox::RegisterLuaFuncs(state);
		MOAIGwenRegisterTextBoxNumeric::RegisterLuaFuncs(state);
		MOAIGwenRegisterNumericUpDown::RegisterLuaFuncs(state);
	}
};

#endif
