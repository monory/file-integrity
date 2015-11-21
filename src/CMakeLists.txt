cmake_minimum_required(VERSION 3.3)
project(integrity)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Digest.cpp Digest.h Database.cpp Database.h Storage.cpp Storage.h ArgParser.cpp ArgParser.h)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenSSL REQUIRED)
find_package(BerkeleyDB REQUIRED)
find_package(Boost COMPONENTS program_options system REQUIRED)

add_executable(integrity ${SOURCE_FILES})

include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(integrity ${OPENSSL_LIBRARIES})

include_directories(${BERKELEY_DB_INCLUDE_DIR})
target_link_libraries(integrity ${BERKELEY_DB_LIBRARIES})

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(integrity ${Boost_LIBRARIES})