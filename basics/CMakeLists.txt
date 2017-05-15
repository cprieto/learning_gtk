cmake_minimum_required (VERSION 3.6)
project (gtk_basics)

find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)

set (SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (BASIC_SOURCE ${SOURCES_DIR}/basic01.c)

include_directories (${GTK3_INCLUDE_DIRS})
link_directories (${GTK3_LIBRARY_DIRS})
add_definitions (${GTK3_CFLAGS_OTHER})

add_executable (basic_window ${BASIC_SOURCE})
target_link_libraries (basic_window ${GTK3_LIBRARIES})
