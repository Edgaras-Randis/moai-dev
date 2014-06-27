// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENDOCKBASE_H
#define MOAIGWENDOCKBASE_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

template<typename T>
class MOAIGwenDockBaseBase : public MOAIGwenControlBase<T>
{
public:
	MOAIGwenDockBaseBase(Gwen::Controls::Base* pParent, const Gwen::String& Name = "", MOAIGwenBase* Base = NULL) : MOAIGwenControlBase<T>(pParent, Name, Base)
	{

	}
};

class MOAIGwenDockBase : public MOAIGwenControl<Gwen::Controls::DockBase, MOAIGwenDockBaseBase>
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
