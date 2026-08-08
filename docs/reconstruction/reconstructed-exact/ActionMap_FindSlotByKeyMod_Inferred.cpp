// =============================================================================
// ActionMap_FindSlotByKeyMod_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007f6db0
// Address:   0x007f6db0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; dual seal refine 2026-08-05 MEGA-018
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  Leaf ActionMap lookup — scan one of four mode groups for a slot
//           whose primary or alt DIK matches keyCode, with mod-state agreement
//           or override-flag escape. Returns pointer to the slot's key0 field.
//
// Convention (asm-sealed; NOT standard fastcall):
//   EAX = mode (0..3)
//   EDI = ActionMap* base
//   SI  = keyCode (u16)
//   DX  = modState (u16; 0 = no-mod / unbound, nonzero e.g. 0x2A LSHIFT)
//   return EAX = uint16_t* (&slot.key0) or NULL
//   RET (C3) — no stack cleanup
//
// Slot stride: 0x34
// Jump table @ 0x007f6fa4 → mode cases 0..3
// Body: 0x007f6db0–0x007f6fa3 (756 B)
//
// Related:
//   Client_Input_OnKeyDown_MatchAction  0x00911030  (sole caller @ 0x00911429)
//   ActionMap_TrySetSlotBind            0x007f72e0  (same mode/offset family)
//   ActionMap_FormatSlotBindDisplay     0x007f9160
//   Client_ActionMap_Init               0x007f9110
//   Client_InitDefaultKeybinds          0x007f8720
//   reviews/A|B_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md
//
// Retired scaffold name:
//   Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007f6db0
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf: no callees.
 * - Match if keyN==keyCode and ((modState==0)==(modN==0) OR override!=0).
 * - Return targets key0 field of the slot (caller uses +4 held / +5 edge).
 * - Mode product group names: Tentative (offsets sealed).
 * - Sole observed call site uses mode=0 + global ActionMap 0x00d1b9ac.
 */

#include <stdint.h>

uint16_t* ActionMap_FindSlotByKeyMod_Inferred(
    uint32_t mode,       // EAX
    uint16_t keyCode,    // SI
    uint16_t modState,   // DX
    uint8_t* actionMap)  // EDI
{
  if (mode > 3u) {
    return 0;
  }

  // Per-mode: max count, key0 base, mod0 cursor (match TrySetSlotBind tables)
  static const uint32_t kMax[4]  = { 5, 6, 0x78, 0x14 };
  static const uint32_t kKey0[4] = { 0x06, 0x10A, 0x242, 0x1AA2 };
  static const uint32_t kMod0[4] = { 0x30, 0x134, 0x26C, 0x1ACC };

  const uint32_t maxSlots = kMax[mode];
  const uint32_t key0Base = kKey0[mode];
  uint16_t* cursor = (uint16_t*)(actionMap + kMod0[mode]);

  for (uint32_t i = 0; i < maxSlots; ++i) {
    // Primary lane: key0 @ cursor-0x15 shorts (-0x2A bytes), mod0 @ cursor
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

    // Alt lane: key1 @ cursor-0x14 shorts (-0x28 bytes), mod1 @ cursor+1
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

    cursor += 0x1a; // +0x34 bytes
  }

  return 0;
}
