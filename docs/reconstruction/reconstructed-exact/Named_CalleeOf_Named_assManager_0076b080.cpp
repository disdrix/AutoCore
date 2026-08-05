// =============================================================================
// Named_CalleeOf_Named_assManager_0076b080
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b080
// Callee of Named_assManager
// Address:   0x0076b080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: stat×2, FUN_0076b080, _chmod, _unlink.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assManager
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

bool Named_CalleeOf_Named_assManager_0076b080(char param_1)



{

  int iVar1;

  char *unaff_ESI;

  uint local_1e;

  

  if ((((param_1 != '\0') && (iVar1 = stat(), iVar1 == 0)) && ((local_1e >> 0xf & 1) != 0)) &&

     ((iVar1 = stat(), iVar1 == 0 && ((~((byte)local_1e >> 7) & 1) != 0)))) {

    _chmod(unaff_ESI,0x180);

  }

  iVar1 = _unlink(unaff_ESI);

  return iVar1 == 0;

}
