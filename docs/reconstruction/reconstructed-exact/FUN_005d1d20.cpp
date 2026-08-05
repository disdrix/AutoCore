// =============================================================================
// FUN_005d1d20 / Math_QuatExtractForwardZ_OutFirst_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005d1d20
// Address:   0x005d1d20  (autoassault.exe, image base 0x400000)
// Body:      0x005d1d20–0x005d1d93 (116 B); bare RET; pad CC
// System:    math / quat → local +Z (rotation matrix column 2)
// Generated: 2026-07-29 W27-J live decompile + read_memory seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Twin algebra: Math_QuatExtractForwardZ @ 0x004e8a40 — same formula, args (quat,out)
// This unit: args (out, quat)
// =============================================================================

// PURPOSE:
//   From unit quaternion q=(x,y,z,w) at param_2, write world-space local +Z
//   (forward) into param_1 as float4 with W=0:
//     out.x = 2*(z*x + y*w)
//     out.y = 2*(z*y - x*w)
//     out.z = 1 - 2*(x*x + y*y)
//     out.w = 0
//   No normalize; non-unit input → non-unit axis.

// ABI:
//   __cdecl: param_1 = out float[4]*, param_2 = quat float[4]* XYZW

// CONSTANTS (read_memory):
//   g_flLevelUpUiBase_Inferred @ 0x00a10e74 = 2.0f  (00 00 00 40) — factor 2
//   g_flOne                    @ 0x00a0f2a0 = 1.0f  (00 00 80 3f)

extern float g_flLevelUpUiBase_Inferred; // 2.0f @ 0x00a10e74
extern float g_flOne;                    // 1.0f @ 0x00a0f2a0

void FUN_005d1d20(float *param_1 /* out */, float *param_2 /* quat XYZW */)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;

  fVar5 = g_flLevelUpUiBase_Inferred;
  fVar1 = param_2[2];
  fVar2 = *param_2;
  fVar6 = g_flOne - (*param_2 * *param_2 + param_2[1] * param_2[1]) * g_flLevelUpUiBase_Inferred;
  fVar3 = param_2[3];
  fVar4 = param_2[1];
  param_1[1] = (param_2[2] * param_2[1] - param_2[3] * *param_2) * g_flLevelUpUiBase_Inferred;
  *param_1 = (fVar3 * fVar4 + fVar1 * fVar2) * fVar5;
  param_1[2] = fVar6;
  param_1[3] = 0.0f;
  return;
}
