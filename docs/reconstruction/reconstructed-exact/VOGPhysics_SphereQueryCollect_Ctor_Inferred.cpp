// =============================================================================
// VOGPhysics_SphereQueryCollect_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005ebec0
// Address:   0x005ebec0  (autoassault.exe, image base 0x400000)
// Range:     0x005ebec0–0x005ebef0 inclusive (49 B / 0x31); pad CC after
// System:    interaction-activation (CVOGPhysicsUtils sphere-query collect)
// Generated: 2026-08-05 MEGA-070 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Derived constructor for the 0xD0-byte physics **sphere query collect** object.
//   1) Base-init via FUN_005eb210(params)  [thiscall; ECX remains self]
//   2) Install derived vtbl PTR_FUN_009dce90
//   3) Zero-init result-collect buffer triad at this+0xC0 / +0xC4 / +0xC8
//
// ABI (sealed)
//   thiscall: ECX = self (query object*), stack = params*, RET 4
//   EAX = self on return
//
// CALL SITES
//   FUN_004ea350 (GetObjectsInArea param_5==2 sphere path) @ 0x004ea770
//   FUN_005dd080 (sphere branch) @ 0x005dd368
//   factory near 0x005ebfcf (alloc 0xD0 / tag 0x2C then construct)
//
// DISTINCT FROM
//   FUN_006c7fa0  — sphere-shape setup (mode-2 peer; not this VA)
//   FUN_004ea350  — parent area query / collect loop
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_005ebec0 — retired wrong scaffold
//
// PEERS (not dualled here)
//   FUN_005eb210  base ctor
//   FUN_005ebf00  dtor (releases +0xC0 collect buffer)
//   FUN_005ebf70  scalar-deleting dtor
// =============================================================================

#include <cstdint>

// External symbols (image VA anchors; not dualled in MEGA-070)
// Base ctor is thiscall: ECX=self, stack=params*, returns self.
extern uint32_t * __thiscall FUN_005eb210(uint32_t *self /* ECX */, uint32_t params);
extern uint32_t PTR_FUN_009dce90;  // derived vtbl @ 0x009dce90

// Ghidra-faithful thiscall body (ECX = self).
uint32_t * __thiscall VOGPhysics_SphereQueryCollect_Ctor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t params /* stack */)
{
  // Assembly: PUSH params; MOV ESI,ECX; CALL FUN_005eb210  (ECX still = self)
  FUN_005eb210(self, params);

  *self = (uint32_t)(uintptr_t)&PTR_FUN_009dce90;

  self[0x30] = 0;              // +0xC0 begin
  self[0x31] = 0;              // +0xC4 count
  self[0x32] = 0x80000000u;    // +0xC8 empty capacity sentinel

  return self;
}
