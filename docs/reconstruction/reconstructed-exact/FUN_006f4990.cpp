// =============================================================================
// FUN_006f4990
// -----------------------------------------------------------------------------
// Stable ID: aa_006f4990
// Address:   0x006f4990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f4990 @ 0x006f4990
// Stable ID: aa_006f4990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_006f4830, FUN_006f4990.
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

void __thiscall

FUN_006f4990(int param_1,uint *param_2,uint param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint *param_6,int *param_7,int param_8)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  float fVar10;

  float fVar11;

  int iVar12;

  bool bVar13;

  int iVar14;

  int local_20;

  uint8_t local_1c [12];

  int *piStack_10;

  int *piStack_c;

  int *piStack_8;

  int *piStack_4;

  

  iVar14 = *(int *)(*(int *)(param_8 + 0xb8) + 0x14);

  iVar12 = 0;

  fVar10 = g_flZero;

  if ((iVar14 != 0) &&

     (fVar11 = *(float *)(param_8 + 0x10) - *(float *)(param_8 + 0xc), g_flZero < fVar11)) {

    fVar10 = fVar11;

  }

  if ((iVar14 != 1) &&

     (fVar11 = *(float *)(param_8 + 0x18) - *(float *)(param_8 + 0x14), fVar10 < fVar11)) {

    iVar12 = 1;

    fVar10 = fVar11;

  }

  if ((iVar14 != 2) && (fVar10 < *(float *)(param_8 + 0x20) - *(float *)(param_8 + 0x1c))) {

    iVar12 = 2;

  }

  iVar14 = (int)(*param_7 - *param_6) >> 4;

  local_20 = param_1;

  (**(code **)(**(int **)(param_1 + 0x28) + 0xc))

            (iVar12 * 0x20 + *(int *)(param_1 + 0x34),*param_6,iVar14,&local_20,local_1c);

  param_3 = param_3 & 0xffffff00;

  if (1 < iVar14) {

    FUN_006f4830(*param_6,0,iVar14 + -1,param_3);

  }

  param_3 = *param_2;

  bVar13 = (int)(*piStack_c - *piStack_10 & 0xfffffff0U) <

           (int)(*piStack_4 - *piStack_8 & 0xfffffff0U);

  if (*param_6 < param_3) {

    do {

      iVar12 = *piStack_c - *piStack_10 >> 4;

      iVar14 = *piStack_4 - *piStack_8 >> 4;

      if (bVar13) {

        iVar14 = iVar14 << 2;

      }

      else {

        iVar12 = iVar12 << 2;

      }

      if (iVar14 <= iVar12) {

        *piStack_4 = *piStack_4 + 0x10;

        *param_6 = *param_6 + 0x10;

      }

      else {

        uVar1 = *(uint32_t /* width from decompiler */ *)(param_3 - 0x10);

        uVar2 = *(uint32_t /* width from decompiler */ *)(param_3 - 0xc);

        uVar3 = *(uint32_t /* width from decompiler */ *)(param_3 - 8);

        uVar4 = *(uint32_t /* width from decompiler */ *)(param_3 - 4);

        puVar5 = (uint32_t /* width from decompiler */ *)*param_6;

        *(uint32_t /* width from decompiler */ *)(param_3 - 0x10) = *puVar5;

        *(uint32_t /* width from decompiler */ *)(param_3 - 0xc) = puVar5[1];

        *(uint32_t /* width from decompiler */ *)(param_3 - 8) = puVar5[2];

        *(uint32_t /* width from decompiler */ *)(param_3 - 4) = puVar5[3];

        puVar5 = (uint32_t /* width from decompiler */ *)*piStack_8;

        uVar6 = *puVar5;

        uVar7 = puVar5[1];

        uVar8 = puVar5[2];

        uVar9 = puVar5[3];

        puVar5 = (uint32_t /* width from decompiler */ *)*piStack_c;

        *puVar5 = uVar1;

        puVar5[1] = uVar2;

        puVar5[2] = uVar3;

        puVar5[3] = uVar4;

        puVar5 = (uint32_t /* width from decompiler */ *)*param_6;

        *puVar5 = uVar6;

        puVar5[1] = uVar7;

        puVar5[2] = uVar8;

        puVar5[3] = uVar9;

        *piStack_c = *piStack_c + 0x10;

        *piStack_8 = *piStack_8 + 0x10;

        *param_6 = *param_6 + 0x10;

        *piStack_4 = *piStack_4 + 0x10;

      }

      bVar13 = iVar14 > iVar12;

      param_3 = *param_2;

    } while (*param_6 < param_3);

  }

  return;

}
