// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, while×2, goto×2, do×1.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×2, FUN_00672440, FUN_006727c0, SetThreadPriority, WaitForMultipleObjects.
//  - Strings: "Failed to set out thread priority to %d"; "Invalid mutex index: %d"; "Bad mutex object: %d".
//  - Return sites: 2.

// =============================================================================
// Named_AudioInThread_006727c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006727c0
// Address:   0x006727c0  (autoassault.exe, image base 0x400000)
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

void __fastcall Named_AudioInThread_006727c0(int *param_1)



{

  int *piVar1;

  BOOL BVar2;

  uint32_t /* width from decompiler */ uVar3;

  DWORD DVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t local_10 [4];

  HANDLE local_c;

  int local_8;

  int local_4;

  

  BVar2 = SetThreadPriority((HANDLE)param_1[2],param_1[0x269]);

  if (BVar2 == 0) {

    uVar3 = FUN_0076cec0(local_10,"Failed to set out thread priority to %d",param_1[0x269]);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                   ,0x4a,3,uVar3);

    return;

  }

  local_c = (HANDLE)param_1[7];

  local_8 = param_1[4];

  local_4 = param_1[0x34];

  while( true ) {

    do {

      DVar4 = WaitForMultipleObjects(3,&local_c,0,1000);

    } while (DVar4 == 0x102);

    if (0x7f < DVar4) break;

    if (2 < (int)DVar4) {

      uVar3 = FUN_0076cec0(local_10,"Invalid mutex index: %d",DVar4);

      uVar5 = 0x66;

      goto LAB_006728a3;

    }

    if (DVar4 == 0) goto LAB_006728b0;

    if (DVar4 == 1) {

      (**(code **)(*param_1 + 0xc))();

    }

    else if (DVar4 == 2) {

      FUN_00672440();

    }

  }

  uVar3 = FUN_0076cec0(local_10,"Bad mutex object: %d",DVar4 - 0x80);

  uVar5 = 0x5e;

LAB_006728a3:

  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                 ,uVar5,2,uVar3);

LAB_006728b0:

  if (param_1[0x26] != 0) {

    (**(code **)(*(int *)param_1[0x26] + 0x28))((int *)param_1[0x26]);

  }

  piVar1 = (int *)param_1[0x27];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  param_1[0x27] = 0;

  piVar1 = (int *)param_1[0x26];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  param_1[0x26] = 0;

  piVar1 = (int *)param_1[0x25];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  param_1[0x25] = 0;

  return;

}
