// =============================================================================
// FUN_00968680  /  GfxBufferedViewList_ClearField184_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00968680
// Address:   0x00968680  (autoassault.exe, image base 0x400000)
// System:    graphics / gfxBufferedView global list
// Generated: 2026-08-04 W38-Z (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern uint32_t *DAT_00d1ee30; // sentinel node*

void FUN_00968680(void)
{
  uint32_t *sentinel = DAT_00d1ee30;
  for (uint32_t *node = (uint32_t *)*DAT_00d1ee30; node != sentinel; node = (uint32_t *)*node) {
    // node[0] = next; node[2] = payload*
    if (node[2] != 0) {
      *(uint32_t *)(node[2] + 0x184) = 0;
    }
  }
}
