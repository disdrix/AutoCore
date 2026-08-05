// =============================================================================
// FUN_00921f70  (scaffold alias of Client_SelectHostileUnderScreenPick_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00921f70
// Address:   0x00921f70–0x009221de  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-07-29 W20-Q dual A/B seal
// Exactness: Scaffold keeps Ghidra name; CF = live decompile (see named clean).
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: Client_SelectHostileUnderScreenPick_Inferred.cpp
// Dual: reviews/A|B_aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md
// =============================================================================

#include <cmath>
#include <cstdint>

// PURPOSE: Screen-ray hostile pick → Client_SelectTargetObject (see named clean).

uint32_t FUN_00921f70(void)
{
  float *pfVar1;
  void *pvVar2;
  int iVar3;
  long double fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float local_74;
  uint32_t local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  // TFID_16 local_30
  uint32_t local_30[4];

  if ((DAT_00d1b6d8 != 0) && (*(char *)((char *)DAT_00d1b6d8 + 0x4f1) == '\0')) {
    local_74 = (float)DAT_00d1d86c;
    local_70 = (uint32_t)DAT_00d1d870;
    GfxView_UnprojectScreenToWorldRay_Inferred(
        /*this*/ 0, &local_74, &local_6c, &local_60);
    fVar4 = FUN_004cd220(local_6c, local_64);
    local_74 = (float)(((long double)local_68 - fVar4) / fabs((long double)local_5c));
    local_4c = local_60 * local_74 + local_6c;
    local_48 = local_5c * local_74 + local_68;
    local_44 = local_58 * local_74 + local_64;
    pfVar1 = Math_CopyFloat3ToFloat4_Inferred(&local_60, &local_4c);
    local_40 = *pfVar1;
    local_3c = pfVar1[1];
    local_38 = pfVar1[2];
    local_34 = pfVar1[3];
    fVar5 = local_40 - *(float *)((char *)DAT_00d17944 + 0x228);
    fVar6 = local_3c - *(float *)((char *)DAT_00d17944 + 0x22c);
    fVar7 = local_38 - *(float *)((char *)DAT_00d17944 + 0x230);
    local_30[0] = DAT_00a158b8;
    local_30[1] = DAT_00a158bc;
    local_74 = sqrtf(fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5) *
               _DAT_00aaacbc * DAT_00aaa6fc;
    local_30[2] = DAT_00a158c0;
    local_30[3] = DAT_00a158c4;
    if (DAT_00a1109c <= local_74) {
      local_74 = DAT_00a1109c;
    }
    if (DAT_00d1b6d8 == 0) {
      iVar3 = 0;
    } else {
      iVar3 = *(int *)(*(int *)((char *)DAT_00d1b6d8 + 4) + 4) + 4 +
              (int)(intptr_t)DAT_00d1b6d8;
    }
    Skill_GatherTargetsInArea(
        local_30, 0,
        *(uint32_t *)(*(int *)(*(int *)((char *)DAT_00d1b6d8 + 4) + 4) + 0xa8 +
                      (int)(intptr_t)DAT_00d1b6d8),
        iVar3, &local_40, local_74, 1, 2, 0, 0, 1, 0, 1, 0, -1.0f);
    iVar3 = TFID_NotEquals(local_30, &DAT_00a158b8);
    if ((char)iVar3 == '\0') {
      Client_SelectTargetObject_Inferred(0);
    } else {
      pvVar2 = Object_ResolveFromTFID(local_30);
      if (pvVar2 != 0) {
        Client_SelectTargetObject_Inferred(pvVar2);
        return 1;
      }
    }
    return 1;
  }
  return 0;
}
