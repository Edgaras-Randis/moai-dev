// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenCollapsibleCategory.h>
#include <moai-gwen/MOAIGwenCollapsibleList.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
MOAIGwenCollapsibleList::MOAIGwenCollapsibleList()
{
	RTTI_BEGIN
		RTTI_EXTEND(MOAIGwenBase)
	RTTI_END

	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::ScrollControl));
	RTTI_CAST.insert(STRINGIFY(Gwen::Controls::CollapsibleList));
}

//----------------------------------------------------------------//
MOAIGwenCollapsibleList::~MOAIGwenCollapsibleList() 
{

}

void MOAIGwenCollapsibleList::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaClass(state);
	MOAIGwenRegisterCollapsibleList::RegisterLuaClass(state);
}

void MOAIGwenCollapsibleList::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenControl::RegisterLuaFuncs(state);
	MOAIGwenRegisterCollapsibleList::RegisterLuaFuncs(state);
}