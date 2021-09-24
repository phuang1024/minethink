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
 * Implementations for general utilities.
 */

#include <fstream>

#include "space3d.hpp"


namespace Space3D {

void mesh_write(std::ofstream& fp, const Mesh& mesh) {
    const int count = mesh.tris.size();
    fp.write((char*)(&count), sizeof(int));
    for (int i = 0; i < count; i++)
        fp.write((char*)(&mesh.tris[i]), sizeof(Tri));
}

void mesh_read(std::ifstream& fp, Mesh& mesh) {
    mesh.tris.clear();

    int count;
    fp.read((char*)(&count), sizeof(int));
    for (int i = 0; i < count; i++) {
        Tri tri;
        fp.read((char*)(&tri), sizeof(Tri));
        mesh.tris.push_back(tri);
    }
}

void scene_write(std::ofstream& fp, const Scene& scene) {
    // TODO
}

void scene_read(std::ifstream& fp, Scene& scene) {
    // TODO
}

}  // namespace Space3D
