// =============================================================================
// ObjectMotion_SlotEmptyDtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0bd0
// Address:   0x004b0bd0–0x004b0bd1 exclusive (1 B / 0x1)
// Module:    autoassault.exe (image base 0x400000)
// System:    client object motion / reaction slot freelist
// Dual:      W30-R 2026-07-29 — accept
// Exactness: Behavior-preserving (single-byte ret).
// Bit-for-bit / runtime / differential: OPEN
// =============================================================================
//
// PURPOSE:
//   Empty thiscall dtor stub invoked by ObjectMotion_SlotReleaseToFreelist
//   before freelist-push of optional child@+0x8 and the slot node itself.
//
// ABI:
//   Call sites use thiscall (ECX = slot or child). Body is bare `ret` —
//   ignores ECX and does no stack cleanup.
//
// CALLER (sole):
//   ObjectMotion_SlotReleaseToFreelist_Inferred (FUN_005be2b0)
//     @ 0x005be2bf (child) and @ 0x005be2da (node)
//
// NOTES:
//   - Do NOT invent resource teardown, free, or notify at this address.
//   - Distinct from mass-shared EmptyRet @ 0x0056f570.
// =============================================================================

// thiscall shape at call sites; body ignores this
extern "C" void ObjectMotion_SlotEmptyDtor_Inferred(void /*this*/)
{
  return;
}
