// =============================================================================
// GlyphCache_PlacementCtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00754ee0
// Address:   0x00754ee0  (autoassault.exe, image base 0x400000)
// System:    GlyphCache / font glyph texture host
// Wave:      W35-H dual seal 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Placement constructor for GlyphCache (alloc size 0xB8).
// Product: vtbl-adjacent "Failed to create texture for glyph cache".
// ABI: stack(this*); RET 4; returns this. Not ECX-thiscall.
// Nested: NestedHashBag_Ctor_Sentinel0x30_Inferred at +0x44 (W34-G).
//

#include <cstdint>

struct NestedHashBag_Sentinel0x30; // W34-G
struct GlyphCache;

// External / residual symbols (image)
extern "C" void* ExceptionList;
extern uint32_t DAT_00d1f01c;
extern uint32_t DAT_00d1f020;
extern void* PTR_FUN_00a9f584[];
// IAT basic_string default ctor at this+0x18
void basic_string_default_ctor(void* self);
// W34-G sealed
NestedHashBag_Sentinel0x30* NestedHashBag_Ctor_Sentinel0x30_Inferred(
    NestedHashBag_Sentinel0x30* self /*stack*/);

struct GlyphCache {
  void** vtbl;                 // +0x00 → PTR_FUN_00a9f584
  uint32_t refcount;           // +0x04
  uint32_t unwritten_08;       // +0x08 not written here
  uint32_t z0c, z10, z14;      // +0x0c..+0x14
  uint8_t name_string[0x20];   // +0x18 basic_string storage span to +0x38
  uint32_t def_a;              // +0x38 ← DAT_00d1f01c
  uint32_t def_b;              // +0x3c ← DAT_00d1f020
  uint32_t z40;                // +0x40
  uint8_t hash_bag[0x28];      // +0x44 NestedHashBag bag
  uint32_t z70, z74, z78, z7c, z80; // +0x70..+0x80
  uint8_t gap_84[0x10];        // +0x84..+0x93 unwritten
  uint32_t z94, z98, z9c;      // +0x94..
  uint32_t gdi_a;              // +0xa0 later HFONT-class
  uint32_t gdi_b;              // +0xa4
  uint32_t hdc;                // +0xa8 HDC
  uint32_t zac;                // +0xac
  uint32_t def_a2;             // +0xb0 ← DAT_00d1f01c
  uint32_t def_b2;             // +0xb4 ← DAT_00d1f020
}; // sizeof == 0xB8

// Stack this*; RET 4; returns this in EAX
GlyphCache* GlyphCache_PlacementCtor(GlyphCache* self /*stack*/)
{
  // SEH LAB_009b0971 omitted (MSVC frame)
  self->refcount = 0;
  self->vtbl = PTR_FUN_00a9f584;
  self->z0c = 0;
  self->z10 = 0;
  self->z14 = 0;
  basic_string_default_ctor(self->name_string);
  self->def_a = DAT_00d1f01c;
  self->def_b = DAT_00d1f020;
  self->z40 = 0;
  NestedHashBag_Ctor_Sentinel0x30_Inferred(
      reinterpret_cast<NestedHashBag_Sentinel0x30*>(self->hash_bag));
  self->z70 = self->z74 = self->z78 = self->z7c = self->z80 = 0;
  self->z94 = self->z98 = self->z9c = 0;
  self->gdi_a = self->gdi_b = self->hdc = self->zac = 0;
  self->def_a2 = DAT_00d1f01c;
  self->def_b2 = DAT_00d1f020;
  return self;
}
