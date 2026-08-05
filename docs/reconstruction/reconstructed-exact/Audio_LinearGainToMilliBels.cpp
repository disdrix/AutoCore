// =============================================================================
// Audio_LinearGainToMilliBels  (INFERRED name for FUN_007227e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_007227e0
// Address:   0x007227e0–0x00722821  (autoassault.exe, image base 0x400000)
// System:    audio / interface sound
// Generated: 2026-07-29 W18-M dual A/B seal
// Exactness: Behavior-preserving; FPU-sealed log path.
// =============================================================================

#include <cmath>

// Named clean port of FUN_007227e0.
// Retail clamps and scale constants preserved as literals matching read_memory.

float Audio_LinearGainToMilliBels(float linearGain)
{
  if (linearGain <= 0.0f) {
    return -10000.0f;
  }
  if (linearGain >= 1.0f) {
    return 0.0f;
  }
  // 2000 * log10(gain)  == millibels of amplitude gain
  // Retail: FLDLG2; FYL2X(1/gain); FMUL -2000.0
  return (float)(2000.0 * std::log10(static_cast<double>(linearGain)));
}
