// =============================================================================
// FUN_004d7e30
// -----------------------------------------------------------------------------
// Stable ID: aa_004d7e30
// Address:   0x004d7e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d7e30 @ 0x004d7e30
// Stable ID: aa_004d7e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, goto×3, while×1.
//  - Notable callees: FUN_004bb070, FUN_004d78e0, FUN_004d7e30, FUN_004e1600.
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

char __thiscall

FUN_004d7e30(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int *param_4,int *param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,uint param_9,uint param_10,

            uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ param_12,uint32_t /* width from decompiler */ *param_13)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  void *pvVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if ((param_5 == (int *)0x0) || (cVar1 = (**(code **)(*param_5 + 0x198))(), cVar1 != '\0')) {

    return '\0';

  }

  cVar1 = FUN_004d78e0(param_2,param_3,param_4,param_5,param_7,param_8,param_9,param_10,param_11,

                       param_12,param_13);

  if ((*(char *)(param_1 + 0x7e) == '\0') && ((char)param_8 == '\0')) {

    return cVar1;

  }

  puVar2 = operator_new(0x28);

  puVar6 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2[9] = 0;

    puVar6 = puVar2;

  }

  *(uint8_t *)(puVar6 + 8) = (uint8_t)param_7;

  if (param_4 == (int *)0x0) {

    param_4 = &DAT_009cbf68;

  }

  else {

    piVar5 = param_4;

    if (*(int *)(param_4[0x2a] + 0x38) == 0x12) {

      while (*(int *)(piVar5[0x2a] + 0x38) == 0x12) {

        iVar3 = (**(code **)(*piVar5 + 0x1d8))();

        uStack_10 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x228);

        uStack_c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x22c);

        uStack_8 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x230);

        uStack_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x234);

        iVar3 = FUN_004bb070(&uStack_10);

        if ((iVar3 == 0) ||

           (piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3), piVar5 == (int *)0x0))

        goto LAB_004d7f45;

      }

      if (*(int *)(piVar5[0x2a] + 0x38) == 0x14) {

        param_4 = piVar5 + 0x58;

        puVar6[4] = *param_4;

        puVar6[5] = piVar5[0x59];

        iVar3 = piVar5[0x5a];

        goto LAB_004d7faa;

      }

LAB_004d7f45:

      puVar6[4] = param_4[0x58];

      puVar6[5] = param_4[0x59];

      puVar6[6] = param_4[0x5a];

      iVar3 = param_4[0x5b];

      goto LAB_004d7fb0;

    }

    param_4 = param_4 + 0x58;

  }

  puVar6[4] = *param_4;

  puVar6[5] = param_4[1];

  iVar3 = param_4[2];

LAB_004d7faa:

  puVar6[6] = iVar3;

  iVar3 = param_4[3];

LAB_004d7fb0:

  puVar2 = puVar6 + 4;

  puVar6[7] = iVar3;

  if (((param_9 & param_10) != 0xffffffff) || ((char)param_11 != '\0')) {

    puVar2 = &param_9;

  }

  *puVar6 = *puVar2;

  puVar6[1] = puVar2[1];

  puVar6[2] = puVar2[2];

  puVar6[3] = puVar2[3];

  *(uint16_t *)((int)puVar6 + 0x22) = 1;

  pvVar4 = operator_new__(0x20);

  puVar6[9] = pvVar4;

  *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x16) = 0;

  *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x1a) = 0;

  *(uint8_t *)((int)pvVar4 + 0x1e) = 0;

  if (cVar1 == '\0') {

    *(uint8_t *)(puVar6[9] + 0x14) = 0;

  }

  else {

    *(uint8_t *)(puVar6[9] + 0x14) = 1;

  }

  piVar5 = (int *)puVar6[9];

  *piVar5 = param_5[0x58];

  piVar5[1] = param_5[0x59];

  piVar5[2] = param_5[0x5a];

  piVar5[3] = param_5[0x5b];

  *(uint32_t /* width from decompiler */ *)(puVar6[9] + 0x10) = param_3;

  *(uint8_t *)(puVar6[9] + 0x15) = (uint8_t)param_2;

  if (param_13 != (uint32_t /* width from decompiler */ *)0x0) {

    *(uint8_t *)(puVar6[9] + 0x1c) = *(uint8_t *)((int)param_13 + 6);

    *(uint8_t *)(puVar6[9] + 0x1d) = *(uint8_t *)((int)param_13 + 7);

    *(uint8_t *)(puVar6[9] + 0x1e) = *(uint8_t *)(param_13 + 2);

    iVar3 = puVar6[9];

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x16) = *param_13;

    *(uint16_t *)(iVar3 + 0x1a) = *(uint16_t *)(param_13 + 1);

  }

  FUN_004e1600(puVar6);

  return cVar1;

}
