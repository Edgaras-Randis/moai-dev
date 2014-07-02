// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCollapsibleList_H
#define MOAIGwenCollapsibleList_H

#include <moai-gwen/MOAIGwenRegister.h>
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
	MOAIGwenCollapsibleList()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::ScrollControl));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::CollapsibleList));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterCollapsibleList::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterCollapsibleList::RegisterLuaFuncs(state);
	}
};

#endif
