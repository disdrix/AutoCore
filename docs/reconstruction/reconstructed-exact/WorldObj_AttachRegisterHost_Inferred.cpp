// =============================================================================
// WorldObj_AttachRegisterHost_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e760
// Address:   0x0055e760–0x0055e850 (240 B / 0xF0); ret 4
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_0055e760
// System:    world-object / phys host attach
// Dual:      2026-07-29 W29-T OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = Manager*; stack = WorldObj*; void; ret 4
//
// CF (machine-corrected; decompiler drops FUN_006291e0 this):
//   1. obj+8 = manager
//   2. if obj+0x40:  Host_Attach(*(manager+0x2c), obj); return
//   3. if manager+0x23c:
//        host = arena.alloc(0xa8, tag 0x2d); host+4 = 0xa8
//        Host_Init(host, manager); host+0x24 = manager.count
//        Host_Attach(host, obj); push host on manager+8 list; return
//   4. if manager.count==0: same create/push first host
//   5. Host_Attach(manager.list[0], obj)
//
// Callers: WorldObj_EnrollActivate, ReattachLinksGuarded, RehomeLinksFromSnapshot
// Nested: FUN_006291e0 (host attach), FUN_006295f0 (host init), FUN_005b3370, DAT_00b05060

// Forward decls of nested (not dual-sealed here)
extern "C" void __thiscall FUN_006291e0(int host, int obj);
extern "C" void __thiscall FUN_006295f0(int host, int manager);
extern "C" void FUN_005b3370(int *desc, int elemSize);
extern int *DAT_00b05060;

void __thiscall WorldObj_AttachRegisterHost_Inferred(int manager, uint32_t obj)
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
