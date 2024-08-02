cmake_minimum_required(VERSION 3.10)
project(NanoGUIExample)

set(CMAKE_CXX_STANDARD 11)

set(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL " " FORCE)
set(NANOGUI_BUILD_PYTHON  OFF CACHE BOOL " " FORCE)
set(NANOGUI_INSTALL       OFF CACHE BOOL " " FORCE)

# Add the configurations from nanogui
add_subdirectory(nanogui/)

# For reliability of parallel build, make the NanoGUI targets dependencies
set_property(TARGET glfw glfw_objects nanogui PROPERTY FOLDER "dependencies")


add_definitions(${NANOGUI_EXTRA_DEFS})

# On top of adding the path to nanogui/include, you may need extras
include_directories(${NANOGUI_EXTRA_INCS})

# Compile a target using NanoGUI
add_executable(myTarget nanogui.cpp)

# Lastly, additional libraries may have been built for you.  In addition to linking
# against NanoGUI, we need to link against those as well.
target_link_libraries(myTarget nanogui ${NANOGUI_EXTRA_LIBS})
