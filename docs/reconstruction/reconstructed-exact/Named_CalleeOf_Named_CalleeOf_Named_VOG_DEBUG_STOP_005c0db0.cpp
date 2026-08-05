// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005c0db0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c0db0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x005c0db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_00414c20, FUN_005c0db0, FUN_007464e0, FUN_00746520, FUN_007478c0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005c0db0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  void *pvVar1;

  int iVar2;

  uint8_t local_24 [4];

  void *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6c9a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new__(param_3 * 4);

  *(void **)(param_1 + 200) = pvVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc) = 0;

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

  local_20 = (void *)0x0;

  local_1c = 0;

  local_18 = 0;

  local_4 = 0;

  local_14 = 0;

  local_10 = 0;

  FUN_007478c0(0x1d2);

  local_4 = 1;

  iVar2 = FUN_00414c20(param_3 * 6,local_24,0x20,0);

  local_4 = 0xffffffff;

  local_14 = 0;

  local_10 = 0;

  if (local_20 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_20);

  }

  local_20 = (void *)0x0;

  local_1c = 0;

  local_18 = 0;

  if (-1 < iVar2) {

    iVar2 = *(int *)(param_1 + 0x14);

    if (*(int *)(iVar2 + 0x10) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x18),0);

    }

    *(int *)(param_1 + 0xd0) = iVar2;

    if (iVar2 != 0) {

      ExceptionList = local_c;

      return 1;

    }

    if (*(int *)(*(int *)(param_1 + 0x14) + 0x10) != 0) {

      FUN_007464e0();

    }

  }

  ExceptionList = local_c;

  return 0;

}
