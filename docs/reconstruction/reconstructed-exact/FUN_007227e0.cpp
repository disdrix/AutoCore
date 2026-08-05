// =============================================================================
// FUN_007227e0 / Audio_LinearGainToMilliBels
// -----------------------------------------------------------------------------
// Stable ID: aa_007227e0
// Address:   0x007227e0–0x00722821  (autoassault.exe, image base 0x400000)
// System:    audio / interface sound
// Generated: 2026-07-29 W18-M dual A/B seal
// Exactness: Behavior-preserving rewrite. Main path sealed from FPU bytes
//            (FLDLG2/FYL2X), NOT from decompiler linear product.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Convert linear amplitude gain x in (0,1) to millibels:
//          2000 * log10(x)  (== 100 * 20*log10(x)).
//          Clamp: x<=0 -> -10000; x>=1 -> 0.
//          Leaf; __stdcall float arg; return ST0.

// READABILITY:
//  - Decompiler expression 0.30103*(1/x)*(-2000) is REJECTED (linear).
//  - Constants: DAT_00aaa5d8=-10000.f, g_flZero=0, g_flOne=1,
//               _DAT_00aaa5d0=-2000.0 (double).

#include <cmath>

// Retail constants (VA annotations for reconstruction docs)
// DAT_00aaa5d8 @ 0x00aaa5d8 = -10000.0f
// g_flOne      @ 0x00a0f2a0 = 1.0f
// g_flZero     @ 0x00a0f518 = 0.0f
// _DAT_00aaa5d0@ 0x00aaa5d0 = -2000.0 (double)

extern "C" float DAT_00aaa5d8; // -10000.f
extern "C" float g_flOne;      // 1.f
extern "C" float g_flZero;     // 0.f
extern "C" double _DAT_00aaa5d0; // -2000.0

// __stdcall; return in ST0 (x87). Clean models as long double / float10.
long double __stdcall FUN_007227e0(float param_1)
{
  if (param_1 <= 0.0f) {
    return (long double)DAT_00aaa5d8; // -10000.f
  }
  if (g_flOne <= param_1) {
    return (long double)g_flZero; // 0.f
  }
  // Hardware: FLD 1.0; FDIV x; FLDLG2; FXCH; FYL2X; FMUL -2000.0
  // = log10(1/x) * (-2000) = 2000 * log10(x)
  const long double inv = (long double)g_flOne / (long double)param_1;
  const long double log10_inv = log10l(inv); // matches FLDLG2+FYL2X on 1/x
  return log10_inv * (long double)_DAT_00aaa5d0;
}
