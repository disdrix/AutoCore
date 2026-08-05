// =============================================================================
// FUN_0081e650
// -----------------------------------------------------------------------------
// Stable ID: aa_0081e650
// Address:   0x0081e650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0081e650 @ 0x0081e650
// Stable ID: aa_0081e650
// Embedded strings (evidence for future rename):
//   - "DSL/Cable (20k+)"
//   - "ISDN (10k)"
//   - "56k (5k)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: Cable, FUN_00794090, FUN_0081e650, FUN_0092dcc0, ISDN.
//  - Strings: "DSL/Cable (20k+)"; "ISDN (10k)"; "56k (5k)".
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

void FUN_0081e650(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int *unaff_EDI;

  

  if (unaff_EDI != (int *)0x0) {

    (**(code **)(*unaff_EDI + 0x74))(0x9cd3);

    if (unaff_EDI[0x24c] != 0) {

      FUN_00794090();

    }

    uVar1 = (**(code **)(*unaff_EDI + 0x448))("DSL/Cable (20k+)");

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8c) = uVar1;

    uVar1 = (**(code **)(*unaff_EDI + 0x448))("ISDN (10k)");

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe90) = uVar1;

    uVar1 = (**(code **)(*unaff_EDI + 0x448))("56k (5k)");

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe94) = uVar1;

    if (2 < DAT_00d1b24e) {

      FUN_0092dcc0(&DAT_00d1a840);

    }

                    /* WARNING: Could not recover jumptable at 0x0081e6e9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*unaff_EDI + 0x45c))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe8c + (uint)DAT_00d1b24e * 4));

    return;

  }

  return;

}
