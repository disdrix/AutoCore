// =============================================================================
// FUN_00563800
// -----------------------------------------------------------------------------
// Stable ID: aa_00563800
// Address:   0x00563800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00563800 @ 0x00563800
// Stable ID: aa_00563800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004d0e90×2, FUN_00563800.
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

uint FUN_00563800(int *param_1,char *param_2)



{

  uint in_EAX;

  uint uVar1;

  

  if ((*(byte *)(param_1 + 0x5f) & 1) == 0) {

    if (*param_2 != '\0') {

      param_1[0x33] = 2;

      uVar1 = FUN_004d0e90(param_1);

      return uVar1 & 0xffffff00;

    }

    param_1[0x33] = 0;

    (**(code **)(*param_1 + 600))(DAT_009d2988,DAT_009d298c,DAT_009d2990,DAT_009d2994);

    in_EAX = FUN_004d0e90(param_1);

  }

  return in_EAX & 0xffffff00;

}
