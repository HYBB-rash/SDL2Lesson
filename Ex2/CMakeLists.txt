project(Ex2)
add_executable(Ex2 src/main.cpp)
target_link_libraries(Ex2 ${SDL2_LIBRARY})
install(TARGETS Ex2 RUNTIME DESTINATION ${BIN_DIR})