// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenDockBase.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
MOAIGwenDockBase::MOAIGwenDockBase()
{
	RTTI_BEGIN
		RTTI_EXTEND(MOAIGwenBase)
	RTTI_END

	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::DockBase));
}

//----------------------------------------------------------------//
MOAIGwenDockBase::~MOAIGwenDockBase() 
{

}

void MOAIGwenDockBase::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaClass(state);
	MOAIGwenRegisterDockBase::RegisterLuaClass(state);
}

void MOAIGwenDockBase::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaFuncs(state);
	MOAIGwenRegisterDockBase::RegisterLuaFuncs(state);
}