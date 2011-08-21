add_library(flPlug STATIC flPlug.cpp)
set(ver_file ${CMAKE_CURRENT_BINARY_DIR}/flPlug_version.h)
configure_file(version.h.in ${ver_file})

install(FILES flPlug.h ${ver_file} COMPONENT headers DESTINATION include)
install(TARGETS flPlug COMPONENT libraries DESTINATION lib)
