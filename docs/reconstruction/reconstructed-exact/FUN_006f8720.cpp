// =============================================================================
// FUN_006f8720
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8720
// Address:   0x006f8720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8720 @ 0x006f8720
// Stable ID: aa_006f8720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f8720.
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

void __thiscall FUN_006f8720(int param_1,float *param_2,ushort *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  ushort uVar4;

  float *pfVar5;

  

  uVar4 = *param_3;

  *(ushort *)(param_2 + 8) = param_3[2];

  pfVar5 = *(float **)(param_1 + 0x14);

  fVar1 = *param_4;

  fVar2 = param_4[1];

  fVar3 = param_4[2];

  *param_2 = fVar1 * *pfVar5 + fVar2 * pfVar5[4] + fVar3 * pfVar5[8] + pfVar5[0xc];

  param_2[1] = fVar1 * pfVar5[1] + fVar2 * pfVar5[5] + fVar3 * pfVar5[9] + pfVar5[0xd];

  param_2[2] = fVar1 * pfVar5[2] + fVar2 * pfVar5[6] + fVar3 * pfVar5[10] + pfVar5[0xe];

  param_2[3] = 0.0;

  fVar1 = -param_4[0xc];

  pfVar5 = (float *)((uVar4 - 3) * 0x10 + *(int *)(param_1 + 0x18));

  param_2[4] = fVar1 * *pfVar5;

  param_2[5] = fVar1 * pfVar5[1];

  param_2[6] = fVar1 * pfVar5[2];

  param_2[7] = fVar1 * pfVar5[3];

  param_2[3] = param_4[0xd];

  return;

}
