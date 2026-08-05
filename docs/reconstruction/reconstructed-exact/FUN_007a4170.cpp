// =============================================================================
// FUN_007a4170
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4170
// Address:   0x007a4170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a4170 @ 0x007a4170
// Stable ID: aa_007a4170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007a4170.
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

float10 __thiscall FUN_007a4170(int param_1,uint param_2)



{

  ushort uVar1;

  

  if ((int)param_2 < 0) {

    if (0xfffff < *(int *)(param_1 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 2);

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

    return (float10)uVar1 * (float10)DAT_00aaa638;

  }

  param_2 = param_2 & 0x800fffff;

  if ((int)param_2 < 0) {

    param_2 = (param_2 - 1 | 0xfff00000) + 1;

  }

  return (float10)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * (float10)DAT_00aaa638;

}
