// =============================================================================
// FUN_004c8970 — Ghidra twin of Object_TFIDMapLookupOrRelatedMatch_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8970
// Address:   0x004c8970  (autoassault.exe, image base 0x400000)
// Named:     reconstructed-exact/Object_TFIDMapLookupOrRelatedMatch_Inferred.cpp
// Wave:      W30-T (2026-07-29)
// Exactness: Same CF as named clean; Ghidra symbol retained as twin entry.
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall FUN_004cb4b0(void *map, uint32_t *pTfidKey);
extern "C" int __cdecl TFID_EqualsObjectId(void *pA, void *pB);

uint32_t __thiscall FUN_004c8970(
    void *param_1,
    uint32_t param_2,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5)
{
  void *map = (char *)param_1 + 0x154;
  void *end = *(void **)((char *)param_1 + 0x158);
  void *node = FUN_004cb4b0(map, &param_2);

  void *sel;
  if (node == end
      || (int)param_3 < *(int *)((char *)node + 0x14)
      || ((int)param_3 <= *(int *)((char *)node + 0x14)
          && param_2 < *(uint32_t *)((char *)node + 0x10))) {
    sel = end;
  } else {
    sel = node;
  }

  if (sel == end) {
    int mi = *(int *)(*(int *)((char *)param_1 + 4) + 4);
    int *related = *(int **)((char *)param_1 + mi + 0xA4);
    if (related != nullptr) {
      if (related[0x58] == (int)param_2
          && related[0x59] == (int)param_3
          && (char)related[0x5a] == (char)param_4) {
        return 1;
      }
      int r = (**(int(__thiscall ***)(void *))(*related + 0x214))(related);
      if (r != 0) {
        related = *(int **)((char *)param_1 + mi + 0xA4);
        r = (**(int(__thiscall ***)(void *))(*related + 0x214))(related);
        int rmi = *(int *)(*(int *)((char *)r + 4) + 4);
        if ((char)TFID_EqualsObjectId((char *)r + rmi + 0x164, &param_2) != 0) {
          return 1;
        }
      }
    }
    return 0;
  }
  return *(uint32_t *)((char *)sel + 0x20);
}
