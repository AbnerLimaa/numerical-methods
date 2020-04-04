add_library(model function.c number.c equations.c methods.c)

target_include_directories(model PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(model PRIVATE m utils)