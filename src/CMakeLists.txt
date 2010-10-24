# -*- mode: cmake; -*-
set(ehzread_src ehzread.cpp)

#include_directories(${CMAKE_SOURCE_DIR}/libflukso ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(ehzread ${ehzread_src})

# Link the executable 
#target_link_libraries(${CURL_LIBRARIES_SHARED} ${POPT_LIBRARIES} ${JSON_LIBRARIES})

# add programs to the install target - do not install the hashbench benchmark program.
INSTALL(PROGRAMS 
  ${CMAKE_CURRENT_BINARY_DIR}/ehzread
  DESTINATION bin)

