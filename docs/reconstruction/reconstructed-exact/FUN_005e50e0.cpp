// =============================================================================
// FUN_005e50e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e50e0
// Address:   0x005e50e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e50e0 @ 0x005e50e0
// Stable ID: aa_005e50e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_005e4f50×4, FUN_005e4df0×2, FUN_005e4d40, FUN_005e4d70, FUN_005e4e20, FUN_005e4e90, FUN_005e4fe0, FUN_005e50b0.
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

void __thiscall FUN_005e50e0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  int iVar6;

  uint8_t local_50 [60];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a75d0;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffa4;

  ExceptionList = &local_10;

  FUN_005e4e20(param_4);

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x3c;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x3c;

    }

    if (0x4444444U - iVar2 < param_3) {

      FUN_005e4d70();

      uVar5 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x3c;

    }

    if (uVar5 < iVar2 + param_3) {

      if (0x4444444 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x3c;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_005e4d40();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x3c);

      local_8 = 0;

      iVar2 = FUN_005e4f50(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_005e4fe0(iVar2,param_3,local_50,param_1,param_2);

      FUN_005e4f50(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x3c,param_1,param_2);

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x3c;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x3c + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar2) * 0x3c);

      *(void **)(param_1 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    iVar2 = *(int *)(param_1 + 8);

    iVar1 = param_3 * 0x3c;

    if ((uint)((iVar2 - param_2) / 0x3c) < param_3) {

      FUN_005e4f50(param_2,iVar2,iVar1 + param_2,param_1,param_2);

      local_8 = 2;

      FUN_005e50b0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x3c,

                   local_50);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;

      FUN_005e4df0(param_2,*(int *)(param_1 + 8) + param_3 * -0x3c,local_50);

      ExceptionList = local_10;

      return;

    }

    iVar6 = iVar2 + param_3 * -0x3c;

    uVar4 = FUN_005e4f50(iVar6,iVar2,iVar2,param_1,param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    FUN_005e4e90(param_2,iVar6,iVar2);

    FUN_005e4df0(param_2,iVar1 + param_2,local_50);

  }

  ExceptionList = local_10;

  return;

}
