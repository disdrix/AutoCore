// =============================================================================
// FUN_005a6340
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6340
// Address:   0x005a6340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6340 @ 0x005a6340
// Stable ID: aa_005a6340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×6, while×1, return×1.
//  - Notable callees: SQRT×2, FUN_005a6340.
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

uint32_t /* width from decompiler */ __thiscall FUN_005a6340(int *param_1,int param_2,float *param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  float fStack_54;

  uint32_t /* width from decompiler */ local_50;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float local_30;

  float local_2c;

  float local_28;

  float fStack_24;

  float local_20;

  float fStack_1c;

  float fStack_18;

  

  local_2c = param_3[1];

  local_30 = *param_3;

  local_50 = DAT_009d823c;

  local_28 = param_3[2];

  fVar4 = local_28 * local_28 + local_2c * local_2c + local_30 * local_30;

  iVar3 = 0;

  if (fVar4 == 0.0) {

    fVar4 = 0.0;

  }

  else {

    fVar4 = g_flOne / SQRT(fVar4);

  }

  local_30 = fVar4 * local_30;

  local_2c = fVar4 * local_2c;

  local_28 = local_28 * fVar4;

  (**(code **)(*param_1 + 0x2c))(&local_20);

  while( true ) {

    if (param_1[5] == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = param_1[6] - param_1[5] >> 2;

    }

    if (iVar2 <= iVar3) break;

    iVar2 = iVar3 * 4;

    if ((*(int *)(iVar2 + param_1[5]) != 0) &&

       (piVar1 = *(int **)(iVar2 + param_1[5]), piVar1[0x4d] != param_2)) {

      (**(code **)(*piVar1 + 0x2c))(&fStack_44);

      fStack_40 = fStack_40 - local_20;

      fStack_3c = fStack_3c - fStack_1c;

      fStack_44 = fStack_44 - fStack_24;

      fVar5 = fStack_3c * fStack_3c + fStack_40 * fStack_40 + fStack_44 * fStack_44;

      fVar4 = 0.0;

      if (fVar5 != 0.0) {

        fVar4 = g_flOne / SQRT(fVar5);

      }

      fStack_44 = fVar4 * fStack_44;

      fStack_3c = fVar4 * fStack_3c;

      fStack_40 = fVar4 * fStack_40;

      fVar5 = fStack_3c * local_2c + fStack_40 * local_30 + fStack_44 * fStack_34;

      fStack_38 = fVar4 * (fStack_38 - fStack_18);

      if (fStack_54 < fVar5) {

        local_50 = *(uint32_t /* width from decompiler */ *)(param_1[5] + iVar2);

        fStack_54 = fVar5;

      }

    }

    iVar3 = iVar3 + 1;

  }

  return local_50;

}
