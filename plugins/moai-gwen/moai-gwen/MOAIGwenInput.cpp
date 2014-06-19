// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenCanvas.h>
#include <moai-gwen/MOAIGwenInput.h>

//================================================================//
// lua
//================================================================//

int MOAIGwenInput::_init(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenInput, "U");

	self->Canvas.Set(*self, state.GetLuaObject<MOAIGwenCanvas>(2, true));

	return 1;
}

int MOAIGwenInput::_inputMouseMoved(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenInput, "U");

	int x = state.GetValue<int>(2, 0);
	int y = state.GetValue<int>(3, 0);
	int deltaX = state.GetValue<int>(4, 0);
	int deltaY = state.GetValue<int>(5, 0);

	state.Push(self->Canvas ? self->Canvas->InputMouseMoved(x, y, deltaX, deltaY) : false);

	return 1;
}

int MOAIGwenInput::_inputMouseButton(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenInput, "U");
	
	int button = state.GetValue<int>(2, 0);
	bool down  = state.GetValue<bool>(3, false);

	state.Push(self->Canvas ? self->Canvas->InputMouseButton(button, down) : false);

	return 1;
}

int MOAIGwenInput::_inputKey(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenInput, "U");

	int key   = state.GetValue<int>(2, 0);
	bool down = state.GetValue<bool>(3, false);

	state.Push(self->Canvas ? self->Canvas->InputKey(key, down) : false);

	return 1;
}

int MOAIGwenInput::_inputCharacter(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenInput, "U");

	unsigned int character = state.GetValue<unsigned int>(2, 0);

	state.Push(self->Canvas ? self->Canvas->InputCharacter(character) : false);

	return 1;
}

int MOAIGwenInput::_inputMouseWheel(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenInput, "U");

	int value = state.GetValue<int>(2, 0);

	state.Push(self->Canvas ? self->Canvas->InputMouseWheel(value) : false);

	return 1;
}

int MOAIGwenInput::_inputQuit(lua_State* L)
{
	MOAI_LUA_SETUP(MOAIGwenInput, "U");

	state.Push(self->Canvas ? self->Canvas->InputQuit() : false);

	return 1;
}

//================================================================//
// MOAIGwenInput
//================================================================//

//----------------------------------------------------------------//
MOAIGwenInput::MOAIGwenInput()
 {
	RTTI_BEGIN
		RTTI_EXTEND(MOAILuaObject)
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenInput::~MOAIGwenInput() 
{
	Canvas.Set(*this, 0);
}

void MOAIGwenInput::RegisterLuaClass(MOAILuaState& state)
{
	MOAILuaObject::RegisterLuaClass(state);

	state.SetField(-1, "KEY_ALT",		Gwen::Key::Alt);
	state.SetField(-1, "KEY_BACKSPACE", Gwen::Key::Backspace);
	state.SetField(-1, "KEY_CONTROL",	Gwen::Key::Control);
	state.SetField(-1, "KEY_COUNT",		Gwen::Key::Count);
	state.SetField(-1, "KEY_DELETE",	Gwen::Key::Delete);
	state.SetField(-1, "KEY_DOWN",		Gwen::Key::Down);
	state.SetField(-1, "KEY_END",		Gwen::Key::End);
	state.SetField(-1, "KEY_ESCAPE",	Gwen::Key::Escape);
	state.SetField(-1, "KEY_HOME",		Gwen::Key::Home);
	state.SetField(-1, "KEY_INVALID",	Gwen::Key::Invalid);
	state.SetField(-1, "KEY_LEFT",		Gwen::Key::Left);
	state.SetField(-1, "KEY_RETURN",	Gwen::Key::Return);
	state.SetField(-1, "KEY_RIGHT",		Gwen::Key::Right);
	state.SetField(-1, "KEY_SHIFT",		Gwen::Key::Shift);
	state.SetField(-1, "KEY_SPACE",		Gwen::Key::Space);
	state.SetField(-1, "KEY_TAB",		Gwen::Key::Tab);
	state.SetField(-1, "KEY_UP",		Gwen::Key::Up);

	luaL_Reg regTable[] = 
	{
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

void MOAIGwenInput::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAILuaObject::RegisterLuaFuncs(state);

	luaL_Reg regTable[] =
	{
		{ "init",			  _init },
		{ "inputMouseMoved",  _inputMouseMoved },
		{ "inputMouseButton", _inputMouseButton },
		{ "inputKey",		  _inputKey },
		{ "inputCharacter",   _inputCharacter },
		{ "inputMouseWheel",  _inputMouseWheel },
		{ "inputQuit",		  _inputQuit },
		{ NULL, NULL }
	};
	
	luaL_register(state, 0, regTable);
}
