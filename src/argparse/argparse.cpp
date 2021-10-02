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
 * Implementations for CLI argument parsing.
 */

#include <map>
#include <string>
#include <vector>

#include "argparse.hpp"

using std::map;
using std::string;
using std::vector;


namespace Argparse {

int Argument::as_int() {
    return std::stoi(value);
}

LL Argument::as_ll() {
    return std::stol(value);
}

float Argument::as_float() {
    return std::stof(value);
}

double Argument::as_double() {
    return std::stod(value);
}


Parser::Parser(std::string description) {
    this->description = description;
}

void Parser::add(std::string identifier, Argument arg) {
    _args[identifier] = arg;
}

}  // namespace Argparse
