// =============================================================================
// ActionMap_TrySetSlotBind  (Ghidra: FUN_007f72e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_007f72e0
// Address:   0x007f72e0 – 0x007f748f  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-29 W21-P dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + register ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: reconstructed-exact/ActionMap_TrySetSlotBind.cpp
// =============================================================================

// PURPOSE:
//   Leaf: write primary/alt DIK+mod into ActionMap slot if customized flag clear.

#include <stdint.h>

// ABI: AL idx, BL lane, SI key, DX mod; stack base + mode; RET 8; AL success
uint8_t FUN_007f72e0(
    uint16_t modCode /*DX*/,
    void* actionMap /*stack0*/,
    uint32_t mode /*stack1*/)
{
  uint8_t slotIndex /*AL*/ = 0;  // filled by caller convention
  uint8_t bindLane /*BL*/ = 0;   // filled by caller convention
  uint16_t keyCode /*SI*/ = 0;   // filled by caller convention

  if (mode > 3u) {
    return 0;
  }

  static const uint32_t kMax[4]  = { 5, 6, 0x78, 0x14 };
  static const uint32_t kFlag[4] = { 0x0C, 0x110, 0x248, 0x1AA8 };
  static const uint32_t kKey0[4] = { 0x06, 0x10A, 0x242, 0x1AA2 };
  static const uint32_t kMod0[4] = { 0x30, 0x134, 0x26C, 0x1ACC };
  static const uint32_t kKey1[4] = { 0x08, 0x10C, 0x244, 0x1AA4 };
  static const uint32_t kMod1[4] = { 0x32, 0x136, 0x26E, 0x1ACE };
  static const uint32_t kClA[4]  = { 0x0B, 0x10F, 0x247, 0x1AA7 };
  static const uint32_t kClB[4]  = { 0x0A, 0x10E, 0x246, 0x1AA6 };

  if (slotIndex >= kMax[mode]) {
    return 0;
  }

  uint8_t* slot = (uint8_t*)actionMap + (uint32_t)slotIndex * 0x34u;
  if (slot[kFlag[mode]] != 0) {
    return 0;
  }

  if (bindLane == 0) {
    *(uint16_t*)(slot + kKey0[mode]) = keyCode;
    *(uint16_t*)(slot + kMod0[mode]) = modCode;
  } else {
    *(uint16_t*)(slot + kKey1[mode]) = keyCode;
    *(uint16_t*)(slot + kMod1[mode]) = modCode;
  }
  slot[kClA[mode]] = 0;
  slot[kClB[mode]] = 0;
  return 1;
}
