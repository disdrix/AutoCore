// =============================================================================
// FUN_0053d170
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d170
// Address:   0x0053d170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053d170 @ 0x0053d170
// Stable ID: aa_0053d170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: CONCAT31, FUN_004cd220, FUN_0053d170, FUN_00568100, FUN_005d6870.
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

uint __thiscall FUN_0053d170(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  float *pfVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint *puVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint in_EAX;

  char *pcVar9;

  int iVar10;

  float *unaff_ESI;

  float10 fVar11;

  int **ppiStack_24;

  int iStack_20;

  uint8_t *puStack_1c;

  int iStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  int *piStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  if (param_2 == (int *)0x0) {

    return in_EAX & 0xffffff00;

  }

  uStack_c = param_3;

  piStack_10 = param_2;

  uStack_14 = 0x53d19d;

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1) + 0xb0))();

  iStack_18 = *(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x34 + param_1;

  uStack_14 = 0x10;

  puStack_1c = (uint8_t *)0x53d1b1;

  (**(code **)(*param_2 + 0x14))();

  iVar10 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

  pfVar1 = (float *)(iVar10 + 0x34 + param_1);

  *pfVar1 = *unaff_ESI + *(float *)(iVar10 + 0x34 + param_1);

  pfVar1[1] = unaff_ESI[1] + pfVar1[1];

  pfVar1[2] = unaff_ESI[2] + pfVar1[2];

  pfVar1[3] = unaff_ESI[3] + pfVar1[3];

  puStack_1c = &stack0xfffffff8;

  iStack_20 = 0x53d20e;

  pcVar9 = (char *)FUN_005d6870();

  uVar8 = DAT_00aaa7ac;

  uVar7 = DAT_00a0f694;

  if (*pcVar9 == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x34 + param_1);

    *puVar2 = DAT_00a0f694;

    puVar2[2] = uVar7;

    puVar2[1] = uVar8;

    puVar2[3] = 0;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x40 + param_1) = 0;

  }

  iStack_20 = *(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x44 + param_1;

  puStack_1c = (uint8_t *)0x10;

  ppiStack_24 = (int **)0x53d268;

  (**(code **)(*param_2 + 0x14))();

  ppiStack_24 = &piStack_10;

  pcVar9 = (char *)FUN_00568100();

  if (*pcVar9 == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x44 + param_1);

    puVar2[3] = 0;

    puVar2[2] = 0;

    puVar2[1] = 0;

    *puVar2 = 0;

    puVar2[3] = g_flOne;

  }

  ppiStack_24 = (int **)0x4;

  (**(code **)(*param_2 + 0x14))(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x6c + param_1);

  (**(code **)(*param_2 + 0x14))(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x70 + param_1);

  ppiStack_24 = (int **)((uint)ppiStack_24 & 0xffffff00);

  (**(code **)(*param_2 + 0x14))(&ppiStack_24,1);

  puVar3 = (uint *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x130 + param_1);

  *puVar3 = *puVar3 ^ *puVar3 & 0x200;

  iVar4 = *(int *)(param_1 + -0x4c);

  iVar10 = *(int *)(iVar4 + 4);

  if ((*(int *)(iVar10 + 0x58 + param_1) != 0) &&

     (iVar10 = *(int *)(*(int *)(iVar4 + 4) + 0x58 + param_1), *(int *)(iVar10 + 0xe4f8) != 0)) {

    if ((char)iStack_20 != '\0') {

      iVar10 = *(int *)(iVar4 + 4);

      fVar11 = (float10)FUN_004cd220(*(uint32_t /* width from decompiler */ *)(iVar10 + 0x34 + param_1),

                                     *(uint32_t /* width from decompiler */ *)(iVar10 + 0x3c + param_1));

      *(float *)(iVar10 + param_1 + 0x38) = (float)fVar11;

    }

    fVar6 = g_flOne;

    iVar10 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

    pfVar1 = (float *)(iVar10 + 0x34 + param_1);

    if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {

      *(float *)(iVar10 + 0x34 + param_1) = g_flOne;

    }

    iVar10 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

    iVar4 = *(int *)(*(int *)(iVar10 + 0x58 + param_1) + 0xe4f8);

    if ((float)*(int *)(iVar4 + 0x10) * *(float *)(iVar4 + 0x18) <

        *(float *)(iVar10 + 0x34 + param_1)) {

      iVar10 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

      iVar4 = *(int *)(*(int *)(iVar10 + 0x58 + param_1) + 0xe4f8);

      *(float *)(iVar10 + param_1 + 0x34) =

           (float)*(int *)(iVar4 + 0x10) * *(float *)(iVar4 + 0x18) - fVar6;

    }

    iVar10 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

    pfVar1 = (float *)(iVar10 + 0x3c + param_1);

    if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {

      *(float *)(iVar10 + 0x3c + param_1) = fVar6;

    }

    iVar4 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

    iVar5 = *(int *)(*(int *)(iVar4 + 0x58 + param_1) + 0xe4f8);

    iVar10 = iVar4 + param_1;

    if ((float)*(int *)(iVar5 + 0x14) * *(float *)(iVar5 + 0x18) <

        *(float *)(iVar4 + 0x3c + param_1)) {

      iVar10 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

      iVar4 = *(int *)(*(int *)(iVar10 + 0x58 + param_1) + 0xe4f8);

      iVar10 = iVar10 + param_1;

      *(float *)(iVar10 + 0x3c) = (float)*(int *)(iVar4 + 0x14) * *(float *)(iVar4 + 0x18) - fVar6;

    }

  }

  return CONCAT31((int3)((uint)iVar10 >> 8),1);

}
