// =============================================================================
// FUN_0067c750
// -----------------------------------------------------------------------------
// Stable ID: aa_0067c750
// Address:   0x0067c750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067c750 @ 0x0067c750
// Stable ID: aa_0067c750
// Embedded strings (evidence for future rename):
//   - "Closing session: clean termination."
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0067c750, FUN_00684b00, FUN_00684b10, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Closing session: clean termination.".
//  - Return sites: 1.

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

void __thiscall FUN_0067c750(int param_1,char param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(int *)(param_1 + 0x2a3c) != 0) {

    FUN_00684b00();

  }

  if ((param_2 == '\0') && (*(char *)(param_1 + 6) != '\0')) {

    uVar1 = FUN_0076cec0(&param_2,"Closing session: clean termination.");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",

                   0x221,1,uVar1);

    *(uint8_t *)(param_1 + 5) = 1;

  }

  else if (*(int **)(param_1 + 0x2984) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x2984) + 0x10))();

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2984) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2984))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2984) = 0;

    *(uint8_t *)(param_1 + 4) = 0;

  }

  if (*(int *)(param_1 + 0x2a3c) != 0) {

    FUN_00684b10();

  }

  return;

}
