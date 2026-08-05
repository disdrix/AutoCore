// =============================================================================
// FUN_00440b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00440b20
// Address:   0x00440b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00440b20 @ 0x00440b20
// Stable ID: aa_00440b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, goto×2.
//  - Notable callees: CONCAT31, FUN_00440b20.
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

uint FUN_00440b20(void)



{

  uint uVar1;

  uint *in_EAX;

  uint uVar2;

  uint *unaff_EDI;

  

  uVar1 = *unaff_EDI;

  uVar2 = *in_EAX;

  if (*(uint *)(uVar2 + 8) < *(uint *)(uVar1 + 8)) {

LAB_00440b32:

    return CONCAT31((int3)(uVar2 >> 8),1);

  }

  if (*(uint *)(uVar2 + 8) <= *(uint *)(uVar1 + 8)) {

    if (uVar2 < uVar1) goto LAB_00440b32;

    if (uVar2 == uVar1) {

      uVar2 = in_EAX[2];

      if ((uVar2 < unaff_EDI[2]) ||

         ((uVar2 == unaff_EDI[2] && ((int)in_EAX[3] < (int)unaff_EDI[3])))) goto LAB_00440b32;

    }

  }

  return uVar2 & 0xffffff00;

}
