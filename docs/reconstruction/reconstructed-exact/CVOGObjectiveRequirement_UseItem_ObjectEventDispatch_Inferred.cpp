// =============================================================================
// CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060df70
// Address:   0x0060df70  (autoassault.exe, image base 0x400000)
// Body:      0x0060df70–0x0060e06a inclusive (251 B / 0xFB)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-038 dual seal (live Ghidra decompile + disassemble + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + image ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   CVOGObjectiveRequirement_UseItem virtual method (vtbl +0x04): dispatch on
//   object-use events **9** and **10** only.
//     1) Skip if Eval (vtbl+8) already complete
//     2) Optional req+0x54 character-field gate
//     3) MatchTargetCore(charCtx, worldObj)
//     4a) event==10 OR req+0x34==0 → ApplyObjectUseProgress (return its AL)
//     4b) event==9 AND req+0x34≠0 → find self in parent objective vector;
//         FUN_005319d0(mission key + index + world COID); then return 0
//
// CLASS: CVOGObjectiveRequirement_UseItem (RTTI via vtable PTR_FUN_009dfc1c)
// ABI:   __thiscall; ECX=this; 7 stack dwords; ret 0x1C; AL status
//        (slots +0x10,+0x14,+0x18 unread in this body but cleaned by RET)
//
// CALLEES:
//   [vtbl+8] Eval
//   FUN_0060d460  CVOGObjectiveRequirement_UseItem_MatchTargetCore
//   FUN_0060d630  CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress
//   FUN_005319d0  LogicUi / UseItem confirm packet helper (local + cast UseItem)
// =============================================================================

#include <cstdint>

// Sibling duals / named callees (external linkage as in image)
extern "C" std::uint8_t __thiscall
CVOGObjectiveRequirement_UseItem_MatchTargetCore(void* self, void* charCtx, void* worldObj);

extern "C" std::uint8_t __thiscall
CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress(
    void* self, void* charCtx, void* progress, void* worldObj);

// ECX = charCtx; stack: missionKey, reqIndex, coid0..coid3 (image builds 16 B from obj+0x160)
extern "C" std::uint8_t __thiscall
FUN_005319d0(
    void* charCtx,
    std::uint32_t missionKey,
    int reqIndex,
    std::uint32_t coid0,
    std::uint32_t coid1,
    std::uint32_t coid2,
    std::uint32_t coid3);

struct UseItemReq {
  void** vtbl;                 // +0x00
  std::uint8_t* parent;        // +0x04  mission / objective host
  std::uint8_t  _pad08[0x2C];  // +0x08 .. +0x33
  std::int32_t  flag_34;       // +0x34  0 → direct Apply; ≠0 + event9 → packet
  std::uint8_t  _pad38[0x1C];  // +0x38 .. +0x53
  std::int32_t  field_54;      // +0x54  optional char field; -1 skip
};

// this = UseItem requirement*
// Returns AL: Apply path forwards Apply AL; all other exits 0.
std::uint8_t __thiscall CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred(
    UseItemReq* self,
    void* charCtx,       // stack +0x04
    void* progress,      // stack +0x08
    int eventId,         // stack +0x0C  (9 or 10)
    std::uint32_t /*a4*/,// stack +0x10  unread
    std::uint32_t /*a5*/,// stack +0x14  unread
    std::uint32_t /*a6*/,// stack +0x18  unread
    void* worldObj)      // stack +0x1C
// ret 0x1C
{
  if (eventId != 9 && eventId != 10) {
    return 0;
  }

  // Eval not yet complete (vtbl +8)
  using EvalFn = char(__thiscall*)(UseItemReq*, void*, void*);
  char done = reinterpret_cast<EvalFn>(self->vtbl[2])(self, charCtx, progress);
  if (done != 0) {
    return 0;
  }

  // Optional req+0x54 vs character MI field +0xFC
  if (self->field_54 != -1) {
    int base = *reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(charCtx) + 4) + 4);
    auto* mi = *reinterpret_cast<std::uint8_t**>(base + 0xA8 + reinterpret_cast<int>(charCtx));
    if (*reinterpret_cast<std::int32_t*>(mi + 0xFC) != self->field_54) {
      return 0;
    }
  }

  if (CVOGObjectiveRequirement_UseItem_MatchTargetCore(self, charCtx, worldObj) == 0) {
    return 0;
  }

  // Direct apply arm
  if (eventId == 10 || self->flag_34 == 0) {
    return CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress(
        self, charCtx, progress, worldObj);
  }

  // Event 9 + flag: index self in parent objective pointer vector, fire packet helper
  auto* parent = self->parent;
  auto* begin = *reinterpret_cast<UseItemReq***>(parent + 0x158);
  int count = 0;
  if (begin != nullptr) {
    auto* end = *reinterpret_cast<UseItemReq***>(parent + 0x15C);
    count = static_cast<int>(end - begin);  // image: (end-begin) >> 2 as byte diff/4
  }

  int index = 0;
  for (;;) {
    if (index >= count) {
      return 0;
    }
    if (begin[index] == self) {
      break;
    }
    ++index;
  }

  // Image has CMP index,-1 after break (unreachable for non-negative index); still call
  if (index != -1) {
    auto* coid = reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<char*>(worldObj) + 0x160);
    std::uint32_t missionKey = *reinterpret_cast<std::uint32_t*>(parent + 0x10);
    FUN_005319d0(charCtx, missionKey, index, coid[0], coid[1], coid[2], coid[3]);
  }

  // Shared fail/clean epilogue: always AL=0 after packet path
  return 0;
}
