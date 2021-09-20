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

#pragma once

#include <string>

constexpr int PATH_MAX = 1024;
constexpr char sep = '/';


namespace Pathlib {

/**
 * Get path of this executable.
 */
std::string mypath();

class Path {
public:
    ~Path();
    Path();
    Path(std::string path);

    /**
     * Return path as std::string
     */
    std::string& path();

    /**
     * Check if path is absolute (starts with sep).
     */
    bool isabs();

private:
    std::string _path;
};

}  // namespace Pathlib
