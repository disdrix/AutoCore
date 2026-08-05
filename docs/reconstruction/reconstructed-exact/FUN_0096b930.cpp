// =============================================================================
// FUN_0096b930 — scaffold twin of phySkeleton_unserialize (aa_0096b930)
// Wave W38-K 2026-08-04. Prefer named clean:
//   docs/reconstruction/reconstructed-exact/phySkeleton_unserialize.cpp
// =============================================================================

#include <cstdint>

extern "C" uint32_t phySkeleton_unserialize(void* self, void* reader);

extern "C" uint32_t FUN_0096b930(void* self, void* reader)
{
  return phySkeleton_unserialize(self, reader);
}
