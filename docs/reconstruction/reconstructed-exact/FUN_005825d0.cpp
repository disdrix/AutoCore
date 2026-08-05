// =============================================================================
// FUN_005825d0  (scaffold twin of Object_UnloadGraphics_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005825d0
// Address:   0x005825d0–0x00582664 (148 B / 0x94)
// Dual:      2026-07-29 W31-T OWN-ONLY
// Prefer:    Object_UnloadGraphics_Inferred.cpp
// =============================================================================
//
// Bytes seal first callee this as manager @ *(host+0xE914), not param_1.
// Decompiler surface FUN_004bfd10(param_1) is residual — machine wins.

#include <stdint.h>

extern "C" uint32_t __thiscall FUN_004bfd10(void *manager, void *tracked);
extern "C" void __thiscall FUN_00518370(void *object, int newState);

extern "C" void __thiscall FUN_005825d0(void *param_1 /*ECX MI this*/)
{
  int *meta = *(int **)((uint8_t *)param_1 + 4);
  int adj = meta[1];
  void *host = *(void **)((uint8_t *)param_1 + adj + 0xa8);
  void *manager = *(void **)((uint8_t *)host + 0xe914);

  FUN_004bfd10(manager, param_1);

  *((uint8_t *)param_1 + 0x0f) = 0;

  void *root = (uint8_t *)param_1 + adj + 4;
  void **root_vtbl = *(void ***)root;
  using VFn0 = void(__thiscall *)(void *);
  using VFn1 = void(__thiscall *)(void *, int);
  using NotifyFn = void(__thiscall *)(void *, void *);

  ((VFn0)root_vtbl[0x144 / 4])(root);
  FUN_00518370(root, 3);

  void **notify = *(void ***)((uint8_t *)host + 0xe500);
  if (notify != nullptr) {
    ((NotifyFn)(*notify))(notify, root);
  }

  ((VFn0)root_vtbl[0xfc / 4])(root);

  void **self_vtbl = *(void ***)param_1;
  ((VFn0)self_vtbl[0x04 / 4])(param_1);
  ((VFn1)self_vtbl[0x18 / 4])(param_1, 0);
  ((VFn1)self_vtbl[0x18 / 4])(param_1, 1);
}
