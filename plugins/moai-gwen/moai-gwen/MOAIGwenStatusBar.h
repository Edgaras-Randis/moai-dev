// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenStatusBar_H
#define MOAIGwenStatusBar_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenStatusBar : public MOAIGwenControl<Gwen::Controls::StatusBar>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenStatusBar)

	//----------------------------------------------------------------//
	MOAIGwenStatusBar()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::StatusBar));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterLabel::RegisterLuaClass(state);
		MOAIGwenRegisterStatusBar::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
		MOAIGwenRegisterStatusBar::RegisterLuaFuncs(state);
	}
};

#endif
