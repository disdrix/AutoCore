// =============================================================================
// FUN_008ab340  (twin of MissionSelect_ClearRowWidgetVectors_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab340
// Address:   0x008ab340  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Wave:      MEGA-105 (2026-08-05)
// Exactness: Behavior-preserving; see named clean for ABI notes.
// =============================================================================

#include <cstdint>

// Preferred: MissionSelect_ClearRowWidgetVectors_Inferred
// Scaffold alias (retired as product): Named_CalleeOf_Mission_Select_a_Mission_008ab340

// ESI = MissionSelectHost*; no stack args; plain RET
// Body: 0x008ab340–0x008ab549 exclusive (521 B / 0x209)

void FUN_008ab340(void)
{
  // Register this: ESI = host
  int *host; /* unaff_ESI in decompiler — sealed as ESI ABI */

  int count;
  if (host[0x1cb] == 0) {
    count = 0;
  } else {
    count = (host[0x1cc] - host[0x1cb]) >> 2;
  }
  for (int i = 0; i < count; ++i) {
    int off = i * 4;
    if (*(int *)(host[0x1cb] + off) != 0) {
      char q = (**(char (**)())(**(int **)(host[0x1cb] + off) + 0x3d8))();
      if (q != '\0') {
        (**(void (**)())(**(int **)(host[0x1cb] + off) + 0x440))();
      }
      if (*(int *)(*(int *)(host[0x1cb] + off) + 0x2b0) != 0) {
        (**(void (**)(int))(*host + 0xb0))(*(int *)(host[0x1cb] + off));
      }
      if (*(int *)(host[0x1cb] + off) != 0) {
        int *w = *(int **)(host[0x1cb] + off);
        if (w != nullptr) {
          (**(void (**)(int))(*w))(1);
        }
      }
      *(int *)(host[0x1cb] + off) = 0;
    }
  }
  {
    void *begin = (void *)host[0x1cb];
    void *end = (void *)host[0x1cc];
    if (begin != nullptr && ((int)end - (int)begin) >> 2 != 0 && begin != end) {
      // memmove(begin, end, 0); end = begin
      host[0x1cc] = (int)begin;
    }
  }

  if (host[0x1cf] == 0) {
    count = 0;
  } else {
    count = (host[0x1d0] - host[0x1cf]) >> 2;
  }
  for (int i = 0; i < count; ++i) {
    int off = i * 4;
    if (*(int *)(host[0x1cf] + off) != 0) {
      char q = (**(char (**)())(**(int **)(host[0x1cf] + off) + 0x3d8))();
      if (q != '\0') {
        (**(void (**)())(**(int **)(host[0x1cf] + off) + 0x440))();
      }
      if (*(int *)(*(int *)(host[0x1cf] + off) + 0x2b0) != 0) {
        (**(void (**)(int))(*host + 0xb0))(*(int *)(host[0x1cf] + off));
      }
      if (*(int *)(host[0x1cf] + off) != 0) {
        int *w = *(int **)(host[0x1cf] + off);
        if (w != nullptr) {
          (**(void (**)(int))(*w))(1);
        }
      }
      *(int *)(host[0x1cf] + off) = 0;
    }
  }
  {
    void *begin = (void *)host[0x1cf];
    void *end = (void *)host[0x1d0];
    if (begin != nullptr && ((int)end - (int)begin) >> 2 != 0 && begin != end) {
      host[0x1d0] = (int)begin;
    }
  }
}
