// =============================================================================
// Math_QuatInverseRotateDelta_Inferred  (named alias of FUN_004e8590)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8590
// Address:   0x004e8590  (autoassault.exe, image base 0x400000)
// Span:      004e8590 – 004e87ce (575 B; cdecl leaf; ret)
// Dual A/B:  2026-07-29 accept-with-gaps (W23-O)
// Authoritative clean twin: FUN_004e8590.cpp
// =============================================================================

/*
 * out.xyz = R(quat_xyzw)^T * (world_point.xyz - origin.xyz); out.w unwritten.
 * TWO @ 0x00a10e74 = 2.0f; ONE @ 0x00a0f2a0 = 1.0f.
 */

void Math_QuatInverseRotateDelta_Inferred(float *origin, float *quat_xyzw,
                                          float *world_point, float *out_local)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;

  fVar3 = (*quat_xyzw * quat_xyzw[1] - quat_xyzw[3] * quat_xyzw[2]) * g_flLevelUpUiBase_Inferred;
  fVar4 = *quat_xyzw * *quat_xyzw;
  fVar6 = g_flOne - (quat_xyzw[2] * quat_xyzw[2] + fVar4) * g_flLevelUpUiBase_Inferred;
  fVar7 = (*quat_xyzw * quat_xyzw[3] + quat_xyzw[2] * quat_xyzw[1]) * g_flLevelUpUiBase_Inferred;
  fVar8 = (*quat_xyzw * quat_xyzw[2] + quat_xyzw[3] * quat_xyzw[1]) * g_flLevelUpUiBase_Inferred;
  fVar9 = (quat_xyzw[2] * quat_xyzw[1] - *quat_xyzw * quat_xyzw[3]) * g_flLevelUpUiBase_Inferred;
  fVar1 = g_flOne - (quat_xyzw[1] * quat_xyzw[1] + fVar4) * g_flLevelUpUiBase_Inferred;
  fVar2 = world_point[1] - origin[1];
  fVar5 = world_point[2] - origin[2];
  fVar4 = *world_point - *origin;
  *out_local = (*quat_xyzw * quat_xyzw[2] - quat_xyzw[3] * quat_xyzw[1]) * g_flLevelUpUiBase_Inferred * fVar5
             + (*quat_xyzw * quat_xyzw[1] + quat_xyzw[3] * quat_xyzw[2]) * g_flLevelUpUiBase_Inferred * fVar2
             + (g_flOne - (quat_xyzw[1] * quat_xyzw[1] + quat_xyzw[2] * quat_xyzw[2]) * g_flLevelUpUiBase_Inferred) * fVar4;
  out_local[1] = fVar7 * fVar5 + fVar6 * fVar2 + fVar3 * fVar4;
  out_local[2] = fVar1 * fVar5 + fVar9 * fVar2 + fVar8 * fVar4;
  return;
}
