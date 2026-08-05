// =============================================================================
// FUN_006f4d20
// -----------------------------------------------------------------------------
// Stable ID: aa_006f4d20
// Address:   0x006f4d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f4d20 @ 0x006f4d20
// Stable ID: aa_006f4d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, do×2, goto×2, while×2, for×1.
//  - Notable callees: FUN_006f4d20×3, FUN_006f43e0×2, FUN_006f4830×2, FUN_006f3d20, FUN_006f4170, FUN_006f4230, FUN_006f4750, FUN_006f4b90.
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

int * __thiscall FUN_006f4d20(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3,int *param_4,int param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint uStack_34;

  int iStack_30;

  uint8_t auStack_2c [8];

  float afStack_24 [3];

  uint8_t auStack_18 [12];

  uint8_t auStack_c [12];

  

  puVar1 = param_3;

  if (param_3[1] == 1) {

    if (*(int *)(param_1 + 0x1c) == 0) {

      (**(code **)(**(int **)(param_1 + 0x24) + 0xc))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),param_1,0x800)

      ;

    }

    piVar2 = (int *)FUN_006f4750(param_2,puVar1);

    return piVar2;

  }

  if (*(int *)(param_1 + 0x14) == 0) {

    (**(code **)(**(int **)(param_1 + 0x24) + 0xc))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),param_1,0x800);

  }

  piVar2 = *(int **)(param_1 + 0x10);

  *(int *)(param_1 + 0x10) = *piVar2;

  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;

  FUN_006f3d20();

  *(uint8_t *)(piVar2 + 1) = 0;

  piVar2[0x31] = 0x49742400;

  piVar2[0x2f] = 0x501502f9;

  piVar2[0x3b] = 0;

  piVar2[0x3c] = 0;

  piVar2[0x3d] = puVar1[1];

  *piVar2 = param_2;

  if (param_2 == 0) {

    *(int **)(param_1 + 0x2c) = piVar2;

  }

  else {

    if (param_4 == (int *)0x0) {

      *(int **)(param_2 + 0xec) = piVar2;

    }

    else {

      *(int **)(param_2 + 0xf0) = piVar2;

    }

    piVar2[3] = *(int *)(param_2 + 0xc);

    piVar2[4] = *(int *)(param_2 + 0x10);

    piVar2[5] = *(int *)(param_2 + 0x14);

    piVar2[6] = *(int *)(param_2 + 0x18);

    piVar2[7] = *(int *)(param_2 + 0x1c);

    piVar2[8] = *(int *)(param_2 + 0x20);

  }

  param_3 = (uint32_t /* width from decompiler */ *)0x0;

  FUN_006f4230(param_2,&iStack_30,afStack_24);

  param_2 = 0;

  do {

    iVar3 = (&iStack_30)[param_2] * 0x20;

    iVar4 = iVar3 + *(int *)(param_1 + 0x34);

    if ((float)piVar2[0x31] <

        afStack_24[param_2] + *(float *)(iVar3 + 0x10 + *(int *)(param_1 + 0x34)))

    goto joined_r0x006f4ec4;

    param_4 = piVar2 + (&iStack_30)[param_2] * 2 + 3;

    (**(code **)(**(int **)(param_1 + 0x28) + 0xc))(iVar4,*puVar1,puVar1[1],param_4,param_4 + 1);

    uStack_34 = uStack_34 & 0xffffff00;

    if (1 < (int)puVar1[1]) {

      FUN_006f4830(*puVar1,0,puVar1[1] + -1,uStack_34);

    }

    param_3 = (uint32_t /* width from decompiler */ *)iVar4;

    FUN_006f43e0(piVar2,iVar4,puVar1,param_4,param_5);

    param_2 = param_2 + 1;

  } while (param_2 < 3);

LAB_006f4f06:

  param_4 = (int *)0x3;

  if (3 < *(int *)(param_1 + 0x30)) {

    param_2 = 0x60;

    do {

      iVar3 = *(int *)(param_1 + 0x34) + param_2;

      if ((float)piVar2[0x31] < *(float *)(*(int *)(param_1 + 0x34) + 0x10 + param_2)) break;

      (**(code **)(**(int **)(param_1 + 0x28) + 0xc))(iVar3,*puVar1,puVar1[1],&iStack_30,auStack_2c)

      ;

      uStack_34 = uStack_34 & 0xffffff00;

      if (1 < (int)puVar1[1]) {

        FUN_006f4830(*puVar1,0,puVar1[1] + -1,uStack_34);

      }

      param_3 = (uint32_t /* width from decompiler */ *)iVar3;

      FUN_006f43e0(piVar2,iVar3,puVar1,&iStack_30,param_5);

      param_4 = (int *)((int)param_4 + 1);

      param_2 = param_2 + 0x20;

    } while ((int)param_4 < *(int *)(param_1 + 0x30));

  }

  FUN_006f4170(puVar1,piVar2);

  if (param_3 != (uint32_t /* width from decompiler */ *)piVar2[0x2e]) {

    (**(code **)(**(int **)(param_1 + 0x28) + 0xc))

              (piVar2[0x2e],*puVar1,puVar1[1],&param_3,&param_2);

  }

  iVar3 = param_5;

  FUN_006f4b90(puVar1,piVar2,param_5,auStack_c,auStack_18);

  iVar4 = FUN_006f4d20(piVar2,auStack_18,1,iVar3 + 1);

  piVar2[0x3c] = iVar4;

  iVar3 = FUN_006f4d20(piVar2,auStack_c,0,iVar3 + 1);

  piVar2[0x3b] = iVar3;

  return piVar2;

joined_r0x006f4ec4:

  for (; param_2 < 3; param_2 = param_2 + 1) {

    (**(code **)(**(int **)(param_1 + 0x28) + 0x10))

              ((&iStack_30)[param_2] * 0x20 + *(int *)(param_1 + 0x34),*puVar1,puVar1[1],

               piVar2 + (&iStack_30)[param_2] * 2 + 3,piVar2 + (&iStack_30)[param_2] * 2 + 3 + 1);

  }

  goto LAB_006f4f06;

}
