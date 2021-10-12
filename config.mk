# buttermilk version
VERSION = pre-0.1.0

# paths
PREFIX = /usr/local

# vte
VTELIBS = $(shell pkg-config --libs vte-2.91)
VTEFLAGS = $(shell pkg-config --cflags vte-2.91)

# compiler and linker
CC = cc
