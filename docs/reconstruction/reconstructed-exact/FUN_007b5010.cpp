// =============================================================================
// FUN_007b5010
// -----------------------------------------------------------------------------
// Stable ID: aa_007b5010
// Address:   0x007b5010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b5010 @ 0x007b5010
// Stable ID: aa_007b5010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~155 non-empty decompiler lines.
//  - Control keywords: if×14, return×9, do×4, while×4, for×1, goto×1.
//  - Notable callees: FUN_00798720×10, CONCAT31×4, strncpy×4, CONCAT13, FUN_007b5010.
//  - Return sites: 9.

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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall FUN_007b5010(uint32_t /* width from decompiler */ *param_1,char *param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  size_t sVar5;

  char *pcVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int unaff_ESI;

  size_t _Count;

  uint32_t /* width from decompiler */ uVar11;

  uint8_t uVar12;

  uint32_t /* width from decompiler */ local_1010;

  char local_1000 [2048];

  char acStack_800 [2044];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x7b501a;

  if (*(int *)(unaff_ESI + 0x290) == 0) {

    return;

  }

  iVar9 = *(int *)(unaff_ESI + 700);

  if (iVar9 == 0) {

    if ((DAT_00d17940 != (code *)0x0) &&

       (cVar2 = (*DAT_00d17940)(param_2,local_1000), cVar2 != '\0')) {

      FUN_00798720(param_3,local_1000,*param_1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290),

                   *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130),*(uint8_t *)(unaff_ESI + 0xcb));

      return;

    }

    FUN_00798720(param_3,param_2,*param_1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130),*(uint8_t *)(unaff_ESI + 0xcb));

    return;

  }

  if (iVar9 != 1) {

    if (iVar9 != 2) {

      return;

    }

    if ((DAT_00d17940 == (code *)0x0) ||

       (cVar2 = (*DAT_00d17940)(param_2,local_1000), cVar2 == '\0')) {

      iVar9 = -(int)param_2;

      do {

        cVar2 = *param_2;

        param_2[(int)(local_1000 + iVar9)] = cVar2;

        param_2 = param_2 + 1;

      } while (cVar2 != '\0');

    }

    pcVar6 = local_1000;

    pcVar3 = local_1000 + 1;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    iVar9 = *param_4;

    if ((int)(*(float *)(unaff_ESI + 0x2c4) - DAT_00aaa8dc) <= (int)(pcVar6 + (iVar9 - (int)pcVar3))

       ) {

      if (*(float *)(unaff_ESI + 0x2c4) <= (float)iVar9) {

        FUN_00798720(param_3,local_1000,0,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290),

                     *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130),

                     CONCAT31((int3)((uint)(pcVar6 + (iVar9 - (int)pcVar3)) >> 8),

                              *(uint8_t *)(unaff_ESI + 0xcb)));

        *param_4 = (int)(pcVar6 + (*param_4 - (int)pcVar3));

        return;

      }

      sVar5 = (size_t)(*(float *)(unaff_ESI + 0x2c4) - (float)iVar9);

      strncpy(acStack_800,local_1000,sVar5);

      uVar12 = *(uint8_t *)(unaff_ESI + 0xcb);

      uVar11 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130);

      uVar1 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290);

      acStack_800[sVar5] = '\0';

      FUN_00798720(param_3,acStack_800,*param_1,uVar1,uVar11,uVar12);

      strncpy(acStack_800,local_1000 + sVar5,(size_t)(pcVar6 + (-sVar5 - (int)pcVar3)));

      uVar12 = *(uint8_t *)(unaff_ESI + 0xcb);

      uVar11 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130);

      acStack_800[(int)(pcVar6 + (-sVar5 - (int)pcVar3))] = '\0';

      FUN_00798720(param_3,acStack_800,0,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290),uVar11,uVar12);

      *param_4 = (int)(pcVar6 + (*param_4 - (int)pcVar3));

      return;

    }

    FUN_00798720(param_3,local_1000,*param_1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130),

                 CONCAT31((int3)((uint)iVar9 >> 8),*(uint8_t *)(unaff_ESI + 0xcb)));

    *param_4 = (int)(pcVar6 + (*param_4 - (int)pcVar3));

    return;

  }

  if ((DAT_00d17940 == (code *)0x0) || (cVar2 = (*DAT_00d17940)(param_2,local_1000), cVar2 == '\0'))

  {

    iVar9 = -(int)param_2;

    do {

      cVar2 = *param_2;

      param_2[(int)(local_1000 + iVar9)] = cVar2;

      param_2 = param_2 + 1;

    } while (cVar2 != '\0');

  }

  pcVar3 = local_1000;

  iVar9 = (int)(*(float *)(unaff_ESI + 0x2c4) - DAT_00aaa8dc);

  do {

    cVar2 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar2 != '\0');

  iVar4 = (int)pcVar3 - (int)(local_1000 + 1);

  iVar10 = *param_4;

  if (iVar4 + iVar10 < iVar9) {

    FUN_00798720(param_3,local_1000,*param_1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130),

                 CONCAT31((int3)((uint)iVar9 >> 8),*(uint8_t *)(unaff_ESI + 0xcb)));

    *param_4 = *param_4 + iVar4;

    return;

  }

  if (*(float *)(unaff_ESI + 0x2c4) <= (float)iVar10) {

    uVar12 = *(uint8_t *)(unaff_ESI + 0xcb);

    uVar11 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130);

    pcVar3 = local_1000;

  }

  else {

    _Count = iVar9 - iVar10;

    iVar7 = (int)(*(float *)(unaff_ESI + 0x2c4) - (float)iVar10);

    sVar5 = iVar4 - iVar7;

    iVar10 = 0xff;

    if (0 < (int)_Count) {

      strncpy(acStack_800,local_1000,_Count);

      uVar12 = *(uint8_t *)(unaff_ESI + 0xcb);

      uVar11 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130);

      uVar1 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290);

      acStack_800[_Count] = '\0';

      FUN_00798720(param_3,acStack_800,*param_1,uVar1,uVar11,uVar12);

    }

    for (iVar9 = iVar9 - *param_4; (iVar9 < iVar7 && (iVar9 < iVar4)); iVar9 = iVar9 + 1) {

      iVar10 = iVar10 + -0x2a;

      if (-1 < iVar9) {

        acStack_800[0] = local_1000[iVar9];

        iVar8 = (uint)*(byte *)((int)param_1 + 3) * iVar10;

        local_1010 = CONCAT13(((char)(iVar8 / 0xff) + (char)(iVar8 >> 0x1f)) -

                              (char)((longlong)iVar8 * 0x80808081 >> 0x3f),*(undefined3 *)param_1);

        acStack_800[1] = 0;

        FUN_00798720(param_3,acStack_800,local_1010,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290),

                     *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130),

                     CONCAT31((int3)((uint)iVar8 >> 8),*(uint8_t *)(unaff_ESI + 0xcb)));

      }

    }

    if ((int)sVar5 < 1) goto LAB_007b5318;

    strncpy(acStack_800,local_1000 + iVar7,sVar5);

    uVar12 = *(uint8_t *)(unaff_ESI + 0xcb);

    uVar11 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130);

    acStack_800[sVar5] = '\0';

    pcVar3 = acStack_800;

  }

  FUN_00798720(param_3,pcVar3,0,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290),uVar11,uVar12);

LAB_007b5318:

  *param_4 = *param_4 + iVar4;

  return;

}
