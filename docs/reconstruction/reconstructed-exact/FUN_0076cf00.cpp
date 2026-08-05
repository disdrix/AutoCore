// =============================================================================
// FUN_0076cf00 / Profiler_ScopeEnter
// -----------------------------------------------------------------------------
// Stable ID: aa_0076cf00
// Address:   0x0076cf00  (autoassault.exe, image base 0x400000)
// Body:      0x0076cf00 – 0x0076cf05
// System:    client instrumentation / profiler
// Generated: 2026-07-29 W18-G dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Body bytes: 8B 41 04 C2 04 00
//   mov eax, [ecx+4]
//   ret 4
//
// Callers: ECX = *DAT_00d1f040; push zone name string; call.
// Name is unused (stripped enter body). Leave sibling FUN_0076cef0 is bare ret.
// =============================================================================

#include <stdint.h>

// Ghidra surface (incomplete ABI — omits stack name / ret 4):
uint32_t __fastcall FUN_0076cf00(int param_1)
{
  return *(uint32_t *)(param_1 + 4);
}
