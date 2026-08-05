// =============================================================================
// CVOGHBBase_EmptyVFunc  (FUN_005081f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005081f0
// Address:   0x005081f0  (autoassault.exe, image base 0x400000)
// System:    heartbeat / shared empty leaf
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W18-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Single-byte RET empty leaf. Base CVOGHBBase vtbl slot +0x14 default;
// also shared nop target for subclass OnEnd tails and other CALL/JMP sites.
// Body has zero side effects. Do not invent cleanup, detach, or logging.
//
// ABI: bare ret (c3). Callers may pass this in ECX or stack args; body ignores all.
// Body range: 0x005081f0 only; 0x005081f1+ is int3 pad.
//
// RELATED (context, not this unit):
//   - Neighbor empty ret @ 0x005081e0 (base vtbl+0x10 default; Stop tail target)
//   - Mass shared EmptyRet @ 0x0056f570 (different VA)
//   - Subclass OnEnd overrides of vtbl+0x14 (e.g. CVOGHBOKToCastAgain_OnEnd @ 0x0051e3b0)
//   - CVOGHBBase_EndOrDestroy @ 0x005083f0 may vcall +0x14 when flag set
//

void CVOGHBBase_EmptyVFunc(void)
{
  return;
}

// Ghidra alias
void FUN_005081f0(void)
{
  return;
}

// Misleading auto parent-seed alias (callee-of scan) — keep as name only
void Named_CalleeOf_CVOGHBOKToCastAgain_OnEnd_005081f0(void)
{
  return;
}
