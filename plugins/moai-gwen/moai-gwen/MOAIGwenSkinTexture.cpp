// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenSkinTexture.h>

//================================================================//
// lua
//================================================================//

int MOAIGwenSkinTexture::_load(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenSkinTexture, "US");

	STLString fileName = ZLFileSys::GetAbsoluteFilePath(state.GetValue<cc8*>(2, ""));

	self->Image.Load(fileName, MOAIImageTransform::TRUECOLOR | state.GetValue<u32>(3, 0));

	self->Gwen::Texture::name = fileName;
	self->Gwen::Texture::failed = true;
	self->Gwen::Texture::width  = 0;
	self->Gwen::Texture::height = 0;
	self->Gwen::Texture::data   = NULL;

	if (!self->Image.IsOK())
	{
		return 0;
	}

	self->Init(self->Image, fileName);

	self->Gwen::Texture::name = fileName;
	self->Gwen::Texture::failed = false;
	self->Gwen::Texture::width = self->MOAITexture::GetWidth();
	self->Gwen::Texture::height = self->MOAITexture::GetHeight();
	self->Gwen::Texture::data = (void*)dynamic_cast<MOAITexture*>(self);

	return 0;
}

//================================================================//
// MOAIGwenTexture
//================================================================//

//----------------------------------------------------------------//
MOAIGwenSkinTexture::MOAIGwenSkinTexture()
 {
	RTTI_BEGIN
		RTTI_EXTEND(MOAITexture)
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenSkinTexture::~MOAIGwenSkinTexture() 
{

}

void MOAIGwenSkinTexture::RegisterLuaClass(MOAILuaState& state)
{
	MOAITexture::RegisterLuaClass(state);

	luaL_Reg regTable[] = 
	{
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

void MOAIGwenSkinTexture::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAITexture::RegisterLuaFuncs(state); //Don't register load function

	luaL_Reg regTable[] =
	{
		{ "load", _load },
		{ NULL, NULL }
	};
	
	luaL_register(state, 0, regTable);
}

Gwen::Color MOAIGwenSkinTexture::GetPixelColor(int x, int y, const Gwen::Color& base)
{
	if (!Image.IsOK())
	{
		return base;
	}

	u32 pixel = Image.GetPixel(x, y);

	return Gwen::Color(pixel & 0xFF, (pixel >> 8) & 0xFF, (pixel >> 16) & 0xFF, (pixel >> 24) & 0xFF);
}

void MOAIGwenSkinTexture::Release()
{
	MOAITexture::Release(); //fix for ambiguity on MOAISharedPtr, because Gwen::Texture also has Release method
}
