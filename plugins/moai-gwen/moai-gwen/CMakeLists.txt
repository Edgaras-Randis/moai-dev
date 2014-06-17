cmake_minimum_required ( VERSION 2.8.5 )
project ( moai-gwen )


  set ( PLUGIN_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

  set ( PLUGIN_INCLUDES 
        ${PLUGIN_ROOT}/../
	${PLUGIN_ROOT}/include
  )

  # Use all cpp files in directory as source code
  file ( GLOB_RECURSE PLUGIN_SRC ${PLUGIN_ROOT}/*.cpp ${PLUGIN_ROOT}/UnitTest/*.cpp ${PLUGIN_ROOT}/*.h )


  add_library ( moai-gwen STATIC ${PLUGIN_SRC} )
  target_include_directories( moai-gwen PUBLIC ${PLUGIN_INCLUDES})
  target_link_libraries (moai-gwen moai-core moai-util moai-sim zlcore)
  set_target_properties(moai-gwen PROPERTIES FOLDER Plugins)