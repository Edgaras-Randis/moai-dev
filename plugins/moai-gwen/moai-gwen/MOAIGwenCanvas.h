// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIGWEN_H
#define MOAIGWEN_H

class MOAIGwenSkin;
class MOAIGwenRender;

#include <moai-gwen/MOAIGwenBase.h>

class MOAIGwenCanvas : public virtual MOAIProp, public virtual MOAIGwenBase, public Gwen::Controls::Canvas
{
private:
	
	//----------------------------------------------------------------//

	static int _init(lua_State* L);
	static int _render(lua_State* L);

public:
	DECL_LUA_FACTORY(MOAIGwenCanvas)
	
	//----------------------------------------------------------------//
					MOAIGwenCanvas			 ();
					~MOAIGwenCanvas			 ();

	void			RegisterLuaClass(MOAILuaState& state);
	void			RegisterLuaFuncs(MOAILuaState& state);

	void			SerializeIn(MOAILuaState& state, MOAIDeserializer& serializer);
	void			SerializeOut(MOAILuaState& state, MOAISerializer& serializer);

	Gwen::Controls::Base* Base();

protected:

	virtual void OnChildAdded(Gwen::Controls::Base* pChild);
	virtual void OnChildRemoved(Gwen::Controls::Base* pChild);


private:

	MOAILuaSharedPtr<MOAIGwenSkin> Skin;

	UnitTest* pUnitTest;
};

#endif
