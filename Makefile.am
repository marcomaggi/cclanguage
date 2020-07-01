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
doc_cclanguage_TEXINFOS	=		\
	doc/macros.texi			\
	doc/lgpl-3.0.texi		\
	doc/fdl-1.3.texi		\
	doc/overview-linking.texi

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
	src/cclanguage-compiler.h		\
	src/cclanguage-typedefs.h		\
	src/cclanguage-variadic-macros.h	\
	src/cclanguage-structs.h

lib_LTLIBRARIES			= libcclanguage.la
libcclanguage_la_LDFLAGS	= $(cclanguage_LINKER_VERSION)
libcclanguage_la_SOURCES	=		\
	src/cclanguage-internals.h		\
	src/cclanguage.h			\
	src/cclanguage-compiler.h		\
	src/cclanguage-typedefs.h		\
	src/cclanguage-variadic-macros.h	\
	src/cclanguage-structs.h		\
	src/cclanguage-library.c

.PHONY: library

library: libcclanguage.la


#### tests

check_PROGRAMS			=			\
	tests/version					\
							\
	tests/test-struct-by-ptr-no-descr		\
	tests/test-struct-by-ptr-with-descr		\
	tests/test-struct-by-val-no-descr		\
	tests/test-struct-by-val-with-descr		\
							\
	tests/test-destructor-trait			\
	tests/test-variadic-macros			\
	tests/test-virtual-methods			\
	tests/test-type-aliases

TESTS				= $(check_PROGRAMS)

cclanguage_tests_cppflags	= $(AM_CPPFLAGS) -I$(srcdir)/tests
cclanguage_tests_ldadd		= $(AM_LDFLAGS) libcclanguage.la -lm

## --------------------------------------------------------------------

tests_version_CPPFLAGS		= $(cclanguage_tests_cppflags)
tests_version_LDADD		= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

tests_test_struct_by_ptr_no_descr_SOURCES	=	\
	tests/struct-by-ptr-no-descr.h			\
	tests/struct-by-ptr-no-descr.c			\
	tests/test-struct-by-ptr-no-descr.c

tests_test_struct_by_ptr_no_descr_CPPFLAGS	= $(cclanguage_tests_cppflags)
tests_test_struct_by_ptr_no_descr_LDADD		= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

tests_test_struct_by_ptr_with_descr_SOURCES	=	\
	tests/struct-by-ptr-with-descr.h		\
	tests/struct-by-ptr-with-descr.c		\
	tests/test-struct-by-ptr-with-descr.c

tests_test_struct_by_ptr_with_descr_CPPFLAGS	= $(cclanguage_tests_cppflags)
tests_test_struct_by_ptr_with_descr_LDADD	= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

tests_test_struct_by_val_no_descr_SOURCES	=	\
	tests/struct-by-val-no-descr.h			\
	tests/struct-by-val-no-descr.c			\
	tests/test-struct-by-val-no-descr.c

tests_test_struct_by_val_no_descr_CPPFLAGS	= $(cclanguage_tests_cppflags)
tests_test_struct_by_val_no_descr_LDADD		= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

tests_test_struct_by_val_with_descr_SOURCES	=	\
	tests/struct-by-val-with-descr.h		\
	tests/struct-by-val-with-descr.c		\
	tests/test-struct-by-val-with-descr.c

tests_test_struct_by_val_with_descr_CPPFLAGS	= $(cclanguage_tests_cppflags)
tests_test_struct_by_val_with_descr_LDADD	= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

tests_test_destructor_trait_SOURCES		=	\
	tests/destructor-trait.h			\
	tests/struct-by-val-with-descr.h		\
	tests/struct-by-val-with-descr.c		\
	tests/struct-by-ptr-with-descr.h		\
	tests/struct-by-ptr-with-descr.c		\
	tests/test-destructor-trait.c

tests_test_destructor_trait_CPPFLAGS		= $(cclanguage_tests_cppflags)
tests_test_destructor_trait_LDADD		= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

tests_test_variadic_macros_SOURCES		= tests/test-variadic-macros.c
tests_test_variadic_macros_CPPFLAGS		= $(cclanguage_tests_cppflags)
tests_test_variadic_macros_LDADD		= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

tests_test_virtual_methods_SOURCES		= tests/test-virtual-methods.c
tests_test_virtual_methods_CPPFLAGS		= $(cclanguage_tests_cppflags)
tests_test_virtual_methods_LDADD		= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

tests_test_type_aliases_SOURCES			= tests/test-type-aliases.c
tests_test_type_aliases_CPPFLAGS		= $(cclanguage_tests_cppflags)
tests_test_type_aliases_LDADD			= $(cclanguage_tests_ldadd)

## --------------------------------------------------------------------

installcheck-local: $(TESTS)
	@for f in $(TESTS); do $(builddir)/$$f; done


#### common rules

include $(top_srcdir)/meta/automake/mmux-makefile-rules

### end of file
