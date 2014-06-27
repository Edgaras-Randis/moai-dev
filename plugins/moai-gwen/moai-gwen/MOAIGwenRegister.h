// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENREGISTER_H
#define MOAIGWENREGISTER_H

#include <moai-gwen/MOAIGwenLabel.h>

class MOAIGwenRegisterLabel
{
private:
	
	//----------------------------------------------------------------//

	static int _setText(lua_State* L);
	static int _sizeToContent(lua_State* L);
	static int _setTextColor(lua_State* L);
	static int _setFont(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterButton
{
private:

	//----------------------------------------------------------------//

	static int _setImage(lua_State* L);
	static int _setIsToggle(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterDockBase
{
private:

	//----------------------------------------------------------------//

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

#endif
