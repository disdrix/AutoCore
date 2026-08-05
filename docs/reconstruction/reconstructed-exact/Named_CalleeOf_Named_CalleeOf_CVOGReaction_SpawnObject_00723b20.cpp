// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_00723b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00723b20
// Callee of Named_CalleeOf_CVOGReaction_SpawnObject (+1 other named callers)
// Address:   0x00723b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGReaction_SpawnObject (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: if×27, goto×10, do×8, while×8, return×2.
//  - Notable callees: FUN_00723ab0×3, FUN_00723b20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_SpawnObject (+1 other named callers)
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

uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_00723b20(int param_1,uint param_2,uint param_3,char param_4,byte *param_5,char param_6)



{

  byte bVar1;

  uint16_t *puVar2;

  byte *pbVar3;

  int iVar4;

  byte *pbVar5;

  int iVar6;

  int *piVar7;

  byte *pbVar8;

  uint16_t *puVar9;

  bool bVar10;

  uint8_t local_108 [4];

  byte local_104 [260];

  

  if (*(char *)(param_1 + 600) != '\0') {

    if ((param_2 & param_3) == 0xffffffff) {

      if ((param_5 != (byte *)0x0) && (iVar6 = 0, 0 < *(int *)(param_1 + 0x210))) {

        piVar7 = (int *)(param_1 + 0x31c);

        do {

          iVar4 = *piVar7;

          if (((iVar4 != 0) && (*(char *)(iVar4 + 0x1c5) != '\0')) &&

             ((*(char *)(iVar4 + 0x36) != '\0' || (param_6 != '\0')))) {

            pbVar3 = (byte *)(iVar4 + 0x48);

            pbVar8 = param_5;

            do {

              bVar1 = *pbVar3;

              bVar10 = bVar1 < *pbVar8;

              if (bVar1 != *pbVar8) {

LAB_00723d84:

                iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);

                goto LAB_00723d89;

              }

              if (bVar1 == 0) break;

              bVar1 = pbVar3[1];

              bVar10 = bVar1 < pbVar8[1];

              if (bVar1 != pbVar8[1]) goto LAB_00723d84;

              pbVar3 = pbVar3 + 2;

              pbVar8 = pbVar8 + 2;

            } while (bVar1 != 0);

            iVar4 = 0;

LAB_00723d89:

            if (iVar4 == 0) {

              FUN_00723ab0();

            }

          }

          iVar6 = iVar6 + 1;

          piVar7 = piVar7 + 1;

        } while (iVar6 < *(int *)(param_1 + 0x210));

      }

    }

    else {

      iVar6 = 0;

      if (0 < *(int *)(param_1 + 0x210)) {

        local_108 = (uint8_t  [4])(param_1 + 0x31c);

        do {

          iVar4 = *(int *)local_108;

          if ((iVar4 != 0) &&

             ((((*(char *)(iVar4 + 0x1c5) != '\0' || (*(char *)(iVar4 + 0x3a) != '\0')) &&

               (param_2 == *(uint *)(iVar4 + 0x40))) &&

              ((param_3 == *(uint *)(iVar4 + 0x44) && (param_4 == *(char *)(iVar4 + 0x35))))))) {

            if (param_5 == (byte *)0x0) {

              if ((*(char *)(iVar4 + 0x36) != '\0') && (*(int *)(iVar4 + 0x2c) != 0x46))

              goto LAB_00723ce7;

            }

            else {

              pbVar3 = (byte *)(iVar4 + 0x48);

              pbVar8 = param_5;

              do {

                bVar1 = *pbVar3;

                bVar10 = bVar1 < *pbVar8;

                if (bVar1 != *pbVar8) {

LAB_00723bf9:

                  iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);

                  goto LAB_00723bfe;

                }

                if (bVar1 == 0) break;

                bVar1 = pbVar3[1];

                bVar10 = bVar1 < pbVar8[1];

                if (bVar1 != pbVar8[1]) goto LAB_00723bf9;

                pbVar3 = pbVar3 + 2;

                pbVar8 = pbVar8 + 2;

              } while (bVar1 != 0);

              iVar4 = 0;

LAB_00723bfe:

              if (iVar4 == 0) {

                FUN_00723ab0();

              }

              iVar4 = *(int *)local_108;

              if (*(char *)(iVar4 + 0x37) != '\0') {

                pbVar8 = param_5;

                do {

                  bVar1 = *pbVar8;

                  pbVar8[(int)(local_104 + -(int)param_5)] = bVar1;

                  pbVar8 = pbVar8 + 1;

                } while (bVar1 != 0);

                if (*(char *)(param_1 + 0x25a) == '\0') {

                  puVar2 = (uint16_t *)(local_108 + 3);

                  do {

                    puVar9 = puVar2;

                    puVar2 = (uint16_t *)((int)puVar9 + 1);

                  } while (*(char *)((int)puVar9 + 1) != '\0');

                  *(uint16_t *)((int)puVar9 + 1) = DAT_00aa9268;

                  *(uint8_t *)((int)puVar9 + 3) = DAT_00aa926a;

                }

                pbVar8 = (byte *)(iVar4 + 0x48);

                pbVar3 = local_104;

                pbVar5 = pbVar8;

                do {

                  bVar1 = *pbVar5;

                  bVar10 = bVar1 < *pbVar3;

                  if (bVar1 != *pbVar3) {

LAB_00723c94:

                    iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);

                    goto LAB_00723c99;

                  }

                  if (bVar1 == 0) break;

                  bVar1 = pbVar5[1];

                  bVar10 = bVar1 < pbVar3[1];

                  if (bVar1 != pbVar3[1]) goto LAB_00723c94;

                  pbVar5 = pbVar5 + 2;

                  pbVar3 = pbVar3 + 2;

                } while (bVar1 != 0);

                iVar4 = 0;

LAB_00723c99:

                pbVar3 = param_5;

                if (iVar4 != 0) {

                  do {

                    bVar1 = *pbVar8;

                    bVar10 = bVar1 < *pbVar3;

                    if (bVar1 != *pbVar3) {

LAB_00723cca:

                      iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);

                      goto LAB_00723ccf;

                    }

                    if (bVar1 == 0) break;

                    bVar1 = pbVar8[1];

                    bVar10 = bVar1 < pbVar3[1];

                    if (bVar1 != pbVar3[1]) goto LAB_00723cca;

                    pbVar8 = pbVar8 + 2;

                    pbVar3 = pbVar3 + 2;

                  } while (bVar1 != 0);

                  iVar4 = 0;

LAB_00723ccf:

                  if (iVar4 != 0) goto LAB_00723cf2;

                }

LAB_00723ce7:

                FUN_00723ab0();

              }

            }

          }

LAB_00723cf2:

          local_108 = (uint8_t  [4])((int)local_108 + 4);

          iVar6 = iVar6 + 1;

          if (*(int *)(param_1 + 0x210) <= iVar6) {

            return 0;

          }

        } while( true );

      }

    }

  }

  return 0;

}
