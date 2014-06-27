// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENLABEL_H
#define MOAIGWENLABEL_H

#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenLabel : public MOAIGwenControl<Gwen::Controls::Label>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenLabel)
	
	//----------------------------------------------------------------//
					MOAIGwenLabel();
					~MOAIGwenLabel();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);
};

#endif
