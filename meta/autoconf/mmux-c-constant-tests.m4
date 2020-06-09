## mmux-c-constant-tests.m4 --
#
# Determine value of C language constants.
#
# LICENSE
#
#   Copyright (c) 2020 Marco Maggi <mrc.mgg@gmail.com>
#
#   Copying and distribution of this file, with or without modification,
#   are permitted in  any medium without royalty  provided the copyright
#   notice and this  notice are preserved.  This file  is offered as-is,
#   without any warranty.
#


# MMUX_C_COMPUTE_SIGNED_INT(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the  integer value of  a C language  expression; the expected  result must be  a "signed
#   int".  Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_SIGNED_INT],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "%+d", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_COMPUTE_UNSIGNED_INT(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the integer  value of a C language  expression; the expected result must  be a "unsigned
#   int".  Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_UNSIGNED_INT],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "+%u", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_COMPUTE_SIGNED_LONG(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the integer value of a C language expression; the expected result must be a "signed long
#   int".  Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_SIGNED_LONG],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "%+ld", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_COMPUTE_UNSIGNED_LONG(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the integer  value of a C language  expression; the expected result must  be a "unsigned
#   long int".  Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_UNSIGNED_LONG],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "+%lu", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_COMPUTE_SIGNED_LONG_LONG(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the integer value of a C language expression; the expected result must be a "signed long
#   long int".  Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_SIGNED_LONG_LONG],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "%+lld", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_COMPUTE_UNSIGNED_LONG_LONG(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the integer  value of a C language  expression; the expected result must  be a "unsigned
#   long long int".  Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_UNSIGNED_LONG_LONG],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "+%llu", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_COMPUTE_DOUBLE(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the integer  value of a C language  expression; the expected result must  be a "double".
#   Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_DOUBLE],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "%+A", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_COMPUTE_LONG_DOUBLE(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the  integer value  of a  C language  expression; the  expected result  must be  a "long
#   double".  Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_LONG_DOUBLE],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "%+LA", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_COMPUTE_STRING(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Compute the  integer value of a  C language expression; the  expected result must be  a "char *"
#   referencing an ASCIIZ string.  Store the result in a shell variable.
#
# ARGUMENTS
#
#   $1 - The output variable name.
#   $2 - The C language expression.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
AC_DEFUN([MMUX_C_COMPUTE_STRING],
  [AC_RUN_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT
     $3
     int main (void)
     {
        FILE *f = fopen ("conftest.val", "w");
        fprintf(f, "%s", $2);
        return ferror (f) || fclose (f) != 0;
     }])],
     [AS_VAR_SET([$1],[`cat conftest.val`])],
     [$4],[$4])
   rm -f conftest.val])


# MMUX_C_VALUEOF_TEST_OUTPUT(STEM, EXPRESSION, VALUE)
#
# DESCRIPTION
#
#   Set the output that defines the result of a C language expression evaluation.
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - The expression.
#   $3 - The resulf of the evaluation.
#
# USAGE EXAMPLE
#
#   Example, to set the result of "INT_MAX":
#
#     MMUX_C_DEFINE_SIZEOF_OUPTUT([MAX_OF_INT],[INT_MAX],[$mmux_cv_valueof_INT_MAX])
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_MAX_OF_INT" to "mmux_cv_valueof_INT_MAX".
#   Define the GNU Autoconf substitution "MMUX_SIZEOF_MAX_OF_INT" to "mmux_cv_valueof_INT_MAX".
#
AC_DEFUN([MMUX_C_VALUEOF_TEST_OUTPUT],
  [AC_DEFINE_UNQUOTED([MMUX_VALUEOF_$1],[$3],[the value of '$2'])
   AC_SUBST([MMUX_VALUEOF_$1],[$3])])


# MMUX_C_SIGNED_INT_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the  integer  value  of  an  expression.   Store  the  result  in  the  cached  value
#   "mmux_cv_c_valueof_$1".  Define the substitution "MMUX_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to a "signed int".
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL_VALUE".  Define the substitution "MMUX_VALUEOF_EINVAL_VALUE".
#
#     MMUX_C_SIGNED_INT_VALUEOF_TEST([EINVAL_VALUE],[EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_SIGNED_INT_VALUEOF_TEST],
  [AC_CACHE_CHECK([the 'signed int' value of '$2'],
     [mmux_cv_c_valueof_$1],
     [MMUX_C_COMPUTE_SIGNED_INT([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_SIGNED_INT_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_SIGNED_INT_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 - Constant name to be determined, it must fit into a "signed int".  Output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL".  Define the substitution "MMUX_VALUEOF_EINVAL".
#
#     MMUX_C_SIGNED_INT_CONSTANT_TEST([EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_SIGNED_INT_CONSTANT_TEST],[MMUX_C_SIGNED_INT_VALUEOF_TEST([$1],[$1],[$2])])

# MMUX_C_SIGNED_INT_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper for  MMUX_C_SIGNED_INT_CONSTANT_TEST that applies this  macro to a list  of preprocesso
#   symbols.
#
# ARGUMENTS
#
#   $1 - Space separated list of constant names to be determined, they must fit into a "signed int".
#        Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value of  EINVAL, ENOMEM as defined by "errno.h".  Store the  values in the cached
#   shell   variables  "mmux_cv_c_valueof_EINVAL"   and   "mmux_cv_c_valueof_ENOMEM".   Define   the
#   substitutions "MMUX_VALUEOF_EINVAL" and "MMUX_VALUEOF_ENOMEM".
#
#   MMUX_C_SIGNED_INT_CONSTANT_TESTS([EINVAL ENOMEM],[
#   #include <errno.h>
#   ])
#
AC_DEFUN([MMUX_C_SIGNED_INT_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_SIGNED_INT_CONSTANT_TEST(],[,$2)])])


# MMUX_C_UNSIGNED_INT_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the  integer  value  of  an  expression.   Store  the  result  in  the  cached  value
#   "mmux_cv_c_valueof_$1".  Define the substitution "MMUX_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to a "unsigned int".
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL_VALUE".  Define the substitution "MMUX_VALUEOF_EINVAL_VALUE".
#
#     MMUX_C_UNSIGNED_INT_VALUEOF_TEST([EINVAL_VALUE],[EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_UNSIGNED_INT_VALUEOF_TEST],
  [AC_CACHE_CHECK([the 'unsigned int' value of '$2'],
     [mmux_cv_c_valueof_$1],
     [MMUX_C_COMPUTE_UNSIGNED_INT([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_UNSIGNED_INT_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_UNSIGNED_INT_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 - Constant  name to be determined,  it must fit into a  "unsigned int".  Output
#        variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL".  Define the substitution "MMUX_VALUEOF_EINVAL".
#
#     MMUX_C_UNSIGNED_INT_CONSTANT_TEST([EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_UNSIGNED_INT_CONSTANT_TEST],[MMUX_C_UNSIGNED_INT_VALUEOF_TEST([$1],[$1],[$2])])

# MMUX_C_UNSIGNED_INT_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_UNSIGNED_INT_CONSTANT_TEST that applies this macro to a list of preprocessor
#   symbols.
#
# ARGUMENTS
#
#   $1 -  Space separated list of  constant names to be  determined, they must fit  into a "unsigned
#        int".  Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL, ENOMEM as defined  by "errno.h".  Store the values  n the cached
#   shell   variables  "mmux_cv_c_valueof_EINVAL"   and   "mmux_cv_c_valueof_ENOMEM".   Define   the
#   substitutions "MMUX_VALUEOF_EINVAL" and "MMUX_VALUEOF_ENOMEM".
#
#   MMUX_C_UNSIGNED_INT_CONSTANT_TESTS([EINVAL ENOMEM],[
#   #include <errno.h>
#   ])
#
AC_DEFUN([MMUX_C_UNSIGNED_INT_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_UNSIGNED_INT_CONSTANT_TEST(],[,$2)])])


# MMUX_C_SIGNED_LONG_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the  integer  value  of  an  expression.   Store  the  result  in  the  cached  value
#   "mmux_cv_c_valueof_$1".  Define the substitution "MMUX_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to a "signed long".
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL_VALUE".  Define the substitution "MMUX_VALUEOF_EINVAL_VALUE".
#
#     MMUX_C_SIGNED_LONG_VALUEOF_TEST([EINVAL_VALUE],[EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_SIGNED_LONG_VALUEOF_TEST],
  [AC_CACHE_CHECK([the 'signed long int' value of '$2'],
     [mmux_cv_c_valueof_$1],
     [MMUX_C_COMPUTE_SIGNED_LONG([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_SIGNED_LONG_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_SIGNED_LONG_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 - Constant name to be determined, it must fit into a "signed long".  Output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL".  Define the substitution "MMUX_VALUEOF_EINVAL".
#
#     MMUX_C_SIGNED_LONG_CONSTANT_TEST([EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_SIGNED_LONG_CONSTANT_TEST],[MMUX_C_SIGNED_LONG_VALUEOF_TEST([$1],[$1],[$2])])

# MMUX_C_SIGNED_LONG_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper for  MMUX_C_SIGNED_LONG_CONSTANT_TEST that applies this  macro to a list  of preprocesso
#   symbols.
#
# ARGUMENTS
#
#   $1 - Space separated list of constant  names to be determined, they must fit into
#        a "signed long".  Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value of  EINVAL, ENOMEM as defined by "errno.h".  Store the  values in the cached
#   shell   variables  "mmux_cv_c_valueof_EINVAL"   and   "mmux_cv_c_valueof_ENOMEM".   Define   the
#   substitutions "MMUX_VALUEOF_EINVAL" and "MMUX_VALUEOF_ENOMEM".
#
#   MMUX_C_SIGNED_LONG_CONSTANT_TESTS([EINVAL ENOMEM],[
#   #include <errno.h>
#   ])
#
AC_DEFUN([MMUX_C_SIGNED_LONG_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_SIGNED_LONG_CONSTANT_TEST(],[,$2)])])


# MMUX_C_UNSIGNED_LONG_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the  integer  value  of  an  expression.   Store  the  result  in  the  cached  value
#   "mmux_cv_c_valueof_$1".  Define the substitution "MMUX_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to a "unsigned long".
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL_VALUE".  Define the substitution "MMUX_VALUEOF_EINVAL_VALUE".
#
#     MMUX_C_UNSIGNED_LONG_VALUEOF_TEST([EINVAL_VALUE],[EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_UNSIGNED_LONG_VALUEOF_TEST],
  [AC_CACHE_CHECK([the 'unsigned long int' value of '$2'],
     [mmux_cv_c_valueof_$1],
     [MMUX_C_COMPUTE_UNSIGNED_LONG([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_UNSIGNED_LONG_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_UNSIGNED_LONG_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 - Constant  name to be determined,  it must fit into a  "unsigned long".  Output
#        variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL".  Define the substitution "MMUX_VALUEOF_EINVAL".
#
#     MMUX_C_UNSIGNED_LONG_CONSTANT_TEST([EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_UNSIGNED_LONG_CONSTANT_TEST],[MMUX_C_UNSIGNED_LONG_VALUEOF_TEST([$1],[$1],[$2])])

# MMUX_C_UNSIGNED_LONG_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_UNSIGNED_LONG_CONSTANT_TEST that applies this macro to a list of preprocessor
#   symbols.
#
# ARGUMENTS
#
#   $1 -  Space separated list of  constant names to be  determined, they must fit  into a "unsigned
#        long".  Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL, ENOMEM as defined  by "errno.h".  Store the values  n the cached
#   shell   variables  "mmux_cv_c_valueof_EINVAL"   and   "mmux_cv_c_valueof_ENOMEM".   Define   the
#   substitutions "MMUX_VALUEOF_EINVAL" and "MMUX_VALUEOF_ENOMEM".
#
#   MMUX_C_UNSIGNED_LONG_CONSTANT_TESTS([EINVAL ENOMEM],[
#   #include <errno.h>
#   ])
#
AC_DEFUN([MMUX_C_UNSIGNED_LONG_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_UNSIGNED_LONG_CONSTANT_TEST(],[,$2)])])


# MMUX_C_SIGNED_LONG_LONG_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the  integer  value  of  an  expression.   Store  the  result  in  the  cached  value
#   "mmux_cv_c_valueof_$1".  Define the substitution "MMUX_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to a "signed long long".
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL_VALUE".  Define the substitution "MMUX_VALUEOF_EINVAL_VALUE".
#
#     MMUX_C_SIGNED_LONG_LONG_VALUEOF_TEST([EINVAL_VALUE],[EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_SIGNED_LONG_LONG_VALUEOF_TEST],
  [AC_CACHE_CHECK([the 'signed long long int' value of '$2'],
     [mmux_cv_c_valueof_$1],
     [MMUX_C_COMPUTE_SIGNED_LONG_LONG([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_SIGNED_LONG_LONG_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_SIGNED_LONG_LONG_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 - Constant name to be determined, it must fit into a "signed long long".  Output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL".  Define the substitution "MMUX_VALUEOF_EINVAL".
#
#     MMUX_C_SIGNED_LONG_LONG_CONSTANT_TEST([EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_SIGNED_LONG_LONG_CONSTANT_TEST],[MMUX_C_SIGNED_LONG_LONG_VALUEOF_TEST([$1],[$1],[$2])])

# MMUX_C_SIGNED_LONG_LONG_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper  for  MMUX_C_SIGNED_LONG_LONG_CONSTANT_TEST  that  applies  this  macro  to  a  list  of
#   preprocessor symbols.
#
# ARGUMENTS
#
#   $1 - Space separated list of constant names to  be determined, they must fit into a "signed long
#        long".  Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value of  EINVAL, ENOMEM as defined by "errno.h".  Store the  values in the cached
#   shell   variables  "mmux_cv_c_valueof_EINVAL"   and   "mmux_cv_c_valueof_ENOMEM".   Define   the
#   substitutions "MMUX_VALUEOF_EINVAL" and "MMUX_VALUEOF_ENOMEM".
#
#   MMUX_C_SIGNED_LONG_LONG_CONSTANT_TESTS([EINVAL ENOMEM],[
#   #include <errno.h>
#   ])
#
AC_DEFUN([MMUX_C_SIGNED_LONG_LONG_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_SIGNED_LONG_LONG_CONSTANT_TEST(],[,$2)])])


# MMUX_C_UNSIGNED_LONG_LONG_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the  integer  value  of  an  expression.   Store  the  result  in  the  cached  value
#   "mmux_cv_c_valueof_$1".  Define the substitution "MMUX_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to a "signed long long".
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL_VALUE".  Define the substitution "MMUX_VALUEOF_EINVAL_VALUE".
#
#     MMUX_C_UNSIGNED_LONG_LONG_VALUEOF_TEST([EINVAL_VALUE],[EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_UNSIGNED_LONG_LONG_VALUEOF_TEST],
  [AC_CACHE_CHECK([the 'unsigned long long int' value of '$2'],
     [mmux_cv_c_valueof_$1],
     [MMUX_C_COMPUTE_UNSIGNED_LONG_LONG([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_UNSIGNED_LONG_LONG_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 - Constant name to be determined, it must fit into a "signed long long".  Output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value  of EINVAL as defined by  "errno.h".  Store it in the  cached shell variable
#   "mmux_cv_c_valueof_EINVAL".  Define the substitution "MMUX_VALUEOF_EINVAL".
#
#     MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TEST([EINVAL],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TEST],[MMUX_C_UNSIGNED_LONG_LONG_VALUEOF_TEST([$1],[$1],[$2])])

# MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper  for  MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TEST  that  applies  this  macro  to  a  list  of
#   preprocessor symbols.
#
# ARGUMENTS
#
#   $1 - Space separated list of constant names to  be determined, they must fit into a "signed long
#        long".  Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the value of  EINVAL, ENOMEM as defined by "errno.h".  Store the  values in the cached
#   shell   variables  "mmux_cv_c_valueof_EINVAL"   and   "mmux_cv_c_valueof_ENOMEM".   Define   the
#   substitutions "MMUX_VALUEOF_EINVAL" and "MMUX_VALUEOF_ENOMEM".
#
#   MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TESTS([EINVAL ENOMEM],[
#   #include <errno.h>
#   ])
#
AC_DEFUN([MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TEST(],[,$2)])])


# MMUX_C_DOUBLE_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the  "double"  value  of  an  expression.  Store  the  result  in  the  cached  value
#   "mmux_cv_c_valueof_$1".  Define the substitution "MMUX_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to a "double".
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine  the value  of DBL_EPSILON  as defined  by "float.h".   Store it  in the  cached shell
#   variable       "mmux_cv_c_valueof_DBL_EPSILON_VALUE".        Define       the       substitution
#   "MMUX_VALUEOF_DBL_EPSILON_VALUE".
#
#     MMUX_C_DOUBLE_VALUEOF_TEST([DBL_EPSILON_VALUE],[DBL_EPSILON],[
#     #include <float.h>
#     ])
#
AC_DEFUN([MMUX_C_DOUBLE_VALUEOF_TEST],
  [AC_CACHE_CHECK([the floating-point 'double' value of '$2'],
     [mmux_cv_c_valueof_$1],
     [MMUX_C_COMPUTE_DOUBLE([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_DOUBLE_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_DOUBLE_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 - Constant name to be determined, it must fit into a "double".  Output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the  value of  DBL_EPSILON as  defined by "float.h".   Store it  in the  cached shell#
#   variable "mmux_cv_c_valueof_DBL_EPSILON".  Define the substitution "MMUX_VALUEOF_DBL_EPSILON".
#
#     MMUX_C_DOUBLE_CONSTANT_TEST([DBL_EPSILON],[
#     #include <float.h>
#     ])
#
AC_DEFUN([MMUX_C_DOUBLE_CONSTANT_TEST],[MMUX_C_DOUBLE_VALUEOF_TEST([$1],[$1],[$2])])

# MMUX_C_DOUBLE_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper  for MMUX_C_DOUBLE_CONSTANT_TEST  that  applies  this macro  to  a  list of  preprocesso
#   symbols.
#
# ARGUMENTS
#
#   $1 -  Space separated list of  constant names to be  determined, they must fit  into a "double".
#        Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
AC_DEFUN([MMUX_C_DOUBLE_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_DOUBLE_CONSTANT_TEST(],[,$2)])])


# MMUX_C_LONG_DOUBLE_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the "long  double" value  of an  expression.  Store  the result  in the  cached value
#   "mmux_cv_c_valueof_$1".  Define the substitution "MMUX_LONG_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to a "long double".
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine the  value of  LDBL_EPSILON as  defined by "float.h".   Store it  in the  cached shell
#   variable       "mmux_cv_c_valueof_LDBL_EPSILON_VALUE".        Define      the       substitution
#   "MMUX_LONG_VALUEOF_LDBL_EPSILON_VALUE".
#
#     MMUX_C_LONG_DOUBLE_VALUEOF_TEST([LDBL_EPSILON_VALUE],[LDBL_EPSILON],[
#     #include <float.h>
#     ])
#
AC_DEFUN([MMUX_C_LONG_DOUBLE_VALUEOF_TEST],
  [AC_CACHE_CHECK([the floating-point 'long double' value of '$2'],
     [mmux_cv_c_valueof_$1],
     [MMUX_C_COMPUTE_LONG_DOUBLE([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_LONG_DOUBLE_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_LONG_DOUBLE_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 - Constant name to be determined, it must fit into a "long double".  Output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
# USAGE EXAMPLE
#
#   Determine the  value of LDBL_EPSILON  as defined  by "float.h".  Store  it in the  cached shell#
#   variable        "mmux_cv_c_valueof_LDBL_EPSILON".          Define        the        substitution
#   "MMUX_LONG_VALUEOF_LDBL_EPSILON".
#
#     MMUX_C_LONG_DOUBLE_CONSTANT_TEST([LDBL_EPSILON],[
#     #include <float.h>
#     ])
#
AC_DEFUN([MMUX_C_LONG_DOUBLE_CONSTANT_TEST],[MMUX_C_LONG_DOUBLE_VALUEOF_TEST([$1],[$1],[$2])])

# MMUX_C_LONG_DOUBLE_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper for  MMUX_C_LONG_DOUBLE_CONSTANT_TEST that applies this  macro to a list  of preprocesso
#   symbols.
#
# ARGUMENTS
#
#   $1  - Space  separated list  of constant  names to  be determined,  they must  fit into  a "long
#        double".  Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
AC_DEFUN([MMUX_C_LONG_DOUBLE_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_LONG_DOUBLE_CONSTANT_TEST(],[,$2)])])


# MMUX_C_STRING_VALUEOF_TEST(OUTPUT_VARIABLE, EXPRESSION, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine  the  string  value  of  an  expression.    Store  the  result  in  the  cached  value
#   "mmux_cv_c_string_valueof_$1".  Define the substitution "MMUX_VALUEOF_$1".
#
# ARGUMENTS
#
#   $1 - Output variable stem, it must be a valid C language name.
#   $2 - The C language expression evaluating to an ASCIIZ string pointer.
#   $3 - A chunk of C language code that includes the required header files.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Determine the value of "strerror(EINVAL)" as defined by "errno.h".  Store it in the cached shell
#   variable       "mmux_cv_c_string_valueof_STREINVAL".         Define       the       substitution
#   "MMUX_VALUEOF_STREINVAL".
#
#     MMUX_C_STRING_VALUEOF_TEST([STREINVAL],[strerror(EINVAL)],[
#     #include <errno.h>
#     ])
#
AC_DEFUN([MMUX_C_STRING_VALUEOF_TEST],
  [AC_CACHE_CHECK([the ASCIIZ string 'char *' value of '$2'],
     [mmux_cv_c_string_valueof_$1],
     [MMUX_C_COMPUTE_STRING([mmux_cv_c_valueof_$1],
       [$2],
       [$3],
       [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_valueof_$1],["0"])],[$4])])])
   MMUX_C_VALUEOF_TEST_OUTPUT([$1],[$2],[$mmux_cv_c_valueof_$1])])

# MMUX_C_STRING_CONSTANT_TEST
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_STRING_VALUEOF_TEST.  Determine the value of a preprocessor symbol.
#
# ARGUMENTS
#
#   $1 -  Constant name to be  determined, it must evaluate  to a pointer to  ASCIIZ string.  Output
#        variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
AC_DEFUN([MMUX_C_STRING_CONSTANT_TEST],[MMUX_C_STRING_VALUEOF_TEST([$1],[$1])])

# MMUX_C_STRING_CONSTANT_TESTS
#
# DESCRIPTION
#
#   Wrapper for MMUX_C_CONSTANT_TEST that applies this macro to a list of preprocessor symbols.
#
# ARGUMENTS
#
#   $1 - Space separated list of constant names to be determined, they must evaluate to a pointer to
#        ASCIIZ string.  Every name is also an output variable stem.
#   $2 - A chunk of C language code that includes the required header files.
#
AC_DEFUN([MMUX_C_STRING_CONSTANT_TESTS],[m4_map_args_w($1,[MMUX_C_STRING_CONSTANT_TEST(],[)])])


# MMUX_C_DEFINE_SIZEOF_OUPTUT(STEM, DESCRIPTION, SIZE_IN_BYTES)
#
# DESCRIPTION
#
#   Set the output that defines the size in bytes of an expression.
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - A description text for the meaning of this size.
#   $3 - The size in bytes.
#
# USAGE EXAMPLE
#
#   Example, to set the size of "int16_t":
#
#     MMUX_C_DEFINE_SIZEOF_OUPTUT([SINT16],[int16_t],[$mmux_cv_sizeof_SINT16])
#
#   Define the C language preprocessor macro "MMUX_SIZEOF_SINT16" to "$mmux_cv_c_sizeof_SINT16".
#   Define the GNU Autoconf substitution "MMUX_SIZEOF_SINT16" to "$mmux_cv_c_sizeof_SINT16".
#
AC_DEFUN([MMUX_C_DEFINE_SIZEOF_OUPTUT],
  [AC_DEFINE_UNQUOTED([MMUX_SIZEOF_$1],[$3],[the size of '$2'])
   AC_SUBST([MMUX_SIZEOF_$1],          [$3])])


# MMUX_C_DETERMINE_SIZEOF_TYPE(STEM, TYPE, INCLUDES, ACTION-IF-FAILS)
#
# DESCRIPTION
#
#   Determine the size in bytes of the C language  type TYPE, using the header files selected by the
#   directives in INCLUDES.
#
#   Define the the cached variable "mmux_cv_sizeof_$1" to the number of bytes.
#
#   Define the preprocessor macro "MMUX_SIZEOF_$1" to the number of bytes.
#
#   Define the substitution symbol "MMUX_SIZEOF_$1" to the number of bytes.
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - The C language type of which we want to determine the size.
#   $3 - The preprocessor include directives we need to include the required headers.
#   $4 - Action if fails.
#
# USAGE EXAMPLE
#
#   Example, to determine the size of "size_t":
#
#     MMUX_C_DETERMINE_SIZEOF_TYPE([SIZE_T],[size_t],[
#     #ifdef HAVE_STDDEF_H
#     #  include <stddef.h>
#     #endif
#     ])
#
AC_DEFUN([MMUX_C_DETERMINE_SIZEOF_TYPE],
  [AC_CACHE_CHECK([the size of '$2'],
     [mmux_cv_c_sizeof_$1],
     [AC_COMPUTE_INT([mmux_cv_c_sizeof_$1],
        [sizeof($2)],
        [$3],
        [m4_if([$4],,[AS_VAR_SET([mmux_cv_c_sizeof_$1],["0"])],[$4])])])
   MMUX_C_DEFINE_SIZEOF_OUPTUT([$1],[$2],[$mmux_cv_c_sizeof_$1])])


# MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE(TYPESTEM, TYPESPEC, SIZE_IN_BYTES)
#
# DESCRIPTION
#
#   Set the output that defines the size in bytes of a fixed-width integer type.
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - The C language type specification.
#   $3 - The size of the type in bytes.
#
# USAGE EXAMPLE
#
#   Example, to determine the size of "int16_t":
#
#     MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([SINT16], [int16_t], [2])
#
#   Define the cached variable "mmux_cv_c_sizeof_SINT16" to 2.
#   Define the C language preprocessor macro "MMUX_SIZEOF_SINT16" to "$mmux_cv_c_sizeof_SINT16".
#   Define the GNU Autoconf substitution "MMUX_SIZEOF_SINT16" to "$mmux_cv_c_sizeof_SINT16".
#
AC_DEFUN([MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE],
  [AC_CACHE_CHECK([the size of the fixed-width type '$2'],
     [mmux_cv_c_sizeof_$1],
     [AS_VAR_SET([mmux_cv_c_sizeof_$1], $3)])
   MMUX_C_DEFINE_SIZEOF_OUPTUT([$1],[$2],[$mmux_cv_c_sizeof_$1])])


# MMUX_C_DETERMINE_SIZE_OF_LIBC_TYPES
#
# DESCRIPTION
#
#   Determine the size in bytes of the C language standard types defined by the C library.
#
AC_DEFUN([MMUX_C_DETERMINE_SIZE_OF_LIBC_TYPES],
  [AX_REQUIRE_DEFINED([MMUX_INCLUDE_UNISTD_H])
   AX_REQUIRE_DEFINED([MMUX_INCLUDE_STDDEF_H])
   AX_REQUIRE_DEFINED([MMUX_INCLUDE_STDINT_H])
   AX_REQUIRE_DEFINED([MMUX_INCLUDE_WCHAR_H])

   MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([SINT8],  [int8_t],   [1])
   MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([UINT8],  [uint8_t],  [1])
   MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([SINT16], [int16_t],  [2])
   MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([UINT16], [uint16_t], [2])
   MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([SINT32], [int32_t],  [4])
   MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([UINT32], [uint32_t], [4])
   MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([SINT64], [int64_t],  [8])
   MMUX_C_SET_SIZE_OF_FIXED_WIDTH_TYPE([UINT64], [uint64_t], [8])

   MMUX_C_DETERMINE_SIZEOF_TYPE([SCHAR],   [signed   char])
   MMUX_C_DETERMINE_SIZEOF_TYPE([UCHAR],   [unsigned char])
   MMUX_C_DETERMINE_SIZEOF_TYPE([SSHRT],   [signed   short int])
   MMUX_C_DETERMINE_SIZEOF_TYPE([USHRT],   [unsigned short int])
   MMUX_C_DETERMINE_SIZEOF_TYPE([SINT],    [signed   int])
   MMUX_C_DETERMINE_SIZEOF_TYPE([UINT],    [unsigned int])
   MMUX_C_DETERMINE_SIZEOF_TYPE([SLONG],   [signed   long int])
   MMUX_C_DETERMINE_SIZEOF_TYPE([ULONG],   [unsigned long int])
   MMUX_C_DETERMINE_SIZEOF_TYPE([SLLONG],  [signed   long long int])
   MMUX_C_DETERMINE_SIZEOF_TYPE([ULLONG],  [unsigned long long int])
   MMUX_C_DETERMINE_SIZEOF_TYPE([FLOAT],   [float])
   MMUX_C_DETERMINE_SIZEOF_TYPE([DOUBLE],  [double])
   MMUX_C_DETERMINE_SIZEOF_TYPE([LDOUBLE], [long double])

   MMUX_C_DETERMINE_SIZEOF_TYPE([WINT],    [wint_t],    [MMUX_INCLUDE_WCHAR_H])
   MMUX_C_DETERMINE_SIZEOF_TYPE([WCHAR],   [wchar_t],   [MMUX_INCLUDE_WCHAR_H])

   MMUX_C_DETERMINE_SIZEOF_TYPE([SINTMAX], [intmax_t],  [MMUX_INCLUDE_STDINT_H])
   MMUX_C_DETERMINE_SIZEOF_TYPE([UINTMAX], [uintmax_t], [MMUX_INCLUDE_STDINT_H])

   MMUX_C_DETERMINE_SIZEOF_TYPE([SINTPTR], [intptr_t],  [MMUX_INCLUDE_STDINT_H])
   MMUX_C_DETERMINE_SIZEOF_TYPE([UINTPTR], [uintptr_t], [MMUX_INCLUDE_STDINT_H])

   MMUX_C_DETERMINE_SIZEOF_TYPE([PTRDIFF], [ptrdiff_t], [MMUX_INCLUDE_STDDEF_H])

   MMUX_C_DETERMINE_SIZEOF_TYPE([SSIZE],   [ssize_t],   [MMUX_INCLUDE_UNISTD_H])
   MMUX_C_DETERMINE_SIZEOF_TYPE([USIZE],   [size_t],    [MMUX_INCLUDE_STDDEF_H])

   MMUX_C_DETERMINE_SIZEOF_TYPE([OFF],     [off_t],     [MMUX_INCLUDE_UNISTD_H])
   ])


# MMUX_C_DEFINE_MAX_LIMIT_OUPTUT(STEM, DESCRIPTION, LIMIT_VALUE)
#
# DESCRIPTION
#
#   Set the output that defines the range maximum limit of a type.
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - A description text for the meaning of this limit.
#   $3 - The limit.
#
# USAGE EXAMPLE
#
#   Example, to set the maximum limit of "int16_t":
#
#     MMUX_C_DEFINE_MAX_LIMIT_OUPTUT([SINT16],[int16_t],["$mmux_cv_c_valueof_SINT16_MAX"])
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_SINT16_MAX" to "$mmux_cv_c_valueof_SINT16_MAX".
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_SINT16_MAX" to "$mmux_cv_c_valueof_SINT16_MAX".
#
AC_DEFUN([MMUX_C_DEFINE_MAX_LIMIT_OUPTUT],
  [AC_DEFINE_UNQUOTED([MMUX_VALUEOF_$1_MAX],[$3],[the range maximum limit of '$2'])
   AC_SUBST([MMUX_VALUEOF_$1_MAX],          [$3])])

# MMUX_C_DEFINE_MIN_LIMIT_OUPTUT(STEM, DESCRIPTION, LIMIT_VALUE)
#
# DESCRIPTION
#
#   Set the output that defines the range minimum limit of a type.
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - A description text for the meaning of this limit.
#   $3 - The limit.
#
# USAGE EXAMPLE
#
#   Example, to set the minimum limit of "int16_t":
#
#     MMUX_C_DEFINE_MIN_LIMIT_OUPTUT([SINT16],[int16_t],["$mmux_cv_c_valueof_SINT16_MIN"])
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_SINT16_MIN" to "$mmux_cv_c_valueof_SINT16_MIN".
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_SINT16_MIN" to "$mmux_cv_c_valueof_SINT16_MIN".
#
AC_DEFUN([MMUX_C_DEFINE_MIN_LIMIT_OUPTUT],
  [AC_DEFINE_UNQUOTED([MMUX_VALUEOF_$1_MIN],[$3],[the range minimum limit of '$2'])
   AC_SUBST([MMUX_VALUEOF_$1_MIN],          [$3])])


# MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS(STEM, TYPENAME)
#
# DESCRIPTION
#
#   Determine the  range limit of  a signed  integer type by  comparing its size  with predetermined
#   sizes of "int8_t", "int16_t", "int32_t", "int64_t".
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - The type name.
#
# USAGE EXAMPLE
#
#   Example, to determine the limits of "ssize_t":
#
#     MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS([SSIZE],[ssize_t])
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_SSIZE_MAX" to the maximum limit.
#   Define the C language preprocessor macro "MMUX_VALUEOF_SSIZE_MIN" to the minimum limit.
#
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_SSIZE_MAX" to the maximum limit.
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_SSIZE_MIN" to the minimum limit.
#
AC_DEFUN([MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS],
  [AC_CACHE_CHECK([the value of '$1_MAX'],
     [mmux_cv_c_valueof_$1_MAX],
     [AS_IF([test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT8"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],[$mmux_cv_c_valueof_SINT8_MAX])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT16"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],[$mmux_cv_c_valueof_SINT16_MAX])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT32"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],[$mmux_cv_c_valueof_SINT32_MAX])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT64"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],[$mmux_cv_c_valueof_SINT64_MAX])],

            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],0)])])

   AC_CACHE_CHECK([the value of '$1_MIN'],
     [mmux_cv_c_valueof_$1_MIN],
     [AS_IF([test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT8"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MIN],[$mmux_cv_c_valueof_SINT8_MIN])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT16"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MIN],[$mmux_cv_c_valueof_SINT16_MIN])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT32"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MIN],[$mmux_cv_c_valueof_SINT32_MIN])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT64"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MIN],[$mmux_cv_c_valueof_SINT64_MIN])],

            [AS_VAR_SET([mmux_cv_c_valueof_$1_MIN],0)])])

   MMUX_C_DEFINE_MAX_LIMIT_OUPTUT([$1],[$2],["$mmux_cv_c_valueof_$1_MAX"])
   MMUX_C_DEFINE_MIN_LIMIT_OUPTUT([$1],[$2],["$mmux_cv_c_valueof_$1_MIN"])])


# MMUX_C_DETERMINE_UNSIGNED_INTEGER_LIMITS(STEM, TYPENAME)
#
# DESCRIPTION
#
#   Determine the range limit  of an unsigned integer type by comparing  its size with predetermined
#   sizes of "uint8_t", "uint16_t", "uint32_t", "uint64_t".
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - The type name.
#
# USAGE EXAMPLE
#
#   Example, to determine the limits of "size_t":
#
#     MMUX_C_DETERMINE_UNSIGNED_INTEGER_LIMITS([USIZE],[size_t])
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_USIZE_MAX" to the maximum limit.
#   Define the C language preprocessor macro "MMUX_VALUEOF_USIZE_MIN" to the minimum limit.
#
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_USIZE_MAX" to the maximum limit.
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_USIZE_MIN" to the minimum limit.
#
AC_DEFUN([MMUX_C_DETERMINE_UNSIGNED_INTEGER_LIMITS],
  [AC_CACHE_CHECK([the value of '$1_MAX'],
     [mmux_cv_c_valueof_$1_MAX],
     [AS_IF([test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_UINT8"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],[$mmux_cv_c_valueof_UINT8_MAX])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_UINT16"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],[$mmux_cv_c_valueof_UINT16_MAX])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_UINT32"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],[$mmux_cv_c_valueof_UINT32_MAX])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_UINT64"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],[$mmux_cv_c_valueof_UINT64_MAX])],

            [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX],0)])])

   AC_CACHE_CHECK([the value of '$1_MIN'],
     [mmux_cv_c_valueof_$1_MIN],
     [AS_VAR_SET([mmux_cv_c_valueof_$1_MIN],[0])])

   MMUX_C_DEFINE_MAX_LIMIT_OUPTUT([$1],[$2],["$mmux_cv_c_valueof_$1_MAX"])
   MMUX_C_DEFINE_MIN_LIMIT_OUPTUT([$1],[$2],["$mmux_cv_c_valueof_$1_MIN"])])


# MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE(TYPESTEM, TYPENAME, MIN_LIMIT, MAX_LIMIT)
#
# DESCRIPTION
#
#   Set the output that defines the range limits of a fixed-width integer type.
#
# ARGUMENTS
#
#   $1 - A stem used to build variable names.
#   $2 - The C language type name.
#   $3 - The minimum limit.
#   $4 - The maximum limit.
#
# USAGE EXAMPLE
#
#   Example, to set the limits of "int16_t":
#
#     MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([SINT16], [int16_t], [-32768], [+32767])
#
#   Define the cached variable "mmux_cv_c_valueof_SINT16_MAX" to +32767.
#   Define the cached variable "mmux_cv_c_valueof_SINT16_MIN" to -32768.
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_SINT16_MAX" to "$mmux_cv_c_valueof_SINT16_MAX".
#   Define the C language preprocessor macro "MMUX_VALUEOF_SINT16_MIN" to "$mmux_cv_c_valueof_SINT16_MIN".
#
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_SINT16_MAX" to "$mmux_cv_c_valueof_SINT16_MAX".
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_SINT16_MIN" to "$mmux_cv_c_valueof_SINT16_MIN".
#
AC_DEFUN([MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE],
  [AC_CACHE_CHECK([the range maximum limit of the fixed-width type '$2', $1_MAX],
     [mmux_cv_c_valueof_$1_MAX],
     [AS_VAR_SET([mmux_cv_c_valueof_$1_MAX], $4)])
   AC_CACHE_CHECK([the range minimum limit of the fixed-width type '$2', $1_MIN],
     [mmux_cv_c_valueof_$1_MIN],
     [AS_VAR_SET([mmux_cv_c_valueof_$1_MIN], $3)])

   MMUX_C_DEFINE_MAX_LIMIT_OUPTUT([$1],[$2],["$mmux_cv_c_valueof_$1_MAX"])
   MMUX_C_DEFINE_MIN_LIMIT_OUPTUT([$1],[$2],["$mmux_cv_c_valueof_$1_MIN"])])


# MMUX_C_DETERMINE_LIMITS_OF_LIBC_TYPES
#
# DESCRIPTION
#
#   Determine the range limits of the C language standard types defined by the C library.
#
AC_DEFUN([MMUX_C_DETERMINE_LIMITS_OF_LIBC_TYPES],
  [AC_REQUIRE([MMUX_C_DETERMINE_SIZE_OF_LIBC_TYPES])
   AX_REQUIRE_DEFINED([MMUX_INCLUDE_LIMITS_H])
   AX_REQUIRE_DEFINED([MMUX_INCLUDE_FLOAT_H])

   MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([SINT8],  [int8_t],                   [-128],                  [+127])
   MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([UINT8],  [uint8_t],                     [0],                  [+255])
   MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([SINT16], [int16_t],                [-32768],                [+32767])
   MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([UINT16], [uint16_t],                    [0],                [+65535])
   MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([SINT32], [int32_t],           [-2147483648],           [+2147483647])
   MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([UINT32], [uint32_t],                    [0],           [+4294967295])
   MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([SINT64], [int64_t],  [-9223372036854775808],  [+9223372036854775807])
   MMUX_C_SET_LIMITS_OF_FIXED_WIDTH_TYPE([UINT64], [uint64_t],                    [0], [+18446744073709551615])

   MMUX_C_SIGNED_INT_CONSTANT_TESTS([CHAR_MIN CHAR_MAX SCHAR_MIN SCHAR_MAX UCHAR_MAX],
     [MMUX_INCLUDE_LIMITS_H])

   MMUX_C_SIGNED_INT_CONSTANT_TESTS([SHRT_MIN SHRT_MAX USHRT_MAX INT_MIN INT_MAX],
     [MMUX_INCLUDE_LIMITS_H])

   MMUX_C_UNSIGNED_INT_CONSTANT_TESTS([UINT_MAX],
     [MMUX_INCLUDE_LIMITS_H])

   MMUX_C_SIGNED_LONG_CONSTANT_TESTS([LONG_MIN LONG_MAX],
     [MMUX_INCLUDE_LIMITS_H])

   MMUX_C_UNSIGNED_LONG_CONSTANT_TESTS([ULONG_MAX],
     [MMUX_INCLUDE_LIMITS_H])

   MMUX_C_SIGNED_LONG_LONG_CONSTANT_TESTS([LLONG_MIN LLONG_MAX],
     [MMUX_INCLUDE_LIMITS_H])

   MMUX_C_UNSIGNED_LONG_LONG_CONSTANT_TESTS([ULLONG_MAX],
     [MMUX_INCLUDE_LIMITS_H])

   # These should be defined in the header "float.h" distributed with GCC, for example:
   #
   #   /opt/gcc/10.1.0/lib64/gcc/x86_64-pc-linux-gnu/10.1.0/include/float.h
   #
   # GCC should always find this header file when the GNU Autoconf test requests it.
   MMUX_C_DOUBLE_CONSTANT_TESTS([FLT_MAX FLT_MIN DBL_MAX DBL_MIN],
     [MMUX_INCLUDE_FLOAT_H])

   # These should be defined in the header "float.h" distributed with GCC, for example:
   #
   #   /opt/gcc/10.1.0/lib64/gcc/x86_64-pc-linux-gnu/10.1.0/include/float.h
   #
   # GCC should always find this header file when the GNU Autoconf test requests it.
   MMUX_C_LONG_DOUBLE_CONSTANT_TESTS([LDBL_MAX LDBL_MIN],
     [MMUX_INCLUDE_FLOAT_H])

   MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS(WINT)
   MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS(WCHAR)
   MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS(SINTMAX)
   MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS(SINTPTR)
   MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS(SSIZE)
   MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS(PTRDIFF)
   MMUX_C_DETERMINE_SIGNED_INTEGER_LIMITS(OFF)

   MMUX_C_DETERMINE_UNSIGNED_INTEGER_LIMITS(USIZE)
   MMUX_C_DETERMINE_UNSIGNED_INTEGER_LIMITS(UINTMAX)
   MMUX_C_DETERMINE_UNSIGNED_INTEGER_LIMITS(UINTPTR)
   ])


# MMUX_C_DEFINE_TYPE_ALIAS_OUTPUT(STEM, DESCRIPTION, ALIAS)
#
# DESCRIPTION
#
#   Set the output that defines the fixed-width integer type alias of a target type.
#
# ARGUMENTS
#
#   $1 - The target type stem.
#   $2 - A description text for the target type.
#   $3 - The alias.
#
# USAGE EXAMPLE
#
#   Example, to set the alias of "ptrdiff_t":
#
#     MMUX_C_DEFINE_TYPE_ALIAS_OUTPUT([PTRDIFF],[ptrdiff_t],["$mmux_cv_c_valueof_PTRDIFF_ALIAS"])
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_PTRDIFF_ALIAS" to "$mmux_cv_c_valueof_PTRDIFF_ALIAS".
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_PTRDIFF_ALIAS" to "$mmux_cv_c_valueof_PTRDIFF_ALIAS".
#
AC_DEFUN([MMUX_C_DEFINE_TYPE_ALIAS_OUTPUT],
  [AC_DEFINE_UNQUOTED([MMUX_VALUEOF_$1_ALIAS],[$3],[the range maximum limit of '$2'])
   AC_SUBST([MMUX_VALUEOF_$1_ALIAS],          [$3])])

# MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS(STEM, TYPENAME)
#
# DESCRIPTION
#
#   Determine the standard fixed-width  signed integer type whose size and range match  the one of a
#   given type.
#
# ARGUMENTS
#
#   $1 - The target type stem.
#   $2 - The target type name.
#
# USAGE EXAMPLE
#
#   Example, to determine the alias of "ptrdiff_t":
#
#     MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS([PTRDIFF],[ptrdiff_t])
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_PTRDIFF_ALIAS" to "sint64_t".
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_PTRDIFF_ALIAS" to "sint64_t".
#
AC_DEFUN([MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS],
  [AC_CACHE_CHECK([the value of '$1_ALIAS'],
     [mmux_cv_c_valueof_$1_ALIAS],
     [AS_IF([test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT8"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[int8_t])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT16"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[int16_t])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT32"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[int32_t])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_SINT64"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[int64_t])],

            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[int32_t])])])

   MMUX_C_DEFINE_TYPE_ALIAS_OUTPUT([$1],[$2],["$mmux_cv_c_valueof_$1_ALIAS"])])


# MMUX_C_DETERMINE_UNSIGNED_INTEGER_TYPE_ALIAS(STEM, TYPENAME)
#
# DESCRIPTION
#
#   Determine the standard fixed-width  unsigned integer type whose size and range match  the one of a
#   given type.
#
# ARGUMENTS
#
#   $1 - The target type stem.
#   $2 - The target type name.
#
# USAGE EXAMPLE
#
#   Example, to determine the alias of "uintptr_t":
#
#     MMUX_C_DETERMINE_UNSIGNED_INTEGER_TYPE_ALIAS([UINTPTR],[uintptr_t])
#
#   Define the C language preprocessor macro "MMUX_VALUEOF_UINTPTR_ALIAS" to "uint64_t".
#   Define the GNU Autoconf substitution "MMUX_VALUEOF_UINTPTR_ALIAS" to "uint64_t".
#
AC_DEFUN([MMUX_C_DETERMINE_UNSIGNED_INTEGER_TYPE_ALIAS],
  [AC_CACHE_CHECK([the value of '$1_ALIAS'],
     [mmux_cv_c_valueof_$1_ALIAS],
     [AS_IF([test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_UINT8"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[uint8_t])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_UINT16"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[uint16_t])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_UINT32"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[uint32_t])],

            [test "$mmux_cv_c_sizeof_$1" = "$mmux_cv_c_sizeof_UINT64"],
            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[uint64_t])],

            [AS_VAR_SET([mmux_cv_c_valueof_$1_ALIAS],[uint32_t])])])

   MMUX_C_DEFINE_TYPE_ALIAS_OUTPUT([$1],[$2],["$mmux_cv_c_valueof_$1_ALIAS"])])


# MMUX_C_DETERMINE_ALIASES_OF_LIBC_TYPES
#
# DESCRIPTION
#
#   Determine the standard fixed-width unsigned integer types  whose size and range match the ones of
#   the standard C library types.
#
AC_DEFUN([MMUX_C_DETERMINE_ALIASES_OF_LIBC_TYPES],
  [AC_REQUIRE([MMUX_C_DETERMINE_SIZE_OF_LIBC_TYPES])

   MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS(SINTMAX,          intmax_t)
   MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS(SINTPTR,          intptr_t)
   MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS(PTRDIFF,          ptrdiff_t)
   MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS(SSIZE,            ssize_t)
   MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS(OFF,              off_t)

   MMUX_C_DETERMINE_UNSIGNED_INTEGER_TYPE_ALIAS(UINTMAX,        uintmax_t)
   MMUX_C_DETERMINE_UNSIGNED_INTEGER_TYPE_ALIAS(UINTPTR,        uintptr_t)
   MMUX_C_DETERMINE_UNSIGNED_INTEGER_TYPE_ALIAS(USIZE,          usize_t)

   MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS(WINT,             wint_t)
   MMUX_C_DETERMINE_SIGNED_INTEGER_TYPE_ALIAS(WCHAR,            wchar_t)
   ])


#### done

### end of file
# Local Variables:
# mode: autoconf
# fill-column: 100
# End:
