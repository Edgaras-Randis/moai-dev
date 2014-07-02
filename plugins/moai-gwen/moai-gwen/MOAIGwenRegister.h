// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENREGISTER_H
#define MOAIGWENREGISTER_H

class MOAIGwenRegisterLabel
{
private:
	
	//----------------------------------------------------------------//

	static int _setText(lua_State* L);
	static int _sizeToContent(lua_State* L);
	static int _setTextColor(lua_State* L);
	static int _setFont(lua_State* L);

	static int _getTextColor(lua_State* L);
	static int _wrap(lua_State* L);
	static int _setWrap(lua_State* L);

	static int _getTextWidth(lua_State* L);
	static int _getTextRight(lua_State* L);
	static int _getTextHeight(lua_State* L);
	static int _getTextX(lua_State* L);
	static int _getTextY(lua_State* L);
	static int _getTextLength(lua_State* L);

	static int _setAlignment(lua_State* L);
	static int _getAlignment(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterButton
{
private:

	//----------------------------------------------------------------//

	static int _setImage(lua_State* L);
	static int _setIsToggle(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterDockBase
{
private:

	//----------------------------------------------------------------//

	static int _getTabControl(lua_State* L);
	static int _getRight(lua_State* L);
	static int _getLeft(lua_State* L);
	static int _getTop(lua_State* L);
	static int _getBottom(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterCollapsibleList
{
private:

	//----------------------------------------------------------------//

	static int _add(lua_State* L);
	static int _addCategory(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterCollapsibleCategory
{
private:

	//----------------------------------------------------------------//

	static int _setText(lua_State* L);
	static int _add(lua_State* L);
public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterTabControl
{
private:

	//----------------------------------------------------------------//

	static int _addPage(lua_State* L);
public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterCrossSplitter
{
private:

	//----------------------------------------------------------------//

	static int _setPanel(lua_State* L);
	static int _getPanel(lua_State* L);
	static int _isZoomed(lua_State* L);
	static int _zoom(lua_State* L);
	static int _unZoom(lua_State* L);
	static int _centerPanels(lua_State* L);
	static int _setSplitterSize(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterProgressBar
{
private:

	//----------------------------------------------------------------//

	static int _setVertical(lua_State* L);
	static int _setHorizontal(lua_State* L);

	static int _setValue(lua_State* L);
	static int _getValue(lua_State* L);

	static int _setAutoLabel(lua_State* L);

	static int _setCycleSpeed(lua_State* L);
	static int _getCycleSpeed(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterGroupBox
{
private:

	//----------------------------------------------------------------//

	static int _setInnerMargin(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterImagePanel
{
private:

	//----------------------------------------------------------------//

	static int _setUV(lua_State* L);
	static int _setImage(lua_State* L);
	static int _getImageName(lua_State* L);
	static int _getTextureWidth(lua_State* L);
	static int _getTextureHeight(lua_State* L);
	static int _setDrawColor(lua_State* L);
	static int _getStretch(lua_State* L);
	static int _setStretch(lua_State* L);
	static int _getFailedToLoad(lua_State* L);
public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterStatusBar
{
private:

	//----------------------------------------------------------------//

	static int _addControl(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

#endif
