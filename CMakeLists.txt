cmake_minimum_required(VERSION 3.16)
project(GeoObjektGFX)

set(CMAKE_CXX_STANDARD 14)

add_executable(GeoObjektGFXDemo GeoObjektGFXTest/GeoObjektGFXDemo.cpp GeoObjektGFX.cpp GeoObjektGFX.h Pinsel.cpp Pinsel.h Position.hpp)

target_link_libraries(GeoObjektGFXDemo -lpthread)
target_link_libraries(GeoObjektGFXDemo -lX11)

enable_testing()
include(GoogleTest)
add_subdirectory(googletest)

add_executable(GeoObjektGFXTest GeoObjektGFX.cpp GeoObjektGFX.h MemoryMonitor/MemoryMonitor.cpp MemoryMonitor/MemoryMonitor.hpp GeoObjektGFXTest/GeoObjektGFXDemo.cpp)
target_link_libraries(GeoObjektGFXTest gtest gtest_main)
gtest_discover_tests(GeoObjektGFXTest)

if(MSVC)
    target_compile_options(GeoObjektGFXDemo PRIVATE /W4 /WX)
    target_compile_options(GeoObjektGFXTest PRIVATE /W4 /WX)
else()
    target_compile_options(GeoObjektGFXDemo PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(GeoObjektGFXTest PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()