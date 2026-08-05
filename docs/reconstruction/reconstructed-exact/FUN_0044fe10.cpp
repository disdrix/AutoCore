// =============================================================================
// FUN_0044fe10  (clean twin of AnmTrackEvents_UnserializeOneEvent_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044fe10
// Address:   0x0044fe10  (autoassault.exe, image base 0x400000)
// System:    anmTrackEvents per-event unserialize
// Generated: 2026-07-29 W36-G dual seal (scaffold rewritten)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: AnmTrackEvents_UnserializeOneEvent_Inferred.cpp
// =============================================================================

#include <cstdint>

extern uint32_t FUN_0076a900(void);
extern void *FUN_0044fee0(void);
extern void __fastcall FUN_0046c1b0(uint32_t *key);

/*
 * Behavioral notes:
 * - EDI = stoChunkReader* (register formal; MOV ESI,EDI before key read).
 * - NestedHash0x10 once-get + lookup; sentinel at bag+8.
 * - Factory node[+0xC]; unserialize obj[+4] with PUSH EDI.
 * - Fail returns 0xffffffff.
 */

uint32_t FUN_0044fe10(void **out_event)
{
  uint32_t key;
  void *bag;
  void *node;
  void *obj;
  uint32_t status;

  key = FUN_0076a900();
  bag = FUN_0044fee0();
  node = 0;
  FUN_0046c1b0(&key);
  bag = FUN_0044fee0();
  if (node == *(void **)((unsigned char *)bag + 8)) {
    obj = 0;
  } else {
    obj = (*(void *(__thiscall **)(void *))(*(uint32_t *)node + 0xC))(node);
  }
  *out_event = obj;
  if (obj != 0) {
    status = (*(uint32_t(__thiscall **)(void *))(*(uint32_t *)obj + 4))(obj);
    return status;
  }
  return 0xffffffffu;
}
