// =============================================================================
// FUN_0088a910
// -----------------------------------------------------------------------------
// Stable ID: aa_0088a910
// Address:   0x0088a910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088a910 @ 0x0088a910
// Stable ID: aa_0088a910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: CONCAT31, FUN_0046f100, FUN_0088a910.
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

uint FUN_0088a910(void)



{

  uint *puVar1;

  uint *puVar2;

  int in_EAX;

  int unaff_EDI;

  

  puVar1 = *(uint **)(in_EAX + 0x524);

  puVar2 = (uint *)*puVar1;

  while( true ) {

    if (puVar2 == puVar1) {

      return (uint)puVar2 & 0xffffff00;

    }

    if (puVar2[3] == unaff_EDI) break;

    FUN_0046f100();

  }

  return CONCAT31((int3)((uint)puVar2 >> 8),1);

}
