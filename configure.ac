#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([Geometry], [0.1], [https://github.com/freedayko/geometry/issues])
AM_INIT_AUTOMAKE([1.10 no-define foreign])
AC_CONFIG_SRCDIR([src/geometry.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])
PKG_CHECK_MODULES(GEOMETRY,gtkmm-3.0)

[]# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([pow sqrt])

AC_OUTPUT(Makefile src/Makefile)

