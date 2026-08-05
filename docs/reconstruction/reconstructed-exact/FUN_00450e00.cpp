// =============================================================================
// FUN_00450e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00450e00
// Address:   0x00450e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00450e00 @ 0x00450e00
// Stable ID: aa_00450e00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00450e00.
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

void FUN_00450e00(int param_1,int param_2,int *param_3)



{

  int in_EAX;

  int iVar1;

  float10 fVar2;

  float10 fVar3;

  

  while (param_2 < in_EAX) {

    iVar1 = (in_EAX + -1) / 2;

    fVar2 = (float10)(**(code **)(**(int **)(param_1 + iVar1 * 4) + 8))();

    fVar3 = (float10)(**(code **)(*param_3 + 8))();

    if (fVar3 <= (float10)(float)fVar2) break;

    *(uint32_t /* width from decompiler */ *)(param_1 + in_EAX * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar1 * 4);

    in_EAX = iVar1;

  }

  *(int **)(param_1 + in_EAX * 4) = param_3;

  return;

}
