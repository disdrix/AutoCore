// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0046a210
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a210
// Callee of Named_CalleeOf_Named_assPackManager
// Address:   0x0046a210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_0046a210.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assPackManager
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

void Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0046a210(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  puVar1 = operator_new(0x28);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = param_1;

    puVar1[1] = param_2;

    puVar1 = puVar1 + 2;

    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar1 = *param_3;

      param_3 = param_3 + 1;

      puVar1 = puVar1 + 1;

    }

  }

  return;

}
