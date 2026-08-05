// =============================================================================
// Math_QuatExtractForwardZ  (Ghidra: FUN_004e8a40)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8a40
// Address:   0x004e8a40 – 0x004e8acb  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (pure math leaf)
// Generated: 2026-07-23 scaffold; dual-sealed 2026-07-29 (live Ghidra)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Leaf: no calls, no branches.
// Bit-for-bit vs retail EXE: DEFERRED (algebra closed; image may differ slightly).
// Dual:      reviews/A_aa_004e8a40_Math_QuatExtractForwardZ.md
//            reviews/B_aa_004e8a40_Math_QuatExtractForwardZ.md
// =============================================================================
//
// PURPOSE:
//   Unit quaternion q=(x,y,z,w) → chassis forward (+Z) world direction.
//   out = ( 2(xz+yw),  2(yz-xw),  1-2(x^2+y^2),  0 )
//   Rotation-matrix column 2 for XYZW unit quats (Havok/client chassis).
//
// CONSTANTS:
//   g_flOne                    @ 0x00a0f2a0 = 1.0f   (read_memory 00 00 80 3f)
//   g_flLevelUpUiBase_Inferred @ 0x00a10e74 = 2.0f   (read_memory 00 00 00 40)
//     ^ Ghidra name is a UI misnomer; role here is quat scale factor 2.
//
// CALLING CONVENTION:
//   Stack args (param_1, param_2). Not __thiscall.
//
// NOTE: Does not normalize. Non-unit input yields non-unit axis.
// =============================================================================

// External symbols as named in the loaded Ghidra program:
extern float g_flLevelUpUiBase_Inferred;  // 2.0f @ 0x00a10e74
extern float g_flOne;                     // 1.0f @ 0x00a0f2a0

void FUN_004e8a40(float *param_1, float *param_2)
{
  float fVar1;  // x
  float fVar2;  // y
  float fVar3;  // z
  float fVar4;  // w
  float fVar5;  // 2.0

  fVar5 = g_flLevelUpUiBase_Inferred;
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  fVar4 = param_1[3];
  *param_2 = (fVar3 * fVar1 + fVar2 * fVar4) * g_flLevelUpUiBase_Inferred;
  param_2[1] = (fVar3 * fVar2 - fVar1 * fVar4) * fVar5;
  param_2[2] = g_flOne - (fVar1 * fVar1 + fVar2 * fVar2) * fVar5;
  param_2[3] = 0.0;
  return;
}
