// =============================================================================
// FUN_005ffc80  — scaffold twin of EmptyStub_Ret4
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffc80
// Address:   0x005ffc80  (autoassault.exe, image base 0x400000)
// System:    shared / multi-domain nop leaf
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-05 R11-009
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
// Prefer named clean: EmptyStub_Ret4.cpp
// Body: c2 04 00 (ret 4). Decompiler void(void) is ABI-incomplete.

void EmptyStub_Ret4(void * /*ignored_stack_arg*/);

void FUN_005ffc80(void)
{
  // Machine body is ret 4; decompiler elides stack cleanup.
  return;
}
