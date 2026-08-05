// =============================================================================
// FUN_007372e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007372e0
// Address:   0x007372e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007372e0 @ 0x007372e0
// Stable ID: aa_007372e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: ABS, FUN_004653a0, FUN_007372e0, FUN_00972fa0, SQRT.
//  - Return sites: 4.

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

float10 __thiscall FUN_007372e0(int *param_1,uint32_t /* width from decompiler */ param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  float fVar4;

  float fVar5;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  if ((char)param_1[0x34] != '\0') {

    fVar3 = (float10)(**(code **)(*param_1 + 0x24))();

    fVar2 = (float)fVar3;

    if ((float10)g_flMsToSeconds_Inferred <= fVar3) {

      FUN_00972fa0(param_3);

      fStack_8 = fStack_14 - (float)param_1[0x29];

      fVar1 = *(float *)((int)param_3 + 0xc);

      fStack_c = fStack_18 - (float)param_1[0x28];

      fStack_4 = fStack_10 - (float)param_1[0x2a];

      fVar4 = fStack_4 * fStack_4 + fStack_8 * fStack_8 + fStack_c * fStack_c;

      if ((fVar1 + fVar2) * (fVar1 + fVar2) < fVar4) {

        return (float10)g_flZero;

      }

      if (*(char *)((int)param_3 + 0x2c) == '\0') {

        if (DAT_00aaa620 <= fVar4) {

          param_2 = SQRT(fVar4);

          if (fVar1 <= param_2 + fVar2) {

            fVar5 = g_flOne;

            param_3 = g_flOne;

            if (fVar2 <= param_2 + fVar1) {

              fVar4 = ((fVar2 * fVar2 + fVar4) - fVar1 * fVar1) /

                      (param_2 * g_flLevelUpUiBase_Inferred);

              fVar5 = fVar2 - fVar4;

              fVar4 = fVar4 - (param_2 - fVar1);

              param_3 = ((fVar2 * g_flVehicleHpTechCoeff - fVar5) * fVar5 * fVar5 * DAT_00aaa628 +

                        (fVar1 * g_flVehicleHpTechCoeff - fVar4) * fVar4 * fVar4 * DAT_00aaa628) /

                        (fVar1 * fVar1 * fVar1 * DAT_00aaa62c);

              fVar5 = param_3;

              param_2 = ABS((param_2 + fVar2) - fVar1 * DAT_00a0f298);

            }

          }

          else {

            param_3 = (fVar2 * fVar2 * fVar2 * DAT_00aaa62c) /

                      (fVar1 * fVar1 * fVar1 * DAT_00aaa62c);

            param_2 = 0.0;

            fVar5 = 0.0;

          }

        }

        else if (fVar1 <= fVar2) {

          param_3 = g_flOne;

          param_2 = 0.0;

          fVar5 = 0.0;

        }

        else {

          param_3 = (fVar2 * fVar2 * fVar2 * DAT_00aaa62c) / (fVar1 * fVar1 * fVar1 * DAT_00aaa62c);

          param_2 = 0.0;

          fVar5 = 0.0;

        }

        FUN_004653a0(param_2);

        return (float10)fVar5 * (float10)(float)param_1[0x35] * (float10)param_3;

      }

      fVar3 = (float10)(**(code **)(*param_1 + 0x28))(&fStack_c);

      return fVar3 * (float10)(float)param_1[0x35];

    }

  }

  return (float10)g_flZero;

}
