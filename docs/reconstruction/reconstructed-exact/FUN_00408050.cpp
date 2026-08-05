// =============================================================================
// FUN_00408050
// -----------------------------------------------------------------------------
// Stable ID: aa_00408050
// Address:   0x00408050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00408050 @ 0x00408050
// Stable ID: aa_00408050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, for×1.
//  - Notable callees: FUN_00406e50×2, FUN_00409ae0×2, FUN_0040a520×2, FUN_00408050, FUN_00409b00, FUN_00409b20, FUN_00418130, FUN_00437d80.
//  - Return sites: 3.

// READABILITY:
// Control-flow (from raw @ 0x00408050; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_00408050(int param_1,undefined4 *param_2,int param_3,uint param_4)`.
//  - Loops: for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1).
//  - Branches: if (iVar4 == 0); if (param_4 != 0); if (iVar4 == 0); if (0x6666666U - iVar2 < param_4); if (iVar4 == 0).
//  - Calls: FUN_00418130(); FUN_00437d80(); operator_new(local_24); FUN_00409ae0(*(param_1 + 4),param_3); FUN_00406e50(local_58); operator_delete(pvVar1).
//  - Returns (2 site(s)): `void`.




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

void __fastcall FUN_00408050(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint param_4)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint extraout_ECX;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ local_58 [10];

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  int local_28;

  uint local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd120;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff9c;

  puVar7 = local_58;

  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar7 = *param_2;

    param_2 = param_2 + 1;

    puVar7 = puVar7 + 1;

  }

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar4) / 0x28;

  }

  if (param_4 != 0) {

    if (iVar4 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar4) / 0x28;

    }

    uVar5 = param_4;

    ExceptionList = &local_10;

    if (0x6666666U - iVar2 < param_4) {

      ExceptionList = &local_10;

      FUN_00418130();

      uVar5 = extraout_ECX;

    }

    if (iVar4 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar4) / 0x28;

    }

    if (uVar6 < iVar2 + uVar5) {

      if (0x6666666 - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - iVar4) / 0x28;

      }

      if (uVar6 < iVar4 + uVar5) {

        iVar4 = FUN_00437d80();

        uVar6 = iVar4 + param_4;

      }

      local_24 = uVar6 * 0x28;

      local_1c = operator_new(local_24);

      local_8 = 0;

      local_20 = FUN_00409ae0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_3);

      local_20 = FUN_00406e50(local_58);

      FUN_00409ae0(param_3,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x28;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_1 + 0xc) = local_24 + (int)local_1c;

      *(void **)(param_1 + 8) = (void *)((int)local_1c + (param_4 + iVar4) * 0x28);

      *(void **)(param_1 + 4) = local_1c;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((uint)((iVar4 - param_3) / 0x28) < uVar5) {

      local_18 = uVar5 * 0x28;

      FUN_0040a520(param_3,local_18 + param_3,param_1,local_2c);

      local_8 = 2;

      FUN_00406e50(local_58);

      local_8 = 0xffffffff;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;

    }

    else {

      local_18 = uVar5 * 0x28;

      local_28 = iVar4 + uVar5 * -0x28;

      uVar3 = FUN_0040a520(local_28,iVar4,param_1,local_30);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

      FUN_00409b20();

    }

    FUN_00409b00();

  }

  ExceptionList = local_10;

  return;

}
