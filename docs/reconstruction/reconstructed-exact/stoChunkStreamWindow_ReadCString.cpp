// =============================================================================
// stoChunkStreamWindow_ReadCString
// -----------------------------------------------------------------------------
// Stable ID: aa_00436f10
// Address:   0x00436f10–0x00436f7b  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk stream window
// Generated: 2026-07-23 scaffold as FUN_00436f10; dual A/B seal 2026-08-04 (W38-D)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Entry ABI: ESI = StoStreamWindow*, EDI = std::string* out; bare RET.
 * - Clears out via string::resize(out, 0).
 * - Loop while cursor+base < streamEnd (+0x14): ensure 1 byte, read, advance cursor.
 * - NUL terminator: consume and return 0 (not appended to string).
 * - Fail −1: ensure hr < 0, available < 1 after ensure, or hit streamEnd without NUL.
 * - Binary-mode peer of text FUN_0076a200 (mode at reader+0x4044 via wrappers).
 * - Callers usually pass window = reader+0x14.
 */

#include <cstdint>
#include <string>

struct StoStreamWindow {
  // +0x00: stream iface / other (not read here)
  int32_t cursor;       // +0x04
  int32_t base;         // +0x08
  int32_t available;    // +0x0c
  // +0x10: capacity / other
  int32_t streamEnd;    // +0x14  (absolute; stop before)
  // +0x18: inline data buffer base
};

// External (not owned this unit)
extern "C" int32_t __thiscall FUN_00435df0(StoStreamWindow* window, int32_t absPos);
// IAT: std::string::resize, std::string::operator+=(char)

// Clean plate takes explicit args; retail uses ESI=window, EDI=out, bare RET.
int32_t stoChunkStreamWindow_ReadCString(
    StoStreamWindow* window /*ESI*/,
    std::string* out /*EDI*/)
{
  out->resize(0);

  if (window->cursor + window->base >= window->streamEnd) {
    return -1; // 0xffffffff
  }

  do {
    if (window->available < window->cursor + 1) {
      int32_t hr = FUN_00435df0(window, window->base + window->cursor);
      if (hr < 0) {
        return -1;
      }
      if (window->available < 1) {
        return -1;
      }
    }

    char c = *reinterpret_cast<char*>(
        reinterpret_cast<uint8_t*>(window) + 0x18 + window->cursor);
    window->cursor += 1;

    if (c == '\0') {
      return 0; // NUL consumed
    }

    (*out) += c;
  } while (window->cursor + window->base < window->streamEnd);

  return -1; // streamEnd without NUL
}

// Legacy Ghidra name — see FUN_00436f10.cpp
