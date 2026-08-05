// =============================================================================
// FUN_0074c310
// -----------------------------------------------------------------------------
// Stable ID: aa_0074c310
// Address:   0x0074c310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074c310 @ 0x0074c310
// Stable ID: aa_0074c310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00972fa0×2, FUN_0074c060, FUN_0074c310.
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

uint32_t /* width from decompiler */ __thiscall FUN_0074c310(int param_1,int param_2,int param_3,int param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ uVar5;

  float fVar6;

  

  if ((*(char *)(param_2 + 0xb8) == '\0') && (*(char *)(param_3 + 0xb8) == '\0')) {

    pfVar4 = (float *)FUN_00972fa0(param_1);

    fVar1 = *pfVar4;

    fVar2 = pfVar4[1];

    fVar3 = pfVar4[2];

    pfVar4 = (float *)FUN_00972fa0(param_4);

    fVar6 = *(float *)(param_3 + 0x9c) * *(float *)(param_4 + 0xc) +

            *(float *)(param_2 + 0x9c) * *(float *)(param_1 + 0xc);

    if ((fVar3 - pfVar4[2]) * (fVar3 - pfVar4[2]) + (fVar2 - pfVar4[1]) * (fVar2 - pfVar4[1]) +

        (fVar1 - *pfVar4) * (fVar1 - *pfVar4) < fVar6 * fVar6) {

      return 1;

    }

    return 0;

  }

  uVar5 = FUN_0074c060(param_1,param_4);

  return uVar5;

}
