// =============================================================================
// FUN_0066f600
// -----------------------------------------------------------------------------
// Stable ID: aa_0066f600
// Address:   0x0066f600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066f600 @ 0x0066f600
// Stable ID: aa_0066f600
// Embedded strings (evidence for future rename):
//   - "Setting volume to %d"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"
//   - "Invalid volume %d. range is 0 to -10000"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_0066f600, FUN_00673e20.
//  - Strings: "Setting volume to %d"; "Invalid volume %d. range is 0 to -10000".
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

uint32_t /* width from decompiler */ __thiscall FUN_0066f600(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  iVar1 = param_2;

  if (*(int *)(param_1 + 0x30) != 0) {

    if ((param_2 < 1) && (-0x2711 < param_2)) {

      *(int *)(param_1 + 0x1fc) = param_2;

      FUN_00673e20(param_2);

      uVar2 = FUN_0076cec0(&param_2,"Setting volume to %d",iVar1);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                     ,0x555,1,uVar2);

      return 0;

    }

    uVar2 = FUN_0076cec0(&param_2,"Invalid volume %d. range is 0 to -10000",param_2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                   ,0x55a,2,uVar2);

  }

  return 0xffffffff;

}
