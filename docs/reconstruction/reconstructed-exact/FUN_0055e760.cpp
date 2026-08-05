// Twin of WorldObj_AttachRegisterHost_Inferred — see that file for sealed CF.
// Stable ID: aa_0055e760  VA: 0x0055e760  Dual: W29-T 2026-07-29

#include <stdint.h>

extern "C" void __thiscall FUN_006291e0(int host, int obj);
extern "C" void __thiscall FUN_006295f0(int host, int manager);
extern "C" void FUN_005b3370(int *desc, int elemSize);
extern int *DAT_00b05060;

void __thiscall FUN_0055e760(int manager, uint32_t obj)
{
  int host;
  uint32_t count;
  uint32_t cap;

  *(int *)(obj + 8) = manager;

  if (*(uint8_t *)(obj + 0x40) != 0) {
    FUN_006291e0(*(int *)(manager + 0x2c), (int)obj);
    return;
  }

  if (*(uint8_t *)(manager + 0x23c) != 0) {
    host = (*(int(__thiscall **)(int *, int, int))(*DAT_00b05060 + 0x10))(
        DAT_00b05060, 0xa8, 0x2d);
    *(uint16_t *)(host + 4) = 0xa8;
    FUN_006295f0(host, manager);
    *(uint32_t *)(host + 0x24) = *(uint32_t *)(manager + 0xc);
    FUN_006291e0(host, (int)obj);

    count = *(uint32_t *)(manager + 0xc);
    cap = *(uint32_t *)(manager + 0x10) & 0x7fffffff;
    if (count == cap) {
      FUN_005b3370((int *)(manager + 8), 4);
    }
    *(int *)(*(int *)(manager + 8) + *(int *)(manager + 0xc) * 4) = host;
    *(int *)(manager + 0xc) = *(int *)(manager + 0xc) + 1;
    return;
  }

  if (*(int *)(manager + 0xc) == 0) {
    host = (*(int(__thiscall **)(int *, int, int))(*DAT_00b05060 + 0x10))(
        DAT_00b05060, 0xa8, 0x2d);
    *(uint16_t *)(host + 4) = 0xa8;
    FUN_006295f0(host, manager);
    *(uint32_t *)(host + 0x24) = *(uint32_t *)(manager + 0xc);

    count = *(uint32_t *)(manager + 0xc);
    cap = *(uint32_t *)(manager + 0x10) & 0x7fffffff;
    if (count == cap) {
      FUN_005b3370((int *)(manager + 8), 4);
    }
    *(int *)(*(int *)(manager + 8) + *(int *)(manager + 0xc) * 4) = host;
    *(int *)(manager + 0xc) = *(int *)(manager + 0xc) + 1;
  }

  FUN_006291e0(**(int **)(manager + 8), (int)obj);
}
