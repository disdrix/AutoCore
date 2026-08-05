// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00758c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00758c80
// Callee of Named_CalleeOf_Named_gfxDevice
// Address:   0x00758c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: if×8, while×7, do×2, return×1.
//  - Notable callees: FUN_00440810×2, FUN_0076c3c0×2, FUN_0043ffb0, FUN_00440c90, FUN_00441a80, FUN_00756f40, FUN_00758c80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDevice
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00758c80(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  int *local_3c;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = DAT_00d1f614;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1c43;

  local_c = ExceptionList;

  uVar2 = *(uint32_t /* width from decompiler */ *)(DAT_00d1f614 + 0xc4);

  ExceptionList = &local_c;

  if (*(char *)(DAT_00d1f614 + 200) == '\0') {

    ExceptionList = &local_c;

    iVar6 = FUN_0076c3c0();

    piVar7 = (int *)(iVar4 + 0x34 + *(int *)(iVar4 + 0xc4) * 4);

    *piVar7 = *piVar7 + (iVar6 - *(int *)(iVar4 + 0x30));

    *(int *)(iVar4 + 0x30) = iVar6;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc4) = 1;

  }

  uVar3 = DAT_00aaa668;

  local_4 = 0;

  piVar7 = *(int **)(param_1 + 8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = uVar3;

  piVar8 = (int *)*piVar7;

  while (piVar8 != piVar7) {

    FUN_00440810(local_24,local_20,local_1c,0xffffffff,local_14,local_10);

    piVar8[8] = 0;

    FUN_00441a80();

    piVar7 = *(int **)(param_1 + 8);

  }

  FUN_00440c90(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + 4));

  *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);

  piVar7 = (int *)**(int **)(param_1 + 0x14);

  local_3c = piVar7;

  if (piVar7 != *(int **)(param_1 + 0x14)) {

    do {

      piVar8 = *(int **)piVar7[5];

      if (piVar8 != (int *)piVar7[5]) {

        do {

          FUN_00440810(local_24,local_20,local_1c,0xffffffff,local_14,local_10);

          piVar8[8] = 0;

          if (*(char *)((int)piVar8 + 0x3d) == '\0') {

            piVar7 = (int *)piVar8[2];

            if (*(char *)((int)piVar7 + 0x3d) == '\0') {

              cVar1 = *(char *)(*piVar7 + 0x3d);

              piVar8 = piVar7;

              piVar7 = (int *)*piVar7;

              while (cVar1 == '\0') {

                cVar1 = *(char *)(*piVar7 + 0x3d);

                piVar8 = piVar7;

                piVar7 = (int *)*piVar7;

              }

            }

            else {

              cVar1 = *(char *)(piVar8[1] + 0x3d);

              piVar5 = (int *)piVar8[1];

              piVar7 = piVar8;

              while ((piVar8 = piVar5, cVar1 == '\0' && (piVar7 == (int *)piVar8[2]))) {

                cVar1 = *(char *)(piVar8[1] + 0x3d);

                piVar5 = (int *)piVar8[1];

                piVar7 = piVar8;

              }

            }

          }

          piVar7 = local_3c;

        } while (piVar8 != (int *)local_3c[5]);

      }

      if (*(char *)((int)piVar7 + 0x1d) == '\0') {

        piVar8 = (int *)piVar7[2];

        if (*(char *)((int)piVar8 + 0x1d) == '\0') {

          cVar1 = *(char *)(*piVar8 + 0x1d);

          piVar7 = piVar8;

          piVar8 = (int *)*piVar8;

          while (local_3c = piVar7, cVar1 == '\0') {

            cVar1 = *(char *)(*piVar8 + 0x1d);

            piVar7 = piVar8;

            piVar8 = (int *)*piVar8;

          }

        }

        else {

          cVar1 = *(char *)(piVar7[1] + 0x1d);

          piVar5 = (int *)piVar7[1];

          piVar8 = piVar7;

          while ((piVar7 = piVar5, local_3c = piVar7, cVar1 == '\0' && (piVar8 == (int *)piVar7[2]))

                ) {

            cVar1 = *(char *)(piVar7[1] + 0x1d);

            piVar5 = (int *)piVar7[1];

            piVar8 = piVar7;

          }

        }

      }

    } while (piVar7 != *(int **)(param_1 + 0x14));

  }

  FUN_0043ffb0(iVar4,uVar2,local_2c,local_28);

  iVar6 = DAT_00d1f024;

  *(int *)(param_1 + 0x48) = DAT_00d1f024;

  *(int *)(param_1 + 0x50) = iVar6 + *(int *)(param_1 + 0x80);

  iVar6 = DAT_00d1f028;

  *(int *)(param_1 + 0x4c) = DAT_00d1f028;

  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x84) + iVar6;

  FUN_00756f40();

  if (*(char *)(iVar4 + 200) == '\0') {

    iVar6 = FUN_0076c3c0();

    piVar7 = (int *)(iVar4 + 0x34 + *(int *)(iVar4 + 0xc4) * 4);

    *piVar7 = *piVar7 + (iVar6 - *(int *)(iVar4 + 0x30));

    *(int *)(iVar4 + 0x30) = iVar6;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc4) = uVar2;

  }

  ExceptionList = local_c;

  return 0;

}
