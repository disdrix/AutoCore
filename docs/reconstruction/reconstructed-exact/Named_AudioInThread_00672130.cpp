// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_00672130, FUN_00680290, FUN_0076c330.
//  - Strings: "VAD stopped %f."; "VAD started %f".
//  - Return sites: 2.

// =============================================================================
// Named_AudioInThread_00672130
// -----------------------------------------------------------------------------
// Stable ID: aa_00672130
// Address:   0x00672130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AudioInThread"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t __fastcall Named_AudioInThread_00672130(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  float10 fVar3;

  int local_4;

  

  if (*(char *)(param_1 + 0x96d) != '\0') {

    cVar1 = *(char *)(*(int *)(param_1 + 0x15c) + 0x15);

    if (cVar1 != *(char *)(param_1 + 0x96f)) {

      local_4 = param_1;

      fVar3 = (float10)FUN_0076c330();

      if (cVar1 == '\0') {

        uVar2 = FUN_0076cec0(&local_4,"VAD stopped %f.",(double)fVar3);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                       ,0x275,1,uVar2);

        local_4 = 2;

      }

      else {

        uVar2 = FUN_0076cec0(&local_4,"VAD started %f",(double)fVar3);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                       ,0x270,1,uVar2);

        local_4 = 1;

      }

      FUN_00680290(&local_4);

      *(char *)(param_1 + 0x96f) = cVar1;

    }

    return *(uint8_t *)(param_1 + 0x96c);

  }

  return *(uint8_t *)(param_1 + 0x96c);

}
