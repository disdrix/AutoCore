// =============================================================================
// Phy_Start_ReinitPhysics
// -----------------------------------------------------------------------------
// Stable ID: aa_009463b0
// Address:   0x009463b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Phy_Start_ReinitPhysics @ 0x009463b0
// Stable ID: aa_009463b0
// Embedded strings (evidence for future rename):
//   - "start reinitPhysics"
//   - "Evicting ALL managed resources prior to map transition"
//   - "Swapping the process out of physical RAM prior to map transition"
//   - "before setmapinfo"
//   - ".fam"
//   - "

// READABILITY (auto CF):
//  - Body size: ~165 non-empty decompiler lines.
//  - Control keywords: if×9, do×7, while×7, for×6, return×4, goto×2.
//  - Notable callees: FUN_007a4480×6, PathFileExistsA×2, FUN_004069b0, FUN_00406bc0, FUN_00406c00, FUN_004ce020, FUN_004ce230, FUN_007a69d0.
//  - Strings: "start reinitPhysics"; "Evicting ALL managed resources prior to map transition"; "before setmapinfo"; ".fam".
//  - Return sites: 4.

    ;

    FUN_007a69d0("
// Readability: control flow preserved from Ghidra decompile; types tentative.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "start reinitPhysics"
 * Domain alias of FUN_009463b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Phy_Start_ReinitPhysics(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  int in_EAX;

  HANDLE hProcess;

  char *pcVar4;

  int iVar5;

  BOOL BVar6;

  uint8_t auVar7 [4];

  uint uVar8;

  uint uVar9;

  char *pcVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uVar14;

  SIZE_T dwMinimumWorkingSetSize;

  uint32_t /* width from decompiler */ uVar15;

  SIZE_T dwMaximumWorkingSetSize;

  uint32_t /* width from decompiler */ uVar16;

  uint8_t auStack_210 [4];

  char acStack_20c [4];

  uint8_t auStack_208 [255];

  char cStack_109;

  char acStack_108 [264];

  

  FUN_007a4480(0,"start reinitPhysics");

  *(uint8_t *)(param_1 + 0xb7) = 0;

  FUN_009432f0();

  FUN_009302b0();

  FUN_004069b0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xd1c) + 4));

  *(int *)(*(int *)(param_1 + 0xd1c) + 4) = *(int *)(param_1 + 0xd1c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd20) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0xd1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xd1c);

  *(int *)(*(int *)(param_1 + 0xd1c) + 8) = *(int *)(param_1 + 0xd1c);

  FUN_00406bc0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xf18) + 4));

  *(int *)(*(int *)(param_1 + 0xf18) + 4) = *(int *)(param_1 + 0xf18);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf1c) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0xf18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf18);

  *(int *)(*(int *)(param_1 + 0xf18) + 8) = *(int *)(param_1 + 0xf18);

  FUN_00406c00(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xf24) + 4));

  *(int *)(*(int *)(param_1 + 0xf24) + 4) = *(int *)(param_1 + 0xf24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf28) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0xf24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf24);

  *(int *)(*(int *)(param_1 + 0xf24) + 8) = *(int *)(param_1 + 0xf24);

  FUN_007a4480(0,"Evicting ALL managed resources prior to map transition");

  (**(code **)(*(int *)*DAT_00d1f044 + 0x14))((int *)*DAT_00d1f044);

  if (*(char *)(param_1 + 0x9e0) != '\0') {

    FUN_007a4480(0,"Swapping the process out of physical RAM prior to map transition");

    dwMaximumWorkingSetSize = 0xffffffff;

    dwMinimumWorkingSetSize = 0xffffffff;

    hProcess = GetCurrentProcess();

    SetProcessWorkingSetSize(hProcess,dwMinimumWorkingSetSize,dwMaximumWorkingSetSize);

  }

  FUN_007a4480(0,"before setmapinfo");

  if (in_EAX == 0) {

    FUN_004ce020(param_1 + 0x750);

    *(uint8_t *)(*(int *)(param_1 + 0xe04) + 0x100) = *(uint8_t *)(param_1 + 0x1e);

    *(uint8_t *)(*(int *)(param_1 + 0xe04) + 0x7c) = *(uint8_t *)(param_1 + 0x858);

  }

  else {

    FUN_004ce230(in_EAX);

    pcVar10 = (char *)(param_1 + 0x750);

    pcVar4 = (char *)(*(int *)(param_1 + 0xe04) + 0xe198);

    do {

      cVar3 = *pcVar4;

      *pcVar10 = cVar3;

      pcVar4 = pcVar4 + 1;

      pcVar10 = pcVar10 + 1;

    } while (cVar3 != '\0');

    *(uint *)(param_1 + 0x858) = (uint)*(byte *)(*(int *)(param_1 + 0xe04) + 0x7c);

  }

  pcVar10 = (char *)(param_1 + 0x750);

  iVar5 = -(int)pcVar10;

  do {

    cVar3 = *pcVar10;

    pcVar10[(int)(acStack_20c + iVar5)] = cVar3;

    pcVar10 = pcVar10 + 1;

  } while (cVar3 != '\0');

  pcVar10 = strstr(acStack_20c,".fam");

  if (pcVar10 == (char *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)(auStack_210 + 3);

    do {

      puVar12 = puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

    } while (*(char *)((int)puVar12 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar12 + 1) = DAT_00a285c4;

    *(uint8_t *)((int)puVar12 + 5) = DAT_00a285c8;

  }

  iVar5 = FUN_007b6a20();

  if ((*(byte *)(iVar5 + 4) & 1) != 0) {

    BVar6 = PathFileExistsA(acStack_20c);

    if (BVar6 != 0) goto LAB_0094667e;

    auStack_210 = (uint8_t  [4])FUN_007b6420();

    pcVar10 = (char *)&DAT_00d1e574;

    do {

      pcVar4 = pcVar10;

      if (0xf < *(uint *)(pcVar10 + 0x14)) {

        pcVar4 = *(char **)pcVar10;

      }

      pcVar11 = acStack_108;

      do {

        cVar3 = *pcVar4;

        *pcVar11 = cVar3;

        pcVar4 = pcVar4 + 1;

        pcVar11 = pcVar11 + 1;

        auVar7 = auStack_210;

      } while (cVar3 != '\0');

      do {

        cVar3 = *(char *)auVar7;

        auVar7 = (uint8_t  [4])((int)auVar7 + 1);

      } while (cVar3 != '\0');

      uVar8 = (int)auVar7 - (int)auStack_210;

      pcVar4 = &cStack_109;

      do {

        pcVar11 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar11 != '\0');

      auVar7 = auStack_210;

      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)auVar7;

        auVar7 = (uint8_t  [4])((int)auVar7 + 4);

        pcVar4 = pcVar4 + 4;

      }

      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

        *pcVar4 = *(char *)auVar7;

        auVar7 = (uint8_t  [4])((int)auVar7 + 1);

        pcVar4 = pcVar4 + 1;

      }

      BVar6 = PathFileExistsA(acStack_108);

      if (BVar6 != 0) goto LAB_0094667e;

      pcVar10 = pcVar10 + 0x1c;

    } while ((int)pcVar10 < 0xd1e7a4);

  }

  cVar3 = FUN_007b66c0(iVar5);

  if (cVar3 == '\0') {

    FUN_00944b20(1);

    uVar16 = 0;

    uVar15 = 1;

    uVar14 = 0xffffffff;

    uVar13 = 0xffffffff;

    pcVar10 = 

    "You have not yet downloaded content for the area you attempted to enter.\nTo download this content, please return to the patcher and click the \"All Regions\" button, then click the patch button again.\nHigher level content may not be available for those who have not preordered."

    ;

    FUN_007a69d0("You have not yet downloaded content for the area you attempted to enter.\nTo download this content, please return to the patcher and click the \"All Regions\" button, then click the patch button again.\nHigher level content may not be available for those who have not preordered."

                 ,0xffffffff,0xffffffff,1,0);

    uVar13 = FUN_007a6de0(pcVar10,uVar13);

    FUN_007fdfb0(param_1,uVar13,uVar14,uVar15,uVar16);

    return 0x80004005;

  }

LAB_0094667e:

  if (*(char *)(*(int *)(param_1 + 0xe04) + 0xf5) == '\0') {

    fVar1 = *(float *)(param_1 + 0x874);

  }

  else {

    fVar1 = *(float *)(param_1 + 0x870);

  }

  FUN_0092f140((int)fVar1);

  FUN_007a4480(0,"before initphysics");

  FUN_00932060();

  *(uint8_t *)(*(int *)(param_1 + 0xe04) + 0x80) = 1;

  FUN_007a4480(0,"end of reinitphysics");

  return 0;

}
