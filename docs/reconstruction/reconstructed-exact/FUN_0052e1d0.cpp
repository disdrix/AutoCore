// =============================================================================
// FUN_0052e1d0  (twin of Character_ComputeReverseEngineerRequiredLevel_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052e1d0
// Address:   0x0052e1d0 – 0x0052e636 (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Dual:      R11-002 2026-08-05
// Exactness: Decompiler-faithful control flow; prefer named clean for port notes.
// Bit-for-bit / runtime / differential: OPEN.
// =============================================================================
// Canonical name: Character_ComputeReverseEngineerRequiredLevel_Inferred
// See: reconstructed-exact/Character_ComputeReverseEngineerRequiredLevel_Inferred.cpp
// REJECT scaffold Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e1d0

#include <cmath>
#include <cstdint>

extern void* DAT_00b041fc;
extern float _DAT_009cdff4; // 0.2857143f == 1/3.5

extern void  FUN_004ce940(void);
extern int   FUN_00599dd0(void); // ECX = item def
extern void  FUN_004f1e20(int, int);
extern int   FUN_00404d70(uint32_t cbid);
extern int   FUN_005097b0(uint16_t);
extern int   FUN_005206d0(unsigned tier, int cost);

static int* ObjectMapLookupById(uint32_t id) {
  auto* host = *reinterpret_cast<uint8_t**>(
      reinterpret_cast<uint8_t*>(DAT_00b041fc) + 0xf10);
  if (!host) return nullptr;
  uint32_t mask = *reinterpret_cast<uint32_t*>(host + 8);
  auto* buckets = *reinterpret_cast<int***>(host + 0x10);
  int* bucket = reinterpret_cast<int*>(buckets[mask & id]);
  if (!bucket) return nullptr;
  int* node = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(bucket) + 4);
  while (node) {
    if (static_cast<uint32_t>(*(int*)(reinterpret_cast<uint8_t*>(node) + 0x10)) == id) {
      return *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(node) + 8);
    }
    node = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(node) + 0xc);
  }
  return nullptr;
}

static uint32_t LiveMaterialRank(uint32_t cbid) {
  if (cbid == 0xffffffffu) return 0;
  int* obj = ObjectMapLookupById(cbid);
  if (!obj) return 0;
  if (*(int*)(reinterpret_cast<uint8_t*>(obj) + 0x3c) == 0) FUN_004f1e20(1, 1);
  if (*(int*)(reinterpret_cast<uint8_t*>(obj) + 0x38) != 0x1a) return 0;
  int clone = *(int*)(reinterpret_cast<uint8_t*>(obj) + 0x3c);
  if (clone == 0) return 0;
  return *reinterpret_cast<uint8_t*>(clone + 0x4c8);
}

static int PrimaryContrib(uint32_t cbid) {
  uint32_t rank = LiveMaterialRank(cbid);
  if (rank == 1 || static_cast<int>(rank - 1) < 0) return 0;
  if (cbid == 0xffffffffu) return -1;
  int base = FUN_00404d70(cbid);
  if (base == 0) return -1;
  if (*(int*)(base + 0x3c) == 0) FUN_004f1e20(1, 1);
  if (*(int*)(base + 0x38) != 0x1a) return -1;
  int clone = *(int*)(base + 0x3c);
  if (clone == 0) return -1;
  return *reinterpret_cast<uint8_t*>(clone + 0x4c8) - 1;
}

static int SecondaryContrib(uint32_t cbid) {
  uint32_t rank = LiveMaterialRank(cbid);
  if (rank == 1 || static_cast<int>(rank - 1) < 0) return 0;
  int* obj = ObjectMapLookupById(cbid);
  if (!obj) return -1;
  if (*(int*)(reinterpret_cast<uint8_t*>(obj) + 0x3c) == 0) FUN_004f1e20(1, 1);
  if (*(int*)(reinterpret_cast<uint8_t*>(obj) + 0x38) != 0x1a) return -1;
  int clone = *(int*)(reinterpret_cast<uint8_t*>(obj) + 0x3c);
  if (clone == 0) return -1;
  return *reinterpret_cast<uint8_t*>(clone + 0x4c8) - 1;
}

// thiscall: ECX=character (param_1), stack item* (param_2), EAX int, RET 4
int __thiscall FUN_0052e1d0(int param_1, int* param_2) {
  if (param_2 == nullptr) return 0;

  // item[+0xa8] → +0x3c def; FUN_00599dd0 ECX=def (decompiler elides)
  int link = param_2[0x2a];
  if (link == 0) return 0;
  int def = *reinterpret_cast<int*>(link + 0x3c);
  if (def == 0) return 0;

  int slots = FUN_00599dd0();
  if (slots < 1) return 0;
  if (*reinterpret_cast<int*>(param_1 + 0x6b4) > 0) return 0;

  FUN_004ce940();

  int local_30 = 0;
  int aiStack_18[6];
  aiStack_18[1] = -1;
  aiStack_18[2] = -1;
  aiStack_18[3] = -1;
  aiStack_18[4] = -1;
  aiStack_18[5] = -1;

  int iVar7 = 0;
  slots = FUN_00599dd0();
  if (slots > 0) {
    int off = 0x498;
    do {
      uint32_t cbid = *reinterpret_cast<uint32_t*>(def + off);
      local_30 += PrimaryContrib(cbid);
      iVar7 += 1;
      off += 4;
      slots = FUN_00599dd0();
    } while (iVar7 < slots);
  }

  int saved_primary = local_30;
  int local_34 = static_cast<int>(std::ceil(
      static_cast<double>(static_cast<float>(local_30) * _DAT_009cdff4)));

  unsigned uVar8 = 0;
  auto** vtbl = *reinterpret_cast<void***>(param_2);
  using CountFn = int(__thiscall*)(int*);
  using GetFn = uint16_t(__thiscall*)(int*, unsigned);
  int row_count = reinterpret_cast<CountFn>(vtbl[0x60 / 4])(param_2);
  if (row_count != 0) {
    do {
      int iVar3 = 0;
      reinterpret_cast<GetFn>(vtbl[0x5c / 4])(param_2, uVar8);
      int row_cost = 0;
      do {
        uint16_t prefix =
            reinterpret_cast<GetFn>(vtbl[0x5c / 4])(param_2, uVar8);
        int recipe = FUN_005097b0(prefix);
        if (recipe != 0) {
          uint32_t cbid = *reinterpret_cast<uint32_t*>(recipe + iVar3);
          if (cbid != 0xffffffffu) {
            row_cost += SecondaryContrib(cbid);
          }
        }
        iVar3 += 4;
      } while (iVar3 < 0x14);

      local_30 += row_cost;
      float fVar1 = static_cast<float>(row_cost) * _DAT_009cdff4;
      aiStack_18[uVar8] = row_cost;
      double d = std::ceil(static_cast<double>(fVar1));
      if (static_cast<int>(d) > 0) {
        (void)std::ceil(static_cast<double>(fVar1));
      }
      uVar8 += 1;
      row_count = reinterpret_cast<CountFn>(vtbl[0x60 / 4])(param_2);
    } while (uVar8 < static_cast<unsigned>(row_count));
  }

  if (saved_primary != 0) {
    if (local_30 != -1) {
      int t = FUN_005206d0(uVar8, local_30);
      if (local_34 < t) local_34 = FUN_005206d0(uVar8, local_30);
    }
    iVar7 = 1;
    int* piVar9 = aiStack_18;
    do {
      piVar9 = piVar9 + 1;
      int c = *piVar9;
      if (c != -1) {
        int t = FUN_005206d0(static_cast<unsigned>(iVar7), c);
        if (local_34 < t) local_34 = FUN_005206d0(static_cast<unsigned>(iVar7), c);
      }
      iVar7 += 1;
    } while (iVar7 < 6);
    return local_34;
  }
  return 0;
}
