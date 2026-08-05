// =============================================================================
// FUN_00672c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00672c20
// Address:   0x00672c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00672c20 @ 0x00672c20
// Stable ID: aa_00672c20
// Embedded strings (evidence for future rename):
//   - "audio in already recording"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006725b0, FUN_00672c20, FUN_006802d0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "audio in already recording".
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

uint32_t /* width from decompiler */ __fastcall FUN_00672c20(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint8_t *puVar2;

  uint8_t local_c [4];

  uint8_t local_8 [4];

  uint8_t local_4 [4];

  

  if (*(char *)(param_1 + 0x96c) != '\0') {

    uVar1 = FUN_0076cec0(local_8,"audio in already recording");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                   ,0x138,2,uVar1);

    return 0;

  }

  puVar2 = local_4;

  (**(code **)(**(int **)(param_1 + 0x98) + 0x10))(*(int **)(param_1 + 0x98),puVar2,local_c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x968) = 0;

  *(uint *)(param_1 + 200) =

       (uint)(puVar2 + (*(uint *)(param_1 + 0xc4) - *(int *)(param_1 + 0x9ac))) %

       *(uint *)(param_1 + 0xc4);

  FUN_006725b0();

  *(uint8_t *)(param_1 + 0x96c) = 1;

  FUN_006802d0(2,0);

  return 0;

}
