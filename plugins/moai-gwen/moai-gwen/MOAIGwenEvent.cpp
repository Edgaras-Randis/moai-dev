// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenEvent.h>
#include <moai-gwen/MOAIGwenBase.h>

int MOAIGwenEventListener::_setEventListener(lua_State* L)
{
	MOAI_GWEN_BASE_SETUP("UN");

	int id = state.GetValue<int>(2, 0);

	if (id < 1 || id > (int)self->EventListener.size())
	{
		return 0;
	}

	self->EventListener.at(id - 1).SetRef(state, 3);

	return 0;
}

void MOAIGwenEventListener::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenEventListener::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setEventListener", _setEventListener },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

void MOAIGwenEventListener::SetBase(MOAIGwenBase* base)
{
	Base = MOAIWeakPtr<MOAIGwenBase>(base);
}

//================================================================//
// lua
//================================================================//

void MOAIGwenEventButton::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenEventListener::RegisterLuaClass(state);

	state.SetField(-1, "EVENT_PRESS",		 EVENT_PRESS);
	state.SetField(-1, "EVENT_RIGHT_PRESS",  EVENT_RIGHT_PRESS);
	state.SetField(-1, "EVENT_DOWN",		 EVENT_DOWN);
	state.SetField(-1, "EVENT_UP",			 EVENT_UP);
	state.SetField(-1, "EVENT_DOUBLE_CLICK", EVENT_DOUBLE_CLICK);
	state.SetField(-1, "EVENT_TOGGLE",		 EVENT_TOGGLE);
	state.SetField(-1, "EVENT_TOGGLE_ON",	 EVENT_TOGGLE_ON);
	state.SetField(-1, "EVENT_TOGGLE_OFF",	 EVENT_TOGGLE_OFF);
}

void MOAIGwenEventButton::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenEventListener::RegisterLuaFuncs(state);
}

void MOAIGwenEventButton::RegisterEvents()
{
	Gwen::Controls::Button* Control = Cast<Gwen::Controls::Button>(STRINGIFY(Gwen::Controls::Button));

	if (!Control)
	{
		return;
	}

	Base->EventListener.resize(EVENT_COUNT);


	Control->onDoubleClick.Add(this, &MOAIGwenEventButton::OnDoubleClick);
	Control->onDown.Add(this, &MOAIGwenEventButton::OnDown);
	Control->onPress.Add(this, &MOAIGwenEventButton::OnPress);
	Control->onRightPress.Add(this, &MOAIGwenEventButton::OnRightPress);
	Control->onToggle.Add(this, &MOAIGwenEventButton::OnToggle);
	Control->onToggleOff.Add(this, &MOAIGwenEventButton::OnToggleOff);
	Control->onToggleOn.Add(this, &MOAIGwenEventButton::OnToggleOn);
	Control->onUp.Add(this, &MOAIGwenEventButton::OnUp);
}

void MOAIGwenEventButton::UnregisterEvents()
{
	Gwen::Controls::Button* Control = Cast<Gwen::Controls::Button>(STRINGIFY(Gwen::Controls::Button));

	if (!Control)
	{
		return;
	}

	Control->onDoubleClick.RemoveHandler(this);
	Control->onDown.RemoveHandler(this);
	Control->onPress.RemoveHandler(this);
	Control->onRightPress.RemoveHandler(this);
	Control->onToggle.RemoveHandler(this);
	Control->onToggleOff.RemoveHandler(this);
	Control->onToggleOn.RemoveHandler(this);
	Control->onUp.RemoveHandler(this);
}