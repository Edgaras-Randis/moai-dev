// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/host.h>
#include <moai-gwen/headers.h>

static bool sIsInitialized = false;

//----------------------------------------------------------------//
void MOAIGwenAppFinalize () {
	
	if ( !sIsInitialized ) return;
	sIsInitialized = false;
}

void MOAIGwenAppInitialize() {

}

//----------------------------------------------------------------//
void MOAIGwenContextInitialize() {

	if ( !sIsInitialized ) {
		sIsInitialized = true;
	}

	REGISTER_LUA_CLASS ( MOAIGwenBase )
	REGISTER_LUA_CLASS ( MOAIGwenCore )
	REGISTER_LUA_CLASS ( MOAIGwenCanvas )
	REGISTER_LUA_CLASS ( MOAIGwenRender )
	REGISTER_LUA_CLASS ( MOAIGwenSkinTexture )
	REGISTER_LUA_CLASS ( MOAIGwenSkin )
	REGISTER_LUA_CLASS ( MOAIGwenInput )
	REGISTER_LUA_CLASS ( MOAIGwenLabel )
	REGISTER_LUA_CLASS ( MOAIGwenLabelClickable )
	REGISTER_LUA_CLASS ( MOAIGwenButton )
	REGISTER_LUA_CLASS ( MOAIGwenDockBase )
	REGISTER_LUA_CLASS ( MOAIGwenCollapsibleList )
	REGISTER_LUA_CLASS ( MOAIGwenCollapsibleCategory )
	REGISTER_LUA_CLASS ( MOAIGwenCategoryButton )
	REGISTER_LUA_CLASS ( MOAIGwenTabButton )
	REGISTER_LUA_CLASS ( MOAIGwenTabControl )
	REGISTER_LUA_CLASS ( MOAIGwenDockedTabControl )
	REGISTER_LUA_CLASS ( MOAIGwenListBox )
	REGISTER_LUA_CLASS ( MOAIGwenLayoutCenter )
	REGISTER_LUA_CLASS ( MOAIGwenCrossSplitter )
	REGISTER_LUA_CLASS ( MOAIGwenProgressBar )
	REGISTER_LUA_CLASS ( MOAIGwenGroupBox )
	REGISTER_LUA_CLASS ( MOAIGwenImagePanel )
	REGISTER_LUA_CLASS ( MOAIGwenStatusBar )
	REGISTER_LUA_CLASS ( MOAIGwenComboBox )
	REGISTER_LUA_CLASS ( MOAIGwenMenuItem )
	REGISTER_LUA_CLASS ( MOAIGwenTextBox )
	REGISTER_LUA_CLASS ( MOAIGwenTextBoxNumeric )
	REGISTER_LUA_CLASS ( MOAIGwenTextBoxMultiline )
	REGISTER_LUA_CLASS ( MOAIGwenTextBoxPassword )
	REGISTER_LUA_CLASS ( MOAIGwenCheckBox )
	REGISTER_LUA_CLASS ( MOAIGwenCheckBoxWithLabel )
	REGISTER_LUA_CLASS ( MOAIGwenNumericUpDown )
}
