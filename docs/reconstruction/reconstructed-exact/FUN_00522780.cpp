// =============================================================================
// FUN_00522780  (twin of Character_CalcCommodityTierFreeScore_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00522780
// Address:   0x00522780  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 R10-036 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Prefer named twin: Character_CalcCommodityTierFreeScore_Inferred.cpp
// REJECT scaffold Named_CalleeOf_…_00522780

#include <cstdint>

struct Character;

extern "C" int __thiscall Character_SumCommodityTfidRowCost_Inferred(
    Character* self, uint32_t tier, const uint32_t* tfidRow);
extern "C" int __thiscall FUN_00520340(Character* self, uint32_t tier);

// Ghidra-symbol entry: same body as named twin
float __thiscall FUN_00522780(Character* self, uint32_t tier, const uint32_t* tfidRow)
{
  int used = Character_SumCommodityTfidRowCost_Inferred(self, tier, tfidRow);
  int maxCap = FUN_00520340(self, tier);
  int freeSlots = maxCap - used;
  if (freeSlots < 0) {
    return 0.0f;
  }

  int base = 0;
  float scale = 0.0f;
  switch (tier) {
  case 1: base = 0x32; scale = 2.5f; break; // DAT_00aaa6c4
  case 2: base = 0x28; scale = 2.0f; break; // g_flLevelUpUiBase_Inferred
  case 3: base = 0x1e; scale = 1.5f; break; // DAT_00aaa68c
  case 4: base = 0x14; scale = 1.0f; break; // g_flOne
  case 5: base = 10;   scale = 0.5f; break; // DAT_00a0f298
  default: return 0.0f;
  }

  float level = static_cast<float>(
      *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x599));
  return (level * scale + static_cast<float>(base + freeSlots * 2)) * 0.01f; // DAT_00a0f718
}
