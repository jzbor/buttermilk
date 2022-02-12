# buttermilk version
VERSION = 0.2.0

# paths
PREFIX = /usr/local

# vte
VTELIBS = $(shell pkg-config --libs vte-2.91)
VTEFLAGS = $(shell pkg-config --cflags vte-2.91)

# libinih
INIHLIBS = -linih

# compiler and linker
CC = cc
