// =============================================================================
// FUN_00797530 — twin of UiTextLayout_Finalize_Inferred (aa_00797530)
// -----------------------------------------------------------------------------
// Address:   0x00797530  (autoassault.exe, image base 0x400000)
// Body:      0x00797530–0x00797987 inclusive (1112 B / 0x458)
// Wave:      MEGA-122 OWN-ONLY dual 2026-08-05
// Canonical: UiTextLayout_Finalize_Inferred
// Exactness: Twin entry; full body in UiTextLayout_Finalize_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void __stdcall UiTextLayout_Finalize_Inferred(char flag);

// Machine ABI: EBX = layout*; stack char flag; SEH LAB_009add2c; RET 4.
extern "C" void __stdcall FUN_00797530(char flag)
{
  UiTextLayout_Finalize_Inferred(flag);
}
