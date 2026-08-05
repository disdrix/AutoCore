// =============================================================================
// Weapon_SelectMultiTargets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0056c0a0
// Address:   0x0056c0a0  (autoassault.exe, image base 0x400000)
// System:    combat / vehicle weapon targeting
// Generated: 2026-07-29 W20-H dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Virtual weapon method: select up to maxTargets combat targets into the
//   weapon's locked result list (this+0x13c). Prefer preferredTarget when in
//   range; fill remaining slots from locked world list ordered by
//   CVOGPhysicsUtils_FindDistanceToTarget. Fail → 0xffffffff; success → count.
//
// ABI: __thiscall; ret 8
//   ECX = weapon*
//   arg0 = locked object list* (CS @ +4, held-flag @ +0x28)
//   arg1 = preferred target object* (may be null)
//
// Body: 0056c0a0–0056c856 (1974 B). DATA vtable only (@ 0x009d3330, 0x009ddad8).
// String: "WARNING Weaopn <%s> has invalid # of maxtargets(%d) set!" @ 0x009d2fcc
// Product class/RTTI spelling residual — keep _Inferred.
//
// Line-faithful CF from Ghidra decompile (types tentative).
/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t __thiscall Weapon_SelectMultiTargets_Inferred(int param_1,int param_2,int *param_3)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ *puVar6;

  void *pvVar7;

  int iVar8;

  float10 fVar9;

  int *piVar10;

  uint uStack_21c;

  int *piStack_218;

  uint32_t /* width from decompiler */ *puStack_214;

  uint uStack_210;

  int iStack_20c;

  uint32_t /* width from decompiler */ uStack_208;

  uint32_t /* width from decompiler */ uStack_204;

  float fStack_200;

  float fStack_1fc;

  float fStack_1f8;

  float fStack_1f4;

  void *pvStack_1e4;

  float fStack_1e0;

  float fStack_1dc;

  float fStack_1d8;

  float fStack_1d4;

  int iStack_1c8;

  uint32_t /* width from decompiler */ uStack_1c4;

  uint32_t /* width from decompiler */ uStack_1c0;

  uint32_t /* width from decompiler */ uStack_1bc;

  uint32_t /* width from decompiler */ uStack_1b8;

  int aiStack_1b4 [102];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a4d8e;

  pvStack_1c = ExceptionList;

  piVar10 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

  ExceptionList = &pvStack_1c;

  if (((piVar10 == (int *)0x0) ||

      (ExceptionList = &pvStack_1c, cVar2 = (**(code **)(*piVar10 + 0x198))(), cVar2 != '\0')) ||

     (param_2 == 0)) {

    if (*(int *)(param_1 + 0x13c) != 0) {

      FUN_0056bf70();

    }

    ExceptionList = pvStack_1c;

    return 0xffffffff;

  }

  if (*(int *)(param_1 + 0x13c) == 0) {

    ExceptionList = pvStack_1c;

    return 0xffffffff;

  }

  iVar3 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1c8))();

  if (*(int *)(iVar3 + 8) == 0) {

    ExceptionList = pvStack_1c;

    return 0xffffffff;

  }

  iStack_1c8 = iVar3;

  uStack_210 = FUN_0056ac50();

  uStack_21c = 0;

  iStack_20c = -1;

  if (100 < uStack_210) {

    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x160))

                      (uStack_210);

    FUN_007a4480(0,"WARNING Weaopn <%s> has invalid # of maxtargets(%d) set!",uVar4);

    uStack_210 = 100;

  }

  puStack_214 = _DAT_009d2fc8;

  fStack_200 = g_flOne;

  piVar10 = aiStack_1b4;

  for (iVar8 = 100; piVar10 = piVar10 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {

    *piVar10 = 0;

  }

  fStack_1fc = 0.0;

  fStack_1f8 = 0.0;

  fStack_1f4 = 0.0;

  piVar10 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

  uStack_208 = 0;

  if (*(int *)(piVar10[0x2a] + 0x38) == 0xe) {

    (**(code **)(*piVar10 + 0x1d4))();

    iVar8 = *(int *)(*(int *)(param_1 + 4) + 4);

    FUN_004f8c50(&fStack_200,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x164 + param_1),

                 *(uint32_t /* width from decompiler */ *)(iVar8 + 0x168 + param_1));

    uVar4 = FUN_00404a20(&fStack_200,&fStack_1e0);

    uVar4 = FUN_00404c90(uVar4);

    FUN_004e8bf0(uVar4);

    pfVar5 = (float *)FUN_00404c90();

    fStack_1e0 = fStack_1e0 - *pfVar5;

    fStack_1dc = fStack_1dc - pfVar5[1];

    fStack_1d8 = fStack_1d8 - pfVar5[2];

    piStack_218 = (int *)(fStack_1d8 * fStack_1d8 + fStack_1dc * fStack_1dc +

                         fStack_1e0 * fStack_1e0);

    fStack_1d4 = fStack_1d4 - pfVar5[3];

    if ((float)piStack_218 == 0.0) {

      piVar10 = (int *)0x0;

    }

    else {

      piVar10 = (int *)(g_flOne / SQRT((float)piStack_218));

      piStack_218 = piVar10;

    }

    fStack_200 = (float)piVar10 * fStack_1e0;

    fStack_1fc = fStack_1dc * (float)piVar10;

    fStack_1f8 = fStack_1d8 * (float)piVar10;

    fStack_1f4 = fStack_1d4 * (float)piVar10;

  }

  else {

    uVar4 = FUN_00404a20(&fStack_200);

    FUN_004e8a40(uVar4);

  }

  puVar6 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

  uStack_1c0 = *puVar6;

  uStack_1bc = puVar6[1];

  uStack_1b8 = puVar6[2];

  aiStack_1b4[0] = puVar6[3];

  if (((param_3 != (int *)0x0) && (cVar2 = (**(code **)(*param_3 + 0x198))(), cVar2 == '\0')) &&

     ((cVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x298

                           ))(param_3), cVar2 != '\0' &&

      ((iVar8 = (**(code **)(*param_3 + 0x1c8))(), iVar8 != 0 && (*(int *)(iVar8 + 8) != 0)))))) {

    piStack_218 = *(int **)(param_1 + 0xdc);

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8);

    uStack_204 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x34);

    iVar3 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x210))

                      (0);

    fVar9 = (float10)FUN_004e9aa0(&uStack_1c0,uStack_204,uVar4,iVar8,&fStack_200,piStack_218,

                                  iVar3 != 0);

    if ((float)fVar9 != g_flZero) {

      puStack_214 = (uint32_t /* width from decompiler */ *)(float)fVar9;

      pvStack_1e4 = operator_new(0x10);

      uStack_14 = 0;

      if (pvStack_1e4 == (void *)0x0) {

        aiStack_1b4[1] = 0;

      }

      else {

        aiStack_1b4[1] = FUN_005770d0(param_3);

      }

      uStack_14 = 0xffffffff;

      iStack_20c = 0;

      uStack_21c = 1;

    }

  }

  if (uStack_21c != uStack_210) {

    FUN_004294f0();

    iVar3 = FUN_004022a0(&uStack_208,&piStack_218);

    piVar10 = piStack_218;

    while (piStack_218 = piVar10, iVar3 == 0) {

      piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

      if (((((piVar10 != piVar1) && (piVar10 != param_3)) &&

           (cVar2 = (**(code **)(*piVar1 + 0x298))(piVar10), cVar2 != '\0')) &&

          ((cVar2 = (**(code **)(*piVar10 + 0x198))(), cVar2 == '\0' &&

           (((uint)piVar10[0x5f] >> 5 & 1) != 0)))) &&

         ((cVar2 = FUN_005134e0(), cVar2 == '\0' && (((uint)piVar10[0x5f] >> 3 & 1) == 0)))) {

        iVar3 = (**(code **)(*piVar10 + 0x1d8))();

        if (iVar3 != 0) {

          (**(code **)(*piVar10 + 0x1d8))();

          cVar2 = FUN_0040b1b0();

          if (cVar2 != '\0') goto LAB_0056c6c2;

        }

        iVar3 = (**(code **)(*piVar10 + 0x1c8))();

        if (*(int *)(iVar3 + 8) != 0) {

          uStack_204 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc);

          uStack_1c4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8);

          pvStack_1e4 = *(void **)(iStack_1c8 + 0x34);

          iVar8 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +

                              0x210))(0);

          fVar9 = (float10)FUN_004e9aa0(&uStack_1c0,pvStack_1e4,uStack_1c4,iVar3,&fStack_200,

                                        uStack_204,iVar8 != 0);

          puVar6 = (uint32_t /* width from decompiler */ *)(float)fVar9;

          if ((float)puVar6 != g_flZero) {

            if ((float)puStack_214 <= (float)puVar6) {

              if (uStack_21c < uStack_210) {

                pvVar7 = operator_new(0x10);

                uStack_14 = 2;

                if (pvVar7 == (void *)0x0) {

                  iVar3 = 0;

                }

                else {

                  iVar3 = FUN_005770d0(piVar10);

                }

                aiStack_1b4[uStack_21c + 1] = iVar3;

                uStack_21c = uStack_21c + 1;

                uStack_14 = 0xffffffff;

              }

            }

            else {

              iVar8 = uStack_210 - 1;

              iVar3 = iVar8;

              puStack_214 = puVar6;

              if (iStack_20c + 1 < iVar8) {

                do {

                  if (iVar3 == iVar8) {

                    if ((uint32_t /* width from decompiler */ *)aiStack_1b4[iVar3 + 1] != (uint32_t /* width from decompiler */ *)0x0) {

                      (*(code *)**(uint32_t /* width from decompiler */ **)aiStack_1b4[iVar3 + 1])(1);

                    }

                    aiStack_1b4[iVar3 + 1] = 0;

                  }

                  aiStack_1b4[iVar3 + 1] = aiStack_1b4[iVar3];

                  iVar3 = iVar3 + -1;

                } while (iStack_20c + 1 < iVar3);

              }

              pvVar7 = operator_new(0x10);

              uStack_14 = 1;

              if (pvVar7 == (void *)0x0) {

                iVar3 = 0;

              }

              else {

                iVar3 = FUN_005770d0(piVar10);

              }

              uStack_14 = 0xffffffff;

              aiStack_1b4[iStack_20c + 2] = iVar3;

              if (uStack_21c < uStack_210) {

                uStack_21c = uStack_21c + 1;

              }

            }

          }

        }

      }

LAB_0056c6c2:

      iVar3 = FUN_004022a0(&uStack_208,&piStack_218);

      piVar10 = piStack_218;

    }

    if (*(char *)(param_2 + 0x28) != '\0') {

      *(uint8_t *)(param_2 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));

    }

  }

  puStack_214 = (uint32_t /* width from decompiler */ *)0x0;

  FUN_004294f0();

  iVar3 = FUN_004022a0(&uStack_208,&puStack_214);

  puVar6 = puStack_214;

  do {

    puStack_214 = puVar6;

    if (iVar3 != 0) {

      iVar3 = *(int *)(param_1 + 0x13c);

      if (*(char *)(iVar3 + 0x28) != '\0') {

        *(uint8_t *)(iVar3 + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

      }

      FUN_0056f0b0();

      iVar3 = 0;

      if (0 < (int)uStack_21c) {

        do {

          FUN_0056eca0(aiStack_1b4[iVar3 + 1]);

          iVar3 = iVar3 + 1;

        } while (iVar3 < (int)uStack_21c);

        if (99 < iVar3) {

          ExceptionList = pvStack_1c;

          return uStack_21c;

        }

      }

      do {

        if ((uint32_t /* width from decompiler */ *)aiStack_1b4[iVar3 + 1] == (uint32_t /* width from decompiler */ *)0x0) {

          ExceptionList = pvStack_1c;

          return uStack_21c;

        }

        (*(code *)**(uint32_t /* width from decompiler */ **)aiStack_1b4[iVar3 + 1])(1);

        aiStack_1b4[iVar3 + 1] = 0;

        iVar3 = iVar3 + 1;

      } while (iVar3 < 100);

      ExceptionList = pvStack_1c;

      return uStack_21c;

    }

    if (0 < (int)uStack_21c) {

      iVar3 = 0;

      do {

        if (((puVar6[1] == *(int *)(aiStack_1b4[iVar3 + 1] + 4)) &&

            (cVar2 = FUN_005134e0(), cVar2 == '\0')) &&

           ((*(uint *)(puVar6[1] + 0x17c) >> 3 & 1) == 0)) {

          iVar3 = aiStack_1b4[iVar3 + 1];

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = puVar6[3];

          *(uint8_t *)(iVar3 + 8) = *(uint8_t *)(puVar6 + 2);

          break;

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < (int)uStack_21c);

    }

    if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar6)(1);

    }

    iVar3 = FUN_004022a0(&uStack_208,&puStack_214);

    puVar6 = puStack_214;

  } while( true );

}

