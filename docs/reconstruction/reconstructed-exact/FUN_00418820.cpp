// =============================================================================
// FUN_00418820
// -----------------------------------------------------------------------------
// Stable ID: aa_00418820
// Address:   0x00418820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00418820 @ 0x00418820
// Stable ID: aa_00418820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: Map_LowerBoundFindByIntKey×2, FUN_00418820.
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

uint32_t /* width from decompiler */ FUN_00418820(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int *extraout_EAX;

  int *unaff_ESI;

  int local_4;

  

  uVar1 = param_1;

  Map_LowerBoundFindByIntKey(&DAT_00b04740,&local_4,&param_1,unaff_ESI);

  if (local_4 != DAT_00b04744) {

    param_1 = uVar1;

    Map_LowerBoundFindByIntKey(&DAT_00b04740,&local_4,&param_1,unaff_ESI);

    return *(uint32_t /* width from decompiler */ *)(*extraout_EAX + 0x10);

  }

  return 0;

}
