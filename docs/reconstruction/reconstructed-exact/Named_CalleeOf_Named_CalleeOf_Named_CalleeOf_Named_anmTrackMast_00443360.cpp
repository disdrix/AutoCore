// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmTrackMast_00443360
// -----------------------------------------------------------------------------
// Stable ID: aa_00443360
// Callee of Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl (+1 other named callers)
// Address:   0x00443360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00443360.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmTrackMast_00443360(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  for (; in_EAX != param_1; in_EAX = in_EAX + 5) {

    *in_EAX = *param_2;

    in_EAX[1] = param_2[1];

    in_EAX[2] = param_2[2];

    in_EAX[3] = param_2[3];

    in_EAX[4] = param_2[4];

  }

  return;

}
