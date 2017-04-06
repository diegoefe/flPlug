function(setFluid pName)
	if(NOT FLTK_FLUID_EXECUTABLE STREQUAL FLTK_FLUID_EXECUTABLE-NOTFOUND)
		add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${pName}.cpp
								 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
								 COMMENT "Running '${FLTK_FLUID_EXECUTABLE}' on ${pName}.fl..."
								 COMMAND ${FLTK_FLUID_EXECUTABLE} -c ${pName}.fl
								 DEPENDS ${pName}.fl)
	endif()
endfunction()

setFluid(basic_ui)
add_executable(basic basic_main.cpp basic.cpp basic_ui.cpp)
target_link_libraries(basic flPlug ${FLTK_LIBRARIES})

add_executable(simple simple.cpp)
target_link_libraries(simple flPlug ${FLTK_LIBRARIES})

if(BUNDLE_EXAMPLES)
	file(GLOB hdrs "*.h")
	file(GLOB srcs "*.cpp")
	file(GLOB fls "*.fl")
	install(FILES ${hdrs} ${srcs} ${fls} COMPONENT examples DESTINATION examples)
endif()
