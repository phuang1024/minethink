//
//  Minethink
//  3D block based game.
//  Copyright Patrick Huang 2021
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include <iostream>
#include <unistd.h>
#include "pathlib.hpp"


namespace Pathlib {

std::string mypath() {
    char cpath[PATH_MAX];
    int len = readlink("/proc/self/exe", cpath, sizeof(cpath)-1);
    cpath[len] = 0;
    return std::string(cpath);
}

Path::~Path() {
}

Path::Path() {
    _path = mypath();
    std::cout << _path << std::endl;
}

}  // namespace Pathlib
