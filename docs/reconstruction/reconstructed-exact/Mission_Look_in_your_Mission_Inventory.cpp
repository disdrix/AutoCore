// READABILITY (auto CF):
//  - Body size: ~463 non-empty decompiler lines.
//  - Control keywords: if×57, return×13, goto×10, for×5, do×4, while×4.
//  - Notable callees: CNDHash_LookupByKey×10, sprintf×7, FUN_007a6de0×6, FUN_00541a80×3, FUN_009700f0×3, FUN_004024b0×2, FUN_00404c00×2, FUN_008a8040×2.
//  - Strings: "No Objective"; "Next mission"; "Look in your Mission Inventory"; "Read mission journal for details".
//  - Return sites: 13.

// =============================================================================
// Mission_Look_in_your_Mission_Inventory
// -----------------------------------------------------------------------------
// Stable ID: aa_008a8770
// Address:   0x008a8770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Look in your Mission Inventory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Mission_Look_in_your_Mission_Inventory(int *param_1)



{

  float fVar1;

  int *piVar2;

  float fVar3;

  bool bVar4;

  char cVar5;

  char cVar6;

  void *pvVar7;

  void *pvVar8;

  int iVar9;

  uint8_t *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  char *pcVar12;

  int *piVar13;

  uint uVar14;

  char *pcVar15;

  uint32_t /* width from decompiler */ uVar16;

  uint32_t /* width from decompiler */ unaff_EBX;

  float10 fVar17;

  int *piStack_2a4;

  int local_2a0;

  uint local_29c;

  void *local_298;

  float fStack_294;

  float fStack_290;

  float fStack_28c;

  float fStack_288;

  uint32_t /* width from decompiler */ uStack_284;

  int *piStack_280;

  int *piStack_27c;

  uint32_t /* width from decompiler */ uStack_278;

  float fStack_270;

  float fStack_26c;

  float fStack_268;

  float fStack_264;

  float fStack_260;

  float fStack_25c;

  float fStack_258;

  float fStack_254;

  float fStack_250;

  float fStack_24c;

  uint uStack_248;

  uint8_t auStack_244 [20];

  uint8_t auStack_230 [4];

  uint8_t auStack_22c [4];

  uint8_t auStack_228 [4];

  uint8_t auStack_224 [2];

  uint8_t auStack_222 [2];

  uint uStack_220;

  uint8_t uStack_21c;

  uint8_t uStack_1a1;

  char cStack_124;

  uint32_t /* width from decompiler */ uStack_123;

  void *pvStack_3c;

  void *pvStack_38;

  void *pvStack_30;

  void *pvStack_20;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  cVar5 = (char)((uint)unaff_EBX >> 0x10);

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b03d9;

  local_1c = ExceptionList;

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (*(char *)(DAT_00d1b6d8 + 0x4f1) != '\0') {

    return;

  }

  if (param_1[0x1a2] == 0) {

    return;

  }

  if (param_1[0x1a5] == 0) {

    return;

  }

  if (param_1[0x1a4] == 0) {

    return;

  }

  ExceptionList = &local_1c;

  local_298 = (void *)FUN_007a69d0();

  iVar9 = DAT_00d1b6d8;

  if (*(char *)((int)DAT_00d1ad10 + 9) == '\0') {

    local_29c = *(uint *)((int)DAT_00d1ad10 + 0x10);

    if (local_29c == 0) {

      cVar5 = FUN_008a8660();

      if (cVar5 != '\0') {

        ExceptionList = local_1c;

        return;

      }

      (**(code **)(*(int *)param_1[0x1a2] + 0x1d8))("No Objective",1,1);

      (**(code **)(*(int *)param_1[0x1a2] + 0x34c))();

      (**(code **)(*(int *)param_1[0x1a5] + 0x1d8))(0,1,1);

      (**(code **)(*(int *)param_1[0x1a5] + 0x34c))();

      (**(code **)(*(int *)param_1[0x1a4] + 4))(0);

      *(uint8_t *)((int)DAT_00d1ad10 + 4) = 1;

      ExceptionList = pvStack_38;

      return;

    }

    if (*(void **)(DAT_00d1b6d8 + 0x548) == (void *)0x0) {

      ExceptionList = local_1c;

      return;

    }

    pvVar7 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x548),local_29c);

    if (pvVar7 == (void *)0x0) {

      FUN_008a8660();

      ExceptionList = local_1c;

      return;

    }

    if ((((*(int *)((int)pvVar7 + 0x138) != 0) && (*(char *)((int)DAT_00d1ad10 + 7) == '\0')) &&

        (pvVar8 = CNDHash_LookupByKey(*(void **)(iVar9 + 0x55c),*(uint *)((int)pvVar7 + 0x10)),

        pvVar8 == (void *)0x0)) ||

       ((pvVar8 = CNDHash_LookupByKey(*(void **)(iVar9 + 0x55c),local_29c), pvVar8 == (void *)0x0 &&

        (iVar9 = FUN_004024b0(), iVar9 != 0)))) {

      (**(code **)(*(int *)param_1[0x1a2] + 0x1d8))("No Objective",1,1);

      (**(code **)(*(int *)param_1[0x1a2] + 0x34c))();

      (**(code **)(*(int *)param_1[0x1a5] + 0x1d8))(0,1,1);

      (**(code **)(*(int *)param_1[0x1a5] + 0x34c))();

      (**(code **)(*(int *)param_1[0x1a4] + 4))(0);

      (**(code **)(*param_1 + 0x450))(0);

      *(uint8_t *)((int)DAT_00d1ad10 + 4) = 1;

      ExceptionList = pvStack_3c;

      return;

    }

    if ((*(int *)((int)pvVar7 + 0x14c) != 0) &&

       (*(char *)(*(int *)((int)pvVar7 + 0x14c) + 0x168) == '\0')) {

      FUN_00547920(0);

    }

    if (*(char *)((int)DAT_00d1ad10 + 7) == '\0') {

      (**(code **)(*(int *)param_1[0x1a2] + 0x1d8))(*(uint32_t /* width from decompiler */ *)((int)pvVar7 + 4),1,1);

    }

    else {

      local_29c = *(uint *)(*(int *)((int)pvVar7 + 0x14c) + 0x88);

      bVar4 = false;

      local_2a0 = FUN_004024b0();

      local_2a0 = local_2a0 + -1;

      if (-1 < local_2a0) {

        do {

          if (bVar4) goto LAB_008a8b33;

          piVar13 = *(int **)(*(int *)((int)pvVar7 + 0x158) + local_2a0 * 4);

          if (piVar13 != (int *)0x0) {

            iVar9 = (**(code **)(*piVar13 + 0x50))();

            if (iVar9 == 3) {

              (**(code **)(*piVar13 + 0x14))();

              puVar10 = *(uint8_t **)((int)pvVar7 + 4);

LAB_008a8a82:

              (**(code **)(*(int *)param_1[0x1a2] + 0x1d8))(puVar10,1,1);

              bVar4 = true;

            }

            else if (iVar9 == 6) {

              pvVar8 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x55c),

                                           *(uint *)((int)pvVar7 + 0x10));

              uStack_220 = uStack_220 & 0xffffff00;

              uStack_1a1 = 0;

              if (pvVar8 != (void *)0x0) {

                (**(code **)(*piVar13 + 0x1c))(DAT_00d1b6d8,pvVar8,&uStack_220,0x80);

                puVar10 = auStack_230;

                goto LAB_008a8a82;

              }

            }

          }

          local_2a0 = local_2a0 + -1;

        } while (-1 < local_2a0);

        if (bVar4) goto LAB_008a8b33;

      }

      pvVar7 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),local_29c);

      if (pvVar7 != (void *)0x0) {

        if (*(int *)((int)pvVar7 + 0x3c) == 0) {

          FUN_004f1e20();

        }

        if (*(int *)((int)pvVar7 + 0x3c) != 0) {

          FUN_008a8040(*(int *)((int)pvVar7 + 0x3c) + 0x92);

          goto LAB_008a8b33;

        }

      }

      FUN_008a8040(PTR_u_contact_00af92fc);

    }

  }

  else {

    (**(code **)(*(int *)param_1[0x1a2] + 0x1d8))("Next mission",1,1);

  }

LAB_008a8b33:

  (**(code **)(*(int *)param_1[0x1a2] + 0x34c))();

  (**(code **)(*param_1 + 0x450))(0);

  pvVar7 = DAT_00d1ad10;

  if ((*(char *)((int)DAT_00d1ad10 + 8) != '\0') ||

     ((DAT_00d1b217 != '\0' && (cVar6 = FUN_00411220(), cVar6 != '\0')))) {

    cVar5 = '\0';

  }

  iVar9 = FUN_0092c810();

  if (iVar9 < 1) {

    cStack_124 = '\0';

    puVar11 = &uStack_123;

    for (iVar9 = 0x3f; iVar9 != 0; iVar9 = iVar9 + -1) {

      *puVar11 = 0;

      puVar11 = puVar11 + 1;

    }

    *(uint16_t *)puVar11 = 0;

    *(uint8_t *)((int)puVar11 + 2) = 0;

    if (((DAT_00d1b6d8 != 0) && (*(uint *)((int)pvVar7 + 0x10) != 0)) &&

       (pvVar7 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x548),*(uint *)((int)pvVar7 + 0x10))

       , local_298 = pvVar7, pvVar7 != (void *)0x0)) {

      piVar13 = (int *)0x0;

      FUN_00411630();

      puStack_18 = (uint8_t *)0x1;

      piStack_2a4 = piStack_280;

      CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x55c),*(uint *)((int)pvVar7 + 0x10));

      if ((*(char *)((int)DAT_00d1ad10 + 7) != '\0') &&

         (cVar5 = FUN_0052b420(*(uint32_t /* width from decompiler */ *)((int)pvVar7 + 0x14c),0), cVar5 != '\0')) {

        uVar14 = *(uint *)(*(int *)((int)pvVar7 + 0x14c) + 0xfc);

        pvVar8 = (void *)FUN_00541a80();

        piVar13 = CNDHash_LookupByKey(pvVar8,uVar14);

      }

      bVar4 = false;

      if (piStack_280 != piStack_27c) {

        do {

          piVar2 = (int *)*piStack_2a4;

          iVar9 = (**(code **)(*piVar2 + 0x50))();

          if (iVar9 == 0xc) {

            iVar9 = FUN_005710c0(piVar2[6],0,0);

            if (iVar9 != 0) {

              bVar4 = true;

            }

LAB_008a940e:

            if (((piVar13 == (int *)0x0) && (cVar5 = (**(code **)(*piVar2 + 0xc))(), cVar5 != '\0'))

               && (iVar9 = (**(code **)(*piVar2 + 0x58))(), iVar9 != -1)) {

              uVar14 = (**(code **)(*piVar2 + 0x58))();

              goto LAB_008a9444;

            }

          }

          else {

            iVar9 = (**(code **)(*piVar2 + 0x50))();

            if (iVar9 != 3) goto LAB_008a940e;

            (**(code **)(*piVar2 + 0x14))(auStack_228);

            uVar14 = uStack_248;

LAB_008a9444:

            pvVar7 = (void *)FUN_00541a80();

            piVar13 = CNDHash_LookupByKey(pvVar7,uVar14);

            cVar5 = (**(code **)(*piVar2 + 8))();

            pvVar7 = local_298;

            if (cVar5 == '\0') break;

          }

          piStack_2a4 = piStack_2a4 + 1;

          pvVar7 = local_298;

        } while (piStack_2a4 != piStack_27c);

      }

      if (piVar13 == (int *)0x0) {

        uVar14 = *(uint *)((int)pvVar7 + 0x120);

        pvVar7 = (void *)FUN_00541a80();

        piVar13 = CNDHash_LookupByKey(pvVar7,uVar14);

      }

      if (bVar4) {

        pcVar15 = (char *)FUN_007a6de0("Look in your Mission Inventory",0xffffffff);

        pcVar12 = &cStack_124;

        do {

          cVar5 = *pcVar15;

          *pcVar12 = cVar5;

          pcVar15 = pcVar15 + 1;

          pcVar12 = pcVar12 + 1;

        } while (cVar5 != '\0');

      }

      else if (piVar13 != (int *)0x0) {

        if (*(int *)(DAT_00d1b644 + 0xfc) == *piVar13) {

          pcVar15 = (char *)FUN_007a6de0("Read mission journal for details",0xffffffff);

          pcVar12 = &cStack_124;

          do {

            cVar5 = *pcVar15;

            *pcVar12 = cVar5;

            pcVar15 = pcVar15 + 1;

            pcVar12 = pcVar12 + 1;

          } while (cVar5 != '\0');

        }

        else {

          puVar11 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

          puStack_18._0_1_ = 2;

          FUN_007a6de0(*puVar11,0xffffffff);

          uVar16 = FUN_007a6de0("Go to",0xffffffff);

          sprintf(&cStack_124,"%s %s",uVar16);

          puStack_18 = (uint8_t *)CONCAT31(puStack_18._1_3_,1);

          if (_auStack_224 != &uStack_220) {

            free(_auStack_224);

          }

        }

      }

      puStack_18 = (uint8_t *)0xffffffff;

      FUN_00691630();

    }

    (**(code **)(*(int *)param_1[0x1a5] + 0x1d8))(&cStack_124,1,1);

    (**(code **)(*(int *)param_1[0x1a5] + 0x34c))();

    (**(code **)(*(int *)param_1[0x1a4] + 4))(0);

    ExceptionList = local_1c;

    return;

  }

  if (DAT_00d1b6d8 == 0) {

    (**(code **)(*(int *)param_1[0x1a5] + 0x1d8))(0,1,1);

    (**(code **)(*(int *)param_1[0x1a5] + 0x34c))();

    (**(code **)(*(int *)param_1[0x1a4] + 4))(0);

    ExceptionList = pvStack_30;

    return;

  }

  FUN_004023f0();

  puStack_18 = (uint8_t *)0x0;

  _auStack_224 = (uint *)((uint)_auStack_224 & 0xffff0000);

  puVar11 = (uint32_t /* width from decompiler */ *)(auStack_224 + 2);

  for (iVar9 = 0x3f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar11 = 0;

    puVar11 = puVar11 + 1;

  }

  *(uint16_t *)puVar11 = 0;

  if ((*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0') &&

     (iVar9 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)

                               (*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa4 + DAT_00d1b6d8),0,

                              &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGPhysicsBase::RTTI_Type_Descriptor), iVar9 == 0))

  goto LAB_008a9279;

  puVar11 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

  uStack_284 = *puVar11;

  piStack_280 = (int *)puVar11[1];

  piStack_27c = (int *)puVar11[2];

  uStack_278 = puVar11[3];

  FUN_004e88e0(&fStack_254);

  Client_EvalAutoPatrolWaypoint(DAT_00d1ad10,auStack_244,&fStack_270);

  iVar9 = TFID_EqualsObjectId(auStack_244,&DAT_00a1e3a8);

  if ((char)iVar9 != '\0') {

    if ((*(int *)(DAT_00d1b6d8 + 0x548) != 0) &&

       (0 < *(int *)(*(int *)(DAT_00d1b6d8 + 0x548) + 0xc))) {

      *(uint8_t *)((int)DAT_00d1ad10 + 4) = 1;

    }

    (**(code **)(*(int *)param_1[0x1a5] + 0x1d8))(0,1,1);

    (**(code **)(*(int *)param_1[0x1a5] + 0x34c))();

    (**(code **)(*(int *)param_1[0x1a4] + 4))(0);

    goto LAB_008a9279;

  }

  fVar17 = (float10)FUN_00404c00();

  if (fVar17 <= (float10)g_flZero) goto LAB_008a9279;

  fStack_28c = fStack_268 - fStack_24c;

  fStack_290 = fStack_26c - fStack_250;

  fStack_26c = fStack_26c -

               (*(float *)(DAT_00d17944 + 0x214) * g_flLevelUpUiBase_Inferred +

               *(float *)(DAT_00d17944 + 0x22c));

  fStack_294 = fStack_270 - fStack_254;

  fStack_270 = fStack_294;

  fStack_268 = fStack_28c;

  fVar17 = (float10)FUN_00404c00();

  fVar1 = (float)fVar17;

  if (cVar5 == '\0') {

    if (*(char *)((int)DAT_00d1ad10 + 8) == '\0') {

      pcVar12 = (char *)FUN_007a6de0("(Look for Gold Targets on Minimap)",0xffffffff);

      sprintf(auStack_224,pcVar12);

    }

    else {

      pcVar12 = (char *)FUN_007a6de0("(Look for Large Blue Dots on Minimap)",0xffffffff);

      sprintf(auStack_224,pcVar12);

    }

  }

  else if (DAT_00d1b24f == '\x01') {

    if (fVar1 <= DAT_00aaa670) {

      if (DAT_00a0f520 <= fVar1) {

        pcVar12 = "%.2fkm";

        fVar3 = g_flMsToSeconds_Inferred;

        goto LAB_008a8f0b;

      }

      local_298 = (void *)(int)ROUND(fVar1);

      sprintf(auStack_224,"%im");

    }

    else {

      _auStack_224 = (uint *)DAT_00a2d2cc;

      uStack_220 = DAT_00a2d2d0;

    }

  }

  else if (fVar1 <= _DAT_00aaa8a0) {

    if (fVar1 <= _DAT_00aaa89c) {

      if (fVar1 <= _DAT_00aaa888) {

        local_298 = (void *)(fVar1 * _DAT_00aaa890);

        sprintf(auStack_224,"%i ft");

      }

      else {

        local_298 = (void *)(fVar1 * _DAT_00aaa894);

        sprintf(auStack_224,"%i yds");

      }

    }

    else {

      pcVar12 = "%.2f mi";

      fVar3 = _DAT_00aaa88c;

LAB_008a8f0b:

      sprintf(auStack_224,pcVar12,(double)(fVar1 * fVar3));

    }

  }

  else {

    _auStack_224 = (uint *)DAT_00a2d2ec;

    uStack_220 = DAT_00a2d2f0;

    uStack_21c = DAT_00a2d2f4;

  }

  if (param_1[0x1a5] != 0) {

    local_29c = 0xffffffff;

    fStack_290 = _DAT_00aaaab0;

    fStack_28c = g_flZero;

    fStack_294 = DAT_00aaa6f8;

    if (cVar5 == '\0') {

      fStack_290 = DAT_00aaaab8;

      fStack_28c = DAT_00aaaab4;

      fStack_294 = _DAT_00aaa7c0;

    }

    fStack_294 = DAT_00b017e8 * fStack_294;

    fStack_288 = DAT_00b017e8 * DAT_00aaa6f8;

    fStack_28c = DAT_00b017e8 * fStack_28c;

    fStack_290 = DAT_00b017e8 * fStack_290;

    if (param_1[0x1a4] != 0) {

      iVar9 = (**(code **)(*(int *)param_1[0x1a4] + 0x290))();

      if (iVar9 != 0) {

        fStack_264 = (float)param_1[0x1ab] * fStack_294;

        fStack_260 = fStack_290 * (float)param_1[0x1ac];

        fStack_25c = fStack_28c * (float)param_1[0x1ad];

        fStack_258 = fStack_288 * (float)param_1[0x1ae];

        (**(code **)(*(int *)param_1[0x1a4] + 0x290))();

        FUN_009700f0("MatDiffuse",&fStack_264);

        fStack_264 = (float)param_1[0x1a7] * fStack_294;

        fStack_260 = fStack_290 * (float)param_1[0x1a8];

        fStack_25c = fStack_28c * (float)param_1[0x1a9];

        fStack_258 = fStack_288 * (float)param_1[0x1aa];

        (**(code **)(*(int *)param_1[0x1a4] + 0x290))();

        FUN_009700f0("MatAmbient",&fStack_264);

        fStack_264 = (float)param_1[0x1af] * fStack_294;

        fStack_260 = fStack_290 * (float)param_1[0x1b0];

        fStack_25c = fStack_28c * (float)param_1[0x1b1];

        fStack_258 = fStack_288 * (float)param_1[0x1b2];

        (**(code **)(*(int *)param_1[0x1a4] + 0x290))();

        FUN_009700f0("MatEmissive",&fStack_264);

      }

      if (cVar5 == '\0') {

        (**(code **)(*(int *)param_1[0x1a4] + 4))();

      }

      else {

        (**(code **)(*(int *)param_1[0x1a4] + 4))();

      }

    }

    (**(code **)(*(int *)param_1[0x1a2] + 0x34c))();

    (**(code **)(*(int *)param_1[0x1a5] + 0x15c))(1,&local_29c);

    (**(code **)(*(int *)param_1[0x1a5] + 0x1d8))(auStack_22c,1,1);

    (**(code **)(*(int *)param_1[0x1a5] + 0x34c))();

    FUN_0076f5f0(&fStack_270,&fStack_270);

    iVar9 = *(int *)(*(int *)(*(int *)(DAT_00d1b644 + 0xe894) + 0xc0) + 8);

    fStack_294 = *(float *)(iVar9 + 0x80);

    fStack_290 = *(float *)(iVar9 + 0x84);

    fStack_28c = *(float *)(iVar9 + 0x88);

    fStack_288 = *(float *)(iVar9 + 0x8c);

    FUN_004e92d0(&fStack_270,auStack_244);

    FUN_00411770();

    FUN_0076df50(auStack_244,auStack_244,&fStack_294);

    if ((param_1[0x1a4] != 0) &&

       (iVar9 = (**(code **)(*(int *)param_1[0x1a4] + 0x290))(), iVar9 != 0)) {

      piVar13 = (int *)(**(code **)(*(int *)param_1[0x1a4] + 0x290))();

      (**(code **)(*piVar13 + 0x14))();

    }

  }

LAB_008a9279:

  puStack_18 = (uint8_t *)0xffffffff;

  FUN_00403430();

  ExceptionList = pvStack_20;

  return;

}
