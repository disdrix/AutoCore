// =============================================================================
// FUN_006f87d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f87d0
// Address:   0x006f87d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f87d0 @ 0x006f87d0
// Stable ID: aa_006f87d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f87d0.
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

void __thiscall FUN_006f87d0(int param_1,float *param_2,int param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  

  *(uint16_t *)(param_2 + 8) = *(uint16_t *)(param_3 + 4);

  pfVar4 = *(float **)(param_1 + 0x14);

  fVar1 = *param_4;

  fVar2 = param_4[1];

  fVar3 = param_4[2];

  *param_2 = fVar1 * *pfVar4 + fVar2 * pfVar4[4] + fVar3 * pfVar4[8] + pfVar4[0xc];

  param_2[1] = fVar1 * pfVar4[1] + fVar2 * pfVar4[5] + fVar3 * pfVar4[9] + pfVar4[0xd];

  param_2[2] = fVar1 * pfVar4[2] + fVar2 * pfVar4[6] + fVar3 * pfVar4[10] + pfVar4[0xe];

  param_2[3] = 0.0;

  pfVar4 = *(float **)(param_1 + 0x14);

  fVar1 = param_4[8];

  fVar2 = param_4[9];

  fVar3 = param_4[10];

  param_2[4] = fVar1 * *pfVar4 + fVar2 * pfVar4[4] + fVar3 * pfVar4[8];

  param_2[5] = fVar1 * pfVar4[1] + fVar2 * pfVar4[5] + fVar3 * pfVar4[9];

  param_2[6] = fVar1 * pfVar4[2] + fVar2 * pfVar4[6] + fVar3 * pfVar4[10];

  param_2[7] = 0.0;

  param_2[3] = param_4[0xd];

  return;

}
