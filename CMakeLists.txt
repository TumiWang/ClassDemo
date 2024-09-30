cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# 关闭函数返回值优化
# add_compile_options("-fno-elide-constructors")

macro(product_target)
    add_executable(${ARGV0} source/${ARGV0}.cpp)
    install(TARGETS ${ARGV0})
endmacro(product_target)

file(GLOB files LIST_DIRECTORIES false source/*.cpp)

if("${MYTARGET}x" STREQUAL "x")
    foreach(file IN LISTS files)
        get_filename_component(name ${file} NAME_WLE)
        product_target(${name})
    endforeach()
else()
    product_target(${MYTARGET})
endif()
