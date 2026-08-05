// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_004ce940
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce940
// Callee of CVOGReaction_Dispatch
// Address:   0x004ce940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004ce940, FUN_0050c1b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch
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

void Named_CalleeOf_CVOGReaction_Dispatch_004ce940(void)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1f0c;

  local_c = ExceptionList;

  if (DAT_00b037e8 == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0xbc);

    local_4 = 0;

    if (pvVar1 != (void *)0x0) {

      DAT_00b037e8 = FUN_0050c1b0(DAT_00b041fc);

      ExceptionList = pvVar1;

      return;

    }

    DAT_00b037e8 = 0;

  }

  ExceptionList = local_c;

  return;

}
