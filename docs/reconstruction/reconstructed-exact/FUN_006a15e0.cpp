// =============================================================================
// FUN_006a15e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a15e0
// Address:   0x006a15e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a15e0 @ 0x006a15e0
// Stable ID: aa_006a15e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, return×2, for×1.
//  - Notable callees: FUN_0056f570×3, block×3, FUN_006a1190×2, FUN_00696d80, FUN_006a00d0, FUN_006a15e0.
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

/* WARNING: Removing unreachable block (ram,0x006a18a0) */

/* WARNING: Removing unreachable block (ram,0x006a1895) */

/* WARNING: Removing unreachable block (ram,0x006a18ae) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_006a15e0(int param_1,uint param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  float *pfVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  int local_38;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab1e8;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_006a1190(param_2);

  uVar10 = 0;

  if (param_2 != 0) {

    fVar2 = (float)(int)param_2;

    if ((int)param_2 < 0) {

      fVar2 = fVar2 + _DAT_00aaa5dc;

    }

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

    do {

      fVar3 = (float)(int)uVar10;

      if ((int)uVar10 < 0) {

        fVar3 = fVar3 + _DAT_00aaa5dc;

      }

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_006a00d0(&local_24,fVar3 / fVar2);

      *puVar5 = *puVar4;

      puVar5[1] = puVar4[1];

      puVar5[2] = puVar4[2];

      puVar5[3] = puVar4[3];

      puVar5[4] = puVar4[4];

      puVar5[5] = puVar4[5];

      FUN_0056f570();

      uVar10 = uVar10 + 1;

      puVar5 = puVar5 + 6;

    } while (uVar10 < param_2);

  }

  iVar8 = *(int *)(param_1 + 0x40);

  if (iVar8 != 0) {

    iVar1 = *(int *)(param_1 + 0x44);

    for (; iVar8 != iVar1; iVar8 = iVar8 + 0x18) {

      FUN_0056f570();

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x40));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  FUN_006a1190(param_2);

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x40);

  *puVar4 = *puVar5;

  puVar4[1] = puVar5[1];

  puVar4[2] = puVar5[2];

  puVar4[3] = puVar5[3];

  puVar4[4] = puVar5[4];

  uVar9 = 1;

  uVar10 = param_2 - 1;

  puVar4[5] = puVar5[5];

  if (1 < uVar10) {

    fVar2 = (float)(int)param_2;

    if ((int)param_2 < 0) {

      fVar2 = fVar2 + _DAT_00aaa5dc;

    }

    local_38 = 0x18;

    uVar11 = 0;

    do {

      fVar3 = (float)(int)uVar9;

      if ((int)uVar9 < 0) {

        fVar3 = fVar3 + _DAT_00aaa5dc;

      }

      fVar3 = fVar3 / fVar2;

      uVar12 = uVar11;

      if (uVar11 < uVar10) {

        pfVar7 = (float *)(uVar11 * 0x18);

        uVar6 = uVar11;

        do {

          if ((*pfVar7 <= fVar3) && (uVar12 = uVar6, fVar3 < pfVar7[6])) break;

          uVar6 = uVar6 + 1;

          pfVar7 = pfVar7 + 6;

          uVar12 = uVar11;

        } while (uVar6 < uVar10);

      }

      FUN_00696d80(fVar3,0,0,0,0);

      pfVar7 = (float *)(uVar12 * 0x18);

      puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x40) + local_38);

      local_20 = (pfVar7[7] - pfVar7[1]) *

                 ((fVar3 - *(float *)(uVar12 * 0x18)) / (pfVar7[6] - *pfVar7)) + pfVar7[1];

      *puVar5 = local_24;

      puVar5[1] = local_20;

      puVar5[2] = local_1c;

      puVar5[3] = local_18;

      puVar5[4] = local_14;

      puVar5[5] = local_10;

      FUN_0056f570();

      uVar9 = uVar9 + 1;

      local_38 = local_38 + 0x18;

      uVar11 = uVar12;

    } while (uVar9 < uVar10);

  }

  if (*(int *)(param_1 + 0x10) == 0) {

    iVar8 = 0;

  }

  else {

    iVar8 = (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x18;

  }

  iVar1 = *(int *)(param_1 + 0x40);

  puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + -0x18 + iVar8 * 0x18);

  *(uint32_t /* width from decompiler */ *)(iVar1 + -0x18 + param_2 * 0x18) = *puVar5;

  iVar8 = iVar1 + -0x18 + param_2 * 0x18;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 4) = puVar5[1];

  *(uint32_t /* width from decompiler */ *)(iVar8 + 8) = puVar5[2];

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0xc) = puVar5[3];

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x10) = puVar5[4];

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x14) = puVar5[5];

  ExceptionList = local_c;

  return;

}
