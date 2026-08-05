// =============================================================================
// Profiler_ScopeLeave  (FUN_0076cef0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076cef0
// Address:   0x0076cef0  (autoassault.exe, image base 0x400000)
// Body:      0x0076cef0 only (1 byte c3)
// Twin:      Profiler_ScopeEnter @ 0x0076cf00 (mov eax,[ecx+4]; ret 4)
// System:    client instrumentation / profiler
// Generated: dual A/B seal 2026-07-29 (W19-D)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Compiled-out profiler scope leave. High fan-in CALL sites; body is
// pure RET. Does NOT ret 4 — enter already cleaned the zone name stack arg.
// Ignore for AutoCore sector/physics ports.
//
// ABI: bare ret (c3). Ignores ECX / stack / return register.
//

void Profiler_ScopeLeave(void)
{
  return;
}

// Ghidra alias
void FUN_0076cef0(void)
{
  return;
}
