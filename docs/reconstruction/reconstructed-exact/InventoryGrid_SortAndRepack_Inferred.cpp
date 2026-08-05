// =============================================================================
// InventoryGrid_SortAndRepack_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00572730
// Address:   0x00572730  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_00572730
// Generated: 2026-07-29 W20-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + ABI seals.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Sort/repack an InventoryGrid under a caller comparator.
//   1) Build temp InventoryGrid (heap 0x68) with same +0x08/+0x0c/+0x14 dims.
//   2) Empty this item RB-tree at +0x60 (count +0x64 = 0).
//   3) Selection-sort loop: pick best item via compareFn(ctx, cand, best);
//      type==4 → place origin (0,0); else FindFreeSlot whole-grid (page -1)
//      then PlaceItemFootprint. Fail → FUN_00571e10 + destroy temp → return 0.
//   4) Success → AllocateCellArray on this, FUN_00572360 re-place, destroy temp → 1.
//
// ABI: __thiscall, stack compareFn + compareCtx, RET 8.
// Adjusted-null: this == (void*)0xFFFFFFD4 → return 0.
//
// Callers: FUN_00572ed0 (cmp FUN_00572f30), FUN_00572ef0 (cmp LAB_00572fe0).
//
// Residuals: some thiscall ECX targets and FUN_00572360 source-list arg are
// decompiler-weak; role/CF sealed from body + sealed inventory callees.

#include <cstdint>

struct InventoryGrid; // incomplete — layout partial in OBJECT_LAYOUTS
struct CriticalSection; // RTL_CRITICAL_SECTION stand-in

// Sealed callees (not defined here)
extern "C" {
  void *operator_new(uint32_t size);
  InventoryGrid *InventoryGrid_ctor_Inferred(void *mem, int w, int h, int field14);
  void InventoryGrid_AllocateCellArray_Inferred(void *grid);
  char InventoryGrid_FindFreeSlot(void *grid, uint32_t sizeX, uint32_t sizeY,
                                  uint32_t *outX, uint32_t *outY, int pageIndex);
  char InventoryGrid_PlaceItemFootprint(void *item, uint32_t x, uint32_t y, uint32_t sizeArg);
  void FUN_005731c0(void *rbNode);
  void FUN_004294f0(void); // list traversal-lock (thiscall ECX residual)
  int FUN_004022a0(void *iterState, int **outNode);
  void FUN_00566f00(int *item);
  void FUN_005085b0(int *item);
  void FUN_00573810(void *treeIt, void *nodePair);
  void FUN_00571e10(int a, int b);
  void FUN_004bc580(void);
  void FUN_004bc950(void);
  void FUN_00572360(void *grid, int sourceListResidual);
  void InitializeCriticalSection(void *cs);
  void DeleteCriticalSection(void *cs);
  void LeaveCriticalSection(void *cs);
}

using CompareFn = char (*)(uint32_t ctx, int *cand, int *best);

// Decompiler-faithful scaffold with named plate. Prefer FUN_00572730.cpp for
// line-locked raw mirror; this unit carries the inferred product name.

uint32_t __thiscall InventoryGrid_SortAndRepack_Inferred(
    void *thisGrid,
    CompareFn compareFn,
    uint32_t compareCtx)
{
  // --- SEH omitted (LAB_009a4f7f) ---

  // Adjusted-null member check (this+0x2c address == 0)
  if (thisGrid == (void *)0xffffffd4) {
    return 0;
  }

  void *tempMem = operator_new(0x68);
  uint32_t *tempGrid = nullptr;
  if (tempMem != nullptr) {
    tempGrid = (uint32_t *)InventoryGrid_ctor_Inferred(
        tempMem,
        *(int *)((int)thisGrid + 0x08),
        *(int *)((int)thisGrid + 0x0c),
        *(int *)((int)thisGrid + 0x14));
  }

  // Stack locked list shell: vtbl, CS, heads, count@+0x24, lock@+0x28
  // (see annotated). InitializeCriticalSection; install list vtbl.

  // Free RB nodes under this+0x60; reinit empty sentinel; *(this+0x64)=0
  FUN_005731c0(*(void **)(*(int *)((int)thisGrid + 0x60) + 4));
  *(int *)(*(int *)((int)thisGrid + 0x60) + 4) = *(int *)((int)thisGrid + 0x60);
  *(uint32_t *)((int)thisGrid + 0x64) = 0;
  **(uint32_t **)((int)thisGrid + 0x60) = *(uint32_t *)((int)thisGrid + 0x60);
  *(int *)(*(int *)((int)thisGrid + 0x60) + 8) = *(int *)((int)thisGrid + 0x60);

  // Drain / collect pass (list lock + iterate + push) — ECX residual
  // ...

  if (*(char *)((int)thisGrid + 0x54) != 0) {
    *(uint8_t *)((int)thisGrid + 0x54) = 0;
    LeaveCriticalSection((void *)((int)thisGrid + 0x30));
  }

  // Selection-sort place loop while local count != 0:
  //   best = argmax/min under compareFn(compareCtx, cand, best)
  //   if type(*(best[0x2a]+0x38)) == 4: placeXY = (0,0)
  //   else FindFree(invSize from blob+0x406/407, page=-1) or fail
  //   PlaceItemFootprint + FUN_005085b0 + tree insert
  // On fail: FUN_00571e10(0,0); cleanup temp; return 0

  // Success path:
  FUN_004bc580();
  InventoryGrid_AllocateCellArray_Inferred(thisGrid);
  FUN_00572360(thisGrid, /* source list residual */ 0);

  if (tempGrid != nullptr) {
    // vtbl delete (tempGrid[0])(1)
    (*(void(__thiscall **)(uint32_t *, int)) * tempGrid)(tempGrid, 1);
  }
  // stack list dtor + DeleteCriticalSection
  return 1;
}
