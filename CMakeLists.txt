cmake_minimum_required(VERSION 2.6)
project(stdoutisatty C)

add_executable(stdoutisatty stdoutisatty.c)
add_library(libstdoutisatty SHARED libstdoutisatty.c)
target_link_libraries(libstdoutisatty dl)
set_target_properties(libstdoutisatty
  PROPERTIES OUTPUT_NAME stdoutisatty
)

get_target_property(libname libstdoutisatty OUTPUT_NAME)
add_definitions(-DLIB_FILE=\"lib${libname}.so\")

install(TARGETS stdoutisatty libstdoutisatty
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
)
