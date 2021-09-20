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

cmake_minimum_required(VERSION 3.10)

project(Minethink VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(config.hpp.in config.hpp)

find_library(x11 NAMES X11)
message(STATUS "X11: ${x11}")

find_library(cv_core NAMES opencv_core)
find_library(cv_imgproc NAMES opencv_imgproc)
find_library(cv_highgui NAMES opencv_highgui)
find_library(cv_imgcodecs NAMES opencv_imgcodecs)
message(STATUS "OpenCV: ${cv_core} ${cv_imgproc} ${cv_highgui} ${cv_imgcodecs}")

add_subdirectory(pathlib)
add_subdirectory(gui)
# add_subdirectory(render)

set(Minethink_sources main.cpp)
add_executable(Minethink ${Minethink_sources})

target_link_libraries(Minethink pathlib gui
    ${x11}
    ${cv_core} ${cv_imgproc} ${cv_highgui} ${cv_imgcodecs})
target_include_directories(Minethink PUBLIC "${PROJECT_BINARY_DIR}")
