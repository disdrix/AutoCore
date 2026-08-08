// =============================================================================
// EmptyStub_Ret4  (FUN_005ffc80)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffc80
// Address:   0x005ffc80  (autoassault.exe, image base 0x400000)
// System:    shared / multi-domain nop leaf
// Generated: 2026-08-05 R11-009 dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Shared empty leaf — three-byte RET 0x4. Used as default empty vtbl
// methods across many classes (util Class_00a9bbe8 +8, VehicleAction primary +0x10,
// secondary dual slots, physics component builders, etc.) and as a direct CALL
// nop before field-copy in FUN_0064d9f0. Body has zero side effects.
// Do not invent domain logic, free, notify, or logging.
//
// ABI (machine): RET 0x4 — callee cleans one stack dword. Callers may pass this
// in ECX and/or a stack arg; body ignores all. Decompiler void(void) is incomplete.
// Body range: 0x005ffc80–0x005ffc82 inclusive; 0x005ffc83+ is int3 pad until
// FUN_005ffc90 @ 0x005ffc90.
//
// RELATED (context, not this unit):
//   - EmptyRet @ 0x0056f570 — bare c3 (different VA / different stack cleanup)
//   - CVOGHBBase_EmptyVFunc @ 0x005081f0 — bare c3 HB default
//   - Neighbor FUN_005ffc90 @ 0x005ffc90 — non-empty (do not merge)
//   - Parent residual Class_00a9bbe8_CompleteDtor_Inferred @ 0x00416110 (vtbl host)
//   - Sole code caller FUN_0064d9f0 (copy this+0x30..+0x4c after nop call)
//

// Port signature: one ignored stack arg (stdcall / thiscall-with-stack-arg shape).
// MSVC: void __stdcall EmptyStub_Ret4(void *ignored)  OR
//       void __thiscall EmptyStub_Ret4(void *this, void *ignored)  — both ret 4.
void EmptyStub_Ret4(void * /*ignored_stack_arg*/)
{
  return; // machine: ret 4
}

// Ghidra alias (decompiler arity incomplete)
void FUN_005ffc80(void)
{
  return; // machine still ret 4 when linked against retail body
}
