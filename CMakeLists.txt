cmake_minimum_required(VERSION 3.2)
project (CHAKRACORE)

if(UNIX)
    add_definitions(-DPLATFORM_UNIX=1 -DPAL_STDCPP_COMPAT=1 -D__STDC_WANT_LIB_EXT1__=1)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions(-DBIT64=1)
endif()

try_compile(HAS_PREDEFINED_WCHAR_T ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/Build/cmake/check_predefined_wchar_t.cpp)
if(HAS_PREDEFINED_WCHAR_T)
    add_definitions(-D_WCHAR_T_DEFINED=1)
endif()

add_definitions ("-fms-extensions")
add_definitions("-fdiagnostics-color=always")

# Disable some warnings
#add_definitions("-Wno-tautological-constant-out-of-range-compare")
#add_definitions("-D__STDC_WANT_LIB_EXT1__=1")
#add_definitions("-DPAL_STDCPP_COMPAT=1")
#add_definitions("-std=c++11")
#add_definitions("-stdlib=libc++")

include_directories("pal")
include_directories("pal/inc")
include_directories("pal/inc/rt")
add_subdirectory (lib)
