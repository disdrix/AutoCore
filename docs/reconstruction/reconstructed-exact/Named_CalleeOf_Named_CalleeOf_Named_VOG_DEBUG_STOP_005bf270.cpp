// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005bf270
// -----------------------------------------------------------------------------
// Stable ID: aa_005bf270
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x005bf270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: CONCAT31, CVOGTerrain_GetTileIndex, FUN_004a8c40, FUN_005bf270.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005bf270(int param_1,int *param_2,int param_3,int param_4)



{

  int iVar1;

  byte bVar2;

  int iVar3;

  ushort uVar4;

  ushort uVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  int iVar10;

  int iVar11;

  

  iVar1 = (uint)*(byte *)(*param_2 + 0x1c) * 0x54;

  *(int *)(param_1 + 0xcc) = param_3;

  *(int *)(param_1 + 0xd0) = param_4;

  *(uint16_t *)(param_1 + 0xec) = 0;

  *(uint16_t *)(param_1 + 0xea) = 0xffff;

  param_4 = param_2[6] * param_4;

  iVar10 = param_2[7];

  param_3 = param_2[6] * param_3;

  iVar8 = iVar10 + param_4;

  iVar7 = param_4;

  if (param_4 < iVar8) {

    do {

      iVar8 = *(int *)(*param_2 + 0x14) + -1;

      if (iVar7 < iVar8) {

        iVar8 = iVar7;

      }

      iVar3 = param_3;

      if (param_3 < iVar10 + param_3) {

        do {

          iVar10 = *param_2;

          iVar11 = *(int *)(iVar10 + 0x10) + -1;

          if (iVar3 < iVar11) {

            iVar11 = iVar3;

          }

          uVar5 = *(ushort *)

                   (*(int *)(iVar10 + 0x3e0) + (*(int *)(iVar10 + 0x10) * iVar8 + iVar11) * 2);

          uVar6 = ((int)(iVar11 - 1U) < 0) - 1 & iVar11 - 1U;

          uVar9 = iVar8 - 1U & ((int)(iVar8 - 1U) < 0) - 1;

          bVar2 = CVOGTerrain_GetTileIndex(uVar6,uVar9);

          uVar6 = FUN_004a8c40(uVar6,uVar9);

          uVar4 = *(ushort *)(param_1 + 0xea);

          if (uVar5 < *(ushort *)(param_1 + 0xea)) {

            uVar4 = uVar5;

          }

          *(ushort *)(param_1 + 0xea) = uVar4;

          if (uVar5 <= *(ushort *)(param_1 + 0xec)) {

            uVar5 = *(ushort *)(param_1 + 0xec);

          }

          *(ushort *)(param_1 + 0xec) = uVar5;

          uVar9 = (uint)bVar2;

          *(uint *)((iVar8 >> ((byte)param_2[0x18] & 0x1f)) * param_2[0x16] +

                    (iVar11 >> ((byte)param_2[0x18] & 0x1f)) * param_2[0x17] + param_2[0x15]) =

               ((((uint)*(byte *)(iVar1 + 0xaefbbe + uVar9 * 4) * (uVar6 >> 0x10 & 0xff)) / 0xff |

                0xffffff00) << 8 |

               ((uint)*(byte *)(iVar1 + 0xaefbbd + uVar9 * 4) * (uVar6 >> 8 & 0xff)) / 0xff) << 8 |

               ((*(uint *)(iVar1 + 0xaefbbc + uVar9 * 4) & 0xff) * (uVar6 & 0xff)) / 0xff;

          iVar3 = iVar3 + 1;

        } while (iVar3 < param_2[7] + param_3);

      }

      iVar10 = param_2[7];

      iVar7 = iVar7 + 1;

      iVar8 = iVar10 + param_4;

    } while (iVar7 < iVar8);

  }

  return CONCAT31((int3)((uint)iVar8 >> 8),1);

}
