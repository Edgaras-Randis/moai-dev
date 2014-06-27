// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCollapsibleList_H
#define MOAIGwenCollapsibleList_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>

template<typename T>
class MOAIGwenCollapsibleListBase : public MOAIGwenControlBase<T>
{
public:
	MOAIGwenCollapsibleListBase(Gwen::Controls::Base* pParent, const Gwen::String& Name = "", MOAIGwenBase* Base = NULL) : MOAIGwenControlBase<T>(pParent, Name, Base)
	{

	}

	virtual Gwen::Controls::CollapsibleCategory* Add(const Gwen::TextObject& name)
	{
		MOAIGwenCollapsibleCategory* pCategory = new MOAIGwenCollapsibleCategory();
		pCategory->Retain();
		pCategory->CreateControl(Cannary);
		pCategory->Control()->SetText(name);
		T::Add(pCategory->Control());
		return pCategory->Control();
	}
};


class MOAIGwenCollapsibleList : public MOAIGwenControl<Gwen::Controls::CollapsibleList, MOAIGwenCollapsibleListBase>
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
