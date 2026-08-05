// =============================================================================
// FUN_00948530  (scaffold twin of Client_InitRenderEngine)
// -----------------------------------------------------------------------------
// Stable ID: aa_00948530
// Address:   0x00948530  (autoassault.exe, image base 0x400000)
// Wave:      W31-Q OWN-ONLY dual 2026-07-29
// Canonical: Client_InitRenderEngine
// =============================================================================
// Full behavior-preserving body lives in Client_InitRenderEngine.cpp.
// This twin keeps the Ghidra name for tooling that keys off FUN_*.

#include <cstdint>

extern "C" uint32_t __fastcall Client_InitRenderEngine(void* app);

extern "C" uint32_t __fastcall FUN_00948530(void* app)
{
  return Client_InitRenderEngine(app);
}
