cmake_minimum_required (VERSION 3.8)

ADD_LIBRARY(consoleLoadingBar "consoleLoadingBar.h" "consoleLoadingBar.cpp" "osdef.h")
target_include_directories(consoleLoadingBar INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_compile_features(consoleLoadingBar PUBLIC cxx_std_11)
add_library(sharks::consoleLoadingBar ALIAS consoleLoadingBar)

install(TARGETS consoleLoadingBar DESTINATION lib)
install(FILES consoleLoadingBar.h DESTINATION include)
