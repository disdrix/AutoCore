// =============================================================================
// FUN_005a54b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a54b0
// Address:   0x005a54b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a54b0 @ 0x005a54b0
// Stable ID: aa_005a54b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: ABS×3, FUN_005a54b0, SQRT.
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

void __thiscall FUN_005a54b0(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  

  if ((g_flMsToSeconds_Inferred < ABS(param_2[2] - *(float *)(param_1 + 0x28)) ||

      g_flMsToSeconds_Inferred < ABS(param_2[1] - *(float *)(param_1 + 0x24))) ||

      g_flMsToSeconds_Inferred < ABS(*param_2 - *(float *)(param_1 + 0x20))) {

    *(float *)(param_1 + 0x20) = *param_2;

    *(float *)(param_1 + 0x24) = param_2[1];

    *(float *)(param_1 + 0x28) = param_2[2];

    *(float *)(param_1 + 0x2c) = param_2[3];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

    *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x40) - *(float *)(param_1 + 0x30);

    *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) - *(float *)(param_1 + 0x34);

    *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x48) - *(float *)(param_1 + 0x38);

    *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0x4c) - *(float *)(param_1 + 0x3c);

    fVar2 = 0.0;

    fVar1 = *(float *)(param_1 + 0x40) * *(float *)(param_1 + 0x40) +

            *(float *)(param_1 + 0x44) * *(float *)(param_1 + 0x44) +

            *(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x48);

    if (fVar1 != 0.0) {

      fVar2 = g_flOne / SQRT(fVar1);

    }

    *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x40) * fVar2;

    *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) * fVar2;

    *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x48) * fVar2;

    *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0x4c) * fVar2;

  }

  return;

}
