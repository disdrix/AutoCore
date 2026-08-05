// =============================================================================
// Quat_FromAxisAngle_Inferred  (Ghidra: FUN_00567ce0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00567ce0
// Address:   0x00567ce0  (autoassault.exe, image base 0x400000)
// System:    math / orientation (cross-cutting)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Axis-angle → quaternion (radians). Half-angle via DAT_00a0f298 (0.5f):
//     out.xyz = sin(θ/2) * axis.xyz
//     out.w   = cos(θ/2)
//   Does not normalize axis or result. Axis must be readable as float[4]
//   (axis.w is loaded and briefly written to out.w, then overwritten by cos).
//
// ABI (sealed dual A/B 2026-07-29):
//   ECX          = float* pOutQuat   (4 floats)
//   [esp+4]      = float* pAxis      (reads [0..3])
//   [esp+8]      = float  flAngleRad
//   Epilogue     = RET 8
//   Return       = void
//
// Constants:
//   DAT_00a0f298 @ 0x00a0f298 = 0.5f (read_memory 00 00 00 3f)

// External (image):
// extern float DAT_00a0f298; // 0.5f

void Quat_FromAxisAngle_Inferred(float *pOutQuat, float *pAxis, float flAngleRad)
{
  float half;
  float s;
  float c;

  /* half = angle * 0.5f */
  half = flAngleRad * DAT_00a0f298;
  s = (float)fsin((float10)half);

  pOutQuat[0] = s * pAxis[0];
  pOutQuat[1] = s * pAxis[1];
  pOutQuat[2] = s * pAxis[2];
  /* retail: temporary store s * axis[3] then overwrite — preserve order */
  pOutQuat[3] = s * pAxis[3];

  c = (float)fcos((float10)half);
  pOutQuat[3] = c;
  return;
}
