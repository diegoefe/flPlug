add_library(flPlug STATIC flPlug.cpp)
set(ver_file ${CMAKE_CURRENT_BINARY_DIR}/flPlug_version.h)
configure_file(version.h.in ${ver_file})

if(UNIX)
	install(FILES flPlug.h ${ver_file} DESTINATION include)
	install(TARGETS flPlug DESTINATION lib)
endif(UNIX)
