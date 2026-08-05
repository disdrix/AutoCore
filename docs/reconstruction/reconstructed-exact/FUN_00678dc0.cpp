// =============================================================================
// FUN_00678dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00678dc0
// Address:   0x00678dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00678dc0 @ 0x00678dc0
// Stable ID: aa_00678dc0
// Embedded strings (evidence for future rename):
//   - "Couldnt create playback sound buffer\n"
//   - "Couldnt create 3D playback sound buffer\n"
//   - "Couldnt set 3d buffer mode\n"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutStream.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, goto×1.
//  - Notable callees: FUN_0076cec0×3, FUN_00678dc0, thunk_FUN_0076c4d0, vog_LogMessage.
//  - Strings: "Couldnt create playback sound buffer\n"; "Couldnt create 3D playback sound buffer\n"; "Couldnt set 3d buffer mode\n".
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

uint32_t /* width from decompiler */ __thiscall

FUN_00678dc0(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  param_1[3] = param_3;

  param_1[1] = param_2;

  param_1[0x1b] = param_4;

  param_1[2] = *(uint32_t /* width from decompiler */ *)(param_4 + 0xc);

  iVar4 = *(int *)(param_2 + 4) * 4;

  param_1[7] = iVar4;

  pvVar3 = operator_new__(iVar4 + 1);

  *param_1 = pvVar3;

  local_1c = param_1[7];

  local_18 = 0;

  local_10 = DAT_00aa9110;

  local_c = DAT_00aa9114;

  local_14 = param_1[1];

  local_24 = 0x24;

  local_20 = 0x18180;

  local_8 = DAT_00aa9118;

  local_4 = DAT_00aa911c;

  if (param_5 != 0) {

    local_20 = 0x18190;

  }

  iVar4 = (**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],&local_24,param_1 + 4,0);

  if (iVar4 < 0) {

    uVar5 = FUN_0076cec0(&local_c,"Couldnt create playback sound buffer\n");

    uVar6 = 0x71;

  }

  else {

    if (param_5 == 0) {

LAB_00678f11:

      if ((void *)param_1[0xc] != (void *)0x0) {

        operator_delete__((void *)param_1[0xc]);

        param_1[0xc] = 0;

      }

      iVar4 = *(int *)(param_1[0x1b] + 0xc);

      param_1[2] = iVar4;

      pvVar3 = operator_new__(iVar4 + 4);

      param_1[0xc] = pvVar3;

      param_1[6] = 0;

      param_1[0x1c] = 0;

      param_1[0x1d] = 0;

      *(uint8_t *)(param_1 + 0x1e) = 0;

      thunk_FUN_0076c4d0();

      pvVar3 = operator_new__(param_1[0x23]);

      param_1[0x22] = pvVar3;

      return 0;

    }

    puVar1 = (uint32_t /* width from decompiler */ *)param_1[4];

    iVar4 = (**(code **)*puVar1)(puVar1,&DAT_00a0d034,param_1 + 5);

    if (iVar4 < 0) {

      uVar5 = FUN_0076cec0(&local_c,"Couldnt create 3D playback sound buffer\n");

      uVar6 = 0x79;

    }

    else {

      piVar2 = (int *)param_1[5];

      iVar4 = (**(code **)(*piVar2 + 0x48))(piVar2,0,0);

      if (-1 < iVar4) goto LAB_00678f11;

      uVar5 = FUN_0076cec0(&local_c,"Couldnt set 3d buffer mode\n");

      uVar6 = 0x7e;

    }

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutStream.cpp"

                 ,uVar6,3,uVar5);

  return 0xffffffff;

}
