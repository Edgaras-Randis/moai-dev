// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenTextBoxNumeric_H
#define MOAIGwenTextBoxNumeric_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenTextBoxNumeric : public MOAIGwenControl<Gwen::Controls::TextBoxNumeric>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenTextBoxNumeric)
	
	//----------------------------------------------------------------//
	MOAIGwenTextBoxNumeric()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TextBox));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TextBoxNumeric));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterLabel::RegisterLuaClass(state);
		MOAIGwenRegisterTextBox::RegisterLuaClass(state);
		MOAIGwenRegisterTextBoxNumeric::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
		MOAIGwenRegisterTextBox::RegisterLuaFuncs(state);
		MOAIGwenRegisterTextBoxNumeric::RegisterLuaFuncs(state);
	}
};

#endif
