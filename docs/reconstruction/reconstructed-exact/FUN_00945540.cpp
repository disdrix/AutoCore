// =============================================================================
// FUN_00945540
// -----------------------------------------------------------------------------
// Stable ID: aa_00945540
// Address:   0x00945540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00945540 @ 0x00945540
// Stable ID: aa_00945540
// Embedded strings (evidence for future rename):
//   - "lootpickup"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×18, goto×5, return×2, while×1.
//  - Notable callees: FUN_004022a0×2, CVOGCharacter_AddCredits, Client_GetMissionCompleteAudioTable, Client_PlayNamedInterfaceSound, Client_RefreshOpenMissionUiWindows, FUN_0040abf0, FUN_004294f0, FUN_004bb970.
//  - Strings: "lootpickup".
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

uint32_t /* width from decompiler */ FUN_00945540(int param_1)



{

  int iVar1;

  bool bVar2;

  bool bVar3;

  char cVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int iVar9;

  int *unaff_EDI;

  char *pcVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uVar14;

  uint32_t /* width from decompiler */ uVar15;

  int iStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  int iStack_c;

  uint uStack_8;

  uint uStack_4;

  

  bVar3 = false;

  if (((unaff_EDI == (int *)0x0) || (*(int *)(param_1 + 0xe98) == 0)) ||

     (cVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                   *(int *)(param_1 + 0xe98)) + 0x194))(), cVar4 != '\0')) {

    return 0;

  }

  iVar1 = *(int *)(param_1 + 0x4d0);

  cVar4 = FUN_0092a200();

  if (cVar4 != '\0') {

    *(uint8_t *)(iVar1 + 4) = 1;

  }

  iVar1 = *(int *)(unaff_EDI[0x2a] + 0x38);

  uStack_4 = uStack_4 & 0xffffff00;

  uStack_8 = uStack_8 & 0xffffff00;

  iStack_14 = 0;

  bVar2 = false;

  cVar4 = FUN_00513e70();

  if (cVar4 == '\0') {

LAB_00945725:

    if (*(int *)(unaff_EDI[0x2a] + 0x38) == 0x42) {

      iVar8 = (**(code **)(*unaff_EDI + 0x168))();

      CVOGCharacter_AddCredits(*(void **)(param_1 + 0xe98),(longlong)iVar8);

      goto LAB_009457fc;

    }

    FUN_005714e0(unaff_EDI,&uStack_4,&uStack_8,1,0xffffffff);

    uVar6 = (**(code **)(*unaff_EDI + 0x25c))();

    cVar4 = FUN_00571620(unaff_EDI,uStack_4,uStack_8,uVar6);

    if (cVar4 != '\0') {

      iVar8 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

      if (iVar8 != 0) {

        iVar8 = *(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8;

      }

      (**(code **)(*unaff_EDI + 0x158))(iVar8);

      (**(code **)(*unaff_EDI + 0x2ac))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xd34));

      if (*(int **)(param_1 + 0x1098) != (int *)0x0) {

        cVar4 = (**(code **)(**(int **)(param_1 + 0x1098) + 0x3d8))();

        goto joined_r0x009457f3;

      }

      goto LAB_009457fc;

    }

  }

  else {

    iVar9 = *(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 0x250) + 0x2b0) + 0x2c;

    uStack_10 = 0;

    iStack_c = iVar9;

    FUN_004294f0();

    iVar5 = FUN_004022a0(&uStack_10,&iStack_14);

    iVar8 = iStack_14;

    while (iStack_14 = iVar8, iVar5 == 0) {

      if (((iVar8 != 0) &&

          (*(int *)(*(int *)(iVar8 + 0xa8) + 0x34) == *(int *)(unaff_EDI[0x2a] + 0x34))) &&

         (((*(uint *)(iVar8 + 0x17c) >> 0x13 & 1) == 0 && (((uint)unaff_EDI[0x5f] >> 0x13 & 1) == 0)

          ))) {

        uVar6 = (**(code **)(*unaff_EDI + 0x25c))();

        cVar4 = FUN_0040abf0(uVar6);

        if (cVar4 != '\0') {

          bVar2 = true;

          iVar5 = TFID_NotEquals(unaff_EDI + 0x58,(void *)(iVar8 + 0x160));

          iVar9 = iStack_c;

          if ((char)iVar5 != '\0') {

            FUN_004bb970((char)unaff_EDI[0x5a],unaff_EDI[0x58],unaff_EDI[0x59]);

            iVar9 = iStack_c;

          }

          break;

        }

      }

      iVar5 = FUN_004022a0(&uStack_10,&iStack_14);

      iVar8 = iStack_14;

    }

    if (*(char *)(iVar9 + 0x28) != '\0') {

      *(uint8_t *)(iVar9 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar9 + 4));

    }

    if ((!bVar2) || (iVar8 == 0)) goto LAB_00945725;

    uVar6 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x164);

    uVar12 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x160);

    uVar7 = (**(code **)(*unaff_EDI + 0x25c))(uVar12,uVar6);

    FUN_00571830(uVar7,uVar12,uVar6);

    if (*(int **)(param_1 + 0x1098) != (int *)0x0) {

      cVar4 = (**(code **)(**(int **)(param_1 + 0x1098) + 0x3d8))();

joined_r0x009457f3:

      if (cVar4 != '\0') {

        FUN_008bf070();

      }

    }

LAB_009457fc:

    bVar3 = true;

  }

  iVar8 = (**(code **)(*unaff_EDI + 0x1cc))();

  if (iVar8 != 0) {

    uVar12 = 0;

    uVar6 = (**(code **)(*unaff_EDI + 0x1cc))(0);

    FUN_004bfdb0(uVar6,uVar12);

    iVar8 = (**(code **)(*unaff_EDI + 0x1cc))();

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x1b4))(1);

    iVar8 = (**(code **)(*unaff_EDI + 0x1cc))();

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0xfc))();

  }

  if (*(char *)(param_1 + 0x9e6) != '\0') {

    if (!bVar3) goto LAB_009458b4;

    uVar15 = 0;

    uVar14 = 0x1e;

    uVar13 = 0;

    uVar11 = 0;

    uVar7 = 0xffffffff;

    uVar12 = 0xffffffff;

    uVar6 = 0;

    pcVar10 = "lootpickup";

    Client_GetMissionCompleteAudioTable("lootpickup",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar10,uVar6,uVar12,uVar7,uVar11,uVar13,uVar14,uVar15);

  }

  if ((bVar3) && (iVar1 == 4)) {

    FUN_007fe720(param_1,2,1,0);

  }

LAB_009458b4:

  Client_RefreshOpenMissionUiWindows(param_1);

  return 1;

}
