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

/**
 * Implementations for logging.
 */

#include <iostream>
#include <string>

#include "logging.hpp"


namespace Logging {

void info(std::string msg) {
    std::cout << "[INFO] " << msg << std::endl;
}

void warn(std::string msg) {
    std::cout << "[WARN] " << msg << std::endl;
}

void error(std::string msg) {
    std::cout << "[ERROR] " << msg << std::endl;
}

}  // namespace Logging
