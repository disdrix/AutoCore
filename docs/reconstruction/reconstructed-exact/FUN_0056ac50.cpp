// =============================================================================
// FUN_0056ac50
// -----------------------------------------------------------------------------
// Stable ID: aa_0056ac50
// Address:   0x0056ac50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056ac50 @ 0x0056ac50
// Stable ID: aa_0056ac50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0056ac50.
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

char __fastcall FUN_0056ac50(int param_1)



{

  char cVar1;

  int iVar2;

  

  cVar1 = '\x01';

  if ((*(byte *)(param_1 + 0xc4) & 1) == 0) {

    if ((*(byte *)(param_1 + 0xc4) & 0x40) != 0) {

      return 'd';

    }

  }

  else {

    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(iVar2 + 0x3c);

    }

    cVar1 = *(char *)(iVar2 + 0x537);

    if (cVar1 == '\0') {

      cVar1 = '\x01';

    }

  }

  return cVar1;

}
