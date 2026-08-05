// =============================================================================
// stoChunkStreamWindow_ReadHeader16
// -----------------------------------------------------------------------------
// Stable ID: aa_004368b0
// Address:   0x004368b0–0x004368f9  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_004368b0; dual A/B seal 2026-07-29 (W17-R)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Register ABI: ESI = stream window*, EDI = uint32_t out[4] (16-byte header).
 * - If available < cursor+0x10, call FUN_00435df0(window, base+cursor) as thiscall
 *   (ECX=window, stack arg=abs pos). Fail if ensure hr < 0 or available < 0x10.
 * - Copy 4 LE dwords from window+0x18+cursor → *EDI; cursor += 0x10; return 0.
 * - Sole caller: stoChunkReader_OpenChunk binary path (ESI=reader+0x14, EDI=stack header).
 *
 * Header words (OpenChunk plate): tag, size, version, reserved.
 */

#include <cstdint>

struct StoStreamWindow {
  // +0x00: stream iface / other (not read here)
  // layout used:
  int32_t cursor;      // +0x04
  int32_t base;        // +0x08  file-offset partner for ensure arg
  int32_t available;   // +0x0c  valid bytes in buffer
  // +0x10..+0x17 pad / other
  // +0x18: inline data buffer base (byte address = (uint8_t*)this + 0x18)
};

// External (not owned this unit)
extern "C" int32_t __thiscall FUN_00435df0(StoStreamWindow* window, int32_t absPos);

// Register ABI: ESI=window, EDI=out. Clean plate takes explicit args for readability.
int32_t stoChunkStreamWindow_ReadHeader16(StoStreamWindow* window /*ESI*/,
                                          uint32_t out[4] /*EDI*/)
{
  int32_t cursor = window->cursor;

  if (window->available < cursor + 0x10) {
    int32_t hr = FUN_00435df0(window, window->base + cursor);
    if (hr < 0 || window->available < 0x10) {
      return -1; // 0xffffffff
    }
    cursor = window->cursor;
  }

  uint32_t* src = (uint32_t*)((uint8_t*)window + 0x18 + cursor);
  out[0] = src[0];
  out[1] = src[1];
  out[2] = src[2];
  out[3] = src[3];

  window->cursor = cursor + 0x10;
  return 0;
}

// Legacy Ghidra name
// uint32_t FUN_004368b0(void); // ESI/EDI ABI — see raw
