// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAICLASSSINGLETON_H
#define MOAICLASSSINGLETON_H

#include <moai-core/MOAILua.h>

//================================================================//
// MOAIClassSingleton
//================================================================//

class MOAIClassSingleton : public MOAIGlobalClass < MOAIClassSingleton, MOAILuaObject > {
public:
	
	DECL_LUA_SINGLETON(MOAIClassSingleton)
};

#endif
