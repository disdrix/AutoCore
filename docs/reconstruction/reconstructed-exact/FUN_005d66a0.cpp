// =============================================================================
// FUN_005d66a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d66a0
// Address:   0x005d66a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d66a0 @ 0x005d66a0
// Stable ID: aa_005d66a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005d6460×2, FUN_005d66a0.
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

void __fastcall FUN_005d66a0(int param_1)



{

  float10 fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar2 = *(float *)(*(int *)(*(int *)(param_1 + 8) + 0x20) + 0x18);

  if (fVar2 < *(float *)(param_1 + 0x14)) {

    fVar3 = *(float *)(param_1 + 0x14) * DAT_00a0f298;

    fVar4 = *(float *)(*(int *)(*(int *)(param_1 + 8) + 0x14) + 0xc) * *(float *)(param_1 + 0x38);

    if (fVar2 < fVar3) {

      *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x14) + fVar4;

      fVar1 = (float10)FUN_005d6460();

      *(float *)(param_1 + 0xc) = (float)fVar1;

      return;

    }

    fVar2 = ((fVar2 - fVar3) * fVar4) / (*(float *)(param_1 + 0x14) - fVar3) +

            *(float *)(param_1 + 0x14);

  }

  *(float *)(param_1 + 0x10) = fVar2;

  fVar1 = (float10)FUN_005d6460();

  *(float *)(param_1 + 0xc) = (float)fVar1;

  return;

}
