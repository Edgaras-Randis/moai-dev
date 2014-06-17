// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENRENDERER_H
#define MOAIGWENRENDERER_H

class MOAIGwenRenderer : public virtual MOAILuaObject, public Gwen::Renderer::Base 
{
private:
	
	//----------------------------------------------------------------//

	static int	_setLoadTexture(lua_State* L);
	static int	_setFreeTexture(lua_State* L);

public:
	DECL_LUA_FACTORY(MOAIGwenRenderer)

	virtual void Init();

	virtual void Begin();
	virtual void End();

	virtual void SetDrawColor(Gwen::Color color);

	virtual void DrawFilledRect(Gwen::Rect rect);

	virtual void StartClip();
	virtual void EndClip();

	virtual void LoadTexture(Gwen::Texture* pTexture);
	virtual void FreeTexture(Gwen::Texture* pTexture);
	virtual void DrawTexturedRect(Gwen::Texture* pTexture, Gwen::Rect pTargetRect, float u1 = 0.0f, float v1 = 0.0f, float u2 = 1.0f, float v2 = 1.0f);
	virtual void DrawMissingImage(Gwen::Rect pTargetRect);
	virtual Gwen::Color PixelColour(Gwen::Texture* pTexture, unsigned int x, unsigned int y, const Gwen::Color & col_default = Gwen::Color(255, 255, 255, 255));

	virtual void LoadFont(Gwen::Font* pFont) {};
	virtual void FreeFont(Gwen::Font* pFont) {};
	
	//----------------------------------------------------------------//
					MOAIGwenRenderer			 ();
					~MOAIGwenRenderer			 ();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);

private:

	MOAILuaMemberRef LoadTextureCallback;
	MOAILuaMemberRef FreeTextureCallback;

	Gwen::Color m_Color;
};

#endif
