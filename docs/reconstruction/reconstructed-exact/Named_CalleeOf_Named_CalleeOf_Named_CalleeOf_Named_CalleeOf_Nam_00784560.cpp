// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00784560
// -----------------------------------------------------------------------------
// Stable ID: aa_00784560
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut
// Address:   0x00784560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut: callee helper. Evidence string: "succeeded.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "succeeded."
//   - "failed!"
//   - "Winsock initialization %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00783aa0, FUN_00784560, WSAStartup.
//  - Strings: "succeeded."; "failed!"; "Winsock initialization %s".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut
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

bool Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00784560(void)



{

  int iVar1;

  char *pcVar2;

  bool bVar3;

  WSADATA local_190;

  

  bVar3 = true;

  if (DAT_00d17994 == 0) {

    iVar1 = WSAStartup(0x101,&local_190);

    bVar3 = iVar1 == 0;

    pcVar2 = "succeeded.";

    if (!bVar3) {

      pcVar2 = "failed!";

    }

    FUN_00783aa0("Winsock initialization %s",pcVar2);

  }

  DAT_00d17994 = DAT_00d17994 + 1;

  return bVar3;

}
