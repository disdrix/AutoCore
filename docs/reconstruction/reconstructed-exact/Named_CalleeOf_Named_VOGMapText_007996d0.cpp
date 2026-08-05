// =============================================================================
// Named_CalleeOf_Named_VOGMapText_007996d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007996d0
// Callee of Named_VOGMapText (+8 other named callers)
// Address:   0x007996d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGMapText: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGMapText (+8 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00799460, FUN_007996d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOGMapText (+8 other named callers)
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

void Named_CalleeOf_Named_VOGMapText_007996d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint8_t *param_3)



{

  char cVar1;

  int local_4;

  

  cVar1 = FUN_00799460(param_1,param_2,&local_4,10);

  if (cVar1 != '\0') {

    *param_3 = local_4 != 0;

    return;

  }

  *param_3 = 0;

  return;

}
