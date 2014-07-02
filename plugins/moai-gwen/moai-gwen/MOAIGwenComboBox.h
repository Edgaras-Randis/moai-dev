// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGwenComboBox_H
#define MOAIGwenComboBox_H

#include <moai-gwen/MOAIGwenBase.h>
#include <moai-gwen/MOAIGwenEvent.h>
#include <moai-gwen/MOAIGwenRegister.h>

class MOAIGwenComboBox : public MOAIGwenControl<Gwen::Controls::ComboBox>
{
private:
	
	//----------------------------------------------------------------//

public:
	DECL_GWEN_LUA_FACTORY(MOAIGwenComboBox)

	//----------------------------------------------------------------//
	MOAIGwenComboBox()
	{
		RTTI_BEGIN
			RTTI_EXTEND(MOAIGwenBase)
		RTTI_END

		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Base));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Label));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::Button));
		RTTI_CAST.insert(STRINGIFY(Gwen::Controls::ComboBox));
	}

	~MOAIGwenComboBox() {}

	void RegisterLuaClass(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaClass(state);
	}

	void RegisterLuaFuncs(MOAILuaState& state)
	{
		MOAIGwenControl::RegisterLuaFuncs(state);
	}
};

#endif
