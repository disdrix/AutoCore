// =============================================================================
// FUN_0067b070  (scaffold twin of Net_SockaddrIn_InitZero)
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b070
// Address:   0x0067b070  (autoassault.exe, image base 0x400000)
// System:    network / sockaddr fill
// Generated: 2026-07-29 W25-O dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named:     docs/reconstruction/reconstructed-exact/Net_SockaddrIn_InitZero.cpp
// =============================================================================

#include <cstdint>

extern "C" uint16_t __stdcall htons(uint16_t hostshort);

// Live decompile shape.
uint32_t* __fastcall FUN_0067b070(uint32_t* param_1)
{
  uint16_t uVar1;

  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *reinterpret_cast<uint16_t*>(param_1) = 0;
  param_1[1] = 0;
  uVar1 = htons(0);
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(param_1) + 2) = uVar1;
  return param_1;
}
