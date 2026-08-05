// =============================================================================
// GlyphCacheList_ForEach_OnDeviceReset_Inferred  (Ghidra: FUN_0073be50)
// -----------------------------------------------------------------------------
// Stable ID: aa_0073be50
// Address:   0x0073be50  (autoassault.exe, image base 0x400000)
// System:    graphics / GlyphCache device-reset broadcast
// Generated: 2026-08-04 W38-U dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Walk circular list at container+8; for each node call FUN_00755820 with
//   payload at node+0x2c (GlyphCache* family). Always returns 0.
//
// ABI (bytes — decompiler unaff_EBX incomplete):
//   EBX = container*
//   no stack formals
//   RET (plain C3)
//   callee FUN_00755820 takes ESI = *(node+0x2c)
//
// SOLE CALLER:
//   GfxDevice_Reset (FUN_0075eff0) success path:
//     MOV EBX, [device+0x758]
//     CALL 0x0073be50
//
// BODY: 0x0073be50–0x0073be74 exclusive (36 B). Dual: accept-with-gaps.
// =============================================================================

#include <cstdint>

struct CircListNode {
  CircListNode* next;  // +0x00
  // ... other link/key fields ...
  // void* payload at +0x2c (GlyphCache*)
};

struct CircListContainer {
  // ...
  // CircListNode* sentinel at +0x08
};

// Unowned per-cache device-reset hook (ESI = GlyphCache*).
extern "C" void FUN_00755820(void* glyph_cache /*ESI*/);

// Documentary signature — real ABI is EBX container live-in.
extern "C" uint32_t GlyphCacheList_ForEach_OnDeviceReset_Inferred(
    void* container /*EBX*/)
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
