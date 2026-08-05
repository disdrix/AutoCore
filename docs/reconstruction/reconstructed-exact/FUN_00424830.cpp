// =============================================================================
// FUN_00424830  (scaffold alias → Rng_Mt19937_Extract)
// -----------------------------------------------------------------------------
// Stable ID: aa_00424830
// Address:   0x00424830  (autoassault.exe, image base 0x400000)
// Canonical: Rng_Mt19937_Extract
// Dual A/B:  2026-07-29 W20-C accept
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer: reconstructed-exact/Rng_Mt19937_Extract.cpp
// ABI: EAX = Mt19937State* (decompiler in_EAX); result uint32 in EAX.

unsigned int FUN_00424830(void)
{
  int in_EAX;
  unsigned int uVar1;

  if (*(int *)(in_EAX + 0x9c4) == 0) {
    FUN_004248c0();
  }
  *(int *)(in_EAX + 0x9c4) = *(int *)(in_EAX + 0x9c4) + -1;
  uVar1 = **(unsigned int **)(in_EAX + 0x9c0);
  *(unsigned int **)(in_EAX + 0x9c0) = *(unsigned int **)(in_EAX + 0x9c0) + 1;
  uVar1 = uVar1 ^ uVar1 >> 0xb;
  uVar1 = uVar1 ^ (uVar1 & 0xff3a58ad) << 7;
  uVar1 = uVar1 ^ (uVar1 & 0xffffdf8c) << 0xf;
  return uVar1 >> 0x12 ^ uVar1;
}
