// =============================================================================
// FUN_0075d5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d5b0
// Address:   0x0075d5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075d5b0 @ 0x0075d5b0
// Stable ID: aa_0075d5b0
// Embedded strings (evidence for future rename):
//   - "No active catalog object"
//   - "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00415e90, FUN_0075d5b0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "No active catalog object"; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp".
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

uint8_t __thiscall FUN_0075d5b0(int param_1,char param_2)



{

  uint8_t uVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  cVar3 = param_2;

  iVar2 = *(int *)(param_1 + 100);

  if (iVar2 != 0) {

    if (*(char *)(iVar2 + 0x2c) != param_2) {

      FUN_00415e90();

    }

    uVar1 = *(uint8_t *)(iVar2 + 0x2c);

    *(char *)(iVar2 + 0x2c) = cVar3;

    return uVar1;

  }

  uVar4 = FUN_0076cec0(&param_2,"No active catalog object");

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",0x2d3,2,uVar4);

  return 0;

}
