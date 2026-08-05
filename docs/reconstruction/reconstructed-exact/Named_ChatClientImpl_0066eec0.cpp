// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0066eec0, FUN_00671b70, FUN_0076cec0, vog_LogMessage.
//  - Strings: "local Post Stop recording command".
//  - Return sites: 2.

// =============================================================================
// Named_ChatClientImpl_0066eec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066eec0
// Address:   0x0066eec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_ChatClientImpl_0066eec0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int local_4;

  

  if (*(char *)(param_1 + 0x184) != '\0') {

    if ((*(char *)(param_1 + 0x58) == '\0') || (*(char *)(param_1 + 0x5a) == '\0')) {

      return 0xffffffff;

    }

    local_4 = param_1;

    uVar1 = FUN_0076cec0(&local_4,"local Post Stop recording command");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                   ,0x11b,1,uVar1);

    *(uint8_t *)(param_1 + 0x184) = 0;

    FUN_00671b70();

  }

  return 0;

}
