CFLAGS = --pedantic -Wall -std=c99 -O2 -g `pkg-config --cflags --libs gtkmm-3.0`
CPPFLAGS = -g `pkg-config --cflags gtkmm-3.0`
LIBS = `pkg-config --libs gtkmm-3.0`
AM_LDFLAGS =

bin_PROGRAMS = geometry
geometry_SOURCES = geometry.cpp MainWindow.cpp EditBox.cpp Canvas.cpp \
		   Shape/Circle.cpp Shape/Triangle.cpp Shape/Parallelogram.cpp \
		   Shape.cpp ShapeWindow.cpp

