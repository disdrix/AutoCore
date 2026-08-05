// =============================================================================
// stoChunkReader_ReadU8
// -----------------------------------------------------------------------------
// Stable ID: aa_00437000
// Address:   0x00437000–0x00437048  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_00437000; dual A/B seal 2026-08-04 (W38-D)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Entry ABI: EAX = stoChunkReader*, EDI = uint8_t* out; bare RET.
 * - Internally remaps to stream window at reader+0x14 (same layout as ReadU32).
 * - If available < cursor+1, call FUN_00435df0(window, base+cursor) thiscall.
 *   Fail if ensure hr < 0 or available < 1 after ensure.
 * - Read one u8 from window+0x18+cursor; cursor += 1; *out = byte; return 0.
 * - Fail path also writes *out from stack spill (entry-ECX high byte) — unreliable;
 *   do not depend on *out after −1. Sibling ReadU32 leaves *out untouched on fail.
 * - Binary-mode peer of text FUN_00769660 (mode at reader+0x4044 via FUN_00439a50).
 * - Neighbor: stoChunkReader_ReadU32 @ 0x00437050 (4 B, stack out, RET 4).
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

// Clean plate takes explicit args; retail uses EAX=reader, EDI=out, bare RET.
int32_t stoChunkReader_ReadU8(
    StoChunkReader* reader /*EAX*/,
    uint8_t* out /*EDI*/)
{
  StoStreamWindow* window =
      reinterpret_cast<StoStreamWindow*>(reinterpret_cast<uint8_t*>(reader) + 0x14);
  int32_t cursor = window->cursor;

  if (window->available < cursor + 1) {
    int32_t hr = FUN_00435df0(window, window->base + cursor);
    if (hr < 0 || window->available < 1) {
      // Retail: *out = high byte of entry-ECX push slot (undefined product value).
      // Port: leave *out unchanged or document as unspecified on failure.
      (void)out;
      return -1; // 0xffffffff
    }
    cursor = window->cursor;
  }

  *out = *(reinterpret_cast<uint8_t*>(window) + 0x18 + cursor);
  window->cursor = cursor + 1;
  return 0;
}

// Legacy Ghidra name — see FUN_00437000.cpp
