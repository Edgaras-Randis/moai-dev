// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWENSKIN_H
#define MOAIGWENSKIN_H

class MOAIGwenSkinTexture;
class MOAIGwenRender;

class MOAIGwenSkin : public virtual MOAILuaObject, public Gwen::Skin::Base
{
private:

	//----------------------------------------------------------------//

	static int _setRender	(lua_State* L);
	static int _init		(lua_State* L);

public:
	DECL_LUA_FACTORY(MOAIGwenSkin)

		//----------------------------------------------------------------//
					MOAIGwenSkin();
				   ~MOAIGwenSkin();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);


	MOAILuaSharedPtr<MOAIGwenSkinTexture> SkinTexture;
	MOAILuaSharedPtr<MOAIGwenRender>	  Render;

	struct Textures_t
	{
		Gwen::Skin::Texturing::Bordered StatusBar;
		Gwen::Skin::Texturing::Bordered Selection;
		Gwen::Skin::Texturing::Bordered	Shadow;
		Gwen::Skin::Texturing::Bordered	Tooltip;

		struct Panel_t
		{
			Gwen::Skin::Texturing::Bordered Normal;
			Gwen::Skin::Texturing::Bordered Bright;
			Gwen::Skin::Texturing::Bordered Dark;
			Gwen::Skin::Texturing::Bordered Highlight;

		} Panel;

		struct Window_t
		{
			Gwen::Skin::Texturing::Bordered Normal;
			Gwen::Skin::Texturing::Bordered Inactive;
			Gwen::Skin::Texturing::Single Close;
			Gwen::Skin::Texturing::Single Close_Hover;
			Gwen::Skin::Texturing::Single Close_Down;
			Gwen::Skin::Texturing::Single Maxi;
			Gwen::Skin::Texturing::Single Maxi_Hover;
			Gwen::Skin::Texturing::Single Maxi_Down;
			Gwen::Skin::Texturing::Single Mini;
			Gwen::Skin::Texturing::Single Mini_Hover;
			Gwen::Skin::Texturing::Single Mini_Down;
			Gwen::Skin::Texturing::Single Restore;
			Gwen::Skin::Texturing::Single Restore_Hover;
			Gwen::Skin::Texturing::Single Restore_Down;

		} Window;

		struct Checkbox_t
		{
			struct  Active_t
			{
				Gwen::Skin::Texturing::Single Normal;
				Gwen::Skin::Texturing::Single Checked;

			} Active;

			struct  Disabled_t
			{
				Gwen::Skin::Texturing::Single Normal;
				Gwen::Skin::Texturing::Single Checked;

			} Disabled;

		} Checkbox;

		struct  RadioButton_t
		{
			struct  Active_t
			{
				Gwen::Skin::Texturing::Single Normal;
				Gwen::Skin::Texturing::Single Checked;

			} Active;

			struct  Disabled_t
			{
				Gwen::Skin::Texturing::Single Normal;
				Gwen::Skin::Texturing::Single Checked;

			} Disabled;

		} RadioButton;

		struct  TextBox_t
		{
			Gwen::Skin::Texturing::Bordered Normal;
			Gwen::Skin::Texturing::Bordered Focus;
			Gwen::Skin::Texturing::Bordered Disabled;

		} TextBox;

		struct  Tree_t
		{
			Gwen::Skin::Texturing::Bordered Background;
			Gwen::Skin::Texturing::Single Minus;
			Gwen::Skin::Texturing::Single Plus;

		} Tree;


		struct  ProgressBar_t
		{
			Gwen::Skin::Texturing::Bordered Back;
			Gwen::Skin::Texturing::Bordered Front;

		} ProgressBar;

		struct  Scroller_t
		{
			Gwen::Skin::Texturing::Bordered TrackV;
			Gwen::Skin::Texturing::Bordered ButtonV_Normal;
			Gwen::Skin::Texturing::Bordered ButtonV_Hover;
			Gwen::Skin::Texturing::Bordered ButtonV_Down;
			Gwen::Skin::Texturing::Bordered ButtonV_Disabled;
			Gwen::Skin::Texturing::Bordered TrackH;
			Gwen::Skin::Texturing::Bordered ButtonH_Normal;
			Gwen::Skin::Texturing::Bordered ButtonH_Hover;
			Gwen::Skin::Texturing::Bordered ButtonH_Down;
			Gwen::Skin::Texturing::Bordered ButtonH_Disabled;

			struct  Button_t
			{
				Gwen::Skin::Texturing::Bordered	Normal[4];
				Gwen::Skin::Texturing::Bordered	Hover[4];
				Gwen::Skin::Texturing::Bordered	Down[4];
				Gwen::Skin::Texturing::Bordered	Disabled[4];

			} Button;

		} Scroller;

		struct  Menu_t
		{
			Gwen::Skin::Texturing::Single RightArrow;
			Gwen::Skin::Texturing::Single Check;

			Gwen::Skin::Texturing::Bordered Strip;
			Gwen::Skin::Texturing::Bordered Background;
			Gwen::Skin::Texturing::Bordered BackgroundWithMargin;
			Gwen::Skin::Texturing::Bordered Hover;

		} Menu;

		struct  Input_t
		{
			struct  Button_t
			{
				Gwen::Skin::Texturing::Bordered Normal;
				Gwen::Skin::Texturing::Bordered Hovered;
				Gwen::Skin::Texturing::Bordered Disabled;
				Gwen::Skin::Texturing::Bordered Pressed;

			} Button;

			struct  ListBox_t
			{
				Gwen::Skin::Texturing::Bordered Background;
				Gwen::Skin::Texturing::Bordered Hovered;

				Gwen::Skin::Texturing::Bordered EvenLine;
				Gwen::Skin::Texturing::Bordered OddLine;
				Gwen::Skin::Texturing::Bordered EvenLineSelected;
				Gwen::Skin::Texturing::Bordered OddLineSelected;

			} ListBox;

			struct  UpDown_t
			{
				struct  Up_t
				{
					Gwen::Skin::Texturing::Single Normal;
					Gwen::Skin::Texturing::Single Hover;
					Gwen::Skin::Texturing::Single Down;
					Gwen::Skin::Texturing::Single Disabled;

				} Up;

				struct  Down_t
				{
					Gwen::Skin::Texturing::Single Normal;
					Gwen::Skin::Texturing::Single Hover;
					Gwen::Skin::Texturing::Single Down;
					Gwen::Skin::Texturing::Single Disabled;

				} Down;

			} UpDown;

			struct  ComboBox_t
			{
				Gwen::Skin::Texturing::Bordered Normal;
				Gwen::Skin::Texturing::Bordered Hover;
				Gwen::Skin::Texturing::Bordered Down;
				Gwen::Skin::Texturing::Bordered Disabled;

				struct  Button_t
				{
					Gwen::Skin::Texturing::Single Normal;
					Gwen::Skin::Texturing::Single Hover;
					Gwen::Skin::Texturing::Single Down;
					Gwen::Skin::Texturing::Single Disabled;

				} Button;

			} ComboBox;

			struct  Slider_t
			{
				struct  H_t
				{
					Gwen::Skin::Texturing::Single Normal;
					Gwen::Skin::Texturing::Single Hover;
					Gwen::Skin::Texturing::Single Down;
					Gwen::Skin::Texturing::Single Disabled;
				} H;

				struct  V_t
				{
					Gwen::Skin::Texturing::Single Normal;
					Gwen::Skin::Texturing::Single Hover;
					Gwen::Skin::Texturing::Single Down;
					Gwen::Skin::Texturing::Single Disabled;
				} V;

			} Slider;

		} Input;

		struct  Tab_t
		{
			struct  Bottom_t
			{
				Gwen::Skin::Texturing::Bordered Active;
				Gwen::Skin::Texturing::Bordered Inactive;
			} Bottom;

			struct  Top_t
			{
				Gwen::Skin::Texturing::Bordered Active;
				Gwen::Skin::Texturing::Bordered Inactive;
			} Top;

			struct  Left_t
			{
				Gwen::Skin::Texturing::Bordered Active;
				Gwen::Skin::Texturing::Bordered Inactive;
			} Left;

			struct  Right_t
			{
				Gwen::Skin::Texturing::Bordered Active;
				Gwen::Skin::Texturing::Bordered Inactive;
			} Right;

			Gwen::Skin::Texturing::Bordered Control;
			Gwen::Skin::Texturing::Bordered HeaderBar;

		} Tab;

		struct  CategoryList_t
		{
			Gwen::Skin::Texturing::Bordered Outer;
			Gwen::Skin::Texturing::Bordered Inner;
			Gwen::Skin::Texturing::Bordered Header;

		} CategoryList;

		Gwen::Skin::Texturing::Bordered GroupBox;

	} Textures;

	virtual bool Init(MOAIGwenSkinTexture* skinTexture);

	virtual void DrawButton(Gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled);

	virtual void DrawMenuItem(Gwen::Controls::Base* control, bool bSubmenuOpen, bool bChecked);

	virtual void DrawMenuStrip(Gwen::Controls::Base* control);

	virtual void DrawMenu(Gwen::Controls::Base* control, bool bPaddingDisabled);

	virtual void DrawMenuRightArrow(Gwen::Controls::Base* control);

	virtual void DrawShadow(Gwen::Controls::Base* control);

	virtual void DrawRadioButton(Gwen::Controls::Base* control, bool bSelected, bool bDepressed);

	virtual void DrawCheckBox(Gwen::Controls::Base* control, bool bSelected, bool bDepressed);

	virtual void DrawGroupBox(Gwen::Controls::Base* control, int textStart, int textHeight, int textWidth);

	virtual void DrawTextBox(Gwen::Controls::Base* control);

	virtual void DrawActiveTabButton(Gwen::Controls::Base* control, int dir);

	virtual void DrawTabButton(Gwen::Controls::Base* control, bool bActive, int dir);

	virtual void DrawTabControl(Gwen::Controls::Base* control);

	virtual void DrawTabTitleBar(Gwen::Controls::Base* control);

	virtual void DrawGenericPanel(Gwen::Controls::Base* control);

	virtual void DrawWindow(Gwen::Controls::Base* control, int topHeight, bool inFocus);

	virtual void DrawHighlight(Gwen::Controls::Base* control);

	virtual void DrawScrollBar(Gwen::Controls::Base* control, bool isHorizontal, bool bDepressed);

	virtual void DrawScrollBarBar(Gwen::Controls::Base* control, bool bDepressed, bool isHovered, bool isHorizontal);

	virtual void DrawProgressBar(Gwen::Controls::Base* control, bool isHorizontal, float progress);

	virtual void DrawListBox(Gwen::Controls::Base* control);

	virtual void DrawListBoxLine(Gwen::Controls::Base* control, bool bSelected, bool bEven);

	void DrawSliderNotchesH(Gwen::Rect rect, int numNotches, int dist);

	void DrawSliderNotchesV(Gwen::Rect rect, int numNotches, int dist);

	virtual void DrawSlider(Gwen::Controls::Base* control, bool bIsHorizontal, int numNotches, int barSize);

	virtual void DrawComboBox(Gwen::Controls::Base* control, bool bDown, bool bMenuOpen);

	virtual void DrawKeyboardHighlight(Gwen::Controls::Base* control, const Gwen::Rect & r, int iOffset);

	virtual void DrawToolTip(Gwen::Controls::Base* control);

	virtual void DrawScrollButton(Gwen::Controls::Base* control, int iDirection, bool bDepressed, bool bHovered, bool bDisabled);

	virtual void DrawComboDownArrow(Gwen::Controls::Base* control, bool bHovered, bool bDown, bool bMenuOpen, bool bDisabled);

	virtual void DrawNumericUpDownButton(Gwen::Controls::Base* control, bool bDepressed, bool bUp);

	virtual void DrawStatusBar(Gwen::Controls::Base* control);

	virtual void DrawTreeButton(Gwen::Controls::Base* control, bool bOpen);

	void DrawColorDisplay(Gwen::Controls::Base* control, Gwen::Color color);

	virtual void DrawModalControl(Gwen::Controls::Base* control);

	virtual void DrawMenuDivider(Gwen::Controls::Base* control);

	virtual void DrawTreeControl(Gwen::Controls::Base* control);

	virtual void DrawWindowCloseButton(Gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled);

	virtual void DrawWindowMaximizeButton(Gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled, bool bMaximized);

	virtual void DrawWindowMinimizeButton(Gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled);

	virtual void DrawSlideButton(Gwen::Controls::Base* control, bool bDepressed, bool bHorizontal);

	void DrawTreeNode(Gwen::Controls::Base* ctrl, bool bOpen, bool bSelected, int iLabelHeight, int iLabelWidth, int iHalfWay, int iLastBranch, bool bIsRoot);

	void DrawCategoryHolder(Gwen::Controls::Base* ctrl);

	void DrawCategoryInner(Gwen::Controls::Base* ctrl, bool bCollapsed);
};

#endif