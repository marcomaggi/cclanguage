/*
  Part of: CCLanguage
  Contents: library functions
  Date: Jun  9, 2020

  Abstract

	This module implements library initialisation and version numbers inspection.

  Copyright (C) 2020 Marco Maggi <mrc.mgg@gmail.com>

  This program is free  software: you can redistribute it and/or  modify it under the
  terms of the  GNU Lesser General Public  License as published by  the Free Software
  Foundation, either version 3 of the License, or (at your option) any later version.

  This program  is distributed in the  hope that it  will be useful, but  WITHOUT ANY
  WARRANTY; without  even the implied  warranty of  MERCHANTABILITY or FITNESS  FOR A
  PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along with
  this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "cclanguage-internals.h"


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

char const *
cclang_version_string (void)
{
  return cclanguage_VERSION_INTERFACE_STRING;
}
int
cclang_version_interface_current (void)
{
  return cclanguage_VERSION_INTERFACE_CURRENT;
}
int
cclang_version_interface_revision (void)
{
  return cclanguage_VERSION_INTERFACE_REVISION;
}
int
cclang_version_interface_age (void)
{
  return cclanguage_VERSION_INTERFACE_AGE;
}


/** --------------------------------------------------------------------
 ** Library initialisation.
 ** ----------------------------------------------------------------- */

/*
void
cclang_library_init (void)
{
  static bool	to_be_initialised = true;

  if (to_be_initialised) {
    to_be_initialised = false;
    ccstr_library_init();
  }
}

*/

/* end of file */
