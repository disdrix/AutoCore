// =============================================================================
// FUN_00678360
// -----------------------------------------------------------------------------
// Stable ID: aa_00678360
// Address:   0x00678360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00678360 @ 0x00678360
// Stable ID: aa_00678360
// Embedded strings (evidence for future rename):
//   - "Codec cannot decode"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\SpeexCodec.cpp"
//   - "Speex Decoded %d into %d bytes"
//   - "Speex decode failure: %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×3, FUN_00678360, FUN_00702930, FUN_00702970, FUN_00702f80.
//  - Strings: "Codec cannot decode"; "Speex Decoded %d into %d bytes"; "Speex decode failure: %d".
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

uint32_t /* width from decompiler */ __thiscall

FUN_00678360(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 4) != 1) {

    uVar1 = FUN_0076cec0(&param_4,"Codec cannot decode");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\SpeexCodec.cpp"

                   ,0xaa,3,uVar1);

    return 0xffffffff;

  }

  iVar2 = param_1 + 0x50;

  FUN_00702930(iVar2);

  uVar1 = param_4;

  FUN_00702970(iVar2,param_3,param_4);

  iVar2 = FUN_00702f80(*(uint32_t /* width from decompiler */ *)(param_1 + 0x78),iVar2,param_2);

  if (iVar2 != 0) {

    uVar1 = FUN_0076cec0(&param_4,"Speex Decoded %d into %d bytes",uVar1,

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\SpeexCodec.cpp"

                   ,0xb6,1,uVar1);

    uVar1 = FUN_0076cec0(&param_4,"Speex decode failure: %d",iVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\SpeexCodec.cpp"

                   ,0xb7,3,uVar1);

    return 0xffffffff;

  }

  return 0;

}
