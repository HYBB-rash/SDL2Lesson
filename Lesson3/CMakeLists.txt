find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
# Link this lesson against SDL2 and SDL2_image
add_executable(Lesson3 src/main.cpp)
target_link_libraries(Lesson3 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
# Install target is the same as before