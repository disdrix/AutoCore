// =============================================================================
// FUN_0044fee0  (clean twin of NestedHash0x10_StaticOnceGet_d1fcc0_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044fee0
// Address:   0x0044fee0  (autoassault.exe, image base 0x400000)
// System:    NestedHash static once-get
// Generated: 2026-07-29 W35-E dual seal (scaffold rewritten)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - Once-flag DAT_00d1fce8 bit0; ctor FUN_00457ac0; atexit LAB_009c34b0.
 * - Returns &DAT_00d1fcc0 always.
 * - Reject scaffold anmTrackEvents name.
 */

void *FUN_0044fee0(void)
{
  extern unsigned int DAT_00d1fce8;
  extern unsigned char DAT_00d1fcc0[];
  extern void FUN_00457ac0(void *self /* stack */);
  extern void LAB_009c34b0(void);
  extern int __cdecl atexit(void (*func)(void));

  if ((DAT_00d1fce8 & 1u) == 0) {
    DAT_00d1fce8 |= 1u;
    FUN_00457ac0(&DAT_00d1fcc0);
    atexit(LAB_009c34b0);
  }
  return &DAT_00d1fcc0;
}
