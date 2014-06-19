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

	REGISTER_LUA_CLASS ( MOAIGwenCanvas )
	REGISTER_LUA_CLASS ( MOAIGwenRender )
	REGISTER_LUA_CLASS ( MOAIGwenSkinTexture )
	REGISTER_LUA_CLASS ( MOAIGwenSkin )
	REGISTER_LUA_CLASS ( MOAIGwenInput )
	
}
