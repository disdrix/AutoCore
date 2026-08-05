// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGWaypoint_UpdateState_004d5910
// -----------------------------------------------------------------------------
// Stable ID: aa_004d5910
// Callee of Named_CalleeOf_CVOGWaypoint_UpdateState
// Address:   0x004d5910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGWaypoint_UpdateState: AI/path helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×1.
//  - Notable callees: FUN_00493830, FUN_004d5910.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGWaypoint_UpdateState
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGWaypoint_UpdateState_004d5910(int param_1,float *param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint uVar9;

  int local_c;

  int local_8;

  

  uVar7 = (uint)(*param_2 / *(float *)(param_1 + 0xe7c0));

  iVar2 = *(int *)(param_1 + 0xe7b8);

  uVar9 = (uint)(param_2[2] / *(float *)(param_1 + 0xe7c4));

  uVar7 = ((int)uVar7 < 0) - 1 & uVar7;

  uVar5 = iVar2 - 1U;

  if ((int)uVar7 <= (int)(iVar2 - 1U)) {

    uVar5 = uVar7;

  }

  uVar7 = *(int *)(param_1 + 0xe7bc) - 1;

  uVar9 = ((int)uVar9 < 0) - 1 & uVar9;

  if ((int)uVar7 < (int)uVar9) {

    uVar9 = uVar7;

  }

  uVar5 = uVar5 - 1;

  local_8 = 3;

  do {

    uVar7 = ((int)uVar5 < 0) - 1 & uVar5;

    param_2 = (float *)(iVar2 - 1U);

    if ((int)uVar7 <= (int)(iVar2 - 1U)) {

      param_2 = (float *)uVar7;

    }

    local_c = 3;

    uVar7 = uVar9 - 1;

    do {

      uVar6 = *(int *)(param_1 + 0xe7bc) - 1;

      uVar3 = ((int)uVar7 < 0) - 1 & uVar7;

      if ((int)uVar3 <= (int)uVar6) {

        uVar6 = uVar3;

      }

      iVar4 = (iVar2 * uVar6 + (int)param_2) * 0x20 + *(int *)(param_1 + 0xe7b4);

      puVar8 = *(uint32_t /* width from decompiler */ **)(iVar4 + 4);

      if (puVar8 != *(uint32_t /* width from decompiler */ **)(iVar4 + 8)) {

        do {

          iVar2 = *(int *)(param_3 + 4);

          if ((iVar2 == 0) ||

             ((uint)(*(int *)(param_3 + 0xc) - iVar2 >> 2) <=

              (uint)(*(int *)(param_3 + 8) - iVar2 >> 2))) {

            FUN_00493830(*(uint32_t /* width from decompiler */ *)(param_3 + 8),1,puVar8);

          }

          else {

            puVar1 = *(uint32_t /* width from decompiler */ **)(param_3 + 8);

            *puVar1 = *puVar8;

            *(uint32_t /* width from decompiler */ **)(param_3 + 8) = puVar1 + 1;

          }

          iVar2 = *(int *)(param_1 + 0xe7b8);

          puVar8 = puVar8 + 1;

        } while (puVar8 != *(uint32_t /* width from decompiler */ **)

                            ((iVar2 * uVar6 + (int)param_2) * 0x20 + 8 + *(int *)(param_1 + 0xe7b4))

                );

      }

      uVar7 = uVar7 + 1;

      local_c = local_c + -1;

    } while (local_c != 0);

    uVar5 = uVar5 + 1;

    local_8 = local_8 + -1;

  } while (local_8 != 0);

  return;

}
