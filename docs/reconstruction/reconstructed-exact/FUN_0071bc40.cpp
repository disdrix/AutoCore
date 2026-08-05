// =============================================================================
// FUN_0071bc40
// -----------------------------------------------------------------------------
// Stable ID: aa_0071bc40
// Address:   0x0071bc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// SUPERSEDED 2026-07-29: canonical clean is DES_CalculatePermutationP.cpp
// PURPOSE: DES P-permutation @ 0x0071bc40 (aa_0071bc40)
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: DES_CalculatePermutationP.
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

byte * DES_CalculatePermutationP(byte *param_1)



{

  byte *pbVar1;

  int iVar2;

  byte bVar3;

  byte *in_EAX;

  

  *in_EAX = 0;

  pbVar1 = in_EAX + 1;

  *pbVar1 = 0;

  in_EAX[2] = 0;

  in_EAX[3] = 0;

  bVar3 = *param_1;

  *in_EAX = *in_EAX | *(byte *)(&DAT_00d11658 + bVar3);

  iVar2 = (uint)bVar3 * 4;

  *pbVar1 = *pbVar1 | *(byte *)((int)&DAT_00d11658 + iVar2 + 1);

  in_EAX[2] = in_EAX[2] | *(byte *)((int)&DAT_00d11658 + iVar2 + 2);

  in_EAX[3] = in_EAX[3] | *(byte *)((int)&DAT_00d11658 + iVar2 + 3);

  bVar3 = param_1[1];

  *in_EAX = *in_EAX | (&DAT_00d11a58)[(uint)bVar3 * 4];

  iVar2 = (uint)bVar3 * 4;

  *pbVar1 = *pbVar1 | (&DAT_00d11a59)[iVar2];

  in_EAX[2] = in_EAX[2] | (&DAT_00d11a5a)[iVar2];

  in_EAX[3] = in_EAX[3] | (&DAT_00d11a5b)[iVar2];

  bVar3 = param_1[2];

  *in_EAX = *in_EAX | (&DAT_00d11e58)[(uint)bVar3 * 4];

  iVar2 = (uint)bVar3 * 4;

  *pbVar1 = *pbVar1 | (&DAT_00d11e59)[iVar2];

  in_EAX[2] = in_EAX[2] | (&DAT_00d11e5a)[iVar2];

  in_EAX[3] = in_EAX[3] | (&DAT_00d11e5b)[iVar2];

  bVar3 = param_1[3];

  *in_EAX = *in_EAX | (&DAT_00d12258)[(uint)bVar3 * 4];

  iVar2 = (uint)bVar3 * 4;

  *pbVar1 = *pbVar1 | (&DAT_00d12259)[iVar2];

  in_EAX[2] = in_EAX[2] | (&DAT_00d1225a)[iVar2];

  in_EAX[3] = in_EAX[3] | (&DAT_00d1225b)[iVar2];

  return in_EAX + 3;

}
