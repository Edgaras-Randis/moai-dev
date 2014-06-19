// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENINPUT_H
#define MOAIGWENINPUT_H

class MOAIGwenInput : public MOAILuaObject
{
private:
	
	//----------------------------------------------------------------//

	static int _init(lua_State* L);
	static int _inputMouseMoved(lua_State* L);
	static int _inputMouseButton(lua_State* L);
	static int _inputKey(lua_State* L);
	static int _inputCharacter(lua_State* L);
	static int _inputMouseWheel(lua_State* L);
	static int _inputQuit(lua_State* L);

public:
	DECL_LUA_FACTORY(MOAIGwenInput)
	
	//----------------------------------------------------------------//
					MOAIGwenInput();
					~MOAIGwenInput();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);

	MOAILuaSharedPtr<MOAIGwenCanvas> Canvas;
};

#endif
