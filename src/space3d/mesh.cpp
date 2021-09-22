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

#include <fstream>

#include "space3d.hpp"


namespace Space3D {

PF3D::PF3D() {
    x = 0;
    y = 0;
    z = 0;
}

PF3D::PF3D(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

PF2D::PF2D() {
    x = 0;
    y = 0;
}

PF2D::PF2D(float x, float y) {
    this->x = x;
    this->y = y;
}

Tri::Tri() {
}

Tri::Tri(PF3D p1, PF3D p2, PF3D p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Camera::Camera() {
    loc = PF3D(0, 0, 0);
    dir = PF3D(0, 0, 0);
    fov = 1.2;
}


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

}  // namespace Space3D
