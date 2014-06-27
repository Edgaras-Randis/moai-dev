// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENDOCKBASE_H
#define MOAIGWENDOCKBASE_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenDockBase : public MOAIGwenControl<Gwen::Controls::DockBase>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenDockBase)

	//----------------------------------------------------------------//
					MOAIGwenDockBase();
				   ~MOAIGwenDockBase();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);
};

#endif
