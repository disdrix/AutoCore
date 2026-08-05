// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions_005e0480
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0480
// Callee of Named_CalleeOf_Mission_after_CVOGRegionMissions
// Address:   0x005e0480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_after_CVOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×13, switch×1.
//  - Notable callees: FUN_005e0480.
//  - Return sites: 13.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_after_CVOGRegionMissions
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions_005e0480(uint32_t /* width from decompiler */ param_1)



{

  switch(param_1) {

  case 6:

    return 0;

  default:

    return 0xffffffff;

  case 8:

    return 1;

  case 10:

    return 2;

  case 0xc:

    return 3;

  case 0xe:

    return 4;

  case 0x10:

    return 5;

  case 0x1a:

    return 6;

  case 0x1c:

    return 7;

  case 0x32:

    return 9;

  case 0x34:

    return 8;

  case 0x44:

    return 0xb;

  case 0x46:

    return 10;

  }

}
