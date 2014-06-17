// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWEN_H
#define MOAIGWEN_H

class MOAIGwenSkin;
class MOAIGwenRenderer;

class MOAIGwen : public virtual MOAIProp {
private:
	
	//----------------------------------------------------------------//

	static int _init(lua_State* L);
	static int _render(lua_State* L);

public:
	DECL_LUA_FACTORY(MOAIGwen)
	
	//----------------------------------------------------------------//
					MOAIGwen			 ();
					~MOAIGwen			 ();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);

private:

	MOAIGwenSkin* Skin;
	
	MOAIGwenRenderer* Renderer;
	Gwen::Controls::Canvas* Canvas;

	UnitTest* pUnitTest;
};

#endif
