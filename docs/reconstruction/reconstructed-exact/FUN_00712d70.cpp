// =============================================================================
// FUN_00712d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00712d70
// Address:   0x00712d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712d70 @ 0x00712d70
// Stable ID: aa_00712d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×4, do×3, while×3, return×1.
//  - Notable callees: FUN_00712d70, FUN_00712f60, FUN_00712fc0, FUN_00713300, FUN_00713360.
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

void FUN_00712d70(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint32_t /* width from decompiler */ **param_4)



{

  float *pfVar1;

  float fVar2;

  uint32_t /* width from decompiler */ *puVar3;

  float *pfVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ uVar6;

  undefined *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  undefined **ppuVar10;

  int local_54;

  uint32_t /* width from decompiler */ *local_50;

  float local_48;

  float local_44;

  uint32_t /* width from decompiler */ *local_40;

  undefined *local_3c;

  undefined *local_38;

  undefined *local_34;

  float local_30 [12];

  

  if ((float)param_4 <= DAT_00a0f698) {

    local_50 = &DAT_00a0f780;

    puVar7 = &DAT_00af8ab8;

    pfVar4 = (float *)&DAT_00a0f780;

    local_40 = (uint32_t /* width from decompiler */ *)&DAT_00a10210;

  }

  else {

    pfVar4 = (float *)&DAT_00a0f750;

    puVar7 = &DAT_00af8aa0;

    local_50 = &DAT_00a0f750;

    local_40 = &DAT_00a0fdc0;

  }

  local_3c = &DAT_00a10568;

  local_38 = &DAT_00a10840;

  local_34 = &DAT_00a10ad0;

  if (0 < param_3) {

    pfVar5 = pfVar4;

    iVar9 = param_3;

    do {

      pfVar1 = (float *)((param_1 - (int)pfVar4) + (int)pfVar5);

      fVar2 = *pfVar5;

      pfVar5 = pfVar5 + 1;

      iVar9 = iVar9 + -1;

      *(float *)(((int)&local_34 - (int)pfVar4) + (int)pfVar5) = *pfVar1 - fVar2;

    } while (iVar9 != 0);

  }

  param_4 = &local_40;

  ppuVar10 = &PTR_DAT_00af8ac0;

  local_54 = 0;

  pfVar4 = local_30;

  pfVar5 = local_30 + 1;

  puVar8 = param_2;

  param_2 = param_2 + 1;

  do {

    FUN_00712f60(local_30,local_54,*(uint32_t /* width from decompiler */ *)(((int)puVar7 - (int)&local_40) + (int)param_4),

                 &local_48,2);

    *pfVar4 = *pfVar4 - local_48;

    *pfVar5 = *pfVar5 - local_44;

    if ((int)ppuVar10 < 0xaf8ad0) {

      puVar3 = *param_4;

      FUN_00712fc0(puVar8,pfVar4,2,*puVar3,puVar3[1],puVar3[2],puVar3[3],puVar3[4],puVar3[5],

                   puVar3[6],puVar3[7]);

    }

    else {

      uVar6 = FUN_00713300(pfVar4,*(uint32_t /* width from decompiler */ *)((int)*ppuVar10 + 4),*(uint32_t /* width from decompiler */ *)*ppuVar10);

      *puVar8 = uVar6;

      *param_2 = 0;

      FUN_00713360(*puVar8,*(uint32_t /* width from decompiler */ *)((int)*ppuVar10 + 4),*(uint32_t /* width from decompiler */ *)*ppuVar10,pfVar4);

    }

    *pfVar4 = local_48 + *pfVar4;

    ppuVar10 = ppuVar10 + 1;

    local_54 = local_54 + 2;

    pfVar5 = pfVar5 + 2;

    param_2 = param_2 + 2;

    pfVar4[1] = local_44 + pfVar4[1];

    puVar8 = puVar8 + 2;

    pfVar4 = pfVar4 + 2;

    param_4 = param_4 + 1;

  } while ((int)ppuVar10 < 0xaf8ad8);

  if (0 < param_3) {

    pfVar4 = local_30;

    do {

      pfVar5 = (float *)(((int)local_50 - (int)local_30) + (int)pfVar4);

      fVar2 = *pfVar4;

      pfVar4 = pfVar4 + 1;

      param_3 = param_3 + -1;

      *(float *)((param_1 - (int)local_30) + -4 + (int)pfVar4) = *pfVar5 + fVar2;

    } while (param_3 != 0);

  }

  return;

}
