// =============================================================================
// FUN_004b6a80  (alias → NDSpecialFX_List1e0_AnyFlag10)
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6a80
// Address:   0x004b6a80–0x004b6aa7  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX residual list probe
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W26-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Named clean: docs/reconstruction/reconstructed-exact/NDSpecialFX_List1e0_AnyFlag10.cpp

#include <cstdint>

// Retail: ECX=host; AL bool. Leaf.
uint32_t __fastcall FUN_004b6a80(int param_1)
{
  uint32_t* puVar1;

  puVar1 = reinterpret_cast<uint32_t*>(
      *reinterpret_cast<uint32_t**>(param_1 + 0x1e0));
  while (true) {
    if (puVar1 == *reinterpret_cast<uint32_t**>(param_1 + 0x1e0)) {
      return reinterpret_cast<uint32_t>(puVar1) & 0xffffff00; // AL=0
    }
    if ((*(uint8_t*)(puVar1[2] + 0x989) & 0x10) != 0) {
      break;
    }
    puVar1 = reinterpret_cast<uint32_t*>(*puVar1);
  }
  return 1; // AL=1 (upper bits from node ptr ignored by callers as char)
}
