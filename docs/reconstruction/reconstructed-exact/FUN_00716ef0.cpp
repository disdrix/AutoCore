// =============================================================================
// FUN_00716ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_00716ef0
// Address:   0x00716ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716ef0 @ 0x00716ef0
// Stable ID: aa_00716ef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00716ef0, FUN_00717c10.
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

float10 FUN_00716ef0(float param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                    uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,float *param_7)



{

  float fVar1;

  float *pfVar2;

  float10 fVar3;

  float local_c [3];

  

  fVar1 = (float)(&DAT_00a10e7c)[(int)param_1];

  if (0 < (int)param_1) {

    local_c[1] = (fVar1 + (float)(&DAT_00a10e78)[(int)param_1]) * DAT_00a0f298;

  }

  local_c[0] = (float)(uint)(0 < (int)param_1);

  if ((int)param_1 + 1 < 0x4a) {

    local_c[0] = (float)((int)local_c[0] + 1);

    local_c[(int)local_c[0]] = (fVar1 + (float)(&DAT_00a10e7c)[(int)param_1 + 1]) * DAT_00a0f298;

  }

  if (local_c[0] == 0.0) {

    return (float10)fVar1;

  }

  pfVar2 = local_c;

  param_1 = fVar1;

  do {

    pfVar2 = pfVar2 + 1;

    fVar1 = *pfVar2;

    fVar3 = (float10)FUN_00717c10(fVar1,param_2,param_3,param_4,param_5,param_6);

    if ((float10)*param_7 < fVar3) {

      *param_7 = (float)fVar3;

      param_1 = fVar1;

    }

    local_c[0] = (float)((int)local_c[0] - 1);

  } while (local_c[0] != 0.0);

  return (float10)param_1;

}
