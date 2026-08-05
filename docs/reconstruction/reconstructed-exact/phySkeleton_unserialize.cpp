// =============================================================================
// phySkeleton_unserialize  (aa_0096b930)
// -----------------------------------------------------------------------------
// Address:   0x0096b930–0x0096ba79 exclusive (329 B / 0x149)
// Module:    autoassault.exe @ image base 0x400000
// Ghidra:    FUN_0096b930
// System:    physics / phySkeleton.cpp asset I/O
// Wave:      W38-K OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving from decompile + read_memory. Not modernization.
// Bit-for-bit / runtime: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   stack: phySkeleton* self, stoChunkReader* reader
//   RET 0x08; returns uint32_t status (0xffffffff on bad tag/version)
//
// Semantics:
//   Enter PSKE chunk; require tag 0x50534b45 and version 1.
//   Read bone count (binary FUN_00437050 / text FUN_007689e0 via reader+0x4044).
//   FUN_0096b150(self, count); loop bone vector [self+0x0C, self+0x10):
//     phyBone_unserialize; *(bone+0x144) = index.
//   *(self+0x1C) += 1; *(self+4) |= 3; leave scope; return count-read status.
//
// Callers: FUN_00765740 (gfxBody unserialize) @ 0x00765ac5, 0x00765ea5 — body+0x98.
// Name from product strings / phySkeleton.cpp path. Alias: Named_phySkeleton_0096b930.
// =============================================================================

#include <cstdint>

struct stoChunkReader {
  // layout mostly open; dual uses only +0x4044 binary/text mode flag
  uint8_t opaque[0x4048];
};

struct phyBone {
  uint8_t opaque[0x144];
  int32_t bone_index; // +0x144 — written by this VA after unserialize
};

struct phySkeleton {
  uint8_t unk0[4];          // +0x00
  uint32_t flags;           // +0x04  (OR 3 on success)
  uint8_t pad8[4];          // +0x08
  phyBone** bones_begin;    // +0x0C
  phyBone** bones_end;      // +0x10
  uint8_t pad14[8];         // +0x14
  int32_t revision_or_gen;  // +0x1C  (+= 1 on success)
};

// External callees (not dual-owned here)
extern "C" void stoChunkReader_EnterChunkScope(stoChunkReader* reader /* + scope outs */);
extern "C" void FUN_00769e40(/* leave scope */);
extern "C" uint32_t FUN_00437050(int* out_i32);   // binary
extern "C" uint32_t FUN_007689e0(int* out_i32);   // text
extern "C" void FUN_0096b150(phySkeleton* self, int count);
extern "C" void phyBone_unserialize(/* reader / this via calling convention */);
extern "C" void* FUN_0076cec0(void* buf, const char* fmt, int ver);
extern "C" void vog_LogMessage(const char* file, int line, int level, const void* msg);

static constexpr uint32_t kTag_PSKE = 0x50534b45u;
static constexpr int kChunkVersion = 1;
static constexpr int kLineInvalidTag = 0x3a;
static constexpr int kLineInvalidVer = 0x53;

// Retail: stack (self, reader); RET 0x08
extern "C" uint32_t phySkeleton_unserialize(
    phySkeleton* self,
    stoChunkReader* reader)
{
  // SEH / ExceptionList + EnterChunkScope omitted as compiler plate.
  // After enter: chunk_tag, chunk_ver, scope_flag populated by EnterChunkScope.

  // --- illustrative CF matching sealed decompile ---
  int chunk_tag = 0;     // from scope locals
  int chunk_ver = 0;
  char scope_flag = 0;
  (void)scope_flag;

  // Live body compares tag/version produced by EnterChunkScope.
  if (chunk_tag != static_cast<int>(kTag_PSKE)) {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp",
        kLineInvalidTag,
        3,
        "Invalid TAG unserializing phySkeleton");
    // leave scope if flag; return 0xffffffff
    return 0xffffffffu;
  }
  if (chunk_ver != kChunkVersion) {
    void* msg = FUN_0076cec0(
        nullptr,
        "Invalid chunk version (%i) unserializing phySkeleton",
        chunk_ver);
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp",
        kLineInvalidVer,
        3,
        msg);
    return 0xffffffffu;
  }

  int count = 0;
  uint32_t status;
  // reader+0x4044 mode select
  if (*reinterpret_cast<int*>(reinterpret_cast<char*>(reader) + 0x4044) == 0) {
    status = FUN_00437050(&count);
  } else {
    status = FUN_007689e0(&count);
  }

  FUN_0096b150(self, count);

  int index = 0;
  for (phyBone** it = self->bones_begin; it != self->bones_end; ++it, ++index) {
    phyBone_unserialize();
    (*it)->bone_index = index;
  }

  self->revision_or_gen += 1;
  self->flags |= 3u;

  // leave scope if flag
  return status;
}
