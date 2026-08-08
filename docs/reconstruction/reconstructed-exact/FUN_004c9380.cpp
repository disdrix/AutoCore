// Scaffold twin — prefer Object_AggroMap_ExportToIntKeyMap_Inferred.cpp
// aa_004c9380 / 0x004c9380 / FUN_004c9380
// WQ9G-C 2026-08-04

#include <cstdint>

extern "C" void __thiscall FUN_004cbe20(void *map, void *out, void *value);

void __thiscall FUN_004c9380(void *self /*ECX*/, void *dest /*stack*/)
// RET 4  (decomp wrongly omits dest / marks fastcall)
{
  int *head = *(int **)((char *)self + 0x158);
  int *node = (int *)*head;
  if (node == head) {
    return;
  }
  do {
    int value[6];
    value[0] = node[8];          // score
    // value[1] not written
    value[2] = node[4];          // TFID
    value[3] = node[5];
    value[4] = node[6];
    value[5] = node[7];
    uint8_t out[8];
    FUN_004cbe20(dest, out, value);

    // inorder successor isnil@+0x29 (see named clean)
    if (*(char *)((uintptr_t)node + 0x29) == 0) {
      int *r = (int *)node[2];
      if (*(char *)((uintptr_t)r + 0x29) == 0) {
        node = r;
        int *l = (int *)*node;
        while (*(char *)((uintptr_t)l + 0x29) == 0) {
          node = l;
          l = (int *)*node;
        }
      } else {
        int *p = (int *)node[1];
        int *cur = node;
        while (*(char *)((uintptr_t)p + 0x29) == 0 && cur == (int *)p[2]) {
          cur = p;
          p = (int *)p[1];
        }
        node = p;
      }
    }
  } while (node != head);
}
