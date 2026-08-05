// =============================================================================
// FUN_007716f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007716f0
// Address:   0x007716f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007716f0 @ 0x007716f0
// Stable ID: aa_007716f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00770ea0×2, FUN_00770710, FUN_007714a0, FUN_007716f0.
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

void FUN_007716f0(int param_1)



{

  int iVar1;

  int iVar2;

  int unaff_EBX;

  int unaff_ESI;

  

  iVar1 = *(int *)(param_1 + 8);

  if (iVar1 != *(int *)(unaff_EBX + 8)) {

    *(int *)(unaff_ESI + 8) = iVar1;

    FUN_007714a0(param_1);

    return;

  }

  iVar2 = FUN_00770710();

  if (iVar2 != -1) {

    *(int *)(unaff_ESI + 8) = iVar1;

    FUN_00770ea0();

    return;

  }

  *(uint *)(unaff_ESI + 8) = (uint)(iVar1 == 0);

  FUN_00770ea0();

  return;

}
