// =============================================================================
// FUN_007ce130
// -----------------------------------------------------------------------------
// Stable ID: aa_007ce130
// Address:   0x007ce130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ce130 @ 0x007ce130
// Stable ID: aa_007ce130
// Embedded strings (evidence for future rename):
//   - "//tLootRarity/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×13, do×3, while×3, return×2.
//  - Notable callees: block×11, FUN_004231d0×3, _com_issue_error×3, CONCAT31×2, FUN_0041c000×2, FUN_00423170×2, FUN_007a4480×2, FUN_004048e0.
//  - Strings: "//tLootRarity/row".
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

/* WARNING: Removing unreachable block (ram,0x007ce4c4) */

/* WARNING: Removing unreachable block (ram,0x007ce447) */

/* WARNING: Removing unreachable block (ram,0x007ce41a) */

/* WARNING: Removing unreachable block (ram,0x007ce432) */

/* WARNING: Removing unreachable block (ram,0x007ce44d) */

/* WARNING: Removing unreachable block (ram,0x007ce475) */

/* WARNING: Removing unreachable block (ram,0x007ce48a) */

/* WARNING: Removing unreachable block (ram,0x007ce490) */

/* WARNING: Removing unreachable block (ram,0x007ce4af) */

/* WARNING: Removing unreachable block (ram,0x007ce4ca) */

/* WARNING: Removing unreachable block (ram,0x007ce514) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_007ce130(char *param_1,uint16_t *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  char *pcVar4;

  int iVar5;

  ULONG UVar6;

  IUnknown *unaff_EBX;

  IUnknown *This;

  IUnknown *local_98;

  int local_90;

  uint8_t *local_8c;

  uint32_t /* width from decompiler */ local_84;

  uint32_t /* width from decompiler */ local_80;

  int *local_7c;

  uint32_t /* width from decompiler */ local_78;

  int local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ *local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  BSTR local_58;

  BSTR local_54;

  char local_50 [64];

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae83d;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    uVar2 = 0x80004004;

  }

  else {

    if (DAT_00d1793c == '\0') {

      local_6c = &local_84;

      local_84 = 0;

      local_80 = 0;

      local_7c = (int *)0x0;

      local_78 = 0;

      local_74 = 0;

      local_70 = 0;

      local_64 = 0;

      local_68 = 0;

      local_60 = 0;

      local_5c = 0;

      local_4 = 0;

      ExceptionList = &local_c;

      iVar3 = FUN_0041a810(local_6c,param_1 + 0x28,0);

      local_7c = &local_90;

      if ((((iVar3 < 0) || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

          (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

         ((iVar3 = FUN_004231d0(), iVar3 < 0 || (local_74 == 0)))) {

        FUN_00423170();

        FUN_007a4480();

      }

      else {

        iVar3 = FUN_0041c000();

        if (iVar3 == 0) {

          iVar3 = 0;

          do {

            if (8 < iVar3) {

              FUN_007a4480();

            }

            *param_2 = (uint16_t)local_90;

            pcVar4 = local_50;

            do {

              cVar1 = *pcVar4;

              pcVar4[(2 - (int)local_50) + (int)param_2] = cVar1;

              pcVar4 = pcVar4 + 1;

            } while (cVar1 != '\0');

            *(BSTR *)(param_2 + 0x22) = local_58;

            iVar3 = iVar3 + 1;

            param_2 = param_2 + 0x24;

            iVar5 = FUN_0041c000();

          } while (iVar5 == 0);

        }

        if (local_74 != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

      }

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      ExceptionList = &local_c;

      local_54 = SysAllocString(L"//tLootRarity/row");

      if (local_54 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

      local_8c = &stack0xffffff50;

      local_4 = 1;

      FUN_00419ca0();

      local_4._0_1_ = 2;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_4._0_1_ = 1;

      FUN_00419ed0();

      local_4 = CONCAT31(local_4._1_3_,4);

      if (local_98 == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_8c = (uint8_t *)0x0;

      UVar6 = (*local_98->lpVtbl[2].Release)(local_98);

      if ((int)UVar6 < 0) {

        _com_issue_errorex(UVar6,local_98,(_GUID *)&DAT_00a86118);

      }

      local_8c = (uint8_t *)0x0;

      This = unaff_EBX;

      if (0 < local_90) {

        do {

          _com_issue_error(-0x7fffbffd);

          if (This != (IUnknown *)0x0) {

            (*This->lpVtbl->Release)(This);

          }

          (**(code **)(_DAT_00000000 + 0x1c))();

          unaff_EBX = (IUnknown *)0x0;

          local_8c = (uint8_t *)((int)local_8c + 1);

          This = (IUnknown *)0x0;

        } while ((int)local_8c < local_90);

      }

      puStack_8._0_1_ = 3;

      if (unaff_EBX != (IUnknown *)0x0) {

        (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

      }

      puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

      SysFreeString(local_58);

    }

    uVar2 = 0;

  }

  ExceptionList = pvStack_10;

  return uVar2;

}
