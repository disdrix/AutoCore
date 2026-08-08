// =============================================================================
// VOGPhysics_SphereQueryCollect_Dtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005ebf00
// Address:   0x005ebf00  (autoassault.exe, image base 0x400000)
// Range:     0x005ebf00–0x005ebf67 inclusive (104 B / 0x68); pad CC after
// System:    interaction-activation (CVOGPhysicsUtils sphere-query collect)
// Generated: 2026-08-05 R12-038 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Complete-object destructor for the 0xD0-byte physics **sphere query collect**
//   object (pair of VOGPhysics_SphereQueryCollect_Ctor_Inferred / 0x005ebec0):
//   1) Reinstall derived vtbl PTR_FUN_009dce90
//   2) Reverse-walk collect buffer at +0xC0 (stride 8); vcall release +0x14 on each obj*
//   3) Zero count at +0xC4
//   4) If capacity at +0xC8 >= 0, free buffer via allocator tag 0x12
//   5) Tail-jump base dtor FUN_006343d0 (destroys 0xC0 query core)
//
// ABI (sealed)
//   thiscall: ECX = self (query collect object*)
//   no stack args; ends in JMP FUN_006343d0 (not RET)
//
// CALL SITES
//   FUN_005ebf70 (scalar-deleting dtor) @ 0x005ebf73
//   (vtbl 009dce90 slot0 = 005ebf70, which wraps this complete dtor)
//
// DISTINCT FROM
//   FUN_005ebf70  — scalar-deleting dtor (flags&1 → free 0xD0 / tag 0x2C)
//   FUN_006343d0  — base query-object dtor (0xC0 core only)
//   FUN_005ebec0  — matching derived ctor
//   FUN_005eb210  — base ctor
//
// PEERS (not dualled here)
//   FUN_005ebf70  scalar-deleting dtor
//   FUN_006343d0  base dtor
//   FUN_005eb790  sibling collect ctor (vtbl 009dce20)
// =============================================================================

#include <cstdint>

// Image VA anchors (not dualled in R12-038)
extern uint32_t PTR_FUN_009dce90;           // derived vtbl @ 0x009dce90
extern void **DAT_00b05060;                 // allocator singleton @ 0x00b05060
extern void __thiscall FUN_006343d0(uint32_t *self /* ECX */);

// Ghidra-faithful thiscall body (ECX = self). Ends via tail JMP in retail.
void __thiscall VOGPhysics_SphereQueryCollect_Dtor_Inferred(
    uint32_t *self /* ECX */)
{
  int i = (int)self[0x31];  // +0xC4 count

  // Assembly: MOV dword ptr [EDI], 0x9dce90
  *self = (uint32_t)(uintptr_t)&PTR_FUN_009dce90;

  // Reverse element release: stride 8; first dword is object*
  for (i = i - 1; i >= 0; --i) {
    uint32_t *entry_obj =
        *reinterpret_cast<uint32_t **>(self[0x30] + static_cast<uint32_t>(i) * 8);
    auto **vtbl = reinterpret_cast<void **>(*entry_obj);
    auto release = reinterpret_cast<void (__thiscall *)(uint32_t *)>(vtbl[0x14 / 4]);
    release(entry_obj);
  }
  self[0x31] = 0;

  // Free backing store unless empty-capacity sentinel (0x80000000 → signed < 0)
  if (static_cast<int>(self[0x32]) >= 0) {
    uint32_t cap = self[0x32] & 0x7fffffffu;
    uint32_t size_bytes = cap * 8u;
    auto **alloc_vtbl = reinterpret_cast<void **>(*DAT_00b05060);
    auto free_fn = reinterpret_cast<void (__stdcall *)(void *, uint32_t, uint32_t)>(
        alloc_vtbl[0x14 / 4]);
    free_fn(reinterpret_cast<void *>(self[0x30]), size_bytes, 0x12u);
  }

  // Assembly: MOV ECX,EDI; POP EDI; POP ESI; JMP FUN_006343d0
  FUN_006343d0(self);
}
