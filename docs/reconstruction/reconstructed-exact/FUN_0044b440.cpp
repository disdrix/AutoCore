// =============================================================================
// FUN_0044b440  (twin of Xform_SetScaleXYZ_DetectUniform_Inferred)
// Stable ID: aa_0044b440  VA: 0x0044b440  Wave: W37-R
// ABI: __thiscall; ECX=this; stack float x,y,z; RET 0x0C. Leaf.
// =============================================================================

#include <cmath>
#include <cstdint>

extern "C" float DAT_00aaa620; // ≈ 1e-5f @ 0x00aaa620

void __thiscall FUN_0044b440(int param_1, float param_2, float param_3, float param_4)
{
  float* pfVar1 = reinterpret_cast<float*>(param_1 + 0x9C);

  if ((param_2 != *reinterpret_cast<float*>(param_1 + 0x9C)) ||
      (param_3 != *reinterpret_cast<float*>(param_1 + 0xA0)) ||
      (param_4 != *reinterpret_cast<float*>(param_1 + 0xA4))) {
    *pfVar1 = param_2;
    *reinterpret_cast<float*>(param_1 + 0xA0) = param_3;
    *reinterpret_cast<float*>(param_1 + 0xA4) = param_4;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0xBC) = 0xFFFFFFFFu;

    if ((std::fabs(*pfVar1 - *reinterpret_cast<float*>(param_1 + 0xA0)) <= DAT_00aaa620) &&
        (std::fabs(*pfVar1 - *reinterpret_cast<float*>(param_1 + 0xA4)) <= DAT_00aaa620)) {
      *reinterpret_cast<std::uint8_t*>(param_1 + 0xB8) = 0;
      *reinterpret_cast<int*>(param_1 + 0xB4) =
          *reinterpret_cast<int*>(param_1 + 0xB4) + 1;
      return;
    }
    *reinterpret_cast<int*>(param_1 + 0xB4) =
        *reinterpret_cast<int*>(param_1 + 0xB4) + 1;
    *reinterpret_cast<std::uint8_t*>(param_1 + 0xB8) = 1;
  }
}
