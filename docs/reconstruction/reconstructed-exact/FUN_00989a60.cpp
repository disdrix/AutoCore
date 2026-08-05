// =============================================================================
// FUN_00989a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00989a60
// Address:   0x00989a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00989a60 @ 0x00989a60
// Stable ID: aa_00989a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_00989a60, _aligned_malloc.
//  - Return sites: 1.

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

void * FUN_00989a60(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *unaff_EDI;

  void *local_4;

  

  if (unaff_EDI[5] == 0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = _aligned_malloc(unaff_EDI[5],unaff_EDI[4]);

  }

  if (pvVar1 != (void *)0x0) {

    *unaff_EDI = pvVar1;

    unaff_EDI[1] = unaff_EDI[5];

    local_4 = pvVar1;

    CVOGReaction_FailMissionNotify(&local_4);

  }

  return pvVar1;

}
