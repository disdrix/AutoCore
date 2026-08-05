// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_SendLogicUiPacket_004076a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004076a0
// Callee of Named_CalleeOf_Client_SendLogicUiPacket
// Address:   0x004076a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_SendLogicUiPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_00409a70×4, FUN_00406970×2, FUN_00409a90×2, FUN_004059c0, FUN_004076a0, FUN_00408880, FUN_00409ac0, FUN_00418130.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_SendLogicUiPacket
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_SendLogicUiPacket_004076a0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint extraout_ECX;

  uint8_t local_164 [312];

  uint32_t /* width from decompiler */ local_2c;

  int local_28;

  int local_24;

  uint local_20;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be300;

  local_10 = ExceptionList;

  local_14 = &stack0xfffffe90;

  ExceptionList = &local_10;

  FUN_00408880(param_4);

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    local_20 = 0;

  }

  else {

    local_20 = (*(int *)(param_1 + 0xc) - iVar2) / 0x138;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x138;

    }

    if ((uint)((int)&DAT_00d20d20 - iVar2) < param_3) {

      FUN_00418130();

      local_20 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x138;

    }

    if (local_20 < iVar2 + param_3) {

      if ((int)&DAT_00d20d20 - (local_20 >> 1) < local_20) {

        local_20 = 0;

      }

      else {

        local_20 = local_20 + (local_20 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x138;

      }

      if (local_20 < iVar2 + param_3) {

        iVar2 = FUN_004059c0();

        local_20 = iVar2 + param_3;

      }

      local_20 = local_20 * 0x138;

      local_1c = operator_new(local_20);

      local_8 = 0;

      local_2c = FUN_00409a70(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,local_1c);

      local_2c = FUN_00406970(local_2c,param_3,local_164);

      FUN_00409a70(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_2c);

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x138;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_1 + 0xc) = local_20 + (int)local_1c;

      *(void **)(param_1 + 8) = (void *)((int)local_1c + (param_3 + iVar2) * 0x138);

      *(void **)(param_1 + 4) = local_1c;

      ExceptionList = local_10;

      return;

    }

    local_28 = *(int *)(param_1 + 8);

    local_24 = local_28 - param_2;

    if ((uint)(local_24 / 0x138) < param_3) {

      local_18 = param_3 * 0x138;

      FUN_00409a70(param_2,local_28,local_18 + param_2);

      local_8 = 2;

      FUN_00406970(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x138,

                   local_164);

      local_8 = 0xffffffff;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;

      FUN_00409a90(param_2,*(int *)(param_1 + 8) - local_18,local_164);

      ExceptionList = local_10;

      return;

    }

    local_18 = param_3 * 0x138;

    iVar2 = local_28 + param_3 * -0x138;

    uVar3 = FUN_00409a70(iVar2,local_28,local_28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    FUN_00409ac0(param_2,iVar2,local_28);

    FUN_00409a90(param_2,local_18 + param_2,local_164);

  }

  ExceptionList = local_10;

  return;

}
