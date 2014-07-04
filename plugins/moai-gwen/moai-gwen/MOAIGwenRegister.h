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

class MOAIGwenRegisterComboBox
{
private:

	//----------------------------------------------------------------//

	static int _selectItem(lua_State* L);
	static int _selectItemByName(lua_State* L);
	static int _getSelectedItem(lua_State* L);
	static int _openList(lua_State* L);
	static int _closeList(lua_State* L);
	static int _clearItems(lua_State* L);
	static int _addItem(lua_State* L);
	static int _isMenuOpen(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterMenuItem
{
private:

	//----------------------------------------------------------------//

	static int _getMenu(lua_State* L);
	static int _isMenuOpen(lua_State* L);
	static int _closeMenu(lua_State* L);
	static int _toggleMenu(lua_State* L);
	static int _setOnStrip(lua_State* L);
	static int _isOnStrip(lua_State* L);
	static int _setCheckable(lua_State* L);
	static int _setChecked(lua_State* L);
	static int _getChecked(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterTextBox
{
private:

	//----------------------------------------------------------------//

	static int _setEditable(lua_State* L);
	static int _setSelectAllOnFocus(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterTextBoxNumeric
{
private:

	//----------------------------------------------------------------//

	static int _getFloatFromText(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterTextBoxMultiline
{
private:

	//----------------------------------------------------------------//

	static int _getCurrentLine(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterTextBoxPassword
{
private:

	//----------------------------------------------------------------//

	static int _setPasswordChar(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterCheckBox
{
private:

	//----------------------------------------------------------------//

	static int _setChecked(lua_State* L);
	static int _toggle(lua_State* L);
	static int _isChecked(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterCheckBoxWithLabel
{
private:

	//----------------------------------------------------------------//

	static int _getCheckBox(lua_State* L);
	static int _getLabel(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

class MOAIGwenRegisterNumericUpDown
{
private:

	//----------------------------------------------------------------//

	static int _setMin(lua_State* L);
	static int _setMax(lua_State* L);
	static int _setValue(lua_State* L);

public:

	static void	RegisterLuaClass(MOAILuaState& state);
	static void	RegisterLuaFuncs(MOAILuaState& state);
};

#endif
