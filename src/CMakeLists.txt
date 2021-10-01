#
#  Minethink
#  3D block based game.
#  Copyright Patrick Huang 2021
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

# Config stuff
cmake_minimum_required(VERSION 3.10)

find_package(Git)

# Project
project(Minethink VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
set(Minethink_sources main.cpp)
add_executable(Minethink ${Minethink_sources})

# Configure files
execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --match=asdf --always --abbrev=40 --dirty
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE GIT_HASH
    ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_custom_command(TARGET Minethink POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/datafiles/ $<TARGET_FILE_DIR:Minethink>/datafiles
)
configure_file(config.hpp.in config.hpp)

# Add libraries
find_library(x11 NAMES X11)
message(STATUS "X11: ${x11}")

find_library(cv_core NAMES opencv_core)
find_library(cv_imgproc NAMES opencv_imgproc)
find_library(cv_highgui NAMES opencv_highgui)
find_library(cv_imgcodecs NAMES opencv_imgcodecs)
message(STATUS "OpenCV: ${cv_core} ${cv_imgproc} ${cv_highgui} ${cv_imgcodecs}")

add_subdirectory(argparse)
add_subdirectory(gui)
add_subdirectory(logging)
add_subdirectory(pathlib)
add_subdirectory(render)
add_subdirectory(space3d)
add_subdirectory(tests)
add_subdirectory(utils)

# Link and include
target_link_libraries(Minethink
    argparse gui logging pathlib render space3d tests utils
    ${x11}
    ${cv_core} ${cv_imgproc} ${cv_highgui} ${cv_imgcodecs}
)
target_include_directories(Minethink PUBLIC "${PROJECT_SOURCE_DIR}")
