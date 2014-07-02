// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCrossSplitter_H
#define MOAIGwenCrossSplitter_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenCrossSplitter : public MOAIGwenControl<Gwen::Controls::CrossSplitter>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenCrossSplitter)

	//----------------------------------------------------------------//
	MOAIGwenCrossSplitter()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::CrossSplitter));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterCrossSplitter::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterCrossSplitter::RegisterLuaFuncs(state);
	}
};

#endif
