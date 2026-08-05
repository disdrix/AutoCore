// =============================================================================
// Named_VOG_DEBUG_STOP_0051e3d0
// -----------------------------------------------------------------------------
// Legacy auto-seed alias for aa_0051e3d0 (from lock-warn string only).
// Canonical: CNDHash_Insert_009ce0a0 (FUN_0051e3d0 @ 0x0051e3d0).
// VOG_DEBUG_STOP is a diagnostic log path — NOT the product API name.
// W21-D: retained as alias only.
// =============================================================================

#include <stdint.h>

extern void * __thiscall CNDHash_LookupByKey(void *self, uint32_t key);
extern void * __thiscall FUN_0053ada0(void);
extern void FUN_00537d30(void);
extern void FUN_007a4480(int severity, const char *fmt, ...);
extern uint32_t PTR_FUN_009ce0a0;

uint32_t __thiscall Named_VOG_DEBUG_STOP_0051e3d0(
    void *self, uint32_t key, void *value, char softIfExists)
{
  int iVar1;
  void *pvVar2;
  uint32_t *puVar3;

  if (value == 0) {
    return 0x80004003;
  }
  if (*(char *)((int)self + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:insert, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (softIfExists != 0) {
    pvVar2 = CNDHash_LookupByKey(self, key);
    if (pvVar2 != 0) {
      return 1;
    }
  }
  pvVar2 = CNDHash_LookupByKey(self, key);
  if (pvVar2 != 0) {
    FUN_007a4480(0, "Duplicate hash insert %u, failing out", key);
    return 0x80004005;
  }
  puVar3 = (uint32_t *)FUN_0053ada0();
  puVar3[3] = 0;
  *puVar3 = (uint32_t)&PTR_FUN_009ce0a0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  *(uint8_t *)(puVar3 + 1) = 0;
  puVar3[2] = (uint32_t)value;
  puVar3[4] = key;
  iVar1 = *(int *)(*(int *)((int)self + 0x10)
                   + (*(uint32_t *)((int)self + 8) & key) * 4);
  puVar3[3] = *(uint32_t *)(iVar1 + 4);
  *(uint32_t **)(iVar1 + 4) = puVar3;
  FUN_00537d30();
  if (*(int *)((int)self + 0x18) != 0) {
    *(uint32_t **)(*(int *)((int)self + 0x18) + 0x14) = puVar3;
    puVar3[5] = 0;
    puVar3[6] = *(uint32_t *)((int)self + 0x18);
    *(int *)((int)self + 0xc) = *(int *)((int)self + 0xc) + 1;
    *(uint32_t **)((int)self + 0x18) = puVar3;
    return 0;
  }
  *(uint32_t **)((int)self + 0x18) = puVar3;
  *(uint32_t **)((int)self + 0x14) = puVar3;
  puVar3[6] = 0;
  puVar3[5] = 0;
  *(int *)((int)self + 0xc) = *(int *)((int)self + 0xc) + 1;
  return 0;
}
