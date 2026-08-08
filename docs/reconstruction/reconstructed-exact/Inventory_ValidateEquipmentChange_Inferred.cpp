// =============================================================================
// Inventory_ValidateEquipmentChange_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Pre-flight gate for unequip / hardpoint-grab transfers.
//           Returns a multi-code equipment-change status used by UI
//           FUN_00931db0. Includes free-space probe (code 2) plus
//           arena / town / hazard / swap / equip-location checks.
//
// Address:  0x004f6a80  (autoassault.exe, image base 0x400000)
// Stable:   aa_004f6a80
// System:   inventory-transfer
// Size:     0x452 bytes (0x004f6a80..0x004f6ed1 inclusive); pad CC after
//
// Convention: MSVC __thiscall
//   ECX     = inventory host (callers: *[DAT_00d1b6d8 + 0x250])
//   stack0  = item object*  (null → 8)
//   EAX     = uint32 status
//   ret 4
//
// Status codes emitted here (mapped by residual 0x00931db0):
//   0  OK
//   1  town-only change
//   2  not enough inventory space   ← InventoryGrid_FindFreeForItem fail
//   8  cannot equip / no match
//   0xa must swap directly
//   0xd hazard mode
//   0xf arena lock
//
// Callees:
//   InventoryGrid_FindFreeForItem  0x005714e0  (ECX = this+0x2b0)
//   __RTDynamicCast                0x004898a4  (type 6 only)
//   FUN_004ce5f0                   0x004ce5f0  (type 0xe only)
//
// Callers (2):
//   Client_SendInventoryUnequip          0x00862c00 @ 0x00862c4c
//   Client_SendInventoryGrab_Hardpoint   0x00862d90 @ 0x00862dd5
//
// Partition hint Inventory_HasSpaceForItem = ret-2 path only; full unit is
// multi-code equipment-change validation → _Inferred name.
//
// Dual: reviews/A|B_aa_004f6a80_Inventory_ValidateEquipmentChange_Inferred.md
// Exactness: Behavior-preserving rewrite of decompiler CF + asm-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================

#include <cstdint>

struct InventoryHost;
struct ItemObject;

// Forward (dualed elsewhere)
extern "C" uint32_t __thiscall InventoryGrid_FindFreeForItem(
    void* grid, void* item, uint8_t* outX, uint8_t* outY,
    char allowStackMerge, int pageIndex);
extern "C" void* __cdecl __RTDynamicCast(void* in, int vfDelta,
    void* srcType, void* targetType, int isRef);
extern "C" bool __thiscall FUN_004ce5f0(void* a, void* inv /*see asm*/);

// RTTI descriptors (addresses from live decompile)
extern "C" void CVOGClonedObjectBase_RTTI;
extern "C" void CVOGSimpleObject_CVOGGraphicsBase_RTTI;

static inline void* adj_base(void* obj) {
  auto* p = reinterpret_cast<uint8_t*>(obj);
  int off = *reinterpret_cast<int*>(*reinterpret_cast<int*>(p + 4) + 4);
  return p + off;
}

static inline bool tfid_eq(void* a, void* b) {
  auto* aa = reinterpret_cast<uint8_t*>(adj_base(a));
  auto* bb = reinterpret_cast<uint8_t*>(adj_base(b));
  return *reinterpret_cast<int*>(aa + 0x164) == *reinterpret_cast<int*>(bb + 0x164)
      && *reinterpret_cast<int*>(aa + 0x168) == *reinterpret_cast<int*>(bb + 0x168);
}

static inline void* inv_state_a8(void* inv) {
  auto* p = reinterpret_cast<uint8_t*>(inv);
  int off = *reinterpret_cast<int*>(*reinterpret_cast<int*>(p + 4) + 4);
  return *reinterpret_cast<void**>(p + off + 0xa8);
}

// Exact CF from Ghidra decompile + disassemble_function (MEGA-056).
uint32_t __thiscall Inventory_ValidateEquipmentChange_Inferred(
    InventoryHost* inv,
    ItemObject* item)
{
  if (item == nullptr)
    return 8;

  void* state = inv_state_a8(inv);
  if (state != nullptr && *reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(state) + 0xf6) != 0)
    return 0xf;

  // Scratch outs (decompiler uStack_4 / param_2 reuse); values unused by callers
  // when only the bool result is tested.
  uint8_t outX = 0, outY = 0;
  void* grid = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(inv) + 0x2b0);
  // Live asm: MOV ECX,[EDI+0x2b0]; CALL 0x005714e0
  if (!InventoryGrid_FindFreeForItem(grid, item, &outX, &outY, 1, -1))
    return 2;

  auto* it = reinterpret_cast<uint8_t*>(item);
  int type = *reinterpret_cast<int*>(*reinterpret_cast<int*>(it + 0xa8) + 0x38);

  if (type == 0xc) {
    auto** vt = *reinterpret_cast<void***>(item);
    using Vfn = void* (__thiscall*)(void*);
    void* related = reinterpret_cast<Vfn>(vt[0x1e0 / 4])(item);
    auto* rel = reinterpret_cast<uint8_t*>(adj_base(related));
    void* clone = nullptr;
    if (*reinterpret_cast<void**>(rel + 0xac) != nullptr)
      clone = *reinterpret_cast<void**>(
          *reinterpret_cast<uint8_t**>(rel + 0xac) + 0x3c);
    if (clone != nullptr && *reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(clone) + 0x3f4) == 9) {
      void* slot = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(inv) + 0x264);
      if (slot != nullptr && tfid_eq(related, slot))
        return 0;
    } else {
      // flags from related object (EAX after vtbl call) +0xc4
      uint8_t flags = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(related) + 0xc4);
      void** arr = *reinterpret_cast<void***>(reinterpret_cast<uint8_t*>(inv) + 0x260);
      void* slot = nullptr;
      if (flags & 2)
        slot = arr[0];
      else if (flags & 0x10)
        slot = arr[1];
      else if (flags & 4)
        slot = arr[2];
      if (slot != nullptr && tfid_eq(related, slot))
        return 0;
    }
  } else if (type == 0x1c) {
    auto** vt = *reinterpret_cast<void***>(item);
    using Vfn = void* (__thiscall*)(void*);
    void* related = reinterpret_cast<Vfn>(vt[0x1f8 / 4])(item);
    void* slot = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(inv) + 0x254);
    if (slot != nullptr && tfid_eq(related, slot))
      return 0;
  } else if (type == 0xa) {
    auto** vt = *reinterpret_cast<void***>(item);
    using Vfn = void* (__thiscall*)(void*);
    void* related = reinterpret_cast<Vfn>(vt[0x1f4 / 4])(item);
    void* slot = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(inv) + 0x268);
    if (slot != nullptr && tfid_eq(related, slot))
      return 0;
  } else if (type == 0x10) {
    auto** vt = *reinterpret_cast<void***>(item);
    using Vfn = void* (__thiscall*)(void*);
    void* related = reinterpret_cast<Vfn>(vt[0x1f0 / 4])(item);
    void* slot = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(inv) + 0x258);
    if (slot != nullptr && tfid_eq(related, slot)) {
      state = inv_state_a8(inv);
      if (state != nullptr && *reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(state) + 0xf5) != 0)
        return 0;
      return 1;
    }
  } else if (type == 6) {
    void* casted = __RTDynamicCast(
        item, 0,
        &CVOGClonedObjectBase_RTTI,
        &CVOGSimpleObject_CVOGGraphicsBase_RTTI,
        0);
    int16_t sub = *reinterpret_cast<int16_t*>(
        *reinterpret_cast<uint8_t**>(*reinterpret_cast<int*>(it + 0xa8) + 0x3c) + 0x3f4);
    if (sub == 10) {
      void* slot = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(inv) + 0x26c);
      if (slot != nullptr && tfid_eq(casted, slot))
        return 0;
    } else if (sub == 11) {
      void* slot = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(inv) + 0x270);
      if (slot != nullptr && tfid_eq(casted, slot)) {
        // host secondary vtbl at adj(inv)+4 → call +0x210(0) twice (exact CF)
        auto* base = reinterpret_cast<uint8_t*>(inv);
        int off = *reinterpret_cast<int*>(*reinterpret_cast<int*>(base + 4) + 4);
        auto** hvt = *reinterpret_cast<void***>(base + off + 4);
        using Hfn = void* (__thiscall*)(void*, int);
        void* h = reinterpret_cast<Hfn>(hvt[0x210 / 4])(base + off + 4, 0);
        if (h == nullptr)
          return 0;
        h = reinterpret_cast<Hfn>(hvt[0x210 / 4])(base + off + 4, 0);
        if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(h) + 0x6b8) == 0)
          return 0;
        return 0xd;
      }
    }
  } else if (type == 0xe) {
    if (inv_state_a8(inv) == nullptr)
      return 1;
    // asm: PUSH EDI; CALL 0x004ce5f0  (thiscall-ish on inv)
    if (!FUN_004ce5f0(inv, inv))
      return 1;
    return 0xa;
  }

  return 8;
}
