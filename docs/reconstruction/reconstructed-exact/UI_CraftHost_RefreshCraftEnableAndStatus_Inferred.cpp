// =============================================================================
// UI_CraftHost_RefreshCraftEnableAndStatus_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008e55e0
// Address:   0x008e55e0–0x008e598d inclusive (942 B / 0x3AE)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer
// Dual:      R13-015 OWN-ONLY 2026-08-05 (accept-with-gaps; terminal false)
// Exactness: Behavior-preserving rewrite of sealed CF/ABI. Not modernization.
// Runtime:   OPEN — never Runtime Confirmed this pass.
// =============================================================================
//
// PURPOSE:
//   Refresh craft/RE host craft-button enable state and status/cost/chance text.
//
// ABI (sealed):
//   host in EAX on entry; no stack args; void; plain RET (C3).
//   Not ECX-thiscall. Not EDI-host (contrast material-list 008e5e00).
//
// Embedded product strings:
//   "You must select an item to craft!"
//   "You need a broken item to craft!"
//   "You don't have the right components!"
//   "To craft this from Memory costs"
//   "Chance of Success"
//   "\n%s: %.1f%%" / "\n%s: %i%%"
//
// Decompiler traps corrected here:
//   - status out-param is int codes 2/4/5 (not denormal floats)
//   - success path hardcodes 100.0 double for %.1f%% (not live chance float)
//   - tier-max loop discards Character_CalcCommodityTierMaxCapacity returns
// =============================================================================

#include <cstdint>
#include <cmath>
#include <cstdio>

// External dualed / residual callees (not owned this VA)
extern "C" {
  extern void* DAT_00d1b6d8;           // global character*
  extern float DAT_00aaa680;          // 0.85f
  extern double DAT_00aaa708;         // 100.0
  extern void* DAT_00d1ad30;
  extern char DAT_00a3ad3c[];         // spacer / currency glyph string

  void FUN_008e54a0(/* host often in ESI */);
  int __thiscall Character_CalcCommodityTierMaxCapacity_Inferred(void* ch, uint32_t tier);
  char __thiscall Character_Craft_HasMatchingStationInRange_Inferred(void* ch, void* craftObject);
  char __thiscall FUN_005202d0(void* ch, uint32_t tfid_lo, uint32_t tfid_hi);
  int __thiscall Item_GetStoreSellPrice_Inferred(void* item);
  char __thiscall FUN_0052d450(void* ch, void* object, int* status_out /* + chance overlay */);
  void FUN_008e3820(/* status formatter; this/regs residual */);
  void FUN_008e3940(/* station/status formatter; residual */);
  void* FUN_007a69d0(const char* key, int unk, ...);
  void* __thiscall FUN_007a6de0(void* loc, int unk);
  int __thiscall FUN_0040f4e0(void* obj);
  void __fastcall FUN_00977a30(void* font, int value_lo, int value_hi);
  void FUN_008e41b0(/* host in EAX — Complexity labels */);
}

// Widget vtbl ordinals used (offsets into vtbl, not owned)
// +0xd4 enable/set, +0xd8 is-enabled query, +0x34c refresh
// +0x268 clear text, +0x250 append text, +0x15c set color, +0x1d8 set string, +0xcc show
// +0x490 list row count

void UI_CraftHost_RefreshCraftEnableAndStatus_Inferred(void* host /*EAX*/) {
  if (DAT_00d1b6d8 == nullptr) {
    return;
  }

  char msg[0x20C];
  // Zero message buffer (~0x200 via REP STOSD pattern)
  for (int i = 0; i < (int)(sizeof(msg) / 4); ++i) {
    reinterpret_cast<uint32_t*>(msg)[i] = 0;
  }

  uint8_t station_ok = 0;
  uint8_t afford_ok = 1;
  int status_code = 0;
  float chance_or_scratch = 0.0f;

  // host+0x7d8 craft-gate byte
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(host) + 0x7d8) = 1;
  FUN_008e54a0();  // residual; may clear +0x7d8

  // Dualed tier-max leaf — returns discarded (read-only; vestigial vs warm open)
  for (uint32_t tier = 1; tier <= 5; ++tier) {
    (void)Character_CalcCommodityTierMaxCapacity_Inferred(DAT_00d1b6d8, tier);
  }

  void* bound = *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0x7cc);
  if (bound != nullptr) {
    if (Character_Craft_HasMatchingStationInRange_Inferred(DAT_00d1b6d8, bound)) {
      station_ok = 1;
    }
  }

  if (bound != nullptr) {
    uint32_t lo = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(bound) + 0x160);
    uint32_t hi = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(bound) + 0x164);
    if (FUN_005202d0(DAT_00d1b6d8, lo, hi)) {
      int price = Item_GetStoreSellPrice_Inferred(bound);
      // cost = (int)ceil((float)price * 0.85f)
      double scaled = static_cast<double>(static_cast<float>(price) * DAT_00aaa680);
      int cost = static_cast<int>(std::ceil(scaled));

      // i64 credits = (char+0x720) - (char+0x728)
      auto* ch = reinterpret_cast<uint8_t*>(DAT_00d1b6d8);
      uint32_t a_lo = *reinterpret_cast<uint32_t*>(ch + 0x720);
      uint32_t a_hi = *reinterpret_cast<uint32_t*>(ch + 0x724);
      uint32_t b_lo = *reinterpret_cast<uint32_t*>(ch + 0x728);
      uint32_t b_hi = *reinterpret_cast<uint32_t*>(ch + 0x72c);
      uint32_t avail_lo = a_lo - b_lo;
      uint32_t avail_hi = a_hi - b_hi - (a_lo < b_lo ? 1u : 0u);

      int64_t avail = (static_cast<int64_t>(static_cast<int32_t>(avail_hi)) << 32) |
                      static_cast<uint32_t>(avail_lo);
      int64_t need = static_cast<int64_t>(cost);
      if (need > avail) {
        afford_ok = 0;
      }
    }
  }

  void** button = *reinterpret_cast<void***>(reinterpret_cast<char*>(host) + 0x748);
  void** status = *reinterpret_cast<void***>(reinterpret_cast<char*>(host) + 0x528);
  uint8_t gate_7d8 = *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(host) + 0x7d8);

  char ready = FUN_0052d450(DAT_00d1b6d8, bound, &status_code);
  // status_code shares stack slot with chance overlay; treat as int on fail ladder

  uint8_t color_r = 0, color_g = 0, color_a = 0xFF, color_b = 0xFF;

  if (ready && station_ok && gate_7d8 && afford_ok) {
    // Enable craft button
    auto* bv = reinterpret_cast<void**>(*button);
    reinterpret_cast<void(__thiscall*)(void*, int)>(bv[0xd4 / 4])(button, 1);
    auto* sv = reinterpret_cast<void**>(*status);
    reinterpret_cast<void(__thiscall*)(void*)>(sv[0x268 / 4])(status);

    void* loc = FUN_007a69d0("Chance of Success", -1, DAT_00aaa708);
    loc = FUN_007a6de0(loc, -1);
    std::sprintf(msg, "\n%s: %.1f%%", reinterpret_cast<const char*>(loc));
    // Note: product hardcodes 100.0 via DAT_00aaa708 — not status_code/chance float
    color_r = 0xFF;
    color_g = 0xFF;
  } else {
    auto* bv = reinterpret_cast<void**>(*button);
    char was_on = reinterpret_cast<char(__thiscall*)(void*)>(bv[0xd8 / 4])(button);
    if (was_on) {
      reinterpret_cast<void(__thiscall*)(void*, int)>(bv[0xd4 / 4])(button, 0);
      reinterpret_cast<void(__thiscall*)(void*)>(bv[0x34c / 4])(button);
    }
    auto* sv = reinterpret_cast<void**>(*status);
    reinterpret_cast<void(__thiscall*)(void*)>(sv[0x268 / 4])(status);

    if (bound == nullptr) {
      void** list = *reinterpret_cast<void***>(reinterpret_cast<char*>(host) + 0x754);
      if (list == nullptr ||
          reinterpret_cast<int(__thiscall*)(void*)>(
              reinterpret_cast<void**>(*list)[0x490 / 4])(list) > 0) {
        std::sprintf(msg, "You must select an item to craft!");
      } else {
        std::sprintf(msg, "You need a broken item to craft!");
      }
    } else if (status_code == 4) {
      FUN_008e3820();
    } else if (status_code == 2) {
      std::sprintf(msg, "You don't have the right components!");
    } else if (!afford_ok) {
      msg[0] = 0;
      void* loc = FUN_007a69d0("To craft this from Memory costs", -1);
      loc = FUN_007a6de0(loc, -1);
      auto* sv2 = reinterpret_cast<void**>(*status);
      reinterpret_cast<void(__thiscall*)(void*, void*)>(sv2[0x250 / 4])(status, loc);
      reinterpret_cast<void(__thiscall*)(void*, void*)>(sv2[0x250 / 4])(status, DAT_00a3ad3c);
      int val = FUN_0040f4e0(bound);
      FUN_00977a30(DAT_00d1ad30, val, val >> 31);
    } else if (!station_ok || status_code == 5) {
      FUN_008e3940();
    } else {
      void* loc = FUN_007a69d0("Chance of Success", -1, 0);
      loc = FUN_007a6de0(loc, -1);
      std::sprintf(msg, "\n%s: %i%%", reinterpret_cast<const char*>(loc));
    }
    color_r = 0;
    color_g = 0;
  }

  // Apply colors + Complexity refresh + widget show
  auto* svf = reinterpret_cast<void**>(*status);
  uint8_t color_bytes[4] = {color_r, color_g, color_a, color_b};
  reinterpret_cast<void(__thiscall*)(void*, int, void*)>(svf[0x15c / 4])(status, 1, color_bytes);

  // FUN_008e41b0 expects host in EAX
  FUN_008e41b0();

  auto* bvf = reinterpret_cast<void**>(
      *reinterpret_cast<void***>(reinterpret_cast<char*>(host) + 0x748));
  reinterpret_cast<void(__thiscall*)(void*)>(bvf[0x34c / 4])(
      *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0x748));

  if (msg[0] != '\0') {
    reinterpret_cast<void(__thiscall*)(void*, char*, int, int)>(svf[0x1d8 / 4])(
        status, msg, 1, 1);
  }
  reinterpret_cast<void(__thiscall*)(void*, int)>(svf[0xcc / 4])(status, 1);
  reinterpret_cast<void(__thiscall*)(void*)>(svf[0x34c / 4])(status);

  (void)chance_or_scratch;
}
