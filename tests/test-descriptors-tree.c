/*
  Part of: CCLanguage
  Contents: tests for descriptors hierarchy as a tree
  Date: Jul 11, 2020

  Abstract



  Copyright (C) 2020 Marco Maggi <mrc.mgg@gmail.com>

  The author  hereby grant permission to  use, copy, modify, distribute,  and license
  this  software  and its  documentation  for  any  purpose, provided  that  existing
  copyright  notices are  retained in  all copies  and that  this notice  is included
  verbatim in  any distributions. No  written agreement,  license, or royalty  fee is
  required for  any of the  authorized uses.  Modifications  to this software  may be
  copyrighted by  their authors  and need  not follow  the licensing  terms described
  here, provided that the  new terms are clearly indicated on the  first page of each
  file where they apply.

  IN NO  EVENT SHALL THE AUTHOR  OR DISTRIBUTORS BE  LIABLE TO ANY PARTY  FOR DIRECT,
  INDIRECT, SPECIAL, INCIDENTAL,  OR CONSEQUENTIAL DAMAGES ARISING OUT OF  THE USE OF
  THIS SOFTWARE,  ITS DOCUMENTATION, OR ANY  DERIVATIVES THEREOF, EVEN IF  THE AUTHOR
  HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  THE AUTHOR  AND DISTRIBUTORS SPECIFICALLY  DISCLAIM ANY WARRANTIES,  INCLUDING, BUT
  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
  PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS  PROVIDED ON AN "AS IS" BASIS, AND
  THE AUTHOR  AND DISTRIBUTORS  HAVE NO OBLIGATION  TO PROVIDE  MAINTENANCE, SUPPORT,
  UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include <cclanguage.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


/** --------------------------------------------------------------------
 ** Descriptors.
 ** ----------------------------------------------------------------- */

#define cclib_descriptor_type_1(STRUCT)			STRUCT ## __cclib_descriptor_type
#define cclib_descriptor_type_2(STRUCT, VAR)		STRUCT ## __cclib_descriptor_type__ ## VAR
#define cclib_descriptor_type_3(STRUCT, VAR1, VAR2)	STRUCT ## __cclib_descriptor_type__ ## VAR1 ## _ ## VAR2
#define cclib_descriptor_type_4(STRUCT, VAR1, VAR2, VAR3) STRUCT ## __cclib_descriptor_type__ ## VAR1 ## _ ## VAR2 ## __ ## VAR3
#define cclib_descriptor_type(...)			CCLIB_VNAME(cclib_descriptor_type, __VA_ARGS__)
#define cclib_descriptor_t(...)				CCLIB_VNAME(cclib_descriptor_type, __VA_ARGS__)

#define cclib_descriptor_1(STRUCT)			STRUCT ## __cclib_descriptor
#define cclib_descriptor_2(STRUCT, VAR)			STRUCT ## __cclib_descriptor__ ## VAR
#define cclib_descriptor_3(STRUCT, VAR1, VAR2)		STRUCT ## __cclib_descriptor__ ## VAR1 ## _ ## VAR2
#define cclib_descriptor_4(STRUCT, VAR1, VAR2, VAR3)	STRUCT ## __cclib_descriptor__ ## VAR1 ## _ ## VAR2 ## __ ## VAR3
#define cclib_descriptor(...)				CCLIB_VNAME(cclib_descriptor, __VA_ARGS__)

cclib_struct_typedef(cclib_descriptor_t(my_things));

struct cclib_descriptor_t(my_things) {
  cclib_descriptor_t(my_things) const *parent;
  char const	*name;
};

typedef cclib_descriptor_t(my_things) const * cclib_method_t(my_things, descriptor) (cclib_resource_data_t const * self);


/** --------------------------------------------------------------------
 ** Alpha struct type definitions and methods.
 ** ----------------------------------------------------------------- */

cclib_define_struct_with_descriptor(my_alpha_t);

struct my_alpha_t {
  cclib_struct_descriptor(my_alpha_t);
  int	a;
};

typedef int cclib_method_t(my_alpha_t, get_a) (cclib_resource_data_t const * self);

#define my_alpha_t__methods_table_fields			\
  cclib_method_t(my_things, descriptor)		*descriptor;	\
  cclib_method_t(my_alpha_t, get_a)		*get_a

struct cclib_methods_table_t(my_alpha_t) {
  my_alpha_t__methods_table_fields;
};

/* ------------------------------------------------------------------ */

static cclib_method_t(my_things, descriptor)	cclib_method(my_alpha_t, descriptor);
static cclib_method_t(my_alpha_t, get_a)	cclib_method(my_alpha_t, get_a);

static cclib_methods_table_t(my_alpha_t) cclib_methods_table(my_alpha_t) = {
  .descriptor	= cclib_method(my_alpha_t, descriptor),
  .get_a	= cclib_method(my_alpha_t, get_a),
};

cclib_methods_table_t(my_alpha_t) const * const cclib_methods_table_ptr(my_alpha_t) = &cclib_methods_table(my_alpha_t);

static cclib_descriptor_t(my_things) const cclib_descriptor(my_alpha_t) = {
  .parent	= NULL,
  .name		= "my_alpha_t"
};

cclib_descriptor_t(my_things) const *
cclib_method(my_alpha_t, descriptor) (cclib_resource_data_t const * self CCLIB_UNUSED)
{
  return &(cclib_descriptor(my_alpha_t));
}

int
cclib_method(my_alpha_t, get_a) (cclib_resource_data_t const * _self)
{
  CCLIB_PC(my_alpha_t const, self, _self);
  return self->a;
}

/* ------------------------------------------------------------------ */

cclib_decl void cclib_init(my_alpha_t) (my_alpha_t * S, int a)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl my_alpha_t const * cclib_new(my_alpha_t) (int a)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

cclib_decl void cclib_final(my_alpha_t) (my_alpha_t const * self)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl void cclib_delete(my_alpha_t) (my_alpha_t const * self)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

void
cclib_init(my_alpha_t) (my_alpha_t * self, int a)
{
  cclib_struct_descriptor_set_methods_table_pointer(self, cclib_methods_table_ptr(my_alpha_t));
  self->a	= a;
}

void
cclib_final(my_alpha_t) (my_alpha_t const * self CCLIB_UNUSED)
{
  if (1) { fprintf(stderr, "%-35s: finalised\n", __func__); }
}

static my_alpha_t *
cclib_alloc(my_alpha_t) (void)
{
  /* We ignore "malloc()" errors in thi simple test program. */
  return (my_alpha_t *)malloc(sizeof(my_alpha_t));
}

static void
cclib_release(my_alpha_t) (my_alpha_t const * self)
{
  if (1) { fprintf(stderr, "%-35s: enter release function\n", __func__); }
  free((void *)self);
  if (1) { fprintf(stderr, "%-35s: released\n", __func__); }
}

my_alpha_t const *
cclib_new(my_alpha_t) (int a)
{
  my_alpha_t *	self = cclib_alloc(my_alpha_t)();

  cclib_init(my_alpha_t)(self, a);
  return (my_alpha_t const *) self;
}

void
cclib_delete(my_alpha_t) (my_alpha_t const * self)
{
  if (1) { fprintf(stderr, "%-35s: enter delete destructor\n", __func__); }
  cclib_final(my_alpha_t)(self);
  cclib_release(my_alpha_t)(self);
  if (1) { fprintf(stderr, "%-35s: deleted\n", __func__); }
}


/** --------------------------------------------------------------------
 ** Beta struct type definitions and methods.
 ** ----------------------------------------------------------------- */

cclib_define_struct_with_descriptor(my_beta_t);

struct my_beta_t {
  my_alpha_t	alpha;
  cclib_struct_descriptor(my_beta_t);
  int		b;
};

typedef int cclib_method_t(my_beta_t, get_b) (cclib_resource_data_t const * self);

#define my_beta_t__methods_table_fields			    \
  my_alpha_t__methods_table_fields;			    \
  cclib_method_t(my_beta_t, get_b)	*get_b

struct cclib_methods_table_t(my_beta_t) {
  my_beta_t__methods_table_fields;
};

/* ------------------------------------------------------------------ */

static cclib_method_t(my_things, descriptor)	cclib_method(my_beta_t, descriptor);
static cclib_method_t(my_beta_t, get_b)		cclib_method(my_beta_t, get_b);

static cclib_methods_table_t(my_beta_t) cclib_methods_table(my_beta_t) = {
  .get_b	= cclib_method(my_beta_t, get_b),
};

cclib_methods_table_t(my_beta_t) const * const cclib_methods_table_ptr(my_beta_t) = &cclib_methods_table(my_beta_t);

static cclib_descriptor_t(my_things) const cclib_descriptor(my_beta_t) = {
  .parent	= &cclib_descriptor(my_alpha_t),
  .name		= "my_beta_t"
};

cclib_descriptor_t(my_things) const *
cclib_method(my_beta_t, descriptor) (cclib_resource_data_t const * self CCLIB_UNUSED)
{
  return &(cclib_descriptor(my_beta_t));
}

int
cclib_method(my_beta_t, get_b) (cclib_resource_data_t const * _self)
{
  CCLIB_PC(my_beta_t const, self, _self);
  return self->b;
}

/* ------------------------------------------------------------------ */

cclib_decl void cclib_init(my_beta_t) (my_beta_t * S, int a, int b)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl my_beta_t const * cclib_new(my_beta_t) (int a, int b)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

cclib_decl void cclib_final(my_beta_t) (my_beta_t const * self)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl void cclib_delete(my_beta_t) (my_beta_t const * self)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

void
cclib_init(my_beta_t) (my_beta_t * self, int a, int b)
{
  cclib_init(my_alpha_t)(&(self->alpha), a);
  cclib_struct_descriptor_set_methods_table_pointer(self, cclib_methods_table_ptr(my_beta_t));
  self->b	= b;
}

void
cclib_final(my_beta_t) (my_beta_t const * self CCLIB_UNUSED)
{
  cclib_final(my_alpha_t)(&(self->alpha));
  if (1) { fprintf(stderr, "%-35s: finalised\n", __func__); }
}

static my_beta_t *
cclib_alloc(my_beta_t) (void)
{
  /* We ignore "malloc()" errors in thi simple test program. */
  return (my_beta_t *)malloc(sizeof(my_beta_t));
}

static void
cclib_release(my_beta_t) (my_beta_t const * self)
{
  if (1) { fprintf(stderr, "%-35s: enter release function\n", __func__); }
  free((void *)self);
  if (1) { fprintf(stderr, "%-35s: released\n", __func__); }
}

my_beta_t const *
cclib_new(my_beta_t) (int a, int b)
{
  my_beta_t *	self = cclib_alloc(my_beta_t)();

  cclib_init(my_beta_t)(self, a, b);
  return (my_beta_t const *) self;
}

void
cclib_delete(my_beta_t) (my_beta_t const * self)
{
  if (1) { fprintf(stderr, "%-35s: enter delete destructor\n", __func__); }
  cclib_final(my_beta_t)(self);
  cclib_release(my_beta_t)(self);
  if (1) { fprintf(stderr, "%-35s: deleted\n", __func__); }
}


/** --------------------------------------------------------------------
 ** Gamma struct type definitions and methods.
 ** ----------------------------------------------------------------- */

cclib_define_struct_with_descriptor(my_gamma_t);

struct my_gamma_t {
  my_beta_t	beta;
  cclib_struct_descriptor(my_gamma_t);
  int		c;
};

typedef int cclib_method_t(my_gamma_t, get_c) (cclib_resource_data_t const * self);

#define my_gamma_t__methods_table_fields		    \
  my_beta_t__methods_table_fields;			    \
  cclib_method_t(my_gamma_t, get_c)	*get_c

struct cclib_methods_table_t(my_gamma_t) {
  my_gamma_t__methods_table_fields;
};

/* ------------------------------------------------------------------ */

static cclib_method_t(my_things, descriptor)	cclib_method(my_gamma_t, descriptor);
static cclib_method_t(my_gamma_t, get_c)	cclib_method(my_gamma_t, get_c);

static cclib_methods_table_t(my_gamma_t) cclib_methods_table(my_gamma_t) = {
  .get_c	= cclib_method(my_gamma_t, get_c),
};

cclib_methods_table_t(my_gamma_t) const * const cclib_methods_table_ptr(my_gamma_t) = &cclib_methods_table(my_gamma_t);

static cclib_descriptor_t(my_things) const cclib_descriptor(my_gamma_t) = {
  .parent	= &cclib_descriptor(my_beta_t),
  .name		= "my_gamma_t"
};

cclib_descriptor_t(my_things) const *
cclib_method(my_gamma_t, descriptor) (cclib_resource_data_t const * self CCLIB_UNUSED)
{
  return &(cclib_descriptor(my_gamma_t));
}

int
cclib_method(my_gamma_t, get_c) (cclib_resource_data_t const * _self)
{
  CCLIB_PC(my_gamma_t const, self, _self);
  return self->c;
}

/* ------------------------------------------------------------------ */

cclib_decl void cclib_init(my_gamma_t) (my_gamma_t * S, int a, int b, int c)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl my_gamma_t const * cclib_new(my_gamma_t) (int a, int b, int c)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

cclib_decl void cclib_final(my_gamma_t) (my_gamma_t const * self)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl void cclib_delete(my_gamma_t) (my_gamma_t const * self)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

void
cclib_init(my_gamma_t) (my_gamma_t * self, int a, int b, int c)
{
  cclib_init(my_beta_t)(&(self->beta), a, b);
  cclib_struct_descriptor_set_methods_table_pointer(self, cclib_methods_table_ptr(my_gamma_t));
  self->c	= c;
}

void
cclib_final(my_gamma_t) (my_gamma_t const * self CCLIB_UNUSED)
{
  cclib_final(my_beta_t)(&(self->beta));
  if (1) { fprintf(stderr, "%-35s: finalised\n", __func__); }
}

static my_gamma_t *
cclib_alloc(my_gamma_t) (void)
{
  /* We ignore "malloc()" errors in thi simple test program. */
  return (my_gamma_t *)malloc(sizeof(my_gamma_t));
}

static void
cclib_release(my_gamma_t) (my_gamma_t const * self)
{
  if (1) { fprintf(stderr, "%-35s: enter release function\n", __func__); }
  free((void *)self);
  if (1) { fprintf(stderr, "%-35s: released\n", __func__); }
}

my_gamma_t const *
cclib_new(my_gamma_t) (int a, int b, int c)
{
  my_gamma_t *	self = cclib_alloc(my_gamma_t)();

  cclib_init(my_gamma_t)(self, a, b, c);
  return (my_gamma_t const *) self;
}

void
cclib_delete(my_gamma_t) (my_gamma_t const * self)
{
  if (1) { fprintf(stderr, "%-35s: enter delete destructor\n", __func__); }
  cclib_final(my_gamma_t)(self);
  cclib_release(my_gamma_t)(self);
  if (1) { fprintf(stderr, "%-35s: deleted\n", __func__); }
}


/** --------------------------------------------------------------------
 ** Tests for alpha.
 ** ----------------------------------------------------------------- */

static void
tests_my_alpha_t_stack_allocation (void)
{
  my_alpha_t	S[1];
  int const	a_val = 123;

  cclib_init(my_alpha_t)(S, a_val);
  {
    cclib_descriptor_t(my_things) const	* const D = cclib_call(descriptor, S);

    assert(a_val == cclib_call(get_a, S));
    assert(0    == strcmp("my_alpha_t", D->name));
    assert(NULL == D->parent);
  }
  cclib_final(my_alpha_t)(S);
}

void
tests_my_alpha_t_dynamic_allocation (void)
{
  my_alpha_t const *S;
  int const	a_val = 123;

  S = cclib_new(my_alpha_t)(a_val);
  {
    cclib_descriptor_t(my_things) const	* const D = cclib_call(descriptor, S);

    assert(a_val == cclib_call(get_a, S));
    assert(0 == strcmp("my_alpha_t", D->name));
    assert(NULL == D->parent);
  }
  cclib_delete(my_alpha_t)(S);
}


/** --------------------------------------------------------------------
 ** Tests for beta.
 ** ----------------------------------------------------------------- */

static void
tests_my_beta_t_stack_allocation (void)
{
  my_beta_t	S[1];
  int const	a_val = 123;
  int const	b_val = 456;

  cclib_init(my_beta_t)(S, a_val, b_val);
  {
    cclib_descriptor_t(my_things) const	* const D = cclib_call(descriptor, S);

    assert(a_val == cclib_call(get_a, S));
    assert(b_val == cclib_call(get_b, S));
    assert(0 == strcmp("my_beta_t", D->name));
    assert(&cclib_descriptor(my_alpha_t) == D->parent);
  }
  cclib_final(my_beta_t)(S);
}

void
tests_my_beta_t_dynamic_allocation (void)
{
  my_beta_t const *S;
  int const	a_val = 123;
  int const	b_val = 456;

  S = cclib_new(my_beta_t)(a_val, b_val);
  {
    cclib_descriptor_t(my_things) const	* const D = cclib_call(descriptor, S);

    assert(a_val == cclib_call(get_a, S));
    assert(b_val == cclib_call(get_b, S));
    assert(0 == strcmp("my_beta_t", D->name));
    assert(&cclib_descriptor(my_alpha_t) == D->parent);
  }
  cclib_delete(my_beta_t)(S);
}


/** --------------------------------------------------------------------
 ** Tests for gamma.
 ** ----------------------------------------------------------------- */

static void
tests_my_gamma_t_stack_allocation (void)
{
  my_gamma_t	S[1];
  int const	a_val = 123;
  int const	b_val = 456;
  int const	c_val = 789;

  cclib_init(my_gamma_t)(S, a_val, b_val, c_val);
  {
    cclib_descriptor_t(my_things) const	* const D = cclib_call(descriptor, S);

    assert(a_val == cclib_call(get_a, S));
    assert(b_val == cclib_call(get_b, S));
    assert(c_val == cclib_call(get_c, S));
    assert(0 == strcmp("my_gamma_t", cclib_call(descriptor, S)->name));
    assert(&cclib_descriptor(my_beta_t) == D->parent);
  }
  cclib_final(my_gamma_t)(S);
}

void
tests_my_gamma_t_dynamic_allocation (void)
{
  my_gamma_t const *S;
  int const	a_val = 123;
  int const	b_val = 456;
  int const	c_val = 789;

  S = cclib_new(my_gamma_t)(a_val, b_val, c_val);
  {
    cclib_descriptor_t(my_things) const	* const D = cclib_call(descriptor, S);

    assert(a_val == cclib_call(get_a, S));
    assert(b_val == cclib_call(get_b, S));
    assert(c_val == cclib_call(get_c, S));
    assert(0 == strcmp("my_gamma_t", cclib_call(descriptor, S)->name));
    assert(&cclib_descriptor(my_beta_t) == D->parent);
  }
  cclib_delete(my_gamma_t)(S);
}


/** --------------------------------------------------------------------
 ** Let's go.
 ** ----------------------------------------------------------------- */

static void
initialise_methods_tables (void)
{
  /* Copy the methods from "my_alpha_t"'s table into "my_beta_t"'s table. */
  {
    CCLIB_PC(cclib_methods_table_type(my_alpha_t), T, cclib_methods_table_ptr(my_beta_t));
    *T = cclib_methods_table(my_alpha_t);
  }

  /* Copy the methods from "my_gamma_t"'s table into "my_beta_t"'s table. */
  {
    CCLIB_PC(cclib_methods_table_type(my_beta_t), T, cclib_methods_table_ptr(my_gamma_t));
    *T = cclib_methods_table(my_beta_t);
  }

  /* Override methods for "my_beta_t". */
  {
    cclib_methods_table(my_beta_t).descriptor	= cclib_method(my_beta_t, descriptor);
  }

  /* Override methods for "my_gamma_t". */
  {
    cclib_methods_table(my_gamma_t).descriptor	= cclib_method(my_gamma_t, descriptor);
  }
}

int
main (void)
{
  initialise_methods_tables();

  tests_my_alpha_t_stack_allocation();
  tests_my_alpha_t_dynamic_allocation();

  tests_my_beta_t_stack_allocation();
  tests_my_beta_t_dynamic_allocation();

  tests_my_gamma_t_stack_allocation();
  tests_my_gamma_t_dynamic_allocation();

  exit(EXIT_SUCCESS);
}

/* end of file */
