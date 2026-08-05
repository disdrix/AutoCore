// =============================================================================
// FUN_009216e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009216e0
// Address:   0x009216e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009216e0 @ 0x009216e0
// Stable ID: aa_009216e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_009210e0, FUN_009216e0.
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

void __thiscall FUN_009216e0(int *param_1,float param_2)



{

  float fVar1;

  int iVar2;

  

  if (((int *)param_1[0x31e] != (int *)0x0) &&

     (iVar2 = (**(code **)(*(int *)param_1[0x31e] + 0xe8))(), iVar2 != -1)) {

    return;

  }

  if ((DAT_00d1b6d8 != 0) &&

     (fVar1 = (float)param_1[0x15a], param_1[0x15a] = (int)(fVar1 + param_2),

     (float)param_1[0x159] <= fVar1 + param_2)) {

    param_1[0x15a] = 0;

    (**(code **)(*param_1 + 0x478))();

    FUN_009210e0(param_1);

  }

  return;

}
