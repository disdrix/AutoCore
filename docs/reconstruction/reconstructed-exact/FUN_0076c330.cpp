// =============================================================================
// FUN_0076c330 / Timer_GetTimeSeconds_Rdtsc
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c330
// Address:   0x0076c330  (autoassault.exe, image base 0x400000)
// System:    timer / util (cross-cutting)
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W16-R dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Lazy-calibrated RDTSC timer → absolute time in **seconds** as x87 float80.
//   If DAT_00d1a530 == 0, FUN_0076c270 fills DAT_00d1a538:DAT_00d1a53c with
//   TSC ticks/second (via QPC calibration) and sets the flag.
//   Then: quot = rdtsc / scale; return quot + rem/scale on ST0.
//
// CALLERS (sample): NDResource_AcquireInnerObject (fstp float @ this+0x1c),
//   assManager / zone helpers, graphics age stamps (many FUN_0067* / 00970*).
//
// ABI: void args, cdecl, return float80 in ST0. RET (no stack cleanup).
// Sibling FUN_0076c3c0 is a different object-relative zone timer — not this unit.

/*
 * Behavioral notes:
 * - Raw ≡ live decompile 2026-07-29; remainder/u64→f80 convert is MSVC idiom.
 * - Scale globals are runtime-filled; static image is zero until first call.
 * - Runtime / differential verification: OPEN.
 */

// Ghidra float10 == long double / x87 80-bit; port may demote to double/float.
typedef long double float10;

extern "C" void     FUN_0076c270(void);
extern "C" unsigned __int64 __aulldiv(unsigned /*lo*/, unsigned /*hi*/,
                                      unsigned /*dlo*/, unsigned /*dhi*/);
// Platform: rdtsc intrinsic / inline. Decompiler models as undefined8.
extern "C" unsigned __int64 rdtsc(void);
// CONCAT44(hi,lo) → 64-bit
#ifndef CONCAT44
#define CONCAT44(hi, lo) (((unsigned __int64)(unsigned)(hi) << 32) | (unsigned)(lo))
#endif

extern "C" unsigned char DAT_00d1a530; // init flag
extern "C" int           DAT_00d1a538; // scale lo (ticks/sec)
extern "C" unsigned      DAT_00d1a53c; // scale hi

float10 FUN_0076c330(void)
{
  unsigned __int64 uVar1;
  int iVar2;
  unsigned uVar3;
  long long lVar4;

  if (DAT_00d1a530 == '\0') {
    FUN_0076c270();
  }
  uVar3 = DAT_00d1a53c;
  iVar2 = DAT_00d1a538;
  uVar1 = rdtsc();
  lVar4 = (long long)__aulldiv((int)uVar1, (int)((unsigned __int64)uVar1 >> 0x20),
                               DAT_00d1a538, DAT_00d1a53c);
  // MSVC unsigned-64 → float80 divisor conversion + rem/quot combine (raw-faithful).
  return (float10)lVar4 +
         (float10)((int)uVar1 - iVar2 * (int)lVar4) /
         (-(float10)(long long)(((unsigned __int64)uVar3 & 0x80000000) << 0x20) +
          (float10)(CONCAT44(uVar3, iVar2) & 0x7fffffffffffffffULL));
}
