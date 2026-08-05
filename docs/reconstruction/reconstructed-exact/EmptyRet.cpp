// =============================================================================
// EmptyRet  (FUN_0056f570)
// -----------------------------------------------------------------------------
// Stable ID: aa_0056f570
// Address:   0x0056f570  (autoassault.exe, image base 0x400000)
// System:    shared / multi-domain nop leaf
// Generated: 2026-07-29 W17-P dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Shared empty leaf — single-byte RET. Used as default empty vtbl methods,
// MSVC EH Unwind / vector dtor for trivial types, and stripped debug-print sinks.
// Body has zero side effects. Do not invent domain logic.
//
// ABI: bare ret (c3). Callers may pass stack args (cdecl) or this in ECX; body ignores all.
// Body range: 0x0056f570 only; 0x0056f571+ is int3 pad.
//
// RELATED (context, not this unit):
//   - CVOGHBBase vtbl slot 7 default → this; player targeting derived overrides (0x0051b850)
//   - Distinct empty ret VehicleEntity_DrivePathNoOp @ 0x004f3700 (different VA)
//

void EmptyRet(void)
{
  return;
}

// Ghidra alias
void FUN_0056f570(void)
{
  return;
}
