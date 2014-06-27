// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCollapsibleCategory_H
#define MOAIGwenCollapsibleCategory_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenCollapsibleCategory : public MOAIGwenControl<Gwen::Controls::CollapsibleCategory>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenCollapsibleCategory)

	//----------------------------------------------------------------//
					MOAIGwenCollapsibleCategory();
				   ~MOAIGwenCollapsibleCategory();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);
};

#endif
