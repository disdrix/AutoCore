// =============================================================================
// FUN_007020e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007020e0
// Address:   0x007020e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007020e0 @ 0x007020e0
// Stable ID: aa_007020e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007020e0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_007020e0(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float *pfVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  pfVar1 = (float *)param_1[5];

  uVar4 = 1;

  fVar2 = (*param_2 - *pfVar1) * *param_1 +

          (param_2[1] - pfVar1[1]) * param_1[1] + (param_2[2] - pfVar1[2]) * param_1[2];

  if (fVar2 <= *param_3) {

    if (fVar2 + _DAT_00a0f040 <= *param_3) {

      uVar4 = 2;

    }

    else {

      *param_3 = fVar2 + _DAT_00a0f040;

      uVar4 = 2;

    }

  }

  else if (fVar2 < *param_4) {

    *param_4 = fVar2;

  }

  uVar3 = 4;

  if (*param_3 < *param_4) {

    uVar3 = uVar4;

  }

  return uVar3;

}
