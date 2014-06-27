// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCategoryButton_H
#define MOAIGwenCategoryButton_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenCategoryButton : public MOAIGwenControl<Gwen::Controls::CategoryButton>, public MOAIGwenEventButton
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenCategoryButton)

	//----------------------------------------------------------------//
					MOAIGwenCategoryButton();
				   ~MOAIGwenCategoryButton();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);

	void			RegisterEvent();
};

#endif
