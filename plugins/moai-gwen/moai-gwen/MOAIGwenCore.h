// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCore_H
#define MOAIGwenCore_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenCore : public MOAIGwenControl<Gwen::Controls::Base>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenCore)

	//----------------------------------------------------------------//
	MOAIGwenCore()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
	}
};

#endif
