// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068a4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068a4d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068a4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00688100, FUN_00688390, FUN_00688e90, FUN_00689950, FUN_00689b70, FUN_0068a4d0.
//  - Return sites: 2.

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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068a4d0(int param_1,uint32_t /* width from decompiler */ param_2,byte param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009aa192;

  local_10 = ExceptionList;

  local_8 = 0;

  ExceptionList = &local_10;

  if ((param_3 & 1) != 0) {

    ExceptionList = &local_10;

    FUN_00689950(param_2,param_4);

  }

  if ((param_3 & 2) != 0) {

    FUN_00689b70(param_2,param_5);

  }

  if ((param_3 & 4) != 0) {

    FUN_00688100(param_2,param_6);

  }

  if ((param_3 & 8) != 0) {

    if ((*(char *)(param_1 + 0x68) != '\0') && ((param_3 & 0x10) == 0)) {

      FUN_00688e90(param_2);

      ExceptionList = local_10;

      return;

    }

    FUN_00688390(param_2);

  }

  ExceptionList = local_10;

  return;

}
