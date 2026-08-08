// =============================================================================
// VOGPhysics_QueryObject_Dtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00507350
// Address:   0x00507350  (autoassault.exe, image base 0x400000)
// Range:     0x00507350–0x005073bd inclusive (110 B / 0x6E); pad CC after
// System:    interaction-activation (query-object base body dtor)
// Generated: 2026-08-05 R13-028 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Body destructor for the physics query-object / shared base header that
//   SubInit (`0x00581190`) constructs under provisional vtbl `009cd99c`:
//   1) install provisional vtbl `PTR_FUN_009cd99c`
//   2) release linked_obj* @ +0x0C (refcount @ linked+6; zero → vtbl[0](1))
//   3) if capacity @ +0x38 signed ≥ 0: pool-free buffer @ +0x30,
//      size (cap & 0x7FFFFFFF)*8, tag 0x12 via (*DAT_00b05060)[+0x14]
//   4) install mid vtbl `009d81e8`; if flag word @ +4 high bit set:
//      clear to low 15 bits + FUN_005ffdb0(this, 0)
//   5) install base vtbl `009cc290`
//
// ABI (sealed)
//   thiscall: ECX = self
//   stack:    none
//   RET 0     (C3)
//
// CALL SITES
//   FUN_005073f0 @ 0x005073f3  scalar deleting wrapper
//   FUN_005074d0 @ 0x005075b7  derived dtor chain
//   FUN_006343d0 @ 0x0063443e  derived dtor chain
//
// DISTINCT FROM
//   FUN_005073f0 — scalar deleting dtor (calls this, then optional free self)
//   FUN_00581190 — SubInit ctor peer (same provisional vtbl)
//   FUN_005eb210 — full query base ctor (overwrites vtbl 009dcde0)
//   FUN_00581220 — TtPhantom AABB ctor (different vtbl/size)
//   FUN_005074d0 / FUN_006343d0 — derived dtors that chain here
//
// PEERS (not dualled here)
//   FUN_00581190  SubInit (R12-027 dualed parent)
//   FUN_005073f0  scalar deleting wrapper
//   FUN_005f5760  same-vtbl peer ctor
//   FUN_005ffdb0  flag/weak clear helper
// =============================================================================

#include <cstdint>

// Image VA anchors (not dualled in R13-028)
extern uint32_t PTR_FUN_009cd99c;   // provisional vtbl @ 0x009cd99c
extern uint32_t PTR_FUN_009d81e8;   // mid base vtbl @ 0x009d81e8
extern uint32_t PTR_LAB_009cc290;   // final base vtbl @ 0x009cc290
extern uint32_t *DAT_00b05060;      // global pool / allocator object

// FUN_005ffdb0 — thiscall flag helper (param_2==0 clears weak bit path)
void __thiscall FUN_005ffdb0(uint32_t *self, int set_bit);

// Ghidra-faithful thiscall body (ECX = self).
void __thiscall VOGPhysics_QueryObject_Dtor_Inferred(uint32_t *self /* ECX */)
{
  // Assembly: PUSH ESI; MOV ESI,ECX
  uint32_t *linked = reinterpret_cast<uint32_t *>(
      static_cast<uintptr_t>(self[3]));              // +0x0C

  *self = reinterpret_cast<uint32_t>(
      reinterpret_cast<uintptr_t>(&PTR_FUN_009cd99c));

  if (linked != nullptr) {
    // ADD word [linked+6], -1; if zero → CALL [*(linked)](1)
    int16_t *rc = reinterpret_cast<int16_t *>(
        reinterpret_cast<uint8_t *>(linked) + 6);
    *rc = static_cast<int16_t>(*rc - 1);
    if (*rc == 0) {
      auto **vtbl = reinterpret_cast<void ***>(linked);
      auto fn = reinterpret_cast<void(__stdcall *)(int)>(**vtbl);
      fn(1);
    }
  }

  int32_t cap = static_cast<int32_t>(self[0xe]);     // +0x38
  if (cap >= 0) {
    // AND 0x7FFFFFFF; *8; push tag 0x12, size, ptr@+0x30
    uint32_t nbytes =
        (static_cast<uint32_t>(cap) & 0x7FFFFFFFu) * 8u;
    auto **alloc_vtbl = reinterpret_cast<void ***>(*DAT_00b05060);
    auto free_fn = reinterpret_cast<void(__stdcall *)(uint32_t, uint32_t, int)>(
        alloc_vtbl[0x14 / 4]);
    free_fn(self[0xc], nbytes, 0x12);
  }

  *self = reinterpret_cast<uint32_t>(
      reinterpret_cast<uintptr_t>(&PTR_FUN_009d81e8));

  uint16_t flags = *reinterpret_cast<uint16_t *>(self + 1); // +0x04
  if (static_cast<int16_t>(flags) < 0) {
    flags = static_cast<uint16_t>(flags & 0x7FFFu);
    *reinterpret_cast<uint16_t *>(self + 1) = flags;
    // MOV ECX,ESI; PUSH 0; CALL FUN_005ffdb0
    FUN_005ffdb0(self, 0);
  }

  *self = reinterpret_cast<uint32_t>(
      reinterpret_cast<uintptr_t>(&PTR_LAB_009cc290));
  // POP ESI; RET
}
