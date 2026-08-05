// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGClient_007ffef0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ffef0
// Callee of Named_CalleeOf_Named_VOGClient
// Address:   0x007ffef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGClient: callee helper. Evidence string: "Dodges". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Dodges"
//   - "Misses"
//   - "Resists An Attack"
//   - "Attack"
//   - "Resists"
//   - "Deflects An Attack"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~479 non-empty decompiler lines.
//  - Control keywords: if×55, return×11, goto×9, for×8, do×8, while×8, switch×1.
//  - Notable callees: FUN_007a6de0×40, sprintf×16, FUN_0040aff0×4, FUN_005749d0×4, Object_ResolveFromTFID×4, TFID_EqualsObjectId×2, TFID_NotEquals×2, FUN_007a69d0.
//  - Strings: "Dodges"; "%s %s!"; "Misses"; "%s %s %s!".
//  - Return sites: 11.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGClient
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_VOGClient_007ffef0(int param_1,TFID_16 *param_2)



{

  bool bVar1;

  bool bVar2;

  bool bVar3;

  byte bVar4;

  char cVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  void *pvVar9;

  TFID_16 *pTVar10;

  int *piVar11;

  int iVar12;

  uint32_t /* width from decompiler */ uVar13;

  char *pcVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint32_t /* width from decompiler */ uVar16;

  uint uVar17;

  char *pcVar18;

  char *pcVar19;

  uint32_t /* width from decompiler */ *puVar20;

  char *pcVar21;

  bool bVar22;

  uint8_t *puVar23;

  undefined *puVar24;

  char local_140 [2];

  uint32_t /* width from decompiler */ local_13e [12];

  char local_10c [2];

  uint32_t /* width from decompiler */ local_10a [12];

  uint8_t auStack_d8 [15];

  char cStack_c9;

  char local_c8 [2];

  uint32_t /* width from decompiler */ local_c6 [49];

  

  if (*(int **)(param_1 + 0xf40) == (int *)0x0) {

    return;

  }

  if (**(int **)(param_1 + 0xf40) == 0) {

    return;

  }

  if (DAT_00d1b644 == 0) {

    return;

  }

  if (param_2 == (TFID_16 *)0x0) {

    return;

  }

  iVar6 = TFID_EqualsObjectId(param_2 + 1,param_2);

  if (((((char)iVar6 != '\0') && (DAT_00d1b6d8 != 0)) &&

      (iVar6 = TFID_EqualsObjectId((void *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0x164 +

                                           DAT_00d1b6d8),param_2), (char)iVar6 != '\0')) &&

     (param_2[2].bPad1 != 0)) {

    return;

  }

  FUN_007a69d0();

  local_c8[0] = '\0';

  local_c8[1] = '\0';

  puVar20 = local_c6;

  for (iVar6 = 0x31; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar20 = 0;

    puVar20 = puVar20 + 1;

  }

  *(uint16_t *)puVar20 = 0;

  local_140[0] = '\0';

  local_140[1] = '\0';

  puVar20 = local_13e;

  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar20 = 0;

    puVar20 = puVar20 + 1;

  }

  local_10c[0] = '\0';

  local_10c[1] = '\0';

  puVar20 = local_10a;

  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar20 = 0;

    puVar20 = puVar20 + 1;

  }

  piVar7 = Object_ResolveFromTFID(param_2 + 1);

  piVar8 = Object_ResolveFromTFID(param_2);

  bVar1 = false;

  if ((piVar7 != (int *)0x0) &&

     (iVar6 = (**(code **)(*piVar7 + 0x210))(0), *(int *)(param_1 + 0xe98) == iVar6)) {

    bVar1 = true;

  }

  bVar2 = false;

  if ((piVar8 != (int *)0x0) &&

     (iVar6 = (**(code **)(*piVar8 + 0x210))(0), *(int *)(param_1 + 0xe98) == iVar6)) {

    bVar2 = true;

  }

  bVar3 = false;

  if (((piVar8 == (int *)0x0) || (iVar6 = (**(code **)(*piVar8 + 0x1d8))(), iVar6 == 0)) ||

     (*(int *)(param_1 + 0xe98) == 0)) {

LAB_0080015a:

    if (((piVar7 != (int *)0x0) && (iVar6 = (**(code **)(*piVar7 + 0x1d8))(), iVar6 != 0)) &&

       (*(int *)(param_1 + 0xe98) != 0)) {

      puVar24 = &DAT_00a1e850;

      puVar23 = auStack_d8;

      (**(code **)(*piVar7 + 0x1d8))(puVar23);

      pvVar9 = (void *)FUN_0040aff0(puVar23);

      iVar6 = TFID_NotEquals(pvVar9,puVar24);

      if ((char)iVar6 != '\0') {

        puVar23 = auStack_d8;

        (**(code **)(*piVar7 + 0x1d8))(puVar23);

        pTVar10 = (TFID_16 *)FUN_0040aff0(puVar23);

        piVar11 = Object_ResolveFromTFID(pTVar10);

        if ((piVar11 != (int *)0x0) && (iVar6 = (**(code **)(*piVar11 + 0x210))(0), iVar6 != 0)) {

          iVar6 = *(int *)(param_1 + 0xe98);

          iVar12 = (**(code **)(*piVar11 + 0x210))(0);

          if (iVar12 == iVar6) {

            bVar4 = (byte)(DAT_00af921c >> 2);

LAB_00800262:

            bVar22 = (~bVar4 & 1) == 0;

            goto LAB_00800266;

          }

          if (*(int *)(iVar6 + 0xcb0) != 0) {

            uVar13 = (**(code **)(*piVar11 + 0x210))(0);

            cVar5 = FUN_005749d0(uVar13);

            if (cVar5 != '\0') {

              bVar4 = (byte)(DAT_00af921c >> 3);

              goto LAB_00800262;

            }

          }

        }

      }

    }

  }

  else {

    puVar24 = &DAT_00a1e850;

    puVar23 = auStack_d8;

    (**(code **)(*piVar8 + 0x1d8))(puVar23);

    pvVar9 = (void *)FUN_0040aff0(puVar23);

    iVar6 = TFID_NotEquals(pvVar9,puVar24);

    if ((char)iVar6 == '\0') goto LAB_0080015a;

    puVar23 = auStack_d8;

    (**(code **)(*piVar8 + 0x1d8))(puVar23);

    pTVar10 = (TFID_16 *)FUN_0040aff0(puVar23);

    piVar11 = Object_ResolveFromTFID(pTVar10);

    if ((piVar11 == (int *)0x0) || (iVar6 = (**(code **)(*piVar11 + 0x210))(0), iVar6 == 0))

    goto LAB_0080026d;

    iVar6 = *(int *)(param_1 + 0xe98);

    iVar12 = (**(code **)(*piVar11 + 0x210))(0);

    if (iVar12 != iVar6) {

      if (*(int *)(iVar6 + 0xcb0) != 0) {

        uVar13 = (**(code **)(*piVar11 + 0x210))(0);

        cVar5 = FUN_005749d0(uVar13);

        if (cVar5 != '\0') {

          bVar22 = (~(byte)(DAT_00af921c >> 1) & 1) == 0;

          goto LAB_00800266;

        }

      }

      goto LAB_0080026d;

    }

    bVar22 = (~(byte)DAT_00af921c & 1) == 0;

LAB_00800266:

    if (bVar22) {

      bVar3 = true;

    }

  }

LAB_0080026d:

  if (((!bVar1) && (!bVar2)) && (!bVar3)) {

    if (*(int *)(param_1 + 0xe98) == 0) {

      return;

    }

    if (*(int *)(*(int *)(param_1 + 0xe98) + 0xcb0) == 0) {

      return;

    }

    if (piVar7 != (int *)0x0) {

      uVar13 = (**(code **)(*piVar7 + 0x210))(0);

      cVar5 = FUN_005749d0(uVar13);

      if (cVar5 != '\0') goto LAB_008002fc;

    }

    if (piVar8 == (int *)0x0) {

      return;

    }

    uVar13 = (**(code **)(*piVar8 + 0x210))(0);

    cVar5 = FUN_005749d0(uVar13);

    if (cVar5 == '\0') {

      return;

    }

  }

LAB_008002fc:

  if (piVar7 != (int *)0x0) {

    uVar13 = 0;

    iVar6 = (**(code **)(*piVar7 + 0x210))(0);

    if (iVar6 == 0) {

      iVar6 = (**(code **)(*piVar7 + 0x214))();

      if ((iVar6 == 0) || (iVar6 = (**(code **)(*piVar7 + 0x214))(), *(int *)(iVar6 + 0x250) == 0))

      {

        iVar6 = (**(code **)(*piVar7 + 0x214))();

        if (iVar6 != 0) {

          iVar6 = (**(code **)(*piVar7 + 0x214))();

          uVar15 = 0xffffffff;

          uVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x15c))

                             (0xffffffff);

          pcVar14 = (char *)FUN_007a6de0(uVar13,uVar15);

          pcVar18 = local_140;

          do {

            cVar5 = *pcVar14;

            *pcVar18 = cVar5;

            pcVar14 = pcVar14 + 1;

            pcVar18 = pcVar18 + 1;

          } while (cVar5 != '\0');

        }

      }

      else {

        iVar6 = (**(code **)(*piVar7 + 0x214))();

        uVar15 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x250) + 4) + 4) + 4 +

                                      *(int *)(iVar6 + 0x250)) + 0x15c))(0xffffffff);

        pcVar14 = (char *)FUN_007a6de0(uVar15,uVar13);

        pcVar18 = local_140;

        do {

          cVar5 = *pcVar14;

          *pcVar18 = cVar5;

          pcVar14 = pcVar14 + 1;

          pcVar18 = pcVar18 + 1;

        } while (cVar5 != '\0');

      }

    }

    else {

      iVar6 = (**(code **)(*piVar7 + 0x210))(0);

      pcVar14 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x160

                                    ))();

      pcVar18 = local_140;

      do {

        cVar5 = *pcVar14;

        *pcVar18 = cVar5;

        pcVar14 = pcVar14 + 1;

        pcVar18 = pcVar18 + 1;

      } while (cVar5 != '\0');

    }

  }

  if (piVar8 != (int *)0x0) {

    uVar13 = 0;

    iVar6 = (**(code **)(*piVar8 + 0x210))(0);

    if (iVar6 == 0) {

      iVar6 = (**(code **)(*piVar8 + 0x214))();

      if ((iVar6 == 0) || (iVar6 = (**(code **)(*piVar8 + 0x214))(), *(int *)(iVar6 + 0x250) == 0))

      {

        iVar6 = (**(code **)(*piVar8 + 0x214))();

        if (iVar6 != 0) {

          iVar6 = (**(code **)(*piVar8 + 0x214))();

          uVar15 = 0xffffffff;

          uVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x15c))

                             (0xffffffff);

          pcVar14 = (char *)FUN_007a6de0(uVar13,uVar15);

          pcVar18 = local_10c;

          do {

            cVar5 = *pcVar14;

            *pcVar18 = cVar5;

            pcVar14 = pcVar14 + 1;

            pcVar18 = pcVar18 + 1;

          } while (cVar5 != '\0');

        }

      }

      else {

        iVar6 = (**(code **)(*piVar8 + 0x214))();

        uVar15 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x250) + 4) + 4) + 4 +

                                      *(int *)(iVar6 + 0x250)) + 0x15c))(0xffffffff);

        pcVar14 = (char *)FUN_007a6de0(uVar15,uVar13);

        pcVar18 = local_10c;

        do {

          cVar5 = *pcVar14;

          *pcVar18 = cVar5;

          pcVar14 = pcVar14 + 1;

          pcVar18 = pcVar18 + 1;

        } while (cVar5 != '\0');

      }

    }

    else {

      iVar6 = (**(code **)(*piVar8 + 0x210))(0);

      pcVar14 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x160

                                    ))();

      pcVar18 = local_10c;

      do {

        cVar5 = *pcVar14;

        *pcVar18 = cVar5;

        pcVar14 = pcVar14 + 1;

        pcVar18 = pcVar18 + 1;

      } while (cVar5 != '\0');

    }

  }

  if (local_140[0] == '\0') {

    return;

  }

  switch(param_2[3].dwCoidLo) {

  case 0:

    if (param_2[2].bPad1 != 0) {

      if (local_10c[0] == '\0') {

        uVar13 = FUN_007a6de0("Dodges",0xffffffff);

        sprintf(local_c8,"%s %s!",local_140,uVar13);

        uVar13 = 0x12;

      }

      else {

        pcVar18 = local_140;

        uVar13 = FUN_007a6de0("Misses",0xffffffff);

        sprintf(local_c8,"%s %s %s!",local_10c,uVar13,pcVar18);

        uVar13 = 0x12;

      }

      break;

    }

    if (param_2[2].bPad2 != 0) {

      if (local_10c[0] == '\0') {

        uVar13 = FUN_007a6de0("Resists An Attack",0xffffffff);

        sprintf(local_c8,"%s %s!",local_140,uVar13);

        uVar13 = 0x12;

      }

      else {

        uVar13 = FUN_007a6de0("Attack",0xffffffff);

        pcVar18 = local_10c;

        uVar15 = FUN_007a6de0("Resists",0xffffffff);

        sprintf(local_c8,"%s %s %s\'s %s!",local_140,uVar15,pcVar18,uVar13);

        uVar13 = 0x12;

      }

      break;

    }

    if (param_2[2].bPad3 != 0) {

      if (local_10c[0] == '\0') {

        uVar13 = FUN_007a6de0("Deflects An Attack",0xffffffff);

        sprintf(local_c8,"%s %s!",local_140,uVar13);

        uVar13 = 0x12;

      }

      else {

        uVar13 = FUN_007a6de0("Attack",0xffffffff);

        pcVar18 = local_10c;

        uVar15 = FUN_007a6de0("Deflects",0xffffffff);

        sprintf(local_c8,"%s %s %s\'s %s!",local_140,uVar15,pcVar18,uVar13);

        uVar13 = 0x12;

      }

      break;

    }

    if (param_2[2].bPad0 == 0) {

LAB_0080073d:

      if (local_10c[0] == '\0') {

        uVar13 = FUN_007a6de0("Damage",0xffffffff);

        uVar17 = param_2[2].dwCoidLo;

        uVar15 = FUN_007a6de0("is Hit for",0xffffffff);

        pcVar18 = "%s %s %d %s.";

LAB_008007bf:

        sprintf(local_c8,pcVar18,local_140,uVar15,uVar17,uVar13);

      }

      else {

        uVar13 = FUN_007a6de0("Damage",0xffffffff);

        uVar17 = param_2[2].dwCoidLo;

        uVar15 = FUN_007a6de0(&DAT_00a84270,0xffffffff);

        pcVar18 = local_140;

        uVar16 = FUN_007a6de0(&DAT_00a84224,0xffffffff);

        sprintf(local_c8,"%s %s %s %s %d %s.",local_10c,uVar16,pcVar18,uVar15,uVar17,uVar13);

      }

    }

    else {

      if (local_10c[0] == '\0') {

        if (param_2[2].bPad0 == 0) goto LAB_0080073d;

        uVar13 = FUN_007a6de0("Damage",0xffffffff);

        uVar17 = param_2[2].dwCoidLo;

        uVar15 = FUN_007a6de0("is Criticaled for",0xffffffff);

        pcVar18 = "%s %s %d %s!";

        goto LAB_008007bf;

      }

      uVar13 = FUN_007a6de0("Damage",0xffffffff);

      uVar17 = param_2[2].dwCoidLo;

      uVar15 = FUN_007a6de0(&DAT_00a84270,0xffffffff);

      pcVar18 = local_140;

      uVar16 = FUN_007a6de0("Criticals ",0xffffffff);

      sprintf(local_c8,"%s %s %s %s %d %s!",local_10c,uVar16,pcVar18,uVar15,uVar17,uVar13);

    }

    if (param_2[2].bPad0 == 0) {

      if (param_2[2].dwCoidHi == param_2[2].dwCoidLo) {

        pcVar14 = (char *)FUN_007a6de0("(Shielded)",0xffffffff);

        pcVar18 = pcVar14;

        do {

          cVar5 = *pcVar18;

          pcVar18 = pcVar18 + 1;

        } while (cVar5 != '\0');

        pcVar21 = &cStack_c9;

        do {

          pcVar19 = pcVar21 + 1;

          pcVar21 = pcVar21 + 1;

        } while (*pcVar19 != '\0');

        pcVar19 = pcVar14;

        for (uVar17 = (uint)((int)pcVar18 - (int)pcVar14) >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar21 = *(uint32_t /* width from decompiler */ *)pcVar19;

          pcVar19 = pcVar19 + 4;

          pcVar21 = pcVar21 + 4;

        }

        for (uVar17 = (int)pcVar18 - (int)pcVar14 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {

          *pcVar21 = *pcVar19;

          pcVar19 = pcVar19 + 1;

          pcVar21 = pcVar21 + 1;

        }

        uVar13 = 0x16;

      }

      else {

        uVar13 = 0x11;

      }

    }

    else {

      uVar13 = 0x10;

    }

    break;

  case 1:

    if (bVar1) {

      if ((local_10c[0] == '\0') || (bVar2)) {

        uVar13 = FUN_007a6de0("Hit Points",0xffffffff);

        iVar6 = -param_2[2].dwCoidLo;

        uVar15 = FUN_007a6de0("You Repair",0xffffffff);

        sprintf(local_c8,"%s %d %s.",uVar15,iVar6,uVar13);

        uVar13 = 0x13;

        break;

      }

      uVar13 = FUN_007a6de0("Hit Points",0xffffffff);

      iVar6 = -param_2[2].dwCoidLo;

      uVar15 = FUN_007a6de0("Repairs You for",0xffffffff);

      pcVar18 = local_10c;

    }

    else {

      if (local_10c[0] != '\0') {

        uVar13 = FUN_007a6de0("Hit Points",0xffffffff);

        iVar6 = -param_2[2].dwCoidLo;

        uVar15 = FUN_007a6de0(&DAT_00a84270,0xffffffff);

        pcVar18 = local_140;

        uVar16 = FUN_007a6de0("Repairs",0xffffffff);

        sprintf(local_c8,"%s %s %s %s %d %s.",local_10c,uVar16,pcVar18,uVar15,iVar6,uVar13);

        uVar13 = 0x13;

        break;

      }

      uVar13 = FUN_007a6de0("Hit Points",0xffffffff);

      iVar6 = -param_2[2].dwCoidLo;

      uVar15 = FUN_007a6de0("Repairs",0xffffffff);

      pcVar18 = local_140;

    }

    sprintf(local_c8,"%s %s %d %s.",pcVar18,uVar15,iVar6,uVar13);

    uVar13 = 0x13;

    break;

  case 2:

    if ((int)param_2[2].dwCoidLo < 0) {

      if (local_10c[0] != '\0') {

        pcVar18 = local_140;

        uVar13 = FUN_007a6de0("Power from",0xffffffff);

        iVar6 = -param_2[2].dwCoidLo;

        uVar15 = FUN_007a6de0(&DAT_00a84184,0xffffffff);

        sprintf(local_c8,"%s %s %d %s %s",local_10c,uVar15,iVar6,uVar13,pcVar18);

        uVar13 = 0x15;

        break;

      }

      uVar13 = FUN_007a6de0("Power",0xffffffff);

      uVar17 = -param_2[2].dwCoidLo;

      pcVar18 = "Loses";

    }

    else {

      uVar13 = FUN_007a6de0("Power",0xffffffff);

      uVar17 = param_2[2].dwCoidLo;

      pcVar18 = "Gains";

    }

    uVar15 = FUN_007a6de0(pcVar18,0xffffffff);

    sprintf(local_c8,"%s %s %d %s",local_140,uVar15,uVar17,uVar13);

    uVar13 = 0x15;

    break;

  case 3:

    uVar13 = FUN_007a6de0(&DAT_00a43258,0xffffffff);

    if (bVar1) {

      uVar17 = param_2[2].dwCoidLo;

      uVar15 = FUN_007a6de0("You Gain",0xffffffff);

      sprintf(local_c8,"%s %d %s",uVar15,uVar17,uVar13);

      uVar13 = 0x14;

    }

    else {

      uVar17 = param_2[2].dwCoidLo;

      uVar13 = FUN_007a6de0("Gains",0xffffffff);

      sprintf(local_c8,"%s %s %d %s",local_140,uVar13,uVar17);

      uVar13 = 0x14;

    }

    break;

  default:

    uVar13 = 0x11;

  }

  if ((local_c8[0] != '\0') && (DAT_00d1b8dc != 0)) {

    FUN_008f8200(DAT_00d1b8dc,uVar13,&DAT_00a1419b,local_c8,0);

  }

  return;

}
