// =============================================================================
// VOGPhysics_QueryObject_SubInit_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00581190
// Address:   0x00581190  (autoassault.exe, image base 0x400000)
// Range:     0x00581190–0x005811e7 inclusive (88 B / 0x58); pad CC after
// System:    interaction-activation (query-object base sub-init)
// Generated: 2026-08-05 R12-027 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Leaf thiscall **sub-init** for the front of the physics query-object /
//   shared base-object header:
//   1) refcount @ +0x06 = 1
//   2) install provisional vtbl PTR_FUN_009cd99c
//   3) store linked host/object* @ +0x0C; optional linked->refcount++
//   4) store mode @ +0x24 (sole caller passes 2)
//   5) clear mid-fields; self-ptr @ +0x2C; empty-vector cap 0x80000000 @ +0x38
//
// ABI (sealed)
//   thiscall: ECX = self
//   stack:    linked_obj*  ([ESP+4] entry), mode ([ESP+8] entry)
//   RET 8
//   EAX = self at RET (preserved via MOV EAX,ECX; sole caller ignores)
//
// CALL SITES
//   FUN_005eb210 (VOGPhysics_QueryObject_BaseCtor_Inferred) @ 0x005eb21e
//     PUSH 2; PUSH params[1]; MOV ESI,ECX; CALL 00581190
//
// DISTINCT FROM
//   FUN_005eb210 — full query base ctor (overwrites vtbl 009dcde0; more fields)
//   FUN_00581220 — TtPhantom AABB ctor (vtbl 009d45b0; object 0x90)
//   FUN_005f5760 — same vtbl peer ctor (mode from desc byte; not this VA)
//   FUN_00507350 — same-vtbl dtor path (refcount release)
//
// PEERS (not dualled here)
//   FUN_005eb210  parent dual (R11-008)
//   FUN_005f5760  near-identical layout + extra follow-on
//   FUN_00507350  dtor using same provisional vtbl
// =============================================================================

#include <cstdint>

// Image VA anchor (not dualled in R12-027)
extern uint32_t PTR_FUN_009cd99c;   // provisional base vtbl @ 0x009cd99c

// Ghidra-faithful thiscall body (ECX = self).
// Decompiler displays void; EAX holds self at RET.
void __thiscall VOGPhysics_QueryObject_SubInit_Inferred(
    uint32_t *self /* ECX */,
    uint32_t *linked_obj /* stack */,
    uint32_t mode /* stack */)
{
  // Assembly: MOV EDX,[ESP+4]; MOV EAX,ECX
  // refcount word @ +0x06
  *reinterpret_cast<uint16_t *>(reinterpret_cast<uint8_t *>(self) + 6) = 1;

  *self = reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_009cd99c));

  self[2] = 0;                                          // +0x08
  self[3] = reinterpret_cast<uint32_t>(
      reinterpret_cast<uintptr_t>(linked_obj));         // +0x0C
  self[5] = 0;                                          // +0x14
  self[6] = 0;                                          // +0x18
  self[4] = 0xFFFFFFFFu;                                // +0x10
  self[9] = mode;                                       // +0x24
  self[7] = 0;                                          // +0x1c
  self[8] = 0;                                          // +0x20
  self[10] = 0;                                         // +0x28
  self[0xb] = 0;                                        // +0x2c temp
  self[0xc] = 0;                                        // +0x30
  self[0xd] = 0;                                        // +0x34
  self[0xe] = 0x80000000u;                              // +0x38 cap sentinel
  self[0xb] = reinterpret_cast<uint32_t>(
      reinterpret_cast<uintptr_t>(self));               // +0x2c = self

  if (linked_obj != nullptr) {
    uint16_t *rc = reinterpret_cast<uint16_t *>(
        reinterpret_cast<uint8_t *>(linked_obj) + 6);
    *rc = static_cast<uint16_t>(*rc + 1);
  }
  // RET 8; EAX still = self
}
