// =============================================================================
// Gfx_DepthStencilFormat_ToBpp_Inferred  (Ghidra: FUN_0043b800)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043b800
// Address:   0x0043b800  (autoassault.exe, image base 0x400000)
// System:    graphics / D3D9 depth-stencil format utility
// Generated: 2026-08-04 W38-U dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte jump table.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Map a D3D9 depth/stencil D3DFORMAT enum value to bits-per-pixel.
//   ABI: EAX = format in; EAX = bpp out (0 if unknown); plain RET.
//   Impl is a jump table over format-0x47 in range [0..9]; this source uses
//   an equivalent switch.
//
// PRODUCT ENUM MATCH (D3D9):
//   0x47 D3DFMT_D32      → 32
//   0x49 D3DFMT_D15S1    → 15
//   0x4B D3DFMT_D24S8    → 24
//   0x4D D3DFMT_D24X8    → 24
//   0x4F D3DFMT_D24X4S4  → 24
//   0x50 D3DFMT_D16      → 16
//
// TWIN (not this unit): FUN_0040ead0 maps color/texture D3DFORMAT → bpp.
//
// BODY: 0x0043b800–0x0043b831 exclusive (49 B). Dual: accept.
// =============================================================================

#include <cstdint>

// Documentary signature — real ABI is EAX in / EAX out / RET.
extern "C" uint32_t Gfx_DepthStencilFormat_ToBpp_Inferred(uint32_t format /*EAX*/)
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
