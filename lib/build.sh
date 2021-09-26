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

# Automatically download and build dependencies.
# You may need to rm -rf build include lib for building a second time.


# Setup
mkdir -p ./build ./include ./lib
cd ./build


# FFmpeg
mkdir -p ./ffmpeg
cd ./ffmpeg

# x264
git clone --depth 1 https://code.videolan.org/videolan/x264.git
cd ./x264
PKG_CONFIG_PATH=./pkgconfig
./configure --prefix=./build --bindir=./bin --enable-static --enable-pic
make -j`nproc`
make install

cp ./build/include/*.h ../../../include
cp ./build/lib/*.a ../../../lib
cd ..

# x265
git clone https://bitbucket.org/multicoreware/x265_git
cd ./x265_git/build/linux
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=./build -DENABLE_SHARED=off ../../source
make -j`nproc`
make install

cp ./build/include/*.h ../../../../../include
cp ./build/lib/*.a ../../../../../lib
cd ../../..
