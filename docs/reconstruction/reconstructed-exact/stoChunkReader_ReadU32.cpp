// =============================================================================
// stoChunkReader_ReadU32
// -----------------------------------------------------------------------------
// Stable ID: aa_00437050
// Address:   0x00437050–0x00437095  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_00437050; dual A/B seal 2026-07-29 (W18-N)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Entry ABI: EAX = stoChunkReader*, stack = uint32_t* out; epilogue RET 4.
 * - Internally remaps to stream window at reader+0x14 (same layout as ReadHeader16).
 * - If available < cursor+4, call FUN_00435df0(window, base+cursor) thiscall.
 *   Fail if ensure hr < 0 or available < 4 after ensure.
 * - Read one LE u32 from window+0x18+cursor; cursor += 4; return 0.
 * - Binary-mode peer of text FUN_007689e0 (mode at reader+0x4044 via FUN_00436900).
 */

#include <cstdint>

struct StoStreamWindow {
  // +0x00: stream iface / other (not read here)
  int32_t cursor;      // +0x04
  int32_t base;        // +0x08
  int32_t available;   // +0x0c
  // +0x10..+0x17 pad / other
  // +0x18: inline data buffer base
};

struct StoChunkReader {
  // … other fields …
  // +0x14: StoStreamWindow window (fields at +0x18/+0x1c/+0x20/+0x2c relative to reader)
  // +0x4044: mode (0 = binary)
};

// External (not owned this unit)
extern "C" int32_t __thiscall FUN_00435df0(StoStreamWindow* window, int32_t absPos);

// Clean plate takes explicit args; retail uses EAX=reader + stack out + RET 4.
int32_t stoChunkReader_ReadU32(StoChunkReader* reader /*EAX*/, uint32_t* out /*stack*/)
{
  StoStreamWindow* window = (StoStreamWindow*)((uint8_t*)reader + 0x14);
  int32_t cursor = window->cursor;

  if (window->available < cursor + 4) {
    int32_t hr = FUN_00435df0(window, window->base + cursor);
    if (hr < 0 || window->available < 4) {
      return -1; // 0xffffffff
    }
    cursor = window->cursor;
  }

  *out = *(uint32_t*)((uint8_t*)window + 0x18 + cursor);
  window->cursor = cursor + 4;
  return 0;
}

// Legacy Ghidra name — see FUN_00437050.cpp
// undefined4 FUN_00437050(undefined4 *param_1); // in_EAX = reader
