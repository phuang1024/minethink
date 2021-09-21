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
#include <vector>


namespace Space3D {

/**
 * 3D point.
 * Uses floats to save memory.
 */
struct Point {
    float x, y, z;
};

/**
 * Triangle in 3D space
 */
struct Tri {
    Point p1, p2, p3;
};

/**
 * Mesh
 * Collection of triangles
 */
struct Mesh {
    std::vector<Tri> tris;
};

/**
 * Write mesh to binary file.
 * Recommended file extension: .mtmesh
 */
void mesh_write(std::ofstream& fp, const Mesh& mesh);

/**
 * Read mesh from binary file.
 * Overwrites param mesh.
 */
void mesh_read(std::ifstream& fp, Mesh& mesh);

}  // namespace Space3D
