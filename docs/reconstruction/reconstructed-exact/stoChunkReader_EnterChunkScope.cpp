// =============================================================================
// stoChunkReader_EnterChunkScope
// -----------------------------------------------------------------------------
// Stable ID: aa_004370b0
// Address:   0x004370b0–0x0043711a  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - ABI: __thiscall; ECX = ChunkScope*; stack arg = stoChunkReader*; RET 4; returns scope*.
 * - Sole callee: stoChunkReader_OpenChunk (ECX = reader).
 * - okFlag (u8 @ +8) = (signed OpenChunk result >= 0).
 * - Ring object base reader+0x4030; entries @ +0x4034; capacity +0x4038;
 *   base idx +0x403c; write idx +0x4040. Tag = *entry; version = *(entry+8).
 * - absPos @ +4 = reader[+0x1c] + reader[+0x18] (not size-inclusive chunk end).
 */

#include <cstdint>

struct StoChunkRingEntry {
  uint32_t tag;       // +0x00
  uint32_t size;      // +0x04  (not read here)
  uint32_t version;   // +0x08
  // further fields used by leave / push — not touched in this unit
};

struct StoChunkReader {
  // ... stream window ...
  // +0x18 cursor, +0x1c base partner (absolute pos partners)
  // ...
  // +0x4030 ring object:
  //   +0x4034 entries**, +0x4038 capacity, +0x403c base, +0x4040 write
};

struct ChunkScope {
  StoChunkReader* reader; // +0x00
  int32_t absPos;         // +0x04
  uint8_t okFlag;         // +0x08
  // pad 3
  uint32_t tag;           // +0x0c
  uint32_t version;       // +0x10
}; // sizeof == 0x14

// External (owned elsewhere)
extern "C" int32_t __fastcall stoChunkReader_OpenChunk(StoChunkReader* reader);

/* stoChunkReader::EnterChunkScope(scope*, reader*) - scoped chunk-enter helper used at the top of
   every Unserialize.
   Calls stoChunkReader_OpenChunk, then fills scope = {reader, endPos, okFlag(byte), tag(u32 4cc),
   version(u32)} from the reader's current chunk ring entry. Callers then check scope.tag against
   the expected 4CC ('VERT'=0x56455254, 'INDX'=0x494e4458, 'GPCE'=0x47504345, ...) and dispatch on
   scope.version. */

ChunkScope* __thiscall stoChunkReader_EnterChunkScope(ChunkScope* scope, StoChunkReader* reader)
{
  int32_t openHr;
  uint32_t idx;
  StoChunkRingEntry* entry;
  uint8_t* readerBytes;
  uint32_t* ring;
  StoChunkRingEntry** entries;

  scope->reader = reader;
  openHr = stoChunkReader_OpenChunk(reader);
  scope->okFlag = (uint8_t)(openHr >= 0);

  readerBytes = (uint8_t*)reader;
  scope->absPos = *(int32_t*)(readerBytes + 0x1c) + *(int32_t*)(readerBytes + 0x18);

  ring = (uint32_t*)(readerBytes + 0x4030);
  // ring[0] unused here; ring[1]=entries ptr as u32, ring[2]=capacity, ring[3]=base, ring[4]=write
  idx = ring[4] + ring[3] - 1;
  if (ring[2] <= idx) {
    idx = idx - ring[2];
  }
  entries = (StoChunkRingEntry**)ring[1];
  entry = entries[idx];
  scope->tag = entry->tag;

  idx = ring[4] + ring[3] - 1;
  if (ring[2] <= idx) {
    idx = idx - ring[2];
  }
  entry = entries[idx];
  scope->version = entry->version;

  return scope;
}
