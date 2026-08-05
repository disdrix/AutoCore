// =============================================================================
// GfxBufferedViewList_ClearField184_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00968680
// Address:   0x00968680  (autoassault.exe, image base 0x400000)
// System:    graphics / gfxBufferedView global list
// Generated: 2026-08-04 W38-Z dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler + machine bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: After successful Device Reset, walk the global circular list of
// gfxBufferedView instances (sentinel DAT_00d1ee30) and set each payload's
// dword at +0x184 to 0. Ctor (W37-I FUN_00968a50) initializes +0x184 = 1.
//
// ABI: no formals; plain RET (c3). Body 0x00968680–0x009686a7 (40 B / 0x28).
// Sole caller: FUN_0075eff0 success arm (gfxDevice.cpp Device Reset).
// =============================================================================

#include <cstdint>

struct CircListNode {
  CircListNode *next; // +0
  CircListNode *prev; // +4 (unused here)
  void *payload;      // +8  → gfxBufferedView*
};

// Global list sentinel for gfxBufferedView (also StdList control nearby 0x00d1ee2c).
extern CircListNode *DAT_00d1ee30;

void GfxBufferedViewList_ClearField184_Inferred(void)
{
  CircListNode *sentinel = DAT_00d1ee30;
  for (CircListNode *n = sentinel->next; n != sentinel; n = n->next) {
    void *view = n->payload;
    if (view != nullptr) {
      *(uint32_t *)((uint8_t *)view + 0x184) = 0;
    }
  }
}
