// =============================================================================
// FUN_00569fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00569fe0
// Address:   0x00569fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00569fe0 @ 0x00569fe0
// Stable ID: aa_00569fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: floor×2, FUN_00569fe0.
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

void __thiscall FUN_00569fe0(int param_1,float param_2)



{

  float fVar1;

  double dVar2;

  

  if (param_2 <= g_flZero) {

    dVar2 = floor((double)((float)(int)*(short *)(param_1 + 0x10c) * param_2));

    fVar1 = *(float *)(param_1 + 0x114) - ((float)dVar2 + (float)(int)*(short *)(param_1 + 0x10c));

  }

  else {

    dVar2 = floor((double)((float)(int)*(short *)(param_1 + 0x10c) * param_2));

    fVar1 = ((float)dVar2 - (float)(int)*(short *)(param_1 + 0x10c)) + *(float *)(param_1 + 0x114);

  }

  *(float *)(param_1 + 0x114) = fVar1;

  if (*(float *)(param_1 + 0x114) <= 0.0 && *(float *)(param_1 + 0x114) != 0.0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = 0;

  }

  return;

}
