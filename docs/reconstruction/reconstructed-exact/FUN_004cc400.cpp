// Scaffold twin — prefer StdMap_OperatorIndex_Tfid_Isnil29_Inferred.cpp
// aa_004cc400 / 0x004cc400 / FUN_004cc400
// WQ9G-C 2026-08-04

#include <cstdint>

extern "C" int __thiscall FUN_004cb4b0(void *map, const uint32_t *key);
extern "C" int *__thiscall FUN_004cc220(void *map, int **outIt, int *hint, void *value);

int *__thiscall FUN_004cc400(void *map /*ECX*/, const uint32_t *key /*stack*/)
// RET 4
{
  const uint32_t *k = key;
  int it = FUN_004cb4b0(map, key);
  if (it != *(int *)((char *)map + 4)) {
    if ((*(int *)(it + 0x14) < (int)k[1]) ||
        ((*(int *)(it + 0x14) <= (int)k[1] && (*(uint32_t *)(it + 0x10) <= k[0])))) {
      return (int *)(it + 0x20);
    }
  }
  uint32_t staged[5];
  staged[0] = k[0];
  staged[1] = k[1];
  staged[2] = k[2];
  staged[3] = k[3];
  staged[4] = 0;
  int *out = nullptr;
  int *pair = FUN_004cc220(map, &out, (int *)it, staged);
  it = *pair;
  return (int *)(it + 0x20);
}
