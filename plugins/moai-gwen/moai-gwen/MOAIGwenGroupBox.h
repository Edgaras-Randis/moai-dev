// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenGroupBox_H
#define MOAIGwenGroupBox_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>
#include <moai-gwen/MOAIGwenRegister.h>

class MOAIGwenGroupBox : public MOAIGwenControl<Gwen::Controls::GroupBox>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenGroupBox)

	//----------------------------------------------------------------//
	MOAIGwenGroupBox()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::GroupBox));
	}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
		MOAIGwenRegisterLabel::RegisterLuaClass(state);
		MOAIGwenRegisterGroupBox::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
		MOAIGwenRegisterLabel::RegisterLuaFuncs(state);
		MOAIGwenRegisterGroupBox::RegisterLuaFuncs(state);
	}
};

#endif
