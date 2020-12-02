project(Lesson4)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
add_executable(Lesson4 src/main.cpp)
target_link_libraries(Lesson4 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
