// =============================================================================
// stoChunkReader_LeaveChunk
// -----------------------------------------------------------------------------
// Stable ID: aa_00769e40
// Address:   0x00769e40–0x00769fcc  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - ABI: ECX = stoChunkReader*; no stack args; plain RET; EAX = sticky (this+0x402c).
 * - Clears sticky to 0, may OR 0xffffffff on fail.
 * - Binary (+0x4044==0): ring top entry[+0x10] end absolute → reposition +0x18/+0x1c/+0x20.
 * - Text (+0x4044!=0): brace nest via FUN_00767840(this,1); log stoChunk.cpp:0x20d on fail.
 * - Always pop ring write (+0x4040); clear base (+0x403c) when write hits 0.
 * - Pair: EnterChunkScope 0x004370b0 / OpenChunk 0x0076a2c0; okFlag thunk 0x00437120.
 */

#include <cstdint>
#include <string>

struct StoChunkRingEntry {
  uint32_t tag;       // +0x00
  uint32_t size;      // +0x04
  uint32_t version;   // +0x08
  uint32_t reserved;  // +0x0c
  int32_t  endAbs;    // +0x10  (used by LeaveChunk)
}; // element size Probable 0x14

struct StoChunkReader {
  // stream window (via +0x14 base in OpenChunk notes)
  // +0x18 cursor, +0x1c base partner, +0x20 remaining, +0x28 limit
  // +0x402c stickyError
  // +0x4030 ring object: +0x4034 entries**, +0x4038 capacity, +0x403c base, +0x4040 write
  // +0x4044 textMode
};

// External (owned elsewhere)
extern "C" uint32_t FUN_00767840(StoChunkReader* reader, char allowPastEnd);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

/* stoChunkReader::LeaveChunk()
   Leave the current open chunk: binary path seeks the stream to the ring-top end
   absolute; text path consumes tokens until brace nesting returns to zero, then both
   paths pop one ring level. Returns sticky error at this+0x402c (0 ok, -1 fail). */

uint32_t __fastcall stoChunkReader_LeaveChunk(StoChunkReader* self /* ECX */)
{
  uint8_t* r = reinterpret_cast<uint8_t*>(self);
  uint32_t idx;
  int32_t endPos;
  int32_t base;
  int depth;
  std::string token;

  // sticky = 0
  *reinterpret_cast<uint32_t*>(r + 0x402c) = 0;

  if (*reinterpret_cast<int32_t*>(r + 0x4044) == 0) {
    idx = static_cast<uint32_t>(
        *reinterpret_cast<int32_t*>(r + 0x4040) +
        *reinterpret_cast<int32_t*>(r + 0x403c) - 1);
    if (*reinterpret_cast<uint32_t*>(r + 0x4038) <= idx) {
      idx -= *reinterpret_cast<uint32_t*>(r + 0x4038);
    }
    {
      StoChunkRingEntry** entries =
          *reinterpret_cast<StoChunkRingEntry***>(r + 0x4034);
      endPos = entries[idx]->endAbs;
    }
    if (endPos < 0 || *reinterpret_cast<int32_t*>(r + 0x28) < endPos) {
      *reinterpret_cast<uint32_t*>(r + 0x402c) |= 0xffffffffu;
    } else {
      base = *reinterpret_cast<int32_t*>(r + 0x1c);
      if (endPos < base ||
          base + *reinterpret_cast<int32_t*>(r + 0x20) <= endPos) {
        *reinterpret_cast<int32_t*>(r + 0x1c) = endPos;
        *reinterpret_cast<uint32_t*>(r + 0x20) = 0;
        *reinterpret_cast<uint32_t*>(r + 0x18) = 0;
      } else {
        *reinterpret_cast<int32_t*>(r + 0x18) = endPos - base;
      }
      // success: OR sticky with 0 (no-op)
    }
  } else {
    depth = 1;
    do {
      uint32_t st = FUN_00767840(self, 1);
      *reinterpret_cast<uint32_t*>(r + 0x402c) |= st;
      if (static_cast<int32_t>(*reinterpret_cast<uint32_t*>(r + 0x402c)) < 0) {
        vog_LogMessage(
            "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
            0x20d, 3, "Could not find end of text chunk");
        return 0xffffffffu;
      }
      // token filled by FUN_00767840 into caller-owned string (EDI in retail)
      if (token == "{") depth++;
      if (token == "}") depth--;
    } while (depth != 0);
  }

  if (*reinterpret_cast<int32_t*>(r + 0x4040) != 0) {
    int32_t w = *reinterpret_cast<int32_t*>(r + 0x4040) - 1;
    *reinterpret_cast<int32_t*>(r + 0x4040) = w;
    if (w == 0) {
      *reinterpret_cast<uint32_t*>(r + 0x403c) = 0;
    }
  }
  return *reinterpret_cast<uint32_t*>(r + 0x402c);
}
