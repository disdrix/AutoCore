// =============================================================================
// Named_CalleeOf_Named_gfxView_0043f1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f1d0
// Callee of Named_gfxView
// Address:   0x0043f1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0043f1d0, FUN_0076c3c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxView
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

void Named_CalleeOf_Named_gfxView_0043f1d0(void)



{

  int *piVar1;

  int iVar2;

  int *in_EAX;

  int iVar3;

  int extraout_ECX;

  

  iVar2 = in_EAX[1];

  if (*(char *)(*in_EAX + 200) == '\0') {

    iVar3 = FUN_0076c3c0();

    piVar1 = (int *)(extraout_ECX + 0x34 + *(int *)(extraout_ECX + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar3 - *(int *)(extraout_ECX + 0x30));

    *(int *)(extraout_ECX + 0x30) = iVar3;

    *(int *)(extraout_ECX + 0xc4) = iVar2;

  }

  return;

}
