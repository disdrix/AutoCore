// =============================================================================
// FUN_00700810
// -----------------------------------------------------------------------------
// Stable ID: aa_00700810
// Address:   0x00700810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00700810 @ 0x00700810
// Stable ID: aa_00700810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00700810.
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

void __thiscall FUN_00700810(int param_1,float *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float *pfVar4;

  

  iVar2 = *(int *)(param_1 + 0x50);

  iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 0x80) * 0x10;

  *(float *)(iVar3 + iVar2) = *param_2 - param_2[8];

  iVar3 = iVar3 + iVar2;

  *(float *)(iVar3 + 4) = param_2[1] - param_2[9];

  *(float *)(iVar3 + 8) = param_2[2] - param_2[10];

  *(float *)(iVar3 + 0xc) = param_2[3] - param_2[0xb];

  pfVar4 = (float *)(*(int *)(*(int *)(param_1 + 0x48) + 0x80) * 0x10 + *(int *)(param_1 + 0x48));

  *pfVar4 = *param_2;

  pfVar4[1] = param_2[1];

  pfVar4[2] = param_2[2];

  pfVar4[3] = param_2[3];

  pfVar4 = (float *)((*(int *)(*(int *)(param_1 + 0x48) + 0x80) + 4) * 0x10 +

                    *(int *)(param_1 + 0x48));

  *pfVar4 = param_2[4];

  pfVar4[1] = param_2[5];

  pfVar4[2] = param_2[6];

  pfVar4[3] = param_2[7];

  piVar1 = (int *)(*(int *)(param_1 + 0x48) + 0x80);

  *piVar1 = *piVar1 + 1;

  return;

}
