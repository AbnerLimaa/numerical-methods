add_library(model methods.c table.c)

target_include_directories(model PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(model PRIVATE m utils)