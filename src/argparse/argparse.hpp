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

struct Argument {
    /**
     * Documentation string.
     */
    std::string doc;

    /**
     * Possible ways to set this argument.
     */
    std::vector<std::string> names;

    /**
     * Whether the user included this argument in the args.
     */
    bool passed;

    /**
     * String the user passes. Use as_int, ... for types.
     */
    std::string value;

    Argument();

    Argument(std::string doc, std::vector<std::string> names);

    int as_int();

    LL as_ll();

    float as_float();

    double as_double();
};

class Parser {
public:
    ~Parser();

    Parser();

    /**
     * @param help whether to add help argument.
     */
    Parser(bool help);

    /**
     * Get an argument.
     * @param key the key set in add_argument.
     */
    Argument& get(std::string key);

    /**
     * Add an argument to the target arguments.
     * @param key the string key to use Parser.get() on.
     * @param arg argument instance.
     */
    void add_argument(std::string key, Argument arg);

    /**
     * Add --help, -h argument.
     */
    void add_help();

    /**
     * Call this to do the actual parsing.
     * Stores the value attr of each Argument.
     */
    void parse(int argc, char** argv);

private:
    std::map<std::string, Argument> _args;
};

}  // namespace Argparse
