// =============================================================================
// CxImage_Create
// -----------------------------------------------------------------------------
// Stable ID: aa_004323e0
// Address:   0x004323e0–0x0043255f  (autoassault.exe, image base 0x400000)
// System:    graphics / CxImage
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W22-Q)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Product evidence: "CxImage::Create : width and height must be greater than zero",
 *   "CxImage::Create can't allocate memory", "CXIMAGE_MAX_MEMORY exceeded".
 * - Retail ABI: EBX=this, EAX=height, stack (width, bpp, type), RET 12.
 * - Clean plate uses explicit args; port must restore register ABI at call sites.
 * - bpp is quantized to effective bit depth 1 / 4 / 8 / 24 before stride math.
 * - Allocates BITMAPINFOHEADER (0x28) + palette (count*4) + image bits; installs
 *   bits pointer at this+0x34 = block + biSize + paletteBytes.
 * - Callees FUN_004321b0 / FUN_00433490 / FUN_004331d0 not owned this unit.
 */

#include <cstdint>
#include <cstdlib>
#include <cstring>

struct CxImage {
  // … vptr / other …
  void*    block;         // +0x04  malloc(header+palette+bits)
  int32_t  biSize;        // +0x08  = 0x28
  int32_t  width;         // +0x0c
  int32_t  height;        // +0x10
  uint16_t planes;        // +0x14  = 1
  uint16_t bitCount;      // +0x16  effective bits
  int32_t  compression;   // +0x18  = 0
  int32_t  imageBytes;    // +0x1c  stride * height
  // +0x20..+0x27
  int32_t  paletteCount;  // +0x28  2 / 0x10 / 0x100 / 0
  int32_t  field_2c;      // +0x2c  = 0
  int32_t  stride;        // +0x30  DWORD-aligned row bytes
  uint8_t* bits;          // +0x34
  // …
  uint32_t type;          // +0x40  create type (stack param_3)
  char     lastError[64]; // +0x44  inline error text (size ≥ 0x3c used)
  // …
  // +0x1b0: optional secondary buffer pointer / flag
};

// External (not owned)
extern "C" char FUN_004321b0(void);           // precheck / destroy prior
extern "C" uint32_t* FUN_00433490(void);      // palette base in block
extern "C" void FUN_004331d0(void);           // secondary buffer path

static void copy_error(char* dst, const char* src, int dwords, bool tail_u16, bool tail_u8)
{
  uint32_t* d = reinterpret_cast<uint32_t*>(dst);
  const uint32_t* s = reinterpret_cast<const uint32_t*>(src);
  for (int i = dwords; i != 0; --i) {
    *d++ = *s++;
  }
  if (tail_u16) {
    *reinterpret_cast<uint16_t*>(d) = *reinterpret_cast<const uint16_t*>(s);
  }
  if (tail_u8) {
    *reinterpret_cast<char*>(d) = *reinterpret_cast<const char*>(s);
  }
}

// Clean explicit signature. Retail: EBX=self, EAX=height, stack width/bpp/type, RET 12.
int32_t* CxImage_Create(CxImage* self /*EBX*/,
                        int32_t height /*EAX*/,
                        int32_t width /*stack*/,
                        uint32_t bpp /*stack*/,
                        uint32_t type /*stack*/)
{
  if (FUN_004321b0() == 0) {
    return nullptr;
  }

  if (width == 0 || height == 0) {
    copy_error(self->lastError,
               "CxImage::Create : width and height must be greater than zero",
               15, false, true);
    return nullptr;
  }

  int32_t bits;
  if (bpp < 2) {
    bits = 1;
  } else if (bpp < 5) {
    bits = 4;
  } else {
    // bpp<=8 → 8; bpp>8 → 24  ( 8 + ((bpp>8)?0x10:0) )
    bits = static_cast<int32_t>((-(uint32_t)(8 < bpp) & 0x10) + 8);
  }

  if ((static_cast<uint32_t>(width * height * bits) >> 8) > 256000000u) {
    copy_error(self->lastError, "CXIMAGE_MAX_MEMORY exceeded", 7, false, false);
    return nullptr;
  }

  if (bits == 1) {
    self->paletteCount = 2;
  } else if (bits == 4) {
    self->paletteCount = 0x10;
  } else if (bits == 8) {
    self->paletteCount = 0x100;
  } else {
    self->paletteCount = 0;
  }

  int32_t stride = ((width * bits + 0x1f) >> 5) * 4;
  self->stride = stride;
  int32_t imageBytes = stride * height;
  self->bitCount = static_cast<uint16_t>(bits);
  self->width = width;
  self->type = type;
  self->biSize = 0x28;
  self->height = height;
  self->planes = 1;
  self->compression = 0;
  self->imageBytes = imageBytes;
  self->field_2c = 0;

  void* block = std::malloc(static_cast<size_t>(imageBytes + 0x28 + self->paletteCount * 4));
  self->block = block;
  if (block == nullptr) {
    copy_error(self->lastError, "CxImage::Create can't allocate memory", 9, true, false);
    return nullptr;
  }

  uint32_t* pal = FUN_00433490();
  if (pal != nullptr) {
    for (uint32_t n = static_cast<uint32_t>(self->paletteCount) & 0x3fffffffu; n != 0; --n) {
      *pal++ = 0;
    }
    // decompiler residual byte loop with count 0 omitted
  }

  // retail: if (*(int*)(this+0x1b0) != 0) FUN_004331d0();
  if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(self) + 0x1b0) != 0) {
    FUN_004331d0();
  }

  uint32_t* src = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 8);
  uint32_t* dst = reinterpret_cast<uint32_t*>(self->block);
  for (int i = 10; i != 0; --i) {
    *dst++ = *src++;
  }

  int32_t* hdr = reinterpret_cast<int32_t*>(self->block);
  if (hdr != nullptr) {
    self->bits = reinterpret_cast<uint8_t*>(hdr) + *hdr + self->paletteCount * 4;
    return hdr;
  }
  self->bits = nullptr;
  return hdr;
}

// Legacy Ghidra name — see FUN_004323e0.cpp
// int * FUN_004323e0(int param_1, uint param_2, undefined4 param_3);
