// =============================================================================
// FUN_00970910  (twin of AssPreloader_ExtBucketFromPath_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00970910
// Address:   0x00970910
// Wave:      W38-C
// =============================================================================

#include <cstdint>
#include <cstring>

struct MsvcBasicString {
  union {
    char sso[16];
    char* heap;
  };
  uint32_t size;
  uint32_t capacity;
};

extern MsvcBasicString DAT_00d1f7f0[5];
extern char* PTR_DAT_00afa2bc;

static const char* c_str(const MsvcBasicString* s)
{
  return (s->capacity > 0x0f) ? s->heap : s->sso;
}

extern "C" int FUN_00970910(const char** name_holder)
{
  const char* hay = *name_holder;
  if (hay == nullptr)
    hay = PTR_DAT_00afa2bc;
  for (int i = 0; i < 4; ++i) {
    if (std::strstr(hay, c_str(&DAT_00d1f7f0[i])) != nullptr)
      return i;
  }
  return 4;
}
