# -*- mode: cmake; -*-
set(ehzreader_src EhzDatagram.cpp EhzParse.cpp EhzRead.cpp ehzreader.cpp)

# search necessary stuff and make sure it was found
find_library(PCRE_LIBRARY pcrecpp)

if(NOT PCRE_LIBRARY)
  message(FATAL_ERROR "Could not find pcre library !")
endif()

#include_directories(${CMAKE_SOURCE_DIR}/libflukso ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(ehzreader ${ehzreader_src})

# Link the executable 
target_link_libraries(ehzreader ${PCRE_LIBRARY})

# add programs to the install target - do not install the hashbench benchmark program.
INSTALL(PROGRAMS 
  ${CMAKE_CURRENT_BINARY_DIR}/ehzreader
  DESTINATION bin)

