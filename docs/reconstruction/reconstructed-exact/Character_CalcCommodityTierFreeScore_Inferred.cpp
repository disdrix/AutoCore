// =============================================================================
// Character_CalcCommodityTierFreeScore_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00522780
// Address:   0x00522780  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_00522780
// Generated: 2026-08-05 R10-036 dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Score free commodity capacity for one TFID tier row.
//   used = Character_SumCommodityTfidRowCost_Inferred(this, tier, row)
//   max  = FUN_00520340(this, tier)   // level-scaled max (callee not owned)
//   free = max - used; if free < 0 or tier not in 1..5 → 0
//   return (level * scale[tier] + (base[tier] + free * 2)) * 0.01f
//   level = *(uint8_t*)(this + 0x599)
//
// ABI: __thiscall (ECX = Character*); two stack dwords; ret 8.
//
// REJECT: scaffold Named_CalleeOf_…_00522780
//
// Sole caller (context): FUN_00522860 multiplies per-tier scores.

#include <cstdint>

struct Character;

// Parent dual @ 0x00522710 — thiscall Character*, ret 8
extern "C" int __thiscall Character_SumCommodityTfidRowCost_Inferred(
    Character* self,
    uint32_t unused_or_tier,
    const uint32_t* tfidRow);

// Tier max capacity from level @ this+0x599 — FUN_00520340 (not dualed here)
extern "C" int __thiscall FUN_00520340(Character* self, uint32_t tier);

// Float globals (image VAs; values sealed via read_memory 2026-08-05)
// 0x00aaa6c4 = 2.5f, 0x00a10e74 = 2.0f, 0x00aaa68c = 1.5f
// 0x00a0f2a0 = 1.0f (g_flOne), 0x00a0f298 = 0.5f
// 0x00a0f718 ≈ 0.01f, 0x00a0f518 = 0.0f (g_flZero)

float __thiscall Character_CalcCommodityTierFreeScore_Inferred(
    Character* self,
    uint32_t tier,
    const uint32_t* tfidRow /* 5 × {lo, hi} */)
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
  case 1:
    base = 50;   // 0x32
    scale = 2.5f;
    break;
  case 2:
    base = 40;   // 0x28
    scale = 2.0f;
    break;
  case 3:
    base = 30;   // 0x1e
    scale = 1.5f;
    break;
  case 4:
    base = 20;   // 0x14
    scale = 1.0f;
    break;
  case 5:
    base = 10;
    scale = 0.5f;
    break;
  default:
    return 0.0f;
  }

  auto* bytes = reinterpret_cast<uint8_t*>(self);
  float level = static_cast<float>(bytes[0x599]);
  // bytes: fild level; fmul scale; fiadd (base + free*2); fmul DAT_00a0f718
  return (level * scale + static_cast<float>(base + freeSlots * 2)) * 0.01f;
}
