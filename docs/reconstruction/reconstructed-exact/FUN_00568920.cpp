// =============================================================================
// FUN_00568920
// -----------------------------------------------------------------------------
// Stable ID: aa_00568920
// Address:   0x00568920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00568920 @ 0x00568920
// Stable ID: aa_00568920
// Embedded strings (evidence for future rename):
//   - "GetCloneBaseFromID failed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×7, for×3, return×2, do×2, goto×2, while×2.
//  - Notable callees: FUN_00568f20×2, CONCAT31, CoTaskMemFree, FUN_004933f0, FUN_004f1e20, FUN_00568920, FUN_00568b59, FUN_00568bc0.
//  - Strings: "GetCloneBaseFromID failed %d".
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

int __thiscall FUN_00568920(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int local_68;

  uint32_t /* width from decompiler */ local_64 [14];

  uint8_t local_2c [8];

  int local_24;

  int local_20;

  int local_1c;

  LPVOID local_18;

  uint8_t *local_14;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a4cab;

  pvStack_10 = ExceptionList;

  local_14 = &stack0xffffff8c;

  ExceptionList = &pvStack_10;

  local_24 = param_1;

  uVar2 = FUN_004933f0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  local_8 = 0;

  iVar3 = FUN_00568f20();

  *(int *)(param_1 + 0x18) = iVar3;

  *(uint8_t *)(iVar3 + 0x49) = 1;

  *(int *)(*(int *)(param_1 + 0x18) + 4) = *(int *)(param_1 + 0x18);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

  *(int *)(*(int *)(param_1 + 0x18) + 8) = *(int *)(param_1 + 0x18);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  local_8._0_1_ = 1;

  iVar3 = FUN_00568f20();

  *(int *)(param_1 + 0x24) = iVar3;

  *(uint8_t *)(iVar3 + 0x49) = 1;

  *(int *)(*(int *)(param_1 + 0x24) + 4) = *(int *)(param_1 + 0x24);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  *(int *)(*(int *)(param_1 + 0x24) + 8) = *(int *)(param_1 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  DAT_00b047ac = param_2;

  local_1c = 0;

  local_18 = (LPVOID)0x0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  local_8 = CONCAT31(local_8._1_3_,3);

  if ((char)param_3 != '\0') {

    FUN_007da1b0(param_1 + 0xc);

  }

  FUN_007d65a0(&local_1c,&local_18);

  for (param_2 = 0; param_2 < local_1c; param_2 = param_2 + 1) {

    iVar3 = param_2 * 0x38;

    local_20 = iVar3;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_005697d0((LPVOID)(iVar3 + (int)local_18));

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar3 + (int)local_18);

    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar4 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar4 = puVar4 + 1;

    }

    local_68 = (int)*(short *)(local_20 + 0x12 + (int)local_18);

    puVar6 = (uint32_t /* width from decompiler */ *)(local_20 + (int)local_18);

    puVar4 = local_64;

    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar4 = puVar4 + 1;

    }

    FUN_005692b0(local_2c,&local_68);

  }

  CoTaskMemFree(local_18);

  local_8 = 2;

  if ((char)param_3 == '\0') {

    ExceptionList = pvStack_10;

    return param_1;

  }

  param_2 = 0;

  if (0 < *(int *)(param_1 + 0xc)) {

    do {

      uVar1 = *(uint *)(*(int *)(param_1 + 0x10) + param_2 * 4);

      iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b047ac + 0xf10) + 0x10) +

                               (*(uint *)(*(int *)(DAT_00b047ac + 0xf10) + 8) & uVar1) * 4) + 4);

      if (iVar3 == 0) {

LAB_00568ab7:

        iVar3 = 0;

      }

      else {

        do {

          if (uVar1 == *(uint *)(iVar3 + 0x10)) {

            if (iVar3 == 0) goto LAB_00568ab7;

            iVar3 = *(int *)(iVar3 + 8);

            goto LAB_00568abe;

          }

          iVar3 = *(int *)(iVar3 + 0xc);

        } while (iVar3 != 0);

        iVar3 = 0;

      }

LAB_00568abe:

      if (iVar3 == 0) {

        FUN_007a4480(0,"GetCloneBaseFromID failed %d",

                     *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + param_2 * 4));

      }

      else {

        FUN_004f1e20(0,1);

        iVar3 = *(int *)(iVar3 + 0x3c);

        param_3 = operator_new(8);

        *param_3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + param_2 * 4);

        *(uint16_t *)(param_3 + 1) = *(uint16_t *)(iVar3 + 0x4ee);

        iVar3 = *(int *)(param_1 + 4);

        iVar5 = FUN_006759b0(iVar3,*(uint32_t /* width from decompiler */ *)(iVar3 + 4),&param_3);

        FUN_00568bc0(1);

        *(int *)(iVar3 + 4) = iVar5;

        **(int **)(iVar5 + 4) = iVar5;

      }

      param_2 = param_2 + 1;

    } while (param_2 < *(int *)(param_1 + 0xc));

  }

  FUN_005698c0(param_3);

  iVar3 = FUN_00568b59();

  return iVar3;

}
