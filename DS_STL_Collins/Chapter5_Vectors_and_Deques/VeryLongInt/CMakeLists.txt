
project(longint)

include_directories(${CMAKE_SOURCE_DIR})

set(headers Very_long_int.hxx )
set(longint_SOURCES Very_long_int.cxx)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(longint ${longint_SOURCES} vlimain.cxx)
