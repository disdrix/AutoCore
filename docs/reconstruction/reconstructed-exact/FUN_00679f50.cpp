// =============================================================================
// FUN_00679f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00679f50
// Address:   0x00679f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00679f50 @ 0x00679f50
// Stable ID: aa_00679f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, for×2.
//  - Notable callees: FUN_00679a30×2, FUN_00679a80×2, FUN_00679ae0×2, FUN_00679ee0×2, FUN_00679f50, acmDriverEnum, acmDriverOpen.
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

uint32_t /* width from decompiler */ __thiscall

FUN_00679f50(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,void *param_3,int param_4,uint32_t /* width from decompiler */ *param_5,

            uint32_t /* width from decompiler */ *param_6,uint32_t /* width from decompiler */ *param_7)



{

  int iVar1;

  void *pvVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ auStack_3c8 [229];

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ *puStack_30;

  uint32_t /* width from decompiler */ *puStack_2c;

  uint32_t /* width from decompiler */ local_14;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009a95b6;

  local_c = ExceptionList;

  puStack_30 = (uint32_t /* width from decompiler */ *)&LAB_00679e70;

  ExceptionList = &local_c;

  *param_1 = param_2;

  *(uint8_t *)(param_1 + 1) = 0;

  uStack_34 = 0x679f86;

  puStack_2c = param_1;

  acmDriverEnum();

  if (*(char *)(param_1 + 1) != '\0') {

    puStack_2c = (uint32_t /* width from decompiler */ *)param_1[2];

    puStack_30 = &param_2;

    uStack_34 = 0x679fa0;

    iVar1 = acmDriverOpen();

    if (iVar1 == 0) {

      puStack_2c = &param_2;

      puStack_30 = (uint32_t /* width from decompiler */ *)0x679fb9;

      pvVar2 = (void *)FUN_00679ee0();

      puStack_2c = &param_2;

      puStack_30 = (uint32_t /* width from decompiler */ *)0x679fd0;

      param_3 = pvVar2;

      iVar1 = FUN_00679ee0();

      if ((pvVar2 != (void *)0x0) && (iVar1 != 0)) {

        puStack_2c = (uint32_t /* width from decompiler */ *)0x679ff0;

        param_4 = iVar1;

        pvVar3 = operator_new(0x428);

        puVar6 = param_7;

        local_4 = 0;

        if (pvVar3 == (void *)0x0) {

          pvVar3 = (void *)0x0;

        }

        else {

          puVar5 = param_1 + 3;

          puVar7 = auStack_3c8;

          puStack_30 = (uint32_t /* width from decompiler */ *)iVar1;

          puStack_2c = pvVar2;

          for (iVar4 = 0xe6; iVar4 != 0; iVar4 = iVar4 + -1) {

            *puVar7 = *puVar5;

            puVar5 = puVar5 + 1;

            puVar7 = puVar7 + 1;

          }

          pvVar3 = (void *)FUN_00679a30(param_2);

          pvVar2 = param_3;

        }

        puStack_2c = (uint32_t /* width from decompiler */ *)0x0;

        local_4 = 0xffffffff;

        puStack_30 = (uint32_t /* width from decompiler */ *)0x67a04a;

        iVar1 = FUN_00679ae0();

        if (-1 < iVar1) {

          *puVar6 = local_14;

          *param_5 = pvVar3;

          puStack_2c = (uint32_t /* width from decompiler */ *)0x67a068;

          param_3 = operator_new(0x428);

          local_4 = 1;

          if (param_3 == (void *)0x0) {

            pvVar2 = (void *)0x0;

          }

          else {

            puStack_30 = (uint32_t /* width from decompiler */ *)param_4;

            puVar6 = param_1 + 3;

            puVar5 = auStack_3c8;

            puStack_2c = pvVar2;

            for (iVar1 = 0xe6; iVar1 != 0; iVar1 = iVar1 + -1) {

              *puVar5 = *puVar6;

              puVar6 = puVar6 + 1;

              puVar5 = puVar5 + 1;

            }

            pvVar2 = (void *)FUN_00679a30(param_2);

          }

          puStack_2c = (uint32_t /* width from decompiler */ *)0x1;

          local_4 = 0xffffffff;

          puStack_30 = (uint32_t /* width from decompiler */ *)0x67a0c1;

          iVar1 = FUN_00679ae0();

          if (-1 < iVar1) {

            *param_6 = pvVar2;

            ExceptionList = local_c;

            return 0;

          }

          if (pvVar2 != (void *)0x0) {

            FUN_00679a80();

                    /* WARNING: Subroutine does not return */

            puStack_2c = (uint32_t /* width from decompiler */ *)&UNK_0067a0d6;

            operator_delete(pvVar2);

          }

          pvVar3 = (void *)*param_5;

        }

        if (pvVar3 != (void *)0x0) {

          FUN_00679a80();

                    /* WARNING: Subroutine does not return */

          puStack_2c = (uint32_t /* width from decompiler */ *)&UNK_0067a0f0;

          operator_delete(pvVar3);

        }

      }

    }

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
