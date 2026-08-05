// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCraftFr_00403980
// -----------------------------------------------------------------------------
// Stable ID: aa_00403980
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCraftFromAssemblyKitRe
// Address:   0x00403980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvCraftFromAssemblyKitRe: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_00404510×4, FUN_00404130×2, FUN_00404530×2, FUN_00403960, FUN_00403980, FUN_00418130, FUN_00421ee0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCraftFromAssemblyKitRe
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCraftFr_00403980(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ local_c0 [38];

  uint local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd1f0;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff34;

  puVar5 = local_c0;

  for (iVar4 = 0x26; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = *param_4;

    param_4 = param_4 + 1;

    puVar5 = puVar5 + 1;

  }

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    local_28 = 0;

  }

  else {

    local_28 = (*(int *)(param_1 + 0xc) - iVar4) / 0x98;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar4) / 0x98;

    }

    ExceptionList = &local_10;

    if (0x1af286bU - iVar2 < param_3) {

      ExceptionList = &local_10;

      FUN_00418130();

      local_28 = extraout_ECX;

    }

    if (iVar4 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar4) / 0x98;

    }

    if (local_28 < iVar2 + param_3) {

      if (0x1af286b - (local_28 >> 1) < local_28) {

        local_28 = 0;

      }

      else {

        local_28 = local_28 + (local_28 >> 1);

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - iVar4) / 0x98;

      }

      if (local_28 < iVar4 + param_3) {

        iVar4 = FUN_00403960();

        local_28 = iVar4 + param_3;

      }

      local_28 = local_28 * 0x98;

      local_1c = operator_new(local_28);

      local_8 = 0;

      local_20 = FUN_00404510(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,local_1c);

      local_20 = FUN_00404130(local_20,param_3,local_c0);

      FUN_00404510(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_20);

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x98;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint *)(param_1 + 0xc) = local_28 + (int)local_1c;

      *(void **)(param_1 + 8) = (void *)((int)local_1c + (param_3 + iVar4) * 0x98);

      *(void **)(param_1 + 4) = local_1c;

      ExceptionList = local_10;

      return;

    }

    local_24 = *(int *)(param_1 + 8);

    if ((uint)((local_24 - param_2) / 0x98) < param_3) {

      local_18 = param_3 * 0x98;

      FUN_00404510(param_2,local_24,local_18 + param_2);

      local_8 = 2;

      FUN_00404130(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x98,local_c0

                  );

      local_8 = 0xffffffff;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;

      FUN_00404530(param_2,*(int *)(param_1 + 8) - local_18,local_c0);

      ExceptionList = local_10;

      return;

    }

    local_18 = param_3 * 0x98;

    iVar4 = local_24 + param_3 * -0x98;

    uVar3 = FUN_00404510(iVar4,local_24,local_24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    FUN_00421ee0(param_2,iVar4,local_24);

    FUN_00404530(param_2,local_18 + param_2,local_c0);

  }

  ExceptionList = local_10;

  return;

}
