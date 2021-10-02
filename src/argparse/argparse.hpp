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
 * Declarations for CLI argument parsing.
 */

#pragma once

#include <map>
#include <string>
#include <vector>

#include "utils.hpp"


namespace Argparse {

/**
 * One argument.
 * Currently, only positional is supported.
 */
class Argument {
public:
    /**
     * List of strings that can be used to set this argument.
     */
    std::vector<std::string> identifiers;

    /**
     * Whether the set this argument in the args.
     */
    bool passed;

    /**
     * String the user passes. Use as_int, ... for types.
     */
    std::string value;

    Argument(std::vector<std::string> identifiers);

    int as_int();

    LL as_ll();

    float as_float();

    double as_double();

private:
};

/**
 * Set of argument parsing rules.
 */
class Parser {
public:
    std::string description;

    Parser(std::string description);

    /**
     * Write help message to stdout.
     */
    void print_help();

    /**
     * Add a identifier-argument pair.
     */
    void add(std::string identifier, Argument arg);

private:
    std::map<std::string, Argument> _args;
};

}  // namespace Argparse
