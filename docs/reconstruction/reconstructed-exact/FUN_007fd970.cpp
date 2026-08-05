// =============================================================================
// FUN_007fd970  (scaffold twin of Ui_WriteFormatColorD3d)
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd970
// Address:   0x007fd970  (autoassault.exe, image base 0x400000)
// System:    ui / gfx
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29 W22-F
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical name: Ui_WriteFormatColorD3d
// See: reconstructed-exact/Ui_WriteFormatColorD3d.cpp
// =============================================================================

#include <stdint.h>

// Ghidra-shaped twin: CL = formatIndex, EAX = out buffer (phantom in decomp).
void __fastcall FUN_007fd970(uint8_t param_1)
{
  uint8_t* in_EAX; /* register EAX — out color */

  switch (param_1) {
  case 0:
    in_EAX[3] = 0xff;
    in_EAX[2] = 0xc1;
    in_EAX[1] = 0xc1;
    *in_EAX = 0xc1;
    return;
  case 1:
    in_EAX[2] = 0;
    in_EAX[1] = 0x8f;
    in_EAX[3] = 0xff;
    *in_EAX = 0xff;
    return;
  case 2:
    in_EAX[2] = 0xff;
    in_EAX[1] = 0x4b;
    *in_EAX = 0x2c;
    in_EAX[3] = 0xff;
    return;
  case 3:
    in_EAX[2] = 0x6c;
    in_EAX[1] = 0xf4;
    *in_EAX = 0xb;
    in_EAX[3] = 0xff;
    return;
  case 4:
    in_EAX[2] = 0xff;
    in_EAX[1] = 0xc9;
    *in_EAX = 0;
    in_EAX[3] = 0xff;
    return;
  default:
    in_EAX[3] = 0xff;
    in_EAX[2] = 0xff;
    in_EAX[1] = 0xff;
    *in_EAX = 0xff;
    return;
  case 100:
    in_EAX[2] = 0xff;
    in_EAX[1] = 0;
    *in_EAX = 0;
    in_EAX[3] = 0xff;
    return;
  case 0x65:
    in_EAX[2] = 0;
    in_EAX[1] = 0xff;
    *in_EAX = 0;
    in_EAX[3] = 0xff;
    return;
  case 0x66:
    in_EAX[2] = 0;
    in_EAX[1] = 0;
    in_EAX[3] = 0xff;
    *in_EAX = 0xff;
    return;
  }
}
