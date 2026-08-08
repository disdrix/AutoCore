// =============================================================================
// Character_ComputeReverseEngineerRequiredLevel_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Compute the integer Reverse Engineer skill level required for an
//           item given its material recipe cost. Consumed by:
//             Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred (mode 0)
//               when Character_ComputeReverseEngineerSuccessFraction_Inferred
//               returns <= 0:
//                 sprintf("%s %d %s",
//                         "Requires At Least", need, "Reverse Engineering");
//
// Address:  0x0052e1d0 – 0x0052e636  (autoassault.exe, image base 0x400000)
// Size:     1127 B / 0x467
// Stable:   aa_0052e1d0
// System:   inventory-transfer
// Ghidra:   FUN_0052e1d0
// Prior:    Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e1d0
//           (retired scaffold — parent tinkering strings, not this body)
//
// ABI (read_memory prologue/epilogue + call site 0x0085cfe9; sealed R11-002):
//   ECX          = character*  (this)
//   stack arg0   = item*
//   return EAX   = int required RE level
//   cleanup      = RET 4  (thiscall)
//
// Constants (read_memory LE) — inverse of FUN_00520520 capacity mults:
//   1/3.5 @ 0x009cdff4   primary base + FUN_005206d0 tiers 0/1
//   1/2.8 @ 0x009cefcc   FUN_005206d0 tier 2
//   1/2.1 @ 0x009cefc8   tier 3
//   1/1.4 @ 0x00aaa7c4   tier 4
//   1/0.7 @ 0x009cefc4   tier 5
//
// Twin: Character_ComputeReverseEngineerSuccessFraction_Inferred @ 0x0052e640
//   (float success fraction; free flag → 1.0 here free → 0)
//
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI.
// Bit-for-bit / runtime / differential: OPEN (no Launcher; Terminal false).
// Dual: R11-002 2026-08-05
// =============================================================================

#include <cmath>
#include <cstdint>

// --- globals / unowned callees ---
extern void* DAT_00b041fc; // world / object-map host

extern float DAT_009cdff4; // 0.2857143f == 1/3.5
// FUN_005206d0 also reads DAT_009cefcc / 009cefc8 / 00aaa7c4 / 009cefc4

extern void* CVOGLootGenerator_GetOrCreate();                 // 0x004ce940
extern int   ItemDef_CountConfiguredModSlots_Inferred(void*); // 0x00599dd0
extern void* GameData_LookupCloneBaseByCbid(uint32_t cbid);  // 0x00404d70
extern void  FUN_004f1e20(int, int);                         // null-clone assert
extern int*  FUN_005097b0(uint16_t prefix);                  // recipe-by-prefix
extern int   FUN_005206d0(unsigned tier, int cost);          // ceil(cost*inv_mult)

static constexpr int kMaterialType = 0x1a;
static constexpr uint32_t kSentinelCbid = 0xffffffffu;

// Hash-chain object lookup: DAT_00b041fc→+0xf10 table (mask+8, buckets+0x10).
static void* ObjectMapLookupById(uint32_t id) {
  auto* host = *reinterpret_cast<uint8_t**>(
      reinterpret_cast<uint8_t*>(DAT_00b041fc) + 0xf10);
  if (!host) return nullptr;
  uint32_t mask = *reinterpret_cast<uint32_t*>(host + 8);
  auto* buckets = *reinterpret_cast<void***>(host + 0x10);
  void* node = buckets[mask & id];
  if (!node) return nullptr;
  node = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(node) + 4);
  while (node) {
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(node) + 0x10) == id) {
      return *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(node) + 8);
    }
    node = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(node) + 0xc);
  }
  return nullptr;
}

// Live-map rank gate: type 0x1a only; returns raw rank byte (0 if non-material).
static int LiveMaterialRank(uint32_t cbid) {
  if (cbid == kSentinelCbid) return 0;
  void* obj = ObjectMapLookupById(cbid);
  if (!obj) return 0;
  auto* o = reinterpret_cast<uint8_t*>(obj);
  void* clone = *reinterpret_cast<void**>(o + 0x3c);
  if (!clone) FUN_004f1e20(1, 1);
  if (*reinterpret_cast<int*>(o + 0x38) != kMaterialType) return 0;
  clone = *reinterpret_cast<void**>(o + 0x3c);
  if (!clone) return 0;
  return *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(clone) + 0x4c8);
}

// Primary path: rank<=1 → 0; else LookupCloneBase → (rank-1) or -1.
static int PrimaryMaterialCostContrib(uint32_t cbid) {
  if (cbid == kSentinelCbid) return -1; // image: sentinel after rank gate → -1 branch
  int rank_gate = LiveMaterialRank(cbid);
  if (rank_gate == 1 || rank_gate < 1) {
    // also covers non-material / missing (rank_gate 0)
    return 0;
  }
  void* cb = GameData_LookupCloneBaseByCbid(cbid);
  if (!cb) return -1;
  auto* c = reinterpret_cast<uint8_t*>(cb);
  void* def = *reinterpret_cast<void**>(c + 0x3c);
  if (!def) FUN_004f1e20(1, 1);
  if (*reinterpret_cast<int*>(c + 0x38) != kMaterialType) return -1;
  def = *reinterpret_cast<void**>(c + 0x3c);
  if (!def) return -1;
  unsigned r = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(def) + 0x4c8);
  return static_cast<int>(r) - 1;
}

// Secondary path: rank<=1 → 0; else live-map (rank-1) or -1 (no CloneBase).
static int SecondaryMaterialCostContrib(uint32_t cbid) {
  if (cbid == kSentinelCbid) return 0;
  int rank_gate = LiveMaterialRank(cbid);
  if (rank_gate == 1 || rank_gate < 1) return 0;
  void* obj = ObjectMapLookupById(cbid);
  if (!obj) return -1;
  auto* o = reinterpret_cast<uint8_t*>(obj);
  void* clone = *reinterpret_cast<void**>(o + 0x3c);
  if (!clone) FUN_004f1e20(1, 1);
  if (*reinterpret_cast<int*>(o + 0x38) != kMaterialType) return -1;
  clone = *reinterpret_cast<void**>(o + 0x3c);
  if (!clone) return -1;
  unsigned r = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(clone) + 0x4c8);
  return static_cast<int>(r) - 1;
}

// thiscall entry — matches sealed ABI.
int __thiscall Character_ComputeReverseEngineerRequiredLevel_Inferred(
    void* character,
    void* item) {
  if (item == nullptr) return 0;

  auto* item_i = reinterpret_cast<int*>(item);
  void* link = reinterpret_cast<void*>(item_i[0x2a]); // +0xa8
  if (!link) return 0;
  void* def = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(link) + 0x3c);
  if (!def) return 0;

  int slot_count = ItemDef_CountConfiguredModSlots_Inferred(def);
  if (slot_count < 1) return 0;

  auto* ch = reinterpret_cast<uint8_t*>(character);
  // Free / privileged: twin returns 1.0f success; required level is 0.
  if (*reinterpret_cast<int*>(ch + 0x6b4) > 0) {
    return 0;
  }

  (void)CVOGLootGenerator_GetOrCreate();

  int primary_cost = 0;
  int row_costs[6];
  // image: aiStack_18[1..5] = -1; index 0 filled by secondary row 0
  for (int t = 1; t < 6; ++t) row_costs[t] = -1;
  row_costs[0] = 0; // not pre-filled with -1 in image

  for (int i = 0; i < slot_count; ++i) {
    uint32_t cbid = *reinterpret_cast<uint32_t*>(
        reinterpret_cast<uint8_t*>(def) + 0x498 + i * 4);
    int contrib;
    if (cbid == kSentinelCbid) {
      // rank gate short-circuits to 0 before sentinel -1 path when cbid==-1
      // image: uVar8==-1 → uVar4=0 → contrib 0 via rank<=1 path... actually
      // early: if cbid==-1 → rank=0 → then "if uVar4==1 || (int)(uVar4-1)<0" → 0
      contrib = 0;
    } else {
      contrib = PrimaryMaterialCostContrib(cbid);
    }
    primary_cost += contrib;
  }

  int saved_primary = primary_cost;
  int required = static_cast<int>(
      std::ceil(static_cast<double>(static_cast<float>(primary_cost) * DAT_009cdff4)));

  int total_cost = primary_cost;
  auto** vtbl = *reinterpret_cast<void***>(item);
  using CountFn = int(__thiscall*)(void*);
  using GetFn = uint16_t(__thiscall*)(void*, unsigned);
  int row_count = reinterpret_cast<CountFn>(vtbl[0x60 / 4])(item);

  if (row_count != 0) {
    for (unsigned row = 0; static_cast<int>(row) < row_count; ++row) {
      int row_cost = 0;
      // image calls vtbl+0x5c once before inner loop (discard) then per slot
      (void)reinterpret_cast<GetFn>(vtbl[0x5c / 4])(item, row);
      for (int slot = 0; slot < 5; ++slot) {
        uint16_t prefix = reinterpret_cast<GetFn>(vtbl[0x5c / 4])(item, row);
        int* recipe = FUN_005097b0(prefix);
        if (!recipe) continue;
        uint32_t cbid = static_cast<uint32_t>(recipe[slot]);
        if (cbid == kSentinelCbid) continue;
        row_cost += SecondaryMaterialCostContrib(cbid);
      }
      total_cost += row_cost;
      if (row < 6u) {
        row_costs[row] = row_cost;
      }
      // image: ceil(row_cost * 1/3.5); positive → second ceil (FPU side)
      double d = std::ceil(static_cast<double>(
          static_cast<float>(row_cost) * DAT_009cdff4));
      if (static_cast<int>(d) > 0) {
        (void)std::ceil(static_cast<double>(
            static_cast<float>(row_cost) * DAT_009cdff4));
      }
    }
  }

  // No primary material cost → no required level (parent shows other strings).
  if (saved_primary == 0) {
    return 0;
  }

  // Max over aggregate + per-tier FUN_005206d0 (inv capacity mults).
  // After secondary loop, tier arg for aggregate is final row_count (uVar8).
  if (total_cost != -1) {
    int v = FUN_005206d0(static_cast<unsigned>(row_count), total_cost);
    if (required < v) required = v;
  }
  for (int tier = 1; tier < 6; ++tier) {
    int c = row_costs[tier];
    if (c != -1) {
      int v = FUN_005206d0(static_cast<unsigned>(tier), c);
      if (required < v) required = v;
    }
  }
  return required;
}
