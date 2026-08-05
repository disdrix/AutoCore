// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×5.
//  - Notable callees: FUN_006a5dac×3, FUN_006b7a5a×3, FUN_0076cec0×3, vog_LogMessage×3, DirectSoundCreate8, FUN_00720d40, FUN_007225e0, FUN_00724180.
//  - Strings: "%s - %s\r\n%s"; "Failed to set cooperative level on DXSound device"; "Failed to set primary buffer format on DXSound device".
//  - Return sites: 5.

// =============================================================================
// Named_VOGSoundManager_00724180
// -----------------------------------------------------------------------------
// Stable ID: aa_00724180
// Address:   0x00724180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGSoundManager"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_VOGSoundManager_00724180(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piStack_c;

  

  if ((char)in_EAX[0x96] == '\0') {

    piStack_c = (int *)0x724192;

    iVar1 = FUN_00720d40();

    if (*(char *)(iVar1 + 0x10) == '\0') {

      return 0;

    }

  }

  piStack_c = (int *)*in_EAX;

  if (piStack_c != (int *)0x0) {

    (**(code **)(*piStack_c + 8))();

    *in_EAX = 0;

  }

  piStack_c = (int *)0x0;

  iVar1 = DirectSoundCreate8(&DAT_00a0d054,in_EAX);

  if (iVar1 < 0) {

    piStack_c = (int *)0xaa93a8;

    uVar2 = FUN_006b7a5a(iVar1);

    uVar2 = FUN_006a5dac(iVar1,uVar2);

    uVar2 = FUN_0076cec0(&stack0x00000000,"%s - %s\r\n%s",uVar2);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOGAudio\\VOGSoundManager.cpp",0xda,3,

                   uVar2);

    return iVar1;

  }

  piStack_c = param_2;

  iVar1 = (**(code **)(*(int *)*in_EAX + 0x18))((int *)*in_EAX,param_1);

  if (iVar1 < 0) {

    uVar2 = FUN_006b7a5a(iVar1,"Failed to set cooperative level on DXSound device");

    uVar2 = FUN_006a5dac(iVar1,uVar2);

    uVar2 = FUN_0076cec0(&piStack_c,"%s - %s\r\n%s",uVar2);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOGAudio\\VOGSoundManager.cpp",0xe1,3,

                   uVar2);

    return iVar1;

  }

  iVar1 = FUN_007225e0(in_EAX,2,0xac44);

  if (-1 < iVar1) {

    return 0;

  }

  uVar2 = FUN_006b7a5a(iVar1,"Failed to set primary buffer format on DXSound device");

  uVar2 = FUN_006a5dac(iVar1,uVar2);

  uVar2 = FUN_0076cec0(&piStack_c,"%s - %s\r\n%s",uVar2);

  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOGAudio\\VOGSoundManager.cpp",0xe9,3,uVar2

                );

  return iVar1;

}
