// =============================================================================
// FUN_00404c00  (Ghidra twin of Math_Vec3_Length_Sqrt_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404c00
// Address:   0x00404c00 – 0x00404c20 inclusive
// Dual:      MEGA-060 2026-08-05
// Canonical: docs/reconstruction/reconstructed-exact/Math_Vec3_Length_Sqrt_Inferred.cpp
// =============================================================================

// Ghidra name retained for path stability. Prefer Math_Vec3_Length_Sqrt_Inferred.

double FUN_00404c00(const float *param_1 /* ECX */)
{
  const double x = static_cast<double>(param_1[0]);
  const double y = static_cast<double>(param_1[1]);
  const double z = static_cast<double>(param_1[2]);
  return __builtin_sqrt(x * x + y * y + z * z);
}
