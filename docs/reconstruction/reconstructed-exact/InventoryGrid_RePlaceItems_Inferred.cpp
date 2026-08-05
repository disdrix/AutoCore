// =============================================================================
// InventoryGrid_RePlaceItems_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00572360
// Address:   0x00572360  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_00572360
// Generated: 2026-07-29 W21-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + ABI seals.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Re-place / commit inventory items for an InventoryGrid:
//     1) Reject relatedPtr == null → return 0.
//     2) Walk item enumeration (helpers on this+0x2c).
//     3) Per item: origin via vtbl +0x250/+0x254; type!=4 → CanPlace at origin
//        with InvSize (+0x406/+0x407); on miss FindFree page -1; PlaceFootprint.
//     4) Fail → FUN_00571e10, leave CS if held, return 0.
//     5) Success → leave CS; if flag FUN_00571e10; free/reinit item RB +0x60;
//        if !flag FUN_004bc580 + AllocateCellArray; return 1.
//
// ABI: __thiscall, stack relatedPtr + char flag, RET 8. Returns 1/0 in AL.
//
// Callers: FUN_00572730 (SortAndRepack commit), FUN_005252f0 (×3 cargo path),
//          FUN_00521e90 (wrapper flag=1).
//
// Supersedes seed alias Named_CalleeOf_*_ShowInventoryFullAcceptMes_00572360.
// Residuals: product name; relatedPtr exact type; why success empties RB after
// Place (CF sealed); some thiscall ECX targets decompiler-weak.

#include <cstdint>

struct InventoryGrid; // incomplete — layout partial in OBJECT_LAYOUTS

extern "C" {
  void FUN_004294f0(void); // list/walk begin (thiscall ECX residual → this+0x2c)
  int  FUN_004022a0(void *iterState, int **outItem);
  char InventoryGrid_CanPlace(void *grid, uint32_t sizeX, uint32_t sizeY,
                              uint32_t originX, uint32_t originY, int pageIndex);
  char InventoryGrid_FindFreeSlot(void *grid, uint32_t sizeX, uint32_t sizeY,
                                  uint32_t *outX, uint32_t *outY, int pageIndex);
  char InventoryGrid_PlaceItemFootprint(void *grid, int *item,
                                        uint32_t x, uint32_t y, uint32_t packArg);
  void FUN_00573810(void *treeIt, void *nodePair);
  void FUN_00571e10(void *relatedOrGrid, int flagA /*, char flagB residual */);
  void FUN_005731c0(void *rbNode);
  void FUN_004bc580(void);
  void InventoryGrid_AllocateCellArray_Inferred(void *grid);
  void LeaveCriticalSection(void *cs);
}

// Decompiler-faithful named plate. Prefer FUN_00572360.cpp for raw symbol mirror.

uint32_t __thiscall InventoryGrid_RePlaceItems_Inferred(
    void *thisGrid,
    void *relatedPtr,
    char flag)
{
  if (relatedPtr == nullptr) {
    return 0;
  }

  uint32_t iterState = 0;
  int *item = nullptr;
  int exhausted = 0;

  // ECX = thisGrid + 0x2c for walk helpers (byte-sealed lea ebp,[ecx+0x2c])
  FUN_004294f0();
  exhausted = FUN_004022a0(&iterState, &item);

  for (;;) {
    if (exhausted != 0) {
      // Success exit
      if (*(char *)((int)thisGrid + 0x54) != '\0') {
        *(uint8_t *)((int)thisGrid + 0x54) = 0;
        LeaveCriticalSection((void *)((int)thisGrid + 0x30));
      }

      char savedFlag = flag;
      if (flag != '\0') {
        FUN_00571e10(relatedPtr, 1);
      }

      // Free left subtree of item RB at +0x60; reinit empty; count +0x64 = 0
      void *rbHead = *(void **)((int)thisGrid + 0x60);
      FUN_005731c0(*(void **)((int)rbHead + 4));
      *(void **)((int)rbHead + 4) = rbHead;
      *(uint32_t *)((int)thisGrid + 0x64) = 0;
      *(void **)rbHead = rbHead;
      *(void **)((int)rbHead + 8) = rbHead;

      if (savedFlag == '\0') {
        FUN_004bc580();
        InventoryGrid_AllocateCellArray_Inferred(thisGrid);
      }
      return 1;
    }

    if (item != nullptr) {
      // origin X/Y via item vfuncs +0x250 / +0x254
      using VFn = uint8_t(__thiscall *)(int *self);
      using VFnA = uint32_t(__thiscall *)(int *self, uint32_t a);
      int *vtbl = (int *)*item;

      uint8_t originX = ((VFn)vtbl[0x250 / 4])(item);
      uint8_t originY = ((VFn)vtbl[0x254 / 4])(item);
      uint32_t originXw = originX;
      uint32_t originYw = originY;

      int *typeBlk = (int *)item[0x2a];
      if (typeBlk[0x38 / 4] != 4) {
        int *clone = (int *)typeBlk[0x3c / 4];
        uint32_t sizeY = *(uint8_t *)((int)clone + 0x407);
        uint32_t sizeX = *(uint8_t *)((int)clone + 0x406);

        // CanPlace at saved origin (page 0 in decomp residual for last arg)
        char ok = InventoryGrid_CanPlace(
            thisGrid, sizeX, sizeY, originXw, originYw, 0);
        if (ok == '\0') {
          if (typeBlk[0x38 / 4] == 4) {
            originXw = 0;
            originYw = 0;
          } else {
            sizeY = *(uint8_t *)((int)clone + 0x407);
            sizeX = *(uint8_t *)((int)clone + 0x406);
            ok = InventoryGrid_FindFreeSlot(
                thisGrid, sizeX, sizeY, &originXw, &originYw, (int)0xffffffff);
            if (ok == '\0') {
              goto fail;
            }
          }
        }
      }

      uint32_t packArg = ((VFn)vtbl[0x25c / 4])(item);
      char placed = InventoryGrid_PlaceItemFootprint(
          thisGrid, item, originXw, originYw, packArg);
      if (placed == '\0') {
        goto fail;
      }

      uint8_t treeScratch[8];
      int *nodePair[2];
      FUN_00573810(treeScratch, nodePair);
    }

    exhausted = FUN_004022a0(&iterState, &item);
  }

fail:
  FUN_00571e10(relatedPtr, 1);
  if (*(char *)((int)thisGrid + 0x54) != '\0') {
    *(uint8_t *)((int)thisGrid + 0x54) = 0;
    LeaveCriticalSection((void *)((int)thisGrid + 0x30));
  }
  return 0;
}
