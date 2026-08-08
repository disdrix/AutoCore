// =============================================================================
// FUN_00930f40  (scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_00930f40
// Address:   0x00930f40
// Named:     Ui_NameColorPalette_WriteArgb_Inferred
// See:       Ui_NameColorPalette_WriteArgb_Inferred.cpp  (WQ9E-C dual 2026-08-04)
// =============================================================================

#include <cstdint>

// Scaffold forwarder plate — prefer named unit.
extern "C" uint32_t* __fastcall Ui_NameColorPalette_WriteArgb_Inferred(int mode, uint8_t* out);

extern "C" void __fastcall FUN_00930f40(uint32_t mode) {
  // Decompiler shape retained for grep stability; real ABI uses EAX=out from caller.
  // Do not call this symbol without setting EAX out buffer.
  (void)mode;
  (void)Ui_NameColorPalette_WriteArgb_Inferred;
}
