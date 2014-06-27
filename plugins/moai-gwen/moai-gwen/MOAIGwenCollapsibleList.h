// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCollapsibleList_H
#define MOAIGwenCollapsibleList_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

class MOAIGwenCollapsibleList : public MOAIGwenControl<Gwen::Controls::CollapsibleList>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenCollapsibleList)

	//----------------------------------------------------------------//
					MOAIGwenCollapsibleList();
				   ~MOAIGwenCollapsibleList();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);
};

#endif
