// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWEN_H
#define MOAIGWEN_H

class MOAIGwenSkin;
class MOAIGwenRender;

class MOAIGwenCanvas : public virtual MOAIProp, public virtual Gwen::Controls::Canvas
{
private:
	
	//----------------------------------------------------------------//

	static int _init(lua_State* L);
	static int _render(lua_State* L);

public:
	DECL_LUA_FACTORY(MOAIGwenCanvas)
	
	//----------------------------------------------------------------//
					MOAIGwenCanvas			 ();
					~MOAIGwenCanvas			 ();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);

private:

	MOAILuaSharedPtr<MOAIGwenSkin> Skin;

	UnitTest* pUnitTest;
};

#endif
