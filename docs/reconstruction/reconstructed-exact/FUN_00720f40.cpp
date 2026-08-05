// =============================================================================
// FUN_00720f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00720f40
// Address:   0x00720f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00720f40 @ 0x00720f40
// Stable ID: aa_00720f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×13, return×2.
//  - Notable callees: Client_GetMissionCompleteAudioTable×2, FUN_007227e0×2, ROUND×2, FUN_00720f40.
//  - Return sites: 2.

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

void __thiscall FUN_00720f40(int param_1,float param_2)



{

  int *piVar1;

  int iVar2;

  float fVar3;

  float10 fVar4;

  float fVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  fVar3 = g_flOne;

  fVar5 = *(float *)(param_1 + 0x1b0);

  if (fVar5 < *(float *)(param_1 + 0x1a4) || fVar5 == *(float *)(param_1 + 0x1a4)) {

    if (*(float *)(param_1 + 0x1b0) <= *(float *)(param_1 + 0x1a4) &&

        *(float *)(param_1 + 0x1a4) != *(float *)(param_1 + 0x1b0)) {

      fVar5 = g_flMultiKillCountBlend;

      if (*(float *)(param_1 + 0x2e0) != g_flZero) {

        fVar5 = param_2 / *(float *)(param_1 + 0x2e0);

      }

      fVar5 = *(float *)(param_1 + 0x1a4) - fVar5;

      if (fVar5 <= g_flOne) {

        *(float *)(param_1 + 0x1a4) = fVar5;

      }

      else {

        *(float *)(param_1 + 0x1a4) = g_flOne;

      }

      fVar5 = *(float *)(param_1 + 0x1b0);

      if (*(float *)(param_1 + 0x1a4) <= fVar5 && fVar5 != *(float *)(param_1 + 0x1a4)) {

        if (fVar5 <= fVar3) {

          *(float *)(param_1 + 0x1a4) = fVar5;

        }

        else {

          *(float *)(param_1 + 0x1a4) = fVar3;

        }

      }

      if (((*(int **)(param_1 + 0x10) != (int *)0x0) && (*(int *)(param_1 + 0x1c) != 0)) &&

         (piVar1 = (int *)**(int **)(param_1 + 0x10), piVar1 != (int *)0x0)) {

        uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a4);

        iVar2 = *piVar1;

        Client_GetMissionCompleteAudioTable(uVar6);

        fVar4 = (float10)FUN_007227e0(uVar6);

        (**(code **)(iVar2 + 0x3c))(piVar1,(int)ROUND(fVar4));

      }

    }

  }

  else if (*(float *)(param_1 + 0x1a4) <= fVar5 && fVar5 != *(float *)(param_1 + 0x1a4)) {

    fVar5 = g_flMultiKillCountBlend;

    if (*(float *)(param_1 + 0x2e0) != g_flZero) {

      fVar5 = param_2 / *(float *)(param_1 + 0x2dc);

    }

    fVar5 = fVar5 + *(float *)(param_1 + 0x1a4);

    if (fVar5 <= g_flOne) {

      *(float *)(param_1 + 0x1a4) = fVar5;

    }

    else {

      *(float *)(param_1 + 0x1a4) = g_flOne;

    }

    if (*(float *)(param_1 + 0x1b0) <= *(float *)(param_1 + 0x1a4) &&

        *(float *)(param_1 + 0x1a4) != *(float *)(param_1 + 0x1b0)) {

      if (*(float *)(param_1 + 0x1b0) <= fVar3) {

        *(float *)(param_1 + 0x1a4) = *(float *)(param_1 + 0x1b0);

      }

      else {

        *(float *)(param_1 + 0x1a4) = fVar3;

      }

    }

    if (((*(int **)(param_1 + 0x10) != (int *)0x0) && (*(int *)(param_1 + 0x1c) != 0)) &&

       (piVar1 = (int *)**(int **)(param_1 + 0x10), piVar1 != (int *)0x0)) {

      uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a4);

      iVar2 = *piVar1;

      Client_GetMissionCompleteAudioTable(uVar6);

      fVar4 = (float10)FUN_007227e0(uVar6);

      (**(code **)(iVar2 + 0x3c))(piVar1,(int)ROUND(fVar4));

      return;

    }

  }

  return;

}
