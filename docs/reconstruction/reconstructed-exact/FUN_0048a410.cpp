// =============================================================================
// FUN_0048a410
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a410
// Address:   0x0048a410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a410 @ 0x0048a410
// Stable ID: aa_0048a410
// Embedded strings (evidence for future rename):
//   - "SetLEDSettings() - Enter"
//   - "SetLEDSettings() - Exit"
//   - "SetLEDSettings() - DESKTOP"
//   - "SetLEDSettings() - NONE (Unsupported)"
//   - "SetLEDSettings() - Exit(Failure)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: SetLEDSettings×5, FUN_0056f570×4, Exit, FUN_0048a330, FUN_0048a410, NONE.
//  - Strings: "SetLEDSettings() - Enter"; "SetLEDSettings() - Exit"; "SetLEDSettings() - DESKTOP"; "SetLEDSettings() - NONE (Unsupported)".
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

uint32_t /* width from decompiler */ FUN_0048a410(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  char *pcVar2;

  

  FUN_0056f570("SetLEDSettings() - Enter");

  if (param_1 != 0) {

    if (param_2 == 1) {

      FUN_0056f570("SetLEDSettings() - Exit");

      uVar1 = FUN_0048a330(param_1,param_3);

      return uVar1;

    }

    if (param_2 == 2) {

      pcVar2 = "SetLEDSettings() - DESKTOP";

    }

    else {

      pcVar2 = "SetLEDSettings() - NONE (Unsupported)";

    }

    FUN_0056f570(pcVar2);

  }

  FUN_0056f570("SetLEDSettings() - Exit(Failure)");

  return 0;

}
