// =============================================================================
// FUN_00867060
// -----------------------------------------------------------------------------
// Stable ID: aa_00867060
// Address:   0x00867060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00867060 @ 0x00867060
// Stable ID: aa_00867060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~211 non-empty decompiler lines.
//  - Control keywords: if×23, goto×3, return×1.
//  - Notable callees: FUN_00791f30, FUN_00867060.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00867060(int param_1,float param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  bool bVar5;

  float fVar6;

  float fVar7;

  uint8_t *puStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint8_t *puStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  float fStack_18;

  uint8_t auStack_8 [8];

  

  fVar7 = DAT_00af9314;

  fVar6 = DAT_00af9304;

  if (*(float *)(param_1 + 0x50c) <= DAT_00aaa6cc) {

    if ((*(char *)(param_1 + 0x51c) == '\x01') && (*(char *)(param_1 + 0x51e) == '\x01')) {

      *(uint8_t *)(param_1 + 0x51c) = 0;

    }

    fVar7 = DAT_00af9314;

    if (*(int **)(param_1 + 0x530) != (int *)0x0) {

      fStack_18 = 1.4013e-45;

      uStack_1c = 0x86717d;

      iVar2 = (**(code **)(**(int **)(param_1 + 0x530) + 0x164))();

      uVar4 = *(uint *)(param_1 + 0x514);

      bVar5 = *(byte *)(iVar2 + 3) == uVar4;

      goto LAB_00867189;

    }

  }

  else {

    if (*(char *)(param_1 + 0x51c) == '\0') {

      fVar6 = *(float *)(param_1 + 0x50c) - param_2;

      *(float *)(param_1 + 0x50c) = fVar6;

      if (fVar6 < 0.0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0;

      }

    }

    else {

      if (*(float *)(param_1 + 0x50c) <= DAT_00af9304 && DAT_00af9304 != *(float *)(param_1 + 0x50c)

         ) {

        *(float *)(param_1 + 0x50c) =

             (DAT_00af9314 / _DAT_00af9310) * param_2 + *(float *)(param_1 + 0x50c);

      }

      if ((fVar6 <= *(float *)(param_1 + 0x50c)) &&

         (*(float *)(param_1 + 0x50c) = fVar6, *(char *)(param_1 + 0x51e) != '\0')) {

        *(uint8_t *)(param_1 + 0x51c) = 0;

      }

    }

    if (*(int **)(param_1 + 0x530) != (int *)0x0) {

      uVar4 = *(uint *)(param_1 + 0x514);

      if (*(float *)(param_1 + 0x50c) <= fVar7 && fVar7 != *(float *)(param_1 + 0x50c)) {

        uVar4 = (uint)(((float)(int)uVar4 / fVar7) * *(float *)(param_1 + 0x50c));

      }

      fStack_18 = 1.4013e-45;

      uStack_1c = 0x867148;

      iVar2 = (**(code **)(**(int **)(param_1 + 0x530) + 0x164))();

      bVar5 = *(byte *)(iVar2 + 3) == uVar4;

LAB_00867189:

      fVar7 = DAT_00af9314;

      if (!bVar5) {

        fStack_18 = 1.4013e-45;

        uStack_1c = 0x86719b;

        iVar2 = (**(code **)(**(int **)(param_1 + 0x530) + 0x164))();

        *(char *)(iVar2 + 3) = (char)uVar4;

        uStack_1c = 0x8671ac;

        (**(code **)(**(int **)(param_1 + 0x530) + 0x34c))();

        fVar7 = DAT_00af9314;

      }

    }

  }

  fVar6 = DAT_00af9308;

  if (*(float *)(param_1 + 0x510) <= DAT_00aaa6cc) {

    if ((*(char *)(param_1 + 0x51d) == '\x01') && (*(char *)(param_1 + 0x51f) == '\x01')) {

      *(uint8_t *)(param_1 + 0x51d) = 0;

    }

    if (*(int **)(param_1 + 0x534) == (int *)0x0) goto LAB_008672ea;

    fStack_18 = 0.0;

    uStack_1c = 0x8672bb;

    iVar2 = (**(code **)(**(int **)(param_1 + 0x534) + 0x164))();

    uVar4 = *(uint *)(param_1 + 0x518);

  }

  else {

    if (*(char *)(param_1 + 0x51d) == '\0') {

      fVar6 = *(float *)(param_1 + 0x510) - param_2;

      *(float *)(param_1 + 0x510) = fVar6;

      if (fVar6 < 0.0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 0;

      }

    }

    else {

      if (*(float *)(param_1 + 0x510) <= DAT_00af9308 && DAT_00af9308 != *(float *)(param_1 + 0x510)

         ) {

        *(float *)(param_1 + 0x510) =

             (fVar7 / _DAT_00af9310) * param_2 + *(float *)(param_1 + 0x510);

      }

      if ((fVar6 <= *(float *)(param_1 + 0x510)) &&

         (*(float *)(param_1 + 0x510) = fVar6, *(char *)(param_1 + 0x51f) != '\0')) {

        *(uint8_t *)(param_1 + 0x51d) = 0;

      }

    }

    if (*(int **)(param_1 + 0x534) == (int *)0x0) goto LAB_008672ea;

    uVar4 = *(uint *)(param_1 + 0x518);

    if (*(float *)(param_1 + 0x510) <= fVar7 && fVar7 != *(float *)(param_1 + 0x510)) {

      uVar4 = (uint)(((float)(int)uVar4 / fVar7) * *(float *)(param_1 + 0x510));

    }

    fStack_18 = 0.0;

    uStack_1c = 0x86728c;

    iVar2 = (**(code **)(**(int **)(param_1 + 0x534) + 0x164))();

  }

  if (*(byte *)(iVar2 + 3) != uVar4) {

    fStack_18 = 0.0;

    uStack_1c = 0x8672d9;

    iVar2 = (**(code **)(**(int **)(param_1 + 0x534) + 0x164))();

    *(char *)(iVar2 + 3) = (char)uVar4;

    uStack_1c = 0x8672ea;

    (**(code **)(**(int **)(param_1 + 0x534) + 0x34c))();

  }

LAB_008672ea:

  iVar2 = *(int *)(param_1 + 0x530);

  if (iVar2 != 0) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 400) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x520);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x194) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x524);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x198) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x528);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x19c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c);

    fStack_18 = 0.0;

    uStack_1c = 1;

    puStack_20 = auStack_8;

    uStack_24 = 0x867330;

    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x530) + 0x120))();

    piVar1 = (int *)(*(int *)(param_1 + 0x530) + 400);

    *piVar1 = *piVar1 - *piVar3;

    uStack_24 = 0;

    uStack_28 = 1;

    puStack_2c = &stack0xffffffec;

    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x530) + 0x120))();

    piVar1 = (int *)(*(int *)(param_1 + 0x530) + 0x198);

    *piVar1 = *piVar1 - *piVar3;

    piVar1 = *(int **)(param_1 + 0x530);

    iVar2 = (**(code **)(*piVar1 + 0x120))(&puStack_20,1,0);

    piVar1 = piVar1 + 0x65;

    *piVar1 = *piVar1 - *(int *)(iVar2 + 4);

    piVar1 = *(int **)(param_1 + 0x530);

    iVar2 = (**(code **)(*piVar1 + 0x120))(&puStack_2c,1,0);

    piVar1 = piVar1 + 0x67;

    *piVar1 = *piVar1 - *(int *)(iVar2 + 4);

  }

  iVar2 = *(int *)(param_1 + 0x534);

  if (iVar2 != 0) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 400) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x520);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x194) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x524);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x198) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x528);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x19c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c);

    fStack_18 = 0.0;

    uStack_1c = 1;

    puStack_20 = auStack_8;

    uStack_24 = 0x8673ed;

    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x534) + 0x120))();

    piVar1 = (int *)(*(int *)(param_1 + 0x534) + 400);

    *piVar1 = *piVar1 - *piVar3;

    uStack_24 = 0;

    uStack_28 = 1;

    puStack_2c = &stack0xffffffec;

    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x534) + 0x120))();

    piVar1 = (int *)(*(int *)(param_1 + 0x534) + 0x198);

    *piVar1 = *piVar1 - *piVar3;

    piVar1 = *(int **)(param_1 + 0x534);

    iVar2 = (**(code **)(*piVar1 + 0x120))(&puStack_20,1,0);

    piVar1 = piVar1 + 0x65;

    *piVar1 = *piVar1 - *(int *)(iVar2 + 4);

    piVar1 = *(int **)(param_1 + 0x534);

    iVar2 = (**(code **)(*piVar1 + 0x120))(&puStack_2c,1,0);

    piVar1 = piVar1 + 0x67;

    *piVar1 = *piVar1 - *(int *)(iVar2 + 4);

  }

  iVar2 = *(int *)(param_1 + 0x538);

  if (iVar2 != 0) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 400) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x520);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x194) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x524);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x198) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x528);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x19c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c);

    fStack_18 = 0.0;

    uStack_1c = 1;

    puStack_20 = auStack_8;

    uStack_24 = 0x8674aa;

    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x538) + 0x120))();

    piVar1 = (int *)(*(int *)(param_1 + 0x538) + 400);

    *piVar1 = *piVar1 - *piVar3;

    uStack_24 = 0;

    uStack_28 = 1;

    puStack_2c = &stack0xffffffec;

    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x538) + 0x120))();

    piVar1 = (int *)(*(int *)(param_1 + 0x538) + 0x198);

    *piVar1 = *piVar1 - *piVar3;

    piVar1 = *(int **)(param_1 + 0x538);

    iVar2 = (**(code **)(*piVar1 + 0x120))(&puStack_20,1,0);

    piVar1 = piVar1 + 0x65;

    *piVar1 = *piVar1 - *(int *)(iVar2 + 4);

    piVar1 = *(int **)(param_1 + 0x538);

    iVar2 = (**(code **)(*piVar1 + 0x120))(&puStack_2c,1,0);

    piVar1 = piVar1 + 0x67;

    *piVar1 = *piVar1 - *(int *)(iVar2 + 4);

  }

  fStack_18 = param_2;

  uStack_1c = 0x86752d;

  FUN_00791f30();

  return;

}
