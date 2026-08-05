// =============================================================================
// FUN_00780730 / Profiler_TimerBlock_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00780730
// Address:   0x00780730  (autoassault.exe, image base 0x400000)
// System:    client instrumentation / profiler internals
// Generated: 2026-07-29 W17-S dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + body-byte ABI. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (static dual only).
// =============================================================================

// PURPOSE:
// Construct a 0x30 timer sample block in ESI: zero sample fields, set
// divisor = QueryPerformanceFrequency() / 1_000_000 (ticks per microsecond).
// Returns this in EAX. Sole caller: Profiler zone ctor FUN_00786280 @ 0x00786313.

// ABI:
//   ESI = TimerBlock* (pre-allocated via operator_new(0x30))
//   EAX = TimerBlock* (same)
//   ret 0 (c3) — no stack formals

// Layout (timer block 0x30) — sealed with QpcAccumulate / StartZoneTimer duals:
//   +0x00/+0x04  start QPC
//   +0x08/+0x0c  accum ticks
//   +0x10/+0x14  divisor (ticks/µs)
//   +0x18/+0x1c  average
//   +0x20        count
//   +0x24        last scaled µs
//   +0x28        max scaled µs

#include <cstdint>
#include <windows.h>

struct TimerBlock {
  uint32_t startLo;     // +0x00
  uint32_t startHi;     // +0x04
  uint32_t accumLo;     // +0x08
  uint32_t accumHi;     // +0x0c
  uint32_t divLo;       // +0x10
  uint32_t divHi;       // +0x14
  uint32_t avgLo;       // +0x18
  uint32_t avgHi;       // +0x1c
  uint32_t count;       // +0x20
  uint32_t last;        // +0x24
  uint32_t max;         // +0x28
  uint32_t pad;         // +0x2c (within 0x30 alloc)
};

// MSVC runtime 64/64 divide (as called from body).
extern "C" int64_t __alldiv(uint32_t lo, uint32_t hi, uint32_t dlo, uint32_t dhi);

// ESI this — decompiler shows unaff_ESI; body returns EAX=ESI.
TimerBlock *FUN_00780730(void /* ESI */)
{
  // Body uses ESI; model as register-passed this.
  TimerBlock *self;
#ifdef _MSC_VER
  __asm { mov self, esi }
#else
  self = nullptr; // non-MSVC: call sites must pass ESI
#endif

  self->startLo = 0;
  self->startHi = 0;
  self->accumLo = 0;
  self->accumHi = 0;
  self->avgLo = 0;
  self->avgHi = 0;
  self->count = 0;
  self->last = 0;
  self->max = 0;

  LARGE_INTEGER *lpFrequency = reinterpret_cast<LARGE_INTEGER *>(&self->divLo);
  QueryPerformanceFrequency(lpFrequency);

  // __alldiv(QPF_lo, QPF_hi, 1000000, 0) → ticks per µs
  int64_t scaled = __alldiv(lpFrequency->LowPart, self->divHi, 1000000u, 0u);
  lpFrequency->QuadPart = scaled;

  return self;
}
