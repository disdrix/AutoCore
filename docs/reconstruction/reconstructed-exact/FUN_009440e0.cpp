// =============================================================================
// FUN_009440e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009440e0
// Address:   0x009440e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009440e0 @ 0x009440e0
// Stable ID: aa_009440e0
// Embedded strings (evidence for future rename):
//   - "Attempting to delete your character... bad bad"
//   - "!!!!CompletelyDestroyObject COID:%I64d global:%d CBID:%d Unique:%s force:%d death:%d"
//   - "C:\\vog\\1_code\\vog_14_117_branch\\appClient\\VOGClient.cpp"
//   - "Object %I64d (%d) isn\'t a valid object to delete. Most likely a map synch issue."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~203 non-empty decompiler lines.
//  - Control keywords: if×36, return×5.
//  - Notable callees: FUN_004024b0×4, FUN_004d3310×2, FUN_004d9b50×2, FUN_007a4480×2, FUN_007fca10×2, FUN_008718a0×2, FUN_00933370×2, CONCAT13.
//  - Strings: "Attempting to delete your character... bad bad"; "C:\\vog\\1_code\\vog_14_117_branch\\appClient\\VOGClient.cpp".
//  - Return sites: 5.

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

void FUN_009440e0(int *param_1,uint param_2,uint param_3)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  uint8_t uVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ unaff_EBP;

  int *unaff_ESI;

  int *piVar11;

  uint32_t /* width from decompiler */ *unaff_EDI;

  char unaff_retaddr;

  uint32_t /* width from decompiler */ local_4;

  

  iVar7 = unaff_EDI[0x3a6];

  if (iVar7 == 0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7);

  }

  if (param_1 == piVar5) {

    FUN_007a4480(1,"Attempting to delete your character... bad bad");

    return;

  }

  if (param_1[0x2a] == 0) {

    local_4 = 0xffffffff;

  }

  else {

    local_4 = *(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x34);

  }

  uVar6 = FUN_0076cec0(&param_2,

                       "!!!!CompletelyDestroyObject COID:%I64d global:%d CBID:%d Unique:%s force:%d death:%d"

                       ,param_1[0x58],param_1[0x59],(char)param_1[0x5a],local_4,param_1[0x2a] + 0x40

                       ,param_2 & 0xff,param_3);

  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\appClient\\VOGClient.cpp",0x1366,0,uVar6);

  iVar7 = unaff_EDI[0x134];

  cVar3 = FUN_0092a200();

  if (cVar3 != '\0') {

    *(uint8_t *)(iVar7 + 4) = 1;

  }

  if (((unaff_EDI[0x3a6] != 0) && (*(char *)(unaff_EDI[0x3a6] + 0x4f1) != '\0')) &&

     ((int *)unaff_EDI[0x382] == param_1)) {

    unaff_EDI[0x382] = 0;

    FUN_0092d730();

  }

  piVar5 = (int *)(**(code **)(*param_1 + 0x1cc))();

  if (piVar5 == (int *)0x0) {

    FUN_007a4480(1,

                 "Object %I64d (%d) isn\'t a valid object to delete. Most likely a map synch issue."

                 ,param_1[0x58],param_1[0x59],*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x34));

  }

  FUN_0093ffb0(unaff_EDI);

  uVar4 = (**(code **)(*param_1 + 0x50))(param_3);

  param_2 = CONCAT31(param_2._1_3_,uVar4);

  CVOGObject_SetInteractSpecialFX(param_1,(void *)0x0);

  (**(code **)*unaff_EDI)(param_1);

  iVar7 = *(int *)(param_1[0x2a] + 0x38);

  piVar11 = param_1;

  if (iVar7 == 0xe) {

    iVar7 = (**(code **)(*param_1 + 0x1d4))();

    if (((unaff_EDI[0x3a6] != 0) && (iVar8 = *(int *)(unaff_EDI[0x3a6] + 0x250), iVar8 != 0)) &&

       (iVar7 == iVar8)) {

      FUN_00802170();

    }

    if (iVar7 == 0) {

      return;

    }

    if ((unaff_retaddr == '\0') && ((char)param_1 == '\0')) {

      return;

    }

    if ((unaff_EDI[0x3a6] != 0) && (iVar7 == *(int *)(unaff_EDI[0x3a6] + 0x250))) {

      return;

    }

    piVar1 = *(int **)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xb0 + iVar7);

    if (((piVar1 != (int *)0x0) && (iVar8 = (**(code **)(*piVar1 + 0x1d8))(), iVar8 != 0)) &&

       (iVar9 = *(int *)(iVar8 + 0x250), iVar9 == iVar7)) {

      if (iVar9 != 0) {

        (**(code **)*unaff_EDI)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9);

      }

      if (*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac + iVar8) + 0x38) == 0x14) {

        if (unaff_EDI[0x3a6] != 0) {

          iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x1dc))();

          iVar7 = *(int *)(*(int *)(iVar9 + 4) + 4);

          if ((*(int *)(iVar7 + 0x164 + iVar9) == *(int *)(unaff_EDI[0x3a6] + 0xcd8)) &&

             (*(int *)(iVar7 + 0x168 + iVar9) == *(int *)(unaff_EDI[0x3a6] + 0xcdc))) {

            FUN_007fca10();

          }

        }

        if ((((int *)unaff_EDI[0x433] != (int *)0x0) &&

            (cVar3 = (**(code **)(*(int *)unaff_EDI[0x433] + 0xd0))(), cVar3 != '\0')) &&

           (cVar3 = (**(code **)(*(int *)unaff_EDI[0x433] + 0x3d8))(), cVar3 != '\0')) {

          iVar7 = *(int *)(*(int *)(iVar8 + 4) + 4);

          FUN_008718a0(*(uint32_t /* width from decompiler */ *)(iVar7 + 0x164 + iVar8),*(uint32_t /* width from decompiler */ *)(iVar7 + 0x168 + iVar8)

                      );

          piVar11 = piVar5;

        }

      }

      iVar7 = FUN_004024b0();

      uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x1dc))();

      FUN_004d9b50(uVar6);

      iVar9 = FUN_004024b0();

      if (iVar9 != iVar7) {

        uVar10 = (uint)(unaff_EDI[0x3a6] != 0);

        uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x1dc))

                          (uVar10);

        FUN_004d3310(uVar6,uVar10);

      }

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x2a8))

                (unaff_EDI[0x34d]);

      (**(code **)*unaff_EDI)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8);

      FUN_00933370(unaff_EDI);

      unaff_EBP = 0x1010000;

    }

  }

  else if ((iVar7 == 0x14) || (iVar7 == 0x12)) {

    iVar7 = (**(code **)(*param_1 + 0x1d8))();

    if (iVar7 != 0) {

      iVar8 = *(int *)(iVar7 + 0x250);

      if (iVar8 != 0) {

        (**(code **)*unaff_EDI)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8);

      }

      if (((unaff_EDI[0x3a6] != 0) && (*(int *)(param_1[0x2a] + 0x38) == 0x14)) &&

         ((iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x1dc))(),

          iVar8 != 0 &&

          (((iVar9 = unaff_EDI[0x3a6], iVar8 != iVar9 &&

            (iVar2 = *(int *)(*(int *)(iVar8 + 4) + 4),

            *(int *)(iVar2 + 0x164 + iVar8) == *(int *)(iVar9 + 0xcd8))) &&

           (*(int *)(iVar2 + 0x168 + iVar8) == *(int *)(iVar9 + 0xcdc))))))) {

        FUN_007fca10();

      }

      if ((((int *)unaff_EDI[0x433] != (int *)0x0) &&

          (cVar3 = (**(code **)(*(int *)unaff_EDI[0x433] + 0xd0))(), cVar3 != '\0')) &&

         (cVar3 = (**(code **)(*(int *)unaff_EDI[0x433] + 0x3d8))(), cVar3 != '\0')) {

        iVar8 = *(int *)(*(int *)(iVar7 + 4) + 4);

        FUN_008718a0(*(uint32_t /* width from decompiler */ *)(iVar8 + 0x164 + iVar7),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x168 + iVar7));

        piVar11 = piVar5;

      }

      if ((*(int *)(piVar11[0x2a] + 0x38) == 0x14) && (unaff_EDI[0x381] != 0)) {

        iVar8 = FUN_004024b0();

        uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x1dc))();

        FUN_004d9b50(uVar6);

        iVar9 = FUN_004024b0();

        if (iVar9 != iVar8) {

          uVar10 = (uint)(unaff_EDI[0x3a6] != 0);

          uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x1dc))

                            (uVar10);

          FUN_004d3310(uVar6,uVar10);

        }

      }

    }

  }

  else if (iVar7 == 0x16) {

    cVar3 = (**(code **)(*(int *)unaff_EDI[0x417] + 0x3d8))();

    if (cVar3 != '\0') {

      FUN_007fef20(0xb,0,0);

    }

  }

  else {

    if ((((int *)param_1[0x2b] != (int *)0x0) &&

        (iVar7 = (**(code **)(*(int *)param_1[0x2b] + 0x210))(0), iVar7 != unaff_EDI[0x3a6])) &&

       (iVar7 = (**(code **)(*(int *)param_1[0x2b] + 0x1d4))(), iVar7 != 0)) {

      iVar7 = param_1[0x59];

      iVar8 = param_1[0x58];

      (**(code **)(*(int *)param_1[0x2b] + 0x1d4))(iVar8,iVar7);

      cVar3 = FUN_004f70f0(iVar8,iVar7);

      if (cVar3 != '\0') {

        piVar5 = param_1;

        (**(code **)(*(int *)param_1[0x2b] + 0x1d4))(param_1);

        FUN_00504f60(piVar5);

      }

    }

    if ((((param_2 & param_3) != 0xffffffff) && (unaff_EDI[0x3a6] != 0)) &&

       (cVar3 = FUN_00571b60(param_1), cVar3 == '\0')) {

      (**(code **)(*param_1 + 0x2a8))(unaff_EDI[0x34d]);

      unaff_EBP = CONCAT13((char)((uint)unaff_EBP >> 0x18),0x10000);

    }

    if (((param_1[0x2b] == 0) && ((char)param_1[0x5a] == '\0')) &&

       ((param_1[0x33] != 0 && (unaff_EDI[0x3a6] != 0)))) {

      Client_MaybeShowFirstTimeTip(0x14);

    }

  }

  if ((unaff_retaddr != '\0') || ((char)param_1 != '\0')) {

    if ((char)((uint)unaff_EBP >> 0x10) == '\0') {

      (**(code **)(*piVar11 + 0x2a8))(unaff_EDI[0x34d]);

    }

    else if (((char)((uint)unaff_EBP >> 0x18) == '\0') && (unaff_ESI != (int *)0x0)) {

      (**(code **)(*unaff_ESI + 0x1c))(0);

    }

    cVar3 = (char)((uint)unaff_EBP >> 0x18);

    if ((unaff_EDI[0x381] != 0) && (*(int *)(unaff_EDI[0x381] + 0xe898) != 0)) {

      FUN_004962b0();

    }

    if (cVar3 == '\0') {

      FUN_00933370(unaff_EDI);

    }

  }

  return;

}
