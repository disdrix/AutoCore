// =============================================================================
// FUN_00919ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00919ff0
// Address:   0x00919ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00919ff0 @ 0x00919ff0
// Stable ID: aa_00919ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×14, do×3, while×3, return×1.
//  - Notable callees: FUN_005070b0×3, FUN_005070d0×3, FUN_00919ff0.
//  - Return sites: 1.

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

void FUN_00919ff0(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *pcVar7;

  int *piVar8;

  int *piVar9;

  uint8_t auStack_59 [2];

  uint8_t uStack_57;

  uint8_t auStack_56 [2];

  int *local_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  piVar9 = *(int **)(*(int *)(DAT_00d1b644 + 0xe4a4) + 8);

  if (piVar9 != piVar9 + *(int *)(*(int *)(DAT_00d1b644 + 0xe4a4) + 0xc)) {

    do {

      piVar8 = *(int **)(*piVar9 + 0x3c);

      local_54 = piVar9;

      if (piVar8 != piVar8 + *(int *)(*piVar9 + 0x40)) {

        do {

          iVar5 = *(int *)(*piVar8 + 0x34);

          iVar3 = 0;

          if (0 < iVar5) {

            piVar1 = *(int **)(*piVar8 + 0x30);

            piVar4 = piVar1;

            do {

              if (*piVar4 == 1) {

                piVar1 = (int *)piVar1[iVar3 * 2 + 1];

                if (((piVar1 != (int *)0x0) && (((uint)piVar1[0x5f] >> 6 & 1) != 0)) &&

                   (((uint)piVar1[0x5f] >> 5 & 1) != 0)) {

                  piVar4 = (int *)(**(code **)(*piVar1 + 0x1d0))();

                  (**(code **)(*piVar4 + 0x44))();

                  if ((piVar1[5] != 0) &&

                     ((*(int *)(piVar1[0x2a] + 0x38) == 3 ||

                      ((iVar5 = (**(code **)(*piVar1 + 0x1d4))(), iVar5 != 0 &&

                       (iVar5 = (**(code **)(*piVar1 + 0x1d4))(), *(int *)(iVar5 + 0x1a0) == 0))))))

                  {

                    iVar5 = (**(code **)(*piVar1 + 0x1c8))();

                    if (*(int *)(iVar5 + 8) == 0) {

                      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x84 + iVar5);

                    }

                    else {

                      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0xb0);

                    }

                    uStack_20 = *puVar6;

                    uStack_1c = puVar6[1];

                    uStack_18 = puVar6[2];

                    uStack_14 = puVar6[3];

                    iVar5 = (**(code **)(*piVar1 + 0x1c8))();

                    if (*(int *)(iVar5 + 8) == 0) {

                      puVar6 = &DAT_00d1a640;

                    }

                    else {

                      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0x40);

                    }

                    uStack_40 = *puVar6;

                    uStack_3c = puVar6[1];

                    uStack_38 = puVar6[2];

                    uStack_34 = puVar6[3];

                    iVar5 = (**(code **)(*piVar1 + 0x1c8))();

                    iVar5 = *(int *)(*(int *)(iVar5 + 8) + 0x3c);

                    uStack_30 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x50);

                    uStack_2c = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x54);

                    uStack_28 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x58);

                    uStack_24 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x5c);

                    iVar5 = (**(code **)(*piVar1 + 0x1c8))();

                    if (*(int *)(iVar5 + 8) == 0) {

                      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x94 + iVar5);

                    }

                    else {

                      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0x30);

                    }

                    uStack_50 = *puVar6;

                    uStack_4c = puVar6[1];

                    uStack_48 = puVar6[2];

                    uStack_44 = puVar6[3];

                    piVar4 = (int *)(**(code **)(*piVar1 + 0x1c8))();

                    cVar2 = (**(code **)(*piVar4 + 0x3c))

                                      (param_1,&uStack_20,&uStack_40,&uStack_30,&uStack_50,

                                       0x3c23d70a,0,1);

                    if (cVar2 != '\0') {

                      iVar5 = (**(code **)(*piVar1 + 0x1c8))();

                      iVar5 = *(int *)(iVar5 + 8);

                      pcVar7 = (char *)FUN_005070b0(&uStack_57);

                      if ((*pcVar7 == '\0') && (*(int *)(iVar5 + 0x44) != 0)) {

                        FUN_005070d0();

                      }

                      if ((*(char *)(iVar5 + 0x40) == '\0') || (*(int *)(iVar5 + 8) == 0)) {

                        (**(code **)(**(int **)(iVar5 + 0x3c) + 0x44))(&uStack_50);

                      }

                      iVar5 = (**(code **)(*piVar1 + 0x1c8))();

                      iVar5 = *(int *)(iVar5 + 8);

                      pcVar7 = (char *)FUN_005070b0(auStack_56);

                      if ((*pcVar7 == '\0') && (*(int *)(iVar5 + 0x44) != 0)) {

                        FUN_005070d0();

                      }

                      (**(code **)(**(int **)(iVar5 + 0x3c) + 0x50))(&uStack_40);

                      iVar5 = (**(code **)(*piVar1 + 0x1c8))();

                      iVar5 = *(int *)(iVar5 + 8);

                      pcVar7 = (char *)FUN_005070b0(auStack_59);

                      if ((*pcVar7 == '\0') && (*(int *)(iVar5 + 0x44) != 0)) {

                        FUN_005070d0();

                      }

                      (**(code **)(**(int **)(iVar5 + 0x3c) + 0x54))(&DAT_00d1a640);

                      piVar9 = local_54;

                    }

                  }

                }

                break;

              }

              iVar3 = iVar3 + 1;

              piVar4 = piVar4 + 2;

            } while (iVar3 < iVar5);

          }

          piVar8 = piVar8 + 1;

        } while (piVar8 != (int *)(*(int *)(*piVar9 + 0x3c) + *(int *)(*piVar9 + 0x40) * 4));

      }

      piVar9 = piVar9 + 1;

    } while (piVar9 != (int *)(*(int *)(*(int *)(DAT_00d1b644 + 0xe4a4) + 8) +

                              *(int *)(*(int *)(DAT_00d1b644 + 0xe4a4) + 0xc) * 4));

  }

  return;

}
