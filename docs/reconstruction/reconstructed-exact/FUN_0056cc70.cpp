// =============================================================================
// FUN_0056cc70
// -----------------------------------------------------------------------------
// Stable ID: aa_0056cc70
// Address:   0x0056cc70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056cc70 @ 0x0056cc70
// Stable ID: aa_0056cc70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004f56e0×4, FUN_004f54f0, FUN_0056cc70.
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

float * __thiscall FUN_0056cc70(int param_1,float *param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  int iVar11;

  char cVar12;

  int iVar13;

  float *pfVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint8_t auStack_20 [28];

  

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

  if (*(int **)(iVar1 + 0xb0) == (int *)0x0) {

    *param_2 = *(float *)(iVar1 + 0x84);

    param_2[1] = *(float *)(iVar1 + 0x88);

    param_2[2] = *(float *)(iVar1 + 0x8c);

    param_2[3] = *(float *)(iVar1 + 0x90);

    return param_2;

  }

  iVar13 = (**(code **)(**(int **)(iVar1 + 0xb0) + 0x1d4))();

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  if (iVar13 == 0) {

    pfVar14 = (float *)(**(code **)(**(int **)(iVar1 + 0xb0 + param_1) + 0x1a0))();

    *param_2 = *pfVar14;

    param_2[1] = pfVar14[1];

    param_2[2] = pfVar14[2];

    param_2[3] = pfVar14[3];

    return param_2;

  }

  uVar15 = FUN_004f56e0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1),

                        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1));

  FUN_004f54f0(auStack_20,uVar15);

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  fVar2 = *(float *)(param_1 + 0xf0);

  iVar11 = *(int *)(*(int *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 0xac + iVar13) + 0x3c);

  fVar3 = *(float *)(param_1 + 0xf4);

  fVar4 = *(float *)(param_1 + 0xf8);

  cVar12 = FUN_004f56e0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1),

                        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1));

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  fVar5 = *(float *)(iVar11 + 0x4e8 + cVar12 * 0xc);

  iVar11 = *(int *)(*(int *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 0xac + iVar13) + 0x3c);

  cVar12 = FUN_004f56e0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1),

                        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1));

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  fVar6 = *(float *)(iVar11 + (cVar12 + 0x69) * 0xc);

  iVar11 = *(int *)(*(int *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 0xac + iVar13) + 0x3c);

  cVar12 = FUN_004f56e0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1),

                        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1));

  fVar7 = *(float *)(iVar11 + 0x4f0 + cVar12 * 0xc);

  if (*(int *)(iVar13 + 8) == 0) {

    pfVar14 = (float *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 0x84 + iVar13);

  }

  else {

    pfVar14 = (float *)(*(int *)(*(int *)(iVar13 + 8) + 0x3c) + 0xb0);

  }

  fVar8 = pfVar14[2];

  fVar9 = pfVar14[1];

  fVar10 = pfVar14[3];

  *param_2 = *pfVar14 + fVar5 + fVar2;

  param_2[1] = fVar9 + fVar6 + fVar3;

  param_2[2] = fVar8 + fVar7 + fVar4;

  param_2[3] = fVar10;

  return param_2;

}
