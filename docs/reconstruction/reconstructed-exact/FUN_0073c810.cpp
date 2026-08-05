// =============================================================================
// FUN_0073c810  (clean twin of HostPtrTable12_Bootstrap_EDI_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0073c810
// Address:   0x0073c810  (autoassault.exe, image base 0x400000)
// Body:      0x0073c810–0x0073cb6d (862 B)
// System:    host pointer-table bootstrap
// Generated: 2026-07-29 W35-E dual seal (scaffold rewritten)
// Exactness: Behavior-preserving; EDI register formal; returns 0.
// Named twin: HostPtrTable12_Bootstrap_EDI_Inferred.cpp
// =============================================================================

/*
 * EDI = void** table of 12 host pointers (+0x00..+0x2C).
 * See named twin for full slot map and helper factoring.
 * Ghidra unaff_EDI is the intentional register formal.
 */

#include <stdint.h>

extern void *operator_new(unsigned size);
extern uint32_t *FUN_00748960(uint32_t *self);
extern uint32_t *FUN_00457720(uint32_t *self);
extern uint32_t FUN_00457ac0(void *self);
extern uint32_t FUN_00457b30(void *self);
extern uint32_t FUN_00764030(void);
extern void FUN_0099e6c0(void);
extern void FUN_0099e4a0(void);
extern void FUN_0099e2c0(void);
extern void FUN_0099e0a0(void);
extern void FUN_0099d060(void *obj);
extern void FUN_00731130(void *obj);
extern void FUN_007300c0(void *obj);
extern void FUN_0099eb60(void *obj);
extern void FUN_0099f450(void *obj, uint32_t f32_bits);
extern void FUN_0098fd80(void *obj);
extern void FUN_0098df00(void);
extern void FUN_007647c0(void *slot8);

extern void *PTR_FUN_00aa37b4, *PTR_LAB_00aa37a8;
extern void *PTR_FUN_00aa3714, *PTR_LAB_00aa3708;
extern void *PTR_FUN_00aa3674, *PTR_LAB_00aa3668;
extern void *PTR_FUN_00aa35d4, *PTR_LAB_00aa35c8;
extern void *PTR_FUN_00aa3534, *PTR_LAB_00aa3528;
extern void *PTR_FUN_00aa3494, *PTR_LAB_00aa3484;
extern void *PTR_FUN_00aa33fc, *PTR_LAB_00aa33ec;
extern void *PTR_FUN_00aa33c8, *PTR_FUN_00a9db18, *PTR_FUN_00a9da80;

/* Prefer HostPtrTable12_Bootstrap_EDI_Inferred.cpp for readable port. */
uint32_t FUN_0073c810(void **unaff_EDI)
{
  /* Full CF: see HostPtrTable12_Bootstrap_EDI_Inferred.cpp — identical slot ladder. */
  extern uint32_t HostPtrTable12_Bootstrap_EDI_Inferred(void **table);
  return HostPtrTable12_Bootstrap_EDI_Inferred(unaff_EDI);
}
