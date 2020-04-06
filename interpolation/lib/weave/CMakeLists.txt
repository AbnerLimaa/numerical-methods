add_library(weave weave.c)

target_include_directories(weave PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(weave PRIVATE model)