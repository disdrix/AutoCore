// =============================================================================
// Client_Map_RaySegmentHitDistance_Inferred  (named alias of FUN_00916090)
// -----------------------------------------------------------------------------
// Stable ID: aa_00916090
// Address:   0x00916090
// Dual A/B:  2026-07-29 accept-with-gaps (W23-O)
// Authoritative clean twin: FUN_00916090.cpp
// =============================================================================

/*
 * Cast segment start→end through client map collision; return hit distance or 0.
 * stdcall 6 floats; ST0 return; optional ESI hitOut.
 * Filter=7; map = DAT_00d1b644; ctx = map+0xe4a4.
 */

float10 Client_Map_RaySegmentHitDistance_Inferred(
    float start_x, float start_y, float start_z,
    float end_x, float end_y, float end_z)
{
  int *unaff_ESI;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  uint32_t local_64;
  float local_60;
  float local_5c;
  float local_58;
  uint32_t local_54;
  uint8_t local_50;
  uint32_t local_4c;
  uint8_t local_40[20];
  float local_2c;
  int local_20;

  local_70 = start_x;
  local_6c = start_y;
  local_68 = start_z;
  local_60 = end_x;
  local_64 = 0;
  local_5c = end_y;
  local_54 = 0;
  local_50 = 0;
  local_4c = 7;
  local_58 = end_z;
  local_2c = g_flOne;
  local_20 = 0;
  FUN_0055e530(&local_70, local_40);
  if (local_20 != 0) {
    if (unaff_ESI != (int *)0x0) {
      *unaff_ESI = local_20;
    }
    fVar1 = g_flOne - local_2c;
    fVar2 = fVar1 * local_70;
    fVar5 = local_60 * local_2c;
    fVar3 = local_5c * local_2c;
    fVar6 = local_6c * fVar1;
    fVar4 = local_58 * local_2c;
    fVar1 = local_68 * fVar1;
    FUN_004e9530(&local_80, &start_x);
    local_80 = (fVar2 + fVar5) - local_80;
    local_7c = (fVar3 + fVar6) - local_7c;
    local_78 = (fVar4 + fVar1) - local_78;
    return SQRT((float10)local_80 * (float10)local_80 +
                (float10)local_7c * (float10)local_7c +
                (float10)local_78 * (float10)local_78);
  }
  if (unaff_ESI != (int *)0x0) {
    *unaff_ESI = 0;
  }
  return (float10)g_flZero;
}
