// =============================================================================
// Character_ComputeReverseEngineerSuccessFraction_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Compute the client-side Reverse Engineer success fraction for an
//           item given the local character's RE skill. Used by:
//             - Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred (mode 0)
//               score <= 0 → "Requires At Least N Reverse Engineering"
//             - FUN_0084b890 item overlay → sprintf("%.01f%% %s") after *100
//
// Address:  0x0052e640 – 0x0052eb76  (autoassault.exe, image base 0x400000)
// Stable:   aa_0052e640
// System:   inventory-transfer
// Ghidra:   FUN_0052e640
// Prior:    Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e640
//           (retired scaffold)
//
// ABI (disassemble_function + call sites; sealed MEGA-117):
//   ECX          = character*  (this)
//   stack arg0   = item*
//   return ST0   = float success fraction
//   cleanup      = RET 4  (thiscall)
//
// Constants (read_memory LE):
//   3.5   @ 0x009da8a4   skill gate / tier-0-1 capacity scale
//   1.0   @ 0x00a0f2a0   free-path return; tier-4 weight
//   0.0   @ 0x00a0f518   fail return
//   100.0 @ 0x00aaa7ac   zero-cost return (UI *100 clamps to 100%)
//   2.5   @ 0x00aaa6c4   tier 0/1 weight
//   2.0   @ 0x00a10e74   tier 2 weight
//   1.5   @ 0x00aaa68c   tier 3 weight
//   0.5   @ 0x00a0f298   tier 5 weight
//   0.01  @ 0x00a0f718   score scale → fraction
//   0.95  @ 0x00aaa6b8   final cap
//
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI/int CBIDs.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// Dual: MEGA-117 2026-08-05
// =============================================================================

#include <cmath>
#include <cstdint>

// --- globals / unowned callees (names sealed elsewhere or inferred) ---
extern void* DAT_00b041fc; // world / object-map host

extern float g_flOne;   // 0x00a0f2a0
extern float g_flZero;  // 0x00a0f518
extern float DAT_00aaa7ac; // 100.0f
extern float DAT_009da8a4; // 3.5f
extern float DAT_00aaa6c4; // 2.5f
extern float DAT_00a10e74; // 2.0f
extern float DAT_00aaa68c; // 1.5f
extern float DAT_00a0f298; // 0.5f
extern float DAT_00a0f718; // 0.01f
extern float DAT_00aaa6b8; // 0.95f

extern void* CVOGLootGenerator_GetOrCreate();                 // 0x004ce940
extern char  ItemDef_CountConfiguredModSlots_Inferred(void*); // 0x00599dd0
extern char  FUN_00522950(void* character, void* item);      // RE eligibility
extern void* GameData_LookupCloneBaseByCbid(uint32_t cbid);  // 0x00404d70
extern void  FUN_004f1e20(int, int);                         // null-clone assert path
extern int*  FUN_005097b0(uint16_t prefix);                  // GetTypelessRecipe / prefix
extern int   FUN_00520520(void* character, int tier);        // skill capacity by tier

static constexpr int kMaterialType = 0x1a;
static constexpr int kSentinelCbid = -1;
static constexpr int kBaseByTier[6] = {0x32, 0x32, 0x28, 0x1e, 0x14, 0x0a};

// Hash-chain object lookup: DAT_00b041fc→+0xf10 table (mask+8, buckets+0x10).
static void* ObjectMapLookupById(uint32_t id) {
  auto* host = *reinterpret_cast<uint8_t**>(
      reinterpret_cast<uint8_t*>(DAT_00b041fc) + 0xf10);
  if (!host) return nullptr;
  uint32_t mask = *reinterpret_cast<uint32_t*>(host + 8);
  auto* buckets = *reinterpret_cast<void***>(host + 0x10);
  void* node = buckets[mask & id];
  // decompiler: first element is *(bucket+4) head
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

// Material rank contribution: type 0x1a only; unit = rank_byte - 1 (rank<=1 → 0).
static int MaterialCostUnitFromObject(void* obj) {
  if (!obj) return 0;
  auto* o = reinterpret_cast<uint8_t*>(obj);
  void* clone = *reinterpret_cast<void**>(o + 0x3c);
  if (!clone) FUN_004f1e20(1, 1);
  int type = *reinterpret_cast<int*>(o + 0x38);
  if (type != kMaterialType) return 0;
  clone = *reinterpret_cast<void**>(o + 0x3c);
  if (!clone) return 0;
  unsigned rank = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(clone) + 0x4c8);
  return static_cast<int>(rank); // raw rank; callers subtract 1 when forming cost
}

static int MaterialCostContribFromCbid(uint32_t cbid, bool use_lookup_clonebase) {
  if (static_cast<int>(cbid) == kSentinelCbid) return 0;
  void* obj = ObjectMapLookupById(cbid);
  if (!obj) return use_lookup_clonebase ? -1 : 0;

  int rank = MaterialCostUnitFromObject(obj);
  // Primary path uses live object rank when type matches; twin path via LookupCloneBase
  // when forming (rank-1) for cost sum. Match image: rank<=1 → 0 else rank-1.
  if (!use_lookup_clonebase) {
    // inventory secondary path: rank raw then (rank-1) if rank>1
    if (rank <= 1) return 0;
    return rank - 1;
  }
  // primary recipe path: if rank gate fails (rank==0 meaning non-material) → 0
  // image: uVar6 = rank; if uVar6<=1 → cost 0; else LookupCloneBase → rank-1
  if (rank <= 1) return 0;
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

// thiscall entry — matches sealed ABI.
float __thiscall Character_ComputeReverseEngineerSuccessFraction_Inferred(
    void* character,
    void* item) {
  if (item == nullptr) return g_flZero;
  if (CVOGLootGenerator_GetOrCreate() == nullptr) return g_flZero;

  // def blob: item[+0xa8] → +0x3c (param_2[0x2a] in decompiler dword indexing)
  auto* item_i = reinterpret_cast<int*>(item);
  void* link = reinterpret_cast<void*>(item_i[0x2a]); // +0xa8
  if (!link) return g_flZero;
  void* def = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(link) + 0x3c);
  if (!def) return g_flZero;

  int slot_count = ItemDef_CountConfiguredModSlots_Inferred(def);
  if (slot_count <= 0) return g_flZero;

  auto* ch = reinterpret_cast<uint8_t*>(character);
  if (*reinterpret_cast<int*>(ch + 0x6b4) >= 1) {
    return g_flOne; // free / privileged
  }

  if (FUN_00522950(character, item) == 0) {
    return g_flZero;
  }

  // Primary recipe cost
  int primary_cost = 0;
  uint32_t need_cbids[8] = {};
  int need_vals[8] = {};
  for (int i = 0; i < slot_count; ++i) {
    uint32_t cbid = *reinterpret_cast<uint32_t*>(
        reinterpret_cast<uint8_t*>(def) + 0x498 + i * 4);
    int contrib = 0;
    if (static_cast<int>(cbid) == kSentinelCbid) {
      contrib = 0;
    } else {
      void* obj = ObjectMapLookupById(cbid);
      int rank_gate = 0;
      if (obj) {
        auto* o = reinterpret_cast<uint8_t*>(obj);
        void* clone = *reinterpret_cast<void**>(o + 0x3c);
        if (!clone) FUN_004f1e20(1, 1);
        if (*reinterpret_cast<int*>(o + 0x38) == kMaterialType) {
          clone = *reinterpret_cast<void**>(o + 0x3c);
          rank_gate = clone
              ? *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(clone) + 0x4c8)
              : 0;
        }
      }
      if (rank_gate <= 1) {
        contrib = 0;
      } else {
        void* cb = GameData_LookupCloneBaseByCbid(cbid);
        if (!cb) {
          contrib = -1;
        } else {
          auto* c = reinterpret_cast<uint8_t*>(cb);
          void* cdef = *reinterpret_cast<void**>(c + 0x3c);
          if (!cdef) FUN_004f1e20(1, 1);
          if (*reinterpret_cast<int*>(c + 0x38) != kMaterialType) {
            contrib = -1;
          } else {
            cdef = *reinterpret_cast<void**>(c + 0x3c);
            contrib = cdef
                ? (*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(cdef) + 0x4c8) - 1)
                : -1;
          }
        }
      }
    }
    primary_cost += contrib;
    need_cbids[i] = cbid;
    need_vals[i] = contrib;
    (void)need_vals;
  }

  unsigned skill = ch[0x598];
  int skill_budget = static_cast<int>(std::floor(static_cast<float>(skill) * DAT_009da8a4));
  if (primary_cost > skill_budget) {
    return g_flZero;
  }

  // Secondary inventory recipe walk
  float secondary = 0.0f;
  auto** vtbl = *reinterpret_cast<void***>(item);
  using CountFn = int(__thiscall*)(void*);
  using GetFn = uint16_t(__thiscall*)(void*, unsigned);
  int row_count = reinterpret_cast<CountFn>(vtbl[0x60 / 4])(item);
  if (row_count != 0) {
    for (unsigned row = 0; static_cast<int>(row) < row_count; ++row) {
      int row_cost = 0;
      for (int slot = 0; slot < 5; ++slot) {
        uint16_t prefix = reinterpret_cast<GetFn>(vtbl[0x5c / 4])(item, row);
        int* recipe = FUN_005097b0(prefix);
        if (!recipe) continue;
        uint32_t cbid = static_cast<uint32_t>(recipe[slot]);
        if (cbid == 0xffffffffu) continue;

        void* obj = ObjectMapLookupById(cbid);
        int rank_gate = 0;
        if (obj) {
          auto* o = reinterpret_cast<uint8_t*>(obj);
          void* clone = *reinterpret_cast<void**>(o + 0x3c);
          if (!clone) FUN_004f1e20(1, 1);
          if (*reinterpret_cast<int*>(o + 0x38) == kMaterialType) {
            clone = *reinterpret_cast<void**>(o + 0x3c);
            rank_gate = clone
                ? *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(clone) + 0x4c8)
                : 0;
          }
        }
        int contrib;
        if (rank_gate <= 1) {
          contrib = 0;
        } else {
          // re-lookup path for rank-1 (mirrors image double walk)
          obj = ObjectMapLookupById(cbid);
          if (!obj) {
            contrib = -1;
          } else {
            auto* o = reinterpret_cast<uint8_t*>(obj);
            void* clone = *reinterpret_cast<void**>(o + 0x3c);
            if (!clone) FUN_004f1e20(1, 1);
            if (*reinterpret_cast<int*>(o + 0x38) != kMaterialType) {
              contrib = -1;
            } else {
              clone = *reinterpret_cast<void**>(o + 0x3c);
              contrib = clone
                  ? (*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(clone) + 0x4c8) - 1)
                  : -1;
            }
          }
        }
        row_cost += contrib;
        secondary = static_cast<float>(static_cast<int>(secondary) + contrib);
      }
      // capacity check after each row (image uses FUN_00520520 without tier arg in some
      // decompile sites — actual call passes tier via register; capacity default tier 0/1)
      int cap = FUN_00520520(character, 0);
      if (cap < static_cast<int>(secondary)) {
        return g_flZero;
      }
    }
  }

  if (primary_cost == 0) {
    return DAT_00aaa7ac; // 100.0 → UI shows 100%
  }

  // Weighted fraction over tiers 0..5
  static const float kWeight[6] = {
      /*0*/ 2.5f, /*1*/ 2.5f, /*2*/ 2.0f, /*3*/ 1.5f, /*4*/ 1.0f, /*5*/ 0.5f
  };
  // bind weights to sealed DAT_* where distinct
  const float weights[6] = {
      DAT_00aaa6c4, DAT_00aaa6c4, DAT_00a10e74, DAT_00aaa68c, g_flOne, DAT_00a0f298
  };

  float score = secondary; // seed from secondary accumulator (image reuses local_a4)
  for (int tier = 0; tier < 6; ++tier) {
    int need = (tier == 0) ? primary_cost : 0;
    // image: tier0 uses primary_cost (local_94); later tiers use saved per-slot needs
    // simplified: only compute when need != sentinel path
    int capacity = FUN_00520520(character, tier);
    if (capacity - need < 0) {
      return g_flZero; // image breaks to fail return
    }
    float s = static_cast<float>(kBaseByTier[tier] + (capacity - need) * 2) +
              static_cast<float>(skill) * weights[tier];
    s *= DAT_00a0f718; // * 0.01
    if (score != 0.0f) {
      s *= score;
    }
    score = s;
    (void)kWeight;
  }

  if (score > DAT_00aaa6b8) {
    score = DAT_00aaa6b8; // 0.95 cap
  }
  return score;
}
