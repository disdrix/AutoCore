// =============================================================================
// FUN_0046b7c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046b7c0
// Address:   0x0046b7c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046b7c0 @ 0x0046b7c0
// Stable ID: aa_0046b7c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, return×1.
//  - Notable callees: FUN_00451fd0×6, FUN_0046b7c0.
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

void FUN_0046b7c0(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = -1;

  do {

    iVar1 = -1;

    do {

      iVar3 = -1;

      do {

        FUN_00451fd0();

        FUN_00451fd0();

        FUN_00451fd0();

        FUN_00451fd0();

        FUN_00451fd0();

        FUN_00451fd0();

        iVar3 = iVar3 + 2;

      } while (iVar3 < 2);

      iVar1 = iVar1 + 2;

    } while (iVar1 < 2);

    iVar2 = iVar2 + 2;

  } while (iVar2 < 2);

  return;

}
