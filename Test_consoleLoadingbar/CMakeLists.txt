cmake_minimum_required (VERSION 3.8)

add_executable (consoleLoadingbarTest "consoleLoadingbar.cpp" "consoleLoadingbar.h" "killhandler.h")
target_link_libraries(consoleLoadingbarTest sharks::consoleLoadingBar)

install(TARGETS consoleLoadingbarTest DESTINATION testApp)
