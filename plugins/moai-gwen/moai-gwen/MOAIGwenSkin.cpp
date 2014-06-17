// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/MOAIGwenSkinTexture.h>
#include <moai-gwen/MOAIGwenSkin.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
MOAIGwenSkin::MOAIGwenSkin() : skinTexture(NULL)
{

}

MOAIGwenSkin::~MOAIGwenSkin()
{

}

void MOAIGwenSkin::RegisterLuaClass(MOAILuaState& state)
{

}
void MOAIGwenSkin::RegisterLuaFuncs(MOAILuaState& state)
{

}

void MOAIGwenSkin::Init(MOAIGwenSkinTexture* texture)
{
	if (!texture)
	{
		return;
	}

	if (skinTexture)
	{
		this->LuaRelease(skinTexture);
		skinTexture = NULL;
	}

	this->LuaRetain(texture);

	skinTexture = texture;

	m_DefaultFont.facename = L"Microsoft Sans Serif";
	m_DefaultFont.size = 11;

	Colors.Window.TitleActive = skinTexture->GetPixelColor(4 + 8 * 0, 508, Gwen::Color(255, 0, 0));
	Colors.Window.TitleInactive = skinTexture->GetPixelColor(4 + 8 * 1, 508, Gwen::Color(255, 255, 0));
	Colors.Button.Normal = skinTexture->GetPixelColor(4 + 8 * 2, 508, Gwen::Color(255, 255, 0));
	Colors.Button.Hover = skinTexture->GetPixelColor(4 + 8 * 3, 508, Gwen::Color(255, 255, 0));
	Colors.Button.Down = skinTexture->GetPixelColor(4 + 8 * 2, 500, Gwen::Color(255, 255, 0));
	Colors.Button.Disabled = skinTexture->GetPixelColor(4 + 8 * 3, 500, Gwen::Color(255, 255, 0));
	Colors.Tab.Active.Normal = skinTexture->GetPixelColor(4 + 8 * 4, 508, Gwen::Color(255, 255, 0));
	Colors.Tab.Active.Hover = skinTexture->GetPixelColor(4 + 8 * 5, 508, Gwen::Color(255, 255, 0));
	Colors.Tab.Active.Down = skinTexture->GetPixelColor(4 + 8 * 4, 500, Gwen::Color(255, 255, 0));
	Colors.Tab.Active.Disabled = skinTexture->GetPixelColor(4 + 8 * 5, 500, Gwen::Color(255, 255, 0));
	Colors.Tab.Inactive.Normal = skinTexture->GetPixelColor(4 + 8 * 6, 508, Gwen::Color(255, 255, 0));
	Colors.Tab.Inactive.Hover = skinTexture->GetPixelColor(4 + 8 * 7, 508, Gwen::Color(255, 255, 0));
	Colors.Tab.Inactive.Down = skinTexture->GetPixelColor(4 + 8 * 6, 500, Gwen::Color(255, 255, 0));
	Colors.Tab.Inactive.Disabled = skinTexture->GetPixelColor(4 + 8 * 7, 500, Gwen::Color(255, 255, 0));
	Colors.Label.Default = skinTexture->GetPixelColor(4 + 8 * 8, 508, Gwen::Color(255, 255, 0));
	Colors.Label.Bright = skinTexture->GetPixelColor(4 + 8 * 9, 508, Gwen::Color(255, 255, 0));
	Colors.Label.Dark = skinTexture->GetPixelColor(4 + 8 * 8, 500, Gwen::Color(255, 255, 0));
	Colors.Label.Highlight = skinTexture->GetPixelColor(4 + 8 * 9, 500, Gwen::Color(255, 255, 0));
	Colors.Tree.Lines = skinTexture->GetPixelColor(4 + 8 * 10, 508, Gwen::Color(255, 255, 0));
	Colors.Tree.Normal = skinTexture->GetPixelColor(4 + 8 * 11, 508, Gwen::Color(255, 255, 0));
	Colors.Tree.Hover = skinTexture->GetPixelColor(4 + 8 * 10, 500, Gwen::Color(255, 255, 0));
	Colors.Tree.Selected = skinTexture->GetPixelColor(4 + 8 * 11, 500, Gwen::Color(255, 255, 0));
	Colors.Properties.Line_Normal = skinTexture->GetPixelColor(4 + 8 * 12, 508, Gwen::Color(255, 255, 0));
	Colors.Properties.Line_Selected = skinTexture->GetPixelColor(4 + 8 * 13, 508, Gwen::Color(255, 255, 0));
	Colors.Properties.Line_Hover = skinTexture->GetPixelColor(4 + 8 * 12, 500, Gwen::Color(255, 255, 0));
	Colors.Properties.Title = skinTexture->GetPixelColor(4 + 8 * 13, 500, Gwen::Color(255, 255, 0));
	Colors.Properties.Column_Normal = skinTexture->GetPixelColor(4 + 8 * 14, 508, Gwen::Color(255, 255, 0));
	Colors.Properties.Column_Selected = skinTexture->GetPixelColor(4 + 8 * 15, 508, Gwen::Color(255, 255, 0));
	Colors.Properties.Column_Hover = skinTexture->GetPixelColor(4 + 8 * 14, 500, Gwen::Color(255, 255, 0));
	Colors.Properties.Border = skinTexture->GetPixelColor(4 + 8 * 15, 500, Gwen::Color(255, 255, 0));
	Colors.Properties.Label_Normal = skinTexture->GetPixelColor(4 + 8 * 16, 508, Gwen::Color(255, 255, 0));
	Colors.Properties.Label_Selected = skinTexture->GetPixelColor(4 + 8 * 17, 508, Gwen::Color(255, 255, 0));
	Colors.Properties.Label_Hover = skinTexture->GetPixelColor(4 + 8 * 16, 500, Gwen::Color(255, 255, 0));
	Colors.ModalBackground = skinTexture->GetPixelColor(4 + 8 * 18, 508, Gwen::Color(255, 255, 0));
	Colors.TooltipText = skinTexture->GetPixelColor(4 + 8 * 19, 508, Gwen::Color(255, 255, 0));
	Colors.Category.Header = skinTexture->GetPixelColor(4 + 8 * 18, 500, Gwen::Color(255, 255, 0));
	Colors.Category.Header_Closed = skinTexture->GetPixelColor(4 + 8 * 19, 500, Gwen::Color(255, 255, 0));
	Colors.Category.Line.Text = skinTexture->GetPixelColor(4 + 8 * 20, 508, Gwen::Color(255, 255, 0));
	Colors.Category.Line.Text_Hover = skinTexture->GetPixelColor(4 + 8 * 21, 508, Gwen::Color(255, 255, 0));
	Colors.Category.Line.Text_Selected = skinTexture->GetPixelColor(4 + 8 * 20, 500, Gwen::Color(255, 255, 0));
	Colors.Category.Line.Button = skinTexture->GetPixelColor(4 + 8 * 21, 500, Gwen::Color(255, 255, 0));
	Colors.Category.Line.Button_Hover = skinTexture->GetPixelColor(4 + 8 * 22, 508, Gwen::Color(255, 255, 0));
	Colors.Category.Line.Button_Selected = skinTexture->GetPixelColor(4 + 8 * 23, 508, Gwen::Color(255, 255, 0));
	Colors.Category.LineAlt.Text = skinTexture->GetPixelColor(4 + 8 * 22, 500, Gwen::Color(255, 255, 0));
	Colors.Category.LineAlt.Text_Hover = skinTexture->GetPixelColor(4 + 8 * 23, 500, Gwen::Color(255, 255, 0));
	Colors.Category.LineAlt.Text_Selected = skinTexture->GetPixelColor(4 + 8 * 24, 508, Gwen::Color(255, 255, 0));
	Colors.Category.LineAlt.Button = skinTexture->GetPixelColor(4 + 8 * 25, 508, Gwen::Color(255, 255, 0));
	Colors.Category.LineAlt.Button_Hover = skinTexture->GetPixelColor(4 + 8 * 24, 500, Gwen::Color(255, 255, 0));
	Colors.Category.LineAlt.Button_Selected = skinTexture->GetPixelColor(4 + 8 * 25, 500, Gwen::Color(255, 255, 0));

	Textures.Shadow.Init(skinTexture, 448, 0, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Tooltip.Init(skinTexture, 128, 320, 127, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.StatusBar.Init(skinTexture, 128, 288, 127, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Selection.Init(skinTexture, 384, 32, 31, 31, Gwen::Margin(4, 4, 4, 4));
	Textures.Panel.Normal.Init(skinTexture, 256, 0, 63, 63, Gwen::Margin(16, 16, 16, 16));
	Textures.Panel.Bright.Init(skinTexture, 256 + 64, 0, 63, 63, Gwen::Margin(16, 16, 16, 16));
	Textures.Panel.Dark.Init(skinTexture, 256, 64, 63, 63, Gwen::Margin(16, 16, 16, 16));
	Textures.Panel.Highlight.Init(skinTexture, 256 + 64, 64, 63, 63, Gwen::Margin(16, 16, 16, 16));
	Textures.Window.Normal.Init(skinTexture, 0, 0, 127, 127, Gwen::Margin(8, 32, 8, 8));
	Textures.Window.Inactive.Init(skinTexture, 128, 0, 127, 127, Gwen::Margin(8, 32, 8, 8));
	Textures.Checkbox.Active.Checked.Init(skinTexture, 448, 32, 15, 15);
	Textures.Checkbox.Active.Normal.Init(skinTexture, 464, 32, 15, 15);
	Textures.Checkbox.Disabled.Checked.Init(skinTexture, 448, 48, 15, 15);
	Textures.Checkbox.Disabled.Normal.Init(skinTexture, 464, 48, 15, 15);
	Textures.RadioButton.Active.Checked.Init(skinTexture, 448, 64, 15, 15);
	Textures.RadioButton.Active.Normal.Init(skinTexture, 464, 64, 15, 15);
	Textures.RadioButton.Disabled.Checked.Init(skinTexture, 448, 80, 15, 15);
	Textures.RadioButton.Disabled.Normal.Init(skinTexture, 464, 80, 15, 15);
	Textures.TextBox.Normal.Init(skinTexture, 0, 150, 127, 21, Gwen::Margin(4, 4, 4, 4));
	Textures.TextBox.Focus.Init(skinTexture, 0, 172, 127, 21, Gwen::Margin(4, 4, 4, 4));
	Textures.TextBox.Disabled.Init(skinTexture, 0, 193, 127, 21, Gwen::Margin(4, 4, 4, 4));
	Textures.Menu.Strip.Init(skinTexture, 0, 128, 127, 21, Gwen::Margin(1, 1, 1, 1));
	Textures.Menu.BackgroundWithMargin.Init(skinTexture, 128, 128, 127, 63, Gwen::Margin(24, 8, 8, 8));
	Textures.Menu.Background.Init(skinTexture, 128, 192, 127, 63, Gwen::Margin(8, 8, 8, 8));
	Textures.Menu.Hover.Init(skinTexture, 128, 256, 127, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Menu.RightArrow.Init(skinTexture, 464, 112, 15, 15);
	Textures.Menu.Check.Init(skinTexture, 448, 112, 15, 15);
	Textures.Tab.Control.Init(skinTexture, 0, 256, 127, 127, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.Bottom.Active.Init(skinTexture, 0, 416, 63, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.Bottom.Inactive.Init(skinTexture, 0 + 128, 416, 63, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.Top.Active.Init(skinTexture, 0, 384, 63, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.Top.Inactive.Init(skinTexture, 0 + 128, 384, 63, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.Left.Active.Init(skinTexture, 64, 384, 31, 63, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.Left.Inactive.Init(skinTexture, 64 + 128, 384, 31, 63, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.Right.Active.Init(skinTexture, 96, 384, 31, 63, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.Right.Inactive.Init(skinTexture, 96 + 128, 384, 31, 63, Gwen::Margin(8, 8, 8, 8));
	Textures.Tab.HeaderBar.Init(skinTexture, 128, 352, 127, 31, Gwen::Margin(4, 4, 4, 4));
	Textures.Window.Close.Init(skinTexture, 32, 448, 31, 31);
	Textures.Window.Close_Hover.Init(skinTexture, 64, 448, 31, 31);
	Textures.Window.Close_Down.Init(skinTexture, 96, 448, 31, 31);
	Textures.Window.Maxi.Init(skinTexture, 32 + 96 * 2, 448, 31, 31);
	Textures.Window.Maxi_Hover.Init(skinTexture, 64 + 96 * 2, 448, 31, 31);
	Textures.Window.Maxi_Down.Init(skinTexture, 96 + 96 * 2, 448, 31, 31);
	Textures.Window.Restore.Init(skinTexture, 32 + 96 * 2, 448 + 32, 31, 31);
	Textures.Window.Restore_Hover.Init(skinTexture, 64 + 96 * 2, 448 + 32, 31, 31);
	Textures.Window.Restore_Down.Init(skinTexture, 96 + 96 * 2, 448 + 32, 31, 31);
	Textures.Window.Mini.Init(skinTexture, 32 + 96, 448, 31, 31);
	Textures.Window.Mini_Hover.Init(skinTexture, 64 + 96, 448, 31, 31);
	Textures.Window.Mini_Down.Init(skinTexture, 96 + 96, 448, 31, 31);
	Textures.Tree.Background.Init(skinTexture, 256, 128, 127, 127, Gwen::Margin(16, 16, 16, 16));
	Textures.Tree.Plus.Init(skinTexture, 448, 96, 15, 15);
	Textures.Tree.Minus.Init(skinTexture, 464, 96, 15, 15);
	Textures.Input.Button.Normal.Init(skinTexture, 480, 0, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.Button.Hovered.Init(skinTexture, 480, 32, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.Button.Disabled.Init(skinTexture, 480, 64, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.Button.Pressed.Init(skinTexture, 480, 96, 31, 31, Gwen::Margin(8, 8, 8, 8));

	for (int i = 0; i < 4; i++)
	{
		Textures.Scroller.Button.Normal[i].Init(skinTexture, 464 + 0, 208 + i * 16, 15, 15, Gwen::Margin(2, 2, 2, 2));
		Textures.Scroller.Button.Hover[i].Init(skinTexture, 480, 208 + i * 16, 15, 15, Gwen::Margin(2, 2, 2, 2));
		Textures.Scroller.Button.Down[i].Init(skinTexture, 464, 272 + i * 16, 15, 15, Gwen::Margin(2, 2, 2, 2));
		Textures.Scroller.Button.Disabled[i].Init(skinTexture, 480 + 48, 272 + i * 16, 15, 15, Gwen::Margin(2, 2, 2, 2));
	}

	Textures.Scroller.TrackV.Init(skinTexture, 384, 208, 15, 127, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.ButtonV_Normal.Init(skinTexture, 384 + 16, 208, 15, 127, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.ButtonV_Hover.Init(skinTexture, 384 + 32, 208, 15, 127, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.ButtonV_Down.Init(skinTexture, 384 + 48, 208, 15, 127, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.ButtonV_Disabled.Init(skinTexture, 384 + 64, 208, 15, 127, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.TrackH.Init(skinTexture, 384, 128, 127, 15, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.ButtonH_Normal.Init(skinTexture, 384, 128 + 16, 127, 15, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.ButtonH_Hover.Init(skinTexture, 384, 128 + 32, 127, 15, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.ButtonH_Down.Init(skinTexture, 384, 128 + 48, 127, 15, Gwen::Margin(4, 4, 4, 4));
	Textures.Scroller.ButtonH_Disabled.Init(skinTexture, 384, 128 + 64, 127, 15, Gwen::Margin(4, 4, 4, 4));
	Textures.Input.ListBox.Background.Init(skinTexture, 256, 256, 63, 127, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.ListBox.Hovered.Init(skinTexture, 320, 320, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.ListBox.EvenLine.Init(skinTexture, 352, 256, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.ListBox.OddLine.Init(skinTexture, 352, 288, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.ListBox.EvenLineSelected.Init(skinTexture, 320, 256, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.ListBox.OddLineSelected.Init(skinTexture, 320, 288, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.ComboBox.Normal.Init(skinTexture, 384, 336, 127, 31, Gwen::Margin(8, 8, 32, 8));
	Textures.Input.ComboBox.Hover.Init(skinTexture, 384, 336 + 32, 127, 31, Gwen::Margin(8, 8, 32, 8));
	Textures.Input.ComboBox.Down.Init(skinTexture, 384, 336 + 64, 127, 31, Gwen::Margin(8, 8, 32, 8));
	Textures.Input.ComboBox.Disabled.Init(skinTexture, 384, 336 + 96, 127, 31, Gwen::Margin(8, 8, 32, 8));
	Textures.Input.ComboBox.Button.Normal.Init(skinTexture, 496, 272, 15, 15);
	Textures.Input.ComboBox.Button.Hover.Init(skinTexture, 496, 272 + 16, 15, 15);
	Textures.Input.ComboBox.Button.Down.Init(skinTexture, 496, 272 + 32, 15, 15);
	Textures.Input.ComboBox.Button.Disabled.Init(skinTexture, 496, 272 + 48, 15, 15);
	Textures.Input.UpDown.Up.Normal.Init(skinTexture, 384, 112, 7, 7);
	Textures.Input.UpDown.Up.Hover.Init(skinTexture, 384 + 8, 112, 7, 7);
	Textures.Input.UpDown.Up.Down.Init(skinTexture, 384 + 16, 112, 7, 7);
	Textures.Input.UpDown.Up.Disabled.Init(skinTexture, 384 + 24, 112, 7, 7);
	Textures.Input.UpDown.Down.Normal.Init(skinTexture, 384, 120, 7, 7);
	Textures.Input.UpDown.Down.Hover.Init(skinTexture, 384 + 8, 120, 7, 7);
	Textures.Input.UpDown.Down.Down.Init(skinTexture, 384 + 16, 120, 7, 7);
	Textures.Input.UpDown.Down.Disabled.Init(skinTexture, 384 + 24, 120, 7, 7);
	Textures.ProgressBar.Back.Init(skinTexture, 384, 0, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.ProgressBar.Front.Init(skinTexture, 384 + 32, 0, 31, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.Input.Slider.H.Normal.Init(skinTexture, 416, 32, 15, 15);
	Textures.Input.Slider.H.Hover.Init(skinTexture, 416, 32 + 16, 15, 15);
	Textures.Input.Slider.H.Down.Init(skinTexture, 416, 32 + 32, 15, 15);
	Textures.Input.Slider.H.Disabled.Init(skinTexture, 416, 32 + 48, 15, 15);
	Textures.Input.Slider.V.Normal.Init(skinTexture, 416 + 16, 32, 15, 15);
	Textures.Input.Slider.V.Hover.Init(skinTexture, 416 + 16, 32 + 16, 15, 15);
	Textures.Input.Slider.V.Down.Init(skinTexture, 416 + 16, 32 + 32, 15, 15);
	Textures.Input.Slider.V.Disabled.Init(skinTexture, 416 + 16, 32 + 48, 15, 15);
	Textures.CategoryList.Outer.Init(skinTexture, 256, 384, 63, 63, Gwen::Margin(8, 8, 8, 8));
	Textures.CategoryList.Inner.Init(skinTexture, 256 + 64, 384, 63, 63, Gwen::Margin(8, 21, 8, 8));
	Textures.CategoryList.Header.Init(skinTexture, 320, 352, 63, 31, Gwen::Margin(8, 8, 8, 8));
	Textures.GroupBox.Init(skinTexture, 0, 448, 31, 31, Gwen::Margin(8, 8, 8, 8));
}


void MOAIGwenSkin::DrawButton(Gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled)
{
	if (bDisabled)	{ return Textures.Input.Button.Disabled.Draw(GetRender(), control->GetRenderBounds()); }

	if (bDepressed)	{ return Textures.Input.Button.Pressed.Draw(GetRender(), control->GetRenderBounds()); }

	if (bHovered)		{ return Textures.Input.Button.Hovered.Draw(GetRender(), control->GetRenderBounds()); }

	Textures.Input.Button.Normal.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawMenuItem(Gwen::Controls::Base* control, bool bSubmenuOpen, bool bChecked)
{
	const Gwen::Rect & rect = control->GetRenderBounds();

	if (bSubmenuOpen || control->IsHovered())	{ Textures.Menu.Hover.Draw(GetRender(), rect); }

	if (bChecked) { Textures.Menu.Check.Draw(GetRender(), Gwen::Rect(rect.x + 4, rect.y + 3, 15, 15)); }
}

void MOAIGwenSkin::DrawMenuStrip(Gwen::Controls::Base* control)
{
	Textures.Menu.Strip.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawMenu(Gwen::Controls::Base* control, bool bPaddingDisabled)
{
	if (!bPaddingDisabled)
	{
		return Textures.Menu.BackgroundWithMargin.Draw(GetRender(), control->GetRenderBounds());
	}

	Textures.Menu.Background.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawMenuRightArrow(Gwen::Controls::Base* control)
{
	Textures.Menu.RightArrow.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawShadow(Gwen::Controls::Base* control)
{
	Gwen::Rect r = control->GetRenderBounds();
	r.x -= 4;
	r.y -= 4;
	r.w += 10;
	r.h += 10;
	Textures.Shadow.Draw(GetRender(), r);
}

void MOAIGwenSkin::DrawRadioButton(Gwen::Controls::Base* control, bool bSelected, bool bDepressed)
{
	if (bSelected)
	{
		if (control->IsDisabled())
		{
			Textures.RadioButton.Disabled.Checked.Draw(GetRender(), control->GetRenderBounds());
		}
		else
		{
			Textures.RadioButton.Active.Checked.Draw(GetRender(), control->GetRenderBounds());
		}
	}
	else
	{
		if (control->IsDisabled())
		{
			Textures.RadioButton.Disabled.Normal.Draw(GetRender(), control->GetRenderBounds());
		}
		else
		{
			Textures.RadioButton.Active.Normal.Draw(GetRender(), control->GetRenderBounds());
		}
	}
}


void MOAIGwenSkin::DrawCheckBox(Gwen::Controls::Base* control, bool bSelected, bool bDepressed)
{
	if (bSelected)
	{
		if (control->IsDisabled())
		{
			Textures.Checkbox.Disabled.Checked.Draw(GetRender(), control->GetRenderBounds());
		}
		else
		{
			Textures.Checkbox.Active.Checked.Draw(GetRender(), control->GetRenderBounds());
		}
	}
	else
	{
		if (control->IsDisabled())
		{
			Textures.Checkbox.Disabled.Normal.Draw(GetRender(), control->GetRenderBounds());
		}
		else
		{
			Textures.Checkbox.Active.Normal.Draw(GetRender(), control->GetRenderBounds());
		}
	}
}

void MOAIGwenSkin::DrawGroupBox(Gwen::Controls::Base* control, int textStart, int textHeight, int textWidth)
{
	Gwen::Rect rect = control->GetRenderBounds();
	rect.y += textHeight * 0.5f;
	rect.h -= textHeight * 0.5f;
	Textures.GroupBox.Draw(GetRender(), rect, Gwen::Colors::White, true, false);
	rect.x += textStart + textWidth - 4;
	rect.w -= textStart + textWidth - 4;
	Textures.GroupBox.Draw(GetRender(), rect, Gwen::Colors::White, false, true, false, false, false, false, false, false, false);
}

void MOAIGwenSkin::DrawTextBox(Gwen::Controls::Base* control)
{
	if (control->IsDisabled())
	{
		return Textures.TextBox.Disabled.Draw(GetRender(), control->GetRenderBounds());
	}

	if (control->HasFocus())
	{
		Textures.TextBox.Focus.Draw(GetRender(), control->GetRenderBounds());
	}
	else
	{
		Textures.TextBox.Normal.Draw(GetRender(), control->GetRenderBounds());
	}
}

void MOAIGwenSkin::DrawActiveTabButton(Gwen::Controls::Base* control, int dir)
{
	if (dir == Gwen::Pos::Bottom)	{ return Textures.Tab.Bottom.Active.Draw(GetRender(), control->GetRenderBounds() + Gwen::Rect(0, -8, 0, 8)); }

	if (dir == Gwen::Pos::Top)		{ return Textures.Tab.Top.Active.Draw(GetRender(), control->GetRenderBounds() + Gwen::Rect(0, 0, 0, 8)); }

	if (dir == Gwen::Pos::Left)		{ return Textures.Tab.Left.Active.Draw(GetRender(), control->GetRenderBounds() + Gwen::Rect(0, 0, 8, 0)); }

	if (dir == Gwen::Pos::Right)	{ return Textures.Tab.Right.Active.Draw(GetRender(), control->GetRenderBounds() + Gwen::Rect(-8, 0, 8, 0)); }
}

void MOAIGwenSkin::DrawTabButton(Gwen::Controls::Base* control, bool bActive, int dir)
{
	if (bActive)
	{
		return DrawActiveTabButton(control, dir);
	}

	if (dir == Gwen::Pos::Bottom)	{ return Textures.Tab.Bottom.Inactive.Draw(GetRender(), control->GetRenderBounds()); }

	if (dir == Gwen::Pos::Top)		{ return Textures.Tab.Top.Inactive.Draw(GetRender(), control->GetRenderBounds()); }

	if (dir == Gwen::Pos::Left)		{ return Textures.Tab.Left.Inactive.Draw(GetRender(), control->GetRenderBounds()); }

	if (dir == Gwen::Pos::Right)	{ return Textures.Tab.Right.Inactive.Draw(GetRender(), control->GetRenderBounds()); }
}

void MOAIGwenSkin::DrawTabControl(Gwen::Controls::Base* control)
{
	Textures.Tab.Control.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawTabTitleBar(Gwen::Controls::Base* control)
{
	Textures.Tab.HeaderBar.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawGenericPanel(Gwen::Controls::Base* control)
{
	Textures.Panel.Normal.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawWindow(Gwen::Controls::Base* control, int topHeight, bool inFocus)
{
	if (inFocus) { Textures.Window.Normal.Draw(GetRender(), control->GetRenderBounds()); }
	else { Textures.Window.Inactive.Draw(GetRender(), control->GetRenderBounds()); }
}

void MOAIGwenSkin::DrawHighlight(Gwen::Controls::Base* control)
{
	Gwen::Rect rect = control->GetRenderBounds();
	GetRender()->SetDrawColor(Gwen::Color(255, 100, 255, 255));
	GetRender()->DrawFilledRect(rect);
}

void MOAIGwenSkin::DrawScrollBar(Gwen::Controls::Base* control, bool isHorizontal, bool bDepressed)
{
	if (isHorizontal)
	{
		Textures.Scroller.TrackH.Draw(GetRender(), control->GetRenderBounds());
	}
	else
	{
		Textures.Scroller.TrackV.Draw(GetRender(), control->GetRenderBounds());
	}
}

void MOAIGwenSkin::DrawScrollBarBar(Gwen::Controls::Base* control, bool bDepressed, bool isHovered, bool isHorizontal)
{
	if (!isHorizontal)
	{
		if (control->IsDisabled())
		{
			return Textures.Scroller.ButtonV_Disabled.Draw(GetRender(), control->GetRenderBounds());
		}

		if (bDepressed)
		{
			return Textures.Scroller.ButtonV_Down.Draw(GetRender(), control->GetRenderBounds());
		}

		if (isHovered)
		{
			return Textures.Scroller.ButtonV_Hover.Draw(GetRender(), control->GetRenderBounds());
		}

		return Textures.Scroller.ButtonV_Normal.Draw(GetRender(), control->GetRenderBounds());
	}

	if (control->IsDisabled())
	{
		return Textures.Scroller.ButtonH_Disabled.Draw(GetRender(), control->GetRenderBounds());
	}

	if (bDepressed)
	{
		return Textures.Scroller.ButtonH_Down.Draw(GetRender(), control->GetRenderBounds());
	}

	if (isHovered)
	{
		return Textures.Scroller.ButtonH_Hover.Draw(GetRender(), control->GetRenderBounds());
	}

	return Textures.Scroller.ButtonH_Normal.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawProgressBar(Gwen::Controls::Base* control, bool isHorizontal, float progress)
{
	Gwen::Rect rect = control->GetRenderBounds();
	Gwen::Color FillColour(0, 211, 40, 255);

	if (isHorizontal)
	{
		Textures.ProgressBar.Back.Draw(GetRender(), rect);
		rect.w *= progress;

		if (rect.w > 0)
		{
			Textures.ProgressBar.Front.Draw(GetRender(), rect);
		}
	}
	else
	{
		Textures.ProgressBar.Back.Draw(GetRender(), rect);
		int inv_progress = rect.h * (1 - progress);
		rect.y += inv_progress;
		rect.h -= inv_progress;
		Textures.ProgressBar.Front.Draw(GetRender(), rect);
	}
}

void MOAIGwenSkin::DrawListBox(Gwen::Controls::Base* control)
{
	return Textures.Input.ListBox.Background.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawListBoxLine(Gwen::Controls::Base* control, bool bSelected, bool bEven)
{
	if (bSelected)
	{
		if (bEven)
		{
			return Textures.Input.ListBox.EvenLineSelected.Draw(GetRender(), control->GetRenderBounds());
		}
		else
		{
			return Textures.Input.ListBox.OddLineSelected.Draw(GetRender(), control->GetRenderBounds());
		}
	}

	if (control->IsHovered())
	{
		return Textures.Input.ListBox.Hovered.Draw(GetRender(), control->GetRenderBounds());
	}

	if (bEven)
	{
		return Textures.Input.ListBox.EvenLine.Draw(GetRender(), control->GetRenderBounds());
	}

	return Textures.Input.ListBox.OddLine.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawSliderNotchesH(Gwen::Rect rect, int numNotches, int dist)
{
	if (numNotches == 0) { return; }

	float iSpacing = (float)rect.w / (float)numNotches;

	for (int i = 0; i < numNotches + 1; i++)
	{
		GetRender()->DrawFilledRect(Gwen::Rect(rect.x + iSpacing * i, rect.y + dist - 2, 1, 5));
	}
}

void MOAIGwenSkin::DrawSliderNotchesV(Gwen::Rect rect, int numNotches, int dist)
{
	if (numNotches == 0) { return; }

	float iSpacing = (float)rect.h / (float)numNotches;

	for (int i = 0; i < numNotches + 1; i++)
	{
		GetRender()->DrawFilledRect(Gwen::Rect(rect.x + dist - 1, rect.y + iSpacing * i, 5, 1));
	}
}

void MOAIGwenSkin::DrawSlider(Gwen::Controls::Base* control, bool bIsHorizontal, int numNotches, int barSize)
{
	if (bIsHorizontal)
	{
		Gwen::Rect rect = control->GetRenderBounds();
		rect.x += barSize * 0.5;
		rect.w -= barSize;
		rect.y += rect.h * 0.5 - 1;
		rect.h = 1;
		GetRender()->SetDrawColor(Gwen::Color(0, 0, 0, 100));
		DrawSliderNotchesH(rect, numNotches, barSize * 0.5);
		return GetRender()->DrawFilledRect(rect);
	}

	Gwen::Rect rect = control->GetRenderBounds();
	rect.y += barSize * 0.5;
	rect.h -= barSize;
	rect.x += rect.w * 0.5 - 1;
	rect.w = 1;
	GetRender()->SetDrawColor(Gwen::Color(0, 0, 0, 100));
	DrawSliderNotchesV(rect, numNotches, barSize * 0.4);
	return GetRender()->DrawFilledRect(rect);
}

void MOAIGwenSkin::DrawComboBox(Gwen::Controls::Base* control, bool bDown, bool bMenuOpen)
{
	if (control->IsDisabled())
	{
		return Textures.Input.ComboBox.Disabled.Draw(GetRender(), control->GetRenderBounds());
	}

	if (bDown || bMenuOpen)
	{
		return Textures.Input.ComboBox.Down.Draw(GetRender(), control->GetRenderBounds());
	}

	if (control->IsHovered())
	{
		return Textures.Input.ComboBox.Hover.Draw(GetRender(), control->GetRenderBounds());
	}

	Textures.Input.ComboBox.Normal.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawKeyboardHighlight(Gwen::Controls::Base* control, const Gwen::Rect & r, int iOffset)
{
	Gwen::Rect rect = r;
	rect.x += iOffset;
	rect.y += iOffset;
	rect.w -= iOffset * 2;
	rect.h -= iOffset * 2;
	//draw the top and bottom
	bool skip = true;

	for (int i = 0; i < rect.w * 0.5; i++)
	{
		m_Render->SetDrawColor(Gwen::Color(0, 0, 0, 255));

		if (!skip)
		{
			GetRender()->DrawPixel(rect.x + (i * 2), rect.y);
			GetRender()->DrawPixel(rect.x + (i * 2), rect.y + rect.h - 1);
		}
		else
		{
			skip = !skip;
		}
	}

	skip = false;

	for (int i = 0; i < rect.h * 0.5; i++)
	{
		GetRender()->SetDrawColor(Gwen::Color(0, 0, 0, 255));

		if (!skip)
		{
			GetRender()->DrawPixel(rect.x, rect.y + i * 2);
			GetRender()->DrawPixel(rect.x + rect.w - 1, rect.y + i * 2);
		}
		else
		{
			skip = !skip;
		}
	}
}

void MOAIGwenSkin::DrawToolTip(Gwen::Controls::Base* control)
{
	return Textures.Tooltip.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawScrollButton(Gwen::Controls::Base* control, int iDirection, bool bDepressed, bool bHovered, bool bDisabled)
{
	int i = 0;

	if (iDirection == Gwen::Pos::Top) { i = 1; }

	if (iDirection == Gwen::Pos::Right) { i = 2; }

	if (iDirection == Gwen::Pos::Bottom) { i = 3; }

	if (bDisabled)
	{
		return Textures.Scroller.Button.Disabled[i].Draw(GetRender(), control->GetRenderBounds());
	}

	if (bDepressed)
	{
		return Textures.Scroller.Button.Down[i].Draw(GetRender(), control->GetRenderBounds());
	}

	if (bHovered)
	{
		return Textures.Scroller.Button.Hover[i].Draw(GetRender(), control->GetRenderBounds());
	}

	return Textures.Scroller.Button.Normal[i].Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawComboDownArrow(Gwen::Controls::Base* control, bool bHovered, bool bDown, bool bMenuOpen, bool bDisabled)
{
	if (bDisabled)
	{
		return Textures.Input.ComboBox.Button.Disabled.Draw(GetRender(), control->GetRenderBounds());
	}

	if (bDown || bMenuOpen)
	{
		return Textures.Input.ComboBox.Button.Down.Draw(GetRender(), control->GetRenderBounds());
	}

	if (bHovered)
	{
		return Textures.Input.ComboBox.Button.Hover.Draw(GetRender(), control->GetRenderBounds());
	}

	Textures.Input.ComboBox.Button.Normal.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawNumericUpDownButton(Gwen::Controls::Base* control, bool bDepressed, bool bUp)
{
	if (bUp)
	{
		if (control->IsDisabled())	{ return Textures.Input.UpDown.Up.Disabled.DrawCenter(GetRender(), control->GetRenderBounds()); }

		if (bDepressed)				{ return Textures.Input.UpDown.Up.Down.DrawCenter(GetRender(), control->GetRenderBounds()); }

		if (control->IsHovered())		{ return Textures.Input.UpDown.Up.Hover.DrawCenter(GetRender(), control->GetRenderBounds()); }

		return Textures.Input.UpDown.Up.Normal.DrawCenter(GetRender(), control->GetRenderBounds());
	}

	if (control->IsDisabled())	{ return Textures.Input.UpDown.Down.Disabled.DrawCenter(GetRender(), control->GetRenderBounds()); }

	if (bDepressed)				{ return Textures.Input.UpDown.Down.Down.DrawCenter(GetRender(), control->GetRenderBounds()); }

	if (control->IsHovered())		{ return Textures.Input.UpDown.Down.Hover.DrawCenter(GetRender(), control->GetRenderBounds()); }

	return Textures.Input.UpDown.Down.Normal.DrawCenter(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawStatusBar(Gwen::Controls::Base* control)
{
	Textures.StatusBar.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawTreeButton(Gwen::Controls::Base* control, bool bOpen)
{
	Gwen::Rect rect = control->GetRenderBounds();

	if (bOpen)
	{
		Textures.Tree.Minus.Draw(GetRender(), rect);
	}
	else
	{
		Textures.Tree.Plus.Draw(GetRender(), rect);
	}
}

void MOAIGwenSkin::DrawColorDisplay(Gwen::Controls::Base* control, Gwen::Color color)
{
	Gwen::Rect rect = control->GetRenderBounds();

	if (color.a != 255)
	{
		GetRender()->SetDrawColor(Gwen::Color(255, 255, 255, 255));
		GetRender()->DrawFilledRect(rect);
		GetRender()->SetDrawColor(Gwen::Color(128, 128, 128, 128));
		GetRender()->DrawFilledRect(Gwen::Rect(0, 0, rect.w * 0.5, rect.h * 0.5));
		GetRender()->DrawFilledRect(Gwen::Rect(rect.w * 0.5, rect.h * 0.5, rect.w * 0.5, rect.h * 0.5));
	}

	GetRender()->SetDrawColor(color);
	GetRender()->DrawFilledRect(rect);
	GetRender()->SetDrawColor(Gwen::Color(0, 0, 0, 255));
	GetRender()->DrawLinedRect(rect);
}

void MOAIGwenSkin::DrawModalControl(Gwen::Controls::Base* control)
{
	if (!control->ShouldDrawBackground()) { return; }

	Gwen::Rect rect = control->GetRenderBounds();
	GetRender()->SetDrawColor(Colors.ModalBackground);
	GetRender()->DrawFilledRect(rect);
}

void MOAIGwenSkin::DrawMenuDivider(Gwen::Controls::Base* control)
{
	Gwen::Rect rect = control->GetRenderBounds();
	GetRender()->SetDrawColor(Gwen::Color(0, 0, 0, 100));
	GetRender()->DrawFilledRect(rect);
}

void MOAIGwenSkin::DrawTreeControl(Gwen::Controls::Base* control)
{
	Textures.Tree.Background.Draw(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawWindowCloseButton(Gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled)
{
	Gwen::Rect r = Gwen::Rect(control->GetRenderBounds().x, control->GetRenderBounds().y, 31, 31);

	if (bDisabled)	{ return Textures.Window.Close.Draw(GetRender(), r, Gwen::Color(255, 255, 255, 50)); }

	if (bDepressed)	{ return Textures.Window.Close_Down.Draw(GetRender(), r); }

	if (bHovered)		{ return Textures.Window.Close_Hover.Draw(GetRender(), r); }

	Textures.Window.Close.Draw(GetRender(), r);
}

void MOAIGwenSkin::DrawWindowMaximizeButton(Gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled, bool bMaximized)
{
	Gwen::Rect r = Gwen::Rect(control->GetRenderBounds().x, control->GetRenderBounds().y, 31, 31);

	if (!bMaximized)
	{
		if (bDisabled)	{ return Textures.Window.Maxi.Draw(GetRender(), r, Gwen::Color(255, 255, 255, 50)); }

		if (bDepressed)	{ return Textures.Window.Maxi_Down.Draw(GetRender(), r); }

		if (bHovered)		{ return Textures.Window.Maxi_Hover.Draw(GetRender(), r); }

		return Textures.Window.Maxi.Draw(GetRender(), r);
	}

	if (bDisabled)	{ return Textures.Window.Restore.Draw(GetRender(), r, Gwen::Color(255, 255, 255, 50)); }

	if (bDepressed)	{ return Textures.Window.Restore_Down.Draw(GetRender(), r); }

	if (bHovered)		{ return Textures.Window.Restore_Hover.Draw(GetRender(), r); }

	return Textures.Window.Restore.Draw(GetRender(), r);
}

void MOAIGwenSkin::DrawWindowMinimizeButton(Gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled)
{
	Gwen::Rect r = Gwen::Rect(control->GetRenderBounds().x, control->GetRenderBounds().y, 31, 31);

	if (bDisabled)	{ return Textures.Window.Mini.Draw(GetRender(), r, Gwen::Color(255, 255, 255, 100)); }

	if (bDepressed)	{ return Textures.Window.Mini_Down.Draw(GetRender(), r); }

	if (bHovered)		{ return Textures.Window.Mini_Hover.Draw(GetRender(), r); }

	Textures.Window.Mini.Draw(GetRender(), r);
}


void MOAIGwenSkin::DrawSlideButton(Gwen::Controls::Base* control, bool bDepressed, bool bHorizontal)
{
	if (!bHorizontal)
	{
		if (control->IsDisabled())	{ return Textures.Input.Slider.V.Disabled.DrawCenter(GetRender(), control->GetRenderBounds()); }

		if (bDepressed)				{ return Textures.Input.Slider.V.Down.DrawCenter(GetRender(), control->GetRenderBounds()); }

		if (control->IsHovered())		{ return Textures.Input.Slider.V.Hover.DrawCenter(GetRender(), control->GetRenderBounds()); }

		return Textures.Input.Slider.V.Normal.DrawCenter(GetRender(), control->GetRenderBounds());
	}

	if (control->IsDisabled())	{ return Textures.Input.Slider.H.Disabled.DrawCenter(GetRender(), control->GetRenderBounds()); }

	if (bDepressed)				{ return Textures.Input.Slider.H.Down.DrawCenter(GetRender(), control->GetRenderBounds()); }

	if (control->IsHovered())		{ return Textures.Input.Slider.H.Hover.DrawCenter(GetRender(), control->GetRenderBounds()); }

	Textures.Input.Slider.H.Normal.DrawCenter(GetRender(), control->GetRenderBounds());
}

void MOAIGwenSkin::DrawTreeNode(Gwen::Controls::Base* ctrl, bool bOpen, bool bSelected, int iLabelHeight, int iLabelWidth, int iHalfWay, int iLastBranch, bool bIsRoot)
{
	if (bSelected)
	{
		Textures.Selection.Draw(GetRender(), Gwen::Rect(17, 0, iLabelWidth + 2, iLabelHeight - 1));
	}

	Base::DrawTreeNode(ctrl, bOpen, bSelected, iLabelHeight, iLabelWidth, iHalfWay, iLastBranch, bIsRoot);
}

void MOAIGwenSkin::DrawCategoryHolder(Gwen::Controls::Base* ctrl)
{
	Textures.CategoryList.Outer.Draw(GetRender(), ctrl->GetRenderBounds());
}

void MOAIGwenSkin::DrawCategoryInner(Gwen::Controls::Base* ctrl, bool bCollapsed)
{
	if (bCollapsed)
	{
		return Textures.CategoryList.Header.Draw(GetRender(), ctrl->GetRenderBounds());
	}

	Textures.CategoryList.Inner.Draw(GetRender(), ctrl->GetRenderBounds());
}