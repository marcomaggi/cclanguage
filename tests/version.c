/*
  Part of: CCLanguage
  Contents: test for version functions
  Date: Jun  9, 2020

  Abstract

	Test file for version functions.

  Copyright (C) 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/

#include <cclanguage.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc CCLIB_UNUSED, char const *const argv[] CCLIB_UNUSED)
{
  printf("version number string: %s\n", cclang_version_string());
  printf("libtool version number: %d:%d:%d\n",
	 cclang_version_interface_current(),
	 cclang_version_interface_revision(),
	 cclang_version_interface_age());
  exit(EXIT_SUCCESS);
}

/* end of file */
