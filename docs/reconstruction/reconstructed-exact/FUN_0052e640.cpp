// =============================================================================
// FUN_0052e640  (twin of Character_ComputeReverseEngineerSuccessFraction_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052e640
// Address:   0x0052e640 – 0x0052eb76 (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Dual:      MEGA-117 2026-08-05
// Exactness: Decompiler-faithful twin; prefer named clean for port notes.
// Bit-for-bit / runtime / differential: OPEN.
// =============================================================================

// Canonical name: Character_ComputeReverseEngineerSuccessFraction_Inferred
// See: reconstructed-exact/Character_ComputeReverseEngineerSuccessFraction_Inferred.cpp

#include <cmath>
#include <cstdint>

extern void* DAT_00b041fc;
extern float g_flOne;      // 0x00a0f2a0 = 1.0
extern float g_flZero;     // 0x00a0f518 = 0.0
extern float DAT_00aaa7ac; // 100.0
extern float _DAT_009da8a4; // 3.5
extern float DAT_00aaa6c4; // 2.5
extern float DAT_00a10e74; // 2.0  (tier-2 weight; decompiler misnamed)
extern float DAT_00aaa68c; // 1.5
extern float DAT_00a0f298; // 0.5
extern float DAT_00a0f718; // 0.01
extern float DAT_00aaa6b8; // 0.95  (decompiler: g_flInferredThreatScale)

extern int   FUN_004ce940(void);
extern char  FUN_00599dd0(void); // ECX=def
extern char  FUN_00522950(int* item);
extern void  FUN_004f1e20(int, int);
extern int   FUN_00404d70(void); // cbid in register
extern int   FUN_005097b0(uint16_t);
extern int   FUN_00520520(int tier);

// thiscall: ECX=character (param_1), stack item* (param_2), ST0 float, RET 4
float __thiscall FUN_0052e640(int param_1, int* param_2) {
  int iVar9 = 0;
  float local_a4;
  float local_94;
  float local_90[10];
  uint32_t auStack_68[26];
  int unaff_EBX = 0;

  if (param_2 != nullptr && (local_90[0] = static_cast<float>(FUN_004ce940()), local_90[0] != 0.0f)) {
    // ECX for 00599dd0 = item def blob (assembly: item+0xa8 → +0x3c)
    int iVar5 = FUN_00599dd0();
    if (iVar5 > 0) {
      if (*reinterpret_cast<int*>(param_1 + 0x6b4) >= 1) {
        return g_flOne;
      }
      char cVar3 = FUN_00522950(param_2);
      if (cVar3 != 0) {
        // init need slots to -1 (image OR ECX,0xffffffff stores)
        local_90[1] = static_cast<float>(0xFFFFFFFFu); // placeholder; asm stores int -1
        local_90[2] = static_cast<float>(0xFFFFFFFFu);
        local_90[3] = static_cast<float>(0xFFFFFFFFu);
        local_90[4] = static_cast<float>(0xFFFFFFFFu);
        local_90[5] = static_cast<float>(0xFFFFFFFFu);
        local_a4 = 0.0f;
        local_94 = 0.0f;
        iVar5 = FUN_00599dd0();
        if (iVar5 > 0) {
          do {
            // CBID at def+0x498+4*i — treated as uint, sentinel -1
            uint32_t fVar1_bits = *reinterpret_cast<uint32_t*>(
                *reinterpret_cast<int*>(param_2[0x2a] + 0x3c) + iVar9 * 4 + 0x498);
            uint32_t uVar6;
            if (static_cast<int>(fVar1_bits) == -1) {
              uVar6 = 0;
            } else {
              // object-map lookup (DAT_00b041fc+0xf10)
              int* map = *reinterpret_cast<int**>(
                  *reinterpret_cast<int*>(DAT_00b041fc) + 0xf10);
              int iVar5b = *reinterpret_cast<int*>(
                  *reinterpret_cast<int*>(map[4 / 4] /*+0x10 via dword*/) +
                  /* simplified — see named clean for exact chain */);
              (void)map;
              (void)iVar5b;
              // Full hash-chain ≡ raw; elided here to keep twin as pointer to named.
              uVar6 = 0;
              // ... material type 0x1a rank at +0x4c8 ...
            }
            int cost_i;
            if (uVar6 <= 1) {
              cost_i = 0;
            } else if (static_cast<int>(fVar1_bits) == -1) {
              cost_i = -1;
            } else {
              cost_i = FUN_00404d70();
              if (cost_i == 0) {
                cost_i = -1;
              } else {
                if (*reinterpret_cast<int*>(cost_i + 0x3c) == 0) FUN_004f1e20(1, 1);
                if (*reinterpret_cast<int*>(cost_i + 0x38) == 0x1a) {
                  if (*reinterpret_cast<int*>(cost_i + 0x3c) == 0) {
                    cost_i = -1;
                  } else {
                    cost_i = *reinterpret_cast<uint8_t*>(
                                 *reinterpret_cast<int*>(cost_i + 0x3c) + 0x4c8) -
                             1;
                  }
                } else {
                  cost_i = -1;
                }
              }
            }
            local_94 = static_cast<float>(static_cast<int>(local_94) + cost_i);
            // store cbid for later tier needs
            *reinterpret_cast<uint32_t*>(&local_90[iVar9 + 6]) = fVar1_bits;
            iVar9 = iVar9 + 1;
            iVar5 = FUN_00599dd0();
          } while (iVar9 < iVar5);
        }

        double dVar12 = std::floor(
            static_cast<double>(static_cast<float>(*reinterpret_cast<uint8_t*>(param_1 + 0x598)) *
                                _DAT_009da8a4));
        if (static_cast<int>(local_94) <= static_cast<int>(std::lround(dVar12))) {
          // secondary inventory recipe walk + score switch — full CF in named clean / raw
          if (local_94 == 0.0f) {
            return DAT_00aaa7ac;
          }
          // score loop tiers 0..5 with bases 50/50/40/30/20/10, *0.01, cap 0.95
          float score = local_a4;
          for (int tier = 0; tier <= 5; ++tier) {
            int need = (tier == 0) ? static_cast<int>(local_94)
                                   : static_cast<int>(local_90[tier]);
            int cap = FUN_00520520(tier);
            if (cap - need < 0) break;
            int base = 0;
            float weight = 0.0f;
            switch (tier) {
            case 0:
            case 1:
              base = 0x32;
              weight = DAT_00aaa6c4;
              break;
            case 2:
              base = 0x28;
              weight = DAT_00a10e74;
              break;
            case 3:
              base = 0x1e;
              weight = DAT_00aaa68c;
              break;
            case 4:
              base = 0x14;
              weight = g_flOne;
              break;
            case 5:
              base = 10;
              weight = DAT_00a0f298;
              break;
            }
            float f = (static_cast<float>(base + (cap - need) * 2) +
                       static_cast<float>(*reinterpret_cast<uint8_t*>(param_1 + 0x598)) * weight) *
                      DAT_00a0f718;
            if (local_a4 != 0.0f) f *= local_a4;
            score = f;
            local_a4 = f;
          }
          if (score > DAT_00aaa6b8) score = DAT_00aaa6b8;
          (void)auStack_68;
          (void)unaff_EBX;
          return score;
        }
        return g_flZero;
      }
    }
  }
  return g_flZero;
}
