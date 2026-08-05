// =============================================================================
// Named_CalleeOf_Named_VOGClient_004d9b50
// -----------------------------------------------------------------------------
// Stable ID: aa_004d9b50
// Callee of Named_VOGClient (+1 other named callers)
// Address:   0x004d9b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGClient (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, for×1.
//  - Notable callees: FUN_0040ed60, FUN_0040f2a0, FUN_0040f400, FUN_0049c5f0, FUN_004bb1c0, FUN_004d9b50, memmove.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOGClient (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_VOGClient_004d9b50(int param_1)



{

  size_t _Size;

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint8_t auStack_2c [12];

  uint32_t /* width from decompiler */ *local_20;

  int local_1c;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a224c;

  local_14 = ExceptionList;

  pvVar2 = *(void **)(param_1 + 0xe760);

  ExceptionList = &local_14;

  puVar1 = (uint32_t /* width from decompiler */ *)

           FUN_0049c5f0(&local_34,*(uint32_t /* width from decompiler */ *)(param_1 + 0xe75c),pvVar2,&stack0x00000004);

  if ((void *)*puVar1 != pvVar2) {

    _Size = (*(int *)(param_1 + 0xe760) - (int)pvVar2 >> 2) * 4;

    pvVar2 = memmove((void *)*puVar1,pvVar2,_Size);

    *(void **)(param_1 + 0xe760) = (void *)((int)pvVar2 + _Size);

  }

  if (*(char *)(param_1 + 0xf6) != '\0') {

    local_20 = (uint32_t /* width from decompiler */ *)FUN_0040f400();

    *(uint8_t *)((int)local_20 + 0x15) = 1;

    local_20[1] = local_20;

    *local_20 = local_20;

    local_20[2] = local_20;

    local_1c = 0;

    local_c = 0;

    for (uVar4 = 0;

        (iVar3 = *(int *)(param_1 + 0xe75c), iVar3 != 0 &&

        (uVar4 < (uint)(*(int *)(param_1 + 0xe760) - iVar3 >> 2))); uVar4 = uVar4 + 1) {

      iVar3 = *(int *)(iVar3 + uVar4 * 4);

      local_34 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x28c))();

      uStack_30 = 0;

      FUN_0040ed60(auStack_2c,&local_34);

    }

    if (local_1c == 1) {

      iVar3 = FUN_004bb1c0(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0xe7f0),*(uint32_t /* width from decompiler */ *)(param_1 + 0xe7f4));

      if (iVar3 != 0) {

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x114))(0);

      }

    }

    local_c = 0xffffffff;

    FUN_0040f2a0(&local_34,*local_20,local_20);

                    /* WARNING: Subroutine does not return */

    operator_delete(local_20);

  }

  ExceptionList = local_14;

  return;

}
