cmake_minimum_required(VERSION 2.8.12)
project(getterReturnCopyVsConstRef)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(getterReturnCopyVsConstRef getterReturnCopyVsConstRef.cpp)
target_link_libraries(getterReturnCopyVsConstRef ${CONAN_LIBS})

add_executable(constructorArgCopyVsConstRef constructorArgCopyVsConstRef.cpp)
target_link_libraries(constructorArgCopyVsConstRef ${CONAN_LIBS})

add_executable(stringConcat stringConcat.cpp)
target_link_libraries(stringConcat ${CONAN_LIBS})
