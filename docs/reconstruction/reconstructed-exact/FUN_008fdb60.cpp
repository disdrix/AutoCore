// =============================================================================
// FUN_008fdb60
// -----------------------------------------------------------------------------
// Stable ID: aa_008fdb60
// Address:   0x008fdb60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fdb60 @ 0x008fdb60
// Stable ID: aa_008fdb60
// Embedded strings (evidence for future rename):
//   - "CDlgBodyShop::UpdateCost() - Trying to apply trick from invalid group (%d)!"
//   - "Trick Change Fee: "
//   - "Trick Change Requires: "
//   - "%d %s"
//   - "Trim Change Fee: "
//   - "Painting Cost: "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~375 non-empty decompiler lines.
//  - Control keywords: if×49, goto×11, while×7, do×6, return×3, for×1.
//  - Notable callees: FUN_007a6de0×11, FUN_00977a30×5, CONCAT44×2, FUN_004022a0×2, CDlgBodyShop::UpdateCost, CONCAT12, CONCAT13, FUN_0040c700.
//  - Strings: "Trick Change Fee: "; "Trick Change Requires: "; "%d %s"; "Trim Change Fee: ".
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x008fdf95) */



void FUN_008fdb60(int param_1)



{

  byte bVar1;

  uint64_t uVar2;

  longlong lVar3;

  char cVar4;

  int *piVar5;

  int iVar6;

  byte *pbVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  uint32_t /* width from decompiler */ unaff_EBX;

  byte *pbVar10;

  int unaff_EDI;

  byte *pbVar11;

  bool bVar12;

  bool bVar13;

  char *pcVar14;

  uint32_t /* width from decompiler */ uVar15;

  char cStack_20e;

  uint32_t /* width from decompiler */ local_20c;

  uint32_t /* width from decompiler */ uStack_208;

  char local_204;

  char local_203;

  char local_202;

  char local_201;

  int local_200;

  longlong local_1fc;

  uint32_t /* width from decompiler */ local_1f4;

  longlong lStack_1f0;

  int iStack_1e8;

  longlong lStack_1e4;

  uint64_t uStack_1dc;

  int local_1d4;

  longlong lStack_1d0;

  int aiStack_1ac [36];

  char acStack_11c [272];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2c2f;

  local_c = ExceptionList;

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  local_1d4 = *(int *)(DAT_00d1b6d8 + 0x250);

  if (local_1d4 == 0) {

    return;

  }

  ExceptionList = &local_c;

  local_1f4 = FUN_007a69d0();

  local_204 = '\0';

  iVar9 = 0;

  piVar5 = (int *)(param_1 + 0x530);

  do {

    if (((piVar5[8] != 0) || (*piVar5 != -1)) && (piVar5[8] != *piVar5)) {

      if (iVar9 < 8) {

        local_204 = '\x01';

      }

      break;

    }

    iVar9 = iVar9 + 1;

    piVar5 = piVar5 + 1;

  } while (iVar9 < 8);

  local_201 = FUN_00502590(param_1 + 0x530,0);

  local_202 = *(int *)(param_1 + 0x52c) != *(int *)(param_1 + 0x528);

  iVar9 = *(int *)(param_1 + 0x7c8);

  uStack_208 = CONCAT13(1,(uint3)uStack_208);

  if (((iVar9 != -1) && (iVar6 = *(int *)(DAT_00d1b6d8 + 0x250), iVar9 != *(int *)(iVar6 + 0x1a8)))

     && ((*(int *)(param_1 + 0x7e0) == iVar9 &&

         ((*(int *)(param_1 + 0x7e0) != *(int *)(iVar6 + 0x1ac) && (*(int *)(iVar6 + 0x2b0) != 0))))

        )) {

    iVar9 = 0;

    local_200 = 0;

    FUN_0040db00();

    local_4 = 0;

    local_20c = (byte *)0x0;

    if (*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) + 0x50) == 0) {

LAB_008fdcfc:

      uStack_208 = uStack_208 & 0xffffff;

    }

    else {

      FUN_004294f0();

      iVar6 = FUN_004022a0(&local_200,&local_20c);

      while (iVar6 == 0) {

        if (((local_20c != (byte *)0x0) &&

            (*(short *)(*(int *)(*(int *)(local_20c + 0xa8) + 0x3c) + 0x3f4) == 8)) &&

           (*(int *)(local_20c + 200) == *(int *)(param_1 + 0x7c8))) {

          iVar9 = iVar9 + 1;

        }

        iVar6 = FUN_004022a0(&local_200,&local_20c);

      }

      FUN_0040c700();

      if (iVar9 < 2) goto LAB_008fdcfc;

    }

    local_4 = 0xffffffff;

    FUN_0040db30();

  }

  iVar9 = 0;

  local_200 = 0;

  if ((*(int *)(param_1 + 0x7c8) != -1) &&

     (*(int *)(param_1 + 0x7c8) != *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1a8))) {

    iVar9 = 1;

    local_200 = 1;

  }

  if ((*(int *)(param_1 + 0x7e0) != -1) &&

     (*(int *)(param_1 + 0x7e0) != *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1ac))) {

    iVar9 = iVar9 + 1;

    local_200 = iVar9;

  }

  local_203 = iVar9 != 0;

  uStack_208._0_3_ = (uint3)(ushort)uStack_208;

  bVar13 = true;

  if (*(int *)(param_1 + 0x740) == 0) {

LAB_008fde64:

    if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x250) == 0)) goto LAB_008fde97;

    local_1fc = FUN_004f58d0(param_1 + 0x530);

  }

  else {

    if (DAT_00d1b6d8 != 0) {

      if (*(int *)(DAT_00d1b6d8 + 0x250) != 0) {

        pbVar7 = (byte *)(**(code **)(**(int **)(param_1 + 0x740) + 0x1dc))();

        pbVar10 = (byte *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1b0);

        pbVar11 = pbVar7;

        do {

          bVar1 = *pbVar11;

          bVar12 = bVar1 < *pbVar10;

          if (bVar1 != *pbVar10) {

LAB_008fdde4:

            iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);

            goto LAB_008fdde9;

          }

          if (bVar1 == 0) break;

          bVar1 = pbVar11[1];

          bVar12 = bVar1 < pbVar10[1];

          if (bVar1 != pbVar10[1]) goto LAB_008fdde4;

          pbVar11 = pbVar11 + 2;

          pbVar10 = pbVar10 + 2;

        } while (bVar1 != 0);

        iVar9 = 0;

LAB_008fdde9:

        uStack_208._0_3_ = CONCAT12(iVar9 != 0,(ushort)uStack_208);

        local_20c = pbVar7;

        if (iVar9 != 0) {

          if (pbVar7 == (byte *)0x0) {

            bVar13 = false;

          }

          else {

            if (*pbVar7 != 0) {

              iVar9 = 0;

              do {

                iVar6 = isalnum((int)(char)*pbVar7);

                if ((((iVar6 == 0) && (*pbVar7 != 0x5f)) && (*pbVar7 != 0x20)) || (0x20 < iVar9)) {

                  bVar13 = false;

                  goto LAB_008fde64;

                }

                pbVar7 = pbVar7 + 1;

                iVar9 = iVar9 + 1;

              } while (*pbVar7 != 0);

            }

            bVar13 = true;

            if (DAT_00d1d8cc != 0) {

              cVar4 = FUN_0079d430(DAT_00d1d8cc,0);

              bVar13 = cVar4 == '\0';

            }

          }

        }

      }

      goto LAB_008fde64;

    }

LAB_008fde97:

    local_1fc = 0;

  }

  if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x250) == 0)) {

    lStack_1e4 = 0;

  }

  else {

    lStack_1e4 = FUN_004f5930(*(uint8_t *)(param_1 + 0x528));

  }

  if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x250) == 0)) {

    uStack_1dc = 0;

  }

  else {

    uStack_1dc = FUN_004f5970(*(uint32_t /* width from decompiler */ *)(param_1 + 0x7c8),*(uint32_t /* width from decompiler */ *)(param_1 + 0x7e0));

  }

  uVar15 = (uint32_t /* width from decompiler */)uStack_1dc;

  if (*(int *)(param_1 + 0x740) == 0) {

LAB_008fdf4b:

    lStack_1f0 = 0;

    uVar2 = uStack_1dc;

  }

  else {

    iVar9 = (**(code **)(**(int **)(param_1 + 0x740) + 0x1dc))();

    if (((iVar9 == 0) || (DAT_00d1b6d8 == 0)) || (*(int *)(DAT_00d1b6d8 + 0x250) == 0))

    goto LAB_008fdf4b;

    lStack_1f0 = FUN_004f59c0(iVar9);

    uVar2 = uStack_1dc;

  }

  uStack_1dc._4_4_ = (uint32_t /* width from decompiler */)((ulonglong)uVar2 >> 0x20);

  lVar3 = lStack_1f0 + CONCAT44(uStack_1dc._4_4_,uVar15) + lStack_1e4 + local_1fc;

  if (((local_201 == '\0') || (uStack_208._3_1_ == '\0')) ||

     ((CONCAT44((*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)),

                *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728)) < lVar3 ||

      (!bVar13)))) {

    bVar12 = false;

  }

  else {

    bVar12 = true;

  }

  uStack_1dc = uVar2;

  lStack_1d0 = lVar3;

  if (*(int *)(param_1 + 0x734) != 0) {

    if (bVar12) {

      if (((local_204 != '\0') || (local_202 != '\0')) ||

         ((local_203 != '\0' || (uStack_208._2_1_ != '\0')))) {

        uVar15 = 1;

        goto LAB_008fdfff;

      }

      (**(code **)(**(int **)(param_1 + 0x734) + 0xd4))(0);

    }

    else {

      uVar15 = 0;

LAB_008fdfff:

      (**(code **)(**(int **)(param_1 + 0x734) + 0xd4))(uVar15);

    }

    (**(code **)(**(int **)(param_1 + 0x734) + 0x34c))();

  }

  if (bVar12) {

    local_20c = (byte *)0xffffffff;

  }

  else {

    local_20c = (byte *)0xffff0000;

  }

  iStack_1e8 = (int)local_20c;

  if (*(int *)(param_1 + 0x71c) == 0) goto LAB_008fe43d;

  (**(code **)(**(int **)(param_1 + 0x71c) + 0x268))();

  (**(code **)(**(int **)(param_1 + 0x71c) + 0x15c))(1,&iStack_1e8);

  if ((char)local_20c != '\0') {

    piVar5 = aiStack_1ac + 2;

    for (iVar9 = 0x24; iVar9 != 0; iVar9 = iVar9 + -1) {

      *piVar5 = 0;

      piVar5 = piVar5 + 1;

    }

    piVar5 = (int *)(param_1 + 0x530);

    iVar9 = 8;

    do {

      iVar6 = *piVar5;

      if ((-1 < iVar6) && (piVar5[8] != iVar6)) {

        iVar6 = FUN_004f5880(iVar6);

        if (iVar6 != 0) {

          if (*(byte *)(iVar6 + 9) < 0x24) {

            aiStack_1ac[*(byte *)(iVar6 + 9) + 2] = aiStack_1ac[*(byte *)(iVar6 + 9) + 2] + 1;

          }

          else {

            FUN_007a4480(0,

                         "CDlgBodyShop::UpdateCost() - Trying to apply trick from invalid group (%d)!"

                         ,*(byte *)(iVar6 + 9));

          }

        }

      }

      piVar5 = piVar5 + 1;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

    iVar6 = 0;

    iVar9 = 0;

    do {

      if (0 < aiStack_1ac[iVar9 + 2]) {

        iVar6 = iVar6 + 1;

      }

      iVar9 = iVar9 + 1;

    } while (iVar9 < 0x24);

    if (iVar6 < 1) {

      iVar9 = **(int **)(param_1 + 0x71c);

      uVar15 = FUN_007a6de0("Trick Change Fee: ",0xffffffff);

      (**(code **)(iVar9 + 0x250))(uVar15);

      iVar9 = (int)local_20c;

LAB_008fe24f:

      FUN_00977a30(DAT_00d1ad30,iVar9,uStack_208);

    }

    else {

      iVar9 = **(int **)(param_1 + 0x71c);

      uVar15 = (uint32_t /* width from decompiler */)lStack_1f0;

      uVar8 = FUN_007a6de0("Trick Change Requires: ",0xffffffff);

      (**(code **)(iVar9 + 0x22c))(uVar8,uVar15);

      iVar6 = 0;

      do {

        iVar9 = *(int *)((int)aiStack_1ac + iVar6);

        if (0 < iVar9) {

          uVar15 = FUN_007a6de0(*(uint32_t /* width from decompiler */ *)((int)&PTR_s_Pipes_00af9180 + iVar6),0xffffffff);

          sprintf(acStack_11c,"%d %s",iVar9,uVar15);

          (**(code **)(**(int **)(param_1 + 0x71c) + 0x250))(acStack_11c);

          if (unaff_EDI < 1) {

            (**(code **)(**(int **)(param_1 + 0x71c) + 0x250))(&DAT_00a2a000);

          }

          else {

            (**(code **)(**(int **)(param_1 + 0x71c) + 0x250))(&DAT_00a34230);

          }

        }

        iVar9 = (int)local_20c;

        iVar6 = iVar6 + 4;

      } while (iVar6 < 0x90);

      if (local_20c != (byte *)0x0 || uStack_208 != 0) {

        iVar6 = **(int **)(param_1 + 0x71c);

        uVar15 = FUN_007a6de0(&DAT_00a34228,0xffffffff);

        (**(code **)(iVar6 + 0x250))(uVar15);

        goto LAB_008fe24f;

      }

    }

    (**(code **)(**(int **)(param_1 + 0x71c) + 0x250))(&DAT_00a15104);

  }

  if (local_20c._2_1_ != '\0') {

    iVar9 = **(int **)(param_1 + 0x71c);

    uVar15 = FUN_007a6de0("Trim Change Fee: ",0xffffffff);

    (**(code **)(iVar9 + 0x250))(uVar15);

    FUN_00977a30(DAT_00d1ad30,lStack_1f0);

    (**(code **)(**(int **)(param_1 + 0x71c) + 0x250))(&DAT_00a15104);

  }

  if (local_20c._1_1_ != '\0') {

    if (bVar13) {

      iVar9 = **(int **)(param_1 + 0x71c);

      uVar15 = FUN_007a6de0("Painting Cost: ",0xffffffff);

      (**(code **)(iVar9 + 0x250))(uVar15);

      if (local_20c == (byte *)0x1) {

        iVar9 = **(int **)(param_1 + 0x71c);

        pcVar14 = "1 Paint Can and ";

LAB_008fe336:

        uVar15 = FUN_007a6de0(pcVar14,0xffffffff);

        (**(code **)(iVar9 + 0x250))(uVar15);

      }

      else if (local_20c == (byte *)0x2) {

        iVar9 = **(int **)(param_1 + 0x71c);

        pcVar14 = "2 Paint Cans and ";

        goto LAB_008fe336;

      }

      FUN_00977a30(DAT_00d1ad30,iStack_1e8,(uint32_t /* width from decompiler */)lStack_1e4);

      (**(code **)(**(int **)(param_1 + 0x71c) + 0x250))(&DAT_00a15104);

    }

    else {

      iVar9 = **(int **)(param_1 + 0x71c);

      uVar15 = FUN_007a6de0("Need More Paint Cans!\n",0xffffffff);

      (**(code **)(iVar9 + 0x250))(uVar15);

    }

  }

  if (cStack_20e != '\0') {

    if ((char)((uint)unaff_EBX >> 0x18) == '\0') {

      iVar9 = **(int **)(param_1 + 0x71c);

      uVar15 = FUN_007a6de0("Invalid Vehicle Name!\n",0xffffffff);

      (**(code **)(iVar9 + 0x250))(uVar15);

    }

    else {

      iVar9 = **(int **)(param_1 + 0x71c);

      uVar15 = FUN_007a6de0("Name Change Fee: ",0xffffffff);

      (**(code **)(iVar9 + 0x250))(uVar15);

      FUN_00977a30(DAT_00d1ad30,local_1fc);

      (**(code **)(**(int **)(param_1 + 0x71c) + 0x250))(&DAT_00a15104);

    }

  }

  (**(code **)(**(int **)(param_1 + 0x71c) + 0x34c))();

  lVar3 = lStack_1d0;

LAB_008fe43d:

  if (*(int *)(param_1 + 0x720) != 0) {

    (**(code **)(**(int **)(param_1 + 0x720) + 0x1d8))(0,1,1);

    (**(code **)(**(int **)(param_1 + 0x720) + 0x15c))(1,&local_1f4);

    iVar9 = **(int **)(param_1 + 0x720);

    uVar15 = FUN_007a6de0("Total Cost: ",0xffffffff);

    (**(code **)(iVar9 + 0x250))(uVar15);

    FUN_00977a30(DAT_00d1ad30,lVar3);

    (**(code **)(**(int **)(param_1 + 0x720) + 0x34c))();

  }

  ExceptionList = local_c;

  return;

}
