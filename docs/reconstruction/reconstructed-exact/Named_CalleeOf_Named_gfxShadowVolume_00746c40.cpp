// =============================================================================
// Named_CalleeOf_Named_gfxShadowVolume_00746c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00746c40
// Callee of Named_gfxShadowVolume
// Address:   0x00746c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, while×1.
//  - Notable callees: FUN_00746910, FUN_00746c40.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxShadowVolume
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxShadowVolume_00746c40(int param_1)



{

  int iVar1;

  char cVar2;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 4);

  while( true ) {

    if (iVar1 == *(int *)(unaff_ESI + 8)) {

      return 0xffffffff;

    }

    cVar2 = '\x01';

    if (*(char *)(iVar1 + 6) == '\x01') break;

    iVar1 = iVar1 + 8;

  }

  if (param_1 == 2) {

    cVar2 = '\0';

  }

  else if ((param_1 != 3) && (cVar2 = '\0', param_1 == 4)) {

    cVar2 = '\x02';

  }

  if (*(char *)(iVar1 + 4) != cVar2) {

    *(char *)(iVar1 + 4) = cVar2;

    FUN_00746910();

  }

  return 0;

}
