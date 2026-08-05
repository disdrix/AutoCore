// =============================================================================
// FUN_0074ed90 — Ghidra-name twin of AnimSlot_Ctor
// Address: 0x0074ed90  Stable: aa_0074ed90  Dual: W24-R 2026-07-29
// See AnimSlot_Ctor.cpp for sealed field table + ABI.
// =============================================================================

#include <cstdint>

extern "C" float g_flOne; // 0x00a0f2a0 = 1.0f

void __fastcall FUN_0074ed90(int param_1)
{
  *reinterpret_cast<std::uint32_t *>(param_1 + 4) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 8) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0xc) = 0;
  *reinterpret_cast<float *>(param_1 + 0x10) = 0.0f;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x18) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x1c) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x20) = 0;
  float one = g_flOne;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x28) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x2c) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x30) = 0;
  *reinterpret_cast<std::uint8_t *>(param_1 + 0x55) = 0;
  *reinterpret_cast<std::uint8_t *>(param_1 + 0x56) = 0;
  *reinterpret_cast<float *>(param_1 + 0x34) = 0.0f;
  *reinterpret_cast<float *>(param_1 + 0x38) = 0.0f;
  *reinterpret_cast<float *>(param_1 + 0x3c) = one;
  *reinterpret_cast<float *>(param_1 + 0x40) = 0.0f;
  *reinterpret_cast<float *>(param_1 + 0x44) = 0.0f;
  *reinterpret_cast<float *>(param_1 + 0x48) = 0.0f;
  *reinterpret_cast<std::uint8_t *>(param_1 + 0x4c) = 1;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x50) = 0xFFFFFFFFu;
  *reinterpret_cast<std::uint8_t *>(param_1 + 0x54) = 1;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x58) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x5c) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x60) = 0xFFFFFFFFu;
  *reinterpret_cast<float *>(param_1 + 0x64) = 0.0f;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x68) = 0xFFFFFFFFu;
  *reinterpret_cast<float *>(param_1 + 0x6c) = 0.0f;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x70) = 0;
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x74) = 0;
}
