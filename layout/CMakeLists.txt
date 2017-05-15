cmake_minimum_required (VERSION 3.6)
project (gtk_containers)

find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)

set (SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories (${GTK3_INCLUDE_DIRS})
link_directories (${GTK3_LIBRARY_DIRS})
add_definitions (${GTK3_CFLAGS_OTHER})

# The box layout sample
set (SAMPLE03_SOURCE ${SOURCES_DIR}/sample03.c)
add_executable (sample03 ${SAMPLE03_SOURCE})
target_link_libraries (sample03 ${GTK3_LIBRARIES})

# The grid layout sample
set (SAMPLE04_SOURCE ${SOURCES_DIR}/sample04.c)
add_executable (sample04 ${SAMPLE04_SOURCE})
target_link_libraries (sample04 ${GTK3_LIBRARIES})

# The grid with next to
set (SAMPLE05_SOURCE ${SOURCES_DIR}/sample05.c)
add_executable (sample05 ${SAMPLE05_SOURCE})
target_link_libraries (sample05 ${GTK3_LIBRARIES})

# The grid with next to
set (SAMPLE06_SOURCE ${SOURCES_DIR}/sample06.c)
add_executable (sample06 ${SAMPLE06_SOURCE})
target_link_libraries (sample06 ${GTK3_LIBRARIES})