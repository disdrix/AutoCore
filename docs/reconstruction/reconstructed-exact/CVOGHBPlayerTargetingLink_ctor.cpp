// =============================================================================
// CVOGHBPlayerTargetingLink_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00512090
// Address:   0x00512090  (autoassault.exe, image base 0x400000)
// System:    object / combat-target / HB
// Generated: 2026-07-29 OWN-ONLY dual A/B (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Self-side targeting heartbeat constructor.
//   1) Run shared base targeting HB ctor FUN_00604d40(attachOwner) on this.
//   2) Overwrite vtbl with 0x009cdfd4 (CVOGHBPlayerTargetingLink family).
//   3) Return this.
//
//   Sole caller: Object_SetSelectedTarget (0x005172d0) after operator_new(0x28),
//   with attachOwner = selector entity (not the new selected target).
//   Target-side HB uses FUN_00604d40 alone (base vtbl 0x009cdfb0).
//
// ABI: __thiscall, ECX=this, stack attachOwner, ret 4, returns this.
// =============================================================================

#include <cstdint>

// External: base targeting HB constructor (also target-side entry).
// Defined at 0x00604d40 — not dualed in this unit.
extern "C" void *__thiscall FUN_00604d40(void *self, void *attachOwner);

// Image vtbl for CVOGHBPlayerTargetingLink (RTTI class name from purge path).
// Slot0=0x0051b870, slot7=0x0051b850; slots 1..6 match base 0x009cdfb0.
static void *const PTR_FUN_009cdfd4 = reinterpret_cast<void *>(0x009cdfd4);

// Retail: FUN_00512090
extern "C" void *__thiscall CVOGHBPlayerTargetingLink_ctor(void *self, void *attachOwner)
{
  FUN_00604d40(self, attachOwner);
  *reinterpret_cast<void **>(self) = PTR_FUN_009cdfd4;
  return self;
}
