// =============================================================================
// ShopVehList_BindSlotFromListIndexIfMismatch_Inferred  (FUN_0083abf0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0083abf0
// Address:   0x0083abf0 – 0x0083ac89 inclusive (154 B / 0x9A); pad CC before parent
// System:    shopveh list UI — bind slot object to list-index entity if mismatch
// Generated: 2026-08-05 WQ9L-J dual seal (decompile + read_memory + assembly_context)
// Exactness: Behavior-preserving rewrite from body bytes / call-site context.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: When the five-slot reindex cannot refresh a window cell from an
// already-correct id (or cannot swap a donor), look up the entity for list_i
// in the host's nested list container and, if the slot is unbound or bound to
// a different entity id, call FUN_0083ab90 to bind/refresh (which finishes
// with ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred(flag=1)).
//
// Host layout (partial; shared with parent reindex):
//   +0x508  nested*     // must be non-null; +0x50 gate; +0x2c = list container
//   +0x50c  void* slots[5]
//
// Slot object (partial):
//   +0x508  nested*     // 0 → unbound
//   +0x50c  int         // bound entity id (compared to entity vtbl+0x1d4)
//
// ABI (bytes): ECX = slot index; EDX = list_i; stack host*; void; RET 4.

#include <cstdint>

// Residual
extern "C" uint8_t FUN_00427d20(/* EDI = list container */, uint32_t index,
                                void **out_entity);
extern "C" void FUN_0083ab90(/* ECX = slot_obj, EAX = entity_id, stack host */);

using GetEntityIdFn = int(__thiscall *)(void *self);

static int EntityId(void *entity)
{
  auto **vtbl = *reinterpret_cast<void ***>(entity);
  return reinterpret_cast<GetEntityIdFn>(vtbl[0x1d4 / 4])(entity);
}

extern "C" void ShopVehList_BindSlotFromListIndexIfMismatch_Inferred(
    int slot, int list_i, void *host)
{
  if (list_i < 0) {
    return;
  }

  auto *h = reinterpret_cast<uint8_t *>(host);
  void *nested = *reinterpret_cast<void **>(h + 0x508);
  if (nested == nullptr) {
    return;
  }
  if (slot < 0 || slot >= 5) {
    return;
  }

  void *slot_obj = reinterpret_cast<void **>(h + 0x50c)[slot];
  if (slot_obj == nullptr) {
    return;
  }
  if (*reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(nested) + 0x50) == 0) {
    return;
  }

  // assembly: EDI = nested + 0x2c  (container for FUN_00427d20)
  void *list_container = reinterpret_cast<uint8_t *>(nested) + 0x2c;
  void *entity = nullptr;
  if (FUN_00427d20(/* EDI = list_container */, static_cast<uint32_t>(list_i),
                   &entity) == 0) {
    return;
  }
  if (entity == nullptr) {
    return;
  }

  int id = EntityId(entity);
  if (id == 0) {
    return;
  }

  auto *s = reinterpret_cast<uint8_t *>(slot_obj);
  if (*reinterpret_cast<void **>(s + 0x508) != nullptr) {
    int bound = *reinterpret_cast<int *>(s + 0x50c);
    int id2 = EntityId(entity);
    if (bound == id2) {
      return; // already bound to this entity
    }
  }

  // third vtbl+0x1d4 leaves EAX = entity id for ab90
  int entity_id = EntityId(entity);
  FUN_0083ab90(/* ECX = slot_obj, EAX = entity_id, stack host */);
  (void)entity_id;
  (void)list_container;
}
