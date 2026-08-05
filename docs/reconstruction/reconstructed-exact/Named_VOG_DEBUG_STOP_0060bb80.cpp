// READABILITY (auto CF):
//  - Body size: ~136 non-empty decompiler lines.
//  - Control keywords: if×17, while×6, do×5, return×2, goto×1, for×1.
//  - Notable callees: CoTaskMemFree×4, FUN_007a4480×2, CNDHash_LookupByKey, CONCAT12, CONCAT13, CONCAT22, FUN_00537d30, FUN_0053c460.
//  - Strings: "HashError:remove, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0060bb80
// -----------------------------------------------------------------------------
// Stable ID: aa_0060bb80
// Address:   0x0060bb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t __thiscall Named_VOG_DEBUG_STOP_0060bb80(uint32_t /* width from decompiler */ *param_1,uint param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void *pvVar5;

  int *piVar6;

  uint uVar7;

  byte bVar8;

  LPVOID unaff_EBX;

  int iVar9;

  uint8_t uVar11;

  uint uVar10;

  int iStack_18;

  int local_14;

  int iStack_10;

  int iStack_c;

  uint32_t /* width from decompiler */ *local_8;

  int local_4;

  

  if (((void *)*param_1 == (void *)0x0) ||

     (local_8 = param_1, pvVar5 = CNDHash_LookupByKey((void *)*param_1,param_2),

     pvVar5 == (void *)0x0)) {

    return 0;

  }

  FUN_007e1d80();

  FUN_007c0350(&local_4,&local_14);

  FUN_007b7df0();

  uVar10 = 0;

  uVar11 = 0;

  iStack_18 = 0;

  if (0 < iStack_c) {

    do {

      piVar6 = *(int **)((int)unaff_EBX + iStack_18 * 4);

      if (*piVar6 == local_4) {

        bVar8 = *(byte *)((int)pvVar5 + 0x130);

        uVar10 = CONCAT13(bVar8,(int3)uVar10) & 0xffff0000;

        if (*(byte *)(piVar6 + 0x4c) == bVar8) {

          uVar7 = (uint)*(byte *)(piVar6 + 0x4c);

          if (uVar7 != 0) {

            piVar6 = (int *)piVar6[0x4d];

            iVar9 = *(int *)((int)pvVar5 + 0x13c) - (int)piVar6;

            do {

              if (*(int *)(*piVar6 + 4) != *(int *)(*(int *)(iVar9 + (int)piVar6) + 0x10)) {

                uVar10 = CONCAT22((short)(uVar10 >> 0x10),0x100);

              }

              piVar6 = piVar6 + 1;

              uVar7 = uVar7 - 1;

            } while (uVar7 != 0);

            if ((char)(uVar10 >> 8) != '\0') {

              bVar8 = (byte)(uVar10 >> 0x18);

              goto LAB_0060bc59;

            }

          }

        }

        else {

          uVar10 = 0x100;

LAB_0060bc59:

          uVar10 = (uint)CONCAT12(1,(short)uVar10);

          local_14 = 0;

          if (bVar8 != 0) {

            do {

              iVar9 = *(int *)(iStack_10 + 4);

              uVar7 = *(uint *)(*(int *)(*(int *)((int)pvVar5 + 0x13c) + local_14 * 4) + 0x10);

              if (*(char *)(iVar9 + 0x1d) != '\0') {

                FUN_007a4480(0,"HashError:remove, already locked for traversal");

                FUN_007a4480(0,"VOG_DEBUG_STOP");

              }

              iVar1 = *(int *)(*(int *)(iVar9 + 0x10) + (*(uint *)(iVar9 + 8) & uVar7) * 4);

              puVar4 = *(uint32_t /* width from decompiler */ **)(iVar1 + 4);

              puVar3 = (uint32_t /* width from decompiler */ *)0x0;

              while (puVar2 = puVar4, puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

                if (uVar7 == puVar2[4]) {

                  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

                    if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

                      *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = puVar2[3];

                    }

                    else {

                      puVar3[3] = puVar2[3];

                    }

                  }

                  break;

                }

                puVar3 = puVar2;

                puVar4 = (uint32_t /* width from decompiler */ *)puVar2[3];

              }

              FUN_00537d30();

              if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

                puVar2[2] = 0;

                if (puVar2 == *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14)) {

                  *(uint32_t /* width from decompiler */ *)(iVar9 + 0x14) = puVar2[5];

                }

                else {

                  *(uint32_t /* width from decompiler */ *)(puVar2[6] + 0x14) = puVar2[5];

                }

                if (puVar2 == *(uint32_t /* width from decompiler */ **)(iVar9 + 0x18)) {

                  *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18) = puVar2[6];

                }

                else {

                  *(uint32_t /* width from decompiler */ *)(puVar2[5] + 0x18) = puVar2[6];

                }

                *puVar2 = &PTR_LAB_009cf02c;

                *puVar2 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x20);

                *(uint32_t /* width from decompiler */ **)(iVar9 + 0x20) = puVar2;

                *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + -1;

              }

              local_14 = local_14 + 1;

            } while (local_14 < (int)(uint)*(byte *)((int)pvVar5 + 0x130));

          }

        }

        FUN_00546e40(*(uint32_t /* width from decompiler */ *)((int)unaff_EBX + iStack_18 * 4));

        if (((char)(uVar10 >> 8) != '\0') && (iVar9 = 0, *(char *)((int)pvVar5 + 0x130) != '\0')) {

          do {

            iVar1 = *(int *)(*(int *)((int)pvVar5 + 0x13c) + iVar9 * 4);

            FUN_0053c460(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x10),iVar1,0);

            iVar9 = iVar9 + 1;

          } while (iVar9 < (int)(uint)*(byte *)((int)pvVar5 + 0x130));

        }

      }

      iVar9 = 0;

      if (*(char *)((int)pvVar5 + 0x130) != '\0') {

        do {

          CoTaskMemFree(*(LPVOID *)

                         (*(int *)(*(int *)((int)unaff_EBX + iStack_18 * 4) + 0x134) + iVar9 * 4));

          iVar9 = iVar9 + 1;

        } while (iVar9 < (int)(uint)*(byte *)((int)pvVar5 + 0x130));

      }

      CoTaskMemFree(*(LPVOID *)(*(int *)((int)unaff_EBX + iStack_18 * 4) + 0x134));

      CoTaskMemFree(*(LPVOID *)((int)unaff_EBX + iStack_18 * 4));

      uVar11 = (uint8_t)(uVar10 >> 0x10);

      iStack_18 = iStack_18 + 1;

    } while (iStack_18 < iStack_c);

  }

  CoTaskMemFree(unaff_EBX);

  return uVar11;

}
