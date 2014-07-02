// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenRender.h>
#include <moai-gwen/MOAIGwenSkinTexture.h>

//================================================================//
// lua
//================================================================//

int MOAIGwenRender::_setLoadTexture(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenRender, "U")

	self->LoadTextureCallback.SetRef(*self, state, 2);

	return 0;
}

int MOAIGwenRender::_setLoadFont(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenRender, "U")

	self->LoadFontCallback.SetRef(*self, state, 2);

	return 0;
}

//================================================================//
// MOAIGwenRenderer
//================================================================//

//----------------------------------------------------------------//
MOAIGwenRender::MOAIGwenRender()
 {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenRender::~MOAIGwenRender() 
{
	LoadTextureCallback.Clear();
	LoadFontCallback.Clear();
}

void MOAIGwenRender::RegisterLuaClass(MOAILuaState& state)
{
	luaL_Reg regTable[] = 
	{
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

void MOAIGwenRender::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAILuaObject::RegisterLuaFuncs(state);

	luaL_Reg regTable[] =
	{
		{ "setLoadTexture", _setLoadTexture },
		{ "setLoadFont",    _setLoadFont },
		{ NULL, NULL }
	};
	
	luaL_register(state, 0, regTable);
}

void MOAIGwenRender::Init()
{

}

void MOAIGwenRender::Begin() 
{
	MOAIGfxDevice::Get().SetBlendMode(ZGL_BLEND_FACTOR_SRC_ALPHA, ZGL_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA);
}

void MOAIGwenRender::End()
{

}

void MOAIGwenRender::SetDrawColor(Gwen::Color color) 
{
	MOAIGfxDevice::Get().SetPenColor((float)color.r / 255.0f, (float)color.g / 255.0f, (float)color.b / 255.0f, (float)color.a / 255.0f);
}

void MOAIGwenRender::DrawFilledRect(Gwen::Rect rect) 
{
	Translate(rect);

	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	gfxDevice.SetTexture();
	gfxDevice.SetShaderPreset(MOAIShaderMgr::LINE_SHADER);
	gfxDevice.SetVertexPreset(MOAIVertexFormatMgr::XYZWC);

	MOAIDraw::DrawRectFill(rect.x, rect.y, rect.x + rect.w, (rect.y + rect.h));
}

void MOAIGwenRender::StartClip() 
{
	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	gfxDevice.Flush();

	Gwen::Rect rect = ClipRegion();

	ZLRect scissor;

	scissor.Init(rect.x, rect.y, rect.x + rect.w, (rect.y + rect.h));
	scissor.Scale(Scale(), Scale());

	gfxDevice.SetScissorRect(scissor);
}

void MOAIGwenRender::EndClip() 
{
	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	gfxDevice.SetScissorRect();
}

void MOAIGwenRender::LoadTexture(Gwen::Texture* pTexture)
{
	MOAIScopedLuaState state = MOAILuaRuntime::Get().State();

	if (!LoadTextureCallback.PushRef(state))
	{
		return;
	}

	state.Push(pTexture->name.c_str());
	state.DebugCall(1, 1);

	MOAITexture* texture = state.GetLuaObject<MOAITexture>(-1, true);

	if (!texture)
	{
		pTexture->failed = true;
		return;
	}

	pTexture->width  = (int)texture->GetWidth();
	pTexture->height = (int)texture->GetHeight();
	pTexture->data   = (void*)texture;

	this->LuaRetain(texture);
}

void MOAIGwenRender::FreeTexture(Gwen::Texture* pTexture)
{
	MOAITexture* texture = (MOAITexture*)pTexture->data;

	if (!texture)
	{
		return;
	}

	this->LuaRelease(texture);
}

void MOAIGwenRender::DrawTexturedRect(Gwen::Texture* pTexture, Gwen::Rect rect, float u1, float v1, float u2, float v2)
{
	DrawTexturedRect(pTexture ? reinterpret_cast<MOAITexture*>(pTexture->data) : NULL, rect, u1, v1, u2, v2);
}

void MOAIGwenRender::DrawTexturedRect(MOAITextureBase* pTexture, Gwen::Rect rect, float u1, float v1, float u2, float v2)
{
	if (!(pTexture && pTexture->LoadGfxState()))
	{
		DrawMissingImage(rect);
	}

	Translate(rect);

	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	gfxDevice.SetTexture(pTexture);
	gfxDevice.SetShaderPreset(MOAIShaderMgr::DECK2D_SHADER);

	MOAIQuadBrush quad;
	quad.BindVertexFormat(gfxDevice);
	quad.SetVerts(rect.x, rect.y, rect.x + rect.w, (rect.y + rect.h));
	quad.SetUVs(u1, v1, u2, v2);
	quad.Draw();
}

void MOAIGwenRender::DrawMissingImage(Gwen::Rect rect)
{
	DrawFilledRect(rect);
}

Gwen::Color MOAIGwenRender::PixelColour(Gwen::Texture* pTexture, unsigned int x, unsigned int y, const Gwen::Color& col_default)
{
	return col_default;
}

void MOAIGwenRender::LoadFont(Gwen::Font* pFont) 
{
	MOAIScopedLuaState state = MOAILuaRuntime::Get().State();

	if (!LoadFontCallback.PushRef(state))
	{
		return;
	}

	std::string fontName = Gwen::Utility::UnicodeToString(pFont->facename);

	if (fontName.find(".ttf") == std::string::npos)
	{
		fontName += ".ttf";
	}
	
	state.Push((cc8*)fontName.c_str());
	state.DebugCall(1, 1);

	MOAIFont* font = state.GetLuaObject<MOAIFont>(-1, true);

	if (!font || strlen(font->GetFilename()) <= 0)
	{
		pFont->data = NULL;

		return;
	}

	pFont->data = (void*)font;

	this->LuaRetain(font);
}

void MOAIGwenRender::FreeFont(Gwen::Font* pFont) 
{
	MOAIFont* font = (MOAIFont*)pFont->data;

	if (!font)
	{
		return;
	}

	this->LuaRelease(font);
}

void MOAIGwenRender::RenderText(Gwen::Font* pFont, Gwen::Point pos, const Gwen::UnicodeString & text)
{
	MOAIFont* font = (MOAIFont*)pFont->data;

	if (!font)
	{
		return;
	}

	pFont->realsize = pFont->size * Scale();

	for (u32 i = 0; i < text.length(); i++)
	{
		font->AffirmGlyph(pFont->realsize, (u32)text.at(i));
	}

	font->ProcessGlyphs();

	MOAIGlyphSet* glyphSet = font->GetGlyphSet(pFont->realsize);

	if (!glyphSet)
	{
		return;
	}

	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();

	Gwen::Point cursor(pos);

	for (u32 i = 0; i < text.length(); i++)
	{
		if (text.at(i) == (unsigned int)"\\n")
		{
			continue;
		}

		MOAIGlyph* glyph = glyphSet->GetGlyph(text.at(i));
		
		if (!glyph)
		{
			continue;
		}

		MOAITextureBase* texture = font->GetGlyphTexture(*glyph);

		if (texture)
		{
			float x = cursor.x;
			float y = cursor.y + glyph->mHeight - (glyphSet->GetHeight()/2 - 1);

			x += glyph->mBearingX;
			y -= glyph->mBearingY;

			float uScale = 1.0f / texture->GetWidth();
			float vScale = 1.0f / texture->GetHeight();

			float u = glyph->mSrcX * uScale;
			float v = glyph->mSrcY * vScale;

			/*
			ZLColorVec color = gfxDevice.GetPenColor();

			gfxDevice.SetPenColor(1, 0, 0, 0.25);

			DrawFilledRect(Gwen::Rect(x, y, glyph->mWidth, glyph->mHeight));

			gfxDevice.SetPenColor(color);
			//*/

			DrawTexturedRect(texture, Gwen::Rect(x, y, glyph->mWidth, glyph->mHeight), u, v, u + glyph->mWidth * uScale, v + glyph->mHeight * vScale);
		}

		cursor.x += glyph->GetAdvanceX();
	}
}

Gwen::Point MOAIGwenRender::MeasureText(Gwen::Font* pFont, const Gwen::UnicodeString & text)
{
	Gwen::Point result(0, 0);

	if (text.empty())
	{
		return result;
	}

	MOAIFont* font = (MOAIFont*)pFont->data;

	if (!font)
	{
		LoadFont(pFont);

		font = (MOAIFont*)pFont->data;

		if (!font)
		{
			return result;
		}
	}

	pFont->realsize = pFont->size * Scale();

	Gwen::String str(Gwen::Utility::UnicodeToString(text));

	for (u32 i = 0; i < text.length(); i++)
	{
		font->AffirmGlyph(pFont->realsize, (u32)text.at(i));
	}

	font->ProcessGlyphs();

	MOAIGlyphSet* glyphSet = font->GetGlyphSet(pFont->realsize);

	if (!glyphSet)
	{
		return result;
	}

	Gwen::Rect rct;

	ZLRect rect;
	rect.Init(0, 0, 0, 0);

	float fmin = 0;
	float fmax = 0;

	for (u32 i = 0; i < text.length(); i++)
	{
		MOAIGlyph* glyph = glyphSet->GetGlyph(text.at(i));

		result.x += glyph->GetAdvanceX();

		float fmin = glyph->mBearingY - glyph->mHeight;
		float fmax = glyph->mBearingY;

		rect.mYMin = MIN(fmin, rect.mYMin);
		rect.mYMax = MAX(fmax, rect.mYMax);
	}

	result.y = glyphSet->GetHeight(); //rect.Height();


	return result;
}