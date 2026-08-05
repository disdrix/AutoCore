// =============================================================================
// FUN_006f4550
// -----------------------------------------------------------------------------
// Stable ID: aa_006f4550
// Address:   0x006f4550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f4550 @ 0x006f4550
// Stable ID: aa_006f4550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: return×4, if×2, switch×1.
//  - Notable callees: FUN_006f4550.
//  - Return sites: 4.

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

FUN_006f4550(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,float param_4,int *param_5,int *param_6,

            int *param_7,int *param_8,int *param_9,int *param_10)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  float *pfVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  float fVar13;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  

  switch(param_2) {

  case 0:

    *param_9 = *param_9 + -0x10;

    *param_10 = *param_10 + -0x10;

    iVar7 = *param_8;

    *param_8 = iVar7 + -0x10;

    puVar1 = (uint32_t /* width from decompiler */ *)*param_9;

    puVar2 = (uint32_t /* width from decompiler */ *)*param_7;

    uVar3 = *puVar2;

    uVar4 = puVar2[1];

    uVar5 = puVar2[2];

    uVar6 = puVar2[3];

    uVar9 = *(uint32_t /* width from decompiler */ *)(iVar7 + -0x10);

    uVar10 = *(uint32_t /* width from decompiler */ *)(iVar7 + -0xc);

    uVar11 = *(uint32_t /* width from decompiler */ *)(iVar7 + -8);

    uVar12 = *(uint32_t /* width from decompiler */ *)(iVar7 + -4);

    puVar2 = (uint32_t /* width from decompiler */ *)*param_10;

    *puVar1 = *puVar2;

    puVar1[1] = puVar2[1];

    puVar1[2] = puVar2[2];

    puVar1[3] = puVar2[3];

    puVar1 = (uint32_t /* width from decompiler */ *)*param_10;

    *puVar1 = uVar3;

    puVar1[1] = uVar4;

    puVar1[2] = uVar5;

    puVar1[3] = uVar6;

    puVar1 = (uint32_t /* width from decompiler */ *)*param_7;

    if (puVar1 != (uint32_t /* width from decompiler */ *)*param_8) {

      *puVar1 = uVar9;

      puVar1[1] = uVar10;

      puVar1[2] = uVar11;

      puVar1[3] = uVar12;

    }

    break;

  case 1:

    *param_7 = *param_7 + 0x10;

    return;

  case 2:

    *param_9 = *param_9 + -0x10;

    iVar7 = *param_8;

    *param_8 = iVar7 + -0x10;

    puVar1 = (uint32_t /* width from decompiler */ *)*param_7;

    puVar2 = (uint32_t /* width from decompiler */ *)*param_9;

    if (puVar1 != puVar2) {

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar7 + -0x10);

      uVar4 = *(uint32_t /* width from decompiler */ *)(iVar7 + -0xc);

      uVar5 = *(uint32_t /* width from decompiler */ *)(iVar7 + -8);

      uVar6 = *(uint32_t /* width from decompiler */ *)(iVar7 + -4);

      *puVar2 = *puVar1;

      puVar2[1] = puVar1[1];

      puVar2[2] = puVar1[2];

      puVar2[3] = puVar1[3];

      puVar1 = (uint32_t /* width from decompiler */ *)*param_7;

      *puVar1 = uVar3;

      puVar1[1] = uVar4;

      puVar1[2] = uVar5;

      puVar1[3] = uVar6;

      return;

    }

    break;

  case 3:

    *param_5 = *param_5 + -1;

    *param_6 = *param_6 + 1;

    iVar7 = *param_9;

    *param_9 = iVar7 + -0x10;

    pfVar8 = *(float **)(param_3 + 0xb8);

    local_34 = (*(float *)(param_3 + 0xc0) + *(float *)(param_3 + 0xbc)) * DAT_00a0f298;

    fVar13 = param_4;

    (**(code **)(**(int **)(param_1 + 0x28) + 0x14))(*param_7,pfVar8,local_34,param_4,iVar7 + -0x10)

    ;

    local_34 = -*pfVar8;

    local_30 = -pfVar8[1];

    local_2c = -pfVar8[2];

    local_28 = -pfVar8[3];

    (**(code **)(**(int **)(param_1 + 0x28) + 0x14))(*param_7,&local_34,-fVar13,param_4,*param_7);

    *param_7 = *param_7 + 0x10;

    return;

  }

  return;

}
