// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005b71a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b71a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
// Address:   0x005b71a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005b5dc0, FUN_005b6320, FUN_005b67a0, FUN_005b6da0, FUN_005b71a0, FUN_00686120, FUN_00687150, FUN_0068a4d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005b71a0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6a1e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00687150(0x3f800000);

  if (*(int *)(param_1 + 0x50) == 0) {

    pvVar1 = operator_new(0x120);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_00686120();

    }

    local_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = uVar2;

  }

  if ((char)param_2 == '\0') {

    FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),0xf,0xffffffff,0xffffffff,0xffffffff);

  }

  FUN_005b5dc0(param_2);

  FUN_005b6320(param_2);

  FUN_005b67a0(param_2);

  FUN_005b6da0(param_2);

  ExceptionList = local_c;

  return;

}
