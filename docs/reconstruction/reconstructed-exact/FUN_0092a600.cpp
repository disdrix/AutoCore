// =============================================================================
// FUN_0092a600
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a600
// Address:   0x0092a600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092a600 @ 0x0092a600
// Stable ID: aa_0092a600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0092a3d0, FUN_0092a600.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_0092a600(int param_1)



{

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &DAT_009ac63b;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0092a3d0();

  local_4 = 0xffffffff;

  if (*(void **)(param_1 + 0x11c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x11c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x120) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = 0;

  ExceptionList = local_c;

  return;

}
