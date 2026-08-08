// =============================================================================
// Ui_NameColorPalette_WriteArgb_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00930f40
// Address:   0x00930f40–0x00930f9c  (+ jump table @ 0x00930fa0)
// Module:    autoassault.exe (image base 0x400000)
// System:    client UI / entity name-label color
// Generated: 2026-08-04 WQ9E-C dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Write a fixed AARRGGBB name-color palette entry into a 4-byte out
// buffer from a small integer mode. Leaf helper of
// Ui_ResolveEntityNameColor_Inferred (0x00930fc0).
//
// ABI (custom register):
//   ECX = int mode
//   EAX = uint8_t* outBgra  (out[0]=B, out[1]=G, out[2]=R, out[3]=A)
//   bare ret; EAX preserved as out pointer (callers load *out as uint32)
//
// Palette (mode → AARRGGBB):
//   0 → 0xFFC41616 red
//   1 / default → 0xFFDCE0C8 beige
//   2 → 0xFF66D3EA cyan
//   3 → 0xFF14D314 green
//  -1 → 0xFFFFFFFF white
//
// Implementation note: binary uses (mode+1) jump table; idx>4 falls to beige.
//

#include <cstdint>

// Returns out (same pointer passed in EAX).
extern "C" uint32_t* __fastcall Ui_NameColorPalette_WriteArgb_Inferred(
    int mode /*ECX*/,
    uint8_t* out /*EAX — nonstandard; not an MSVC formal*/) {
  // Normalize to documented switch (matches jump-table + default).
  switch (mode) {
  case 0: // red 0xFFC41616
    out[2] = 0xC4;
    out[1] = 0x16;
    out[0] = 0x16;
    out[3] = 0xFF;
    break;
  case 2: // cyan 0xFF66D3EA
    out[2] = 0x66;
    out[1] = 0xD3;
    out[0] = 0xEA;
    out[3] = 0xFF;
    break;
  case 3: // green 0xFF14D314
    out[2] = 0x14;
    out[1] = 0xD3;
    out[0] = 0x14;
    out[3] = 0xFF;
    break;
  case -1: // white 0xFFFFFFFF
    out[0] = 0xFF;
    out[1] = 0xFF;
    out[2] = 0xFF;
    out[3] = 0xFF;
    break;
  default: // mode 1 and any other → beige 0xFFDCE0C8
    out[2] = 0xDC;
    out[1] = 0xE0;
    out[0] = 0xC8; // 200
    out[3] = 0xFF;
    break;
  }
  return reinterpret_cast<uint32_t*>(out);
}
