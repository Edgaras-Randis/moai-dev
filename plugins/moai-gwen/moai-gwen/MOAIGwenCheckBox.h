// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCheckBox_H
#define MOAIGwenCheckBox_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenCheckBox : public MOAIGwenControl<Gwen::Controls::CheckBox>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenCheckBox)

	//----------------------------------------------------------------//
	MOAIGwenCheckBox()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Button));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::CheckBox));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterLabel::RegisterLuaClass(state);
		MOAIGwenRegisterButton::RegisterLuaClass(state);
		MOAIGwenRegisterCheckBox::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
		MOAIGwenRegisterButton::RegisterLuaFuncs(state);
		MOAIGwenRegisterCheckBox::RegisterLuaFuncs(state);
	}
};

#endif
