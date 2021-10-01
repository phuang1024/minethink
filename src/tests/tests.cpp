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
#include <string>

#include "tests.hpp"
#include "../logging/logging.hpp"
#include "../utils/utils.hpp"


namespace Tests {

void test(std::string name) {
    if (name == "shcolor") shcolor();
    std::cout << "No test with name " << name << std::endl;
}

void shcolor() {
    Logging::info("Test info log.");
    Logging::warn("Test warn log.");
    Logging::error("Test error log.");
}

}
