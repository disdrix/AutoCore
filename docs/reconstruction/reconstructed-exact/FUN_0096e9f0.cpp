// =============================================================================
// FUN_0096e9f0 — clean twin of EffTexture_CreateInstance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e9f0
// Address:   0x0096e9f0–0x0096ea5a exclusive (106 B / 0x6A)
// Wave:      W38-O 2026-08-04
// =============================================================================
// Twin of EffTexture_CreateInstance_Inferred.cpp (same behavior).
// Prefer the named clean for ports.

#include <cstdint>

struct EffTextureObj;

extern "C" EffTextureObj* __stdcall EffTexture_CreateInstance_Inferred(
    uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4
    /*EBX = const uint32_t dims[2]*/);

// Scaffold-compatible symbol; register dims* is EBX in retail.
extern "C" EffTextureObj* __stdcall FUN_0096e9f0(
    uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4)
{
  return EffTexture_CreateInstance_Inferred(a0, a1, a2, a3, a4);
}
