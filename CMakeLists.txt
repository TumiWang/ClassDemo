cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# 关闭函数返回值优化
# add_compile_options("-fno-elide-constructors")

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
