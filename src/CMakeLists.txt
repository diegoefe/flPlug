add_library(fl_plug STATIC fl_plug.cpp)
set(ver_file ${CMAKE_CURRENT_BINARY_DIR}/fl_plug_version.h)
configure_file(version.h.in ${ver_file})

if(UNIX)
	install(FILES fl_plug.h ${ver_file} DESTINATION include)
	install(TARGETS fl_plug DESTINATION lib)
endif(UNIX)
