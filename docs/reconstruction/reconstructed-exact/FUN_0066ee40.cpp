// =============================================================================
// FUN_0066ee40
// -----------------------------------------------------------------------------
// Stable ID: aa_0066ee40
// Address:   0x0066ee40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066ee40 @ 0x0066ee40
// Stable ID: aa_0066ee40
// Embedded strings (evidence for future rename):
//   - "Already recording"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"
//   - "Post Start command\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_0066ee40, FUN_00671b50.
//  - Strings: "Already recording"; "Post Start command\n".
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

uint32_t /* width from decompiler */ __fastcall FUN_0066ee40(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int local_4;

  

  local_4 = param_1;

  if (*(char *)(param_1 + 0x184) != '\0') {

    uVar1 = FUN_0076cec0(&local_4,"Already recording");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                   ,0xfc,2,uVar1);

    return 0;

  }

  if ((*(char *)(param_1 + 0x58) != '\0') && (*(char *)(param_1 + 0x5a) != '\0')) {

    uVar1 = FUN_0076cec0(&local_4,"Post Start command\n");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                   ,0x106,1,uVar1);

    *(uint8_t *)(param_1 + 0x184) = 1;

    FUN_00671b50();

    return 0;

  }

  return 0xffffffff;

}
