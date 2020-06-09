## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
EXTRA_DIST		= INSTALL			\
			  meta/slackware/slack-desc.in
dist_doc_DATA		= README COPYING
AM_CFLAGS		= $(MMUX_CFLAGS)
AM_CPPFLAGS		= -I$(srcdir)/src -I$(builddir)/src
CLEANFILES		=

## --------------------------------------------------------------------

nodist_pkgconfig_DATA	= meta/scripts/cclanguage.pc


#### documentation

EXTRA_DIST		+= doc/cclibraries.style.css
CLEANFILES		+= doc/cclibraries.css

AM_MAKEINFOFLAGS	= --no-split
AM_MAKEINFOHTMLFLAGS	= --split=node -I $(srcdir)/examples -c WORDS_IN_PAGE=0 --css-ref=cclibraries.css \
	-c PRE_BODY_CLOSE="<p>This document describes version <tt>$(PACKAGE_VERSION)</tt> of <em>$(PACKAGE_NAME)</em>.</p>"

info_TEXINFOS		= doc/cclanguage.texi
doc_cclanguage_TEXINFOS	=	\
	doc/macros.texi		\
	doc/lgpl-3.0.texi	\
	doc/fdl-1.3.texi

## --------------------------------------------------------------------

doc/cclanguage.html/$(am__dirstamp): doc/$(am__dirstamp)
	@$(MKDIR_P) doc/cclanguage.html/
	@: > doc/cclanguage.html/$(am__dirstamp)

doc/cclanguage.html/cclibraries.css: doc/cclibraries.style.css doc/cclanguage.html/$(am__dirstamp)
	$(INSTALL) -m 0444 "$(top_srcdir)/doc/cclibraries.style.css" "$(builddir)/doc/cclanguage.html/cclibraries.css"

## --------------------------------------------------------------------

html-local: doc/cclanguage.html/cclibraries.css

install-html-local:
	$(MKDIR_P) "$(DESTDIR)$(htmldir)/cclanguage.html/"
	$(INSTALL) -m 0444 $(builddir)/doc/cclanguage.html/cclibraries.css "$(DESTDIR)$(htmldir)/cclanguage.html/"


#### libraries

cclanguage_CURRENT		= @cclanguage_VERSION_INTERFACE_CURRENT@
cclanguage_REVISION		= @cclanguage_VERSION_INTERFACE_REVISION@
cclanguage_AGE			= @cclanguage_VERSION_INTERFACE_AGE@
cclanguage_LINKER_VERSION	= -version-info $(cclanguage_CURRENT):$(cclanguage_REVISION):$(cclanguage_AGE)

include_HEADERS			=		\
	src/cclanguage.h			\
	src/cclanguage-platform.h		\
	src/cclanguage-compiler.h		\
	src/cclanguage-typedefs.h		\
	src/cclanguage-variadic-macros.h	\
	src/cclanguage-structs.h

lib_LTLIBRARIES			= libcclanguage.la
libcclanguage_la_LDFLAGS	= $(cclanguage_LINKER_VERSION)
libcclanguage_la_SOURCES	=		\
	src/cclanguage-internals.h		\
	src/cclanguage.h			\
	src/cclanguage-platform.h		\
	src/cclanguage-compiler.h		\
	src/cclanguage-typedefs.h		\
	src/cclanguage-variadic-macros.h	\
	src/cclanguage-structs.h		\
	src/cclanguage-library.c

.PHONY: library

library: libcclanguage.la


#### tests

check_PROGRAMS	= \
	tests/version

TESTS				= $(check_PROGRAMS)

cclanguage_tests_cppflags	= $(AM_CPPFLAGS) -I$(srcdir)/tests
cclanguage_tests_ldadd		= $(AM_LDFLAGS) libcclanguage.la

## --------------------------------------------------------------------

tests_version_CPPFLAGS		= $(cclanguage_tests_cppflags)
tests_version_LDADD		= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

installcheck-local: $(TESTS)
	@for f in $(TESTS); do $(builddir)/$$f; done


#### common rules

include $(top_srcdir)/meta/automake/mmux-makefile-rules

### end of file
