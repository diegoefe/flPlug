function(setFluid pName)
	add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${pName}.cpp
							 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
							 COMMENT "Running '${FLTK_FLUID_EXECUTABLE}' on ${pName}.fl..."
							 COMMAND ${FLTK_FLUID_EXECUTABLE} -c ${pName}.fl
							 DEPENDS ${pName}.fl)
endfunction()

setFluid(basic_ui)
add_executable(basic basic_main.cpp basic.cpp basic_ui.cpp)
target_link_libraries(basic fl_plug ${FLTK_LIBRARIES})
