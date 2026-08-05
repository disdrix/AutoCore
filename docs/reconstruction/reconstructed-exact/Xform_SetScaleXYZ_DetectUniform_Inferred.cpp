// =============================================================================
// Xform_SetScaleXYZ_DetectUniform_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b440
// Address:   0x0044b440  (autoassault.exe, image base 0x400000)
// System:    gfx / xform-matrix subobject
// Generated: 2026-08-04 W37-R
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Write scale XYZ on a transform/matrix subobject when any component changes.
//   Invalidate cache token (+0xBC = -1), bump revision (+0xB4), set uniform
//   flag (+0xB8): 0 if |x-y| and |x-z| <= eps (~1e-5 @ DAT_00aaa620), else 1.
//
// ABI (bytes): __thiscall; ECX=this; stack float x,y,z; RET 0x0C. Leaf.
// Reject: Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_0044b440
//
// See also: reconstructed-exact/FUN_0044b440.cpp (decompiler-faithful twin)

#include <cmath>
#include <cstdint>

extern "C" float DAT_00aaa620; // 0x00aaa620 ≈ 1e-5f

void __thiscall Xform_SetScaleXYZ_DetectUniform_Inferred(
    void* this_ptr, float x, float y, float z)
{
  auto* base = reinterpret_cast<std::uint8_t*>(this_ptr);
  float* sx = reinterpret_cast<float*>(base + 0x9C);
  float* sy = reinterpret_cast<float*>(base + 0xA0);
  float* sz = reinterpret_cast<float*>(base + 0xA4);

  if (x == *sx && y == *sy && z == *sz) {
    return;
  }

  *sx = x;
  *sy = y;
  *sz = z;
  *reinterpret_cast<std::uint32_t*>(base + 0xBC) = 0xFFFFFFFFu;

  if (std::fabs(*sx - *sy) <= DAT_00aaa620 &&
      std::fabs(*sx - *sz) <= DAT_00aaa620) {
    *(base + 0xB8) = 0;
    *reinterpret_cast<std::int32_t*>(base + 0xB4) += 1;
    return;
  }

  *reinterpret_cast<std::int32_t*>(base + 0xB4) += 1;
  *(base + 0xB8) = 1;
}
