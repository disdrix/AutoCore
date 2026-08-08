// =============================================================================
// Client_UI_RefreshInventoryWindows_Inferred  (FUN_00933310)
// -----------------------------------------------------------------------------
// Stable ID: aa_00933310
// Address:   0x00933310  (autoassault.exe, image base 0x400000)
// Body:      0x00933310 – 0x0093336f inclusive (96 B / 0x60)
// System:    inventory-transfer (UI map side-effect)
// Generated: 2026-08-05 MEGA-099 dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of disassembly ABI + CF.
//            Decompiler void(void) form is WRONG — bytes authority.
// Bit-for-bit vs retail EXE: DEFERRED
// Hash:      a04b98d42bef5dfd0234a2fbaae83339f2d6cccd70eb691f4bd712d07fe98c30
// Dual:      reviews/A_aa_00933310_Client_UI_RefreshInventoryWindows_Inferred.md
//            reviews/B_aa_00933310_Client_UI_RefreshInventoryWindows_Inferred.md
// =============================================================================
//
// PURPOSE
//   Thin pack-and-insert helper used after inventory item remove/use/tinker/
//   gadget mutations. Builds a value whose uint32 key is the item/object*
//   in EAX, folds five stack descriptor fields + CL flag, then insert-or-finds
//   into the client host map at **client+0xF14** via dualed
//   StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred (0x00402b30).
//
//   Not a window walk. Shared map shell with Client_NotifyActiveMissionChanged
//   (direct 00402b30 sites). Product English open → _Inferred.
//
// ABI (bytes authority)
//   EAX = item/object*     (value.key dword0)
//   CL  = u8 flag          (call sites: 0)
//   stack: client*, a1, a2, a3, a4   (sites: client, 1, 0, -1, -1)
//   void return; RET 0x14
//
// CALLEE
//   0x00402b30 StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred
//     EAX=map, EBX=value*, stack out pair, RET 4
//
// CALLERS (5 UNCONDITIONAL_CALL)
//   Client_RecvInventoryUseItemResponse @ 0x008102de
//   FUN_00810170                        @ 0x00810209
//   FUN_0080d570                        @ 0x0080d750, 0x0080d8d3
//   FUN_0080d930                        @ 0x0080daec
//
// REJECT
//   Named_CalleeOf_Client_RecvInventoryUseItemResponse_00933310 as product role
//   (shared map helper; multi-caller).
// =============================================================================

#include <cstdint>

struct MapShell_Isnil31;
struct InsertPair_Isnil31;

// Dual-sealed MEGA-040: EAX=map, EBX=value*, stack out, RET 4
extern "C" InsertPair_Isnil31 *StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred(
    MapShell_Isnil31 *map /*EAX*/,
    InsertPair_Isnil31 *out /*stack*/,
    const void *value /*EBX*/);

// Value layout reconstructed from stores (key @ +0 only compared by insert-or-find).
// Remaining fields are folded from stack args / CL and copied on insert miss.
struct InventoryRefreshMapValue {
  uint32_t key;       // +0x00  entry EAX (item/object* as uint)
  uint32_t _pad04;    // +0x04  (not written before CALL in this unit)
  uint32_t key_mirror;// +0x08  entry EAX again
  uint32_t pack_mid;  // +0x0C  lo byte=a1, next=CL, upper from local pack
  uint32_t a2;        // +0x10
  uint32_t from_local;// +0x14  from uninit [ESP_sub+0xc] — odd, preserved
  uint32_t a3;        // +0x18
  uint32_t a4;        // +0x1C
};

// Custom ABI: EAX + CL + 5 stack args; callee-cleaned RET 0x14.
// Modeled as free function; retail does not use ECX thiscall.
extern "C" void Client_UI_RefreshInventoryWindows_Inferred(
    /*EAX*/ void *itemOrObject,
    /*CL*/  uint8_t flag,
    /*stack*/ void *client,
    int a1,
    int a2,
    int a3,
    int a4)
{
  InventoryRefreshMapValue value{};
  InsertPair_Isnil31 out{};

  value.key = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(itemOrObject));
  value.key_mirror = value.key;

  // Pack a1 lo-byte and CL into mid dword (matches MOV [esp+4],DL / [esp+5],CL
  // then dword load). Upper bytes may carry residual stack noise.
  uint32_t pack = 0;
  reinterpret_cast<uint8_t *>(&pack)[0] = static_cast<uint8_t>(a1);
  reinterpret_cast<uint8_t *>(&pack)[1] = flag;
  value.pack_mid = pack;

  value.a2 = static_cast<uint32_t>(a2);
  // value.from_local: retail reads uninit local — leave zero in clean model
  // (document oddity; do not invent stack contents).
  value.a3 = static_cast<uint32_t>(a3);
  value.a4 = static_cast<uint32_t>(a4);

  auto *map = reinterpret_cast<MapShell_Isnil31 *>(
      reinterpret_cast<uint8_t *>(client) + 0xF14);

  // EAX=map, EBX=&value, stack=&out — insert-or-find; pair discarded.
  (void)StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred(map, &out, &value);
}
