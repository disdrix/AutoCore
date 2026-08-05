// =============================================================================
// AssPreloader_ExtBucketFromPath_Inferred  (FUN_00970910)
// -----------------------------------------------------------------------------
// Stable ID: aa_00970910
// Address:   0x00970910  (autoassault.exe, image base 0x400000)
// System:    AssPreloader asset-path extension bucket
// Generated: 2026-08-04 W38-C (sealed from decompile + read_memory)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Map a path/name C-string to asset bucket index:
//   0 = ".geo", 1 = ".dds", 2 = ".ogg", 3 = ".xml", 4 = OTHER (default).
// Used by AssPreloader tally paths to index host+0xe8 / host+0xfc arrays.
//
// ABI: stack (const char** name_holder); returns int; RET 4.
// Once-init static basic_string table at DAT_00d1f7f0 (stride 0x1c).
// "OTHER" is stored but not strstr-scanned; default return 4 is the OTHER bucket.

#include <cstdint>
#include <cstring>

struct MsvcBasicString {
  union {
    char sso[16];
    char* heap;
  };
  uint32_t size;
  uint32_t capacity;
}; // 0x1c

// BSS statics (image)
extern MsvcBasicString DAT_00d1f7f0[5]; // .geo .dds .ogg .xml OTHER
extern uint32_t DAT_00d1f87c;           // once flag bit0
extern char* PTR_DAT_00afa2bc;          // -> empty ""

static const char* c_str(const MsvcBasicString* s)
{
  return (s->capacity > 0x0f) ? s->heap : s->sso;
}

// FUN_00970910
extern "C" int AssPreloader_ExtBucketFromPath_Inferred(const char** name_holder)
{
  // once-init omitted here: constructs five basic_strings + atexit (see raw)
  // if ((DAT_00d1f87c & 1) == 0) { ... }

  const char* hay = *name_holder;
  if (hay == nullptr)
    hay = PTR_DAT_00afa2bc; // empty string

  // Scan only first four extensions; bound is before OTHER slot
  for (int i = 0; i < 4; ++i) {
    const char* ext = c_str(&DAT_00d1f7f0[i]);
    if (std::strstr(hay, ext) != nullptr)
      return i;
  }
  return 4; // OTHER
}

// Scaffold alias
extern "C" int FUN_00970910(const char** name_holder)
{
  return AssPreloader_ExtBucketFromPath_Inferred(name_holder);
}
