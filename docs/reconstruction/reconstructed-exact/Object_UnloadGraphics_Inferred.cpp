// =============================================================================
// Object_UnloadGraphics_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005825d0
// Address:   0x005825d0–0x00582664 (148 B / 0x94); bare RET
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_005825d0
// System:    object graphics unload / mission-state FX
// Dual:      2026-07-29 W31-T OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = MI this; void; bare RET (C3)
//
// Sole CODE caller: FUN_005d4fd0 logs "UnloadGraphics on %s (%d)" then calls body.
// Also DATA-installed in 14 object vtables.
//
// CF (machine-sealed; bytes win over decompile on first callee this):
//   1. manager = *(*(mi_via_vb + 0xA8) + 0xE914)
//      FUN_004bfd10(manager, this)          // remove from tracking lists
//   2. byte[this+0x0F] = 0
//   3. root = this + vb_adj + 4
//      root->vtbl+0x144()                   // graphics destroy slot family
//   4. Object_SetMissionStateFx(root, 3)    // W30-H sealed
//   5. host = *(mi_via_vb + 0xA8)
//      if notify = *(host+0xE500): (*notify)(root)
//   6. root->vtbl+0xFC()
//   7. this->vtbl+0x04(); this->vtbl+0x18(0); this->vtbl+0x18(1)

#include <stdint.h>

extern "C" uint32_t __thiscall FUN_004bfd10(void *manager /*ECX*/, void *tracked /*stack*/);
extern "C" void __thiscall Object_SetMissionStateFx_Inferred(void *object /*ECX*/, int newState);

static inline int vb_adj(void *mi)
{
  int *meta = *(int **)((uint8_t *)mi + 4);
  return meta[1];
}

extern "C" void __thiscall Object_UnloadGraphics_Inferred(void *mi /*ECX*/)
{
  int adj = vb_adj(mi);
  void *host = *(void **)((uint8_t *)mi + adj + 0xa8);
  void *manager = *(void **)((uint8_t *)host + 0xe914);

  FUN_004bfd10(manager, mi);

  *((uint8_t *)mi + 0x0f) = 0;

  void *root = (uint8_t *)mi + adj + 4;
  void **root_vtbl = *(void ***)root;
  using VFn0 = void(__thiscall *)(void *);
  using VFn1 = void(__thiscall *)(void *, int);
  using NotifyFn = void(__thiscall *)(void *, void *);

  ((VFn0)root_vtbl[0x144 / 4])(root);

  Object_SetMissionStateFx_Inferred(root, 3);

  void **notify = *(void ***)((uint8_t *)host + 0xe500);
  if (notify != nullptr) {
    ((NotifyFn)(*notify))(notify, root);
  }

  ((VFn0)root_vtbl[0xfc / 4])(root);

  void **self_vtbl = *(void ***)mi;
  ((VFn0)self_vtbl[0x04 / 4])(mi);
  ((VFn1)self_vtbl[0x18 / 4])(mi, 0);
  ((VFn1)self_vtbl[0x18 / 4])(mi, 1);
}
