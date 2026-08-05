// =============================================================================
// NDAssetImage_WriteAlphaPlaneByte
// -----------------------------------------------------------------------------
// Stable ID: aa_00433280
// Address:   0x00433280  (autoassault.exe, image base 0x400000)
// System:    gfx-asset / NDAssetImage / alpha plane
// Generated: 2026-07-29 W23-A dual A/B seal
// Exactness: Behavior-preserving; register ABI from read_memory (not modernization).
// Bit-for-bit vs retail EXE: DEFERRED.
// Prior scaffold: FUN_00433280
// =============================================================================

// PURPOSE:
// Write one uint8 into the image alpha plane at (col,row) if plane is allocated
// and coordinates are in-range. Silent no-op otherwise.
//
// ABI (machine):
//   EAX = NDAssetImage* this
//   ESI = int row
//   EDX = int col
//   [esp+4] = uint8_t alpha
//   RET 4
//
// Layout:
//   +0x0c  int32 width
//   +0x10  int32 height
//   +0x1b0 uint8_t* alphaPlane
//
// Callers: NDAssetImage_DecodeUncompressedTgaRow (32bpp), PNG decode path.
// Sibling read: FUN_004332b0 @ 0x004332b0

#include <stdint.h>

typedef struct NDAssetImage_AlphaView {
  /* ... */
  /* +0x0c */ int32_t width;
  /* +0x10 */ int32_t height;
  /* ... */
  /* +0x1b0 */ uint8_t *alpha_plane;
} NDAssetImage_AlphaView;

/* Faithful control flow; C cannot express EAX/ESI/EDX formals — document registers. */
void NDAssetImage_WriteAlphaPlaneByte(
    NDAssetImage_AlphaView *image /*eax*/,
    int32_t row /*esi*/,
    int32_t col /*edx*/,
    uint8_t alpha /*stack, ret 4*/)
{
  uint8_t *plane;
  int32_t width;

  plane = *(uint8_t **)((uint8_t *)image + 0x1b0);
  if (plane == 0) {
    return;
  }
  if (row < 0) {
    return;
  }
  if (row >= *(int32_t *)((uint8_t *)image + 0x10)) {
    return;
  }
  if (col < 0) {
    return;
  }
  width = *(int32_t *)((uint8_t *)image + 0x0c);
  if (col >= width) {
    return;
  }
  plane[(int32_t)(width * row) + col] = alpha;
}
