// =============================================================================
// Named_CalleeOf_Client_PlayNamedInterfaceSound_007227e0
// Alias of Audio_LinearGainToMilliBels / FUN_007227e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007227e0
// Address:   0x007227e0  (autoassault.exe, image base 0x400000)
// System:    audio / interface sound
// Generated: 2026-07-29 W18-M dual A/B seal (replaces 2026-07-23 scaffold)
// =============================================================================

// Prefer: reconstructed-exact/Audio_LinearGainToMilliBels.cpp
// Prefer: reconstructed-exact/FUN_007227e0.cpp
// This file kept as xref-seed alias only.

#include <cmath>

float Named_CalleeOf_Client_PlayNamedInterfaceSound_007227e0(float linearGain)
{
  if (linearGain <= 0.0f) {
    return -10000.0f;
  }
  if (linearGain >= 1.0f) {
    return 0.0f;
  }
  return (float)(2000.0 * std::log10(static_cast<double>(linearGain)));
}
