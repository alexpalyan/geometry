

uidir = $(pkgdatadir)/ui
ui_DATA = geometry.ui

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(GEOMETRY_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = geometry

geometry_SOURCES = geometry.cpp MainWindow.cpp EditBox.cpp Canvas.cpp \
		   Shape/Circle.cpp Shape/Triangle.cpp Shape/Parallelogram.cpp \
		   Shape.cpp ShapeWindow.cpp Canvas.h EditBox.h MainWindow.h Shape.h ShapeWindow.h

geometry_LDFLAGS = 

geometry_LDADD = $(GEOMETRY_LIBS)


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

