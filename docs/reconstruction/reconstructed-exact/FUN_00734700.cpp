// =============================================================================
// FUN_00734700
// -----------------------------------------------------------------------------
// Stable ID: aa_00734700
// Address:   0x00734700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00734700 @ 0x00734700
// Stable ID: aa_00734700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×6, for×3, return×1.
//  - Notable callees: FUN_00734700, FUN_0095d580.
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

void FUN_00734700(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  float fVar7;

  float fVar8;

  float local_30;

  uint32_t /* width from decompiler */ local_28 [10];

  

  piVar1 = (int *)param_1[0xc];

  fVar7 = 0.0;

  piVar4 = (int *)param_1[0xb];

  iVar3 = 0;

  local_30 = 0.0;

  puVar5 = param_1;

  puVar6 = local_28;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  for (; piVar4 != piVar1; piVar4 = piVar4 + 1) {

    iVar3 = *piVar4;

    fVar8 = fVar7;

    if (iVar3 != 0) {

      puVar5 = param_1;

      puVar6 = local_28;

      for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar6 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      }

      FUN_0095d580(param_2,local_28,0);

      fVar8 = local_30;

      if (0.0 < fVar7) {

        fVar8 = fVar7;

        if (g_flOne - local_30 < fVar7) {

          fVar8 = g_flOne - local_30;

        }

        fVar7 = fVar8 + local_30;

        if (*(uint32_t /* width from decompiler */ **)(iVar3 + 4) != *(uint32_t /* width from decompiler */ **)(iVar3 + 8)) {

          (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(iVar3 + 4) + 0x1c))

                    (param_3,param_3,local_28,fVar8 / fVar7);

        }

        fVar8 = fVar7;

        local_30 = fVar7;

        if (g_flOne <= fVar7) break;

      }

    }

    fVar7 = fVar8;

  }

  if ((((param_4 != '\0') && (iVar3 != 0)) && (fVar7 < g_flOne)) &&

     (*(uint32_t /* width from decompiler */ **)(iVar3 + 4) != *(uint32_t /* width from decompiler */ **)(iVar3 + 8))) {

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(iVar3 + 4) + 0x1c))(param_3,param_1,param_3,local_30);

  }

  return;

}
