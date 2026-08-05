// =============================================================================
// FUN_0094b520  (alias plate — see Client_AppFrameTick.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0094b520
// Address:   0x0094b520 – 0x0094b9b5  (autoassault.exe, image base 0x400000)
// System:    client / main-loop frame
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W20-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Canonical clean: reconstructed-exact/Client_AppFrameTick.cpp
// =============================================================================

#include <cstdint>

extern uint32_t __fastcall Client_AppFrameTick(void *client /* ECX */);

extern "C" uint32_t __fastcall FUN_0094b520(void *param_1)
{
  return Client_AppFrameTick(param_1);
}
