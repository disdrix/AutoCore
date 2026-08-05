// =============================================================================
// FUN_0050ba90
// -----------------------------------------------------------------------------
// Stable ID: aa_0050ba90
// Address:   0x0050ba90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0050ba90 @ 0x0050ba90
// Stable ID: aa_0050ba90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×1, while×1.
//  - Notable callees: FUN_00420ab0×2, FUN_005114e0×2, CONCAT31, FUN_0050ba90, FUN_0050f3e0, FUN_00511b40, FUN_00608720.
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

FUN_0050ba90(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            int *param_6)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int local_54 [2];

  int local_4c;

  uint8_t local_48 [4];

  uint8_t local_44 [4];

  void *local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  int local_34;

  uint8_t local_30 [4];

  void *local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  int local_20 [2];

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a32d9;

  local_c = ExceptionList;

  iVar4 = (int)(short)param_3;

  if (iVar4 < param_3 >> 0x10) {

    local_4c = param_1 + 0x80 + (int)param_6 * 0xc;

    ExceptionList = &local_c;

    param_6 = (int *)(param_1 + ((int)param_6 * 3 + 0x21) * 4);

    do {

      local_54[0] = iVar4;

      piVar3 = (int *)FUN_0050f3e0(local_48,local_54);

      iVar1 = *piVar3;

      if (iVar1 == *param_6) {

        local_40 = (void *)0x0;

        local_3c = 0;

        local_38 = 0;

        local_4 = 0;

        FUN_00420ab0(0,1,&param_2);

        local_34 = iVar4;

        FUN_005114e0(local_44);

        local_20[0] = local_34;

        local_4._0_1_ = 1;

        FUN_005114e0(local_30);

        local_4 = CONCAT31(local_4._1_3_,2);

        FUN_00511b40(local_54,local_20);

        if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_18);

        }

        local_18 = (void *)0x0;

        local_14 = 0;

        local_10 = 0;

        if (local_2c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_2c);

        }

        local_2c = (void *)0x0;

        local_28 = 0;

        local_24 = 0;

        local_4 = 0xffffffff;

        if (local_40 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_40);

        }

        local_40 = (void *)0x0;

        local_3c = 0;

        local_38 = 0;

      }

      else {

        iVar2 = *(int *)(iVar1 + 0x14);

        if ((iVar2 == 0) ||

           ((uint)(*(int *)(iVar1 + 0x1c) - iVar2 >> 4) <=

            (uint)(*(int *)(iVar1 + 0x18) - iVar2 >> 4))) {

          FUN_00420ab0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x18),1,&param_2);

        }

        else {

          iVar2 = *(int *)(iVar1 + 0x18);

          FUN_00608720(iVar2,1,&param_2,iVar1 + 0x10,param_6);

          *(int *)(iVar1 + 0x18) = iVar2 + 0x10;

        }

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < param_3._2_2_);

  }

  ExceptionList = local_c;

  return;

}
