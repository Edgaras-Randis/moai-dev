// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRenderer.h>
#include <moai-gwen/MOAIGwenSkinTexture.h>

//================================================================//
// lua
//================================================================//

int MOAIGwenRenderer::_setLoadTexture(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenRenderer, "U")

	self->LoadTextureCallback.SetRef(*self, state, 2);

	return 0;
}

int MOAIGwenRenderer::_setFreeTexture(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenRenderer, "U")

	self->FreeTextureCallback.SetRef(*self, state, 2);

	return 0;
}

//================================================================//
// MOAIGwenRenderer
//================================================================//

//----------------------------------------------------------------//
MOAIGwenRenderer::MOAIGwenRenderer()
 {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenRenderer::~MOAIGwenRenderer() 
{
}

void MOAIGwenRenderer::RegisterLuaClass(MOAILuaState& state)
{
	luaL_Reg regTable[] = 
	{
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

void MOAIGwenRenderer::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAILuaObject::RegisterLuaFuncs(state);

	luaL_Reg regTable[] =
	{
		{ "setLoadTexture", _setLoadTexture },
		{ "setFreeTexture", _setFreeTexture },
		{ NULL, NULL }
	};
	
	luaL_register(state, 0, regTable);
}

void MOAIGwenRenderer::Init()
{

}

void MOAIGwenRenderer::Begin() 
{
	MOAIGfxDevice::Get().SetBlendMode(ZGL_BLEND_FACTOR_ONE, ZGL_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA);
}

void MOAIGwenRenderer::End()
{

}

void MOAIGwenRenderer::SetDrawColor(Gwen::Color color) 
{
	MOAIGfxDevice::Get().SetPenColor((float)color.r / 255.0f, (float)color.g / 255.0f, (float)color.b / 255.0f, (float)color.a / 255.0f);
}

void MOAIGwenRenderer::DrawFilledRect(Gwen::Rect rect) 
{
	Translate(rect);

	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	gfxDevice.SetTexture();
	gfxDevice.SetShaderPreset(MOAIShaderMgr::LINE_SHADER);
	gfxDevice.SetVertexPreset(MOAIVertexFormatMgr::XYZWC);
	
	MOAIDraw::DrawRectFill(rect.x, gfxDevice.GetHeight() - rect.y, rect.x + rect.w, gfxDevice.GetHeight() - (rect.y + rect.h), false);
}

void MOAIGwenRenderer::StartClip() 
{
	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	gfxDevice.Flush();

	Gwen::Rect rect = ClipRegion();

	ZLRect scissor;

	scissor.Init(rect.x, rect.y, rect.x + rect.w, (rect.y + rect.h));
	scissor.Scale(Scale(), Scale());

	//gfxDevice.SetScissorRect(scissor);
}

void MOAIGwenRenderer::EndClip() 
{
	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	gfxDevice.SetScissorRect();
}

void MOAIGwenRenderer::LoadTexture(Gwen::Texture* pTexture)
{
	MOAIScopedLuaState state = MOAILuaRuntime::Get().State();

	if (!LoadTextureCallback.PushRef(state))
	{
		return;
	}

	MOAIImage* img = new MOAIImage();


	state.Push(pTexture->name.c_str());
	state.DebugCall(1, 1);
	cc8* path = state.GetValue<cc8*>(-1, "");

	MOAITexture* texture = NULL;

	if (!texture)
	{
		pTexture->failed = true;
		return;
	}

	pTexture->width  = (int)texture->GetWidth();
	pTexture->height = (int)texture->GetHeight();
	pTexture->data = NULL;

	this->LuaRetain(img);

	this->LuaRetain(texture);
}

void MOAIGwenRenderer::FreeTexture(Gwen::Texture* pTexture)
{
	MOAIScopedLuaState state = MOAILuaRuntime::Get().State();

	MOAITexture* texture = (MOAITexture*)pTexture->data;

	if (FreeTextureCallback.PushRef(state))
	{
		state.Push(texture);
		state.DebugCall(1, 0);
	}

	this->LuaRelease(texture);
}

void MOAIGwenRenderer::DrawTexturedRect(Gwen::Texture* pTexture, Gwen::Rect rect, float u1, float v1, float u2, float v2)
{
	if (!pTexture)
	{
		DrawMissingImage(rect);
	}

	Translate(rect);

	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	gfxDevice.SetTexture(reinterpret_cast<MOAITexture*>(pTexture->data));
	gfxDevice.SetShaderPreset(MOAIShaderMgr::DECK2D_SHADER);

	MOAIQuadBrush quad;
	quad.BindVertexFormat(gfxDevice);
	quad.SetVerts(rect.x, gfxDevice.GetHeight() - rect.y, rect.x + rect.w, gfxDevice.GetHeight() - (rect.y + rect.h));
	quad.SetUVs(u1, v1, u2, v2);
	quad.Draw();
}

void MOAIGwenRenderer::DrawMissingImage(Gwen::Rect rect)
{
	DrawFilledRect(rect);
}

Gwen::Color MOAIGwenRenderer::PixelColour(Gwen::Texture* pTexture, unsigned int x, unsigned int y, const Gwen::Color & col_default)
{
	if (!(pTexture && pTexture->data && !pTexture->failed))
	{
		return col_default;
	}

	return col_default;
}
