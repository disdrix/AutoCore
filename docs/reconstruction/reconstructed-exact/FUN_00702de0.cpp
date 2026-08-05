// =============================================================================
// FUN_00702de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00702de0
// Address:   0x00702de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00702de0 @ 0x00702de0
// Stable ID: aa_00702de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00702de0.
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

void FUN_00702de0(int param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 4) < (int)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 8) * 8 + param_2))

  {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 1;

  }

  if (*(int *)(param_1 + 0x14) == 0) {

    iVar1 = (param_2 & 7) + *(int *)(param_1 + 0xc);

    iVar2 = *(int *)(param_1 + 8) + ((int)param_2 >> 3);

    *(int *)(param_1 + 8) = iVar2;

    *(int *)(param_1 + 0xc) = iVar1;

    if (7 < iVar1) {

      *(int *)(param_1 + 0xc) = iVar1 + -8;

      *(int *)(param_1 + 8) = iVar2 + 1;

    }

  }

  return;

}
