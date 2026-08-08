// =============================================================================
// VOGPhysics_QueryObject_BaseCtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb210
// Address:   0x005eb210  (autoassault.exe, image base 0x400000)
// Range:     0x005eb210–0x005eb2ac inclusive (157 B / 0x9D); pad CC after
// System:    interaction-activation (CVOGPhysicsUtils area-query base object)
// Generated: 2026-08-05 R11-008 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Base thiscall constructor for the 0xC0-byte physics **query object** core
//   shared by derived 0xD0 collect ctors (sphere + sibling).
//   1) Sub-init via FUN_00581190(self, params[1], 2)
//   2) Empty two internal buffer triads (+0x3C, +0x48) with cap 0x80000000
//   3) Install base vtbl PTR_FUN_009dcde0; self-ptr @ +0x2C
//   4) Init float block @ +0x60 (zeros + DAT_009dcddc ~1e30 at +0x6C/+0x7C)
//   5) Store params[0] @ +0x28; ptr to float block @ +0x14
//   6) Virtual call on object* at +0xC → store @ +0x54
//   7) Copy 0x40 bytes from params+0x20 into this+0x80 via FUN_005eb040
//
// ABI (sealed)
//   thiscall: ECX = self (query object*), stack = params*, RET 4
//   EAX = self on return
//
// CALL SITES
//   FUN_005ebec0 (VOGPhysics_SphereQueryCollect_Ctor_Inferred) @ 0x005ebec8
//   FUN_005eb790 (sibling collect ctor, vtbl 009dce20)       @ 0x005eb798
//
// DISTINCT FROM
//   FUN_005ebec0 / FUN_005eb790 — derived collect ctors (add +0xC0 triad)
//   FUN_006c7fa0                 — sphere-shape setup
//   FUN_00581220                 — AABB-path query ctor (0x90)
//   FUN_004ea350                 — GetObjectsInArea parent loop
//
// PEERS (not dualled here)
//   FUN_00581190  base sub-object init
//   FUN_005eb040  16-dword block copy
//   FUN_005ebf00  sphere-collect dtor
// =============================================================================

#include <cstdint>

// Image VA anchors (not dualled in R11-008)
extern void __thiscall FUN_00581190(uint32_t *self /* ECX */,
                                    uint32_t obj_from_params1,
                                    uint32_t mode /* = 2 */);
extern void __thiscall FUN_005eb040(uint32_t *dest /* ECX */,
                                    const uint32_t *src /* stack */);
extern uint32_t PTR_FUN_009dcde0;   // base vtbl @ 0x009dcde0
extern float DAT_009dcddc;          // ~1e30 @ 0x009dcddc (0x7149F2CA)

// Ghidra-faithful thiscall body (ECX = self).
uint32_t * __thiscall VOGPhysics_QueryObject_BaseCtor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t *params /* stack */)
{
  uint32_t uVar1;
  float *float_block;

  // Assembly: PUSH 2; PUSH params[1]; MOV ESI,ECX; CALL FUN_00581190
  FUN_00581190(self, params[1], 2);

  // Buffer triad A @ +0x3C
  self[0x0F] = 0;
  self[0x10] = 0;
  self[0x11] = 0x80000000u;

  // Buffer triad B @ +0x48
  self[0x12] = 0;
  self[0x13] = 0;
  self[0x14] = 0x80000000u;

  self[0x0B] = (uint32_t)(uintptr_t)self;           // +0x2C
  *self = (uint32_t)(uintptr_t)&PTR_FUN_009dcde0;   // base vtbl

  // Float block @ +0x60: eight floats, then W-slots <- DAT_009dcddc
  float_block = reinterpret_cast<float *>(self + 0x18);
  float_block[0] = 0.0f;
  float_block[1] = 0.0f;
  float_block[2] = 0.0f;
  float_block[3] = 0.0f;
  float_block[4] = 0.0f;
  float_block[5] = 0.0f;
  float_block[6] = 0.0f;
  float_block[7] = 0.0f;
  float_block[3] = DAT_009dcddc;   // +0x6C
  float_block[7] = DAT_009dcddc;   // +0x7C

  self[0x0A] = params[0];                              // +0x28
  self[0x05] = (uint32_t)(uintptr_t)(self + 0x18);     // +0x14 -> +0x60

  // Virtual: (*(*self[3])).vtbl[+0x14]()  where self[3] is object* @ +0xC
  {
    uint32_t *obj = reinterpret_cast<uint32_t *>(self[3]);
    uint32_t *vtbl = reinterpret_cast<uint32_t *>(obj[0]);
    using vfn_t = uint32_t(__thiscall *)(uint32_t *);
    uVar1 = reinterpret_cast<vfn_t>(vtbl[5])(obj);     // slot +0x14 / index 5
  }
  self[0x15] = uVar1;                                  // +0x54

  // Copy 16 dwords from params+0x20 into self+0x80
  FUN_005eb040(self + 0x20, params + 8);

  return self;
}
