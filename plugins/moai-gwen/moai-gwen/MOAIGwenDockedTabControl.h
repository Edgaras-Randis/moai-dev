// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenDockedTabControl_H
#define MOAIGwenDockedTabControl_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenDockedTabControl : public MOAIGwenControl<Gwen::Controls::DockedTabControl>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenDockedTabControl)

	//----------------------------------------------------------------//
	MOAIGwenDockedTabControl()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::TabControl));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::DockedTabControl));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterTabControl::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterTabControl::RegisterLuaFuncs(state);
	}
};

#endif
