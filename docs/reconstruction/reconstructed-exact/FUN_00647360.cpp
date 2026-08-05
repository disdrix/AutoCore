// =============================================================================
// FUN_00647360
// -----------------------------------------------------------------------------
// Stable ID: aa_00647360
// Address:   0x00647360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00647360 @ 0x00647360
// Stable ID: aa_00647360
// Embedded strings (evidence for future rename):
//   - "numelements"
//   - "broadPhaseType"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~284 non-empty decompiler lines.
//  - Control keywords: if×47, goto×8, while×4, return×3, do×3.
//  - Notable callees: FUN_0065a230×7, FUN_005b3300×6, FUN_00647360×3, FUN_00651d50×3, FUN_00659d40×3, FUN_0065a140×3, atoi×3, FUN_005f3120×2.
//  - Strings: "numelements"; "broadPhaseType".
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

uint32_t /* width from decompiler */

FUN_00647360(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  short sVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *pcVar7;

  int iVar8;

  uint uVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int *piVar12;

  int local_34;

  uint32_t /* width from decompiler */ *local_30;

  uint32_t /* width from decompiler */ *local_2c;

  int local_28;

  uint32_t /* width from decompiler */ *local_24;

  uint32_t /* width from decompiler */ *local_20;

  int local_1c;

  

  iVar4 = FUN_0065a230(&local_2c);

  if (iVar4 != 0) {

    return 1;

  }

LAB_00647380:

  if ((~-(uint)(local_2c[2] != 1) & (uint)local_2c) == 0) {

    puVar6 = (uint32_t /* width from decompiler */ *)((local_2c[2] != 2) - 1 & (uint)local_2c);

    if ((puVar6 != (uint32_t /* width from decompiler */ *)0x0) &&

       (iVar4 = FUN_00637f70(puVar6[3],*(uint32_t /* width from decompiler */ *)(param_3 + 0xc)), iVar4 == 0)) {

      (**(code **)*puVar6)(1);

      return 1;

    }

    goto LAB_0064794a;

  }

  uVar5 = FUN_00659d40(&DAT_009e46fc,0);

  puVar6 = (uint32_t /* width from decompiler */ *)FUN_006324e0(uVar5);

  local_20 = puVar6;

  if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

    sVar2 = *(short *)(puVar6 + 2);

    piVar12 = (int *)((uint)*(ushort *)((int)puVar6 + 0xe) + param_2);

    if (sVar2 == 0x13) {

      iVar4 = FUN_00651d30();

      if (iVar4 == 0x15) {

        pcVar7 = (char *)FUN_00659d40("numelements",&DAT_00a32460);

        iVar8 = atoi(pcVar7);

        local_24 = (uint32_t /* width from decompiler */ *)FUN_00651db0();

        iVar4 = piVar12[2];

        iVar8 = (int)local_24 * iVar8;

        piVar12[2] = iVar4 * (int)local_24;

        uVar9 = iVar4 * (int)local_24 & 0x7fffffff;

        piVar12[1] = 0;

        if ((int)uVar9 < iVar8) {

          iVar4 = uVar9 * 2;

          if (iVar8 < iVar4) {

            iVar8 = iVar4;

          }

          FUN_005b3300(piVar12,iVar8,1);

        }

        local_28 = 0;

        puVar6 = local_24;

        do {

          local_30 = (uint32_t /* width from decompiler */ *)0x0;

          FUN_0065a230(&local_30);

          iVar4 = local_30[2];

          uVar9 = ~-(uint)(iVar4 != 1) & (uint)local_30;

          if (uVar9 == 0) {

            puVar11 = (uint32_t /* width from decompiler */ *)((iVar4 != 2) - 1 & (uint)local_30);

            if (puVar11 != (uint32_t /* width from decompiler */ *)0x0) goto LAB_00647541;

            uVar9 = (iVar4 != 3) - 1 & (uint)local_30;

            if (uVar9 != 0) {

              FUN_0065a140(CONCAT31((int3)(uVar9 >> 8),1));

            }

          }

          else {

            if ((int)(piVar12[2] & 0x7fffffffU) < (int)puVar6) {

              puVar11 = (uint32_t /* width from decompiler */ *)((piVar12[2] & 0x7fffffffU) * 2);

              if ((int)puVar11 <= (int)puVar6) {

                puVar11 = puVar6;

              }

              FUN_005b3300(piVar12,puVar11,1);

            }

            uVar5 = FUN_00651d50(local_28 + *piVar12,uVar9,param_4,param_5);

            cVar3 = FUN_00647360(uVar5);

            if (cVar3 != '\0') {

              if ((int)(piVar12[2] & 0x7fffffffU) < (int)puVar6) {

                puVar11 = (uint32_t /* width from decompiler */ *)((piVar12[2] & 0x7fffffffU) * 2);

                if ((int)puVar11 <= (int)puVar6) {

                  puVar11 = puVar6;

                }

                FUN_005b3300(piVar12,puVar11,1);

              }

              piVar12[1] = (int)puVar6;

            }

          }

          if (local_30 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*local_30)(1);

          }

          local_28 = local_28 + (int)local_24;

          puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + (int)local_24);

        } while( true );

      }

      local_30 = (uint32_t /* width from decompiler */ *)0x0;

      FUN_0065a230(&local_30);

      uVar9 = (local_30[2] != 3) - 1 & (uint)local_30;

      FUN_0065a140(1);

      pcVar7 = (char *)FUN_00659d40("numelements",&DAT_00a32460);

      iVar8 = atoi(pcVar7);

      iVar4 = *(int *)(uVar9 + 0xc);

      FUN_005f3120(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + -0xc));

      iVar10 = FUN_00651db0();

      iVar4 = piVar12[2];

      iVar8 = iVar10 * iVar8;

      piVar12[2] = iVar4 * iVar10;

      uVar9 = iVar4 * iVar10 & 0x7fffffff;

      piVar12[1] = 0;

      if ((int)uVar9 < iVar8) {

        iVar4 = uVar9 * 2;

        if (iVar8 < iVar4) {

          iVar8 = iVar4;

        }

        FUN_005b3300(piVar12,iVar8,1);

      }

      local_24 = (uint32_t /* width from decompiler */ *)0x0;

      local_28 = iVar10;

      while( true ) {

        if ((int)(piVar12[2] & 0x7fffffffU) < local_28) {

          iVar4 = (piVar12[2] & 0x7fffffffU) * 2;

          if (iVar4 <= local_28) {

            iVar4 = local_28;

          }

          FUN_005b3300(piVar12,iVar4,1);

        }

        local_1c = *piVar12 + (int)local_24;

        FUN_00651d30();

        iVar8 = FUN_00646df0();

        iVar4 = local_28;

        if (iVar8 != 0) break;

        if ((int)(piVar12[2] & 0x7fffffffU) < local_28) {

          iVar8 = (piVar12[2] & 0x7fffffffU) * 2;

          if (iVar8 <= local_28) {

            iVar8 = local_28;

          }

          FUN_005b3300(piVar12,iVar8,1);

        }

        local_24 = (uint32_t /* width from decompiler */ *)((int)local_24 + iVar10);

        piVar12[1] = iVar4;

        local_28 = iVar4 + iVar10;

      }

      piVar12[1] = piVar12[1] / iVar10;

      piVar12[2] = piVar12[2] / iVar10;

      if (local_30 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*local_30)(1);

      }

      FUN_005f3160();

    }

    else if (sVar2 == 0x15) {

      puVar11 = (uint32_t /* width from decompiler */ *)FUN_00651d40();

      puVar6 = puVar11;

      if (puVar11 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar6 = (uint32_t /* width from decompiler */ *)0x1;

      }

      if (puVar11 < (uint32_t /* width from decompiler */ *)0x80000000) {

        do {

          local_20 = puVar6;

          local_24 = (uint32_t /* width from decompiler */ *)0x0;

          FUN_0065a230(&local_24);

          uVar5 = FUN_00651d50(piVar12,~-(uint)(local_24[2] != 1) & (uint)local_24,param_4,param_5);

          FUN_00647360(uVar5);

          if (local_24 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*local_24)(1);

          }

          puVar6 = (uint32_t /* width from decompiler */ *)((int)local_20 - 1U);

        } while ((uint32_t /* width from decompiler */ *)((int)local_20 - 1U) != (uint32_t /* width from decompiler */ *)0x0);

        local_20 = (uint32_t /* width from decompiler */ *)0x0;

      }

    }

    else if (sVar2 == 0x14) {

      local_20 = (uint32_t /* width from decompiler */ *)0x0;

      FUN_0065a230(&local_20);

      puVar11 = (uint32_t /* width from decompiler */ *)((local_20[2] != 3) - 1 & (uint)local_20);

      FUN_00651d50();

      local_34 = 0;

      pcVar7 = (char *)puVar11[3];

      if ((*pcVar7 < '0') || ('9' < *pcVar7)) {

        iVar4 = FUN_0065ac40(pcVar7,&local_34);

        if (iVar4 == 0) goto LAB_006477bc;

      }

      else {

        local_34 = atoi(pcVar7);

        iVar4 = FUN_00637f70(*puVar6,"broadPhaseType");

        if (iVar4 == 0) {

          local_34 = local_34 + 1;

        }

LAB_006477bc:

        iVar4 = FUN_00651d60();

        if (iVar4 != 1) {

          if (iVar4 == 2) {

            *(uint16_t *)piVar12 = (uint16_t)local_34;

            (**(code **)*puVar11)(1);

          }

          else {

            if (iVar4 != 4) goto LAB_00647800;

            *piVar12 = local_34;

            (**(code **)*puVar11)(1);

          }

          goto LAB_0064794a;

        }

        *(uint8_t *)piVar12 = (uint8_t)local_34;

      }

LAB_00647800:

      (**(code **)*puVar11)(1);

    }

    else {

      local_30 = (uint32_t /* width from decompiler */ *)0x0;

      FUN_0065a230(&local_30);

      uVar9 = (local_30[2] != 3) - 1 & (uint)local_30;

      if (uVar9 == 0) {

        if ((((uint)local_30 & (local_30[2] != 2) - 1) != 0) && (*(short *)(puVar6 + 2) == 0x11)) {

          piVar1 = (int *)(*piVar12 + -4);

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            FUN_00638180();

          }

          DAT_00d02c6c = DAT_00d02c6c + 1;

          *piVar12 = (int)&DAT_00d02c70;

        }

      }

      else if (*(short *)(puVar6 + 2) == 0x11) {

        iVar4 = *(int *)(uVar9 + 0xc);

        piVar1 = (int *)(iVar4 + -4);

        *piVar1 = *piVar1 + 1;

        piVar1 = (int *)(*piVar12 + -4);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          FUN_00638180();

        }

        *piVar12 = iVar4;

      }

      else {

        FUN_0065a140(1);

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_00651d40();

        if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

          puVar6 = (uint32_t /* width from decompiler */ *)0x1;

        }

        local_1c = FUN_00651d60();

        local_1c = local_1c / (int)puVar6;

        FUN_005f3120(*(int *)(uVar9 + 0xc),*(uint32_t /* width from decompiler */ *)(*(int *)(uVar9 + 0xc) + -0xc));

        if (0 < (int)puVar6) {

          do {

            local_20 = puVar6;

            FUN_00646df0();

            local_20 = (uint32_t /* width from decompiler */ *)((int)local_20 + -1);

            puVar6 = local_20;

          } while (local_20 != (uint32_t /* width from decompiler */ *)0x0);

        }

        FUN_005f3160();

      }

      if (local_30 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*local_30)(1);

      }

    }

    goto LAB_0064794a;

  }

  if (local_2c != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*local_2c)(1);

  }

  goto LAB_00647958;

LAB_00647541:

  (**(code **)*puVar11)(1);

  piVar12[1] = piVar12[1] / (int)local_24;

  piVar12[2] = piVar12[2] / (int)local_24;

LAB_0064794a:

  if (local_2c != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*local_2c)(1);

  }

LAB_00647958:

  iVar4 = FUN_0065a230(&local_2c);

  if (iVar4 != 0) {

    return 1;

  }

  goto LAB_00647380;

}
