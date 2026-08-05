// =============================================================================
// Class_009c7a1c_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00496f70
// Address:   0x00496f70-0x004970a8 exclusive (312 B / 0x138)
// System:    class complete-object constructor (vtbl PTR_FUN_009c7a1c)
// Generated: 2026-07-29 W29-G dual seal
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// MSVC complete-object constructor for class family PTR_FUN_009c7a1c.
// Installs own vtbl, seeds capacity pair 0x40/0x40, allocates StdList sentinel
// head via FUN_00457c60 into this+0x10 (list object at +0x0C), zeros six buffer
// triples + cookie-vector ptr, sets flags/floats, copies one byte from parent
// context+0x7d. Returns this.
//
// Allocator size (sole factory caller FUN_004cda90): operator_new(0xC8).
// Complete dtor twin: Class_009c7a1c_CompleteDtor @ 0x004970b0 (W28-M).
// Scalar deleting wrapper (vtbl[0]): FUN_004975e0 @ 0x004975e0.

#include <cstdint>

extern "C" void *PTR_FUN_009c7a1c;
extern "C" void *__cdecl FUN_00457c60(void);
extern "C" float DAT_00aaa8a8; // 300.0f
extern "C" float DAT_00aaa6fc; // 25.0f

static void zero_u32(uint8_t *base, unsigned off)
{
  *reinterpret_cast<uint32_t *>(base + off) = 0;
}

static void zero_triple(uint8_t *base, unsigned begin_off)
{
  zero_u32(base, begin_off);
  zero_u32(base, begin_off + 4);
  zero_u32(base, begin_off + 8);
}

// __thiscall; ECX=this; stack: context*; returns this; image ret 4
void *__thiscall Class_009c7a1c_Ctor(void *self, void *ctx)
{
  auto *base = reinterpret_cast<uint8_t *>(self);

  *reinterpret_cast<void **>(base + 0) = &PTR_FUN_009c7a1c;
  *reinterpret_cast<uint32_t *>(base + 0x04) = 0x40;
  *reinterpret_cast<uint32_t *>(base + 0x08) = 0x40;

  void *head = FUN_00457c60();
  *reinterpret_cast<void **>(base + 0x10) = head;
  *reinterpret_cast<uint32_t *>(base + 0x14) = 0;

  zero_triple(base, 0x1C);
  zero_u32(base, 0x28);
  zero_triple(base, 0x30);
  zero_triple(base, 0x40);

  base[0x4D] = 0;
  base[0x4C] = 1;
  base[0x4E] = 1;
  base[0x4F] = 1;
  base[0x50] = 1;

  *reinterpret_cast<float *>(base + 0x54) = DAT_00aaa8a8;
  *reinterpret_cast<float *>(base + 0x58) = DAT_00aaa6fc;

  base[0x51] = *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(ctx) + 0x7D);
  base[0x52] = 0;
  base[0x53] = 1;
  *reinterpret_cast<uint32_t *>(base + 0x5C) = 3;

  for (unsigned off = 0x60; off <= 0x70; off += 4) zero_u32(base, off);
  for (unsigned off = 0x74; off <= 0x84; off += 4)
    *reinterpret_cast<float *>(base + off) = 0.0f;
  for (unsigned off = 0x88; off <= 0x94; off += 4) zero_u32(base, off);

  zero_triple(base, 0x9C);
  zero_triple(base, 0xAC);
  zero_triple(base, 0xBC);

  return self;
}

