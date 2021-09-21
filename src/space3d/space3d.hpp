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

// API classes
// Point classes can also be used as vectors.

/**
 * Point float 3D
 */
struct PF3D {
    float x, y, z;
};

/**
 * Triangle in 3D space
 */
struct Tri {
    PF3D p1, p2, p3;
};

/**
 * Mesh
 * Collection of triangles
 */
struct Mesh {
    std::vector<Tri> tris;
};

/**
 * Perspective camera.
 * Stores location and direction.
 */
struct Camera {
    /**
     * Location.
     */
    PF3D loc;

    /**
     * Direction.
     */
    PF3D dir;

    /**
     * Field of view X.
     * Radians.
     */
    float fov;

    /**
     * Resolution
     */
    int x, y;
};


// Utility functions

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
