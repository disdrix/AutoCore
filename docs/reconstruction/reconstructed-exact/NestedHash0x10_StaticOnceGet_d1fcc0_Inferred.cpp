// =============================================================================
// NestedHash0x10_StaticOnceGet_d1fcc0_Inferred
// -----------------------------------------------------------------------------
// Purpose:  One-shot initialize the static NestedHash (sentinel node 0x10) at
//           DAT_00d1fcc0 via NestedHash_Ctor_Sentinel0x10_Inferred, register
//           atexit(LAB_009c34b0), return &DAT_00d1fcc0.
//
// Address:  0x0044fee0  (autoassault.exe, image base 0x400000)
// Body:     0x0044fee0–0x0044ff39 (90 B / 0x5A)
// Stable:   aa_0044fee0
// System:   NestedHash static once-get
// Ghidra:   FUN_0044fee0
//
// Caller:   FUN_0044fe10 @ 0x0044fe1f, 0x0044fe33 (uses +8 sentinel)
// Family:   twin once-gets FUN_00438c40 / FUN_00438ca0 (other statics)
//
// Exactness: CF mirrors raw + read_memory; names structural _Inferred.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W35-E seal).
// =============================================================================

/* NestedHash0x10_StaticOnceGet_d1fcc0_Inferred

   Parameters: none.

   Side effects (first call only):
     - set once-flag bit 0 at 0x00d1fce8
     - NestedHash_Ctor_Sentinel0x10_Inferred(&DAT_00d1fcc0)
     - atexit(LAB_009c34b0)

   Returns: address of static NestedHash shell (&DAT_00d1fcc0). */

extern unsigned int g_nestedHash0x10_once_d1fce8; /* @ 0x00d1fce8 */
/* NestedHash shell span 0x28 at 0x00d1fcc0 — see NestedHash_Ctor_Sentinel0x10 */
extern unsigned char g_nestedHash0x10_static_d1fcc0[0x28];
extern void NestedHash_Ctor_Sentinel0x10_Inferred(void *self /* stack */);
extern void LAB_009c34b0(void);
extern int __cdecl atexit(void (*func)(void));

void *NestedHash0x10_StaticOnceGet_d1fcc0_Inferred(void)
{
  if ((g_nestedHash0x10_once_d1fce8 & 1u) == 0) {
    g_nestedHash0x10_once_d1fce8 |= 1u;
    NestedHash_Ctor_Sentinel0x10_Inferred(&g_nestedHash0x10_static_d1fcc0);
    atexit(LAB_009c34b0);
  }
  return &g_nestedHash0x10_static_d1fcc0;
}
