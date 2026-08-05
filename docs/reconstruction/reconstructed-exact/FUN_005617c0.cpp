// Twin of WorldObj_SnapshotHostRefsAndUnbind_Inferred — see that file for sealed CF.
// Stable ID: aa_005617c0  VA: 0x005617c0  Dual: W29-T 2026-07-29

#include <stdint.h>

extern "C" void FUN_005b3370(int *desc, int elemSize);
extern "C" void __thiscall FUN_005614f0(int manager, uint8_t *outFlag, int obj);

void __thiscall FUN_005617c0(int manager, int obj, int *snapshot)
{
  int host;
  int *listBase;
  int i;
  int entry;
  int *slot;
  int managerLocal;
  uint8_t local16[16];
  int newCount;
  int j;

  host = *(int *)(manager + 0x2c);
  listBase = (int *)(host + 0x58);
  snapshot[1] = 0;
  managerLocal = manager;

  i = 0;
  if (*(int *)(host + 0x5c) > 0) {
    do {
      slot = (int *)(*listBase + i * 4);
      entry = *slot;
      if (*(int *)(entry + 0xc) == obj || *(int *)(entry + 0x10) == obj) {
        if (snapshot[1] == (snapshot[2] & 0x7fffffff)) {
          FUN_005b3370(snapshot, 4);
        }
        *(int *)(*snapshot + snapshot[1] * 4) = entry;
        snapshot[1] = snapshot[1] + 1;

        (**(void(__thiscall ***)(int, uint8_t *))entry)[0x28 / 4](entry, local16);
        (**(void(__thiscall ***)(int, int, int *))*(int *)(manager + 0x2c))[0xc / 4](
            *(int *)(manager + 0x2c), entry, &managerLocal);

        host = *(int *)(manager + 0x2c);
        newCount = *(int *)(host + 0x5c) - 1;
        *(int *)(host + 0x5c) = newCount;
        j = i;
        if (i < newCount) {
          do {
            *(uint32_t *)(*(int *)(host + 0x58) + j * 4) =
                *(uint32_t *)(*(int *)(host + 0x58) + j * 4 + 4);
            j = j + 1;
          } while (j < *(int *)(host + 0x5c));
        }
        i = i - 1;
      }
      i = i + 1;
    } while (i < *(int *)(host + 0x5c));
  }

  FUN_005614f0(manager, (uint8_t *)&obj, obj);
}
