# CMake generated Testfile for 
# Source directory: /workspaces/be/lr6
# Build directory: /workspaces/be/lr6/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/be/lr6/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/be/lr6/CMakeLists.txt;48;add_test;/workspaces/be/lr6/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
