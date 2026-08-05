// =============================================================================
// Math_Float3_IsFiniteIEEE_Inferred  (Ghidra: FUN_005d6870)
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6870
// Address:   0x005d6870
// Twin:      docs/reconstruction/reconstructed-exact/FUN_005d6870.cpp
// =============================================================================

#include <stdint.h>

// Port contract (thiscall):
//   ECX = base of three float32 values
//   stack arg = out flag byte*
//   *outOk = 1 if all three finite (no Inf/NaN); else 0
//   RET 4
//
// Mask 0x7f800000 isolates the binary32 exponent field. Equality with the same
// mask means exponent == 255 → Inf or NaN. Zero and denormals pass.

void __thiscall Math_Float3_IsFiniteIEEE_Inferred(float *vec3, uint8_t *outOk)
{
  int i = 0;
  do {
    if ((*(uint32_t *)((char *)vec3 + i * 4) & 0x7f800000u) == 0x7f800000u) {
      *outOk = 0;
      return;
    }
    i = i + 1;
  } while (i < 3);
  *outOk = 1;
}
