### @configure_input@
#

AC_PREREQ([2.69])
MMUX_PKG_VERSIONS([0],[1],[0],[devel.0])
AC_INIT([Cclanguage],[MMUX_PACKAGE_VERSION],
  [mrc.mgg@gmail.com],
  [cclanguage],[http://github.com/marcomaggi/cclanguage/])
MMUX_INIT
MMUX_LIBTOOL_LIBRARY_VERSIONS([cclanguage],10,0,0)
AC_REVISION([1.0])
AC_COPYRIGHT([Copyright (c) 2020 Marco Maggi <mrc.mgg@gmail.com>

This program is free software: you  can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free  Software Foundation, either version  3 of the License,  or (at
your option) any later version.

This program  is distributed  in the  hope that it  will be  useful, but
WITHOUT   ANY   WARRANTY;  without   even   the   implied  warranty   of
MERCHANTABILITY  or  FITNESS FOR  A  PARTICULAR  PURPOSE.  See  the  GNU
General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_MACRO_DIR([meta/autotools])
AC_CONFIG_AUX_DIR([meta/autotools])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([1.16 foreign subdir-objects])
AM_MAINTAINER_MODE

AM_PROG_AR
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_MKDIR_P

LT_PREREQ([2.4])
LT_INIT


#### basic system inspection

MMUX_CHECK_TARGET_OS
AX_IS_RELEASE([git-directory])

AC_LANG([C])
MMUX_LANG_C11

AM_PROG_AS
AM_PROG_CC_C_O
AC_HEADER_STDC
dnl These are needed for CCLibraries.
AC_CHECK_HEADERS([float.h math.h limits.h stdint.h stddef.h unistd.h wchar.h])
AC_HEADER_STDBOOL

AC_CACHE_SAVE


#### external libraries

PKG_PREREQ([0.29])
PKG_INSTALLDIR

AC_CACHE_SAVE


#### check platform type limits and sizes

MMUX_C_DETERMINE_SIZE_OF_LIBC_TYPES
AC_CACHE_SAVE

MMUX_C_DETERMINE_LIMITS_OF_LIBC_TYPES
AC_CACHE_SAVE

MMUX_C_DETERMINE_ALIASES_OF_LIBC_TYPES
AC_CACHE_SAVE


#### finish

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile]
  [src/cclanguage-platform.h]
  [meta/scripts/cclanguage.pc]
  [meta/slackware/slack-desc])
MMUX_OUTPUT
AC_OUTPUT

### end of file
