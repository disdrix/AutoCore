// =============================================================================
// FUN_005cc7c0 / EntityHost_ApplyNestedLocalPosition_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc7c0
// Address:   0x005cc7c0  (autoassault.exe, image base 0x400000)
// Body:      0x005cc7c0 – 0x005cc7e7 (40 bytes, ret 8)
// System:    input-drive-control / object pose (host → nested object)
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W23-J dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A_aa_005cc7c0_*.md + B_aa_005cc7c0_*.md (accept-with-gaps)
// =============================================================================

// PURPOSE:
//   Virtual host method: apply a local float4 position to the nested object at
//   host+0x64 after a physics/body prep call, and set nested+0x304 dirty byte.
//
// ABI (sealed from read_memory):
//   __thiscall  ECX = host
//   stack arg1  = float* vec4 (passed to FUN_004c3a40)
//   stack arg2  = present (ret 8) but unread in this override
//
// Callees:
//   FUN_0053d970(object, 0)  — thiscall on nested; stack formal 0; callee ret 4
//   FUN_004c3a40(object, vec) — CVOGObject_SetLocalPosition4_Gated_Inferred
//
// Dispatch: DATA vtable slots 0x009da9d0, 0x009daf58, 0x009db0d8, 0x009db138, 0x009db198
// No UNCONDITIONAL_CALL xrefs recovered.

/*
 * Behavioral notes (2026-07-29 W23-J dual):
 * - Nested object pointer always reloaded from host+0x64 (three times in body).
 * - Dirty store is BYTE 1 at object+0x304 (same offset DCT sets post-set-pos).
 * - Decompiler hazard: single formal + free-call typing; bytes seal ret 8 + thiscall ECX.
 * - Runtime / differential: OPEN.
 */

void __thiscall FUN_005cc7c0(int param_1, float *param_2 /* , unread stack arg cleaned by ret 8 */)
{
  /* ECX host in param_1 after thiscall rewrite; nested at +0x64 */
  FUN_0053d970(0); /* thiscall ECX=*(param_1+0x64), stack arg 0 — decomp free-call form */
  *(unsigned char *)(*(int *)(param_1 + 0x64) + 0x304) = 1;
  FUN_004c3a40(param_2); /* thiscall ECX=*(param_1+0x64) */
  return;
}
