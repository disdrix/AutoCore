// =============================================================================
// FUN_007f74a0  (machine twin of ActionMap_ClearAllSlotBindFields_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007f74a0
// Address:   0x007f74a0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; dual seal refine 2026-08-05 MEGA-019
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named twin: ActionMap_ClearAllSlotBindFields_Inferred.cpp
// =============================================================================

#include <stdint.h>

// ESI = ActionMap*; void; bare RET. See named twin for plate + tables.
void FUN_007f74a0(uint8_t* actionMap /* ESI */)
{
  static const uint32_t kCount[4] = { 5, 6, 0x78, 0x14 };
  static const uint32_t kKey0[4]  = { 0x06, 0x10A, 0x242, 0x1AA2 };
  static const uint32_t kKey1[4]  = { 0x08, 0x10C, 0x244, 0x1AA4 };
  static const uint32_t kMod0[4]  = { 0x30, 0x134, 0x26C, 0x1ACC };
  static const uint32_t kMod1[4]  = { 0x32, 0x136, 0x26E, 0x1ACE };
  static const uint32_t kClB[4]   = { 0x0A, 0x10E, 0x246, 0x1AA6 };
  static const uint32_t kClA[4]   = { 0x0B, 0x10F, 0x247, 0x1AA7 };
  static const uint32_t kFlag[4]  = { 0x0C, 0x110, 0x248, 0x1AA8 };

  for (uint32_t mode = 0; mode < 4u; ++mode) {
    for (uint32_t i = 0; i < kCount[mode]; ++i) {
      uint8_t* slot = actionMap + i * 0x34u;
      *(uint16_t*)(slot + kKey0[mode]) = 0;
      *(uint16_t*)(slot + kKey1[mode]) = 0;
      *(uint16_t*)(slot + kMod0[mode]) = 0;
      *(uint16_t*)(slot + kMod1[mode]) = 0;
      slot[kClB[mode]]  = 0;
      slot[kClA[mode]]  = 0;
      slot[kFlag[mode]] = 0;
    }
  }
}
