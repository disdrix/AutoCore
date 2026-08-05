// =============================================================================
// Xform_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00972cc0
// Address:   0x00972cc0–0x00972d6a  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00972cc0
// System:    gfx-math / shared basis transform (Xform_* family)
// Dual:      W37-D 2026-08-04
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = XformBlock* (0xC0); returns this in EAX; plain RET.
// Leaf ctor/init: two identity mat4 copies, identity quat, zero translation,
// unit scale, version/flag/dirty cleared. Used after _aligned_malloc(0xC0,0x10)
// and as eh_vector_constructor_iterator element ctor.
// =============================================================================

#include <cstdint>
#include <cstring>

// g_flOne @ 0x00a0f2a0 = 1.0f
extern float g_flOne;
// DAT_00afdf70 — row-major 4x4 identity (16 floats)
extern float DAT_00afdf70[16];

struct XformBlock {
  float mat0[16];   // +0x00  identity
  float mat1[16];   // +0x40  identity
  float quat[4];    // +0x80  (0,0,0,1)
  float pos[3];     // +0x90  (0,0,0)
  float scale[3];   // +0x9c  (1,1,1) — scale path at FUN_0044b440
  float extra[3];   // +0xa8  (1,1,1)
  uint32_t version; // +0xb4
  uint8_t  nonuniform; // +0xb8
  uint8_t  _pad_b9[3];
  uint32_t dirty;   // +0xbc
}; // 0xC0

static_assert(sizeof(XformBlock) == 0xC0, "XformBlock size");

// Clean signature: this explicit (retail ECX); returns this.
XformBlock* Xform_Ctor_Inferred(XformBlock* self /*ECX*/)
{
  const float one = g_flOne;

  std::memcpy(self->mat0, DAT_00afdf70, sizeof(self->mat0));
  std::memcpy(self->mat1, DAT_00afdf70, sizeof(self->mat1));

  self->quat[0] = 0.0f;
  self->quat[1] = 0.0f;
  self->quat[2] = 0.0f;
  self->quat[3] = one;

  self->pos[0] = 0.0f;
  self->pos[1] = 0.0f;
  self->pos[2] = 0.0f;

  self->scale[0] = one;
  self->scale[1] = one;
  self->scale[2] = one;

  self->extra[0] = one;
  self->extra[1] = one;
  self->extra[2] = one;

  self->version = 0;
  self->nonuniform = 0;
  self->dirty = 0;

  return self;
}
