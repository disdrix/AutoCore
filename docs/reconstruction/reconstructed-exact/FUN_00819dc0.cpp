// =============================================================================
// FUN_00819dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00819dc0
// Address:   0x00819dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00819dc0 @ 0x00819dc0
// Stable ID: aa_00819dc0
// Embedded strings (evidence for future rename):
//   - "Medium"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_00794090, FUN_00819dc0.
//  - Strings: "Medium".
//  - Return sites: 3.

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

void FUN_00819dc0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int *unaff_EDI;

  

  if (unaff_EDI == (int *)0x0) {

    return;

  }

  (**(code **)(*unaff_EDI + 0x74))(0x9c47);

  if (unaff_EDI[0x24c] != 0) {

    FUN_00794090();

  }

  if (DAT_00d1a851 == '\0') {

    uVar1 = (**(code **)(*unaff_EDI + 0x448))(&DAT_00a7a110);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf18) = uVar1;

    uVar1 = (**(code **)(*unaff_EDI + 0x448))("Medium");

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf1c) = uVar1;

    uVar1 = (**(code **)(*unaff_EDI + 0x448))(&DAT_00a7a10c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf20) = uVar1;

    if (2 < DAT_00d1b24d) {

      DAT_00d1b24d = DAT_00d1a851 != '\0';

      DAT_00d1a8f5 = DAT_00d1a851 != '\0';

    }

                    /* WARNING: Could not recover jumptable at 0x00819e91. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*unaff_EDI + 0x45c))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xf18 + (uint)DAT_00d1b24d * 4));

    return;

  }

  uVar1 = (**(code **)(*unaff_EDI + 0x448))("Medium");

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf18) = uVar1;

  uVar1 = (**(code **)(*unaff_EDI + 0x448))(&DAT_00a7a10c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf1c) = uVar1;

  if ((2 < DAT_00d1b24d) || (DAT_00d1b24d == 0)) {

    DAT_00d1b24d = 1;

    if ((DAT_00d1b780 == (int *)0x0) || (*DAT_00d1b780 != DAT_00d1b778)) {

      DAT_00d1a8f5 = DAT_00d1a851 != '\0';

    }

    else {

      DAT_00d1a8f5 = 1;

    }

  }

                    /* WARNING: Could not recover jumptable at 0x00819f16. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_EDI + 0x45c))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xf14 + (uint)DAT_00d1b24d * 4));

  return;

}
