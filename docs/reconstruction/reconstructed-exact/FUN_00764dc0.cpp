// =============================================================================
// FUN_00764dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00764dc0
// Address:   0x00764dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00764dc0 @ 0x00764dc0
// Stable ID: aa_00764dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×2.
//  - Notable callees: FUN_0043a1d0×2, FUN_004406e0×2, FUN_007649c0×2, memmove×2, FUN_00456780, FUN_00764dc0, FUN_0096ae20.
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

void __thiscall FUN_00764dc0(int *param_1,int *param_2)



{

  int *piVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *local_24;

  uint8_t local_1c [4];

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b276e;

  local_c = ExceptionList;

  if ((((param_1[0x30] != 0) && (1 < (uint)(param_1[0x31] - param_1[0x30] >> 2))) ||

      ((param_1[0x34] != 0 && (1 < (uint)(param_1[0x35] - param_1[0x34] >> 2))))) &&

     (ExceptionList = &local_c, iVar3 = FUN_0096ae20(param_1 + 0x26), iVar3 != -1)) {

    iVar3 = *(int *)(param_1[0x29] + iVar3 * 4);

    if (param_1[0x25] == 0) {

      local_18 = (void *)0x0;

      local_14 = 0;

      local_10 = 0;

      local_4 = 0;

      piVar5 = (int *)param_1[0x30];

      if (piVar5 != (int *)param_1[0x31]) {

        local_24 = piVar5 + 1;

        do {

          piVar1 = (int *)*piVar5;

          iVar4 = (**(code **)(*piVar1 + 4))();

          if ((iVar4 == 0x47504345) && (piVar1[0x16] == *(int *)(*(int *)(iVar3 + 0xf4) + 8))) {

            memmove(piVar5,local_24,(param_1[0x31] - (int)local_24 >> 2) * 4);

            param_1[0x31] = param_1[0x31] + -4;

            FUN_004406e0();

          }

          else {

            piVar5 = piVar5 + 1;

            local_24 = local_24 + 1;

          }

        } while (piVar5 != (int *)param_1[0x31]);

      }

      FUN_007649c0(local_1c,&LAB_00437a50,param_2);

      FUN_0043a1d0(param_1[0x31],local_18,local_14,param_2);

      FUN_00456780(0);

      piVar5 = (int *)param_1[0x34];

      if (piVar5 != (int *)param_1[0x35]) {

        do {

          param_2 = (int *)*piVar5;

          iVar4 = (**(code **)(*param_2 + 4))();

          if ((iVar4 == 0x47504345) && (param_2[0x16] == *(int *)(*(int *)(iVar3 + 0xf4) + 8))) {

            memmove(piVar5,piVar5 + 1,(param_1[0x35] - (int)(piVar5 + 1) >> 2) * 4);

            param_1[0x35] = param_1[0x35] + -4;

            FUN_004406e0();

          }

          else {

            piVar5 = piVar5 + 1;

          }

        } while (piVar5 != (int *)param_1[0x35]);

      }

      FUN_007649c0(local_1c,&LAB_00437a50,0);

      pvVar2 = local_18;

      FUN_0043a1d0(param_1[0x35],local_18,local_14,param_2);

      local_4 = 0xffffffff;

      if (pvVar2 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

    }

    else {

      (**(code **)(*(int *)param_1[0x25] + 0x34))

                (*(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xf4) + 8),param_2);

    }

    (**(code **)(*param_1 + 0x50))();

  }

  ExceptionList = local_c;

  return;

}
