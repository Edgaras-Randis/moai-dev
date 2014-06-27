// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenCollapsibleCategory.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
MOAIGwenCollapsibleCategory::MOAIGwenCollapsibleCategory()
{
	RTTI_BEGIN
		RTTI_EXTEND(MOAIGwenBase)
	RTTI_END

	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::CollapsibleCategory));
}

//----------------------------------------------------------------//
MOAIGwenCollapsibleCategory::~MOAIGwenCollapsibleCategory() 
{

}

void MOAIGwenCollapsibleCategory::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaClass(state);
	MOAIGwenRegisterCollapsibleCategory::RegisterLuaClass(state);
}

void MOAIGwenCollapsibleCategory::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaFuncs(state);
	MOAIGwenRegisterCollapsibleCategory::RegisterLuaFuncs(state);
}