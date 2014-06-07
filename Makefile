# using makefile in case we are not building in android enviroment

#
# Copyright (C) 2014 AliReza Forouzandeh Nezhad (aka alireza7991)
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

CROSS_COMPILE=arm-linux-gnueabi-
CC=gcc
CFLAGS=-I. -O3 -std=c99 -Wall
#enable static build since we are using glibs (will use MUSL later)
RELEASE_CFLAGS=-static
#enable interactive mod and gdb symboles
DEBUG_CFLAGS=-DANF_INTERACTIVE -g
DEBUG_BIN_NAME=anf_debug
RELEASE_BIN_NAME=anf
SRC=anf.c builtin_modules.c

#debug building needs no cross-compilation
debug: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(DEBUG_BIN_NAME)

test: debug
		./$(DEBUG_BIN_NAME) -h

cleandebug:
	rm -rf $(DEBUG_BIN_NAME)

clean:
	rm -rf $(RELEASE_BIN_NAME)

all: $(SRC)
	$(CROSS_COMPILE)$(CC) $(SRC) -o $(RELEASE_BIN_NAME)