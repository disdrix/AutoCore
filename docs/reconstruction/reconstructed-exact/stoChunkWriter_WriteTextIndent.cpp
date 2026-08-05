// =============================================================================
// stoChunkWriter_WriteTextIndent
// -----------------------------------------------------------------------------
// Stable ID: aa_00767070
// Address:   0x00767070–0x0076709d  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_00767070; dual A/B seal 2026-07-29 (W17-R)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Register ABI: stoChunkWriter* in ESI (caller WriteFormatted keeps writer in ESI).
 * - No stack args; epilogue plain RET.
 * - Sets textCol (+0x20) = depth(+0x18) * 4, then writes that many single-space
 *   characters via stream vtbl+0x18 write(DAT_00a2a000, 1).
 * - Sticky-ORs each write status into writer+0x04; returns that status.
 * - depth==0 → textCol=0, no writes, return status unchanged.
 *
 * Sole caller: stoChunkWriter_WriteFormatted (0x00767160) at line-start when textCol==0.
 */

#include <cstdint>

// Stream object with vtable; slot +0x18 is write(const void* buf, int len) → status.
struct StoStream {
  void** vtbl;
};

struct StoChunkWriter {
  StoStream* stream;     // +0x00
  uint32_t status;       // +0x04  sticky OR of stream op results
  // +0x08..+0x14: chunk stack bookkeeping (not touched here)
  int32_t depth;         // +0x18  nest depth (Begin/End chunk)
  // +0x1c: mode (binary/text) — not read here
  int32_t textCol;       // +0x20  text column / line budget
};

// DAT_00a2a000 — single ASCII space (verified read_memory: 0x20 00 00 00 …)
extern const char DAT_00a2a000[]; // " "

// Register ABI: writer in ESI. Clean plate models as explicit this-pointer for readability;
// retail uses ESI only (no ECX load of writer).
uint32_t stoChunkWriter_WriteTextIndent(StoChunkWriter* writer /* retail: ESI */)
{
  int32_t count = writer->depth * 4;
  writer->textCol = count;

  if (count - 1 >= 0) { // equivalent: count > 0; matches decomp (-1 < count-1)
    do {
      // call [(*writer->stream)->vtbl + 0x18](&DAT_00a2a000, 1)
      using WriteFn = uint32_t(__thiscall*)(StoStream*, const void*, int);
      WriteFn write = (WriteFn)writer->stream->vtbl[0x18 / sizeof(void*)];
      uint32_t hr = write(writer->stream, DAT_00a2a000, 1);
      writer->status |= hr;
      count = count - 1;
    } while (count != 0);
  }

  return writer->status;
}

// Legacy scaffold alias
uint32_t FUN_00767070(void); // see raw; ESI ABI
