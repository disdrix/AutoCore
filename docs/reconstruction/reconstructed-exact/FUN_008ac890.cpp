// =============================================================================
// FUN_008ac890  (Ghidra symbol twin of UI_MissionDialog_SetResponseCountAndRebuild_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac890
// Address:   0x008ac890  (autoassault.exe, image base 0x400000)
// System:    missions-progression / client UI mission dialog
// Dual:      MEGA-109 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Prefer named clean:
//   docs/reconstruction/reconstructed-exact/UI_MissionDialog_SetResponseCountAndRebuild_Inferred.cpp

void __fastcall FUN_008ac890(int param_1 /* ECX dialog */, int count_in_EAX /* register */)
{
  // Decompiler surfaces count as in_EAX; bytes: CMP EAX,8 / store [ECX+0x510]
  *(int*)(param_1 + 0x510) = count_in_EAX;
  if (8 < count_in_EAX) {
    *(std::uint32_t*)(param_1 + 0x510) = 8;
  }
  // FUN_008ac110 — UI_MissionDialog_BuildResponseButtons_Inferred (EDI=this)
  extern void FUN_008ac110(void);
  FUN_008ac110();
}
