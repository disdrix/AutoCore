// =============================================================================
// FUN_008028e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008028e0
// Address:   0x008028e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008028e0 @ 0x008028e0
// Stable ID: aa_008028e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×10, while×1, return×1.
//  - Notable callees: Client_SendSectorPacket×2, Client_MaybeShowFirstTimeTip, FUN_00411180, FUN_004c3f10, FUN_007fbcf0, FUN_007fbd10, FUN_007fef20, FUN_008028e0.
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

void __thiscall FUN_008028e0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  void *pvVar3;

  int *piVar4;

  int iStack_34;

  uint32_t /* width from decompiler */ auStack_2c [2];

  int iStack_24;

  int iStack_20;

  uint8_t uStack_1c;

  uint uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &DAT_009bb4cc;

  local_c = ExceptionList;

  if ((((param_1 != (int *)0x0) && (DAT_00d1b778 != (int *)0x0)) &&

      (ExceptionList = &local_c, cVar1 = (**(code **)(*DAT_00d1b778 + 0x3d8))(), cVar1 != '\0')) &&

     ((iVar2 = (**(code **)(*param_1 + 0x1d8))(), iVar2 == 0 ||

      (iVar2 = (**(code **)(*param_1 + 0x1d8))(), (*(uint *)(iVar2 + 0x200) >> 4 & 1) == 0)))) {

    Client_MaybeShowFirstTimeTip(0xf);

    if (DAT_00d1b6d8 == 0) {

      iStack_34 = 0;

    }

    else {

      iStack_34 = FUN_004c3f10(1);

      if ((DAT_00d1b6d8 != 0) && (0 < iStack_34)) {

        FUN_007fef20(0x32,1,0);

      }

    }

    if (DAT_00d1b938 != 0) {

      FUN_0088ba30(param_2);

    }

    iVar2 = (**(code **)(*param_1 + 0x214))();

    if (iVar2 != 0) {

      iStack_24 = param_1[0x58];

      iStack_20 = param_1[0x59];

      auStack_2c[0] = 0x20a4;

      uStack_1c = 2;

      uStack_14 = FUN_007fbd10();

      uStack_14 = uStack_14 & 0xff;

      uStack_10 = 0;

      Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_2c);

      uStack_1c = 1;

      uStack_14 = FUN_007fbcf0();

      uStack_14 = uStack_14 & 0xffff;

      uStack_10 = 0;

      Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_2c);

    }

    while( true ) {

      piVar4 = (int *)0x0;

      if (DAT_00d1b778[0x328] == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = DAT_00d1b778[0x329] - DAT_00d1b778[0x328] >> 2;

      }

      if (iStack_34 <= iVar2) break;

      pvVar3 = operator_new(0x538);

      uStack_4 = 0;

      if (pvVar3 != (void *)0x0) {

        piVar4 = (int *)FUN_0087d250(pvVar3);

      }

      uStack_4 = 0xffffffff;

      (**(code **)(*DAT_00d1b778 + 0xa8))(piVar4);

      if ((char)piVar4[0x14a] != '\x01') {

        *(uint8_t *)(piVar4 + 0x14a) = 1;

        (**(code **)(*piVar4 + 0x34c))();

      }

      if (piVar4[0x14b] != 3) {

        piVar4[0x14b] = 3;

        (**(code **)(*piVar4 + 0x34c))();

      }

      (**(code **)(*piVar4 + 0x43c))();

      (**(code **)(*piVar4 + 0xcc))(0);

      piVar4[0x14d] = DAT_00aaac00;

      piVar4[0x14c] = 0;

      FUN_00411180();

    }

  }

  ExceptionList = local_c;

  return;

}
