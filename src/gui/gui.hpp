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

#pragma once


namespace GUI {

// Including here so won't pollute global
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

/**
 * Wrapper for display and window.
 */
class GuiWindow {
public:
    ~GuiWindow();
    GuiWindow();

private:
    Display* _disp;
    Window _win;
    GC _gc;
    int _screen;

    void _init();
    void _close();
};

}  // namespace GUI
