/*
 * Copyright(c) 2006 to 2018 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef DDSRT_ATOMICS_GCC_H
#define DDSRT_ATOMICS_GCC_H

#include "dds/ddsrt/misc.h"

#if ( DDSRT_HAVE_ATOMIC64 && __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16) || \
    (!DDSRT_HAVE_ATOMIC64 && __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8)
# define DDSRT_HAVE_ATOMIC_LIFO 1
#endif

/* LD, ST */

inline uint32_t ddsrt_atomic_ld32(const volatile ddsrt_atomic_uint32_t *x) { return x->v; }
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_ld64(const volatile ddsrt_atomic_uint64_t *x) { return x->v; }
#endif
inline uintptr_t ddsrt_atomic_ldptr(const volatile ddsrt_atomic_uintptr_t *x) { return x->v; }
inline void *ddsrt_atomic_ldvoidp(const volatile ddsrt_atomic_voidp_t *x) { return (void *) ddsrt_atomic_ldptr(x); }

inline void ddsrt_atomic_st32(volatile ddsrt_atomic_uint32_t *x, uint32_t v) { x->v = v; }
#if DDSRT_HAVE_ATOMIC64
inline void ddsrt_atomic_st64(volatile ddsrt_atomic_uint64_t *x, uint64_t v) { x->v = v; }
#endif
inline void ddsrt_atomic_stptr(volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) { x->v = v; }
inline void ddsrt_atomic_stvoidp(volatile ddsrt_atomic_voidp_t *x, void *v) { ddsrt_atomic_stptr(x, (uintptr_t)v); }

/* INC */

inline void ddsrt_atomic_inc32(volatile ddsrt_atomic_uint32_t *x) {
  __sync_fetch_and_add (&x->v, 1);
}
#if DDSRT_HAVE_ATOMIC64
inline void ddsrt_atomic_inc64 (volatile ddsrt_atomic_uint64_t *x) {
  __sync_fetch_and_add (&x->v, 1);
}
#endif
inline void ddsrt_atomic_incptr (volatile ddsrt_atomic_uintptr_t *x) {
  __sync_fetch_and_add (&x->v, 1);
}
inline uint32_t ddsrt_atomic_inc32_nv (volatile ddsrt_atomic_uint32_t *x) {
  return __sync_add_and_fetch (&x->v, 1);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_inc64_nv (volatile ddsrt_atomic_uint64_t *x) {
  return __sync_add_and_fetch (&x->v, 1);
}
#endif
inline uintptr_t ddsrt_atomic_incptr_nv (volatile ddsrt_atomic_uintptr_t *x) {
  return __sync_add_and_fetch (&x->v, 1);
}

/* DEC */

inline void ddsrt_atomic_dec32 (volatile ddsrt_atomic_uint32_t *x) {
  __sync_fetch_and_sub (&x->v, 1);
}
#if DDSRT_HAVE_ATOMIC64
inline void ddsrt_atomic_dec64 (volatile ddsrt_atomic_uint64_t *x) {
  __sync_fetch_and_sub (&x->v, 1);
}
#endif
inline void ddsrt_atomic_decptr (volatile ddsrt_atomic_uintptr_t *x) {
  __sync_fetch_and_sub (&x->v, 1);
}
inline uint32_t ddsrt_atomic_dec32_nv (volatile ddsrt_atomic_uint32_t *x) {
  return __sync_sub_and_fetch (&x->v, 1);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_dec64_nv (volatile ddsrt_atomic_uint64_t *x) {
  return __sync_sub_and_fetch (&x->v, 1);
}
#endif
inline uintptr_t ddsrt_atomic_decptr_nv (volatile ddsrt_atomic_uintptr_t *x) {
  return __sync_sub_and_fetch (&x->v, 1);
}
inline uint32_t ddsrt_atomic_dec32_ov (volatile ddsrt_atomic_uint32_t *x) {
  return __sync_fetch_and_sub (&x->v, 1);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_dec64_ov (volatile ddsrt_atomic_uint64_t *x) {
  return __sync_fetch_and_sub (&x->v, 1);
}
#endif
inline uintptr_t ddsrt_atomic_decptr_ov (volatile ddsrt_atomic_uintptr_t *x) {
  return __sync_fetch_and_sub (&x->v, 1);
}

/* ADD */

inline void ddsrt_atomic_add32 (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  __sync_fetch_and_add (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline void ddsrt_atomic_add64 (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  __sync_fetch_and_add (&x->v, v);
}
#endif
inline void ddsrt_atomic_addptr (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  __sync_fetch_and_add (&x->v, v);
}
inline void ddsrt_atomic_addvoidp (volatile ddsrt_atomic_voidp_t *x, ptrdiff_t v) {
  ddsrt_atomic_addptr ((volatile ddsrt_atomic_uintptr_t *) x, (uintptr_t) v);
}
inline uint32_t ddsrt_atomic_add32_nv (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  return __sync_add_and_fetch (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_add64_nv (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  return __sync_add_and_fetch (&x->v, v);
}
#endif
inline uintptr_t ddsrt_atomic_addptr_nv (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  return __sync_add_and_fetch (&x->v, v);
}
inline void *ddsrt_atomic_addvoidp_nv (volatile ddsrt_atomic_voidp_t *x, ptrdiff_t v) {
  return (void *) ddsrt_atomic_addptr_nv ((volatile ddsrt_atomic_uintptr_t *) x, (uintptr_t) v);
}

/* SUB */

inline void ddsrt_atomic_sub32 (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  __sync_fetch_and_sub (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline void ddsrt_atomic_sub64 (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  __sync_fetch_and_sub (&x->v, v);
}
#endif
inline void ddsrt_atomic_subptr (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  __sync_fetch_and_sub (&x->v, v);
}
inline void ddsrt_atomic_subvoidp (volatile ddsrt_atomic_voidp_t *x, ptrdiff_t v) {
  ddsrt_atomic_subptr ((volatile ddsrt_atomic_uintptr_t *) x, (uintptr_t) v);
}
inline uint32_t ddsrt_atomic_sub32_nv (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  return __sync_sub_and_fetch (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_sub64_nv (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  return __sync_sub_and_fetch (&x->v, v);
}
#endif
inline uintptr_t ddsrt_atomic_subptr_nv (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  return __sync_sub_and_fetch (&x->v, v);
}
inline void *ddsrt_atomic_subvoidp_nv (volatile ddsrt_atomic_voidp_t *x, ptrdiff_t v) {
  return (void *) ddsrt_atomic_subptr_nv ((volatile ddsrt_atomic_uintptr_t *) x, (uintptr_t) v);
}

/* AND */

inline void ddsrt_atomic_and32 (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  __sync_fetch_and_and (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline void ddsrt_atomic_and64 (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  __sync_fetch_and_and (&x->v, v);
}
#endif
inline void ddsrt_atomic_andptr (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  __sync_fetch_and_and (&x->v, v);
}
inline uint32_t ddsrt_atomic_and32_ov (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  return __sync_fetch_and_and (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_and64_ov (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  return __sync_fetch_and_and (&x->v, v);
}
#endif
inline uintptr_t ddsrt_atomic_andptr_ov (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  return __sync_fetch_and_and (&x->v, v);
}
inline uint32_t ddsrt_atomic_and32_nv (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  return __sync_and_and_fetch (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_and64_nv (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  return __sync_and_and_fetch (&x->v, v);
}
#endif
inline uintptr_t ddsrt_atomic_andptr_nv (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  return __sync_and_and_fetch (&x->v, v);
}

/* OR */

inline void ddsrt_atomic_or32 (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  __sync_fetch_and_or (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline void ddsrt_atomic_or64 (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  __sync_fetch_and_or (&x->v, v);
}
#endif
inline void ddsrt_atomic_orptr (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  __sync_fetch_and_or (&x->v, v);
}
inline uint32_t ddsrt_atomic_or32_ov (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  return __sync_fetch_and_or (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_or64_ov (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  return __sync_fetch_and_or (&x->v, v);
}
#endif
inline uintptr_t ddsrt_atomic_orptr_ov (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  return __sync_fetch_and_or (&x->v, v);
}
inline uint32_t ddsrt_atomic_or32_nv (volatile ddsrt_atomic_uint32_t *x, uint32_t v) {
  return __sync_or_and_fetch (&x->v, v);
}
#if DDSRT_HAVE_ATOMIC64
inline uint64_t ddsrt_atomic_or64_nv (volatile ddsrt_atomic_uint64_t *x, uint64_t v) {
  return __sync_or_and_fetch (&x->v, v);
}
#endif
inline uintptr_t ddsrt_atomic_orptr_nv (volatile ddsrt_atomic_uintptr_t *x, uintptr_t v) {
  return __sync_or_and_fetch (&x->v, v);
}

/* CAS */

inline int ddsrt_atomic_cas32 (volatile ddsrt_atomic_uint32_t *x, uint32_t exp, uint32_t des) {
  return __sync_bool_compare_and_swap (&x->v, exp, des);
}
#if DDSRT_HAVE_ATOMIC64
inline int ddsrt_atomic_cas64 (volatile ddsrt_atomic_uint64_t *x, uint64_t exp, uint64_t des) {
  return __sync_bool_compare_and_swap (&x->v, exp, des);
}
#endif
inline int ddsrt_atomic_casptr (volatile ddsrt_atomic_uintptr_t *x, uintptr_t exp, uintptr_t des) {
  return __sync_bool_compare_and_swap (&x->v, exp, des);
}
inline int ddsrt_atomic_casvoidp (volatile ddsrt_atomic_voidp_t *x, void *exp, void *des) {
  return ddsrt_atomic_casptr (x, (uintptr_t) exp, (uintptr_t) des);
}
#if DDSRT_HAVE_ATOMIC_LIFO
#if DDSRT_HAVE_ATOMIC64
typedef union { __int128_t x; struct { uintptr_t a, b; } s; } ddsrt_atomic_uintptr2_t;
#else
typedef union { uint64_t x; struct { uintptr_t a, b; } s; } ddsrt_atomic_uintptr2_t;
#endif

typedef struct {
  ddsrt_atomic_uintptr2_t aba_head;
} ddsrt_atomic_lifo_t;

DDS_EXPORT void ddsrt_atomic_lifo_init(ddsrt_atomic_lifo_t *head);
DDS_EXPORT void ddsrt_atomic_lifo_push(ddsrt_atomic_lifo_t *head, void *elem, size_t linkoff);
DDS_EXPORT void *ddsrt_atomic_lifo_pop(ddsrt_atomic_lifo_t *head, size_t linkoff);
DDS_EXPORT void ddsrt_atomic_lifo_pushmany(ddsrt_atomic_lifo_t *head, void *first, void *last, size_t linkoff);

inline int ddsrt_atomic_casvoidp2 (volatile ddsrt_atomic_uintptr2_t *x, uintptr_t a0, uintptr_t b0, uintptr_t a1, uintptr_t b1) {
  ddsrt_atomic_uintptr2_t o, n;
  o.s.a = a0; o.s.b = b0;
  n.s.a = a1; n.s.b = b1;
  return __sync_bool_compare_and_swap (&x->x, o.x, n.x);
}
#endif

/* FENCES */

inline void ddsrt_atomic_fence (void) {
  __sync_synchronize ();
}
inline void ddsrt_atomic_fence_ldld (void) {
#if !(defined __i386__ || defined __x86_64__ || defined _M_IX86 || defined _M_X64)
  __sync_synchronize ();
#endif
}
inline void ddsrt_atomic_fence_acq (void) {
  ddsrt_atomic_fence ();
}
inline void ddsrt_atomic_fence_rel (void) {
  ddsrt_atomic_fence ();
}

#endif /* DDSRT_ATOMICS_GCC_H */
