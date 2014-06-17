// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRenderer.h>
#include <moai-gwen/MOAIGwenSkin.h>
#include <moai-gwen/MOAIGwenSkinTexture.h>
#include <moai-gwen/MOAIGwen.h>

//================================================================//
// lua
//================================================================//

int MOAIGwen::_init(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwen, "UU");

	self->Renderer = state.GetLuaObject<MOAIGwenRenderer>(2, true);

	if (!self->Renderer)
	{
		return 0;
	}

	self->LuaRetain(self->Renderer);

	self->Skin = new MOAIGwenSkin();
	self->Skin->SetRender(self->Renderer);
	self->LuaRetain(self->Skin);

	self->Skin->Init(state.GetLuaObject<MOAIGwenSkinTexture>(3, true));

	self->Canvas = new Gwen::Controls::Canvas(self->Skin);
	self->Canvas->SetSize(960, 640);
	self->Canvas->SetDrawBackground(true);
	self->Canvas->SetBackgroundColor(Gwen::Color(150, 170, 170, 125));

	self->pUnitTest = new UnitTest(self->Canvas);
	self->pUnitTest->SetPos(0, 0);

	return 0;
}

//================================================================//
// MOAIGwen
//================================================================//

//----------------------------------------------------------------//
MOAIGwen::MOAIGwen() : Skin(NULL), Renderer(NULL), Canvas(NULL), pUnitTest(NULL)
 {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIProp )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwen::~MOAIGwen() 
{
}

void MOAIGwen::RegisterLuaClass(MOAILuaState& state)
{
	MOAIProp::RegisterLuaClass(state);

	luaL_Reg regTable[] = 
	{
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

void MOAIGwen::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIProp::RegisterLuaFuncs(state);

	luaL_Reg regTable[] =
	{
		{ "init", _init },
		{ "render", _render },
		{ NULL, NULL }
	};
	
	luaL_register(state, 0, regTable);
}

int MOAIGwen::_render(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwen, "U");

	if (!self->Canvas)
	{
		return 0;
	}

	self->Canvas->RenderCanvas();

	return 0;
}
