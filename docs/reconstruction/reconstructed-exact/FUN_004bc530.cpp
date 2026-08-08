// =============================================================================
// FUN_004bc530  — scaffold twin of CNDHash_TraverseToNext_ListNext20
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc530
// Address:   0x004bc530–0x004bc57d inclusive (78 B / 0x4E)
// Module:    autoassault.exe (image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-08-05 MEGA-029 (retires 2026-07-23 scaffold body)
// Prefer:    reconstructed-exact/CNDHash_TraverseToNext_ListNext20.cpp
// =============================================================================

/*
 * Machine ABI (sealed MEGA-029):
 * - __thiscall RET 4; ECX=hash; stack cursor*; EAX=payload|0
 * - lock this+0x1d; head this+0x14; node next+0x20; payload+0x0c
 * - Strings: HashError:TraverseToNext… @ 0x00a27c9c; VOG_DEBUG_STOP @ 0x00a15844
 * - Reject Named_VOG_DEBUG_STOP_004bc530 as product id
 */

#include <cstdint>

extern "C" void FUN_007a4480(std::uint32_t level, const char *msg);

// Ghidra symbol keep-alive twin — same body as CNDHash_TraverseToNext_ListNext20
extern "C" std::uint32_t __thiscall FUN_004bc530(
    std::uint8_t *param_1,
    std::uint32_t *param_2)
{
  std::uint32_t iVar1;

  if (param_1[0x1d] == 0) {
    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }

  if (*param_2 == 0) {
    *param_2 = *reinterpret_cast<std::uint32_t *>(param_1 + 0x14);
    iVar1 = *reinterpret_cast<std::uint32_t *>(param_1 + 0x14);
  } else {
    iVar1 = *reinterpret_cast<std::uint32_t *>(
        reinterpret_cast<std::uint8_t *>(static_cast<std::uintptr_t>(*param_2)) + 0x20);
    *param_2 = iVar1;
  }

  if (iVar1 != 0) {
    return *reinterpret_cast<std::uint32_t *>(
        reinterpret_cast<std::uint8_t *>(static_cast<std::uintptr_t>(iVar1)) + 0x0c);
  }
  return 0;
}
