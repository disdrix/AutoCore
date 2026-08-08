// =============================================================================
// FUN_007f6db0  (clean twin of ActionMap_FindSlotByKeyMod_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007f6db0
// Address:   0x007f6db0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; dual seal refine 2026-08-05 MEGA-018
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named twin: ActionMap_FindSlotByKeyMod_Inferred.cpp
// =============================================================================

#include <stdint.h>

// Ghidra name retained for address-keyed tooling. Prefer the named twin.
uint16_t* FUN_007f6db0(
    uint32_t mode,       // EAX
    uint16_t keyCode,    // SI
    uint16_t modState,   // DX
    uint8_t* actionMap)  // EDI
{
  if (mode > 3u) {
    return 0;
  }

  static const uint32_t kMax[4]  = { 5, 6, 0x78, 0x14 };
  static const uint32_t kKey0[4] = { 0x06, 0x10A, 0x242, 0x1AA2 };
  static const uint32_t kMod0[4] = { 0x30, 0x134, 0x26C, 0x1ACC };

  const uint32_t maxSlots = kMax[mode];
  const uint32_t key0Base = kKey0[mode];
  uint16_t* cursor = (uint16_t*)(actionMap + kMod0[mode]);

  for (uint32_t i = 0; i < maxSlots; ++i) {
    if (cursor[-0x15] == (short)keyCode) {
      if (modState == 0) {
        if (*cursor == 0) {
          return (uint16_t*)(actionMap + key0Base + i * 0x34u);
        }
      } else if (*cursor != 0) {
        return (uint16_t*)(actionMap + key0Base + i * 0x34u);
      }
      if (*(uint8_t*)((uint8_t*)cursor + 6) != 0) {
        return (uint16_t*)(actionMap + key0Base + i * 0x34u);
      }
    }

    if (cursor[-0x14] == (short)keyCode) {
      if (modState == 0) {
        if (cursor[1] == 0) {
          return (uint16_t*)(actionMap + key0Base + i * 0x34u);
        }
      } else if (cursor[1] != 0) {
        return (uint16_t*)(actionMap + key0Base + i * 0x34u);
      }
      if (*(uint8_t*)((uint8_t*)cursor + 6) != 0) {
        return (uint16_t*)(actionMap + key0Base + i * 0x34u);
      }
    }

    cursor += 0x1a;
  }

  return 0;
}
