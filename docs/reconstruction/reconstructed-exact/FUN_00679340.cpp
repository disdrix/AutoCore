// =============================================================================
// FUN_00679340
// -----------------------------------------------------------------------------
// Stable ID: aa_00679340
// Address:   0x00679340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00679340 @ 0x00679340
// Stable ID: aa_00679340
// Embedded strings (evidence for future rename):
//   - "Unable to set volume: %d"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutStream.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00679340, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Unable to set volume: %d".
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

void __thiscall FUN_00679340(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = param_2;

  iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x3c))(*(int **)(param_1 + 0x10));

  if (iVar1 != 0) {

    uVar2 = FUN_0076cec0(&uStack_4,"Unable to set volume: %d",iVar1);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutStream.cpp"

                   ,0x262,2,uVar2);

  }

  return;

}
