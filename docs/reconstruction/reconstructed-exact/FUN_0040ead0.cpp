// =============================================================================
// FUN_0040ead0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ead0
// Address:   0x0040ead0  (autoassault.exe, image base 0x400000)
// System:    Graphics — D3DFORMAT → bits-per-pixel
// Wave:      W38-T dual seal 2026-08-04
// Named plate: D3dFormat_GetBitsPerPixel_Inferred.cpp
// =============================================================================

#include <cstdint>

uint32_t FUN_0040ead0(uint32_t d3d_format)
{
  switch (d3d_format) {
  case 0x14:
    return 24;
  case 0x15:
  case 0x16:
  case 0x23:
  case 0x70:
  case 0x72:
    return 32;
  case 0x17:
  case 0x19:
  case 0x1a:
  case 0x33:
  case 0x6f:
    return 16;
  case 0x1c:
  case 0x32:
    return 8;
  case 0x24:
  case 0x71:
  case 0x73:
    return 64;
  case 0x74:
    return 128;
  default:
    return 0;
  }
}
