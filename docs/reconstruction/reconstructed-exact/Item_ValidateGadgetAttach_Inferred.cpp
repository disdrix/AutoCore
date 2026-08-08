// =============================================================================
// Item_ValidateGadgetAttach_Inferred  (FUN_00513400)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513400
// Address:   0x00513400–0x005134d4 inclusive (213 B / 0xD5)
// System:    inventory-transfer — gadget attach validation (type / slots / dup)
// Generated: 2026-08-05 MEGA-035 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Pure validator: can this Gadget* be attached to this host Item*?
//   Returns status codes consumed by UI hover mode-5 and apply-confirm paths.
//   No mutation, no network send.
//
// ABI: __thiscall; ECX = host Item*; stack = Gadget*; RET 4; EAX = 0..3.
//
// Return codes (caller-string sealed via dualed 0x0085ce20 / FUN_0085fa20):
//   0 = attach allowed
//   1 = "No gadget slots are available."
//   2 = "This is the wrong type of gadget to use on this item."
//   3 = "That gadget is already on the item, no duplicates allowed."
//
// Distinct from tinker-kit validator FUN_00513c10 (MEGA-036).
// Retire scaffold Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_*.
//
// Dual: reviews/A|B_aa_00513400_Item_ValidateGadgetAttach_Inferred.md

#include <cstdint>

// Opaque retail object shells — field layout only for plate readability.
struct ItemDefBlob {
  // +0x38: type id
  // +0x3c: ptr → subtype word at +0x3f4
  std::uint8_t _pad0[0x38];
  std::int32_t typeId;          // +0x38
  void*        subtypeHost;     // +0x3c  → short at +0x3f4
};

struct ItemVtable {
  std::uint8_t _pad[0x7c];
  // +0x7c: get installed gadget id at index (returns short in AX)
  std::uint32_t (__thiscall *GetInstalledGadgetIdAt)(void* self, std::uint32_t index);
  // +0x80: capacity / max gadget slots
  std::uint32_t (__thiscall *GetGadgetSlotCapacity)(void* self);
  std::uint8_t _pad8c[0x8];
  // +0x8c: used/occupied gadget slot count (returns short in AX)
  std::int16_t  (__thiscall *GetGadgetSlotsUsed)(void* self);
};

struct Item {
  ItemVtable* vtbl;             // +0x00
  std::uint8_t _pad[0xa4];
  ItemDefBlob* hostComp;        // +0xa8  (decomp param_1[0x2a])
};

// Gadget: only the ac-chain accesses used by this unit are modeled.
// Retail: type = *(*(*(g+4)+4) + g + 0xac)->+0x3c -> +0x4c4
//         id   = *(*(*(g+4)+4) + g + 0xac) + 0x34

// Helpers for the cloned-object +0xac chain (exact layout residual elsewhere).
static inline void* Gadget_AcNode(void* gadget)
{
  auto* g = reinterpret_cast<std::uint8_t*>(gadget);
  auto* p4 = *reinterpret_cast<std::uint8_t**>(g + 4);
  auto* p44 = *reinterpret_cast<std::uint8_t**>(p4 + 4);
  return *reinterpret_cast<void**>(p44 + reinterpret_cast<std::uintptr_t>(gadget) + 0xac);
}

static inline std::int32_t Gadget_TypeId(void* gadget)
{
  auto* ac = reinterpret_cast<std::uint8_t*>(Gadget_AcNode(gadget));
  auto* tmpl = *reinterpret_cast<std::uint8_t**>(ac + 0x3c);
  return *reinterpret_cast<std::int32_t*>(tmpl + 0x4c4);
}

static inline std::uint32_t Gadget_InstanceId(void* gadget)
{
  auto* ac = reinterpret_cast<std::uint8_t*>(Gadget_AcNode(gadget));
  return *reinterpret_cast<std::uint32_t*>(ac + 0x34);
}

static inline std::int16_t Host_SubtypeWord(ItemDefBlob* hostComp)
{
  auto* blob = reinterpret_cast<std::uint8_t*>(hostComp->subtypeHost);
  return *reinterpret_cast<std::int16_t*>(blob + 0x3f4);
}

// __thiscall RET 4
extern "C" std::uint32_t __thiscall Item_ValidateGadgetAttach_Inferred(
    Item* host,
    void* /*Gadget**/ gadget)
{
  const std::int32_t gadgetType = Gadget_TypeId(gadget);
  ItemDefBlob* hostComp = host->hostComp;

  if (gadgetType != hostComp->typeId) {
    if (gadgetType == 0x44) {
      if (Host_SubtypeWord(hostComp) == 10)
        goto ok;
    } else if (gadgetType == 0x46 && Host_SubtypeWord(hostComp) == 11) {
      goto ok;
    }
    return 2;
  }

ok:
  // Retail: MOVSX used; CALL capacity; SUB; JZ → return 1
  const std::int32_t used = static_cast<std::int32_t>(host->vtbl->GetGadgetSlotsUsed(host));
  const std::uint32_t cap = host->vtbl->GetGadgetSlotCapacity(host);
  if (used == static_cast<std::int32_t>(cap))
    return 1;

  const std::uint32_t gadgetId = Gadget_InstanceId(gadget);
  // Retail: XOR i; CALL capacity; JBE → return 0; do { …; ++i; CALL capacity } while (i < cap)
  std::uint32_t i = 0;
  if (host->vtbl->GetGadgetSlotCapacity(host) != 0) {
    do {
      const std::uint16_t slotId =
          static_cast<std::uint16_t>(host->vtbl->GetInstalledGadgetIdAt(host, i) & 0xffff);
      if (slotId == static_cast<std::uint16_t>(gadgetId & 0xffff))
        return 3;
      ++i;
    } while (i < host->vtbl->GetGadgetSlotCapacity(host));
  }
  return 0;
}

// Scaffold alias — Ghidra symbol
extern "C" std::uint32_t __thiscall FUN_00513400(Item* host, void* gadget)
{
  return Item_ValidateGadgetAttach_Inferred(host, gadget);
}
