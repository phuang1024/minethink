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

BINDIR = /usr/local/games

THREADS = `nproc`

SOURCEDIR = ../src

.PHONY: help release debug install docs

release:
	mkdir -p build
	cd build; \
	cmake $(SOURCEDIR) -DCMAKE_BUILD_TYPE=Release; \
	make -j$(THREADS)

help:
	@echo "Minethink makefile help:"
	@echo "- make release: Build optimized release executable."
	@echo "- make debug: Build debug executable."
	@echo "- make install: Copy executable to /usr/games/minethink. May require sudo."
	@echo "- make docs: Build sphinx documentation in docs/"

debug:
	mkdir -p build
	cd build; \
	cmake $(SOURCEDIR) -DCMAKE_BUILD_TYPE=Debug; \
	make -j$(THREADS)

install:
	mkdir -p $(BINDIR)/minethinkf
	cp build/Minethink $(BINDIR)/minethinkf
	cp -r build/datafiles $(BINDIR)/minethinkf
	ln -s $(BINDIR)/minethinkf/Minethink $(BINDIR)/minethink

docs:
	cd docs; \
	make html
