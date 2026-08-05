// =============================================================================
// D3dFormat_GetBitsPerPixel_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ead0
// Address:   0x0040ead0  (autoassault.exe, image base 0x400000)
// System:    Graphics — D3DFORMAT → bits-per-pixel lookup
// Wave:      W38-T dual seal 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Map a D3D format enum value to bits-per-pixel for memory
//   accounting and pitch math. Unsupported → 0. Callers typically
//   `bpp >> 3` then multiply by width × height × mip levels.
// ABI: __cdecl; stack (format); returns uint32_t bpp; plain RET.
// Leaf: no callees.
//

#include <cstdint>

uint32_t D3dFormat_GetBitsPerPixel_Inferred(uint32_t d3d_format)
{
  switch (d3d_format) {
  case 0x14: // D3DFMT_R8G8B8
    return 24;

  case 0x15: // D3DFMT_A8R8G8B8
  case 0x16: // D3DFMT_X8R8G8B8
  case 0x23: // D3DFMT_A2B10G10R10
  case 0x70:
  case 0x72:
    return 32;

  case 0x17: // D3DFMT_R5G6B5
  case 0x19: // D3DFMT_A1R5G5B5
  case 0x1a: // D3DFMT_A4R4G4B4
  case 0x33: // D3DFMT_A8L8
  case 0x6f:
    return 16;

  case 0x1c: // D3DFMT_A8
  case 0x32: // D3DFMT_L8
    return 8;

  case 0x24: // D3DFMT_A16B16G16R16
  case 0x71:
  case 0x73:
    return 64;

  case 0x74:
    return 128;

  default:
    return 0;
  }
}
