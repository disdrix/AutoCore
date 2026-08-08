// =============================================================================
// ActionMap_ClearAllSlotBindFields_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007f74a0
// Address:   0x007f74a0–0x007f7560  (193 B / 0xC1)
// Module:    autoassault.exe  (image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; dual seal refine 2026-08-05 MEGA-019
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  Leaf ActionMap prologue: zero primary+alt DIK/mod, customized flag,
//           and two status bytes for every slot in all four mode banks.
//           Invoked once at the start of Client_InitDefaultKeybinds so later
//           default writes see flag==0.
//
// Convention (asm-sealed):
//   ESI  = ActionMap* base
//   no stack args
//   void; bare RET (C3)
//   ECX used as loop cursor (not this)
//
// Slot stride: 0x34
// Bank counts: 5 / 6 / 0x78 / 0x14  (≡ ActionMap_TrySetSlotBind kMax)
// Bank cursors (mod1 of index 0): +0x32 / +0x136 / +0x26E / +0x1ACE
//
// Related:
//   Client_InitDefaultKeybinds  0x007f8720  (sole static caller @ 0x007f8725)
//   ActionMap_TrySetSlotBind    0x007f72e0  (sibling; dualed W21-P)
//   Client_ActionMap_Init       0x007f9110
//   reviews/A|B_aa_007f74a0_ActionMap_ClearAllSlotBindFields_Inferred.md
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf: no callees, no SEH, no globals.
 * - Clears exactly 7 fields per slot; does not free, allocate, or write defaults.
 * - Total slots: 5+6+120+20 = 151.
 * - Mode product group names: Tentative (offsets sealed).
 * - _Inferred: product symbol English open.
 */

#include <stdint.h>

// Machine ABI is ESI-register base (not a C thiscall). Documented as an
// explicit parameter for portability; MSVC retail passes it in ESI.
void ActionMap_ClearAllSlotBindFields_Inferred(uint8_t* actionMap /* ESI */)
{
  // Per-mode absolute base offsets for the seven cleared fields at index 0.
  // Matches ActionMap_TrySetSlotBind tables (dualed W21-P).
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

// Retail control-flow shape (four counted loops, cursor = map + kMod1[mode]):
//   for each mode bank:
//     ECX = ESI + kMod1[mode]
//     EDX = kCount[mode]
//     EAX = 0
//     do {
//       word[ECX-0x2a]=0; word[ECX]=0; word[ECX-0x2c]=0; word[ECX-2]=0;
//       byte[ECX-0x27]=0; byte[ECX-0x28]=0; byte[ECX-0x26]=0;
//       ECX += 0x34; EDX--;
//     } while (EDX != 0);
//   RET
