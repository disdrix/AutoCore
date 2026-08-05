// =============================================================================
// EntityHost_ApplyNestedLocalPosition_Inferred  (alias of FUN_005cc7c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc7c0
// Address:   0x005cc7c0  (autoassault.exe, image base 0x400000)
// Body:      0x005cc7c0 – 0x005cc7e7 (40 bytes, ret 8)
// System:    input-drive-control / object pose
// Dual:      W23-J 2026-07-29 — accept-with-gaps
// Exactness: Role-named twin of FUN_005cc7c0.cpp (behavior-preserving).
// =============================================================================

// ROLE (INFERRED):
//   Host virtual: prep nested object at +0x64, mark nested+0x304=1, apply gated
//   local position float4 via CVOGObject_SetLocalPosition4_Gated_Inferred.
//
// Name confidence: Probable (role-sealed from callees + dirty offset; no product string).

void __thiscall EntityHost_ApplyNestedLocalPosition_Inferred(
    void *host,
    float *localPos4,
    void * /*arg2_unread*/)
{
  void *object = *(void **)((char *)host + 0x64);

  /* FUN_0053d970 — phys/body prep; this unit always pushes stack formal 0 */
  FUN_0053d970(object, 0);

  *(unsigned char *)((char *)object + 0x304) = 1;

  /* FUN_004c3a40 — NaN xyz trap + component gate 0xC7 + store +0x240..+0x24c */
  FUN_004c3a40(object, localPos4);
}
