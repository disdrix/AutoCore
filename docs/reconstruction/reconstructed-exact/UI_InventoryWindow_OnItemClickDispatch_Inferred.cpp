// =============================================================================
// UI_InventoryWindow_OnItemClickDispatch_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008612b0
// Address:   0x008612b0 – 0x00861676 exclusive (966 B / 0x3C6); RET 0x8 @ 0x00861673
//            autoassault.exe, image base 0x400000
// Wave:      OWN-ONLY dual gap-close 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + disassemble_function
//            + read_memory + RTTI string seals + dualed child records.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX = inventory window this*; two opaque stack formals; RET 0x8;
//            returns AL bool (1 handled / 0 reject)
// Install:   DATA xref vtable slot 0x00a64b00 (no code callers)
// Prior:     Ghidra FUN_008612b0; missing from inventory.jsonl (gap-close)
// =============================================================================
//
// PURPOSE:
//   Inventory-window UI virtual for selected-item click/use/equip/store:
//     1. Early path when global busy (+0xcd0) or no selected child (+0x4b8)
//     2. RTTI soft-cast selected CNDUIWindow → CWndInventoryItem
//     3. Branch on mode @ *(window+0x56c)+4  (1 / 3 / 4)
//     4. Store UI (DAT_00d1bdfa): IsWantedByStore gate or sell C2S 0x2027/0x40
//     5. Non-store: UseObject / special flag / use-by-coid / type 8|0x32 skill
//        target / equip leaf UI_InventoryWindow_TryEquipOrLockedToast_Inferred
//     6. Most success paths close via window->vtbl[+0x33c](0)
//
// REJECT:
//   - Claiming this is only the equip leaf (that is 0x00861200)
//   - Claiming code callers exist (vtable-only install)
//   - Merging with Client_SendInventoryEquipC2S / pure store drop helpers
//   - Product English without _Inferred
//   - Runtime Confirmed (no Launcher)
// =============================================================================

#include <cstdint>
#include <cstdio>

struct Window;
struct CWndInventoryItem;
struct Item;
struct Client;

// Dualed children
extern "C" std::uint8_t Item_IsWantedByStore_Inferred(Item* item /*ECX*/);
extern "C" void Client_SendSectorPacket(Client* client /*ECX*/,
                                        std::uint32_t size /*stack*/,
                                        void* packet /*stack*/);
// Dualed: EAX=item* entry in retail for UseObject path.
extern "C" void Client_SendUseObject_IfInteractable(Item* item /*EAX*/);
extern "C" std::uint8_t Client_UseInventoryItemByCoid(std::uint32_t coid_lo,
                                                     std::uint32_t coid_hi,
                                                     std::uint32_t mode);
// Dualed: EAX = prompt kind (4 or 5 observed); stack client* + flag.
extern "C" void Client_PromptSkillTargetSelect(Client* client, std::uint32_t flag);
// Dualed MEGA-125: ECX=item*, EAX=window*
extern "C" std::uint32_t UI_InventoryWindow_TryEquipOrLockedToast_Inferred(
    Item* item, Window* window);

extern "C" std::uint8_t FUN_0085f220(void* a, void* b, void* c);
extern "C" std::uint32_t FUN_00861280(CWndInventoryItem* item /*ECX*/);
extern "C" int FUN_00524520(Item* item);
extern "C" void FUN_0093a330(Item* item);
extern "C" void FUN_007fbb70(void);
extern "C" void* FUN_007a69d0(void);
extern "C" void* __thiscall FUN_007a6de0(void* locale, const char* text, int len);
extern "C" std::uint32_t FUN_007fdfb0(Client* client, void* msg, std::uint32_t a,
                                      std::uint32_t b, std::uint32_t c);
extern "C" void* __cdecl __RTDynamicCast(void* obj, int vfDelta, void* srcType,
                                         void* targetType, int isRef);

extern "C" Client DAT_00d1a840;
extern "C" int DAT_00d1b6d8;       // client world/session host*
extern "C" void* DAT_00d1b1f8;
extern "C" void* DAT_00d1b644;
extern "C" std::uint8_t DAT_00d1bdfa; // store-UI active flag
extern "C" void* DAT_00d1b89c;
extern "C" std::uint32_t DAT_00d1d938, DAT_00d1d93c; // type 0x32 TFID stash
extern "C" std::uint32_t DAT_00d1d940, DAT_00d1d944; // type 8 TFID stash

// RTTI type descriptors (image)
extern "C" char CNDUIWindow_RTTI;       // @ 0x00afe1ac family
extern "C" char CWndInventoryItem_RTTI; // @ 0x00aff3ac family

// thiscall-like: ECX = window*; two opaque stack formals; RET 0x8
extern "C" std::uint8_t UI_InventoryWindow_OnItemClickDispatch_Inferred(
    Window* self /*ECX*/)
{
  auto* win = reinterpret_cast<std::uint8_t*>(self);
  auto* host = *reinterpret_cast<std::uint8_t**>(&DAT_00d1b6d8);

  // Early: global busy @ host+0xcd0 OR no selected child @ window+0x4b8
  void* selected = *reinterpret_cast<void**>(win + 0x4b8);
  if (*reinterpret_cast<int*>(host + 0xcd0) != 0 || selected == nullptr) {
    std::uint8_t a = 0, b = 0;
    int out = 0;
    if (!FUN_0085f220(&a, &b, &out))
      return 0;
    if (out != 0 && DAT_00d1b1f8 != nullptr) {
      if (*reinterpret_cast<int*>(host + 0x250) == 0)
        return 0;
      void** vtbl = *reinterpret_cast<void***>(DAT_00d1b1f8);
      using V = void*(__thiscall*)(void*);
      reinterpret_cast<V>(vtbl[0x3ac / 4])(DAT_00d1b1f8);
    }
    return 1;
  }

  // Soft-cast selected UI child → CWndInventoryItem
  auto* inv_item = reinterpret_cast<CWndInventoryItem*>(
      __RTDynamicCast(selected, 0, &CNDUIWindow_RTTI, &CWndInventoryItem_RTTI, 0));
  if (inv_item == nullptr) {
    // fall through to close
  } else {
    void* mode_slot = *reinterpret_cast<void**>(win + 0x56c);
    std::uint32_t mode =
        *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(mode_slot) + 4);

    if (mode != 1) {
      if (mode != 3) {
        if (mode == 4) {
          if (*reinterpret_cast<int*>(host + 0xcd0) == 0 && selected != nullptr) {
            auto* cast_again = reinterpret_cast<CWndInventoryItem*>(
                __RTDynamicCast(selected, 0, &CNDUIWindow_RTTI,
                                &CWndInventoryItem_RTTI, 0));
            FUN_00861280(cast_again);
          }
          // close + return 1
          void** wvtbl = *reinterpret_cast<void***>(self);
          using CloseFn = void(__thiscall*)(Window*, int);
          reinterpret_cast<CloseFn>(wvtbl[0x33c / 4])(self, 0);
          return 1;
        }
        // unknown mode → close
        goto close_ok;
      }
      // mode 3 requires client flag @ DAT_00d1b644+0xf5
      if (*reinterpret_cast<std::uint8_t*>(
              *reinterpret_cast<std::uint8_t**>(&DAT_00d1b644) + 0xf5) == 0)
        return 0;
    }

    // Resolve backing game object from inventory-item widget
    void** ivtbl = *reinterpret_cast<void***>(inv_item);
    using ResolveFn = Item*(__thiscall*)(CWndInventoryItem*);
    Item* item = reinterpret_cast<ResolveFn>(ivtbl[0x3ac / 4])(inv_item);
    if (item == nullptr)
      goto close_ok;

    auto* itemb = reinterpret_cast<std::uint8_t*>(item);
    void* type_block = *reinterpret_cast<void**>(itemb + 0xa8); // [0x2a]
    auto* tb = reinterpret_cast<std::uint8_t*>(type_block);

    // ---------- STORE UI ----------
    if (DAT_00d1bdfa != 0) {
      if (*reinterpret_cast<int*>(tb + 0x38) == 4)
        return 0;
      if (DAT_00d1b89c == nullptr)
        return 0;
      {
        void** sv = *reinterpret_cast<void***>(DAT_00d1b89c);
        using GateFn = std::uint8_t(__thiscall*)(void*);
        if (!reinterpret_cast<GateFn>(sv[0x3d8 / 4])(DAT_00d1b89c))
          return 0;
      }
      if (!Item_IsWantedByStore_Inferred(item)) {
        void* locale = FUN_007a69d0();
        if (locale == nullptr)
          return 0;
        void* msg = FUN_007a6de0(locale, "The store does not want that item.", -1);
        char buf[128];
        std::sprintf(buf, "%s", reinterpret_cast<const char*>(msg));
        // Bytes: MOV EAX,0x4e24 before FUN_007fdfb0
        FUN_007fdfb0(&DAT_00d1a840, buf, 0xffffffffu, 1, 0);
        return 0;
      }

      // StoreTransactionRequest: opcode 0x2027, size 0x40, IsBuy=0 (sell)
      alignas(4) std::uint8_t packet[0x40]{};
      *reinterpret_cast<std::uint32_t*>(packet + 0x00) = 0x2027;
      // retail also fills TFID @ +0x18 from item+0x160 and qty/store fields via
      // item->vtbl[+0x25c] into packet trailing slots — preserve structure:
      void** item_vt = *reinterpret_cast<void***>(item);
      using QtyFn = std::uint32_t(__thiscall*)(Item*);
      std::uint32_t qty_or_flags = reinterpret_cast<QtyFn>(item_vt[0x25c / 4])(item);
      // TFID copy item+0x160 (16B)
      for (int i = 0; i < 4; ++i)
        *reinterpret_cast<std::uint32_t*>(packet + 0x18 + i * 4) =
            *reinterpret_cast<std::uint32_t*>(itemb + 0x160 + i * 4);
      *reinterpret_cast<std::uint8_t*>(packet + 0x38) = 0; // IsBuy = sell
      *reinterpret_cast<std::uint32_t*>(packet + 0x3c) = qty_or_flags;
      // Client_SendSectorPacket: ECX=client, size=0x40, buf=packet
      // retail also sets EAX channel-ish 8 before CALL
      Client_SendSectorPacket(&DAT_00d1a840, 0x40, packet);
      return 1;
    }

    // ---------- NON-STORE ----------
    void* tmpl = *reinterpret_cast<void**>(tb + 0x3c);
    auto* tm = reinterpret_cast<std::uint8_t*>(tmpl);
    if (*reinterpret_cast<std::int16_t*>(tm + 0x3f4) == 8)
      return 1;

    if (FUN_00524520(item) != 0) {
      Client_SendUseObject_IfInteractable(item);
      void** wvtbl = *reinterpret_cast<void***>(self);
      using CloseFn = void(__thiscall*)(Window*, int);
      reinterpret_cast<CloseFn>(wvtbl[0x33c / 4])(self, 0);
      return 1;
    }

    std::uint32_t flags = *reinterpret_cast<std::uint32_t*>(itemb + 0x17c);
    if (((flags >> 0x13) & 1u) != 0) {
      FUN_0093a330(item);
      void** wvtbl = *reinterpret_cast<void***>(self);
      using CloseFn = void(__thiscall*)(Window*, int);
      reinterpret_cast<CloseFn>(wvtbl[0x33c / 4])(self, 0);
      return 1;
    }

    if ((tm[0x3f2] & 0x80) != 0) {
      std::uint32_t lo = *reinterpret_cast<std::uint32_t*>(itemb + 0x160);
      std::uint32_t hi = *reinterpret_cast<std::uint32_t*>(itemb + 0x164);
      if (Client_UseInventoryItemByCoid(lo, hi, mode)) {
        FUN_007fbb70();
        void** wvtbl = *reinterpret_cast<void***>(self);
        using CloseFn = void(__thiscall*)(Window*, int);
        reinterpret_cast<CloseFn>(wvtbl[0x33c / 4])(self, 0);
        return 1;
      }
    } else {
      int type = *reinterpret_cast<int*>(tb + 0x38);
      if (type == 8) {
        DAT_00d1d940 = *reinterpret_cast<std::uint32_t*>(itemb + 0x160);
        DAT_00d1d944 = *reinterpret_cast<std::uint32_t*>(itemb + 0x164);
        // retail: MOV EAX,5 before CALL Client_PromptSkillTargetSelect
        Client_PromptSkillTargetSelect(&DAT_00d1a840, 0);
        void** wvtbl = *reinterpret_cast<void***>(self);
        using CloseFn = void(__thiscall*)(Window*, int);
        reinterpret_cast<CloseFn>(wvtbl[0x33c / 4])(self, 0);
        return 1;
      }
      if (type == 0x32) {
        DAT_00d1d938 = *reinterpret_cast<std::uint32_t*>(itemb + 0x160);
        DAT_00d1d93c = *reinterpret_cast<std::uint32_t*>(itemb + 0x164);
        // retail: MOV EAX,4 before CALL
        Client_PromptSkillTargetSelect(&DAT_00d1a840, 0);
        void** wvtbl = *reinterpret_cast<void***>(self);
        using CloseFn = void(__thiscall*)(Window*, int);
        reinterpret_cast<CloseFn>(wvtbl[0x33c / 4])(self, 0);
        return 1;
      }
      // Default equip path — dualed leaf (ECX=item, EAX=window)
      UI_InventoryWindow_TryEquipOrLockedToast_Inferred(item, self);
    }
  }

close_ok:
  {
    void** wvtbl = *reinterpret_cast<void***>(self);
    using CloseFn = void(__thiscall*)(Window*, int);
    reinterpret_cast<CloseFn>(wvtbl[0x33c / 4])(self, 0);
  }
  return 1;
}
