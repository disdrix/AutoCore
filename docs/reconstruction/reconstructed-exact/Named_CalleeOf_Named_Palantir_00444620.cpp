// =============================================================================
// Named_CalleeOf_Named_Palantir_00444620
// -----------------------------------------------------------------------------
// Stable ID: aa_00444620
// Callee of Named_Palantir
// Address:   0x00444620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00444620, FUN_0076c3c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Palantir
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

void Named_CalleeOf_Named_Palantir_00444620(void)



{

  int *piVar1;

  int iVar2;

  int extraout_ECX;

  

  if ((DAT_00d1f614 != 0) && (*(char *)(DAT_00d1f614 + 200) == '\0')) {

    iVar2 = FUN_0076c3c0();

    piVar1 = (int *)(extraout_ECX + 0x34 + *(int *)(extraout_ECX + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar2 - *(int *)(extraout_ECX + 0x30));

    *(int *)(extraout_ECX + 0x30) = iVar2;

    *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0xc4) = 2;

  }

  return;

}
