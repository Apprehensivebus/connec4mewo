# CMakeList.txt : CMake project for connec4mewo, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (connec4mewo "connec4mewo.cpp" "connec4mewo.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET connec4mewo PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
