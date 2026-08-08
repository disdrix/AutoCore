// =============================================================================
// FUN_004088f0  — scaffold twin of StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004088f0
// Address:   0x004088f0  (autoassault.exe, image base 0x400000)
// System:    util / tree empty buynode isnil@+0x21 size 0x28
// Generated: 2026-08-04 WQ9H-I (updates scaffold 2026-07-23)
// Exactness: Behavior-preserving; prefer named clean for port.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// NOTE: Decompiler prints void; sealed return is EAX = node*.

#include <cstdint>
#include <cstddef>

extern "C" void* operator_new(std::size_t size);

// Prefer: StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred
extern "C" std::uint32_t* FUN_004088f0(void)
{
  // SEH omitted in scaffold plate.
  std::uint32_t* puVar1 = static_cast<std::uint32_t*>(operator_new(0x28));
  if (puVar1 != nullptr) {
    *puVar1 = 0;           // left
  }
  if (puVar1 != nullptr) {
    puVar1[1] = 0;         // parent  (decomp: if puVar1+1)
    puVar1[2] = 0;         // right   (decomp: if puVar1+2)
  }
  if (puVar1 != nullptr) {
    *reinterpret_cast<std::uint8_t*>(puVar1 + 8) = 1;            // color @ +0x20
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(puVar1) + 0x21) = 0; // isnil
  }
  return puVar1; // EAX
}
