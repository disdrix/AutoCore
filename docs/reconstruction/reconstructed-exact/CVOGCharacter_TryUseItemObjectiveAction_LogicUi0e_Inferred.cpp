// =============================================================================
// CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005319d0
// Address:   0x005319d0  (autoassault.exe, image base 0x400000)
// Body:      0x005319d0–0x00531afd inclusive (302 B / 0x12E)
// System:    missions-progression
// Generated: 2026-08-05 R10-012 dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + image ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Character-side UseItem objective action helper for the ObjectEventDispatch
//   packet arm (event 9 + UseItem+0x34≠0):
//     1) If dual-base +0x7E is clear → skip validation and still notify UI
//     2) Else look up active objective by key at char+0x548; index into
//        evaluator vector; require type code 0x0C; RTTI cast to UseItem;
//        stage via residual FUN_00522b30(UseItem+0x34, COID×4, flag+0x3c)
//     3) On success path: pack LogicUI type 0x0E (key + sign-extend + index)
//        and Client_SendLogicUiPacket (queue this = dual-base + 0xE8B8)
//
// ABI:   __thiscall; ECX=character*; 6 stack dwords; ret 0x18; AL bool
// SOLE CALLER: CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred
//              (FUN_0060df70 @ 0x0060e04a) — parent clears AL after call
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall CNDHash_LookupByKey(void* hash, std::uint32_t key);

extern "C" void* __cdecl __RTDynamicCast(
    void* obj, long vfDelta, void* srcType, void* targetType, int isRef);

// Residual: stage use progress / channel on target object (product name open)
extern "C" std::uint8_t __thiscall FUN_00522b30(
    void* targetObj,
    std::uint32_t a0,
    std::uint32_t a1,
    std::uint32_t a2,
    std::uint32_t a3,
    std::uint8_t flag);

// ECX = LogicUI queue base (dual-base + 0xE8B8); packet on stack
extern "C" void __thiscall Client_SendLogicUiPacket(void* queueThis, void* packet);

// RTTI descriptors (image symbols; Ghidra names)
extern "C" void CVOGObjectiveRequirement_RTTI_Type_Descriptor;
extern "C" void CVOGObjectiveRequirement_UseItem_RTTI_Type_Descriptor;

// dual-base host = *( *( *(this+4)+4 ) + this + 0xA8 )
static std::uint8_t* DualBaseHost(void* thisCharacter)
{
  auto* base = reinterpret_cast<std::uint8_t*>(thisCharacter);
  int t1 = *reinterpret_cast<int*>(base + 4);
  int t2 = *reinterpret_cast<int*>(t1 + 4);
  return reinterpret_cast<std::uint8_t*>(
      *reinterpret_cast<int*>(t2 + 0xA8 + reinterpret_cast<std::uintptr_t>(base)));
}

// this = character*
// Returns AL: 1 on LogicUI send; 0 on validation fail (when +0x7E set).
std::uint8_t __thiscall CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred(
    void* thisCharacter,
    std::uint32_t objectiveKey,  // stack +0x04
    int reqIndex,                // stack +0x08
    std::uint32_t coid0,         // stack +0x0C  (caller: worldObj+0x160)
    std::uint32_t coid1,         // stack +0x10
    std::uint32_t coid2,         // stack +0x14
    std::uint32_t coid3)         // stack +0x18
// ret 0x18
{
  auto* base = reinterpret_cast<std::uint8_t*>(thisCharacter);
  std::uint8_t* dualHost = DualBaseHost(thisCharacter);

  if (dualHost[0x7E] != 0) {
    void* objDef = CNDHash_LookupByKey(
        *reinterpret_cast<void**>(base + 0x548), objectiveKey);
    if (objDef == nullptr) {
      return 0;
    }

    auto* def = reinterpret_cast<std::uint8_t*>(objDef);
    int count = 0;
    if (*reinterpret_cast<int*>(def + 0x158) != 0) {
      count = (*reinterpret_cast<int*>(def + 0x15c) -
               *reinterpret_cast<int*>(def + 0x158)) >> 2;
    }
    if (reqIndex >= count) {
      return 0;
    }

    int* req = *reinterpret_cast<int**>(
        *reinterpret_cast<int*>(def + 0x158) + reqIndex * 4);
    using TypeFn = int(__thiscall*)(int* self);
    auto typeCode = reinterpret_cast<TypeFn>(
        *reinterpret_cast<void**>(*reinterpret_cast<void**>(req) + 0x50))(req);
    if (typeCode != 0x0C) {
      return 0;
    }

    auto* useItem = reinterpret_cast<std::uint8_t*>(__RTDynamicCast(
        req, 0,
        &CVOGObjectiveRequirement_RTTI_Type_Descriptor,
        &CVOGObjectiveRequirement_UseItem_RTTI_Type_Descriptor,
        0));
    if (*reinterpret_cast<int*>(useItem + 0x34) == 0) {
      return 0;
    }

    std::uint8_t ok = FUN_00522b30(
        *reinterpret_cast<void**>(useItem + 0x34),
        coid0, coid1, coid2, coid3,
        *(useItem + 0x3c));
    if (ok == 0) {
      return 0;
    }
  }

  // LogicUI packet (0x138 family element) — type 0x0E, key pair, index
  // Stack offsets from decompiler: local_138 base; type @+0x1C; key @+0x20; hi @+0x24
  alignas(4) std::uint8_t packet[0x138]{};
  *reinterpret_cast<int*>(packet + 0x00) = reqIndex;
  *reinterpret_cast<std::uint32_t*>(packet + 0x1C) = 0x0E;
  *reinterpret_cast<std::uint32_t*>(packet + 0x20) = objectiveKey;
  *reinterpret_cast<std::int32_t*>(packet + 0x24) =
      static_cast<std::int32_t>(objectiveKey) >> 31;

  // Image: ADD ECX, 0xE8B8 on dual-base host; CALL Client_SendLogicUiPacket
  Client_SendLogicUiPacket(dualHost + 0xE8B8, packet);
  return 1;
}
