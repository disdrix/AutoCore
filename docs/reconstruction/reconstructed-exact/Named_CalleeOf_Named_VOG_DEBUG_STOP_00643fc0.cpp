// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00643fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00643fc0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00643fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×12, do×3, while×3, return×2, goto×2, for×1.
//  - Notable callees: FUN_006a3db0×2, FUN_00643fc0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00643fc0(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  ushort uVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  uint16_t uVar8;

  ushort *puVar9;

  uint uVar10;

  int iVar11;

  float fVar12;

  int local_28;

  int local_10;

  

  uVar4 = FUN_006a3db0();

  local_10 = 0;

  iVar3 = *(int *)(param_4 + 0x3e0);

  iVar5 = *(int *)(param_1 + 4);

  iVar11 = param_3;

  if (0 < iVar5) {

    do {

      if (*(int *)(param_4 + 0x14) <= iVar11) {

        return;

      }

      local_28 = param_2;

      if (0 < iVar5) {

        do {

          iVar5 = *(int *)(param_4 + 0x10);

          if (iVar5 <= local_28) break;

          fVar12 = 0.0;

          iVar1 = local_28 + 1;

          param_3 = 0;

          for (uVar10 = ((int)(local_28 - 1U) < 1) - 1 & local_28 - 1U;

              ((int)uVar10 <= iVar1 && ((int)uVar10 < iVar5)); uVar10 = uVar10 + 1) {

            uVar6 = iVar11 - 1U & ((int)(iVar11 - 1U) < 1) - 1;

            if ((int)uVar6 <= iVar11 + 1) {

              puVar9 = (ushort *)(iVar3 + (iVar5 * uVar6 + uVar10) * 2);

              do {

                if (*(int *)(param_4 + 0x14) <= (int)uVar6) break;

                uVar2 = *puVar9;

                param_3 = param_3 + 1;

                uVar6 = uVar6 + 1;

                puVar9 = puVar9 + iVar5;

                fVar12 = (float)uVar2 + fVar12;

              } while ((int)uVar6 <= iVar11 + 1);

            }

          }

          uVar6 = FUN_006a3db0();

          local_28 = iVar5 * iVar11 + local_28;

          uVar10 = (uint)*(ushort *)(iVar3 + local_28 * 2);

          uVar7 = (uVar6 & 0xffff) - uVar10;

          uVar6 = (int)uVar7 >> 0x1f;

          uVar6 = (uVar7 ^ uVar6) - uVar6;

          uVar7 = uVar4 & 0xffff;

          if ((float)uVar10 <= fVar12 / (float)param_3) {

            if ((int)uVar7 <= (int)uVar6) {

              uVar6 = uVar7;

            }

            uVar10 = uVar10 + uVar6;

            if (0xfffe < uVar10) goto LAB_00644140;

joined_r0x00644159:

            uVar8 = (uint16_t)uVar10;

            if (uVar10 == 0) {

              uVar8 = 0;

            }

          }

          else {

            if ((int)uVar7 <= (int)uVar6) {

              uVar6 = uVar7;

            }

            uVar10 = uVar10 - uVar6;

            if (uVar10 < 0xffff) goto joined_r0x00644159;

LAB_00644140:

            uVar8 = 0xffff;

          }

          *(uint16_t *)(iVar3 + local_28 * 2) = uVar8;

          local_28 = iVar1;

        } while (iVar1 - param_2 < *(int *)(param_1 + 4));

      }

      iVar5 = *(int *)(param_1 + 4);

      local_10 = local_10 + 1;

      iVar11 = iVar11 + 1;

    } while (local_10 < iVar5);

  }

  return;

}
