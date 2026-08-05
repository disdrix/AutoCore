// =============================================================================
// FUN_006743b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006743b0
// Address:   0x006743b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006743b0 @ 0x006743b0
// Stable ID: aa_006743b0
// Embedded strings (evidence for future rename):
//   - "Release stream %d from player %d"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004e3050, FUN_006743b0, FUN_00675700, FUN_006759b0, FUN_00675a40, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Release stream %d from player %d".
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

uint32_t /* width from decompiler */ __thiscall FUN_006743b0(int param_1,uint8_t param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int local_4;

  

  local_4 = param_1;

  FUN_004e3050(&local_4,&param_2);

  iVar1 = local_4;

  if (local_4 != *(int *)(param_1 + 0x144)) {

    local_4 = *(int *)(local_4 + 0x10);

    if (local_4 != 0) {

      uVar2 = FUN_0076cec0(&param_2,"Release stream %d from player %d",

                           *(uint32_t /* width from decompiler */ *)(local_4 + 0x68),param_2);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"

                     ,0x201,1,uVar2);

      FUN_00675a40(&param_2,iVar1);

      iVar1 = *(int *)(param_1 + 0x138);

      iVar3 = FUN_006759b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&stack0xfffffff4);

      FUN_00675700(1);

      *(int *)(iVar1 + 4) = iVar3;

      **(int **)(iVar3 + 4) = iVar3;

      return 0;

    }

  }

  return 0xffffffff;

}
