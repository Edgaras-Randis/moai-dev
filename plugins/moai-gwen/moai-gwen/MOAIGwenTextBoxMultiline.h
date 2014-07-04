// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenTextBoxMultiline_H
#define MOAIGwenTextBoxMultiline_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenTextBoxMultiline : public MOAIGwenControl<Gwen::Controls::TextBoxMultiline>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenTextBoxMultiline)
	
	//----------------------------------------------------------------//
	MOAIGwenTextBoxMultiline()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TextBox));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TextBoxMultiline));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterLabel::RegisterLuaClass(state);
		MOAIGwenRegisterTextBox::RegisterLuaClass(state);
		MOAIGwenRegisterTextBoxMultiline::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
		MOAIGwenRegisterTextBox::RegisterLuaFuncs(state);
		MOAIGwenRegisterTextBoxMultiline::RegisterLuaClass(state);
	}
};

#endif
