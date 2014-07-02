// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENDOCKBASE_H
#define MOAIGWENDOCKBASE_H

#include <moai-gwen/MOAIGwenRegister.h>
#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenDockedTabControl.h>

class MOAIGwenDockBase;

template<typename T>
class MOAIGwenDockBaseBase : public MOAIGwenControlBase<T>
{
public:
	MOAIGwenDockBaseBase(Gwen::Controls::Base* pParent, const Gwen::String& Name = "", MOAIGwenBase* Base = NULL) : MOAIGwenControlBase<T>(pParent, Name, Base)
	{

	}

	void SetupChildDock(int iPos)
	{
		if (!m_DockedTabControl)
		{
			MOAIGwenDockedTabControl* base = new MOAIGwenDockedTabControl();
			base->CreateControl(Cannary);
			m_DockedTabControl = base->Control();
			m_DockedTabControl->onLoseTab.Add(this, &MOAIGwenDockBaseBase<T>::OnTabRemoved);
			m_DockedTabControl->SetTabStripPosition(Gwen::Pos::Bottom);
			m_DockedTabControl->SetShowTitlebar(true);
		}

		Dock(iPos);
		int iSizeDirection = Gwen::Pos::Left;

		if (iPos == Gwen::Pos::Left) { iSizeDirection = Gwen::Pos::Right; }

		if (iPos == Gwen::Pos::Top) { iSizeDirection = Gwen::Pos::Bottom; }

		if (iPos == Gwen::Pos::Bottom) { iSizeDirection = Gwen::Pos::Top; }

		Gwen::ControlsInternal::Resizer* sizer = new Gwen::ControlsInternal::Resizer(this);
		sizer->Dock(iSizeDirection);
		sizer->SetResizeDir(iSizeDirection);
		sizer->SetSize(2, 2);
		sizer->SetTarget(this);
	}

	Gwen::Controls::DockBase* GetChildDock(int iPos)
	{
		Gwen::Controls::DockBase** pDock = GetChildDockPtr(iPos);

		if (!(*pDock))
		{
			MOAIGwenDockBase* base = new MOAIGwenDockBase();
			base->CreateControl(Cannary);
			(*pDock) = base->Control();
			(*pDock)->SetupChildDock(iPos);
		}
		else
		{
			(*pDock)->SetHidden(false);
		}

		return *pDock;
	}
};

class MOAIGwenDockBase : public MOAIGwenControl<Gwen::Controls::DockBase, MOAIGwenDockBaseBase>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenDockBase)

	//----------------------------------------------------------------//
	MOAIGwenDockBase()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::DockBase));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterDockBase::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterDockBase::RegisterLuaFuncs(state);
	}
};

#endif
