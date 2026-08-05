// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a1a30
// -----------------------------------------------------------------------------
// Stable ID: aa_006a1a30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a1a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006a0ea0×2, CONCAT31, FUN_006939f0, FUN_006a12e0, FUN_006a15e0, FUN_006a18d0, FUN_006a1a30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a1a30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009ab242;

  local_c = ExceptionList;

  uVar4 = 0;

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  local_4 = 4;

  uStack_3 = 0;

  piVar1 = (int *)FUN_006a0ea0(param_2);

  if (*piVar1 == 0) {

    FUN_006a18d0(param_2);

    FUN_006a15e0(500);

    pvVar2 = operator_new(0x5c);

    local_4 = 5;

    if (pvVar2 != (void *)0x0) {

      uVar4 = FUN_006a12e0(param_1);

    }

    _local_4 = CONCAT31(uStack_3,4);

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_006a0ea0(param_2);

    *puVar3 = uVar4;

  }

  else {

    FUN_006939f0(*piVar1);

  }

  ExceptionList = local_c;

  return param_1;

}
