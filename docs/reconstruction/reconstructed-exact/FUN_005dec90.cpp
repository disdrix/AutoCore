// =============================================================================
// FUN_005dec90
// -----------------------------------------------------------------------------
// Stable ID: aa_005dec90
// Address:   0x005dec90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dec90 @ 0x005dec90
// Stable ID: aa_005dec90
// Embedded strings (evidence for future rename):
//   - "---------------------------\n"
//   - " Havok - Build (%d)\n"
//   - " Base system initialized.   \n"
//   - "----------------------------\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00631f10×4, Build, FUN_005dec90, FUN_00631f70.
//  - Strings: "---------------------------\n"; " Havok - Build (%d)\n"; " Base system initialized.   \n"; "----------------------------\n".
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

void FUN_005dec90(void)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (DAT_00bc56a5 == '\x01') {

    uVar1 = (**(code **)(*DAT_00d030e0 + 4))("---------------------------\n");

    FUN_00631f10(uVar1);

    uVar1 = (**(code **)(*DAT_00d030e0 + 4))(" Havok - Build (%d)\n",0x131cb47);

    FUN_00631f10(uVar1);

    uVar1 = (**(code **)(*DAT_00d030e0 + 4))(" Base system initialized.   \n");

    FUN_00631f10(uVar1);

    uVar1 = (**(code **)(*DAT_00d030e0 + 4))("----------------------------\n");

    FUN_00631f10(uVar1);

    (**(code **)(*DAT_00d030e0 + 4))();

    FUN_00631f70();

    return;

  }

  return;

}
