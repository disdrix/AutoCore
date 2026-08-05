// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007a4400
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4400
// Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
// Address:   0x007a4400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007a4400, QueryPerformanceCounter, QueryPerformanceFrequency.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



LARGE_INTEGER * __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007a4400(LARGE_INTEGER *param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  LARGE_INTEGER local_8;

  

  if (DAT_00b00a74 != '\0') {

    DAT_00b00a74 = '\0';

    QueryPerformanceFrequency(&local_8);

    _DAT_00afa254 = g_flOne / (float)(longlong)local_8;

  }

  iVar2 = 8 - (int)param_2;

  do {

    cVar1 = *param_2;

    param_2[(int)param_1 + iVar2] = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  QueryPerformanceCounter(param_1);

  return param_1;

}
