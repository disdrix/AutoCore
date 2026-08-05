// =============================================================================
// FUN_005ec4c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ec4c0
// Address:   0x005ec4c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ec4c0 @ 0x005ec4c0
// Stable ID: aa_005ec4c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005ec4c0.
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

void __thiscall FUN_005ec4c0(int *param_1,float *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  if ((char)param_1[2] == '\0') {

    iVar7 = **(int **)(param_3 + 0x10);

    iVar5 = *param_1;

    iVar6 = param_1[1];

  }

  else {

    iVar5 = param_1[1];

    iVar7 = **(int **)(param_3 + 0x10);

    iVar6 = *param_1;

  }

  fVar1 = *(float *)(iVar7 + 4 + iVar6 * 0xc);

  fVar2 = *(float *)(iVar7 + 8 + iVar6 * 0xc);

  fVar3 = *(float *)(iVar7 + 4 + iVar5 * 0xc);

  fVar4 = *(float *)(iVar7 + 8 + iVar5 * 0xc);

  *param_2 = *(float *)(iVar7 + iVar6 * 0xc) - *(float *)(iVar7 + iVar5 * 0xc);

  param_2[1] = fVar1 - fVar3;

  param_2[2] = fVar2 - fVar4;

  return;

}
