// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_004579d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004579d0
// Callee of Named_gfxDeviceVB
// Address:   0x004579d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004579d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB
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

void __fastcall Named_CalleeOf_Named_gfxDeviceVB_004579d0(uint32_t /* width from decompiler */ *param_1)



{

  if ((void *)param_1[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[2]);

  }

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  *param_1 = &PTR_LAB_009cd118;

  return;

}
