// =============================================================================
// FUN_0074c9c0  (scaffold twin of Bounds_AccumulateTransformedLocal)
// -----------------------------------------------------------------------------
// Stable ID: aa_0074c9c0
// Address:   0x0074c9c0  (autoassault.exe, image base 0x400000)
// Body:      0x0074c9c0 – 0x0074ce55
// System:    graphics / bounds
// Generated: 2026-07-29 W21-O dual seal
// Exactness: Ghidra-shaped control flow from authoritative raw. Prefer named
//            Bounds_AccumulateTransformedLocal.cpp for port contracts.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// ABI note: retail uses ECX=dest bounds*, three stack args, ret 12.
// Ghidra surface below is the three stack params only; ECX is implicit.
//

#include <cmath>
#include <cstdint>

extern "C" void FUN_0044b5c0(void);
extern "C" void FUN_0076f6e0(void);
extern float DAT_00a0f298; // 0.5f

// Ghidra-shaped entry (stack args). ECX = destination BoundsVolume* at call.
extern "C" void FUN_0074c9c0(int param_1, float *param_2, int param_3)
{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float **ppfVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_9c;
  float local_98;
  float *local_94;
  float local_90;
  float *local_8c;
  float *local_88[2];
  float local_80;
  uint32_t local_7c;
  float *local_78;
  float local_74;
  float local_70;
  float *local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float *local_58;
  float local_54;
  uint8_t local_50[76];

  // ECX dest recovered as pfVar3 after first transform block (see annotated).
  // Early gate on local volume +0x2c:
  if (*(char *)(param_2 + 0xb) == '\0') {
    FUN_0044b5c0(); // matrix → local_50; ECX/EDI wired in retail
    local_98 = *param_2;
    local_94 = (float *)param_2[1];
    local_90 = param_2[2];
    FUN_0076f6e0(); // project local center
    pfVar3 = local_8c;
    local_80 = local_68;
    local_98 = local_70;
    local_94 = local_6c;
    local_90 = local_68;

    if ((*(char *)(param_3 + 0xb8) == '\0') && (*(char *)(param_1 + 0xb8) == '\0')) {
      fVar6 = (*(float *)(param_3 + 0x9c) / *(float *)(param_1 + 0x9c)) * param_2[3];
    } else {
      fVar6 = std::sqrt(*(float *)(param_3 + 0xa4) * *(float *)(param_3 + 0xa4) +
                        *(float *)(param_3 + 0xa0) * *(float *)(param_3 + 0xa0) +
                        *(float *)(param_3 + 0x9c) * *(float *)(param_3 + 0x9c)) *
              (param_2[3] /
               std::sqrt(*(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4) +
                         *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0xa0) +
                         *(float *)(param_1 + 0x9c) * *(float *)(param_1 + 0x9c)));
    }

    if (local_8c[3] == 0.0f) {
      *local_8c = local_70;
      local_8c[1] = (float)(uintptr_t)local_6c;
      local_8c[2] = local_68;
      local_8c[3] = fVar6;
    } else {
      fVar1 = local_70 - *local_8c;
      fVar2 = (float)(uintptr_t)local_6c - local_8c[1];
      local_80 = local_68 - local_8c[2];
      fVar7 = std::sqrt(fVar1 * fVar1 + fVar2 * fVar2 + local_80 * local_80);
      fVar8 = (local_8c[3] + fVar7 + fVar6) * DAT_00a0f298;
      if (local_8c[3] < fVar8) {
        if (fVar6 < fVar8) {
          if (0.0f < fVar7) {
            fVar7 = (fVar8 - local_8c[3]) / fVar7;
            local_8c[1] = local_8c[1] + fVar2 * fVar7;
            *local_8c = fVar1 * fVar7 + *local_8c;
            local_8c[2] = local_8c[2] + local_80 * fVar7;
          }
          local_8c[3] = fVar8;
        } else {
          *local_8c = local_70;
          local_8c[1] = (float)(uintptr_t)local_6c;
          local_8c[3] = fVar6;
          local_8c[2] = local_68;
        }
      }
    }

    local_74 = local_70 - fVar6;
    local_78 = (float *)((float)(uintptr_t)local_6c - fVar6);
    local_88[0] = param_2 + 5;
    local_88[1] = param_2 + 8;
    local_7c = 0;
    local_64 = local_68 - fVar6;
    local_60 = local_70 + fVar6;
    local_8c = (float *)((float)(uintptr_t)local_6c + fVar6);
    local_9c = local_68 + fVar6;

    do {
      local_98 = *local_88[local_7c & 1];
      local_94 = (float *)local_88[(int)local_7c >> 1 & 1][1];
      local_90 = local_88[(int)local_7c >> 2 & 1][2];
      FUN_0076f6e0();
      local_70 = local_5c;
      local_6c = local_58;
      local_98 = local_5c;
      local_68 = local_54;
      local_94 = local_58;
      local_90 = local_54;

      // X min expand
      pfVar5 = &local_98;
      if (local_5c <= local_74) {
        pfVar5 = &local_74;
      }
      if (pfVar3[5] <= *pfVar5 && *pfVar5 != pfVar3[5]) {
        pfVar5 = pfVar3 + 5;
      }
      pfVar3[5] = *pfVar5;

      // Y min
      ppfVar4 = &local_94;
      if ((float)(uintptr_t)local_58 <= (float)(uintptr_t)local_78) {
        ppfVar4 = &local_78;
      }
      if (pfVar3[6] <= (float)*ppfVar4 && (float)*ppfVar4 != pfVar3[6]) {
        ppfVar4 = (float **)(pfVar3 + 6);
      }
      pfVar3[6] = (float)*ppfVar4;

      // Z min
      pfVar5 = &local_90;
      if (local_54 <= local_64) {
        pfVar5 = &local_64;
      }
      if (pfVar3[7] <= *pfVar5 && *pfVar5 != pfVar3[7]) {
        pfVar5 = pfVar3 + 7;
      }
      pfVar3[7] = *pfVar5;

      // X max
      pfVar5 = &local_98;
      if (local_60 <= local_5c) {
        pfVar5 = &local_60;
      }
      if (*pfVar5 <= pfVar3[8] && pfVar3[8] != *pfVar5) {
        pfVar5 = pfVar3 + 8;
      }
      pfVar3[8] = *pfVar5;

      // Y max
      ppfVar4 = &local_94;
      if ((float)(uintptr_t)local_8c <= (float)(uintptr_t)local_58) {
        ppfVar4 = &local_8c;
      }
      if ((float)*ppfVar4 <= pfVar3[9] && pfVar3[9] != (float)*ppfVar4) {
        ppfVar4 = (float **)(pfVar3 + 9);
      }
      pfVar3[9] = (float)*ppfVar4;

      // Z max
      pfVar5 = &local_90;
      if (local_9c <= local_54) {
        pfVar5 = &local_9c;
      }
      if (*pfVar5 <= pfVar3[10] && pfVar3[10] != *pfVar5) {
        pfVar5 = pfVar3 + 10;
      }
      pfVar3[10] = *pfVar5;

      local_7c = local_7c + 1;
    } while ((int)local_7c < 8);

    *(uint8_t *)(pfVar3 + 0xb) = 0;
    pfVar3[4] = std::fabs(std::sqrt((pfVar3[8] - *pfVar3) * (pfVar3[8] - *pfVar3) +
                                    (pfVar3[10] - pfVar3[2]) * (pfVar3[10] - pfVar3[2])));
  }
  return;
}
