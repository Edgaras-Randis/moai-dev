// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenTabControl.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
MOAIGwenTabControl::MOAIGwenTabControl()
{
	RTTI_BEGIN
		RTTI_EXTEND(MOAIGwenBase)
	RTTI_END

	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TabControl));
}

//----------------------------------------------------------------//
MOAIGwenTabControl::~MOAIGwenTabControl() 
{

}

void MOAIGwenTabControl::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaClass(state);
	MOAIGwenRegisterTabControl::RegisterLuaClass(state);
}

void MOAIGwenTabControl::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaFuncs(state);
	MOAIGwenRegisterTabControl::RegisterLuaFuncs(state);
}
