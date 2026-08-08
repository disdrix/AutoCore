// =============================================================================
// ObjectiveNode_IsEligibleForTracker_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0059dc50
// Address:   0x0059dc50–0x0059dcb9 inclusive (106 B / 0x6A)
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_0059dc50
// System:    missions-progression
// Sealed:    2026-08-05 MEGA-025 dual (decompile + disassemble_function +
//            read_memory + callers/xrefs + call-site assembly context)
// Exactness: Behavior-preserving rewrite of image control flow. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED (no Launcher; terminal false).
// Prior scaffold retired: Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dc50
// =============================================================================
//
// PURPOSE
//   Boolean eligibility gate for mission-objective tracker selection/bind.
//   Callers (Client_TryBindActiveMissionTracker, objective-hash walks) only
//   promote a node when this returns true.
//
//   Stages:
//     1) Reject null character.
//     2) If template short@+0xf8 is non-zero, require node flag byte@+0x14.
//     3) Reject when sibling evaluator FUN_0059db80 returns -1.
//     4) For template ids in inclusive band [0xdfd, 0xe02], require character
//        virtual method at vtbl+0x27c to return >= 5; else reject.
//     5) Otherwise eligible.
//
// ABI (image-sealed thiscall)
//   ECX = ObjectiveNode* this
//   stack = Character* (often DAT_00d1b6d8 or client+0xe98)
//   AL  = bool (1 eligible / 0 not)
//   RET 4
//
// RELATED
//   Sibling eval:     FUN_0059db80 @ 0x0059db80 (not dualled here)
//   Tracker bind:     Client_TryBindActiveMissionTracker @ 0x0092fd00
//   Tracker write:    Tracker_SetActiveMissionObjective @ 0x0092a590 (parent chain)
// =============================================================================

#include <cstdint>

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using i32 = std::int32_t;

struct ObjectiveTemplate {
  u32 id;                 // first dword; band-checked as [0xdfd, 0xe02]
  // ...
  // +0xf8: u16 gate_short
  // +0xfc: used by FUN_0059db80 default path
};

struct ObjectiveNode {
  // +0x10: key used by sibling hash walk
  // +0x14: u8 flag (must be non-zero when template gate_short != 0)
  // +0x14c: ObjectiveTemplate*
  // +0x120 / +0x158..+0x15c: used by FUN_0059db80
  u8  _pad_00[0x14];
  u8  flag_byte_14;
  u8  _pad_15[0x14c - 0x15];
  ObjectiveTemplate* template_at_14c;
};

struct Character;

// Sibling evaluator — returns -1 when objective is not ready / unmatched.
// Signature sealed at call site: thiscall ECX=node, stack=character, EAX=int.
extern "C" i32 __thiscall FUN_0059db80(ObjectiveNode* self, Character* character);

// Character multi-inheritance this-adjust + virtual @ +0x27c.
// Product English open (level/rank-like threshold 5 observed).
using CharVirtual_0x27c = i32 (__thiscall*)(void* adjusted_this);

static inline i32 CallCharacterVirtual_0x27c(Character* character)
{
  // Image:
  //   MOV EDX, [EDI+4]
  //   MOV EAX, [EDX+4]
  //   MOV EDX, [EAX+EDI+4]
  //   LEA ECX, [EAX+EDI+4]
  //   CALL [EDX+0x27c]
  auto* base = reinterpret_cast<u8*>(character);
  auto* p1   = *reinterpret_cast<u8**>(base + 4);
  auto* adj  = *reinterpret_cast<u8**>(p1 + 4) + reinterpret_cast<u32>(character) + 4;
  auto** vtbl = *reinterpret_cast<void***>(adj);
  auto* fn = reinterpret_cast<CharVirtual_0x27c>(vtbl[0x27c / 4]);
  return fn(adj);
}

// -----------------------------------------------------------------------------
// Exact CF
// -----------------------------------------------------------------------------
extern "C" u8 __thiscall ObjectiveNode_IsEligibleForTracker_Inferred(
    ObjectiveNode* self,
    Character* character)
{
  // fail: null character
  if (character == nullptr)
    return 0;

  ObjectiveTemplate* tmpl = self->template_at_14c;

  // fail: gated short@tmpl+0xf8 != 0 and node flag@+0x14 == 0
  // (offsets applied relative to live layout; see annotated)
  auto* tmpl_bytes = reinterpret_cast<u8*>(tmpl);
  u16 gate_short = *reinterpret_cast<u16*>(tmpl_bytes + 0xf8);
  if (gate_short != 0 && self->flag_byte_14 == 0)
    return 0;

  // fail: sibling evaluator returns -1
  i32 eval = FUN_0059db80(self, character);
  if (eval == -1)
    return 0;

  // special band: id in [0xdfd, 0xe02] inclusive
  // decompiler form 0xdfc < id && id < 0xe03 is integer-equivalent
  u32 id = tmpl->id;
  if (id >= 0xdfd && id <= 0xe02) {
    i32 v = CallCharacterVirtual_0x27c(character);
    if (v < 5)
      return 0;
  }

  return 1;
}

// Ghidra twin export name
extern "C" u8 __thiscall FUN_0059dc50(ObjectiveNode* self, Character* character)
{
  return ObjectiveNode_IsEligibleForTracker_Inferred(self, character);
}
