// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENEVENT_H
#define MOAIGWENEVENT_H

#include <moai-gwen/MOAIGwenBase.h>

#define MOAI_GWEN_EVENT(func, id)												 \
void func(Gwen::Controls::Base* pControl)										 \
{																				 \
	if (!Base)																	 \
	{																			 \
		return;																	 \
	}																			 \
																				 \
	MOAIScopedLuaState state = MOAILuaRuntime::Get().State();					 \
																				 \
	if (id < 1 || id > Base->EventListener.size()) { return; }					 \
	if (!Base->EventListener.at(id - 1).PushRef(state)) { return; }				 \
																				 \
	state.DebugCall(0, 0);														 \
} 

class MOAIGwenEventListener : public Gwen::Event::Handler
{
private:

	static int _setEventListener(lua_State* L);

public:

	void RegisterLuaClass(MOAILuaState& state);
	void RegisterLuaFuncs(MOAILuaState& state);

	void SetBase(MOAIGwenBase* base);

	template<typename T> T* Cast(const char* typeId)
	{
		if (!Base)
		{
			return NULL;
		}

		return Base->Cast<T>(typeId);
	}

protected:

	MOAIWeakPtr<MOAIGwenBase> Base;
};

class MOAIGwenEventButton : public MOAIGwenEventListener
{
private:
	
	//----------------------------------------------------------------//

public:

	enum EVENT
	{
		EVENT_NONE,
		EVENT_PRESS,
		EVENT_RIGHT_PRESS,
		EVENT_DOWN,
		EVENT_UP,
		EVENT_DOUBLE_CLICK,
		EVENT_TOGGLE,
		EVENT_TOGGLE_ON,
		EVENT_TOGGLE_OFF,
		EVENT_COUNT
	};

	MOAI_GWEN_EVENT(OnPress, EVENT_PRESS);
	MOAI_GWEN_EVENT(OnRightPress, EVENT_RIGHT_PRESS);
	MOAI_GWEN_EVENT(OnDown, EVENT_DOWN);
	MOAI_GWEN_EVENT(OnUp, EVENT_UP);
	MOAI_GWEN_EVENT(OnDoubleClick, EVENT_DOUBLE_CLICK);
	MOAI_GWEN_EVENT(OnToggle, EVENT_TOGGLE);
	MOAI_GWEN_EVENT(OnToggleOn, EVENT_TOGGLE_ON);
	MOAI_GWEN_EVENT(OnToggleOff, EVENT_TOGGLE_OFF);

	void RegisterLuaClass(MOAILuaState& state);
	void RegisterLuaFuncs(MOAILuaState& state);

	void RegisterEvents();
	void UnregisterEvents();
};

#endif
