// =============================================================================
// FUN_00433a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00433a00
// Address:   0x00433a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00433a00 @ 0x00433a00
// Stable ID: aa_00433a00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00433a00.
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

void FUN_00433a00(void)



{

  char cVar1;

  uint uVar2;

  char *pcVar3;

  uint uVar4;

  int unaff_ESI;

  

  if (((*(int *)(unaff_ESI + 4) != 0) && (uVar2 = *(uint *)(unaff_ESI + 0x28), uVar2 != 0)) &&

     (uVar4 = 0, uVar2 != 0)) {

    pcVar3 = (char *)(*(int *)(unaff_ESI + 4) + 0x29);

    do {

      cVar1 = (char)(0xff / (ulonglong)(uVar2 - 1)) * (char)uVar4;

      pcVar3[1] = cVar1;

      *pcVar3 = cVar1;

      pcVar3[-1] = cVar1;

      uVar2 = *(uint *)(unaff_ESI + 0x28);

      uVar4 = uVar4 + 1;

      pcVar3 = pcVar3 + 4;

    } while (uVar4 < uVar2);

  }

  return;

}
