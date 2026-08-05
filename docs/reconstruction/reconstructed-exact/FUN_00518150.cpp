// =============================================================================
// FUN_00518150
// -----------------------------------------------------------------------------
// Stable ID: aa_00518150
// Address:   0x00518150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00518150 @ 0x00518150
// Stable ID: aa_00518150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00518150, Map_LowerBoundFindByIntKey.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ FUN_00518150(void *param_1)



{

  void *pvVar1;

  int *unaff_ESI;

  

  pvVar1 = param_1;

  Map_LowerBoundFindByIntKey(param_1,&param_1,&stack0x00000008,unaff_ESI);

  if (param_1 != *(void **)((int)pvVar1 + 4)) {

    return *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x10);

  }

  return 0;

}
