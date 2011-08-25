function(setFluid pName)
	if(NOT FLUID STREQUAL FLUID-NOTFOUND)
		add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${pName}.cpp
								 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
								 COMMENT "Running '${FLUID}' on ${pName}.fl..."
								 COMMAND ${FLUID} -c ${pName}.fl
								 DEPENDS ${pName}.fl)
	endif()
endfunction()

setFluid(basic_ui)
add_executable(basic basic_main.cpp basic.cpp basic_ui.cpp)
target_link_libraries(basic flPlug ${FLTK_LIBRARIES})

add_executable(simple simple.cpp)
target_link_libraries(simple flPlug ${FLTK_LIBRARIES})


file(GLOB hdrs "*.h")
file(GLOB srcs "*.cpp")
install(FILES ${hdrs} ${srcs} COMPONENT examples DESTINATION examples)
