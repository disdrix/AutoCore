// =============================================================================
// FUN_00845af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00845af0
// Address:   0x00845af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00845af0 @ 0x00845af0
// Stable ID: aa_00845af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CONCAT31, FUN_00845af0.
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

uint FUN_00845af0(void)



{

  uint in_EAX;

  int iVar1;

  int *unaff_ESI;

  

  if (unaff_ESI != (int *)0x0) {

    iVar1 = (**(code **)(*unaff_ESI + 0x1e0))();

    in_EAX = 0;

    if (iVar1 != 0) {

      iVar1 = (**(code **)(*unaff_ESI + 0x1e0))();

      iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1);

      if (iVar1 == 0) {

        in_EAX = 0;

      }

      else {

        in_EAX = *(uint *)(iVar1 + 0x3c);

      }

      if ((*(byte *)(in_EAX + 0x536) & 0x12) != 0) {

        return CONCAT31((int3)(in_EAX >> 8),1);

      }

    }

  }

  return in_EAX & 0xffffff00;

}
