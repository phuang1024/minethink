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
    PF3D();
    PF3D(float x, float y, float z);

    float x, y, z;
};

/**
 * Point float 2D
 */
struct PF2D {
    PF2D();
    PF2D(float x, float y);

    float x, y;
};

/**
 * Triangle in 3D space
 */
struct Tri {
    Tri();
    Tri(PF3D p1, PF3D p2, PF3D p3);

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
 * Will always remain horizontal (no rotation in the line of sight axis)
 */
struct Camera {
    Camera();
    Camera(PF3D loc, PF3D dir, float fov, int x, int y, float clip);

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

};

/**
 * Represents one scene with meshes and a camera.
 */
struct Scene {
    Camera cam;

    std::vector<Mesh> meshes;

    /**
     * Minimum distance a face can be to be rendered.
     */
    float clip_start = 0.01;

    /**
     * Maximum distance a face can be to be rendered.
     */
    float clip_end = 1000;
};


// 3D processing functions

/**
 * Project point onto camera (get x and y pixel values).
 * If point not visible from camera, return false and set dest to negative values.
 * Return true otherwise
 * @param dest destination to store.
 * @param point point to project.
 * @param cam camera.
 */
bool project(PF2D& dest, PF3D& point, Camera& cam);


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

/**
 * Write scene to binary file.
 * Recommended file extension: .mtscn
 */
void scene_write(std::ofstream& fp, const Scene& scene);

/**
 * Read scene from binary file.
 * Overwrites param scene.
 */
void scene_read(std::ifstream& fp, Scene& scene);

}  // namespace Space3D
