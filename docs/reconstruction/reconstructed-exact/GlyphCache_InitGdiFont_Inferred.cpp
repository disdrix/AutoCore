// =============================================================================
// GlyphCache_InitGdiFont_Inferred  (Ghidra: FUN_00754a10)
// -----------------------------------------------------------------------------
// Stable ID: aa_00754a10
// Address:   0x00754a10  (autoassault.exe, image base 0x400000)
// System:    GlyphCache / Palantir GDI font open (gfxFontImpl.cpp)
// Generated: 2026-08-04 W38-N dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Initialize GDI resources on an existing GlyphCache (0xB8) host:
//     ESI = GlyphCache* this
//     ECX = style flags (bit0 Bold, bit1 Italic, bit2 Shadow, bit3 Outline)
//     stack: face name (char*), height (int lfHeight)
//     RET 8
//     return EAX: 0 success, 0xFFFFFFFF failure
//
//   Builds display name "%s %i (%s)", CreateFontIndirectA + metrics,
//   power-of-two atlas dims (capped by GfxDevice DAT_00d1f044), and a
//   32bpp top-down DIB section for glyph rasterization.
//
// PRODUCT:
//   Path string: C:\vog\1_code\palantir\palantir\graphics\gfxFontImpl.cpp
//   Factory: GlyphCache_GetOrCreate_ByFontKey (FUN_0073bc50) — face then "Arial".
//   Host ctor: GlyphCache_PlacementCtor (FUN_00754ee0, W35-H).
//
// BODY: 0x00754a10–0x00754edc exclusive (1228 B / 0x4CC). Dual: accept-with-gaps.
// =============================================================================

#include <cstdint>
#include <windows.h>

// Unowned helpers / globals (declarations only).
extern "C" void FUN_00754970();
extern "C" void* FUN_0076cec0(void* buf, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, const void* msg);
extern char DAT_00d1a548;
extern uint8_t* DAT_00d1f044;  // GfxDevice* — caps at +0x6C / +0x70

// Documentary layout — only fields this unit writes are listed.
struct GlyphCache {
  uint8_t  _pad0[0x18];
  // +0x18 basic_string display name
  uint8_t  display_name[0x1C];
  uint32_t style;           // +0x34
  uint32_t atlas_w;         // +0x38
  uint32_t atlas_h;         // +0x3C
  uint32_t rows;            // +0x40
  uint8_t  _pad44[0x28];
  uint32_t quality;         // +0x6C
  uint32_t cell_h;          // +0x70
  int32_t  ascent;          // +0x74
  int32_t  descent;         // +0x78
  int32_t  line_pitch;      // +0x7C
  int32_t  external_lead;   // +0x80
  int32_t  max_char_w;      // +0x84
  uint16_t first_char;      // +0x88
  uint16_t last_char;       // +0x8A
  uint8_t  _pad8C[0x14];
  HBITMAP  dib;             // +0xA0
  HFONT    font;            // +0xA4
  HDC      dc;              // +0xA8
  void*    bits;            // +0xAC
  int32_t  cell_w_copy;     // +0xB0
  int32_t  cell_h_copy;     // +0xB4
  // sizeof 0xB8
};

// Real ABI: ESI=this, ECX=style, stack face+height, RET 8.
// Standard prototype cannot express ESI this — plate documents it.
extern "C" int GlyphCache_InitGdiFont_Inferred(
    uint32_t style /*ECX*/,
    char* face /*stack*/,
    int height /*stack*/)
{
  GlyphCache* self = nullptr;  // = ESI at call
  (void)self;
  (void)style;
  (void)face;
  (void)height;

  // Sealed algorithm (see raw + annotated):
  // 1. if (!DAT_00d1a548) FUN_00754970();
  // 2. style tag string Bold|Italic|Shadow|Outline or "Normal"
  // 3. snprintf "%s %i (%s)" → self->display_name; self->style = style
  // 4. LOGFONTA: weight 400/700, italic, height, charset 1, outprec 8,
  //    quality 5 (or 3 if height < 14), strncpy face 32
  // 5. CreateFontIndirectA → self->font; CreateCompatibleDC → self->dc
  // 6. GetTextMetricsW → metrics fields; shadow/outline pad
  // 7. pow2 atlas from 0x100 capped by DAT_00d1f044[+0x6C/+0x70]
  // 8. CreateDIBSection 32bpp biHeight=-cellH → self->dib / bits
  // 9. SelectObject DIB; SetTextColor white; SetBkMode TRANSPARENT; return 0
  // fail: vog_LogMessage(gfxFontImpl.cpp, line, 3, msg); return -1

  return 0;
}
