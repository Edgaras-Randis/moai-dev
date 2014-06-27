// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENBASE_H
#define MOAIGWENBASE_H

#define STRINGIFY(x) #x

#define MOAI_GWEN_BASE(x) virtual Gwen::Controls::Base* Base() { return (Gwen::Controls::Base*)x; } 

#define DECL_GWEN_LUA_FACTORY(x) DECL_LUA_FACTORY(x) //MOAI_GWEN_BASE(Control())

#define MOAI_GWEN_BASE_SETUP(str) MOAI_LUA_SETUP(MOAIGwenBase, str) if(!self->Base()) { return 0; } Gwen::Controls::Base* base = self->Base();

#define GWEN_CONTROL_EVENT(x) void x(Gwen::Controls::Base* pControl)

class MOAIGwenBase: public virtual MOAILuaObject
{
private:

	static int _getPosition(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->X());
		state.Push(base->Y());

		return 2;
	}

	static int _getSize(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->Width());
		state.Push(base->Height());

		return 2;
	}

	static int _getExtent(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->Right());
		state.Push(base->Bottom());

		return 2;
	}

	static int _getMargin(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		const Gwen::Margin& value = base->GetMargin();

		state.Push(value.left);
		state.Push(value.top);
		state.Push(value.right);
		state.Push(value.bottom);

		return 4;
	}

	static int _getPadding(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		const Gwen::Padding& value = base->GetPadding();

		state.Push(value.left);
		state.Push(value.top);
		state.Push(value.right);
		state.Push(value.bottom);

		return 4;
	}

	static int _getBounds(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		const Gwen::Rect& value = base->GetBounds();

		state.Push(value.x);
		state.Push(value.y);
		state.Push(value.w);
		state.Push(value.h);

		return 4;
	}

	static int _getDock(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->GetDock());

		return 1;
	}

	static int _setHidden(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetHidden(state.GetValue<bool>(2, false));

		return 0;
	}

	static int _isHidden(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->Hidden());

		return 1;
	}

	static int _isVisible(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->Visible());

		return 1;
	}

	static int _hide(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->Hide();

		return 0;
	}

	static int _show(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->Show();

		return 0;
	}

	static int _setPosition(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetPos(state.GetValue<int>(2, 0), state.GetValue<int>(3, 0));

		return 0;
	}

	static int _setWidth(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetWidth(state.GetValue<int>(2, 0));

		return 0;
	}

	static int _setHeight(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetHeight(state.GetValue<int>(2, 0));

		return 0;
	}

	static int _setSize(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetSize(state.GetValue<int>(2, 0), state.GetValue<int>(3, 0));

		return 0;
	}

	static int _setBounds(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetBounds(state.GetValue<int>(2, 0), state.GetValue<int>(3, 0), state.GetValue<int>(4, 0), state.GetValue<int>(5, 0));

		return 0;
	}

	static int _moveTo(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->MoveTo(state.GetValue<int>(2, 0), state.GetValue<int>(3, 0));

		return 0;
	}

	static int _moveBy(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->MoveBy(state.GetValue<int>(2, 0), state.GetValue<int>(3, 0));

		return 0;
	}

	static int _setMouseInputEnabled(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetMouseInputEnabled(state.GetValue<bool>(2, 0));

		return 0;
	}

	static int _getMouseInputEnabled(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->GetMouseInputEnabled());

		return 1;
	}

	static int _setKeyboardInputEnabled(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetKeyboardInputEnabled(state.GetValue<bool>(2, 0));

		return 0;
	}

	static int _getKeyboardInputEnabled(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->GetKeyboardInputEnabled());

		return 1;
	}

	static int _getNeedsInputChars(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->NeedsInputChars());

		return 1;
	}

	static int _isHovered(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->IsHovered());

		return 1;
	}

	static int _isOnTop(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->IsOnTop());

		return 1;
	}

	static int _hasFocus(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->HasFocus());

		return 1;
	}

	static int _focus(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->Focus();

		return 0;
	}

	static int _blur(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->Blur();

		return 0;
	}

	static int _getMinimumSize(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		Gwen::Point value = base->GetMinimumSize();

		state.Push(value.x);
		state.Push(value.y);

		return 2;
	}

	static int _getMaximumSize(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		Gwen::Point value = base->GetMaximumSize();

		state.Push(value.x);
		state.Push(value.y);

		return 2;
	}

	static int _getX(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->X());

		return 1;
	}

	static int _getY(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->Y());

		return 1;
	}

	static int _getBottom(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");
		
		state.Push(base->Bottom());

		return 1;
	}

	static int _getRight(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->Right());

		return 1;
	}

	static int _isMenuComponent(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->IsMenuComponent());

		return 1;
	}

	static int _closeMenus(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->CloseMenus();

		return 0;
	}

	static int _isTabable(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->IsTabable());

		return 1;
	}

	static int _setTabable(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetTabable(state.GetValue<bool>(2, false));

		return 0;
	}

	static int _setToolTip(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetToolTip(state.GetValue<cc8*>(2, ""));

		return 0;
	}

	

	static int _setDisabled(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		base->SetDisabled(state.GetValue<bool>(2, false));

		return 0;
	}

	static int _isDisabled(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		state.Push(base->IsDisabled());

		return 1;
	}

	static int _setParent(lua_State* L)
	{
		MOAI_GWEN_BASE_SETUP("U");

		MOAIGwenBase* parent = state.GetLuaObject<MOAIGwenBase>(2, true);

		base->SetParent(parent ? parent->Base() : NULL);

		return 0;
	}

	static int _createControl(lua_State* L)
	{
		MOAI_LUA_SETUP(MOAIGwenBase, "UU"); //we don't have base yet

		MOAIGwenBase* parent = state.GetLuaObject<MOAIGwenBase>(2, true);

		if (!parent)
		{
			return 0;
		}

		self->CreateControl(parent, state.GetValue<cc8*>(3, ""));

		return 0;
	}

public:

	DECL_LUA_FACTORY(MOAIGwenBase)

	MOAIGwenBase::MOAIGwenBase()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAILuaObject)
		RTTI_END
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAILuaObject::RegisterLuaClass(state);

		luaL_Reg regTable[] =
		{
			{ NULL, NULL }
		};

		luaL_register(state, 0, regTable);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAILuaObject::RegisterLuaFuncs(state);

		luaL_Reg regTable[] =
		{
			{ "blur",					_blur },
			{ "closeMenus",				_closeMenus },
			{ "focus",					_focus },
			{ "getBounds",				_getBounds },
			{ "getExtent",				_getExtent },
			{ "getKeyboardMouseEnabled",_getKeyboardInputEnabled },
			{ "getMargin",				_getMargin },
			{ "getMaximumSize",			_getMaximumSize },
			{ "getMinimumSize",			_getMinimumSize },
			{ "getMouseInputEnabled",	_getMouseInputEnabled },
			{ "getNeedsInputChar",		_getNeedsInputChars },
			{ "getPadding",				_getPadding },
			{ "getPosition",			_getPosition },
			{ "getSize",				_getSize },
			{ "getX", 					_getX },
			{ "getY",					_getY },
			{ "getBottom",				_getBottom },
			{ "getRight",				_getRight },
			{ "hasFocus",				_hasFocus },
			{ "hide",					_hide },
			{ "isDisabled",				_isDisabled },
			{ "isHidden",				_isHidden },
			{ "isHovered",				_isHovered },
			{ "isMenuComponent",		_isMenuComponent },
			{ "isOnTop",				_isOnTop },
			{ "isTabable",				_isTabable },
			{ "isVisible",				_isVisible },
			{ "moveBy",					_moveBy },
			{ "moveTo",					_moveTo },
			{ "setBounds",				_setBounds },
			{ "setDisabled",			_setDisabled },			
			{ "setHeigh",				_setHeight },
			{ "setHidden",				_setHidden },
			{ "setKeyboardInputEnabled",_setKeyboardInputEnabled },
			{ "setMouseInputEnabled",	_setMouseInputEnabled },
			{ "setParent",				_setParent },
			{ "setPosition",			_setPosition },
			{ "setSize",				_setSize },
			{ "setTabable",				_setTabable },
			{ "setToolTip",				_setToolTip },
			{ "setWidth",				_setWidth },
			{ "show",					_show },
			{ "createControl",			_createControl },
			{ NULL, NULL }
		};

		luaL_register(state, 0, regTable);
	}

	virtual Gwen::Controls::Base* Base() { return NULL; }

	virtual void CreateControl(MOAIGwenBase* parent, const std::string& name = ""){}
	virtual void RegisterEvent() {}

	std::vector<MOAILuaStrongRef> EventListener;

	std::set<std::string> RTTI_CAST;

	template < typename T > T* Cast(const char* type)
	{
		if (RTTI_CAST.find(type) == RTTI_CAST.end())
		{
			return NULL;
		}

		return static_cast<T*>(Base());
	}
};


template<typename T>
class MOAIGwenControlBase : public T
{
public:

	MOAIGwenControlBase(Gwen::Controls::Base* pParent, const Gwen::String & Name = "", MOAIGwenBase* Base = NULL) : T(pParent, Name, (void*)Base), Cannary(Base)
	{
		
	}

	virtual void OnChildAdded(Gwen::Controls::Base* pChild)
	{
		T::OnChildAdded(pChild);

		if (!pChild->UserData.Exists("Data"))
		{
			return;
		}

		MOAIGwenBase* base = static_cast<MOAIGwenBase*>(pChild->UserData.Get<void*>("Data"));

		if (!(base && Cannary))
		{
			return;
		}

		Cannary->LuaRetain(base);
	}

	virtual void OnChildRemoved(Gwen::Controls::Base* pChild)
	{
		T::OnChildRemoved(pChild);

		if (!pChild->UserData.Exists("Data"))
		{
			return;
		}

		MOAIGwenBase* base = static_cast<MOAIGwenBase*>(pChild->UserData.Get<void*>("Data"));

		if (!(base && Cannary))
		{
			return;
		}

		Cannary->LuaRelease(base);
	}

private:

	MOAIGwenBase* Cannary;
};

template<typename T>
class MOAIGwenControl : public MOAIGwenBase
{
public:

	virtual void CreateControl(MOAIGwenBase* parent, const std::string& name = "")
	{
		assert(parent && !Data);

		if (!parent)
		{
			return;
		}

		if (Data)
		{
			delete Data;
			Data = NULL;
		}

		Data = new MOAIGwenControlBase<T>(parent->Base(), name, (MOAIGwenBase*)this);

		RegisterEvent();
	}
	
	MOAIGwenControl() : Data(NULL)
	{

	}

	virtual ~MOAIGwenControl()
	{
		if (Data)
		{
			delete Data;
			Data = NULL;
		}
	}

	MOAIGwenControlBase<T>* Control()
	{
		return Data;
	}

	virtual Gwen::Controls::Base* Base()
	{
		return ((Gwen::Controls::Base*)Data);
	}

protected:

	MOAIGwenControlBase<T>* Data;
};

#endif