// =============================================================================
// Profiler_TimerBlock_Ctor  (named contract for aa_00780730)
// -----------------------------------------------------------------------------
// Stable ID: aa_00780730
// Address:   0x00780730
// See FUN_00780730.cpp for full scaffold body notes.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct ProfilerTimerBlock {
  uint64_t startQpc;   // +0x00
  uint64_t accum;      // +0x08
  uint64_t divisor;    // +0x10  // QPF / 1e6 = ticks per µs
  uint64_t avg;        // +0x18
  uint32_t count;      // +0x20
  uint32_t lastUs;     // +0x24
  uint32_t maxUs;      // +0x28
};

extern "C" int64_t __alldiv(uint32_t lo, uint32_t hi, uint32_t dlo, uint32_t dhi);

// Register ABI: ESI in, EAX out (= ESI). No stack args.
ProfilerTimerBlock *Profiler_TimerBlock_Ctor(ProfilerTimerBlock *self /* ESI */)
{
  self->startQpc = 0;
  self->accum = 0;
  self->avg = 0;
  self->count = 0;
  self->lastUs = 0;
  self->maxUs = 0;

  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  // Body writes divisor at self+0x10 via same storage used for QPF out-param.
  int64_t ticksPerUs = __alldiv(
      static_cast<uint32_t>(freq.LowPart),
      static_cast<uint32_t>(freq.HighPart),
      1000000u,
      0u);
  self->divisor = static_cast<uint64_t>(ticksPerUs);
  return self;
}
