// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenCollapsibleCategory_H
#define MOAIGwenCollapsibleCategory_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>
#include <moai-gwen/MOAIGwenCategoryButton.h>

template<typename T>
class MOAIGwenCollapsibleCategoryBase : public MOAIGwenControlBase<T>
{
public:
	MOAIGwenCollapsibleCategoryBase(Gwen::Controls::Base* pParent, const Gwen::String & Name = "", MOAIGwenBase* Base = NULL) : MOAIGwenControlBase<T>(pParent, Name, Base)
	{

	}

	virtual Gwen::Controls::Button* Add(const Gwen::TextObject & name)
	{
		MOAIGwenCategoryButton* pButton = new MOAIGwenCategoryButton();
		pButton->CreateControl(Cannary);
		pButton->Control()->SetText(name);
		pButton->Control()->Dock(Gwen::Pos::Top);
		pButton->Control()->SizeToContents();
		pButton->Control()->SetSize(pButton->Control()->Width() + 4, pButton->Control()->Height() + 4);
		pButton->Control()->SetPadding(Gwen::Padding(5, 2, 2, 2));
		pButton->Control()->onPress.Add(this, &MOAIGwenCollapsibleCategoryBase<T>::OnSelection);
		return pButton->Control();
	}
};

class MOAIGwenCollapsibleCategory : public MOAIGwenControl<Gwen::Controls::CollapsibleCategory, MOAIGwenCollapsibleCategoryBase>
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
