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
#include "pathlib/pathlib.hpp"
#include "gui/gui.hpp"


void print_info() {
    std::cout << "Minethink: A 3D block based game.\n";
    std::cout << "Minethink is licensed as GNU GPL v3. See LICENSE for more info.\n";
    std::cout << "Version " << VMAJOR << "." << VMINOR << "." << VPATCH << std::endl;
}


void display() {
    GUI::GuiWindow window;
    while (true) {
        GUI::XEvent event;
        window.next_event(event);
    }
}


int main() {
    print_info();

    Pathlib::Path path;
    Pathlib::Path path2("asdf");
    std::cout << path.isabs() << std::endl;
    std::cout << path2.isabs() << std::endl;

    // display();
}
