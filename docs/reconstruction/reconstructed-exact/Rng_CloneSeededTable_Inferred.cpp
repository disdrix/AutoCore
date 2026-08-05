// =============================================================================
// Rng_CloneSeededTable_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0058ab60
// Address:   0x0058ab60  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (global RNG helper; HB ctor / skill apply consumers)
// Generated: 2026-07-29 dual A/B (from raw + live Ghidra decompile)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Seeded clone of a 600-ushort (300-dword / 0x4b0-byte) window from the global
//   MT-backed RNG word table (DAT_00d20c1c +0x08, cursor +0x0C).
//   Forces cursor = seedIndex, wraps if cursor+600 > 0xFFFFF, copies 300 dwords,
//   then cursor += 1. Returns heap buffer (caller owns; free with operator delete[]).
//
// HB ctor path (0x005788d0):
//   hb+0x6a8 = arg7 (seed); hb+0x6a0 = this(arg7).
//
// Dual: reviews/A|B_aa_0058ab60_Rng_CloneSeededTable_Inferred.md

#include <cstdint>

// Ghidra symbols (external)
extern "C" void* operator_new__(std::uint32_t size);  // operator new[]
extern "C" void* CVOGReaction_RandomUnitScalar(void); // → &DAT_00d20c1c

// RNG singleton layout (static sealed — see dual A/B):
//   +0x00 vtbl
//   +0x04 ready flag (byte)
//   +0x08 table base (uint8_t*, size 0x200000)
//   +0x0C cursor (int, ushort index)
//   +0x10 rebuild seed
//   +0x14 MT state object*

// __cdecl
extern "C" std::uint32_t* Rng_CloneSeededTable_Inferred(std::uint32_t seedIndex)
{
  std::uint32_t* heap = static_cast<std::uint32_t*>(operator_new__(0x4b0));

  auto* rng = static_cast<std::uint8_t*>(CVOGReaction_RandomUnitScalar());
  *reinterpret_cast<std::uint32_t*>(rng + 0x0c) = seedIndex;

  rng = static_cast<std::uint8_t*>(CVOGReaction_RandomUnitScalar());
  if (0xfffff < *reinterpret_cast<int*>(rng + 0x0c) + 600) {
    *reinterpret_cast<std::uint32_t*>(rng + 0x0c) = 0;
  }

  auto* src = reinterpret_cast<std::uint32_t*>(
      *reinterpret_cast<int*>(rng + 0x08) + *reinterpret_cast<int*>(rng + 0x0c) * 2);
  std::uint32_t* dst = heap;
  for (int n = 300; n != 0; n = n + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }

  *reinterpret_cast<int*>(rng + 0x0c) = *reinterpret_cast<int*>(rng + 0x0c) + 1;
  return heap;
}

// Legacy symbol alias for existing reconstructed-exact call sites.
extern "C" std::uint32_t* FUN_0058ab60(std::uint32_t seedIndex)
{
  return Rng_CloneSeededTable_Inferred(seedIndex);
}
