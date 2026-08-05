// =============================================================================
// FUN_006f29f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f29f0
// Address:   0x006f29f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f29f0 @ 0x006f29f0
// Stable ID: aa_006f29f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: FUN_006469c0×4, FUN_00646a60×4, FUN_006f29f0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_006f29f0(int param_1,int param_2,int param_3,int *param_4,int *param_5)



{

  float fVar1;

  float *pfVar2;

  float fVar3;

  double dVar4;

  double dVar5;

  double dVar6;

  int iVar7;

  byte bVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  float10 fVar12;

  float10 fVar13;

  double local_38;

  double local_30;

  double local_20;

  

  pfVar2 = *(float **)(param_2 + 0xb8);

  iVar9 = 0;

  iVar11 = 0;

  iVar10 = 0;

  if ((*pfVar2 != g_flZero) && (iVar9 = 1, *pfVar2 < g_flZero)) {

    iVar11 = 1;

  }

  if (pfVar2[1] != g_flZero) {

    iVar9 = iVar9 + 1;

    iVar10 = 1;

    if (pfVar2[1] < g_flZero) {

      iVar11 = iVar11 + 1;

    }

  }

  if (pfVar2[2] != g_flZero) {

    iVar9 = iVar9 + 1;

    iVar10 = 2;

    if (pfVar2[2] < g_flZero) {

      iVar11 = iVar11 + 1;

    }

  }

  fVar1 = *(float *)(param_2 + 0xc0);

  if (iVar9 == 1) {

    fVar12 = (float10)FUN_006469c0((float)(((float10)*(float *)(param_2 + 0xbc) -

                                           (float10)*(float *)(param_1 + 0x30 + iVar10 * 4)) *

                                          (float10)*(float *)(param_1 + 0x3c)));

    iVar11 = FUN_00646a60((float)fVar12);

    fVar12 = (float10)FUN_006469c0((fVar1 - *(float *)(param_1 + 0x30 + iVar10 * 4)) *

                                   *(float *)(param_1 + 0x3c));

    iVar7 = FUN_00646a60((float)fVar12);

    iVar9 = *(int *)(param_3 + 0x28 + iVar10 * 4);

    bVar8 = (byte)*(uint32_t /* width from decompiler */ *)(param_3 + 0x24);

    *param_5 = iVar11 - iVar9 >> (bVar8 & 0x1f);

    *param_4 = (iVar7 - iVar9 >> (bVar8 & 0x1f)) + 1;

    if (*param_5 < 0) {

      *param_5 = 0;

      return;

    }

  }

  else {

    fVar3 = g_flOne / *(float *)(param_1 + 0x3c);

    fVar13 = (float10)(fVar3 * (float)*(int *)(param_3 + 0x28) + *(float *)(param_1 + 0x30)) *

             (float10)*pfVar2 +

             ((float10)*(int *)(param_3 + 0x2c) * (float10)fVar3 +

             (float10)*(float *)(param_1 + 0x34)) * (float10)pfVar2[1] +

             ((float10)*(int *)(param_3 + 0x30) * (float10)fVar3 +

             (float10)*(float *)(param_1 + 0x38)) * (float10)pfVar2[2];

    fVar12 = (float10)_DAT_00aaa5f8 / (float10)(1 << ((byte)*(uint32_t /* width from decompiler */ *)(param_3 + 0x24) & 0x1f))

    ;

    local_20 = _DAT_00aaa5f8;

    dVar6 = _DAT_00aaa5e0;

    dVar4 = _DAT_00a0ee90;

    if ((iVar9 == 2) ||

       (dVar6 = _DAT_009e90e8, dVar4 = _DAT_00a0ee88, dVar5 = _DAT_00aaa5f8, iVar9 == 3)) {

      local_20 = dVar6;

      dVar5 = dVar4;

    }

    local_30 = (double)((float10)(double)(((float10)*(float *)(param_2 + 0xbc) - fVar13) *

                                          (float10)*(float *)(param_1 + 0x3c) * fVar12) *

                       (float10)dVar5);

    local_38 = (double)((float10)dVar5 *

                       ((float10)fVar1 - fVar13) * (float10)*(float *)(param_1 + 0x3c) * fVar12);

    if (iVar11 != 0) {

      local_30 = local_30 + (double)(iVar11 * 0xff);

      local_38 = (double)(iVar11 * 0xff) + local_38;

    }

    fVar12 = (float10)FUN_006469c0((float)((float10)local_20 * (float10)local_30));

    iVar9 = FUN_00646a60((float)fVar12);

    fVar12 = (float10)FUN_006469c0((float)((float10)local_20 * (float10)local_38));

    iVar10 = FUN_00646a60((float)fVar12);

    *param_5 = iVar9;

    *param_4 = iVar10 + 1;

  }

  return;

}
