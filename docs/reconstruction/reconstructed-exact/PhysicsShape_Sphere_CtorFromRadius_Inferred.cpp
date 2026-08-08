// =============================================================================
// PhysicsShape_Sphere_CtorFromRadius_Inferred  (FUN_006c7fa0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006c7fa0
// Address:   0x006c7fa0–0x006c7fbc (29 B / 0x1D); pad CC @ 0x006c7fbd
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation / physics sphere shape setup
// Generated: 2026-08-05 MEGA-071 dual seal
// Tools:     decompile_function + analyze_function_complete + disassemble_function
//            + read_memory + callers/xrefs + get_assembly_context
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Leaf thiscall constructor for a 0x10-byte sphere shape object.
// Installs vtbl PTR_FUN_00a0d610, sets refcount@+0x06=1, clears +0x08, stores
// radius float @+0x0c from the sole stack argument, RET 4.
//
// Used by CVOGPhysicsUtils::GetObjectsInArea mode==2 (sphere broadphase path)
// and 16 other physics/query callers. Allocator pattern at call sites:
//   (*heap+0x10)(0x10, 0x22); word[this+4]=0x10; thiscall(this, radius).
//
// Sphere role sealed by sibling vtbl methods (not dualled here):
//   FUN_006c7f20 AABB expand by radius@+0xc
//   FUN_006c7c30 support / max projection + radius
//   FUN_006c7fc0 ray-sphere intersection (radius^2 @ +0xc)
//
// Prior scaffold Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0 RETIRED —
// VOG_DEBUG_STOP is the AABB-fail sibling of GetObjectsInArea, not this callee.
// Product demangle open → _Inferred.

#include <cstdint>

struct PhysicsShape_Sphere_Inferred {
  void **vtbl;            // +0x00  → PTR_FUN_00a0d610
  std::uint16_t size_tag; // +0x04  set by parent to 0x10 (not written here)
  std::uint16_t refcount; // +0x06  = 1
  std::uint32_t field_08; // +0x08  = 0
  float radius;           // +0x0c  stack arg
}; // sizeof == 0x10

// External vtbl symbol (Ghidra PTR_FUN_00a0d610 @ 0x00a0d610)
extern "C" void *PTR_FUN_00a0d610[];

// __thiscall: ECX = this; stack float radius; RET 4; EAX = this
extern "C" PhysicsShape_Sphere_Inferred *__thiscall
PhysicsShape_Sphere_CtorFromRadius_Inferred(PhysicsShape_Sphere_Inferred *self,
                                            float radius)
{
  // Assembly:
  //   MOV EAX, ECX
  //   MOV ECX, [ESP+4]          ; radius
  //   MOV word ptr [EAX+6], 1
  //   MOV dword ptr [EAX+8], 0
  //   MOV [EAX+0xc], ECX
  //   MOV dword ptr [EAX], 0x00a0d610
  //   RET 4
  self->refcount = 1;
  self->field_08 = 0;
  self->radius = radius;
  self->vtbl = PTR_FUN_00a0d610;
  return self;
}
