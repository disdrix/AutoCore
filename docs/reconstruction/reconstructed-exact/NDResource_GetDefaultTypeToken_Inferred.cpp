// =============================================================================
// NDResource_GetDefaultTypeToken_Inferred
// -----------------------------------------------------------------------------
// Purpose:  One-shot init of the default ND resource type-token singleton at
//           DAT_00d1f734 (vptr PTR_FUN_00a95ae8), register atexit teardown
//           LAB_009c3070, return &DAT_00d1f734 for NDResourceCache_LookupOrCreate.
//
// Address:  0x00423b10  (autoassault.exe, image base 0x400000)
// Body:     0x00423b10–0x00423b3f
// Stable:   aa_00423b10
// System:   ND resource cache / type token
//
// Sole caller: NDResource_LoadByKey (0x00423ac0) — type arg between key and
// remaining formals.
//
// Exactness: CF mirrors raw + read_memory; names cleaned / product-inferred.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W18-D seal).
// =============================================================================

/* NDResource_GetDefaultTypeToken_Inferred

   Parameters: none.

   Side effects (first call only):
     - set once-flag bit 0 at 0x00d1f738
     - store vtable 0x00a95ae8 into object at 0x00d1f734
     - atexit(LAB_009c3070)

   Returns: void* address of type-token object (&DAT_00d1f734). */

extern unsigned int g_ndResourceTypeOnceFlags_d1f738; /* @ 0x00d1f738 */
extern void *g_ndResourceTypeToken_d1f734;            /* @ 0x00d1f734 */
extern void *PTR_FUN_00a95ae8;                        /* vtable @ 0x00a95ae8 */
extern void LAB_009c3070(void);
extern int __cdecl atexit(void (*func)(void));

void *NDResource_GetDefaultTypeToken_Inferred(void)
{
  if ((g_ndResourceTypeOnceFlags_d1f738 & 1u) == 0) {
    g_ndResourceTypeOnceFlags_d1f738 |= 1u;
    g_ndResourceTypeToken_d1f734 = &PTR_FUN_00a95ae8;
    atexit(LAB_009c3070);
  }
  return &g_ndResourceTypeToken_d1f734;
}
