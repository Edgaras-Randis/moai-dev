// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenCategoryButton.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
MOAIGwenCategoryButton::MOAIGwenCategoryButton()
{
	RTTI_BEGIN
		RTTI_EXTEND(MOAIGwenBase)
	RTTI_END

	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Button));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::CategoryButton));
}

//----------------------------------------------------------------//
MOAIGwenCategoryButton::~MOAIGwenCategoryButton() 
{

}

void MOAIGwenCategoryButton::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaClass(state);
	MOAIGwenRegisterButton::RegisterLuaClass(state);
	MOAIGwenEventButton::RegisterLuaClass(state);
}

void MOAIGwenCategoryButton::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaFuncs(state);
	MOAIGwenRegisterButton::RegisterLuaFuncs(state);
	MOAIGwenEventButton::RegisterLuaFuncs(state);
}

void MOAIGwenCategoryButton::RegisterEvent()
{
	MOAIGwenEventButton::SetBase(this);
	MOAIGwenEventButton::RegisterEvents();
}
