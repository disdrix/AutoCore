// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007994c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007994c0
// Callee of Named_VOG_DEBUG_STOP (+4 other named callers)
// Address:   0x007994c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00798bb0, FUN_00799060, FUN_00799110, FUN_007994c0, swscanf.
//  - Strings: "%f,%f,%f".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+4 other named callers)
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

char Named_CalleeOf_Named_VOG_DEBUG_STOP_007994c0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

                 int param_6)



{

  char cVar1;

  wchar_t *local_84;

  wchar_t local_80 [64];

  

  cVar1 = FUN_00798bb0(param_1,param_2,local_80);

  if (cVar1 == '\0') {

    return '\0';

  }

  if (param_4 == 0) {

    swscanf(local_80,L"%f,%f,%f",param_3,param_3 + 4,param_3 + 8);

    return cVar1;

  }

  local_84 = local_80;

  if (param_6 == 0) {

    FUN_00799060(&local_84,param_5);

    return cVar1;

  }

  FUN_00799110(param_3,param_4);

  return cVar1;

}
