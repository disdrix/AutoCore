// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00691720
// -----------------------------------------------------------------------------
// Stable ID: aa_00691720
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00691720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00690330, FUN_00690a10, FUN_00691720.
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00691720(int param_1,int param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009aa6e0;

  local_10 = ExceptionList;

  if (*(int *)(param_2 + 4) == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x38;

  }

  ExceptionList = &local_10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  if (uVar3 != 0) {

    if (0x4924924 < uVar3) {

      FUN_00690330();

    }

    pvVar1 = operator_new(uVar3 * 0x38);

    *(void **)(param_1 + 4) = pvVar1;

    *(void **)(param_1 + 8) = pvVar1;

    *(void **)(param_1 + 0xc) = (void *)(uVar3 * 0x38 + (int)pvVar1);

    local_8 = 0;

    uVar2 = FUN_00690a10(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),pvVar1,param_1,

                         param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

  }

  ExceptionList = local_10;

  return param_1;

}
