Building
========

Minethink is written in C++, and uses GCC, GNU Make, and CMake for compiling.

Install those packages:

.. code-block:: bash

    sudo apt install build-essential cmake

Dependencies
------------

* OpenCV: See `opencv.org <https://opencv.org>`__ for build and install instructions.
* X11: ``sudo apt install libx11-dev``

Building
--------

.. code-block:: bash

    git clone https://github.com/phuang1024/minethink
    cd minethink

    make release  # for fast release version, or
    make debug    # for debugging

Installation
------------

After building, you can either run the executable or install it to ``/usr/local/games``.

Run the executable with ``./build/Minethink``.

Install it with ``sudo make install``.
