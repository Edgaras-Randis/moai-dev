// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/headers.h>

#define MOAI_GWEN_REGISTER_SETUP(type, str) MOAI_LUA_SETUP(MOAIGwenBase, str) type* Control = self->Cast<type>(STRINGIFY(type)); if(!Control) return 0;

//================================================================//

int MOAIGwenRegisterLabel::_setText(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->SetText(state.GetValue<cc8*>(2, ""), state.GetValue<bool>(3, true));

	return 0;
}

int MOAIGwenRegisterLabel::_sizeToContent(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->SizeToContents();

	return 0;
}

int MOAIGwenRegisterLabel::_setTextColor(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Gwen::Color value;

	value.r = state.GetValue<u8>(2, 255);
	value.g = state.GetValue<u8>(3, 255);
	value.b = state.GetValue<u8>(4, 255);
	value.a = state.GetValue<u8>(5, 255);

	Control->SetTextColor(value);

	return 0;
}

int MOAIGwenRegisterLabel::_setFont(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->SetFont(Gwen::TextObject(state.GetValue<cc8*>(2, "")).GetUnicode(), state.GetValue<int>(3, 11), state.GetValue<bool>(4, false));

	return 0;
}

void MOAIGwenRegisterLabel::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterLabel::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setText",		_setText },
		{ "sizeToContents", _sizeToContent },
		{ "setTextColor",	_setTextColor },
		{ "setFont",		_setFont },
		{ NULL, NULL }
	};
	
	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterButton::_setImage(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Button, "U");

	Control->SetImage(Gwen::TextObject(state.GetValue<cc8*>(2, "")).GetUnicode(), state.GetValue<bool>(3, false));

	return 0;
}



int MOAIGwenRegisterButton::_setIsToggle(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Button, "U");

	Control->SetIsToggle(state.GetValue<bool>(2, false));

	return 0;
}

void MOAIGwenRegisterButton::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenRegisterLabel::RegisterLuaClass(state);
}

void MOAIGwenRegisterButton::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenRegisterLabel::RegisterLuaFuncs(state);

	luaL_Reg regTable[] =
	{
		{ "setImage",	 _setImage },
		{ "setIsToggle", _setIsToggle },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

void MOAIGwenRegisterDockBase::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterDockBase::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterCollapsibleList::_add(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CollapsibleList, "US");

	Gwen::Controls::CollapsibleCategory* Category = Control->Add(state.GetValue<cc8*>(2, ""));

	if (!Category->UserData.Exists("Data"))
	{
		return 0;
	}

	state.Push(Category->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}

int MOAIGwenRegisterCollapsibleList::_addCategory(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CollapsibleList, "UU");

	MOAIGwenCollapsibleCategory* Category = state.GetLuaObject<MOAIGwenCollapsibleCategory>(2, true);

	if (!Category)
	{
		return 0;
	}

	Control->Add(Category->Control());

	return 0;
}

void MOAIGwenRegisterCollapsibleList::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterCollapsibleList::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "add", _add },
		{ "addCategory", _addCategory },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterCollapsibleCategory::_setText(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CollapsibleCategory, "U");

	Control->SetText(state.GetValue<cc8*>(2, ""));

	return 0;
}

int MOAIGwenRegisterCollapsibleCategory::_add(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CollapsibleCategory, "US");

	Gwen::Controls::Button* Button = Control->Add(state.GetValue<cc8*>(2, ""));

	if (!Button->UserData.Exists("Data"))
	{
		return 0;
	}

	state.Push(Button->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}


void MOAIGwenRegisterCollapsibleCategory::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterCollapsibleCategory::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setText", _setText },
		{ "add",	 _add },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}
