# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (learnOpengl)

include_directories ("${PROJECT_SOURCE_DIR}/include")
set(LINK_DIR,${PROJECT_SOURCE_DIR}/lib)
link_directories(${LINK_DIR})

add_subdirectory(libsrc)
add_subdirectory(shader)
add_subdirectory(steps)
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(learnOpengl ${DIR_SRCS})
target_link_libraries(learnOpengl steps glfw3 libsrc shader GL X11 pthread dl)