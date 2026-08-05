// =============================================================================
// FUN_008a8140
// -----------------------------------------------------------------------------
// Stable ID: aa_008a8140
// Address:   0x008a8140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a8140 @ 0x008a8140
// Stable ID: aa_008a8140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: CONCAT31, FUN_008a8140.
//  - Return sites: 4.

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

uint FUN_008a8140(void)



{

  int iVar1;

  int iVar2;

  uint in_EAX;

  

  if (in_EAX != 0) {

    iVar1 = *(int *)(*(int *)(in_EAX + 4) + 4);

    iVar2 = *(int *)(in_EAX + 0x120 + iVar1);

    in_EAX = in_EAX + iVar1;

    if (iVar2 != 0) {

      if (*(int *)(*(int *)(*(int *)(in_EAX + 0xac) + 0x3c) + 0x4e0) != 1) {

        return CONCAT31((int3)((uint)*(int *)(in_EAX + 0xac) >> 8),1);

      }

      iVar1 = *(int *)(iVar2 + 0x10);

      if ((((iVar1 != 2) && (iVar1 != 6)) && (iVar1 != 7)) &&

         (((iVar1 != 3 && (iVar1 != 5)) && (iVar1 != 8)))) {

        return 0;

      }

      return 1;

    }

  }

  return in_EAX & 0xffffff00;

}
