// =============================================================================
// DES_CalculatePermutationP
// -----------------------------------------------------------------------------
// Stable ID: aa_0071bc40
// Address:   0x0071bc40  (autoassault.exe, image base 0x400000)
// System:    auth
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29):
 * - DES P-permutation leaf: 32-bit S-box output (param_1[0..3]) → 32-bit via
 *   four precomputed 256×4 byte OR-contrib banks (DAT_00d11658 + k*0x400).
 * - Output buffer in EAX; tables runtime-filled at DES_InitializeCipher
 *   (FUN_0071bdd0 / FUN_0071b5a0) — static image reads as all-zero.
 * - Sole caller: DES_RoundFunctionF @ 0x0071bff1.
 * - Remaining DAT_* identifiers are init-built LUTs, not FIPS matrices in-place.
 * - Runtime / differential verification: OPEN.
 *
 * Readability pass:
 * - Control flow and OR order preserved from authoritative raw / live Ghidra.
 * - Bank0 first-byte index uses Ghidra undefined4* scale (≡ byte*4).
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
