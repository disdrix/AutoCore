// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, while×2.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×3, FUN_00674cf0×2, thunk_FUN_0076c4d0×2, FUN_00675280, FUN_0076c3c0, FUN_0076c500, SetThreadPriority.
//  - Strings: "Failed to set out thread priority to %d"; "Bad mutex object: %d"; "Invalid mutex index: %d".
//  - Return sites: 4.

// =============================================================================
// Named_AudioOutThread_00675280
// -----------------------------------------------------------------------------
// Stable ID: aa_00675280
// Address:   0x00675280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AudioOutThread"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_AudioOutThread_00675280(int *param_1)



{

  BOOL BVar1;

  uint32_t /* width from decompiler */ uVar2;

  DWORD DVar3;

  uint uVar4;

  uint8_t local_3c [4];

  HANDLE local_38;

  int local_34;

  

  BVar1 = SetThreadPriority((HANDLE)param_1[2],param_1[0x54]);

  if (BVar1 == 0) {

    uVar2 = FUN_0076cec0(local_3c,"Failed to set out thread priority to %d",param_1[0x54]);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"

                   ,0x59,3,uVar2);

    return;

  }

  local_38 = (HANDLE)param_1[7];

  local_34 = param_1[4];

  FUN_0076c500(1000);

  while( true ) {

    while (DVar3 = WaitForMultipleObjects(2,&local_38,0,0x32), DVar3 == 0x102) {

      FUN_00674cf0();

      thunk_FUN_0076c4d0();

    }

    if (0x7f < DVar3) {

      uVar2 = FUN_0076cec0(local_3c,"Bad mutex object: %d",DVar3 - 0x80);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"

                     ,0x70,2,uVar2);

      return;

    }

    if (1 < (int)DVar3) {

      uVar2 = FUN_0076cec0(local_3c,"Invalid mutex index: %d",DVar3);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"

                     ,0x78,2,uVar2);

      return;

    }

    if (DVar3 == 0) break;

    if (DVar3 == 1) {

      (**(code **)(*param_1 + 0xc))();

      uVar4 = FUN_0076c3c0();

      if (0x31 < uVar4) {

        FUN_00674cf0();

        thunk_FUN_0076c4d0();

      }

    }

  }

  return;

}
