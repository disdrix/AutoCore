// =============================================================================
// Input_KeyCodeToDisplayName
// -----------------------------------------------------------------------------
// Stable ID: aa_007f5120
// Address:   0x007f5120–0x007f5d9c  (autoassault.exe, image base 0x400000)
// System:    input-drive-control / UI keybind display
// Generated: 2026-07-23 scaffold; dual seal refine 2026-08-04 WQ7R-G
// Exactness: Behavior-preserving summary of decompiler control flow + sealed ABI.
//            Full DIK case table lives in Ghidra raw; this clean is the contract.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
//
// Purpose:  Map input key code (DIK / mouse 0xF00+ / joy synthetic) to a
//           display C string for keybind UI.
//
// Convention (asm-sealed):
//   DX  = keyCode (u16)
//   EAX = const char* name (static DAT_00d1f73c, snprintf DAT_00d1f0f8, or empty)
//
// Related:
//   ActionMap_FormatSlotBindDisplay  0x007f9160  (primary consumer)
//   reviews/A|B_aa_007f5120_Input_KeyCodeToDisplayName.md
// =============================================================================

/*
 * Behavioral notes:
 * - Clears DAT_00d1f73c[0] then fills from string tables / single-letter ASCII.
 * - Mouse: 0xF00..0xF07 → MOUSE1.. class strings.
 * - Joy: 0xF000.. → Joy_Button / Joy_Axis / Joy_POV via _snprintf into DAT_00d1f0f8.
 * - Unknown low codes with empty fill → DAT_00a1419b ("").
 * - Static buffers: not re-entrant across nested UI format calls without copy.
 */

#include <stdint.h>
#include <stdio.h>

// Image-static symbols (addresses for documentation; not linked here)
// char DAT_00d1f73c[];   // work name buffer
// char DAT_00d1f0f8[0x104];
// char DAT_00a1419b[];   // ""

extern int _snprintf(char* buf, size_t n, const char* fmt, ...);

const char* Input_KeyCodeToDisplayName(uint16_t keyCode /* DX */)
{
  // Authoritative full switch: docs/reconstruction/raw/aa_007f5120_FUN_007f5120.md
  // Contract sketch:

  // 1) Special-case mouse band 0xF00..0xF07 → "MOUSE1".."MOUSE8"-class
  // 2) DIK switch (1=ESCAPE, 2..0xB digits, letters, modifiers, F-keys, nav, numpad, …)
  //    write into static work buffer; if non-empty return it
  // 3) if keyCode < 0xF000 return empty ""
  // 4) if keyCode > 0xF1FF: snprintf "Joy_POV%d_%c" (POV index + N/E/S/W)
  // 5) if keyCode < 0xF100: snprintf "Joy_Button%03d"
  // 6) else: snprintf "Joy_Axis%s%c%c" (Rot/Slider/Force + axis + +/-)

  (void)keyCode;
  return ""; // placeholder — use raw/Ghidra for full case table port
}
