// =============================================================================
// VOGPhysics_QueryCollect_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb790
// Address:   0x005eb790  (autoassault.exe, image base 0x400000)
// Range:     0x005eb790–0x005eb7c0 inclusive (49 B / 0x31); pad CC after
// System:    interaction-activation (physics query-collect object)
// Generated: 2026-08-05 R12-037 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Derived constructor for the 0xD0-byte physics **query-collect** object
//   (sibling of dualed VOGPhysics_SphereQueryCollect_Ctor_Inferred @ 0x005ebec0).
//   1) Base-init via FUN_005eb210(params)  [thiscall; ECX remains self]
//   2) Install derived vtbl PTR_FUN_009dce20  (≠ sphere vtbl 009dce90)
//   3) Zero-init result-collect buffer triad at this+0xC0 / +0xC4 / +0xC8
//
// ABI (sealed)
//   thiscall: ECX = self (query object*), stack = params*, RET 4
//   EAX = self on return
//
// CALL SITES
//   FUN_004e9720 @ 0x004e97fb  (sphere-shape peer + 0xD0 alloc)
//   FUN_004e9aa0 @ 0x004e9f93, 0x004ea0f2
//   factory near 0x005eb8bf (alloc 0xD0 / tag 0x2C then construct)
//
// DISTINCT FROM
//   FUN_005ebec0  — sphere query collect ctor (vtbl 009dce90; MEGA-070)
//   FUN_005eb210  — base query-object ctor (0xC0 core; no +0xC0 triad)
//   FUN_006c7fa0  — sphere-shape setup (caller peer; not this VA)
//   Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature_005eb790 — retired wrong scaffold
//
// PEERS (not dualled here)
//   FUN_005eb7d0  dtor (releases +0xC0 collect; free stride ×4)
//   FUN_005eb810  scalar-deleting dtor
// =============================================================================

#include <cstdint>

// External symbols (image VA anchors)
// Base ctor is thiscall: ECX=self, stack=params*, returns self. Dualed R11-008.
extern uint32_t * __thiscall FUN_005eb210(uint32_t *self /* ECX */, uint32_t params);
extern uint32_t PTR_FUN_009dce20;  // derived vtbl @ 0x009dce20

// Ghidra-faithful thiscall body (ECX = self).
uint32_t * __thiscall VOGPhysics_QueryCollect_Ctor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t params /* stack */)
{
  // Assembly: PUSH params; MOV ESI,ECX; CALL FUN_005eb210  (ECX still = self)
  FUN_005eb210(self, params);

  *self = (uint32_t)(uintptr_t)&PTR_FUN_009dce20;

  self[0x30] = 0;              // +0xC0 begin
  self[0x31] = 0;              // +0xC4 count
  self[0x32] = 0x80000000u;    // +0xC8 empty capacity sentinel

  return self;
}
