// =============================================================================
// FUN_007874b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007874b0
// Address:   0x007874b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007874b0 @ 0x007874b0
// Stable ID: aa_007874b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007874b0.
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

bool __thiscall FUN_007874b0(int *param_1,int param_2,int param_3)



{

  void *pvVar1;

  uint uVar2;

  

  uVar2 = param_2 * param_3;

  if (uVar2 - param_1[1] * *param_1 != 0) {

    operator_delete__((void *)param_1[2]);

    param_1[2] = 0;

    if (0 < (int)uVar2) {

      pvVar1 = operator_new__(uVar2);

      param_1[2] = (int)pvVar1;

    }

  }

  *param_1 = param_2;

  param_1[1] = param_3;

  return param_1[2] != 0;

}
