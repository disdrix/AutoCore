// =============================================================================
// Character_GiveItemByCbid_Inventory_Inferred  (FUN_005310a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005310a0
// Address:   0x005310a0–0x00531247 inclusive (424 B / 0x1A8)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression / inventory-transfer
// Generated: 2026-08-05 MEGA-003 dual seal
//            (decompile_function + disassemble_function + read_memory + callers/xrefs)
// Exactness: Behavior-preserving rewrite from assembly + decompile.
//            Decompiler surface alone is NOT authoritative for arity / loop.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed)
// =============================================================================
//
// PURPOSE: Character-side **give N items by CBID into inventory**.
//   1. Gate on character readiness flag at +0x7e (clear → return true, no grant).
//   2. For remaining = count down to 0:
//        factory CVOGReaction_GiveItemByCbid(cbid, 0)
//        init item (vtbl+8), stamp 64-bit serial from char+0xe6e0 via FUN_00512160
//        zero-pose transform (g_flOne), owner hooks (vtbl+0x2a4/+0x218)
//        first-item bind/trade gate FUN_00513e70 may collapse remaining to 1
//        Client_SendInventoryAddItem(this, item, flag)
//   3. Factory null → log "Invalid CBID: %d (bad item)" @ 0x009cfea4 → return false.
//
// Parents: CVOGObjectiveRequirement_UseItem_InitActive (0x0060d540),
//          FUN_0060d630 (UseItem progress), craft/outpost/objective grant helpers.
// Factory (no bag insert): dualed CVOGReaction_GiveItemByCbid (0x0051a170).
// Packet path: Client_SendInventoryAddItem (0x00530df0).
//
// ABI (assembly sealed):
//   __thiscall ECX = character dual-base this
//   stack: int cbid, int count
//   RET 8  (C2 08 00)
//   AL bool (1 success / 0 invalid cbid)
//
// Retired scaffold name:
//   Named_CalleeOf_CVOGObjectiveRequirement_UseItem_InitActive_005310a0
//
// =============================================================================

#include <cstdint>

// Dualed / named peers (declarations for readability only).
extern "C" void *__cdecl CVOGReaction_GiveItemByCbid(int cbid, int unused_zero);
extern "C" void __thiscall FUN_00512160(void *item, std::uint32_t lo,
                                        std::uint32_t hi, std::uint8_t flag);
extern "C" std::uint8_t __fastcall FUN_00513e70(void *item);
extern "C" void __thiscall Client_SendInventoryAddItem(void *character,
                                                       void *item,
                                                       std::uint32_t flag);
extern "C" unsigned __cdecl FUN_007a4480(int level, const char *fmt, ...);

// g_flOne @ 0x00a0f2a0 = 1.0f
static constexpr float k_g_flOne = 1.0f;

// Resolve character* from dual-base this: *( *(this+4)+4 ) + 0xa8 + this
static inline void *dual_base_character(void *this_char)
{
  auto *base = *reinterpret_cast<std::uint8_t **>(
      *reinterpret_cast<std::int32_t *>(
          *reinterpret_cast<std::int32_t *>(
              reinterpret_cast<std::uint8_t *>(this_char) + 4) +
          4) +
      0xa8 + reinterpret_cast<std::intptr_t>(this_char));
  return base;
}

// __thiscall: ECX = this_char; stack cbid, count; RET 8; AL bool
extern "C" std::uint8_t __thiscall Character_GiveItemByCbid_Inventory_Inferred(
    void *this_char, int cbid, int count)
{
  void *character = dual_base_character(this_char);

  // Early success if readiness flag at character+0x7e is clear.
  if (*reinterpret_cast<std::uint8_t *>(
          reinterpret_cast<std::uint8_t *>(character) + 0x7e) == 0) {
    return 1;
  }

  int remaining = count;
  std::uint8_t first = 0;
  // Assembly reuses the original count stack slot as inventory notify flag.
  std::uint32_t inv_flag = static_cast<std::uint32_t>(count);

  do {
    // cdecl GiveItemByCbid(cbid, 0) — factory only.
    void *item = CVOGReaction_GiveItemByCbid(cbid, /*unused_zero=*/0);
    if (item == nullptr) {
      FUN_007a4480(1, "Invalid CBID: %d (bad item)", cbid);
      return 0;
    }

    character = dual_base_character(this_char);

    // item->vtbl[+0x08](cbid, character, 1)
    auto **vt = *reinterpret_cast<void ***>(item);
    reinterpret_cast<void(__thiscall *)(void *, int, void *, int)>(vt[0x08 / 4])(
        item, cbid, character, 1);

    // 64-bit instance counter at character+0xe6e0 / +0xe6e4 (pre-increment).
    auto *ch = reinterpret_cast<std::uint8_t *>(character);
    std::uint32_t serial_lo = *reinterpret_cast<std::uint32_t *>(ch + 0xe6e0);
    std::uint32_t serial_hi = *reinterpret_cast<std::uint32_t *>(ch + 0xe6e4);
    *reinterpret_cast<std::uint32_t *>(ch + 0xe6e0) = serial_lo + 1;
    *reinterpret_cast<std::uint32_t *>(ch + 0xe6e4) =
        serial_hi + static_cast<std::uint32_t>(serial_lo > 0xfffffffeu);

    // Stamp item serial fields (+0x160/+0x164/+0x168).
    FUN_00512160(item, serial_lo, serial_hi, /*flag=*/1);

    // xform = item->vtbl[+0x1cc](); then (*xform)(1, 0-vec, identity quat, 0)
    void *xform =
        reinterpret_cast<void *(__thiscall *)(void *)>(vt[0x1cc / 4])(item);
    auto **xvt = *reinterpret_cast<void ***>(xform);
    reinterpret_cast<void(__thiscall *)(
        void *, int, float, float, float, float, float, float, float, int)>(
        xvt[0])(xform, 1, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, k_g_flOne, 0);

    // Owner / container hooks.
    reinterpret_cast<void(__thiscall *)(void *, std::uint32_t)>(vt[0x2a4 / 4])(
        item, *reinterpret_cast<std::uint32_t *>(ch + 0xe4e8));
    reinterpret_cast<void(__thiscall *)(void *, void *)>(vt[0x218 / 4])(
        item, character);

    // First unit only: bind/trade-lock gate may collapse multi-grant.
    if (first == 0) {
      first = 1;
      if (FUN_00513e70(item) != 0) {
        remaining = 1;
      } else {
        inv_flag = 1;
      }
    }

    reinterpret_cast<void(__thiscall *)(void *, std::uint32_t)>(vt[0x260 / 4])(
        item, inv_flag);
    Client_SendInventoryAddItem(this_char, item, inv_flag);

    remaining -= 1;
  } while (remaining != 0);

  return 1;
}
