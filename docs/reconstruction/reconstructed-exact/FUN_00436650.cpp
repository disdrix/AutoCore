// =============================================================================
// FUN_00436650  (alias scaffold → CircularPtrBuf_Grow)
// -----------------------------------------------------------------------------
// Stable ID: aa_00436650
// Address:   0x00436650  (autoassault.exe, image base 0x400000)
// Canonical: CircularPtrBuf_Grow
// System:    container / circular pointer-buffer utility
// Generated: 2026-07-29 dual A/B W18-E (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving; fixes decompiler noreturn on operator_delete.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See CircularPtrBuf_Grow.cpp for named clean source.
// This alias keeps Ghidra FUN_* path stable for inventory/xrefs.

#include <cstddef>
#include <cstdint>

extern void *operator_new(unsigned size);
extern void operator_delete(void *p);
extern void *memmove(void *dst, const void *src, size_t n);
extern void FUN_00436860(void);

// Custom ABI: this in EBX (unaff_EBX in Ghidra plate); ret 4.
void FUN_00436650(unsigned param_1 /* grow_request */)
{
  // Register this is not expressible portably as a C param; plate form:
  int unaff_EBX; // CircularPtrBuf* this — set by caller

  unsigned uVar2 = *(unsigned *)(unaff_EBX + 8);
  if (0xcccccccu - uVar2 < param_1) {
    FUN_00436860();
  }
  unsigned uVar4 = uVar2 >> 1;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  if ((param_1 < uVar4) && (uVar2 <= 0xcccccccu - uVar4)) {
    param_1 = uVar4;
  }
  uVar4 = *(unsigned *)(unaff_EBX + 0xc);
  uint32_t *_Dst = (uint32_t *)operator_new((uVar2 + param_1) * 4);
  int iVar6 = (int)(uVar4 * 4);
  void *pvVar3 = (void *)(iVar6 + *(int *)(unaff_EBX + 4));
  size_t sVar1 =
      (size_t)(((*(int *)(unaff_EBX + 8) * 4 - (int)pvVar3) +
                *(int *)(unaff_EBX + 4)) >>
               2) *
      4;
  pvVar3 = memmove(_Dst + uVar4, pvVar3, sVar1);
  pvVar3 = (void *)((int)pvVar3 + (int)sVar1);
  uint32_t *puVar7;
  if (param_1 < uVar4) {
    memmove(pvVar3, *(void **)(unaff_EBX + 4),
            (size_t)(((int)(param_1 * 4) >> 2) * 4));
    pvVar3 = (void *)((int)(param_1 * 4) + *(int *)(unaff_EBX + 4));
    sVar1 = (size_t)(((iVar6 - (int)pvVar3) + *(int *)(unaff_EBX + 4)) >> 2) * 4;
    pvVar3 = memmove(_Dst, pvVar3, sVar1);
    puVar7 = (uint32_t *)((int)pvVar3 + (int)sVar1);
    uVar4 = param_1;
  } else {
    sVar1 = (size_t)((iVar6 >> 2) * 4);
    iVar6 = (int)(param_1 - uVar4);
    pvVar3 = memmove(pvVar3, *(void **)(unaff_EBX + 4), sVar1);
    uint32_t *puVar5 = (uint32_t *)((int)pvVar3 + (int)sVar1);
    puVar7 = _Dst;
    if (iVar6 != 0) {
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
    }
  }
  if (uVar4 != 0) {
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
  }

  // Bytes-sealed commit (decompiler plate truncated after delete):
  void *old = *(void **)(unaff_EBX + 4);
  if (old != 0) {
    operator_delete(old);
  }
  *(unsigned *)(unaff_EBX + 8) = *(unsigned *)(unaff_EBX + 8) + param_1;
  *(uint32_t **)(unaff_EBX + 4) = _Dst;
}
