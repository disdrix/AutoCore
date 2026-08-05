// =============================================================================
// FUN_00423b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00423b10
// Address:   0x00423b10  (autoassault.exe, image base 0x400000)
// System:    ND resource cache / type token
// Generated: 2026-07-23 scaffold; W18-D 2026-07-29 dual seal refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: NDResource_GetDefaultTypeToken_Inferred.cpp
// =============================================================================

// PURPOSE: One-shot init of type-token singleton DAT_00d1f734; return its address.

/*
 * Behavioral notes:
 * - Once flag bit 0 at _DAT_00d1f738.
 * - Vtable PTR_FUN_00a95ae8 written to DAT_00d1f734.
 * - atexit(LAB_009c3070); return &DAT_00d1f734.
 */

void *FUN_00423b10(void)
{
  if ((_DAT_00d1f738 & 1) == 0) {
    _DAT_00d1f738 = _DAT_00d1f738 | 1;
    _DAT_00d1f734 = &PTR_FUN_00a95ae8;
    _atexit((_func_4879 *)&LAB_009c3070);
  }
  return &DAT_00d1f734;
}
