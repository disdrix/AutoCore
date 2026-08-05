// =============================================================================
// FUN_0067b0a0  (canonical structural: Net_SockaddrIn_Init)
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b0a0
// Address:   0x0067b0a0  (autoassault.exe, image base 0x400000)
// System:    network / sockaddr fill
// Generated: 2026-07-29 W17-C dual A/B seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Prefer named clean: reconstructed-exact/Net_SockaddrIn_Init.cpp
// =============================================================================

#include <cstdint>

extern "C" uint16_t __stdcall htons(uint16_t hostshort);

uint32_t* __thiscall FUN_0067b0a0(uint32_t* param_1, uint32_t param_2, uint16_t param_3)
{
  uint16_t uVar1;

  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *reinterpret_cast<uint16_t*>(param_1) = 2;
  param_1[1] = param_2;
  uVar1 = htons(param_3);
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(param_1) + 2) = uVar1;
  return param_1;
}
