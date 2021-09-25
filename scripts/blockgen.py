#
#  Minethink
#  3D block based game.
#  Copyright Patrick Huang 2021
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

"""
Templates for creating block textures.
"""

import random
import numpy as np
import cv2


class Face:
    """
    One face of the texture.
    """
    data: np.ndarray

    def __init__(self):
        self.data = np.zeros((16, 16, 3), dtype=np.uint8)

    def fill_rand(self, palette, weights):
        """
        Fill self.data with random colors from palette.

        :param palette: Sequence of (r, g, b) values.
        :param weights: Sequence of weights corresponding to each color.
        """
        for y in range(16):
            for x in range(16):
                col = random.choices(palette, weights=weights, k=1)[0]
                self.data[y][x] = col


class Block:
    """
    One block texture.
    """
    top: Face
    bottom: Face
    left: Face
    right: Face
    front: Face
    back: Face

    def __init__(self):
        self.top = Face()
        self.bottom = Face()
        self.left = Face()
        self.right = Face()
        self.front = Face()
        self.back = Face()

    def export(self, path):
        """
        Save image to path.
        """
        img = np.zeros((64, 64, 3), dtype=np.uint8)
        img[0:16, 16:32, ...] = self.top.data
        img[16:32, 16:32, ...] = self.front.data
        img[32:48, 16:32, ...] = self.bottom.data
        img[48:64, 16:32, ...] = self.back.data
        img[16:32, 0:16, ...] = self.left.data
        img[16:32, 32:48, ...] = self.right.data

        cv2.imwrite(path, img)
