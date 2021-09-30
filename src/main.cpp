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
#include "config.hpp"
#include "gui/gui.hpp"
#include "logging/logging.hpp"
#include "pathlib/pathlib.hpp"


void print_info() {
    std::cout << "Minethink: A 3D block based game." << std::endl;
    std::cout << "Licensed as GNU GPL v3. See LICENSE for more info." << std::endl;
    std::cout << "Version " << VMAJOR << "." << VMINOR << "." << VPATCH;
    std::cout << "  Git SHA1: " << GIT_HASH << std::endl;
    std::cout << "Built on " << __DATE__ << ", " << __TIME__ << std::endl;
}


void display() {
    Logging::info("Opening GUI window.");

    GUI::GuiWindow window;
    while (true) {
        GUI::XEvent event;
        window.next_event(event);
    }
}


int main() {
    print_info();

    display();
}
