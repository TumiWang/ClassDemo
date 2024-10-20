cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# 关闭函数返回值优化
# add_compile_options("-fno-elide-constructors")

if(MSVC)
    # msvc编译时，默认适用本地编码。但代码实际使用的是Utf-8
    # 为了避免这个问题，强制msvc适用utf-8编码
    add_compile_options(/utf-8)

    # 使用静态库
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(SOURCE_TYPE_NAME .c .cc .cpp)

macro(product_target)
    add_executable(${ARGV0} source/${ARGV0}${ARGV1})
    install(TARGETS ${ARGV0})
endmacro(product_target)

if("${MYTARGET}x" STREQUAL "x")
    file(GLOB files LIST_DIRECTORIES false source/*.*)
else()
    file(GLOB files LIST_DIRECTORIES false source/${MYTARGET}.*)
endif()

foreach(file IN LISTS files)
    get_filename_component(ext ${file} LAST_EXT)
    list(FIND SOURCE_TYPE_NAME ${ext} index)
    if(${index} STREQUAL "-1")
        continue()
    endif()
    get_filename_component(name ${file} NAME_WLE)
    product_target(${name} ${ext})
endforeach()
