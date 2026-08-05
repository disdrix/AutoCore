// =============================================================================
// FUN_0065eb10  (scaffold twin of Phys_StackDesc_ResetFlag0_Float1000)
// -----------------------------------------------------------------------------
// Stable ID: aa_0065eb10
// Address:   0x0065eb10  (autoassault.exe, image base 0x400000)
// System:    physics / Havok stack or CCS descriptor
// Generated: 2026-07-29 W25-O dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named:     docs/reconstruction/reconstructed-exact/Phys_StackDesc_ResetFlag0_Float1000.cpp
// =============================================================================

#include <cstdint>

extern "C" float DAT_00a0f520;  // 0x00a0f520 → 1000.0f

// Live decompile shape (Ghidra void + undefined1*).
void __fastcall FUN_0065eb10(uint8_t* param_1)
{
  uint32_t uVar1;

  uVar1 = *reinterpret_cast<uint32_t*>(&DAT_00a0f520);
  *param_1 = 0;
  *reinterpret_cast<uint32_t*>(param_1 + 4) = uVar1;
}
