// =============================================================================
// Named_CalleeOf_Client_RecvDestroyObject_007a6de0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a6de0
// Callee of Client_RecvDestroyObject (+42 other named callers)
// Address:   0x007a6de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvDestroyObject: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvDestroyObject (+42 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~190 non-empty decompiler lines.
//  - Control keywords: if×15, do×12, while×12, for×4, goto×3, return×2, switch×1.
//  - Notable callees: FUN_007a62c0×2, FUN_007a6310, FUN_007a6410, FUN_007a6490, FUN_007a6610, FUN_007a6de0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvDestroyObject (+42 other named callers)
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

byte * __thiscall Named_CalleeOf_Client_RecvDestroyObject_007a6de0(int param_1,byte *param_2,int param_3)



{

  char *pcVar1;

  byte bVar2;

  int iVar3;

  uint16_t *puVar4;

  byte *pbVar5;

  int iVar6;

  void *pvVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  uint uVar11;

  uint uVar12;

  byte *pbVar13;

  int iVar14;

  int iVar15;

  uint16_t *puVar16;

  uint32_t /* width from decompiler */ *puVar17;

  bool bVar18;

  int local_8 [2];

  

  if ((param_2 != (byte *)0x0) && (*param_2 != 0)) {

    pbVar13 = &DAT_00a32460;

    pbVar5 = param_2;

    do {

      bVar2 = *pbVar5;

      bVar18 = bVar2 < *pbVar13;

      if (bVar2 != *pbVar13) {

LAB_007a6e2c:

        iVar6 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);

        goto LAB_007a6e31;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar5[1];

      bVar18 = bVar2 < pbVar13[1];

      if (bVar2 != pbVar13[1]) goto LAB_007a6e2c;

      pbVar5 = pbVar5 + 2;

      pbVar13 = pbVar13 + 2;

    } while (bVar2 != 0);

    iVar6 = 0;

LAB_007a6e31:

    if (iVar6 != 0) {

      iVar6 = param_3;

      if (param_3 == -1) {

        iVar6 = *(int *)(param_1 + 0x2c);

      }

      local_8[0] = param_1;

      switch(iVar6) {

      case 0:

        FUN_007a62c0();

        pbVar5 = *(byte **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);

        do {

          bVar2 = *param_2;

          *pbVar5 = bVar2;

          param_2 = param_2 + 1;

          pbVar5 = pbVar5 + 1;

        } while (bVar2 != 0);

        break;

      case 1:

      case 2:

      case 3:

        puVar17 = &param_3;

        piVar10 = local_8;

        FUN_007a6490(piVar10,puVar17);

        FUN_007a6410(piVar10,puVar17);

        if (param_3 == -1) {

          FUN_007a62c0();

          pbVar5 = *(byte **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);

          do {

            bVar2 = *param_2;

            *pbVar5 = bVar2;

            param_2 = param_2 + 1;

            pbVar5 = pbVar5 + 1;

          } while (bVar2 != 0);

        }

        else {

          FUN_007a6310(iVar6,local_8[0]);

          FUN_007a6610();

        }

        break;

      case 4:

        iVar14 = 0;

        iVar6 = 0;

        pbVar5 = param_2;

        do {

          bVar2 = *pbVar5;

          pbVar5 = pbVar5 + 1;

        } while (bVar2 != 0);

        iVar3 = ((int)pbVar5 - (int)(param_2 + 1)) * 2;

        if (*(int *)(param_1 + 0x6c + *(int *)(param_1 + 0xc0) * 4) < iVar3) {

          operator_delete__(*(void **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4));

          *(int *)(param_1 + 0x6c + *(int *)(param_1 + 0xc0) * 4) = iVar3;

          pvVar7 = operator_new__(*(uint *)(param_1 + 0x6c + *(int *)(param_1 + 0xc0) * 4));

          *(void **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4) = pvVar7;

        }

        uVar12 = *(uint *)(param_1 + 0x6c + *(int *)(param_1 + 0xc0) * 4);

        puVar17 = *(uint32_t /* width from decompiler */ **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);

        for (uVar11 = uVar12 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

          *puVar17 = 0;

          puVar17 = puVar17 + 1;

        }

        for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

          *(uint8_t *)puVar17 = 0;

          puVar17 = (uint32_t /* width from decompiler */ *)((int)puVar17 + 1);

        }

        pbVar5 = param_2;

        do {

          bVar2 = *pbVar5;

          pbVar5 = pbVar5 + 1;

        } while (bVar2 != 0);

        iVar8 = (int)pbVar5 - (int)(param_2 + 1);

        iVar3 = *(int *)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);

        param_1 = local_8[0];

        if (0 < iVar8) {

          do {

            if (param_2[iVar14] == 0x20) {

              *(uint8_t *)(iVar6 + iVar3) = 0x20;

              iVar6 = iVar6 + 1;

              iVar15 = iVar14 + 1;

            }

            else {

              iVar9 = 0;

              do {

                if ((int)(char)param_2[iVar14] == (&DAT_00a96fa0)[iVar9]) break;

                iVar9 = iVar9 + 1;

              } while (iVar9 < 6);

              iVar15 = iVar14;

              if (iVar9 == 6) {

                iVar9 = 0;

                do {

                  piVar10 = &DAT_00a96fa0;

                  do {

                    if ((int)(char)param_2[iVar15] == *piVar10) goto joined_r0x007a7000;

                    piVar10 = piVar10 + 1;

                  } while ((int)piVar10 < 0xa96fb4);

                  iVar15 = iVar15 + 1;

                  iVar9 = iVar9 + 1;

                } while (iVar15 != iVar8);

joined_r0x007a7000:

                for (; (iVar15 < iVar8 && (param_2[iVar15] != 0x20)); iVar15 = iVar15 + 1) {

                  *(byte *)(iVar6 + iVar3) = param_2[iVar15];

                  iVar6 = iVar6 + 1;

                }

                if (0 < iVar9) {

                  pbVar5 = param_2 + iVar14;

                  do {

                    *(byte *)(iVar6 + iVar3) = *pbVar5;

                    iVar6 = iVar6 + 1;

                    pbVar5 = pbVar5 + 1;

                    iVar9 = iVar9 + -1;

                  } while (iVar9 != 0);

                }

                puVar4 = (uint16_t *)(iVar3 + -1);

                do {

                  puVar16 = puVar4;

                  puVar4 = (uint16_t *)((int)puVar16 + 1);

                } while (*(char *)((int)puVar16 + 1) != '\0');

                *(uint16_t *)((int)puVar16 + 1) = DAT_00a96f9c;

                *(uint8_t *)((int)puVar16 + 3) = DAT_00a96f9e;

                iVar6 = iVar6 + 2;

              }

              else {

                for (; (iVar15 < iVar8 && (param_2[iVar15] != 0x20)); iVar15 = iVar15 + 1) {

                  *(byte *)(iVar6 + iVar3) = param_2[iVar15];

                  iVar6 = iVar6 + 1;

                }

                puVar17 = (uint32_t /* width from decompiler */ *)(iVar3 + -1);

                do {

                  pcVar1 = (char *)((int)puVar17 + 1);

                  puVar17 = (uint32_t /* width from decompiler */ *)((int)puVar17 + 1);

                } while (*pcVar1 != '\0');

                *puVar17 = DAT_00a800e4;

                iVar6 = iVar6 + 3;

              }

            }

            iVar14 = iVar15;

          } while (iVar15 < iVar8);

        }

      }

      iVar14 = *(int *)(param_1 + 0xc0);

      iVar6 = iVar14 + 1;

      *(int *)(param_1 + 0xc0) = iVar6;

      if (iVar6 == 10) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = 0;

      }

      return *(byte **)(param_1 + 4 + iVar14 * 4);

    }

  }

  return param_2;

}
