// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/headers.h>

#define MOAI_GWEN_REGISTER_SETUP(type, str) MOAI_LUA_SETUP(MOAIGwenBase, str) type* Control = self->Cast<type>(STRINGIFY(type)); if(!Control) return 0;

//================================================================//

int MOAIGwenRegisterLabel::_setText(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->SetText(state.GetValue<cc8*>(2, ""), state.GetValue<bool>(3, true));

	return 0;
}

int MOAIGwenRegisterLabel::_sizeToContent(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->SizeToContents();

	return 0;
}

int MOAIGwenRegisterLabel::_setTextColor(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Gwen::Color value;

	value.r = state.GetValue<u8>(2, 255);
	value.g = state.GetValue<u8>(3, 255);
	value.b = state.GetValue<u8>(4, 255);
	value.a = state.GetValue<u8>(5, 255);

	Control->SetTextColor(value);

	return 0;
}

int MOAIGwenRegisterLabel::_setFont(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->SetFont(Gwen::TextObject(state.GetValue<cc8*>(2, "")).GetUnicode(), state.GetValue<int>(3, 11), state.GetValue<bool>(4, false));

	return 0;
}

int MOAIGwenRegisterLabel::_getTextColor(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	const Gwen::Color& Color = Control->TextColor();

	state.Push(Color.r);
	state.Push(Color.g);
	state.Push(Color.b);
	state.Push(Color.a);

	return 4;
}

int MOAIGwenRegisterLabel::_wrap(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->Wrap();

	return 0;
}

int MOAIGwenRegisterLabel::_setWrap(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->SetWrap(state.GetValue<bool>(2, false));

	return 0;
}

int MOAIGwenRegisterLabel::_getTextWidth(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	state.Push(Control->TextWidth());

	return 1;
}

int MOAIGwenRegisterLabel::_getTextRight(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	state.Push(Control->TextRight());

	return 1;
}

int MOAIGwenRegisterLabel::_getTextHeight(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	state.Push(Control->TextHeight());

	return 1;
}

int MOAIGwenRegisterLabel::_getTextX(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	state.Push(Control->TextX());

	return 1;
}

int MOAIGwenRegisterLabel::_getTextY(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	state.Push(Control->TextY());

	return 1;
}

int MOAIGwenRegisterLabel::_getTextLength(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	state.Push(Control->TextLength());

	return 1;
}

int MOAIGwenRegisterLabel::_setAlignment(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	Control->SetAlignment(state.GetValue<int>(2, 0));

	return 0;
}

int MOAIGwenRegisterLabel::_getAlignment(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Label, "U");

	state.Push(Control->GetAlignment());

	return 1;
}

void MOAIGwenRegisterLabel::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterLabel::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setText",		_setText },
		{ "sizeToContents",	_sizeToContent },
		{ "setTextColor",   _setTextColor },
		{ "setFont",	    _setFont },
		{ "getTextColor",   _getTextColor },
		{ "wrap",		    _wrap },
		{ "setWrap",	    _setWrap },
		{ "getTextWidth",   _getTextWidth },
		{ "getTextRight",   _getTextRight },
		{ "getTextHeight",  _getTextHeight },
		{ "getTextX",	    _getTextX },
		{ "getTextY",	    _getTextY },
		{ "getTextLength",  _getTextLength },
		{ "setAlignment",	_setAlignment },
		{ "getAlignment",   _getAlignment },
		{ NULL, NULL }
	};
	
	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterButton::_setImage(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Button, "U");

	Control->SetImage(Gwen::TextObject(state.GetValue<cc8*>(2, "")).GetUnicode(), state.GetValue<bool>(3, false));

	return 0;
}



int MOAIGwenRegisterButton::_setIsToggle(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::Button, "U");

	Control->SetIsToggle(state.GetValue<bool>(2, false));

	return 0;
}

void MOAIGwenRegisterButton::RegisterLuaClass(MOAILuaState& state)
{
	MOAIGwenRegisterLabel::RegisterLuaClass(state);
}

void MOAIGwenRegisterButton::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIGwenRegisterLabel::RegisterLuaFuncs(state);

	luaL_Reg regTable[] =
	{
		{ "setImage",	 _setImage },
		{ "setIsToggle", _setIsToggle },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterDockBase::_getTabControl(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::DockBase, "U");

	Gwen::Controls::TabControl* Tab = Control->GetTabControl();

	if (!(Tab && Tab->UserData.Exists("Data")))
	{
		return 0;
	}

	state.Push(Tab->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}

int MOAIGwenRegisterDockBase::_getRight(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::DockBase, "U");

	Gwen::Controls::DockBase* Dock = Control->GetRight();

	if (!(Dock && Dock->UserData.Exists("Data")))
	{
		return 0;
	}

	state.Push(Dock->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}

int MOAIGwenRegisterDockBase::_getLeft(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::DockBase, "U");

	Gwen::Controls::DockBase* Dock = Control->GetLeft();

	if (!(Dock && Dock->UserData.Exists("Data")))
	{
		return 0;
	}

	state.Push(Dock->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}

int MOAIGwenRegisterDockBase::_getTop(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::DockBase, "U");

	Gwen::Controls::DockBase* Dock = Control->GetTop();

	if (!(Dock && Dock->UserData.Exists("Data")))
	{
		return 0;
	}

	state.Push(Dock->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}

int MOAIGwenRegisterDockBase::_getBottom(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::DockBase, "U");

	Gwen::Controls::DockBase* Dock = Control->GetBottom();

	if (!(Dock && Dock->UserData.Exists("Data")))
	{
		return 0;
	}

	state.Push(Dock->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}

void MOAIGwenRegisterDockBase::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterDockBase::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "getTabControl",  _getTabControl },
		{ "getRight",	    _getRight },
		{ "getLeft",		_getLeft },
		{ "getTop",			_getTop },
		{ "getBottom",		_getBottom },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterCollapsibleList::_add(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CollapsibleList, "US");

	Gwen::Controls::CollapsibleCategory* Category = Control->Add(state.GetValue<cc8*>(2, ""));

	if (!Category->UserData.Exists("Data"))
	{
		return 0;
	}

	state.Push(Category->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}

int MOAIGwenRegisterCollapsibleList::_addCategory(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CollapsibleList, "UU");

	MOAIGwenCollapsibleCategory* Category = state.GetLuaObject<MOAIGwenCollapsibleCategory>(2, true);

	if (!Category)
	{
		return 0;
	}

	Control->Add(Category->Control());

	return 0;
}

void MOAIGwenRegisterCollapsibleList::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterCollapsibleList::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "add", _add },
		{ "addCategory", _addCategory },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterCollapsibleCategory::_setText(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CollapsibleCategory, "U");

	Control->SetText(state.GetValue<cc8*>(2, ""));

	return 0;
}

int MOAIGwenRegisterCollapsibleCategory::_add(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CollapsibleCategory, "US");

	Gwen::Controls::Button* Button = Control->Add(state.GetValue<cc8*>(2, ""));

	if (!Button->UserData.Exists("Data"))
	{
		return 0;
	}

	state.Push(Button->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}


void MOAIGwenRegisterCollapsibleCategory::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterCollapsibleCategory::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setText", _setText },
		{ "add",	 _add },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterTabControl::_addPage(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::TabControl, "USU");

	MOAIGwenBase* Page = state.GetLuaObject<MOAIGwenBase>(3, true);

	if (!Page)
	{
		return 0;
	}

	Control->AddPage(state.GetValue<cc8*>(2, ""), Page->Base());

	return 0;
}

void MOAIGwenRegisterTabControl::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterTabControl::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "addPage", _addPage },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterCrossSplitter::_setPanel(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CrossSplitter, "UN");

	MOAIGwenBase* Panel = state.GetLuaObject<MOAIGwenBase>(3, true);

	if (!Panel)
	{
		return 0;
	}

	Control->SetPanel(state.GetValue<int>(2, 1) - 1, Panel->Base());

	return 0;
}

int MOAIGwenRegisterCrossSplitter::_getPanel(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CrossSplitter, "UN");

	Gwen::Controls::Base* Panel = Control->GetPanel(state.GetValue<int>(2, 0));

	if (!Panel->UserData.Exists("Data"))
	{
		return 0;
	}

	state.Push(Panel->UserData.Get<MOAIGwenBase*>("Data"));

	return 1;
}

int MOAIGwenRegisterCrossSplitter::_isZoomed(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CrossSplitter, "U");

	state.Push(Control->IsZoomed());

	return 1;
}

int MOAIGwenRegisterCrossSplitter::_zoom(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CrossSplitter, "UN");

	Control->Zoom(state.GetValue<int>(2, 0));

	return 0;
}

int MOAIGwenRegisterCrossSplitter::_unZoom(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CrossSplitter, "U");

	Control->UnZoom();

	return 0;
}

int MOAIGwenRegisterCrossSplitter::_centerPanels(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CrossSplitter, "U");

	Control->CenterPanels();

	return 0;
}

int MOAIGwenRegisterCrossSplitter::_setSplitterSize(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::CrossSplitter, "U");

	Control->SetSplitterSize(state.GetValue<int>(2, 0));

	return 0;
}

void MOAIGwenRegisterCrossSplitter::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterCrossSplitter::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setPanel",		 _setPanel },
		{ "getPanel",		 _getPanel },
		{ "isZoomed",		 _isZoomed },
		{ "zoom",			 _zoom },
		{ "unZoom",			 _unZoom },
		{ "centerPanels",	 _centerPanels },
		{ "setSplitterSize", _setSplitterSize },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterProgressBar::_setVertical(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ProgressBar, "U");

	Control->SetVertical();

	return 0;
}

int MOAIGwenRegisterProgressBar::_setHorizontal(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ProgressBar, "U");

	Control->SetHorizontal();

	return 0;
}

int MOAIGwenRegisterProgressBar::_setValue(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ProgressBar, "U");

	Control->SetValue(state.GetValue<float>(2, 0));

	return 0;
}

int MOAIGwenRegisterProgressBar::_getValue(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ProgressBar, "U");

	state.Push(Control->GetValue());

	return 1;
}

int MOAIGwenRegisterProgressBar::_setAutoLabel(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ProgressBar, "U");

	Control->SetAutoLabel(state.GetValue<bool>(2, true));

	return 0;
}

int MOAIGwenRegisterProgressBar::_setCycleSpeed(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ProgressBar, "U");

	Control->SetCycleSpeed(state.GetValue<float>(2, 0));

	return 0;
}

int MOAIGwenRegisterProgressBar::_getCycleSpeed(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ProgressBar, "U");

	state.Push(Control->GetCycleSpeed());

	return 1;
}

void MOAIGwenRegisterProgressBar::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterProgressBar::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setVertical",   _setVertical },
		{ "setHorizontal", _setHorizontal },
		{ "setValue",	   _setValue },
		{ "getValue",	   _getValue },
		{ "setAutoLabel",  _setAutoLabel },
		{ "setCycleSpeed", _setCycleSpeed },
		{ "getCycleSpeed", _getCycleSpeed },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterGroupBox::_setInnerMargin(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::GroupBox, "U");

	Control->SetInnerMargin(state.GetValue<int>(2, 6));

	return 0;
}

void MOAIGwenRegisterGroupBox::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterGroupBox::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setInnerMargin", _setInnerMargin },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterImagePanel::_setUV(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	float uv[4];

	uv[0] = state.GetValue<float>(2, 0);
	uv[1] = state.GetValue<float>(3, 0);
	uv[2] = state.GetValue<float>(4, 1);
	uv[3] = state.GetValue<float>(5, 1);

	Control->SetUV(uv[0], uv[1], uv[2], uv[3]);

	return 0;
}

int MOAIGwenRegisterImagePanel::_setImage(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	Control->SetImage(state.GetValue<cc8*>(2, ""));

	return 0;
}

int MOAIGwenRegisterImagePanel::_getImageName(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	state.Push(Control->GetImage().c_str());

	return 1;
}

int MOAIGwenRegisterImagePanel::_getTextureWidth(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	state.Push(Control->TextureWidth());

	return 1;
}

int MOAIGwenRegisterImagePanel::_getTextureHeight(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	state.Push(Control->TextureHeight());

	return 1;
}

int MOAIGwenRegisterImagePanel::_setDrawColor(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	Gwen::Color value;

	value.r = state.GetValue<u8>(2, 255);
	value.g = state.GetValue<u8>(3, 255);
	value.b = state.GetValue<u8>(4, 255);
	value.a = state.GetValue<u8>(5, 255);

	Control->SetDrawColor(value);

	return 0;
}

int MOAIGwenRegisterImagePanel::_getStretch(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	state.Push(Control->GetStretch());

	return 1;
}

int MOAIGwenRegisterImagePanel::_setStretch(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	Control->SetStretch(state.GetValue<bool>(2, false));

	return 1;
}

int MOAIGwenRegisterImagePanel::_getFailedToLoad(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::ImagePanel, "U");

	state.Push(Control->FailedToLoad());

	return 1;
}

void MOAIGwenRegisterImagePanel::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterImagePanel::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "setUV",			  _setUV },
		{ "setImage",		  _setImage },
		{ "getImageName",	  _getImageName },
		{ "getTextureWidth",  _getTextureWidth },
		{ "getTextureHeight", _getTextureHeight },
		{ "setDrawColor",	  _setDrawColor },
		{ "getStretch",		  _getStretch },
		{ "setStretch",		  _setStretch },
		{ "getFailedToLoad",  _getFailedToLoad },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//================================================================//

int MOAIGwenRegisterStatusBar::_addControl(lua_State* L)
{
	MOAI_GWEN_REGISTER_SETUP(Gwen::Controls::StatusBar, "UU");

	MOAIGwenBase* base = state.GetLuaObject<MOAIGwenBase>(2, true);

	if (!base)
	{
		return 0;
	}

	Control->AddControl(base->Base(), state.GetValue<bool>(3, false));

	return 0;
}

void MOAIGwenRegisterStatusBar::RegisterLuaClass(MOAILuaState& state)
{

}

void MOAIGwenRegisterStatusBar::RegisterLuaFuncs(MOAILuaState& state)
{
	luaL_Reg regTable[] =
	{
		{ "addControl", _addControl },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}