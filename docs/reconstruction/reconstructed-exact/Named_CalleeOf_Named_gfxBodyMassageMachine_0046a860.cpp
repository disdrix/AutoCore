// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_0046a860
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a860
// Callee of Named_gfxBodyMassageMachine
// Address:   0x0046a860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00426f20, FUN_0046a860.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine
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

void __fastcall Named_CalleeOf_Named_gfxBodyMassageMachine_0046a860(uint32_t /* width from decompiler */ param_1)



{

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 4) != 0) {

    FUN_00426f20(param_1);

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 4));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  return;

}
