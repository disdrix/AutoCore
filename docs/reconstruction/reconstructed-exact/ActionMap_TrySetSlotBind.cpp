// =============================================================================
// ActionMap_TrySetSlotBind
// -----------------------------------------------------------------------------
// Stable ID: aa_007f72e0
// Address:   0x007f72e0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29 W21-P
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  Leaf helper: write primary or alt DIK/mod into an ActionMap slot
//           of one of four mode groups, only if the slot customized flag is 0.
//
// Convention (asm-sealed):
//   AL  = slotIndex
//   BL  = bindLane   (0 = primary pair, nonzero = alt pair)
//   SI  = keyCode    (u16, typically DIK)
//   DX  = modCode    (u16)
//   stack0 = ActionMap* base
//   stack1 = mode (0..3)
//   return AL = 1 success / 0 fail; RET 8
//
// Slot stride: 0x34
// Jump table @ 0x007f7490 → mode cases.
//
// Related:
//   Client_InitDefaultKeybinds  0x007f8720  (74 call sites)
//   FUN_0092f710 keymap.ini     0x0092f710  (BL=0 then BL=1 per line)
//   Client_ActionMap_Init       0x007f9110
//   reviews/A|B_aa_007f72e0_ActionMap_TrySetSlotBind.md
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf: no callees.
 * - Fail if mode>3, index out of mode max, or flag already set.
 * - On success: write key+mod for chosen lane; clear two adjacent status bytes.
 * - Mode product group names: Tentative (offsets sealed).
 */

#include <stdint.h>

uint8_t ActionMap_TrySetSlotBind(
    uint8_t  slotIndex,   // AL
    uint8_t  bindLane,    // BL
    uint16_t keyCode,     // SI
    uint16_t modCode,     // DX
    uint8_t* actionMap,   // stack0
    uint32_t mode)        // stack1
{
  if (mode > 3u) {
    return 0;
  }

  // Per-mode: max count, flag, primary key/mod, alt key/mod, clear pair
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

  uint8_t* slot = actionMap + (uint32_t)slotIndex * 0x34u;

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
