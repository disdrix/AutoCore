// =============================================================================
// FUN_00402bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00402bf0
// Address:   0x00402bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00402bf0 @ 0x00402bf0
// Stable ID: aa_00402bf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00402bf0, FUN_00403fd0.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x00402bf0; evidence only — no invented semantics):
//  - Entry: `int * FUN_00402bf0(int *param_1)`.
//  - Branches: if ((iVar1 != *(unaff_ESI + 4)) && (*(iVar1 + 0xc) <= *unaff_EDI)).
//  - Calls: FUN_00403fd0(unaff_EDI).
//  - Writes: *param_1 = iVar1; *param_1 = *(unaff_ESI + 4).
//  - Returns (2 site(s)): `param_1`.




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

int * FUN_00402bf0(int *param_1)



{

  int iVar1;

  int unaff_ESI;

  byte *unaff_EDI;

  

  iVar1 = FUN_00403fd0(unaff_EDI);

  if ((iVar1 != *(int *)(unaff_ESI + 4)) && (*(byte *)(iVar1 + 0xc) <= *unaff_EDI)) {

    *param_1 = iVar1;

    return param_1;

  }

  *param_1 = *(int *)(unaff_ESI + 4);

  return param_1;

}
