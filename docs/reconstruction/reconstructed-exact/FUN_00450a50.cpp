// =============================================================================
// FUN_00450a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00450a50
// Address:   0x00450a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00450a50 @ 0x00450a50
// Stable ID: aa_00450a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×16, while×4, goto×2, do×1, return×1.
//  - Notable callees: FUN_00450a50, FUN_004694a0.
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

void FUN_00450a50(uint *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  float10 fVar8;

  float10 fVar9;

  uint32_t /* width from decompiler */ *puStack_c;

  

  puVar4 = param_2 + (((int)param_3 - (int)param_2 >> 2) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                     1);

  FUN_004694a0(param_2,puVar4,param_3 + -1,param_4);

  puVar6 = puVar4 + 1;

  if (param_2 < puVar4) {

    while( true ) {

      piVar1 = (int *)*puVar4;

      fVar8 = (float10)(**(code **)(*(int *)puVar4[-1] + 8))();

      fVar9 = (float10)(**(code **)(*piVar1 + 8))();

      if ((float10)(float)fVar8 < fVar9) break;

      piVar1 = (int *)puVar4[-1];

      fVar8 = (float10)(**(code **)(*(int *)*puVar4 + 8))();

      fVar9 = (float10)(**(code **)(*piVar1 + 8))();

      if (((float10)(float)fVar8 < fVar9) || (puVar4 = puVar4 + -1, puVar4 <= param_2)) break;

    }

  }

  puVar3 = puVar6;

  puStack_c = puVar4;

  puVar7 = puVar4;

  if (puVar6 < param_3) {

    while( true ) {

      piVar1 = (int *)*puVar4;

      fVar8 = (float10)(**(code **)(*(int *)*puVar6 + 8))();

      fVar9 = (float10)(**(code **)(*piVar1 + 8))();

      puVar3 = puVar6;

      if ((float10)(float)fVar8 < fVar9) break;

      piVar1 = (int *)*puVar6;

      fVar8 = (float10)(**(code **)(*(int *)*puVar4 + 8))();

      fVar9 = (float10)(**(code **)(*piVar1 + 8))();

      if (((float10)(float)fVar8 < fVar9) ||

         (puVar6 = puVar6 + 1, puVar3 = puVar6, param_3 <= puVar6)) break;

    }

  }

joined_r0x00450b37:

  do {

    puVar5 = puVar4;

    if (param_3 <= puVar3) {

joined_r0x00450b9e:

      while (param_2 < puVar4) {

        puVar5 = puVar5 + -1;

        piVar1 = (int *)*puVar7;

        fVar8 = (float10)(**(code **)(*(int *)*puVar5 + 8))();

        fVar9 = (float10)(**(code **)(*piVar1 + 8))();

        if (fVar9 <= (float10)(float)fVar8) {

          piVar1 = (int *)*puVar5;

          fVar8 = (float10)(**(code **)(*(int *)*puVar7 + 8))();

          fVar9 = (float10)(**(code **)(*piVar1 + 8))();

          puVar4 = puStack_c;

          if ((float10)(float)fVar8 < fVar9) break;

          uVar2 = puVar7[-1];

          puVar7 = puVar7 + -1;

          *puVar7 = *puVar5;

          *puVar5 = uVar2;

        }

        puStack_c = puStack_c + -1;

        puVar4 = puStack_c;

      }

      if (puVar4 == param_2) {

        if (puVar3 == param_3) {

          *param_1 = (uint)puVar7;

          param_1[1] = (uint)puVar6;

          return;

        }

        if (puVar6 != puVar3) {

          uVar2 = *puVar7;

          *puVar7 = *puVar6;

          *puVar6 = uVar2;

        }

        uVar2 = *puVar7;

        *puVar7 = *puVar3;

        puVar6 = puVar6 + 1;

        *puVar3 = uVar2;

        puVar3 = puVar3 + 1;

        puVar7 = puVar7 + 1;

      }

      else {

        puVar4 = puVar4 + -1;

        puStack_c = puVar4;

        if (puVar3 == param_3) {

          puVar7 = puVar7 + -1;

          if (puVar4 != puVar7) {

            uVar2 = *puVar4;

            *puVar4 = *puVar7;

            *puVar7 = uVar2;

          }

          puVar5 = puVar6 + -1;

          uVar2 = *puVar7;

          puVar6 = puVar6 + -1;

          *puVar7 = *puVar5;

          *puVar6 = uVar2;

        }

        else {

          uVar2 = *puVar3;

          *puVar3 = *puVar4;

          *puVar4 = uVar2;

          puVar3 = puVar3 + 1;

        }

      }

      goto joined_r0x00450b37;

    }

    piVar1 = (int *)*puVar3;

    fVar8 = (float10)(**(code **)(*(int *)*puVar7 + 8))();

    fVar9 = (float10)(**(code **)(*piVar1 + 8))();

    puVar4 = puStack_c;

    if (fVar9 <= (float10)(float)fVar8) {

      piVar1 = (int *)*puVar7;

      fVar8 = (float10)(**(code **)(*(int *)*puVar3 + 8))();

      fVar9 = (float10)(**(code **)(*piVar1 + 8))();

      puVar5 = puStack_c;

      if ((float10)(float)fVar8 < fVar9) goto joined_r0x00450b9e;

      uVar2 = *puVar6;

      *puVar6 = *puVar3;

      puVar6 = puVar6 + 1;

      *puVar3 = uVar2;

    }

    puVar3 = puVar3 + 1;

  } while( true );

}
