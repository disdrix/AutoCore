// =============================================================================
// FUN_0048c010
// -----------------------------------------------------------------------------
// Stable ID: aa_0048c010
// Address:   0x0048c010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048c010 @ 0x0048c010
// Stable ID: aa_0048c010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0048c010.
//  - Return sites: 3.

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

void __fastcall FUN_0048c010(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  puStack_8 = &LAB_009a0523;

  pvStack_c = ExceptionList;

  uStack_4 = 1;

  if ((uint32_t /* width from decompiler */ *)param_1[6] != &DAT_00b03504) {

    ExceptionList = &pvStack_c;

                    /* WARNING: Subroutine does not return */

    operator_delete((uint32_t /* width from decompiler */ *)param_1[6]);

  }

  uStack_4 = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[5] != &DAT_00b03504) {

    ExceptionList = &pvStack_c;

                    /* WARNING: Subroutine does not return */

    operator_delete((uint32_t /* width from decompiler */ *)param_1[5]);

  }

  *param_1 = &PTR_LAB_009c6d9c;

  return;

}
