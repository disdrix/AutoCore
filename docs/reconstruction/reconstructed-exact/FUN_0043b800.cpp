// =============================================================================
// FUN_0043b800  — twin of Gfx_DepthStencilFormat_ToBpp_Inferred
// Stable ID: aa_0043b800 | VA 0x0043b800 | W38-U
// Prefer named clean: Gfx_DepthStencilFormat_ToBpp_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" uint32_t FUN_0043b800(uint32_t format /*EAX*/)
{
  switch (format) {
  case 0x47:
    return 0x20;
  case 0x49:
    return 0x0F;
  case 0x4B:
  case 0x4D:
  case 0x4F:
    return 0x18;
  case 0x50:
    return 0x10;
  default:
    return 0;
  }
}
