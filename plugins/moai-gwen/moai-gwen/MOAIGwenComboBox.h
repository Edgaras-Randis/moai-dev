// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenComboBox_H
#define MOAIGwenComboBox_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>
#include <moai-gwen/MOAIGwenRegister.h>

template<typename T>
class MOAIGwenComboBoxBase : public MOAIGwenControlBase<T>
{
public:
	MOAIGwenComboBoxBase(Gwen::Controls::Base* pParent, const Gwen::String & Name = "", MOAIGwenBase* Base = NULL) : MOAIGwenControlBase<T>(pParent, Name, Base)
	{

	}

	/*
	virtual Gwen::Controls::MenuItem* AddItem(const Gwen::UnicodeString & strLabel, const Gwen::String & strName = "") //
	{
		MOAIGwenMenuItem* item = new MOAIGwenMenuItem();

		item->CreateControl(Cannary);

		Gwen::Controls::MenuItem* pItem = item->Control();

		pItem->SetText(strLabel);

		m_Menu->AddItem(pItem);
		
		pItem->SetName(strName);

		pItem->onMenuItemSelected.Add(this, &MOAIGwenComboBoxBase<T>::OnItemSelected);

		//Default
		if (m_SelectedItem == NULL)
		{
			OnItemSelected(pItem);
		}

		return pItem;
	}
	*/
};

class MOAIGwenComboBox : public MOAIGwenControl<Gwen::Controls::ComboBox, MOAIGwenComboBoxBase>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenComboBox)

	//----------------------------------------------------------------//
	MOAIGwenComboBox()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Button));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::ComboBox));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterLabel::RegisterLuaClass(state);
		MOAIGwenRegisterButton::RegisterLuaClass(state);
		MOAIGwenRegisterComboBox::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
		MOAIGwenRegisterButton::RegisterLuaFuncs(state);
		MOAIGwenRegisterComboBox::RegisterLuaFuncs(state);
	}
};

#endif
