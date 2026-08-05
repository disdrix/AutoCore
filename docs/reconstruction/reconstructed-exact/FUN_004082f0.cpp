// =============================================================================
// FUN_004082f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004082f0
// Address:   0x004082f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004082f0 @ 0x004082f0
// Stable ID: aa_004082f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: FUN_00406ee0×2, FUN_00409b40×2, FUN_0040a590×2, FUN_004082f0, FUN_00418130, FUN_0042ac90, FUN_00480c80, FUN_00480fb0.
//  - Return sites: 3.

// READABILITY:
// Control-flow (from raw @ 0x004082f0; evidence only — no invented semantics):
//  - Entry: `void __thiscall FUN_004082f0(int param_1,int param_2,uint param_3,undefined4 *param_4)`.
//  - Branches: if (iVar4 == 0); if (param_3 != 0); if (iVar4 == 0); if (0x15555555U - iVar3 < param_3); if (iVar4 == 0).
//  - Calls: FUN_00418130(); FUN_00480c80(); operator_new(local_24); FUN_00409b40(*(param_1 + 4),param_2); FUN_00406ee0(&local_3c); operator_delete(pvVar1).
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

void __thiscall FUN_004082f0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint8_t *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint extraout_ECX;

  uint uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

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

  puStack_c = &LAB_009bd110;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffb8;

  local_3c = *param_4;

  local_38 = param_4[1];

  local_34 = param_4[2];

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = (*(int *)(param_1 + 0xc) - iVar4) / 0xc;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - iVar4) / 0xc;

    }

    uVar6 = param_3;

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffb8;

    if (0x15555555U - iVar3 < param_3) {

      ExceptionList = &local_10;

      FUN_00418130();

      uVar6 = extraout_ECX;

      puVar2 = local_14;

    }

    local_14 = puVar2;

    if (iVar4 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - iVar4) / 0xc;

    }

    if (uVar7 < iVar3 + uVar6) {

      if (0x15555555 - (uVar7 >> 1) < uVar7) {

        uVar7 = 0;

      }

      else {

        uVar7 = uVar7 + (uVar7 >> 1);

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - iVar4) / 0xc;

      }

      if (uVar7 < iVar4 + uVar6) {

        iVar4 = FUN_00480c80();

        uVar7 = iVar4 + param_3;

      }

      local_24 = uVar7 * 0xc;

      local_1c = operator_new(local_24);

      local_8 = 0;

      local_20 = FUN_00409b40(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2);

      local_20 = FUN_00406ee0(&local_3c);

      FUN_00409b40(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0xc;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_1 + 0xc) = local_24 + (int)local_1c;

      *(void **)(param_1 + 8) = (void *)((int)local_1c + (param_3 + iVar4) * 0xc);

      *(void **)(param_1 + 4) = local_1c;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((uint)((iVar4 - param_2) / 0xc) < uVar6) {

      local_18 = uVar6 * 0xc;

      FUN_0040a590(param_2,local_18 + param_2,param_1,local_2c);

      local_8 = 2;

      FUN_00406ee0(&local_3c);

      local_8 = 0xffffffff;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;

    }

    else {

      local_18 = uVar6 * 0xc;

      local_28 = iVar4 + uVar6 * -0xc;

      uVar5 = FUN_0040a590(local_28,iVar4,param_1,local_30);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

      FUN_00480fb0();

    }

    FUN_0042ac90();

  }

  ExceptionList = local_10;

  return;

}
