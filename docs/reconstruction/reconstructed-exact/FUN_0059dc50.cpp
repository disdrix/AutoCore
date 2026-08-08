// =============================================================================
// FUN_0059dc50  (Ghidra twin of ObjectiveNode_IsEligibleForTracker_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0059dc50
// Address:   0x0059dc50–0x0059dcb9 inclusive (106 B / 0x6A)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression
// Sealed:    2026-08-05 MEGA-025 dual
// Canonical: ObjectiveNode_IsEligibleForTracker_Inferred
// Exactness: Behavior-preserving rewrite of image control flow. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using i32 = std::int32_t;

// Prefer the named clean source for documentation:
//   reconstructed-exact/ObjectiveNode_IsEligibleForTracker_Inferred.cpp
// This twin keeps the Ghidra symbol for xref continuity.

struct ObjectiveNode;
struct Character;

extern "C" i32 __thiscall FUN_0059db80(ObjectiveNode* self, Character* character);

extern "C" u8 __thiscall FUN_0059dc50(ObjectiveNode* self /*ECX*/, Character* character /*stack*/)
{
  i32 eval;

  if (character == nullptr)
    return 0;

  // template* @ this+0x14c
  auto* node_bytes = reinterpret_cast<u8*>(self);
  auto* tmpl = *reinterpret_cast<u8**>(node_bytes + 0x14c);

  // if short@tmpl+0xf8 != 0 && byte@this+0x14 == 0 → false
  if (*reinterpret_cast<u16*>(tmpl + 0xf8) != 0 &&
      *(node_bytes + 0x14) == 0) {
    return 0;
  }

  eval = FUN_0059db80(self, character);
  if (eval == -1)
    return 0;

  // template id = first dword; inclusive band [0xdfd, 0xe02]
  u32 id = *reinterpret_cast<u32*>(tmpl);
  if (id >= 0xdfd && id <= 0xe02) {
    // character this-adjust + virtual +0x27c
    auto* p1  = *reinterpret_cast<u8**>(reinterpret_cast<u8*>(character) + 4);
    auto* adj = *reinterpret_cast<u8**>(p1 + 4) +
                reinterpret_cast<u32>(character) + 4;
    auto** vtbl = *reinterpret_cast<void***>(adj);
    using Fn = i32 (__thiscall*)(void*);
    i32 v = reinterpret_cast<Fn>(vtbl[0x27c / 4])(adj);
    if (v < 5)
      return 0;
  }

  return 1;
}
