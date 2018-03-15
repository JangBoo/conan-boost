project(PackageTest CXX)
cmake_minimum_required(VERSION 2.8.12)

message("include : ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(BOOST_ROOT ${CONAN_BOOST_ROOT})
###############################################
# Boost
#
###############################################
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
add_definitions(-DBOOST_SPIRIT_THREADSAFE)

# define all needed boost libraries
set(BOOST_LIBS 
   atomic
	system 
	filesystem 
	thread 
	date_time 
	chrono 
	regex
)

# search boost libs
find_package(Boost 1.66.0 REQUIRED COMPONENTS ${BOOST_LIBS})
set(BOOST_INCL_DIR ${Boost_INCLUDE_DIR} ${BOOST_ROOT})


add_executable(example example.cpp)
target_link_libraries(example ${CONAN_LIBS} ${Boost_LIBRARIES})

# CTest is a testing tool that can be used to test your project.
# enable_testing()
# add_test(NAME example
#          WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#          COMMAND example)
