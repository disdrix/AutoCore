// =============================================================================
// EmptyDtorStub  (FUN_0074b580)
// -----------------------------------------------------------------------------
// Stable ID: aa_0074b580
// Address:   0x0074b580  (autoassault.exe, image base 0x400000)
// System:    shared empty leaf / EH unwind + trivial member dtor
// Generated: 2026-07-29 W31-B dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Shared empty leaf — single-byte RET. Used as:
//   - Empty member dtor stubs (e.g. ListTrackedObj_CompleteDtor ×3 offsets)
//   - MSVC EH Unwind / trivial vector dtor targets
//   - Other owner teardown call sites
// Body has zero side effects. Do not invent domain logic.
//
// ABI: bare ret (c3). Callers may pass this in ECX or stack args; body ignores all.
// Body range: 0x0074b580 only; 0x0074b581+ is int3 pad.
//
// RELATED (context, not this unit):
//   - Distinct mass EmptyRet @ 0x0056f570
//   - Distinct ObjectMotion_SlotEmptyDtor_Inferred @ 0x004b0bd0
//   - Distinct CVOGHBBase_EmptyVFunc @ 0x005081f0
//   - Reject scaffold Named_CalleeOf_Mission_Uses_CVOGReaction_FailMissionNotify_0074b580
//

void EmptyDtorStub(void)
{
  return;
}

// Ghidra alias
void FUN_0074b580(void)
{
  return;
}
