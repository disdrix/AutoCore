// =============================================================================
// FUN_00572360  (scaffold / Ghidra symbol mirror)
// -----------------------------------------------------------------------------
// Stable ID: aa_00572360
// Address:   0x00572360  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 W21-B dual seal
// Named plate: reconstructed-exact/InventoryGrid_RePlaceItems_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow + ABI seals.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Inventory grid re-place / commit pass. Null related → 0; walk items;
//   CanPlace/FindFree/Place; success clears RB (+ optional AllocCell); fail → 0.
//   ABI: __thiscall ECX=grid, stack related + flag, RET 8, returns 0|1.

#include <cstdint>

extern "C" {
  void FUN_004294f0(void);
  int  FUN_004022a0(void *iterState, int **outItem);
  char FUN_00570840(uint32_t sizeX, uint32_t sizeY, uint32_t ox, uint32_t oy, uint32_t page);
  char FUN_005713a0(uint32_t sizeX, uint32_t sizeY, uint32_t *outX, uint32_t *outY, int page);
  char FUN_00571620(int *item, uint32_t x, uint32_t y, uint32_t packArg);
  void FUN_00573810(void *a, void *b);
  void FUN_00571e10(void *related, int flagA);
  void FUN_005731c0(void *rbNode);
  void FUN_004bc580(void);
  void InventoryGrid_AllocateCellArray_Inferred(void *grid);
  void LeaveCriticalSection(void *cs);
}

uint32_t __thiscall FUN_00572360(void *param_1, uint32_t param_2, char param_3)
{
  int *piVar1;
  uint32_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  char cVar5;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uStack_38;
  int *local_34;
  uint32_t local_30;
  uint32_t uStack_2c;
  uint32_t uStack_28;
  uint32_t uStack_24;
  uint32_t uStack_20;
  uint32_t uStack_18;
  uint8_t auStack_14[8];
  int *apiStack_c[2];
  uint32_t uStack_4;

  uVar2 = param_2;
  if (param_2 == 0) {
    return 0;
  }
  local_30 = 0;
  FUN_004294f0();
  iVar6 = FUN_004022a0(&local_30, &local_34);
  piVar1 = local_34;
  do {
    if (iVar6 != 0) {
      if (*(char *)((int)param_1 + 0x54) != '\0') {
        *(uint8_t *)((int)param_1 + 0x54) = 0;
        LeaveCriticalSection((void *)((int)param_1 + 0x30));
      }
      cVar5 = param_3;
      if (param_3 != '\0') {
        FUN_00571e10((void *)uVar2, 1);
      }
      FUN_005731c0(*(void **)(*(int *)((int)param_1 + 0x60) + 4));
      *(int *)(*(int *)((int)param_1 + 0x60) + 4) = *(int *)((int)param_1 + 0x60);
      *(uint32_t *)((int)param_1 + 0x64) = 0;
      **(uint32_t **)((int)param_1 + 0x60) = *(uint32_t *)((int)param_1 + 0x60);
      *(int *)(*(int *)((int)param_1 + 0x60) + 8) = *(int *)((int)param_1 + 0x60);
      if (cVar5 == '\0') {
        FUN_004bc580();
        InventoryGrid_AllocateCellArray_Inferred(param_1);
      }
      return 1;
    }
    local_34 = piVar1;
    if (piVar1 != nullptr) {
      uVar3 = (**(uint8_t(**)())(*piVar1 + 0x250))();
      uStack_38 = (uStack_38 & 0xffffff00) | uVar3;
      uVar4 = (**(uint8_t(**)())(*piVar1 + 0x254))();
      param_2 = (param_2 & 0xffffff00) | uVar4;
      uStack_18 = (uStack_18 & 0xffff0000) | (uint32_t)uVar4 << 8 | uVar3;
      if (*(int *)(piVar1[0x2a] + 0x38) != 4) {
        iVar6 = *(int *)(piVar1[0x2a] + 0x3c);
        uStack_2c = (uStack_2c & 0xffffff00) | *(uint8_t *)(iVar6 + 0x407);
        uVar9 = 0;
        uStack_28 = (uStack_28 & 0xffffff00) | *(uint8_t *)(iVar6 + 0x406);
        uVar7 = (**(uint32_t(**)(int))(*piVar1 + 0x254))(0);
        uVar8 = (**(uint32_t(**)(uint32_t))(*piVar1 + 0x250))(uVar7);
        cVar5 = FUN_00570840(uStack_28, uStack_2c, uVar8, uVar7, uVar9);
        if (cVar5 == '\0') {
          if (*(int *)(piVar1[0x2a] + 0x38) == 4) {
            uStack_38 = uStack_38 & 0xffffff00;
            param_2 = param_2 & 0xffffff00;
          } else {
            uStack_24 = (uStack_24 & 0xffffff00) |
                        *(uint8_t *)(*(int *)(piVar1[0x2a] + 0x3c) + 0x407);
            uStack_20 = (uStack_20 & 0xffffff00) |
                        *(uint8_t *)(*(int *)(piVar1[0x2a] + 0x3c) + 0x406);
            cVar5 = FUN_005713a0(uStack_20, uStack_24, &uStack_38, &param_2, (int)0xffffffff);
            if (cVar5 == '\0') {
              goto LAB_0057251f;
            }
          }
        }
      }
      uVar7 = (**(uint32_t(**)())(*piVar1 + 0x25c))();
      cVar5 = FUN_00571620(piVar1, uStack_38, param_2, uVar7);
      if (cVar5 == '\0') {
      LAB_0057251f:
        FUN_00571e10((void *)uVar2, 1);
        if (*(char *)((int)param_1 + 0x54) != '\0') {
          *(uint8_t *)((int)param_1 + 0x54) = 0;
          LeaveCriticalSection((void *)((int)param_1 + 0x30));
        }
        return 0;
      }
      uStack_4 = uStack_18;
      FUN_00573810(auStack_14, apiStack_c);
    }
    iVar6 = FUN_004022a0(&local_30, &local_34);
    piVar1 = local_34;
  } while (true);
}
