// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENBUTTON_H
#define MOAIGWENBUTTON_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenButton : public MOAIGwenControl<Gwen::Controls::Button>, public MOAIGwenEventButton
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenButton)

	//----------------------------------------------------------------//
	MOAIGwenButton()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Button));
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
