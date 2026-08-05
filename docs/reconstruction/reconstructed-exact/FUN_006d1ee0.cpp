// =============================================================================
// FUN_006d1ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d1ee0
// Address:   0x006d1ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d1ee0 @ 0x006d1ee0
// Stable ID: aa_006d1ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006d1ee0.
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

void __thiscall FUN_006d1ee0(int param_1,float *param_2,uint32_t /* width from decompiler */ *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  uint uVar6;

  

  fVar1 = *param_2;

  fVar2 = param_2[1];

  fVar3 = param_2[2];

  fVar4 = fVar1 * *(float *)(param_1 + 0x20) +

          fVar2 * *(float *)(param_1 + 0x24) + fVar3 * *(float *)(param_1 + 0x28);

  fVar5 = fVar1 * *(float *)(param_1 + 0x30) +

          fVar2 * *(float *)(param_1 + 0x34) + fVar3 * *(float *)(param_1 + 0x38);

  if (fVar5 <= fVar4) {

    uVar6 = 0x10;

  }

  else {

    uVar6 = 0x20;

    fVar4 = fVar5;

  }

  if (fVar4 < fVar1 * *(float *)(param_1 + 0x10) +

              fVar2 * *(float *)(param_1 + 0x14) + fVar3 * *(float *)(param_1 + 0x18)) {

    uVar6 = 0;

  }

  *param_3 = *(uint32_t /* width from decompiler */ *)(uVar6 + 0x10 + param_1);

  param_3[1] = *(uint32_t /* width from decompiler */ *)(uVar6 + 0x14 + param_1);

  param_3[2] = *(uint32_t /* width from decompiler */ *)(uVar6 + 0x18 + param_1);

  param_3[3] = *(uint32_t /* width from decompiler */ *)(uVar6 + 0x1c + param_1);

  param_3[3] = uVar6 | 0x3f000000;

  return;

}
