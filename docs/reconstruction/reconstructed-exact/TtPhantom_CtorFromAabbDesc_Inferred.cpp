// =============================================================================
// TtPhantom_CtorFromAabbDesc_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00581220
// Address:   0x00581220–0x005812c6 inclusive (167 B / 0xA7)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation / physics (TtPhantom)
// Ghidra:    FUN_00581220
// Dual:      MEGA-037 2026-08-05 — accept-with-gaps (A + B)
// Exactness: Behavior-preserving rewrite of decompiler CF + assembly ABI.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: NOT claimed.
// =============================================================================
//
// PURPOSE
//   Leaf constructor for a retail **TtPhantom** object (alloc size 0x90) from an
//   AABB box descriptor. Parents expand center±radius into 8 floats at
//   desc+0x20, allocate 0x90, stamp size tag at this+4, then call this.
//   Initializes empty overlap list at +0x80/+0x84 (capacity sentinel 0x80000000),
//   installs vtbl PTR_FUN_009d45b0, copies AABB + lead field.
//
//   Consumers:
//     - CVOGPhysicsUtils_GetObjectsInArea mode-1 (box/list path)
//     - hkVehicleFramework_preUpdate → vehicle+0x38 → TtPhantom_castRay
//     - FUN_004ca9f0 → creature+0x254 → FindTerrainHeight phantom path
//
// ABI (sealed)
//   __thiscall; ECX=this; stack const AabbDesc*; EAX=this; RET 4
//
// Retired scaffold name:
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_00581220
// =============================================================================

#include <cstdint>

// Opaque retail layout (0x90). Only offsets touched by this ctor are named.
struct TtPhantom {
  void*    vtbl;            // +0x00 → PTR_FUN_009d45b0
  uint16_t size_tag;        // +0x04  (written by allocator callers, not this body)
  uint16_t refcount;        // +0x06  = 1
  uint32_t f08;             // +0x08
  uint32_t f0c;             // +0x0c
  uint32_t f10;             // +0x10 = -1
  uint32_t f14;             // +0x14
  uint32_t f18;             // +0x18
  uint32_t f1c;             // +0x1c
  uint32_t f20;             // +0x20
  uint32_t type_tag;        // +0x24 = 2
  uint32_t lead_from_desc;  // +0x28 = *src
  TtPhantom* self;          // +0x2c = this
  uint32_t f30;             // +0x30
  uint32_t f34;             // +0x34
  uint32_t vec0_cap;        // +0x38 = 0x80000000
  uint32_t f3c;             // +0x3c
  uint32_t f40;             // +0x40
  uint32_t vec1_cap;        // +0x44 = 0x80000000
  uint32_t f48;             // +0x48
  uint32_t f4c;             // +0x4c
  uint32_t vec2_cap;        // +0x50 = 0x80000000
  uint32_t pad54[3];        // +0x54..+0x5c
  uint32_t aabb[8];         // +0x60..+0x7c  from src+0x20
  void*    overlap_begin;   // +0x80
  int32_t  overlap_count;   // +0x84
  uint32_t overlap_cap;     // +0x88 = 0x80000000
  // ... remainder to 0x90
};

// Source descriptor: head dword + AABB floats at +0x20 (8 dwords).
struct TtPhantomAabbDesc {
  uint32_t lead;            // +0x00 → this+0x28
  uint32_t mid[7];          // +0x04..+0x1c (not read by this ctor)
  uint32_t aabb[8];         // +0x20..+0x3c → this+0x60
};

extern "C" void* PTR_FUN_009d45b0;  // retail vtbl

// Retail: FUN_00581220
TtPhantom* __thiscall TtPhantom_CtorFromAabbDesc_Inferred(
    TtPhantom* self,
    const TtPhantomAabbDesc* src)
{
  self->refcount = 1;

  self->f08 = 0;
  self->f0c = 0;
  self->f14 = 0;
  self->f18 = 0;
  self->f10 = 0xffffffffu;
  self->f1c = 0;
  self->f20 = 0;
  self->lead_from_desc = 0;
  self->type_tag = 2;
  self->self = nullptr;
  self->f30 = 0;
  self->f34 = 0;
  self->vec0_cap = 0x80000000u;
  self->f3c = 0;
  self->f40 = 0;
  self->vec1_cap = 0x80000000u;
  self->f48 = 0;
  self->f4c = 0;
  self->vec2_cap = 0x80000000u;

  self->self = self;
  self->vtbl = &PTR_FUN_009d45b0;

  self->overlap_begin = nullptr;
  self->overlap_count = 0;
  self->overlap_cap = 0x80000000u;

  self->aabb[0] = src->aabb[0];
  self->aabb[1] = src->aabb[1];
  self->aabb[2] = src->aabb[2];
  self->aabb[3] = src->aabb[3];
  self->aabb[4] = src->aabb[4];
  self->aabb[5] = src->aabb[5];
  self->aabb[6] = src->aabb[6];
  self->aabb[7] = src->aabb[7];

  self->lead_from_desc = src->lead;
  return self;
}
