// =============================================================================
// FUN_0073bf60
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bf60
// Address:   0x0073bf60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073bf60 @ 0x0073bf60
// Stable ID: aa_0073bf60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0073bf60.
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

void FUN_0073bf60(void)



{

  code *pcVar1;

  int *piVar2;

  int *unaff_EBX;

  int iVar3;

  

  iVar3 = 0;

  piVar2 = unaff_EBX;

  if (0 < *unaff_EBX) {

    do {

      pcVar1 = (code *)piVar2[0xb];

      if (pcVar1 != (code *)0x0) {

        (*pcVar1)();

      }

      iVar3 = iVar3 + 1;

      piVar2 = piVar2 + 0xb;

    } while (iVar3 < *unaff_EBX);

  }

  *unaff_EBX = 0;

  return;

}
