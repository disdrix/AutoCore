// =============================================================================
// FUN_004dfcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004dfcc0
// Address:   0x004dfcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004dfcc0 @ 0x004dfcc0
// Stable ID: aa_004dfcc0
// Embedded strings (evidence for future rename):
//   - "LoadFromFileToPending"
//   - "\n\n************ Starting Map Load\n\n"
//   - "Loading Modules"
//   - "totalObjs"
//   - "loading #%d Objects"
//   - "Invalid load position for %I64d - %I32d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~393 non-empty decompiler lines.
//  - Control keywords: if×36, goto×12, while×4, do×3, return×3, for×1.
//  - Notable callees: block×8, FUN_007a4390×6, CONCAT31×5, FUN_007a4400×3, FUN_007a4480×3, CVOGReaction_GiveItemByCbid×2, FUN_004024d0×2, FUN_00494850×2.
//  - Strings: "LoadFromFileToPending"; "\n\n************ Starting Map Load\n\n"; "Loading Modules"; "totalObjs".
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

/* WARNING: Removing unreachable block (ram,0x004dffb6) */

/* WARNING: Removing unreachable block (ram,0x004dffc4) */

/* WARNING: Removing unreachable block (ram,0x004dfe97) */

/* WARNING: Removing unreachable block (ram,0x004dfea5) */

/* WARNING: Removing unreachable block (ram,0x004dfffa) */

/* WARNING: Removing unreachable block (ram,0x004e0011) */

/* WARNING: Removing unreachable block (ram,0x004dfedf) */

/* WARNING: Removing unreachable block (ram,0x004dfef6) */



uint32_t /* width from decompiler */ __thiscall FUN_004dfcc0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint uVar1;

  char cVar2;

  int *piVar3;

  uint *puVar4;

  int *piVar5;

  char *pcVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ uVar9;

  uint8_t uVar10;

  uint32_t /* width from decompiler */ uStack_ee0;

  uint16_t uStack_edc;

  int local_ed8;

  char local_ed1;

  int *piStack_ed0;

  uint uStack_ecc;

  uint32_t /* width from decompiler */ uStack_ec8;

  uint32_t /* width from decompiler */ uStack_ec4;

  uint32_t /* width from decompiler */ *local_ec0;

  uint local_ebc;

  uint32_t /* width from decompiler */ *local_eb8;

  int local_eb4;

  int *piStack_eb0;

  int *local_eac;

  uint local_ea8;

  uint8_t uStack_ea1;

  uint uStack_ea0;

  int iStack_e9c;

  int local_e94;

  uint uStack_e90;

  int iStack_e8c;

  int local_e88;

  int local_e84 [7];

  uint local_e68;

  uint local_e64;

  uint8_t local_e60 [8];

  int iStack_e58;

  uint32_t /* width from decompiler */ uStack_e50;

  uint32_t /* width from decompiler */ uStack_e4c;

  uint32_t /* width from decompiler */ uStack_e48;

  uint32_t /* width from decompiler */ uStack_e44;

  uint8_t auStack_e3c [20];

  uint uStack_e28;

  uint32_t /* width from decompiler */ uStack_e24;

  uint8_t auStack_de8 [536];

  char local_bd0 [1036];

  char acStack_7c4 [268];

  undefined **ppuStack_6b8;

  uint8_t uStack_6b3;

  uint8_t uStack_6b2;

  int *piStack_24;

  void *pvStack_20;

  void *local_1c;

  uint8_t *puStack_18;

  uint local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a249c;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

  FUN_007a4400("LoadFromFileToPending");

  local_14 = 0;

  OutputDebugStringA("\n\n************ Starting Map Load\n\n");

  if (*(int *)(param_1 + 0xe4f8) != 0) {

    FUN_004ce020(param_2);

    *(uint8_t *)(*(int *)(param_1 + 0xe894) + 0x8b) = 1;

    QueryPerformanceFrequency((LARGE_INTEGER *)(auStack_e3c + 4));

    QueryPerformanceCounter((LARGE_INTEGER *)local_e60);

    FUN_005126f0();

    piVar3 = (int *)FUN_004ddcc0(&local_e88,local_e84,&local_e68,&local_e94);

    local_eac = piVar3;

    if (piVar3 != (int *)0x0) {

      *(uint *)(param_1 + 0xe6d8) = local_e68 + 1;

      local_e84[1] = 0;

      local_e84[2] = 0;

      local_e84[3] = 0;

      local_e84[4] = 0;

      local_eb4 = 0;

      local_ed8 = 0;

      *(uint *)(param_1 + 0xe6dc) = local_e64 + (0xfffffffe < local_e68);

      local_ec0 = (uint32_t /* width from decompiler */ *)0x0;

      FUN_00691630();

      local_eb8 = (uint32_t /* width from decompiler */ *)0x0;

      uVar10 = (uint8_t)((uint)unaff_EBX >> 0x10);

      if (0 < local_e94) {

        do {

          FUN_007a4400("Loading Modules");

          local_14 = CONCAT31(local_14._1_3_,1);

          if (4 < *(int *)(param_1 + 0x8c)) {

            (**(code **)(*piVar3 + 0x14))();

          }

          uVar9 = 4;

          puVar4 = &local_ebc;

          (**(code **)(*piVar3 + 0x14))();

          FUN_00513880(piVar3,&local_ed8,puVar4,uVar9);

          (**(code **)(*piVar3 + 0x14))(&uStack_ecc,4);

          piVar5 = (int *)CVOGReaction_GiveItemByCbid(local_ebc);

          if (piVar5 == (int *)0x0) {

LAB_004e0268:

            iStack_e9c = (int)local_ebc >> 0x1f;

            uStack_ea0 = local_ebc;

            piStack_eb0 = piStack_ed0;

            cVar2 = FUN_004cd3c0(piVar3,&piStack_eb0,&uStack_ea0,uStack_ec4,piVar5,local_ec0,

                                 local_eb4);

            if (cVar2 == '\0') {

              local_14 = local_14 & 0xffffff00;

              FUN_007a4390();

              goto LAB_004e06fb;

            }

          }

          else {

            uStack_ecc = (**(code **)(*piVar5 + 8))(local_ebc,param_1,1);

            if (((int)uStack_ecc < 0) ||

               (local_ec0 = (uint32_t /* width from decompiler */ *)

                            __RTDynamicCast(piVar5,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                            &CVOGMapModulePlacement::RTTI_Type_Descriptor,0),

               local_ec0 == (uint32_t /* width from decompiler */ *)0x0)) {

              (**(code **)*piVar5)(1);

              goto LAB_004e0268;

            }

            *(uint8_t *)(piVar5 + 0x5e) = uVar10;

            (**(code **)(*piVar5 + 0x218))(param_1);

            FUN_00512160(uStack_ee0,uStack_edc,0);

            if ((*(char *)(param_1 + 0x7d) == '\0') && (*(char *)(param_1 + 0x7e) != '\0')) {

              (**(code **)(*piVar5 + 0xa4))(piVar3,*(uint32_t /* width from decompiler */ *)(param_1 + 0x8c),&uStack_e90,0);

              FUN_004de350(local_eb4);

            }

            else {

              (**(code **)(*piVar5 + 0xa4))(piVar3,*(uint32_t /* width from decompiler */ *)(param_1 + 0x8c),&uStack_e90,0);

              FUN_004024d0(piVar5);

              *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;

              if (local_ed8 < (int)(uint)*(ushort *)(param_1 + 0x940)) {

                puVar4 = (uint *)(param_1 + 0x950 + local_ed8 * 0x18);

                while (((int *)*puVar4 != piStack_ed0 || (puVar4[1] != uStack_ecc))) {

                  if (((int)uStack_ecc < (int)puVar4[1]) ||

                     (((int)uStack_ecc <= (int)puVar4[1] && (piStack_ed0 <= (int *)*puVar4))))

                  goto LAB_004e02a7;

                  local_ed8 = local_ed8 + 1;

                  puVar4 = puVar4 + 6;

                  if ((int)(uint)*(ushort *)(param_1 + 0x940) <= local_ed8) goto LAB_004e02a7;

                }

                piStack_eb0 = (int *)FUN_004e53a0(*(uint32_t /* width from decompiler */ *)

                                                   (param_1 + (local_ed8 * 3 + 300) * 8));

                if (piStack_eb0 != (int *)0x0) {

                  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe6d8) =

                       *(uint32_t /* width from decompiler */ *)(param_1 + 0x958 + local_ed8 * 0x18);

                  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe6dc) =

                       *(uint32_t /* width from decompiler */ *)(param_1 + 0x95c + local_ed8 * 0x18);

                  FUN_004db820();

                  iVar8 = *(int *)(*(int *)(local_eb4 + 4) + 4);

                  uStack_e50 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x84 + local_eb4);

                  uStack_e4c = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x88 + local_eb4);

                  uStack_e48 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x8c + local_eb4);

                  uStack_e44 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x90 + local_eb4);

                  local_ea8 = CONCAT31(local_ea8._1_3_,(char)piVar5[0x5e]);

                  FUN_005ea300(param_1,&uStack_e50,local_ea8);

                }

                local_ed8 = local_ed8 + 1;

              }

            }

          }

LAB_004e02a7:

          local_14 = local_14 & 0xffffff00;

          FUN_007a4390();

          local_eb8 = (uint32_t /* width from decompiler */ *)((int)local_eb8 + 1);

        } while ((int)local_eb8 < local_e94);

      }

      FUN_004e6510(2);

      local_14._0_1_ = 2;

      FUN_007a4400("totalObjs");

      uVar1 = local_e88 + local_e84[0];

      local_14 = CONCAT31(local_14._1_3_,3);

      local_ea8 = uVar1;

      sprintf(local_bd0,"loading #%d Objects",uVar1);

      local_eb8 = (uint32_t /* width from decompiler */ *)0x0;

      if (uVar1 != 0) {

        do {

          local_ed1 = '\0';

          if (4 < *(int *)(param_1 + 0x8c)) {

            (**(code **)(*piVar3 + 0x14))();

          }

          uVar9 = 4;

          puVar4 = &local_ebc;

          (**(code **)(*piVar3 + 0x14))();

          FUN_00513880(piVar3,&local_ed8,puVar4,uVar9);

          (**(code **)(*piVar3 + 0x14))(&uStack_ecc,4);

          iVar8 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                   (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & local_ebc) * 4)

                          + 4);

          if (iVar8 == 0) {

LAB_004e030d:

            local_ed8 = 0;

          }

          else {

            do {

              if (local_ebc == *(uint *)(iVar8 + 0x10)) {

                if (iVar8 == 0) goto LAB_004e030d;

                local_ed8 = *(int *)(iVar8 + 8);

                goto LAB_004e031e;

              }

              iVar8 = *(int *)(iVar8 + 0xc);

            } while (iVar8 != 0);

            local_ed8 = 0;

          }

LAB_004e031e:

          piVar5 = (int *)CVOGReaction_GiveItemByCbid(local_ebc);

          if (piVar5 == (int *)0x0) {

LAB_004e0731:

            iStack_e8c = (int)local_ebc >> 0x1f;

            uStack_e90 = local_ebc;

            piStack_eb0 = piStack_ed0;

            cVar2 = FUN_004cd3c0(piVar3,&piStack_eb0,&uStack_e90,uStack_ec4,piVar5,local_ec0,

                                 local_eb4);

            if (cVar2 == '\0') {

LAB_004e06d3:

              local_14._0_1_ = 2;

              FUN_007a4390();

              local_14 = (uint)local_14._1_3_ << 8;

              FUN_004e6610();

              goto LAB_004e06fb;

            }

          }

          else {

            uStack_ecc = (**(code **)(*piVar5 + 8))(local_ebc,param_1,1);

            if ((int)uStack_ecc < 0) {

              (**(code **)*piVar5)(1);

              goto LAB_004e0731;

            }

            *(uint8_t *)(piVar5 + 0x5e) = uVar10;

            (*(code *)((uint32_t /* width from decompiler */ *)*piVar5)[0x86])(param_1);

            FUN_00512160(uStack_ee0,uStack_edc,0);

            iVar8 = *(int *)(piVar5[0x2a] + 0x3c);

            if (((*(short *)(iVar8 + 0x3f4) == 0xd) || (*(short *)(iVar8 + 0x3f4) == 0xe)) ||

               (*(short *)(iVar8 + 0x3f4) == 0xf)) {

              local_eac = (int *)piVar5[0x59];

              piStack_eb0 = (int *)piVar5[0x58];

              FUN_00418d70(&piStack_eb0);

            }

            cVar2 = (**(code **)(*piVar5 + 0xa4))

                              (piVar3,*(uint32_t /* width from decompiler */ *)(param_1 + 0x8c),&uStack_e90,0);

            if (cVar2 != '\0') {

              pcVar6 = (char *)FUN_005d6870(&uStack_ea1);

              if (*pcVar6 == '\0') {

                FUN_007a4480(1,"Invalid load position for %I64d - %I32d",piStack_ed0,uStack_ecc,

                             local_ebc);

                iVar7 = DAT_00a0f694;

                iVar8 = DAT_009cca58;

                piVar5[0x20] = DAT_00a0f694;

                piVar5[0x22] = iVar7;

                piVar5[0x23] = 0;

                piVar5[0x21] = iVar8;

                piVar5[0x27] = 0;

                piVar5[0x26] = 0;

                piVar5[0x25] = 0;

                piVar5[0x24] = 0;

                piVar5[0x27] = (int)g_flOne;

              }

              iVar8 = local_ed8;

              cVar2 = local_ed1;

              if (((((*(int *)(piVar5[0x2a] + 0x38) == 1) && (*(int *)(local_ed8 + 0x3c) != 0)) &&

                   (((*(byte *)(*(int *)(local_ed8 + 0x3c) + 0x3f2) & 0x20) == 0 &&

                    ((FUN_004eb3b0(), cVar2 = local_ed1, *(int *)(iVar8 + 0x88) == 0 &&

                     (iVar7 = (**(code **)(*piVar5 + 0x1cc))(), cVar2 = local_ed1,

                     *(int *)(iVar7 + 0x1c) == 0)))))) &&

                  (iVar7 = (**(code **)(*piVar5 + 0x1cc))(), cVar2 = local_ed1,

                  *(int *)(iVar7 + 0x18) == 0)) &&

                 (((*(short *)(*(int *)(iVar8 + 0x3c) + 0x3f4) != 0xc &&

                   (((uint)piVar5[0x5f] >> 9 & 1) != 0)) &&

                  ((*(byte *)(*(int *)(piVar5[0x2a] + 0x3c) + 0x3f2) & 4) == 0)))) {

                FUN_004986d0(auStack_de8);

                piVar3 = (int *)FUN_004e3260();

                if ((piVar3 != (int *)0x0) && (iVar8 = (**(code **)(*piVar3 + 0x1cc))(), iVar8 != 0)

                   ) {

                  iVar8 = FUN_004e3260();

                  if (iVar8 == 0) {

                    uVar9 = (**(code **)(*piVar5 + 0x1cc))();

                    FUN_00494850(uVar9);

                    (**(code **)*piVar5)(1);

                  }

                  goto LAB_004e0770;

                }

                cVar2 = '\x01';

              }

              iVar8 = FUN_004e23d0(piStack_ed0,uStack_ecc,&piStack_eb0);

              if ((iVar8 == 0) || (*(int *)(iVar8 + 0xc) == 0)) {

                if (cVar2 == '\0') {

                  FUN_004024d0(piVar5);

                  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;

                }

                else {

                  *(byte *)((int)piVar5 + 0x17d) = *(byte *)((int)piVar5 + 0x17d) | 0x40;

                  FUN_004bc180(piVar5);

                  FUN_004f1c70();

                  (**(code **)(*piVar5 + 0xb4))();

                }

                if ((*(int *)(piVar5[0x2a] + 0x38) == 3) && (*(char *)(param_1 + 0x100) != '\0')) {

                  *(byte *)((int)piVar5 + 0x17d) = *(byte *)((int)piVar5 + 0x17d) | 0x10;

                }

                if (cVar2 != '\0') {

                  uStack_e28 = uStack_e28 & 0xffffff00;

                  FUN_00498700(piStack_ed0,uStack_ecc,uStack_e28,uStack_e24);

                  FUN_004e7e60(piStack_ed0,uStack_ecc,piVar5,0);

                  uVar9 = (**(code **)(*piVar5 + 0x1cc))();

                  FUN_00494850(uVar9);

                }

                goto LAB_004e0770;

              }

              (**(code **)*piVar5)(1);

              iVar8 = (**(code **)(*piStack_eb0 + 4))(uStack_ec8);

              if (iVar8 != -1) goto LAB_004e0770;

              FUN_007a4480(1,"Seek error, seeking %li bytes from current",uStack_ec4);

              goto LAB_004e06d3;

            }

            (**(code **)*piVar5)(1);

          }

LAB_004e0770:

          local_eb8 = (uint32_t /* width from decompiler */ *)((int)local_eb8 + 1);

          piVar3 = local_eac;

        } while (local_eb8 < local_ea8);

      }

      local_14 = CONCAT31(local_14._1_3_,2);

      FUN_007a4390();

      if (0x2a < *(int *)(param_1 + 0x8c)) {

        (**(code **)(*piVar3 + 0x14))();

      }

      FUN_004dc1c0();

      if (*(int *)(param_1 + 0x8c) < 0x26) {

        FUN_004cd9a0(piVar3);

      }

      if (0x29 < *(int *)(param_1 + 0x8c)) {

        FUN_004d6ff0();

      }

      if (0x1d < *(int *)(param_1 + 0x8c)) {

        FUN_0079ce60();

        ppuStack_6b8 = &PTR_FUN_009cc008;

        uStack_6b3 = 1;

        uStack_6b2 = 0;

        local_14._0_1_ = 4;

        piStack_24 = piVar3;

        FUN_00497c80();

        FUN_00497d60(&ppuStack_6b8);

        FUN_00498380();

        FUN_00497690(param_1 + 0xe198);

        local_14 = CONCAT31(local_14._1_3_,2);

        ppuStack_6b8 = &PTR_LAB_009cbf98;

      }

      FUN_004d73c0(piVar3);

      local_ec0 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe8fc) + 4);

      local_eb8 = local_ec0;

      if (*(char *)((int)local_ec0 + 0x15) != '\0') {

        *(int *)(*(int *)(param_1 + 0xe8fc) + 4) = *(int *)(param_1 + 0xe8fc);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xe900) = 0;

        *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0xe8fc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8fc);

        *(int *)(*(int *)(param_1 + 0xe8fc) + 8) = *(int *)(param_1 + 0xe8fc);

        (**(code **)*piVar3)(1);

        FUN_005abba0();

        QueryPerformanceCounter((LARGE_INTEGER *)(local_e60 + 4));

        local_e94 = local_e60._4_4_ - local_e64;

        uStack_e90 = (iStack_e58 - local_e60._0_4_) - (uint)((uint)local_e60._4_4_ < local_e64);

        sprintf(acStack_7c4,"******* Map (%s) loaded to pending in: (%f) sec.\n",param_1 + 0xb4,

                (double)CONCAT44(uStack_e90,local_e94) / (double)(longlong)auStack_e3c._0_8_);

        OutputDebugStringA(acStack_7c4);

        puStack_18 = (uint8_t *)((uint)puStack_18 & 0xffffff00);

        FUN_004e6610();

        puStack_18 = (uint8_t *)0xffffffff;

        FUN_007a4390();

        ExceptionList = pvStack_20;

        return 1;

      }

      FUN_004e2980(local_ec0[2]);

      local_ec0 = (uint32_t /* width from decompiler */ *)*local_ec0;

                    /* WARNING: Subroutine does not return */

      operator_delete(local_eb8);

    }

    FUN_007a4480(1,"Could not locate the following map: %s",param_1 + 0xe198);

  }

LAB_004e06fb:

  local_14 = 0xffffffff;

  FUN_007a4390();

  ExceptionList = local_1c;

  return 0;

}
