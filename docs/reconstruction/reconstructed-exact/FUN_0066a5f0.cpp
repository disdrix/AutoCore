// =============================================================================
// FUN_0066a5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066a5f0
// Address:   0x0066a5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066a5f0 @ 0x0066a5f0
// Stable ID: aa_0066a5f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_005b3370×3, FUN_0066a5f0, SQRT.
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

void __thiscall FUN_0066a5f0(int param_1,float *param_2)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  int iVar9;

  float *pfVar10;

  

  piVar1 = (int *)(param_1 + 0x10);

  if (*(uint *)(param_1 + 0x14) == (*(uint *)(param_1 + 0x18) & 0x7fffffff)) {

    FUN_005b3370(piVar1,0x10);

  }

  iVar9 = *(int *)(param_1 + 0x14);

  *(int *)(param_1 + 0x14) = iVar9 + 1;

  pfVar10 = (float *)(iVar9 * 0x10 + *piVar1);

  *pfVar10 = *param_2;

  pfVar10[1] = param_2[1];

  pfVar10[2] = param_2[2];

  pfVar10[3] = param_2[3];

  if (*(int *)(param_1 + 0x14) == 1) {

    if (*(uint *)(param_1 + 0x20) == (*(uint *)(param_1 + 0x24) & 0x7fffffff)) {

      FUN_005b3370((int *)(param_1 + 0x1c),4);

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x20) * 4) = 0;

    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

    return;

  }

  fVar2 = *param_2;

  pfVar10 = (float *)((*(int *)(param_1 + 0x14) + -2) * 0x10 + *piVar1);

  fVar3 = *pfVar10;

  fVar4 = pfVar10[1];

  fVar5 = pfVar10[2];

  fVar6 = param_2[1];

  fVar7 = param_2[2];

  fVar8 = *(float *)(*(int *)(param_1 + 0x1c) + -4 + *(int *)(param_1 + 0x20) * 4);

  if (*(uint *)(param_1 + 0x20) == (*(uint *)(param_1 + 0x24) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x1c),4);

  }

  *(float *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x20) * 4) =

       SQRT((fVar2 - fVar3) * (fVar2 - fVar3) +

            (fVar6 - fVar4) * (fVar6 - fVar4) + (fVar7 - fVar5) * (fVar7 - fVar5)) + fVar8;

  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

  return;

}
