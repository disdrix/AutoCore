// =============================================================================
// Profiler_ScopeEnter  (probable product role; plate name open)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076cf00
// Address:   0x0076cf00  (autoassault.exe, image base 0x400000)
// Body:      0x0076cf00 – 0x0076cf05
// Twin file: FUN_0076cf00.cpp
// System:    client instrumentation / profiler
// Generated: 2026-07-29 W18-G dual seal
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================
//
// Body: mov eax, [ecx+4] ; ret 4
// Global context: DAT_00d1f040 (current profiler ctx / zone*)
// Zone timer slot: +4 (see Profiler_Zone_Ctor / Profiler_TimerBlock_Ctor)
// Leave: FUN_0076cef0 @ 0x0076cef0 (ret only)
// =============================================================================

#include <stdint.h>

extern "C" void *DAT_00d1f040; // process current profiler context pointer (call sites)

// ECX = profiler context; stack name cleaned by ret 4 but unread.
extern "C" void * __fastcall Profiler_ScopeEnter(void *profilerCtx /* ECX */,
                                                 const char * /*name*/)
{
  return *(void **)((char *)profilerCtx + 4);
}
