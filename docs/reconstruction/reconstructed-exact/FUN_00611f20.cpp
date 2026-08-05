// =============================================================================
// FUN_00611f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00611f20
// Address:   0x00611f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00611f20 @ 0x00611f20
// Stable ID: aa_00611f20
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~183 non-empty decompiler lines.
//  - Control keywords: if×28, return×6, goto×3, do×2, while×2.
//  - Notable callees: CNDHash_LookupByKey×2, CVOGReaction_GiveItemByCbid×2, FUN_004d2820×2, FUN_005711c0×2, FUN_007a4480×2, CONCAT31, CVOGReaction_RandomUnitScalar, FUN_00404c90.
//  - Strings: "allocatenewobjectfromcbid failed %d".
//  - Return sites: 6.

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

uint __thiscall

FUN_00611f20(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3,int *param_4,float param_5,float param_6,

            uint32_t /* width from decompiler */ param_7,int *param_8)



{

  ushort uVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  float *pfVar7;

  void *pvVar8;

  int *piVar9;

  uint uVar10;

  int iStack_44;

  int iStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  float fStack_28;

  float fStack_20;

  

  if (param_4 == (int *)0x0) {

    if (((char)param_1[0x16] == '\0') ||

       ((param_4 = (int *)(**(code **)(*param_8 + 0x27c))(), param_1[0x17] <= (int)param_4 &&

        (param_4 = (int *)(**(code **)(*param_8 + 0x27c))(), (int)param_4 <= param_1[0x18])))) {

      if (*(char *)((int)param_1 + 0x19) == '\0') {

        param_4 = *(int **)(param_2 + 0x250);

        if ((param_4 != (int *)0x0) && (param_4[0xac] != 0)) {

          uStack_38 = FUN_005711c0(param_1[4],0);

          param_4 = (int *)(**(code **)(*param_8 + 0x1d4))();

          if ((iStack_3c < param_1[5]) && (iStack_44 = 0, 0 < param_1[7])) {

            piVar9 = param_1 + 8;

            do {

              if (*(char *)((int)param_1 + 0x1a) == '\0') {

                piVar5 = param_4;

                if (((int)param_5 == *piVar9) || (*piVar9 == -1)) goto LAB_0061208e;

              }

              else if ((param_4 != (int *)0x0) &&

                      (piVar5 = (int *)FUN_005001f0(), *piVar9 == *piVar5)) goto LAB_0061208e;

              iStack_44 = iStack_44 + 1;

              piVar9 = piVar9 + 1;

              if (param_1[7] <= iStack_44) {

                return (uint)param_4 & 0xffffff00;

              }

            } while( true );

          }

        }

      }

      else {

        iVar4 = (**(code **)(*param_8 + 0x1d4))();

        param_4 = (int *)0x0;

        if (iVar4 != 0) {

          iVar4 = (**(code **)(*param_8 + 0x210))(0);

          param_4 = (int *)0x0;

          if (iVar4 != 0) {

            param_4 = *(int **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c);

            if (((*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2)

                                    + 0x3c) + 0x532) != *(byte *)((int)param_4 + 0x532)) &&

                ((param_1[0x14] & 1 << (*(byte *)((int)param_4 + 0x532) & 0x1f)) != 0)) &&

               (piVar5 = param_4,

               (param_1[0x15] & 1 << (*(byte *)((int)param_4 + 0x531) & 0x1f)) != 0)) {

LAB_0061208e:

              param_4 = piVar5;

              uStack_34 = DAT_00d02ab0;

              uStack_30 = DAT_00d02ab4;

              uStack_2c = DAT_00d02ab8;

              fStack_28 = (float)DAT_00d02abc;

              if (g_flZero < (float)param_1[0x12]) {

                iVar4 = CVOGReaction_RandomUnitScalar();

                if (0xfffff < *(int *)(iVar4 + 0xc)) {

                  *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

                }

                uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

                *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

                param_4 = (int *)(uint)uVar1;

                if ((float)(int)param_4 * DAT_00aaa638 <= (float)param_1[0x12] * DAT_00a0f718) {

                  if ((((uint)param_8[0x5f] >> 5 & 1) == 0) ||

                     (iVar4 = (**(code **)(*param_8 + 0x1c8))(), iVar4 == 0)) {

                    piVar9 = *(int **)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa4 + param_2);

                    if (piVar9 == (int *)0x0) {

                      iVar4 = 0;

                    }

                    else {

                      iVar4 = (**(code **)(*piVar9 + 0x1c8))();

                    }

                    if ((*(char *)(param_2 + 0x6b9) != '\0') && (param_4 = (int *)0x0, iVar4 == 0))

                    goto LAB_00611fe2;

                  }

                  puVar6 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

                  uStack_34 = *puVar6;

                  uStack_30 = puVar6[1];

                  uStack_2c = puVar6[2];

                  fStack_28 = (float)puVar6[3];

                  param_4 = (int *)FUN_00404d70(param_1[4]);

                  if (param_4 != (int *)0x0) {

                    if (((char)param_1[0x13] == '\0') || (*(int *)(param_2 + 0xcb0) == 0)) {

                      pvVar8 = CNDHash_LookupByKey(*(void **)(param_2 + 0x55c),

                                                   *(uint *)(param_1[1] + 0x10));

                      param_4 = (int *)0x0;

                      if ((pvVar8 != (void *)0x0) &&

                         (param_4 = (int *)(**(code **)(*param_1 + 0xc))(param_2,pvVar8),

                         (char)param_4 == '\0')) {

                        piVar9 = (int *)CVOGReaction_GiveItemByCbid(param_1[4]);

                        if (piVar9 == (int *)0x0) {

                          uVar10 = FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",param_1[4]);

                          return uVar10 & 0xffffff00;

                        }

                        (**(code **)(*piVar9 + 8))

                                  (param_1[4],

                                   *(uint32_t /* width from decompiler */ *)

                                    (*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2),1);

                        iVar4 = *(int *)(*(int *)(param_2 + 4) + 4);

                        piVar9[0x5c] = *(int *)(iVar4 + 0x164 + param_2);

                        piVar9[0x5d] = *(int *)(iVar4 + 0x168 + param_2);

                        uVar10 = FUN_004d2820(piVar9,&stack0xffffffb4,0,1);

                        return uVar10 & 0xffffff00;

                      }

                    }

                    else {

                      uVar10 = 0;

                      if (*(char *)(*(int *)(param_2 + 0xcb0) + 0x1d8) != '\0') {

                        do {

                          iVar4 = FUN_00574760(uVar10);

                          if (iVar4 != 0) {

                            pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) +

                                                                            4) + 4 + param_2) +

                                                          0x1a0))();

                            fStack_28 = *pfVar7;

                            fStack_20 = pfVar7[2];

                            pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4

                                                                            ) + 4 + iVar4) + 0x1a0))

                                                        ();

                            if (((SQRT((fStack_20 - pfVar7[2]) * (fStack_20 - pfVar7[2]) +

                                       (fStack_28 - *pfVar7) * (fStack_28 - *pfVar7)) < DAT_00aaa8a8

                                 ) && (pvVar8 = CNDHash_LookupByKey(*(void **)(iVar4 + 0x55c),

                                                                    *(uint *)(param_1[1] + 0x10)),

                                      pvVar8 != (void *)0x0)) &&

                               (cVar3 = (**(code **)(*param_1 + 0xc))(iVar4,pvVar8), cVar3 == '\0'))

                            {

                              piVar9 = (int *)CVOGReaction_GiveItemByCbid(param_1[4]);

                              if (piVar9 == (int *)0x0) {

                                FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",param_1[4]);

                              }

                              else {

                                (**(code **)(*piVar9 + 8))

                                          (param_1[4],

                                           *(uint32_t /* width from decompiler */ *)

                                            (*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2),1

                                          );

                                iVar2 = *(int *)(*(int *)(iVar4 + 4) + 4);

                                piVar9[0x5c] = *(int *)(iVar2 + 0x164 + iVar4);

                                piVar9[0x5d] = *(int *)(iVar2 + 0x168 + iVar4);

                                FUN_004d2820(piVar9,&uStack_38,0,1);

                              }

                            }

                          }

                          uVar10 = uVar10 + 1;

                        } while ((int)uVar10 <

                                 (int)(uint)*(byte *)(*(int *)(param_2 + 0xcb0) + 0x1d8));

                        return uVar10 & 0xffffff00;

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

  }

  else if (((param_4 == (int *)0x1) && (param_4 = *(int **)(param_2 + 0x250), param_4 != (int *)0x0)

           ) && (param_4[0xac] != 0)) {

    iVar4 = FUN_005711c0(param_1[4],0);

    param_4 = (int *)(iVar4 - (int)param_6);

    if (((int)param_5 == param_1[4]) && ((int)param_4 < param_1[5])) {

      return CONCAT31((int3)((uint)param_4 >> 8),1);

    }

  }

LAB_00611fe2:

  return (uint)param_4 & 0xffffff00;

}
