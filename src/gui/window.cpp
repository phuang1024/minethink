//
//  Minebuild
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

#include "gui.hpp"


namespace GUI {

GuiWindow::~GuiWindow() {
    _close();
}

GuiWindow::GuiWindow() {
    _init();
}

void GuiWindow::_init() {
    _disp = XOpenDisplay((char*)0);
    _screen = DefaultScreen(_disp);
    _win = XCreateSimpleWindow(_disp, DefaultRootWindow(_disp), 0, 0, 1280, 720, 5, 0, 0);
    _gc = XCreateGC(_disp, _win, 0, 0);

    XSetStandardProperties(_disp, _win, "Minebuild", "Asdf", None, NULL, 0, NULL);
    XClearWindow(_disp, _win);
    XMapRaised(_disp, _win);
}

void GuiWindow::_close() {
    XFreeGC(_disp, _gc);
    XDestroyWindow(_disp, _win);
    XCloseDisplay(_disp);
}

}  // namespace GUI
