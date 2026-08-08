// =============================================================================
// UI_InventoryWindow_TryEquipOrLockedToast_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00861200
// Address:   0x00861200 – 0x00861254 exclusive (84 B / 0x54); RET @ 0x00861253
//            autoassault.exe, image base 0x400000
// Wave:      MEGA-125 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + disassemble_function
//            + read_memory + parent call site (FUN_008612b0 @ 0x008612b0) + dualed
//            Client_ConfirmEquipOrCustomizeItem (0x00941b20).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX = item*; EAX = inventory window* (custom dual-register; NOT
//            MSVC __fastcall ECX/EDX); bare RET;
//            success returns ConfirmEquip result; fail returns 0 (AL)
// Parent:    FUN_008612b0 inventory window command (hint: OnEquipCommand)
// Prior scaffolds: FUN_00861200,
//                  Inv_This_equipment_cannot_be_changed_at_this_time_00861200
// =============================================================================
//
// PURPOSE:
//   UI equip gate for the inventory window equip path:
//     if item* and window->slot@+0x56c are live:
//       mode = *(slot+4)
//       resolved = item->vtbl[+0x3ac](mode, 1)   // caller-clean stack args
//       return Client_ConfirmEquipOrCustomizeItem(
//                EAX=&DAT_00d1a840, stack: resolved, mode, confirmFlag=1)
//     else:
//       toast "This equipment cannot be changed at this time." (chrome 0x4e24)
//       return 0
//
// REJECT:
//   - Claiming this IS the full window OnEquip command (that is FUN_008612b0)
//   - Claiming this emits C2S equip opcodes directly (child ConfirmEquip does)
//   - ECX = window thiscall (ECX is item*; window is EAX)
//   - Always-toast / always-fail (success path is real)
// =============================================================================

#include <cstdint>

struct Item;
struct InventoryWindow;
struct Client;

// Dualed aa_00941b20:
//   EAX = client*
//   stack = item*, mode, confirmFlag
//   RET 0xC
// Declared here as a free function; call site must load EAX = client.
extern "C" std::uint32_t Client_ConfirmEquipOrCustomizeItem(Item* item,
                                                            std::uint32_t mode,
                                                            std::uint32_t confirm_flag);

extern "C" void* FUN_007a69d0(void);
extern "C" void* __thiscall FUN_007a6de0(void* locale /*ECX*/, const char* text,
                                         int len_or_neg1);
// Bytes: EAX = chrome/dialog id (here 0x4e24); stack includes client* + string*.
extern "C" std::uint32_t FUN_007fdfb0(Client* client, void* localized,
                                      std::uint32_t a, std::uint32_t b,
                                      std::uint32_t c);

extern "C" Client DAT_00d1a840;

// Custom dual-register entry (bytes):
//   ECX = item*
//   EAX = inventory window*   // parent: MOV ECX,EBX; MOV EAX,EDI; CALL
// Not portable as MSVC __fastcall (that uses EDX for arg2).
extern "C" std::uint32_t UI_InventoryWindow_TryEquipOrLockedToast_Inferred(
    Item* item /*ECX*/, InventoryWindow* window /*EAX*/)
{
  if (item != nullptr) {
    // window+0x56c → mode/state object*; +4 → mode dword (parent uses 1/3/4).
    auto* win_b = reinterpret_cast<std::uint8_t*>(window);
    void* slot = *reinterpret_cast<void**>(win_b + 0x56c);
    if (slot != nullptr) {
      std::uint32_t mode = *reinterpret_cast<std::uint32_t*>(
          reinterpret_cast<std::uint8_t*>(slot) + 4);

      // item->vtbl[+0x3ac](mode, 1) — resolve related object.
      // Stack args left for ConfirmEquip (caller-clean virtual; see raw re-verify).
      void** vtbl = *reinterpret_cast<void***>(item);
      using ResolveFn =
          Item*(__thiscall*)(Item* self, std::uint32_t mode, std::uint32_t flag);
      auto resolve = reinterpret_cast<ResolveFn>(vtbl[0x3ac / 4]);
      Item* resolved = resolve(item, mode, 1);

      // Bytes: PUSH resolved; MOV EAX,&DAT_00d1a840; CALL FUN_00941b20
      // ConfirmEquip consumes stack item*/mode/confirmFlag (RET 0xC).
      return Client_ConfirmEquipOrCustomizeItem(resolved, mode,
                                                /*confirm_flag=*/1);
      // Note: retail loads EAX=&DAT_00d1a840 immediately before the CALL;
      // a bit-exact port must set that register (not expressible portably here).
    }
  }

  // Locked / missing item or mode slot — user-facing block toast.
  void* locale = FUN_007a69d0();
  void* msg =
      FUN_007a6de0(locale, "This equipment cannot be changed at this time.", -1);
  // Bytes: MOV EAX,0x4e24 before CALL FUN_007fdfb0
  FUN_007fdfb0(&DAT_00d1a840, msg, 0xffffffffu, 1, 0);
  return 0;
}
