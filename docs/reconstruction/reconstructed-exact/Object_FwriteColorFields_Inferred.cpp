// =============================================================================
// Object_FwriteColorFields_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Virtual FILE-stream serialize extension: base object dump, then
//           raw dword at +0x170 and two packed float4 colors at +0x174 / +0x184.
//
// Address:  0x005e1fc0  (autoassault.exe, image base 0x400000)
// Body:     0x005e1fc0–0x005e203c (124 B / 0x7C)
// Stable:   aa_005e1fc0
// System:   object stream serialize (color extension)
//
// ABI:      __thiscall
//           ECX = Object* self
//           stack: FILE* stream
//           ret 4 (C2 04 00); void
//
// Callees:  thunk_FUN_005a61d0 (base serialize), fwrite, FUN_00973820 ×2
//           (Color_PackFloat4_Scale255_Inferred — ECX dest, stack float* src)
//
// Twin:     FUN_005e2040 deserialize (not OWN this wave)
//
// Exactness: CF from live decompile + read_memory; decompiler FILE* locals
//            rejected — pack destinations are u8×4.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W29-J seal).
// =============================================================================

#include <stdint.h>
#include <stdio.h>

struct Object_ColorSerializeView {
  // ... base fields used by thunk_FUN_005a61d0 ...
  uint8_t  pad_to_170[0x170];
  uint32_t field_170;
  float    colorA_174[4];
  float    colorB_184[4];
};

// Base writer (thunk → FUN_005a61d0); not dualed here.
extern void thunk_FUN_005a61d0(Object_ColorSerializeView *self /*ecx*/, FILE *stream);

// W28-E: ECX dest, stack float* src, ret 4.
extern void FUN_00973820(uint8_t *dest /*ecx*/, const float *src);

void Object_FwriteColorFields_Inferred(Object_ColorSerializeView *self /*ecx*/,
                                       FILE *stream)
{
  uint8_t packedA[4];
  uint8_t packedB[4];

  thunk_FUN_005a61d0(self, stream);

  fwrite(&self->field_170, 4, 1, stream);

  // Image: lea ecx, [self+0x174]; push; lea ecx, local; call FUN_00973820
  FUN_00973820(packedA, self->colorA_174);
  FUN_00973820(packedB, self->colorB_184);

  fwrite(packedA, 4, 1, stream);
  fwrite(packedB, 4, 1, stream);
}
