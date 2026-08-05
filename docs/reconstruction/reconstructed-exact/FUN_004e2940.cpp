// =============================================================================
// FUN_004e2940  — twin of StdMap_FreeSubtree_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2940
// Address:   0x004e2940 – 0x004e2975  (autoassault.exe, image base 0x400000)
// Wave:      W29-L OWN dual 2026-07-29
// Exactness: Byte-corrected CF (left-walk restored; false-noreturn residual closed).
// Canonical: docs/reconstruction/reconstructed-exact/StdMap_FreeSubtree_Val12.cpp
// =============================================================================

#include <stdint.h>

extern void operator_delete(void *p);

void FUN_004e2940(void *param_1 /* node* */)
{
  void *node = param_1;

  if (*(uint8_t *)((char *)node + 0x19) != 0)
    return;

  for (;;) {
    FUN_004e2940(*(void **)((char *)node + 8));
    {
      void *left = *(void **)node;
      operator_delete(node);
      node = left;
    }
    if (*(uint8_t *)((char *)node + 0x19) != 0)
      break;
  }
}
