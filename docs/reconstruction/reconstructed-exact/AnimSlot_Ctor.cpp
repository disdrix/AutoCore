// =============================================================================
// AnimSlot_Ctor
// -----------------------------------------------------------------------------
// Purpose:  Default-initialize a 0x78-byte client animation slot object.
//           Leaf field writer used after operator_new(0x78) on load/replace paths.
//
// Address:  0x0074ed90  (autoassault.exe, image base 0x400000)
// Body:     0x0074ed90–0x0074ee31 (162 bytes; exclusive end 0x0074ee32)
// Stable:   aa_0074ed90
// System:   client visual / animation slot
// Ghidra:   FUN_0074ed90
//
// ABI:      ECX=slot*; no stack args; MSVC SEH frame; bare RET
// Global:   g_flOne @ 0x00a0f2a0 = 1.0f → stored at +0x3c (rate)
//
// Defaults of note:
//   +0x3c = 1.0f (rate); +0x4c = 1 (wrap mode for AnimSlot_SetTime);
//   +0x50/+0x60/+0x68 = 0xFFFFFFFF; +0x54 = 1
// Unwritten: +0x00, +0x14, +0x24 (do not invent zeros)
//
// Callers (sample): Object_LoadOrReplaceAnimSlot, CVOGGraphicsBase_LoadNextChildAsset
//   type 0x41, FUN_00504d40, others (12 xrefs / 10 callers)
// Siblings: AnimSlot_SetTime @ 0x0074e910; dtor/teardown FUN_0074ecf0 family
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W24-R seal).
// =============================================================================

#include <cstdint>

// float g_flOne; // 1.0f at 0x00a0f2a0
extern "C" float g_flOne;

// Offset-accurate writer (avoid C++ packing surprises for unwritten holes).
void __fastcall AnimSlot_Ctor(void *slot /* ECX */)
{
  auto *b = reinterpret_cast<std::uint8_t *>(slot);
  auto store_u32 = [&](std::uint32_t off, std::uint32_t v) {
    *reinterpret_cast<std::uint32_t *>(b + off) = v;
  };
  auto store_f32 = [&](std::uint32_t off, float v) {
    *reinterpret_cast<float *>(b + off) = v;
  };
  auto store_u8 = [&](std::uint32_t off, std::uint8_t v) {
    b[off] = v;
  };

  store_u32(0x04, 0);
  store_u32(0x08, 0);
  store_u32(0x0c, 0);
  store_f32(0x10, 0.0f);
  // +0x14 unwritten
  store_u32(0x18, 0);
  store_u32(0x1c, 0);
  store_u32(0x20, 0);
  // +0x24 unwritten
  store_u32(0x28, 0);
  store_u32(0x2c, 0);
  store_u32(0x30, 0);
  store_u8(0x55, 0);
  store_u8(0x56, 0);
  store_f32(0x34, 0.0f);
  store_f32(0x38, 0.0f);
  store_f32(0x3c, g_flOne); // rate = 1.0f
  store_f32(0x40, 0.0f);
  store_f32(0x44, 0.0f);
  store_f32(0x48, 0.0f);
  store_u8(0x4c, 1); // mode wrap
  store_u32(0x50, 0xFFFFFFFFu);
  store_u8(0x54, 1);
  store_u32(0x58, 0);
  store_u32(0x5c, 0);
  store_u32(0x60, 0xFFFFFFFFu);
  store_f32(0x64, 0.0f);
  store_u32(0x68, 0xFFFFFFFFu);
  store_f32(0x6c, 0.0f);
  store_u32(0x70, 0);
  store_u32(0x74, 0);
  // does not write +0x00 / +0x14 / +0x24
}
