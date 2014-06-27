// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENBUTTON_H
#define MOAIGWENBUTTON_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenButton : public MOAIGwenControl<Gwen::Controls::Button>, public MOAIGwenEventButton
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenButton)

	//----------------------------------------------------------------//
					MOAIGwenButton();
				   ~MOAIGwenButton();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);

	void			RegisterEvent();
};

#endif
