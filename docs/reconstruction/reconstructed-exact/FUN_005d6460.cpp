// =============================================================================
// FUN_005d6460
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6460
// Address:   0x005d6460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d6460 @ 0x005d6460
// Stable ID: aa_005d6460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_005d6460, FUN_005d6ae0.
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

float10 __fastcall FUN_005d6460(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  

  fVar4 = *(float *)(param_1 + 0x10) - *(float *)(param_1 + 0x18);

  fVar2 = 0.0;

  if (0.0 <= fVar4) {

    fVar3 = *(float *)(param_1 + 0x34);

    if (*(float *)(param_1 + 0x10) <= *(float *)(param_1 + 0x1c) &&

        *(float *)(param_1 + 0x1c) != *(float *)(param_1 + 0x10)) {

      fVar2 = g_flOne / (*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x18));

      fVar3 = (fVar3 - *(float *)(param_1 + 0x30)) * fVar2 * fVar4 + *(float *)(param_1 + 0x30);

      fVar2 = ((*(float *)(param_1 + 0x28) - g_flOne) * fVar2 * fVar2 * fVar4 * fVar4 + g_flOne) *

              *(float *)(param_1 + 0x20);

    }

    fVar3 = fVar3 * *(float *)(param_1 + 0x20);

  }

  else {

    fVar2 = g_flOne / (*(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x18));

    fVar3 = ((*(float *)(param_1 + 0x2c) - *(float *)(param_1 + 0x30)) * fVar2 * fVar4 +

            *(float *)(param_1 + 0x30)) * *(float *)(param_1 + 0x20);

    fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 8) + 0x20) + 0x18);

    fVar2 = ((*(float *)(param_1 + 0x24) - g_flOne) * fVar2 * fVar2 * fVar4 * fVar4 + g_flOne) *

            *(float *)(param_1 + 0x20);

    if (fVar1 < *(float *)(param_1 + 0x14)) {

      fVar3 = fVar1 / *(float *)(param_1 + 0x14);

    }

  }

  fVar3 = fVar2 * *(float *)(*(int *)(*(int *)(param_1 + 8) + 0x14) + 0xc) - fVar3;

  FUN_005d6ae0(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30) + 0x3c) + 0x80,

               *(int *)(*(int *)(param_1 + 8) + 0x10) + 0x10);

  fVar2 = local_18 * 0.0 + local_20 * 0.0 + local_1c;

  if (0.0 < fVar2) {

    local_28 = DAT_00af4264 * fVar2 + g_flOne;

    if (DAT_00af4264 < local_28) {

      local_28 = DAT_00af4264;

    }

    return (float10)local_28 * (float10)fVar3;

  }

  return (float10)fVar3;

}
