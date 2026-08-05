// =============================================================================
// FUN_0063d7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0063d7d0
// Address:   0x0063d7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063d7d0 @ 0x0063d7d0
// Stable ID: aa_0063d7d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063d7d0.
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

void __thiscall FUN_0063d7d0(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  fVar4 = param_2[1];

  fVar1 = param_2[2];

  fVar2 = *param_2;

  fVar3 = (*(float *)(param_1 + 0x88) * fVar1 + *(float *)(param_1 + 0x84) * fVar4 +

          *(float *)(param_1 + 0x80) * fVar2) * *(float *)(param_1 + 0xe0);

  fVar5 = *(float *)(param_1 + 0xe4) *

          (*(float *)(param_1 + 0x98) * fVar1 + *(float *)(param_1 + 0x94) * fVar4 +

          *(float *)(param_1 + 0x90) * fVar2);

  fVar4 = *(float *)(param_1 + 0xe8) *

          (*(float *)(param_1 + 0xa8) * fVar1 + *(float *)(param_1 + 0xa4) * fVar4 +

          *(float *)(param_1 + 0xa0) * fVar2);

  *(float *)(param_1 + 0x50) =

       *(float *)(param_1 + 0x50) +

       *(float *)(param_1 + 0xa0) * fVar4 + *(float *)(param_1 + 0x90) * fVar5 +

       *(float *)(param_1 + 0x80) * fVar3;

  *(float *)(param_1 + 0x54) =

       *(float *)(param_1 + 0x54) +

       *(float *)(param_1 + 0xa4) * fVar4 + *(float *)(param_1 + 0x94) * fVar5 +

       *(float *)(param_1 + 0x84) * fVar3;

  *(float *)(param_1 + 0x58) =

       *(float *)(param_1 + 0x58) +

       *(float *)(param_1 + 0xa8) * fVar4 + *(float *)(param_1 + 0x98) * fVar5 +

       *(float *)(param_1 + 0x88) * fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c);

  return;

}
