// =============================================================================
// FUN_00572730  (scaffold — prefer InventoryGrid_SortAndRepack_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00572730
// Address:   0x00572730  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 from raw capture; 2026-07-29 W20-S plate refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual: accept-with-gaps — A/B_aa_00572730_InventoryGrid_SortAndRepack_Inferred
// =============================================================================

// PURPOSE: InventoryGrid sort/repack under comparator callback.
// ABI: __thiscall ECX=grid, stack compareFn+ctx, RET 8; returns 1/0.
// Adjusted-null: this == (void*)0xFFFFFFD4 → 0.
// Callers: FUN_00572ed0 (FUN_00572f30), FUN_00572ef0 (LAB_00572fe0).

// READABILITY (auto CF):
//  - Body size: ~158 non-empty decompiler lines.
//  - Control keywords: if×13, return×3, while×3, goto×2, do×1.
//  - Notable callees: FUN_004022a0×4, FUN_004bc950×4, InventoryGrid_*, FindFree, Place.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 * - W20-S: live decompile ≡ raw; ABI ret8 + adjusted-null sealed via read_memory.
 */

#include <cstdint>

using code = void;
using undefined = uint8_t;
using undefined1 = uint8_t;
using undefined4 = uint32_t;
using undefined1_ptr = uint8_t *;
// External symbols from decompiler (not defined here)
extern "C" {
  void *ExceptionList;
  void LAB_009a4f7f(void);
  void *operator_new(uint32_t);
  uint32_t *InventoryGrid_ctor_Inferred(void *, int, int, int);
  void *PTR_FUN_009cb334;
  void *PTR_FUN_009cb378;
  void InitializeCriticalSection(void *);
  void DeleteCriticalSection(void *);
  void LeaveCriticalSection(void *);
  void FUN_005731c0(undefined4);
  void FUN_004294f0(void);
  int FUN_004022a0(undefined4 *, int **);
  void FUN_00566f00(int *);
  char FUN_005713a0(void *, undefined4, uint32_t *, uint32_t *, int);
  undefined4 FUN_00571620(int *, uint32_t, uint32_t, undefined4);
  void FUN_005085b0(int *);
  void FUN_00573810(int **, int **);
  void FUN_00571e10(int, int);
  void FUN_004bc580(void);
  void FUN_004bc950(void);
  void InventoryGrid_AllocateCellArray_Inferred(void *);
  void FUN_00572360(void *, int);
  uint32_t CONCAT31(uint32_t, uint8_t);
  uint16_t CONCAT11(uint8_t, uint8_t);
}
struct _RTL_CRITICAL_SECTION { uint8_t _[24]; };

uint32_t __thiscall FUN_00572730(void *param_1, code *param_2, uint32_t param_3)
{
  bool bVar1;
  int *piVar2;
  void *pGrid;
  char cVar3;
  uint8_t uVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t *pGrid_00;
  int *piVar7;
  uint32_t local_70;
  int *local_6c[2];
  uint32_t *local_64;
  uint32_t uStack_60;
  uint32_t uStack_5c;
  void *local_58;
  uint32_t uStack_54;
  void *local_50;
  uint32_t uStack_48;
  int *piStack_44;
  int *piStack_40;
  uint32_t uStack_3c;
  void **local_38;
  _RTL_CRITICAL_SECTION local_34;
  uint32_t local_1c;
  uint32_t local_18;
  int local_14;
  char local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t *)&LAB_009a4f7f;
  local_c = ExceptionList;
  if (param_1 == (void *)0xffffffd4) {
    return 0;
  }
  ExceptionList = &local_c;
  local_58 = param_1;
  local_50 = operator_new(0x68);
  local_4 = 0;
  if (local_50 == (void *)0x0) {
    local_64 = (uint32_t *)0x0;
  }
  else {
    local_64 = InventoryGrid_ctor_Inferred(
        local_50, *(int *)((int)param_1 + 8), *(int *)((int)param_1 + 0xc),
        *(int *)((int)param_1 + 0x14));
  }
  pGrid_00 = local_64;
  local_38 = &PTR_FUN_009cb334;
  local_18 = 0;
  local_1c = 0;
  local_14 = 0;
  local_10 = '\0';
  InitializeCriticalSection(&local_34);
  local_38 = &PTR_FUN_009cb378;
  local_4 = 1;
  local_6c[0] = (int *)0x0;
  bVar1 = false;
  local_70 = 0;
  FUN_005731c0(*(uint32_t *)(*(int *)((int)param_1 + 0x60) + 4));
  *(int *)(*(int *)((int)param_1 + 0x60) + 4) = *(int *)((int)param_1 + 0x60);
  *(uint32_t *)((int)param_1 + 100) = 0;
  *(uint32_t *)*(uint32_t *)((int)param_1 + 0x60) = *(uint32_t *)((int)param_1 + 0x60);
  *(int *)(*(int *)((int)param_1 + 0x60) + 8) = *(int *)((int)param_1 + 0x60);
  FUN_004294f0();
  iVar5 = FUN_004022a0(&local_70, local_6c);
  while (iVar5 == 0) {
    FUN_00566f00(local_6c[0]);
    iVar5 = FUN_004022a0(&local_70, local_6c);
  }
  if (*(char *)((int)param_1 + 0x54) != '\0') {
    *(uint8_t *)((int)param_1 + 0x54) = 0;
    LeaveCriticalSection((void *)((int)param_1 + 0x30));
  }
  if (local_14 != 0) {
    do {
      if (bVar1) goto LAB_005729cd;
      local_70 = 0;
      local_6c[0] = (int *)0x0;
      piVar7 = (int *)0x0;
      FUN_004294f0();
      iVar5 = FUN_004022a0(&local_70, local_6c);
      piVar2 = local_6c[0];
      while (local_6c[0] = piVar2, iVar5 == 0) {
        if ((piVar7 == (int *)0x0) ||
            (cVar3 = ((char (*)(uint32_t, int *, int *))param_2)(param_3, piVar2, piVar7),
             cVar3 != '\0')) {
          piVar7 = piVar2;
        }
        iVar5 = FUN_004022a0(&local_70, local_6c);
        pGrid_00 = local_64;
        piVar2 = local_6c[0];
      }
      if (local_10 != '\0') {
        local_10 = '\0';
        LeaveCriticalSection(&local_34);
      }
      if (piVar7 != (int *)0x0) {
        uVar4 = (**(uint8_t(**)())(*piVar7 + 0x250))();
        uStack_48 = CONCAT31(uStack_48 >> 8, uVar4);
        uVar4 = (**(uint8_t(**)())(*piVar7 + 0x254))();
        uStack_48 = (uStack_48 & 0xffff0000) | CONCAT11(uVar4, (uint8_t)uStack_48);
        if (*(int *)(piVar7[0x2a] + 0x38) == 4) {
          uStack_5c = uStack_5c & 0xffffff00;
          uStack_60 = uStack_60 & 0xffffff00;
LAB_0057296e:
          uVar6 = (**(uint32_t(**)())(*piVar7 + 0x25c))();
          FUN_00571620(piVar7, uStack_5c, uStack_60, uVar6);
        }
        else {
          uStack_54 = CONCAT31(uStack_54 >> 8,
                               *(uint8_t *)(*(int *)(piVar7[0x2a] + 0x3c) + 0x407));
          local_50 = (void *)CONCAT31((uint32_t)local_50 >> 8,
                                      *(uint8_t *)(*(int *)(piVar7[0x2a] + 0x3c) + 0x406));
          cVar3 = FUN_005713a0(local_50, uStack_54, &uStack_5c, &uStack_60, 0xffffffff);
          if (cVar3 != '\0') goto LAB_0057296e;
          bVar1 = true;
        }
        FUN_005085b0(piVar7);
        uStack_3c = uStack_48;
        piStack_44 = piVar7;
        piStack_40 = piVar7;
        FUN_00573810(local_6c, &piStack_44);
      }
    } while (local_14 != 0);
    if (bVar1) {
LAB_005729cd:
      FUN_00571e10(0, 0);
      FUN_004bc580();
      InventoryGrid_AllocateCellArray_Inferred(pGrid_00);
      if (pGrid_00 != (uint32_t *)0x0) {
        (**(void(**)(int)) * pGrid_00)(1);
      }
      local_38 = &PTR_FUN_009cb378;
      FUN_004bc950();
      local_38 = &PTR_FUN_009cb334;
      FUN_004bc950();
      DeleteCriticalSection(&local_34);
      ExceptionList = local_c;
      return 0;
    }
  }
  pGrid = local_58;
  FUN_004bc580();
  InventoryGrid_AllocateCellArray_Inferred(pGrid);
  FUN_00572360(pGrid, 0);
  if (pGrid_00 != (uint32_t *)0x0) {
    (**(void(**)(int)) * pGrid_00)(1);
  }
  local_38 = &PTR_FUN_009cb378;
  FUN_004bc950();
  local_38 = &PTR_FUN_009cb334;
  FUN_004bc950();
  DeleteCriticalSection(&local_34);
  ExceptionList = local_c;
  return 1;
}
