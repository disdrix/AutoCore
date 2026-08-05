// =============================================================================
// FUN_00490530
// -----------------------------------------------------------------------------
// Stable ID: aa_00490530
// Address:   0x00490530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00490530 @ 0x00490530
// Stable ID: aa_00490530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: for×6, if×3, return×1.
//  - Notable callees: ROUND×4, FUN_004cd330×2, FUN_00490530.
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

void __thiscall FUN_00490530(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  

  iVar1 = (int)ROUND(*(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x80) /

                     *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c0));

  iVar2 = (int)ROUND(*(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x7c) /

                     *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c4));

  iVar3 = (int)ROUND(*(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x88) /

                     *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c4));

  iVar8 = (int)ROUND(*(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x74) /

                     *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c0));

  for (iVar7 = iVar8; iVar6 = iVar2, iVar7 < iVar1; iVar7 = iVar7 + 1) {

    for (; iVar6 < iVar3; iVar6 = iVar6 + 1) {

      iVar5 = FUN_004cd330(iVar7,iVar6);

      puVar9 = *(uint32_t /* width from decompiler */ **)(iVar5 + 4);

      if ((puVar9 != (uint32_t /* width from decompiler */ *)0x0) &&

         (puVar4 = *(uint32_t /* width from decompiler */ **)(iVar5 + 8), (int)puVar4 - (int)puVar9 >> 2 != 0)) {

        for (; puVar9 != puVar4; puVar9 = puVar9 + 1) {

          (**(code **)(*(int *)*puVar9 + 0x50))();

        }

      }

      *param_2 = *param_2 + 1;

    }

  }

  for (; iVar7 = iVar2, iVar8 < iVar1; iVar8 = iVar8 + 1) {

    for (; iVar7 < iVar3; iVar7 = iVar7 + 1) {

      if (*param_2 < *(int *)(param_1 + 0x178)) {

        *param_2 = *param_2 + 1;

      }

      else {

        iVar6 = FUN_004cd330(iVar8,iVar7);

        puVar9 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0x14);

        if ((puVar9 != (uint32_t /* width from decompiler */ *)0x0) && (*(int *)(iVar6 + 0x18) - (int)puVar9 >> 2 != 0)) {

          puVar4 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0x18);

          for (; puVar9 != puVar4; puVar9 = puVar9 + 1) {

            (**(code **)(*(int *)*puVar9 + 0x50))();

          }

        }

        *param_2 = *param_2 + 1;

      }

    }

  }

  return;

}
