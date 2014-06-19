// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com


#ifndef MOAIGWENSKINTEXTURE_H
#define MOAIGWENSKINTEXTURE_H

class MOAIGwenSkinTexture : public virtual MOAITexture, public Gwen::Texture
{
private:
	
	//----------------------------------------------------------------//

	static int _load(lua_State* L);

public:
	DECL_LUA_FACTORY(MOAIGwenSkinTexture)
	
	//----------------------------------------------------------------//
					MOAIGwenSkinTexture();
					~MOAIGwenSkinTexture();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);

	void			Release();

	Gwen::Color GetPixelColor(int x, int y, const Gwen::Color& base = Gwen::Color(255, 255, 255, 255));
	
	MOAIImage Image;
};

#endif
