// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenTabButton_H
#define MOAIGwenTabButton_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenTabButton : public MOAIGwenControl<Gwen::Controls::TabButton>, public MOAIGwenEventButton
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenTabButton)

	//----------------------------------------------------------------//
	MOAIGwenTabButton()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Button));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TabButton));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterButton::RegisterLuaClass(state);
		MOAIGwenEventButton::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterButton::RegisterLuaFuncs(state);
		MOAIGwenEventButton::RegisterLuaFuncs(state);
	}

	void RegisterEvent()
	{
		MOAIGwenEventButton::SetBase(this);
		MOAIGwenEventButton::RegisterEvents();
	}
};

#endif
