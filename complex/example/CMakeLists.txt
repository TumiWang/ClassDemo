cmake_minimum_required(VERSION 3.16)

if(MSVC)
    # msvc编译时，默认适用本地编码。但代码实际使用的是Utf-8
    # 为了避免这个问题，强制msvc适用utf-8编码
    add_compile_options(/utf-8)

    # 使用静态库
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

file(GLOB files LIST_DIRECTORIES false *.cpp)

add_executable(test ${files})
install(TARGETS test)