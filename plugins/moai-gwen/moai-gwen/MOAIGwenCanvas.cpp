// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRender.h>
#include <moai-gwen/MOAIGwenSkin.h>
#include <moai-gwen/MOAIGwenSkinTexture.h>
#include <moai-gwen/MOAIGwenCanvas.h>

//================================================================//
// lua
//================================================================//

int MOAIGwenCanvas::_init(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenCanvas, "UU");

	self->Skin.Set(*self, state.GetLuaObject<MOAIGwenSkin>(2, true));

	if (!self->Skin)
	{
		return 0;
	}

	self->SetSkin(self->Skin);

	self->SetSize(960, 640);
	self->SetDrawBackground(true);
	self->SetBackgroundColor(Gwen::Color(150, 170, 170, 255));

	self->pUnitTest = new UnitTest(self);
	self->pUnitTest->SetPos(0, 0);

	return 0;
}

//================================================================//
// MOAIGwenCanvas
//================================================================//

//----------------------------------------------------------------//
MOAIGwenCanvas::MOAIGwenCanvas() : Canvas(NULL), pUnitTest(NULL)
 {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIProp )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenCanvas::~MOAIGwenCanvas() 
{
	Skin.Set(*this, 0);
}

void MOAIGwenCanvas::RegisterLuaClass(MOAILuaState& state)
{
	MOAIProp::RegisterLuaClass(state);

	luaL_Reg regTable[] = 
	{
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

void MOAIGwenCanvas::RegisterLuaFuncs(MOAILuaState& state)
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

int MOAIGwenCanvas::_render(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenCanvas, "U");

	if (!self->Skin)
	{
		return 0;
	}

	self->RenderCanvas();

	return 0;
}
