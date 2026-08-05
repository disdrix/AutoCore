// =============================================================================
// FUN_0048b370
// -----------------------------------------------------------------------------
// Stable ID: aa_0048b370
// Address:   0x0048b370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048b370 @ 0x0048b370
// Stable ID: aa_0048b370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0048aa20, FUN_0048ad40, FUN_0048b370.
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

void FUN_0048b370(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a0578;

  local_c = ExceptionList;

  local_10 = &DAT_00b03504;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0048ad40(param_1,&local_10);

  FUN_0048aa20(local_10 + 2,*local_10);

  local_4 = 0xffffffff;

  if (local_10 != &DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_10);

  }

  ExceptionList = local_c;

  return;

}
