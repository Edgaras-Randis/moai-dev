// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenTextBoxPassword_H
#define MOAIGwenTextBoxPassword_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenTextBoxPassword : public MOAIGwenControl<Gwen::Controls::PasswordTextBox>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenTextBoxPassword)
	
	//----------------------------------------------------------------//
	MOAIGwenTextBoxPassword()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TextBox));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::PasswordTextBox));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterLabel::RegisterLuaClass(state);
		MOAIGwenRegisterTextBox::RegisterLuaClass(state);
		MOAIGwenRegisterTextBoxPassword::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
		MOAIGwenRegisterTextBox::RegisterLuaFuncs(state);
		MOAIGwenRegisterTextBoxPassword::RegisterLuaFuncs(state);
	}
};

#endif
