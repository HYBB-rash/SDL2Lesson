project(Ex1)
add_executable(Ex1 src/main.cpp)
target_link_libraries(Ex1 ${SDL2_LIBRARY})
install(TARGETS Ex1 RUNTIME DESTINATION ${BIN_DIR})