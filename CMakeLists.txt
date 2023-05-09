cmake_minimum_required(VERSION 3.16)
project(GeoObjektGFX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(CSimpleCanvas)
add_executable(GeoObjektGFXDemo GeoObjektGFXTest/GeoObjektGFXDemo.cpp GeoObjektGFX.cpp Pinsel.cpp)
target_link_libraries(GeoObjektGFXDemo CSimpleCanvas)

enable_testing()
include(GoogleTest)
add_subdirectory(googletest)

add_executable(GeoObjektGFXTest GeoObjektGFX.cpp Pinsel.cpp MemoryMonitor/MemoryMonitor.cpp GeoObjektGFXTest/GeoObjektGFXTest.cpp)
target_link_libraries(GeoObjektGFXTest gtest gtest_main CSimpleCanvas)
gtest_discover_tests(GeoObjektGFXTest)

target_link_libraries(GeoObjektGFXDemo -lpthread)

if(WIN32)
    target_link_libraries(GeoObjektGFXDemo -lgdi32)
    target_link_libraries(GeoObjektGFXTest -lgdi32)
else()
    target_link_libraries(GeoObjektGFXDemo -lX11)
    target_link_libraries(GeoObjektGFXTest -lX11)
endif()

if(MSVC)
    target_compile_options(GeoObjektGFXDemo PRIVATE /W4 /WX)
    target_compile_options(GeoObjektGFXTest PRIVATE /W4 /WX)
else()
    target_compile_options(GeoObjektGFXDemo PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(GeoObjektGFXTest PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
