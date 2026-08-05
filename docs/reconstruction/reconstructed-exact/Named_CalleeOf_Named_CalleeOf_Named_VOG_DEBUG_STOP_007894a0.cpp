// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_007894a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007894a0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x007894a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007894a0.
//  - Return sites: 2.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_007894a0(uint32_t /* width from decompiler */ param_1)



{

  int *unaff_ESI;

  int unaff_EDI;

  

  if ((unaff_ESI != (int *)0x0) && (unaff_EDI != 0)) {

    (**(code **)(*unaff_ESI + 0x1d8))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),1,param_1);

    (**(code **)(*unaff_ESI + 0x15c))(0,unaff_EDI + 0x10);

    (**(code **)(*unaff_ESI + 0x15c))(1,unaff_EDI + 0x14);

    (**(code **)(*unaff_ESI + 0x15c))(2,unaff_EDI + 0x18);

    (**(code **)(*unaff_ESI + 0x1b4))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc));

                    /* WARNING: Could not recover jumptable at 0x007894fb. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*unaff_ESI + 0x34c))();

    return;

  }

  return;

}
