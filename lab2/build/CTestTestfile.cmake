# CMake generated Testfile for 
# Source directory: /workspaces/be/lab2
# Build directory: /workspaces/be/lab2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/be/lab2/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/be/lab2/CMakeLists.txt;31;add_test;/workspaces/be/lab2/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
