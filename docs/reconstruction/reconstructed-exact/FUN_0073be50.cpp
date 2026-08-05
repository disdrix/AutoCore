// =============================================================================
// FUN_0073be50  — twin of GlyphCacheList_ForEach_OnDeviceReset_Inferred
// Stable ID: aa_0073be50 | VA 0x0073be50 | W38-U
// Prefer named clean: GlyphCacheList_ForEach_OnDeviceReset_Inferred.cpp
// =============================================================================

#include <cstdint>

struct CircListNode {
  CircListNode* next;
};

extern "C" void FUN_00755820(void* glyph_cache /*ESI*/);

extern "C" uint32_t FUN_0073be50(void* container /*EBX*/)
{
  auto* sentinel =
      *reinterpret_cast<CircListNode**>(reinterpret_cast<char*>(container) + 8);
  CircListNode* node = sentinel->next;
  if (node != sentinel) {
    do {
      void* payload =
          *reinterpret_cast<void**>(reinterpret_cast<char*>(node) + 0x2c);
      FUN_00755820(payload);
      node = node->next;
    } while (node !=
             *reinterpret_cast<CircListNode**>(
                 reinterpret_cast<char*>(container) + 8));
  }
  return 0;
}
