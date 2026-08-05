// =============================================================================
// FUN_00726850
// -----------------------------------------------------------------------------
// Stable ID: aa_00726850
// Address:   0x00726850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00726850 @ 0x00726850
// Stable ID: aa_00726850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~185 non-empty decompiler lines.
//  - Control keywords: if×25, goto×13, return×4, do×3, while×3.
//  - Notable callees: CONCAT31×4, LeaveCriticalSection×4, FUN_004801a0×3, FUN_007227e0×2, EnterCriticalSection, FUN_004801d0, FUN_0071f8a0, FUN_0071fc20.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_00726850(byte *param_1,int param_2)



{

  LPCRITICAL_SECTION lpCriticalSection;

  byte bVar1;

  byte bVar2;

  uint8_t uVar3;

  char cVar4;

  int iVar5;

  byte *pbVar6;

  int iVar7;

  int *piVar8;

  byte *pbVar9;

  byte *pbVar10;

  bool bVar11;

  float10 fVar12;

  float fVar13;

  float fVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint32_t /* width from decompiler */ uVar16;

  int local_2c;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009b172b;

  local_1c = ExceptionList;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_2 + 0x3f8);

  ExceptionList = &local_1c;

  EnterCriticalSection(lpCriticalSection);

  local_14 = 0;

  bVar1 = 0;

  local_2c = 0;

  if (0 < *(int *)(param_2 + 0x210)) {

    piVar8 = (int *)(param_2 + 0x31c);

    do {

      if (*piVar8 != 0) {

        if (*(byte *)(param_2 + 0x2e5) < bVar1) goto LAB_00726cda;

        iVar5 = _stricmp((char *)param_1,(char *)(*piVar8 + 0x48));

        iVar7 = *piVar8;

        fVar14 = *(float *)(iVar7 + 0x150) - *(float *)(param_1 + 0x140);

        fVar13 = *(float *)(iVar7 + 0x158) - *(float *)(param_1 + 0x148);

        fVar13 = fVar13 * fVar13 + fVar14 * fVar14;

        if (iVar5 == 0) {

          if ((((*(uint *)(param_1 + 0x120) & *(uint *)(param_1 + 0x124)) == 0xffffffff) &&

              (fVar13 < DAT_00aaa664)) &&

             ((*(char *)(iVar7 + 0x1c5) != '\0' || (*(char *)(iVar7 + 0x3a) != '\0'))))

          goto LAB_00726cda;

          if ((*(int *)(param_1 + 0x104) == 0x28) || (*(int *)(param_1 + 0x104) == 0x32))

          goto LAB_00726963;

LAB_00726987:

          iVar7 = *piVar8;

          if ((*(char *)(iVar7 + 0x1c5) != '\0') || (*(char *)(iVar7 + 0x3a) != '\0')) {

            if ((iVar5 != 0) ||

               (*(float *)(param_2 + 0x2e0) * *(float *)(param_2 + 0x2e0) <= fVar13)) {

              bVar1 = bVar1 + 1;

              goto LAB_00726aa8;

            }

            goto LAB_00726cda;

          }

        }

        else {

LAB_00726963:

          iVar7 = *piVar8;

          if (((*(uint *)(iVar7 + 0x40) & *(uint *)(iVar7 + 0x44)) != 0xffffffff) &&

             ((*(uint *)(iVar7 + 0x40) == *(uint *)(param_1 + 0x120) &&

              (*(uint *)(iVar7 + 0x44) == *(uint *)(param_1 + 0x124))))) goto LAB_00726987;

        }

        if (((*(uint *)(iVar7 + 0x40) == *(uint *)(param_1 + 0x120)) &&

            (*(uint *)(iVar7 + 0x44) == *(uint *)(param_1 + 0x124))) &&

           ((*(uint *)(param_1 + 0x120) & *(uint *)(param_1 + 0x124)) != 0xffffffff)) {

          pbVar10 = (byte *)(iVar7 + 0x48);

          pbVar6 = param_1;

          pbVar9 = pbVar10;

          do {

            bVar2 = *pbVar6;

            bVar11 = bVar2 < *pbVar9;

            if (bVar2 != *pbVar9) {

LAB_00726a1b:

              iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);

              goto LAB_00726a20;

            }

            if (bVar2 == 0) break;

            bVar2 = pbVar6[1];

            bVar11 = bVar2 < pbVar9[1];

            if (bVar2 != pbVar9[1]) goto LAB_00726a1b;

            pbVar6 = pbVar6 + 2;

            pbVar9 = pbVar9 + 2;

          } while (bVar2 != 0);

          iVar5 = 0;

LAB_00726a20:

          if (iVar5 == 0) {

            if (*(char *)(iVar7 + 0x1c5) == '\0') {

              pbVar6 = param_1;

              if (*(char *)(iVar7 + 0x36) != '\0') {

                uVar3 = *(uint8_t *)(*(int *)(param_2 + 0x31c + local_2c * 4) + 0x36);

                uVar16 = 0;

                uVar15 = 0xffffffff;

                fVar12 = (float10)FUN_007227e0(0);

                iVar7 = FUN_0071fc20(0,uVar3,(int)ROUND(fVar12),uVar15,uVar16);

                if (-1 < iVar7) {

                  FUN_004801a0(param_1 + 0x140);

                  LeaveCriticalSection(lpCriticalSection);

                  ExceptionList = local_1c;

                  return 1;

                }

                goto LAB_00726cda;

              }

              do {

                bVar2 = *pbVar6;

                bVar11 = bVar2 < *pbVar10;

                if (bVar2 != *pbVar10) {

LAB_00726a94:

                  iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);

                  goto LAB_00726a99;

                }

                if (bVar2 == 0) break;

                bVar2 = pbVar6[1];

                bVar11 = bVar2 < pbVar10[1];

                if (bVar2 != pbVar10[1]) goto LAB_00726a94;

                pbVar10 = pbVar10 + 2;

                pbVar6 = pbVar6 + 2;

              } while (bVar2 != 0);

              iVar7 = 0;

LAB_00726a99:

              if (iVar7 == 0) {

                iVar7 = FUN_00724570(*(uint32_t /* width from decompiler */ *)(param_1 + 0x120),

                                     *(uint32_t /* width from decompiler */ *)(param_1 + 0x124),

                                     CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x110) >> 8),

                                              param_1[0x128]),

                                     CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x114) >> 8),

                                              param_1[0x10b]),*(uint32_t /* width from decompiler */ *)(param_1 + 0x118),

                                     *(uint32_t /* width from decompiler */ *)(param_1 + 0x110),

                                     *(uint32_t /* width from decompiler */ *)(param_1 + 0x114));

                if (-1 < iVar7) {

                  FUN_004801a0(param_1 + 0x140);

                  LeaveCriticalSection(lpCriticalSection);

                  ExceptionList = local_1c;

                  return 1;

                }

                goto LAB_00726cda;

              }

            }

            else if (((*(char *)(iVar7 + 0x36) == '\0') || (*(int *)(param_1 + 0x104) == 10)) &&

                    ((iVar7 = FUN_0071f8a0(0), iVar7 != 0 &&

                     (cVar4 = FUN_007239b0(param_2), cVar4 != '\0')))) {

              if (*(char *)(*(int *)(param_2 + 0x31c + local_2c * 4) + 0x36) != '\0') {

                fVar12 = (float10)FUN_007227e0(0);

                FUN_004801d0((float)fVar12);

              }

              FUN_004801a0(param_1 + 0x140);

              *(uint8_t *)(*(int *)(param_2 + 0x31c + local_2c * 4) + 0x3a) = 1;

              iVar7 = *(int *)(param_2 + 0x31c + local_2c * 4);

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x120);

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x124);

              goto LAB_00726ba2;

            }

          }

        }

      }

LAB_00726aa8:

      local_2c = local_2c + 1;

      piVar8 = piVar8 + 1;

    } while (local_2c < *(int *)(param_2 + 0x210));

  }

  iVar7 = FUN_00723f70(param_1 + 0x140,*(uint32_t /* width from decompiler */ *)(param_1 + 0x104));

  if ((iVar7 == -1) ||

     (iVar7 = FUN_00726390(param_2,param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x120),

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x124),param_1[0x128],param_1 + 0x140,iVar7,

                           CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x104) >> 8),

                                    param_1[0x10b]),

                           CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x118) >> 8),

                                    param_1[0x131]),*(uint32_t /* width from decompiler */ *)(param_1 + 0x104),

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x118),*(uint32_t /* width from decompiler */ *)(param_1 + 0x154),

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x110),*(uint32_t /* width from decompiler */ *)(param_1 + 0x11c),

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x114)), iVar7 < 0)) {

LAB_00726cda:

    LeaveCriticalSection(lpCriticalSection);

    ExceptionList = local_1c;

    return 0;

  }

LAB_00726ba2:

  LeaveCriticalSection(lpCriticalSection);

  ExceptionList = local_1c;

  return 1;

}
