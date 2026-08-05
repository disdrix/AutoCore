// =============================================================================
// FUN_0074e800
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e800
// Address:   0x0074e800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074e800 @ 0x0074e800
// Stable ID: aa_0074e800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_0074e800, ROUND, _CIfmod, floor.
//  - Return sites: 3.

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

float10 __thiscall FUN_0074e800(int param_1,float param_2)



{

  float *pfVar1;

  float fVar2;

  float *pfVar3;

  float10 fVar4;

  float fVar5;

  double dVar6;

  

  if ((*(char *)(param_1 + 0x56) == '\0') &&

     ((param_2 != *(float *)(param_1 + 0x40) || (*(char *)(param_1 + 0x54) != '\0')))) {

    *(float *)(param_1 + 0x40) = param_2;

    fVar5 = (param_2 - *(float *)(param_1 + 0x34)) * *(float *)(param_1 + 0x3c);

    pfVar1 = (float *)(param_1 + 0x44);

    *pfVar1 = fVar5;

    if (*(char *)(param_1 + 0x4c) == '\0') {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

      pfVar3 = (float *)(param_1 + 0x48);

      if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {

        *pfVar1 = 0.0;

        *(uint8_t *)(param_1 + 0x54) = 0;

        return (float10)*(float *)(param_1 + 0x44);

      }

      if (*pfVar1 < *pfVar3 || *pfVar1 == *pfVar3) {

        pfVar3 = pfVar1;

      }

      *pfVar1 = *pfVar3;

    }

    else {

      dVar6 = floor((double)(fVar5 / *(float *)(param_1 + 0x48)));

      *(int *)(param_1 + 0x50) = (int)ROUND(dVar6);

      fVar4 = (float10)_CIfmod();

      fVar2 = g_flZero;

      fVar5 = (float)fVar4;

      *pfVar1 = fVar5;

      if (fVar5 < fVar2) {

        *pfVar1 = fVar5 + *(float *)(param_1 + 0x48);

        *(uint8_t *)(param_1 + 0x54) = 0;

        return (float10)*(float *)(param_1 + 0x44);

      }

    }

    *(uint8_t *)(param_1 + 0x54) = 0;

  }

  return (float10)*(float *)(param_1 + 0x44);

}
