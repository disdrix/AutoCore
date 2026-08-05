// =============================================================================
// FUN_0071b010
// -----------------------------------------------------------------------------
// Stable ID: aa_0071b010
// Address:   0x0071b010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071b010 @ 0x0071b010
// Stable ID: aa_0071b010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×2, while×2.
//  - Notable callees: CONCAT31, FUN_0071b010, FUN_0071d140.
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

uint FUN_0071b010(void)



{

  uint in_EAX;

  int iVar1;

  int iVar2;

  uint uVar3;

  uint unaff_EBX;

  int unaff_EDI;

  

  if ((unaff_EBX & 7) != 0) {

    return in_EAX & 0xffffff00;

  }

  iVar1 = (int)unaff_EBX >> 3;

  if (0 < iVar1) {

    do {

      FUN_0071d140();

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  iVar2 = (int)(unaff_EBX - 8) >> 2;

  uVar3 = 0;

  iVar1 = 0;

  if (0 < iVar2) {

    do {

      uVar3 = uVar3 ^ *(uint *)(unaff_EDI + iVar1 * 4);

      iVar1 = iVar1 + 1;

    } while (iVar1 < iVar2);

  }

  return CONCAT31((int3)((uint)iVar1 >> 8),*(uint *)(unaff_EDI + iVar1 * 4) == uVar3);

}
