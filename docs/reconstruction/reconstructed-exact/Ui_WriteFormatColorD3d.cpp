// =============================================================================
// Ui_WriteFormatColorD3d
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd970
// Address:   0x007fd970  (autoassault.exe, image base 0x400000)
// System:    ui / gfx
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29 W22-F
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  Leaf: map a UI/format color index (CL) to a 4-byte little-endian
//           D3DCOLOR (AARRGGBB as bytes [B,G,R,A]) written through EAX.
//
// Convention (asm-sealed):
//   EAX = uint8_t* outColor  (D3DCOLOR*)
//   CL  = formatIndex        (0..0x66; >0x66 → default white)
//   return EAX = outColor
//
// Dispatch: index table @ 0x007fda3c; jump table @ 0x007fda18 (9 targets).
// Body: 0x007fd970–0x007fda16 (167 B). Leaf — no callees.
//
// Related:
//   UiHost_RefreshTrackedNodeWidgets  0x00871150  (CL = node+0x1c − 0x0f)
//   FUN_00870e80 tracked-list redraw
//   FUN_00814d80 arena scores
//   reviews/A|B_aa_007fd970_Ui_WriteFormatColorD3d.md
// =============================================================================

/*
 * Behavioral notes:
 * - Cases 0..4: packed UI palette colors (product names Tentative).
 * - Cases 100/101/102: pure red/green/blue.
 * - Default and unmapped indices 5..99: opaque white.
 * - Alpha always 0xFF for every sealed case.
 */

#include <stdint.h>

// Returns out (same pointer). Matches EAX-preserving leaf.
uint8_t* Ui_WriteFormatColorD3d(uint8_t formatIndex /*CL*/, uint8_t* out /*EAX*/)
{
  switch (formatIndex) {
  case 0:
    out[0] = 0xC1; out[1] = 0xC1; out[2] = 0xC1; out[3] = 0xFF;
    return out;
  case 1:
    out[0] = 0xFF; out[1] = 0x8F; out[2] = 0x00; out[3] = 0xFF;
    return out;
  case 2:
    out[0] = 0x2C; out[1] = 0x4B; out[2] = 0xFF; out[3] = 0xFF;
    return out;
  case 3:
    out[0] = 0x0B; out[1] = 0xF4; out[2] = 0x6C; out[3] = 0xFF;
    return out;
  case 4:
    out[0] = 0x00; out[1] = 0xC9; out[2] = 0xFF; out[3] = 0xFF;
    return out;
  case 100: /* 0x64 */
    out[0] = 0x00; out[1] = 0x00; out[2] = 0xFF; out[3] = 0xFF;
    return out;
  case 0x65:
    out[0] = 0x00; out[1] = 0xFF; out[2] = 0x00; out[3] = 0xFF;
    return out;
  case 0x66:
    out[0] = 0xFF; out[1] = 0x00; out[2] = 0x00; out[3] = 0xFF;
    return out;
  default:
    out[0] = 0xFF; out[1] = 0xFF; out[2] = 0xFF; out[3] = 0xFF;
    return out;
  }
}
