// =============================================================================
// FUN_00404510  (scaffold alias → UiToast_UninitializedCopy_0x98)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404510
// Address:   0x00404510  (autoassault.exe, image base 0x400000)
// Body:      0x00404510–0x0040452f (32 bytes)
// System:    missions-progression / UI toast vector helpers
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W22-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical clean: UiToast_UninitializedCopy_0x98.cpp
// =============================================================================

// PURPOSE: Trampoline to FUN_004047a0 toast range copy (stride 0x98).
// READABILITY: decompiler thiscall/5-arg print is artifactual; bytes ret 0x0C.

#include <stdint.h>

extern void *FUN_004047a0(void *srcBegin, void *srcEnd, void *dst);

/* Decompiler signature kept for scaffold parity; real ABI is 3 stack args. */
void FUN_00404510(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
  (void)param_1;
  FUN_004047a0((void *)param_2, (void *)param_3, (void *)param_4);
  return;
}
