// =============================================================================
// FUN_00444810 — twin of StringVecShell_TidyAndClearGlobal
// -----------------------------------------------------------------------------
// Stable ID: aa_00444810
// Address:   0x00444810–0x0044484A exclusive (58 B)
// Wave:      W34-K 2026-07-29
// Prefer:    reconstructed-exact/StringVecShell_TidyAndClearGlobal.cpp
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;
  uint8_t* begin;
  uint8_t* end;
  uint8_t* capEnd;
};

extern "C" void __fastcall StringVec_Tidy(StringVecShell* self);
extern "C" StringVecShell* DAT_00d1f1fc;

extern "C" void __fastcall FUN_00444810(StringVecShell* shell)
{
  StringVec_Tidy(shell);
  DAT_00d1f1fc = nullptr;
}
