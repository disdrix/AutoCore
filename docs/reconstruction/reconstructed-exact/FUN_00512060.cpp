// =============================================================================
// FUN_00512060  (alias plate — see CVOGHB_TargetingLink_complete_dtor_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00512060
// Address:   0x00512060 – 0x0051206a  (autoassault.exe, image base 0x400000)
// System:    heartbeat / targeting-link
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W20-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Canonical clean: reconstructed-exact/CVOGHB_TargetingLink_complete_dtor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void *PTR_FUN_009cdfb0[];
extern void __fastcall FUN_00508390(void *thisHb /* ECX */);

void __fastcall FUN_00512060(void *param_1 /* ECX */)
{
  *reinterpret_cast<void **>(param_1) = PTR_FUN_009cdfb0;
  FUN_00508390(param_1);
}
