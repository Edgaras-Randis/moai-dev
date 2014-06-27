// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenButton.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
MOAIGwenButton::MOAIGwenButton()
{
	RTTI_BEGIN
		RTTI_EXTEND(MOAIGwenBase)
	RTTI_END

	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Button));
}

//----------------------------------------------------------------//
MOAIGwenButton::~MOAIGwenButton() 
{

}

void MOAIGwenButton::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaClass(state);
	MOAIGwenRegisterButton::RegisterLuaClass(state);
	MOAIGwenEventButton::RegisterLuaClass(state);
}

void MOAIGwenButton::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaFuncs(state);
	MOAIGwenRegisterButton::RegisterLuaFuncs(state);
	MOAIGwenEventButton::RegisterLuaFuncs(state);
}

void MOAIGwenButton::RegisterEvent()
{
	MOAIGwenEventButton::SetBase(this);
	MOAIGwenEventButton::RegisterEvents();
}
