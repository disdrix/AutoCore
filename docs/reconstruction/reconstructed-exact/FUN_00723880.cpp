// =============================================================================
// FUN_00723880
// -----------------------------------------------------------------------------
// Stable ID: aa_00723880
// Address:   0x00723880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00723880 @ 0x00723880
// Stable ID: aa_00723880
// Embedded strings (evidence for future rename):
//   - "Sound file had invalid group : %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00723880, FUN_007a4480.
//  - Strings: "Sound file had invalid group : %d".
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

uint32_t /* width from decompiler */ FUN_00723880(int param_1)



{

  int iVar1;

  int in_EAX;

  

  if (in_EAX != 0) {

    iVar1 = *(int *)(in_EAX + 0x2c) / 10;

    if (iVar1 < 9) {

      return *(uint32_t /* width from decompiler */ *)(param_1 + 0x260 + iVar1 * 4);

    }

    FUN_007a4480(1,"Sound file had invalid group : %d",iVar1);

  }

  return 0;

}
