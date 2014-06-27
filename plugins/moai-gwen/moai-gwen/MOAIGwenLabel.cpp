// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenLabel.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
MOAIGwenLabel::MOAIGwenLabel()
{
	RTTI_BEGIN
		RTTI_EXTEND(MOAIGwenBase)
	RTTI_END

	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
}

//----------------------------------------------------------------//
MOAIGwenLabel::~MOAIGwenLabel() 
{

}

void MOAIGwenLabel::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaClass(state);
	MOAIGwenRegisterLabel::RegisterLuaClass(state);
}

void MOAIGwenLabel::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaFuncs(state);
	MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
}