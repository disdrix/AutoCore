// =============================================================================
// FUN_0052ae30
// -----------------------------------------------------------------------------
// Stable ID: aa_0052ae30
// Address:   0x0052ae30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052ae30 @ 0x0052ae30
// Stable ID: aa_0052ae30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00418b80, FUN_0052ae30.
//  - Return sites: 1.

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

void __thiscall FUN_0052ae30(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int local_4;

  

  local_4 = param_1;

  FUN_00418b80(&local_4,&param_2);

  if (local_4 != *(int *)(param_1 + 0x588)) {

    *(int *)(local_4 + 0x10) = *(int *)(local_4 + 0x10) + param_3;

    if (*(int *)(local_4 + 0x14) < *(int *)(local_4 + 0x10)) {

      *(int *)(local_4 + 0x10) = *(int *)(local_4 + 0x14);

    }

    *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;

  }

  return;

}
