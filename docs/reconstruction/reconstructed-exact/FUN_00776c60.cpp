// =============================================================================
// FUN_00776c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00776c60
// Address:   0x00776c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00776c60 @ 0x00776c60
// Stable ID: aa_00776c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~293 non-empty decompiler lines.
//  - Control keywords: if×41, goto×14, while×13, do×12, return×3, for×2.
//  - Notable callees: FUN_00770440×4, FUN_00774b50×4, free×4, FUN_00774e60×3, FUN_007707d0×2, FUN_00770650, FUN_007717c0, FUN_00774c50.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



int FUN_00776c60(uint32_t /* width from decompiler */ param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint *param_4,int param_5)



{

  int *piVar1;

  uint uVar2;

  code *pcVar3;

  uint uVar4;

  int *piVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  uint local_103c;

  uint local_1038;

  uint local_1034;

  int *local_1030;

  int local_102c;

  code *local_1028;

  uint local_1024;

  int local_1020;

  uint local_101c;

  uint local_1018;

  int local_1014;

  int local_1010;

  uint32_t /* width from decompiler */ local_100c;

  uint32_t /* width from decompiler */ local_1008;

  void *local_1004;

  int aiStack_1000 [4];

  int local_ff0;

  uint32_t /* width from decompiler */ local_fec;

  uint32_t /* width from decompiler */ local_fe8;

  void *local_fe4;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x776c6a;

  iVar8 = *param_2;

  if (iVar8 == 0) {

LAB_00776ca0:

    iVar8 = 2;

  }

  else {

    iVar7 = iVar8 * 0x1c + -0x1c;

    for (uVar4 = *(uint *)(param_2[3] + -4 + iVar8 * 4); uVar4 != 0; uVar4 = uVar4 >> 1) {

      iVar7 = iVar7 + 1;

    }

    if (iVar7 < 8) goto LAB_00776ca0;

    if (iVar7 < 0x25) {

      iVar8 = 3;

    }

    else if (iVar7 < 0x8d) {

      iVar8 = 4;

    }

    else if (iVar7 < 0x1c3) {

      iVar8 = 5;

    }

    else if (iVar7 < 0x518) {

      iVar8 = 6;

    }

    else {

      iVar8 = (0xdc9 < iVar7) + 7;

    }

  }

  local_102c = iVar8;

  iVar7 = FUN_00770440();

  if (iVar7 != 0) {

    return iVar7;

  }

  local_1020 = iVar8 + -1;

  uVar4 = 1 << (sbyte)iVar8;

  iVar8 = 1 << ((byte)local_1020 & 0x1f);

  local_1014 = iVar8;

  local_1018 = uVar4;

  for (; iVar8 < (int)uVar4; iVar8 = iVar8 + 1) {

    iVar7 = FUN_00770440();

    if (iVar7 != 0) {

      if (local_1014 < iVar8) {

        iVar8 = iVar8 - local_1014;

        do {

          FUN_007707d0();

          iVar8 = iVar8 + -1;

        } while (iVar8 != 0);

      }

      FUN_007707d0();

      return iVar7;

    }

  }

  iVar8 = FUN_00770440();

  if (iVar8 != 0) goto LAB_00777224;

  if (param_5 == 0) {

    iVar8 = FUN_00774c50(param_3);

    if (iVar8 == 0) {

      local_1028 = FUN_00775f50;

LAB_00776de5:

      iVar8 = FUN_00774f50(param_1,&local_ff0);

      if (iVar8 == 0) {

        piVar5 = aiStack_1000 + local_1014 * 4;

        iVar8 = FUN_00770650();

        iVar7 = local_1020;

        if (iVar8 == 0) {

          iVar9 = 0;

          if (0 < local_1020) {

            do {

              iVar8 = FUN_00774b50(piVar5,piVar5);

              if ((iVar8 != 0) || (iVar8 = (*local_1028)(piVar5,param_3,&local_1010), iVar8 != 0))

              goto LAB_007771d4;

              iVar9 = iVar9 + 1;

            } while (iVar9 < iVar7);

          }

          iVar7 = local_1014 + 1;

          if (iVar7 < (int)local_1018) {

            piVar5 = aiStack_1000 + iVar7 * 4;

            do {

              iVar8 = FUN_00774e60(piVar5 + -4,&local_ff0,piVar5);

              if ((iVar8 != 0) || (iVar8 = (*local_1028)(piVar5,param_3,&local_1010), iVar8 != 0))

              goto LAB_007771d4;

              iVar7 = iVar7 + 1;

              piVar5 = piVar5 + 4;

            } while (iVar7 < (int)local_1018);

          }

          iVar8 = FUN_00770440();

          if (iVar8 == 0) {

            iVar8 = 0;

            local_1034 = 0;

            piVar5 = local_1030;

            if (0 < (int)local_1038) {

              do {

                *piVar5 = 0;

                iVar8 = iVar8 + 1;

                piVar5 = piVar5 + 1;

              } while (iVar8 < (int)local_1038);

            }

            *local_1030 = 1;

            local_1020 = 1;

            local_103c = (uint)(*local_1030 != 0);

            iVar7 = 0;

            iVar9 = *param_2 + -1;

            uVar4 = 0;

            do {

              iVar10 = 0;

              local_1024 = 0;

LAB_00776f40:

              do {

                pcVar3 = local_1028;

                local_1020 = local_1020 + -1;

                if (local_1020 == 0) {

                  if (iVar9 == -1) {

                    if (((iVar7 != 2) || (iVar10 < 1)) || (iVar7 = 0, iVar10 < 1))

                    goto LAB_00777143;

                    goto LAB_007770b5;

                  }

                  uVar4 = *(uint *)(param_2[3] + iVar9 * 4);

                  iVar9 = iVar9 + -1;

                  local_1020 = 0x1c;

                }

                local_101c = uVar4 * 2;

                uVar6 = uVar4 >> 0x1b & 1;

                uVar4 = local_101c;

                if (iVar7 == 0) {

                  if (uVar6 == 0) goto LAB_00776f40;

                }

                else if ((iVar7 == 1) && (uVar6 == 0)) {

                  iVar8 = FUN_00774b50(&local_103c,&local_103c);

                  if ((iVar8 != 0) ||

                     (iVar8 = (*local_1028)(&local_103c,param_3,&local_1010), uVar4 = local_101c,

                     iVar8 != 0)) goto LAB_00777184;

                  goto LAB_00776f40;

                }

                iVar10 = iVar10 + 1;

                iVar7 = 2;

                local_1024 = local_1024 | uVar6 << ((char)local_102c - (char)iVar10 & 0x1fU);

              } while (iVar10 != local_102c);

              if (0 < local_102c) {

                iVar7 = 0;

                do {

                  iVar8 = FUN_00774b50(&local_103c,&local_103c);

                  if ((iVar8 != 0) ||

                     (iVar8 = (*local_1028)(&local_103c,param_3,&local_1010), iVar8 != 0))

                  goto LAB_00777184;

                  iVar7 = iVar7 + 1;

                } while (iVar7 < local_102c);

              }

              iVar8 = FUN_00774e60(&local_103c,aiStack_1000 + local_1024 * 4,&local_103c);

              if ((iVar8 != 0) ||

                 (iVar8 = (*local_1028)(&local_103c,param_3,&local_1010), iVar8 != 0))

              goto LAB_00777184;

              iVar7 = 1;

              uVar4 = local_101c;

            } while( true );

          }

        }

      }

    }

  }

  else {

    iVar8 = FUN_007717c0(&local_1010);

    if (iVar8 == 0) {

      local_1028 = (code *)&LAB_00775e70;

      goto LAB_00776de5;

    }

  }

LAB_007771d4:

  if (local_1004 != (void *)0x0) {

    iVar7 = 0;

    if (0 < local_1010) {

      do {

        *(uint32_t /* width from decompiler */ *)((int)local_1004 + iVar7 * 4) = 0;

        iVar7 = iVar7 + 1;

      } while (iVar7 < local_1010);

    }

    free(local_1004);

    local_1004 = (void *)0x0;

    local_1010 = 0;

    local_100c = 0;

    local_1008 = 0;

  }

LAB_00777224:

  if (local_fe4 != (void *)0x0) {

    iVar7 = 0;

    if (0 < local_ff0) {

      do {

        *(uint32_t /* width from decompiler */ *)((int)local_fe4 + iVar7 * 4) = 0;

        iVar7 = iVar7 + 1;

      } while (iVar7 < local_ff0);

    }

    free(local_fe4);

    local_fe4 = (void *)0x0;

    local_ff0 = 0;

    local_fec = 0;

    local_fe8 = 0;

  }

  if (local_1014 < (int)local_1018) {

    local_101c = local_1018 - local_1014;

    piVar5 = aiStack_1000 + local_1014 * 4;

    do {

      piVar1 = piVar5 + 3;

      if (piVar5[3] != 0) {

        iVar7 = 0;

        if (0 < *piVar5) {

          do {

            *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar7 * 4) = 0;

            iVar7 = iVar7 + 1;

          } while (iVar7 < *piVar5);

        }

        free((void *)*piVar1);

        *piVar1 = 0;

        *piVar5 = 0;

        piVar5[1] = 0;

        piVar5[2] = 0;

      }

      piVar5 = piVar5 + 4;

      local_101c = local_101c + -1;

    } while (local_101c != 0);

  }

  return iVar8;

  while (iVar7 = iVar7 + 1, iVar7 < iVar10) {

LAB_007770b5:

    iVar8 = FUN_00774b50(&local_103c,&local_103c);

    if (((iVar8 != 0) || (iVar8 = (*pcVar3)(&local_103c,param_3,&local_1010), iVar8 != 0)) ||

       ((local_1024 = local_1024 * 2, (local_1018 & local_1024) != 0 &&

        ((iVar8 = FUN_00774e60(&local_103c,&local_ff0,&local_103c), iVar8 != 0 ||

         (iVar8 = (*pcVar3)(&local_103c,param_3,&local_1010), iVar8 != 0)))))) goto LAB_00777184;

  }

LAB_00777143:

  uVar4 = *param_4;

  uVar6 = param_4[1];

  uVar2 = param_4[2];

  piVar5 = (int *)param_4[3];

  *param_4 = local_103c;

  param_4[1] = local_1038;

  param_4[2] = local_1034;

  param_4[3] = (uint)local_1030;

  iVar8 = 0;

  local_103c = uVar4;

  local_1038 = uVar6;

  local_1034 = uVar2;

  local_1030 = piVar5;

LAB_00777184:

  if (local_1030 != (int *)0x0) {

    iVar7 = 0;

    if (0 < (int)local_103c) {

      do {

        local_1030[iVar7] = 0;

        iVar7 = iVar7 + 1;

      } while (iVar7 < (int)local_103c);

    }

    free(local_1030);

    local_1030 = (int *)0x0;

    local_103c = 0;

    local_1038 = 0;

    local_1034 = 0;

  }

  goto LAB_007771d4;

}
