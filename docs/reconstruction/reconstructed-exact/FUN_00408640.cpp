// =============================================================================
// FUN_00408640  (scaffold twin → StdVector_InsertN_Elem0x10_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408640
// Address:   0x00408640–0x0040887c exclusive  (572 B / 0x23C)
// Module:    autoassault.exe (image base 0x400000)
// Generated: 2026-08-04 WQ9H-H dual seal
// Canonical: StdVector_InsertN_Elem0x10_Inferred
// =============================================================================
// Prefer StdVector_InsertN_Elem0x10_Inferred.cpp for meaningful names.
// This file preserves the decompiler control-flow spine (raw-equivalent).

#include <stdint.h>

extern "C" uint32_t FUN_00418130(void);
extern "C" void *operator_new(uint32_t size);
extern "C" void operator_delete(void *p);
extern "C" uint32_t FUN_00409b60(uint32_t a, uint32_t b, uint32_t c);
extern "C" int FUN_00407000(void *value_local);
extern "C" uint32_t FUN_0040a670(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern "C" void FUN_0045f050(uint32_t a);
extern "C" void FUN_00465bc0(void);

// ECX = count, EDX = vector*, stack where + value*
void __fastcall FUN_00408640(uint32_t param_1, int param_2, int param_3, uint32_t *param_4)
{
  void *pvVar1;
  int iVar3;
  uint32_t uVar4;
  int iVar5;
  uint32_t local_40;
  uint32_t local_3c;
  uint32_t local_38;
  uint32_t local_34;
  uint32_t local_24;
  void *local_1c;
  int local_18;

  local_40 = *param_4;
  local_3c = param_4[1];
  local_38 = param_4[2];
  local_34 = param_4[3];
  iVar3 = *(int *)(param_2 + 4);
  if (iVar3 == 0) {
    local_24 = 0;
  } else {
    local_24 = (uint32_t)(*(int *)(param_2 + 0xc) - iVar3) >> 4;
  }
  if (param_1 != 0) {
    if (iVar3 == 0) {
      iVar5 = 0;
    } else {
      iVar5 = (*(int *)(param_2 + 8) - iVar3) >> 4;
    }
    if (0xfffffffU - (uint32_t)iVar5 < param_1) {
      local_24 = FUN_00418130();
      iVar3 = *(int *)(param_2 + 4);
    }
    if (iVar3 == 0) {
      iVar5 = 0;
    } else {
      iVar5 = (*(int *)(param_2 + 8) - iVar3) >> 4;
    }
    if (local_24 < (uint32_t)(iVar5 + (int)param_1)) {
      if (0xfffffffU - (local_24 >> 1) < local_24) {
        local_24 = 0;
      } else {
        local_24 = local_24 + (local_24 >> 1);
      }
      if (iVar3 == 0) {
        iVar5 = 0;
      } else {
        iVar5 = (*(int *)(param_2 + 8) - iVar3) >> 4;
      }
      if (local_24 < (uint32_t)(iVar5 + (int)param_1)) {
        if (iVar3 == 0) {
          iVar3 = 0;
        } else {
          iVar3 = (*(int *)(param_2 + 8) - iVar3) >> 4;
        }
        local_24 = (uint32_t)(iVar3 + (int)param_1);
      }
      local_24 = local_24 << 4;
      local_1c = operator_new(local_24);
      FUN_00409b60(*(uint32_t *)(param_2 + 4), (uint32_t)param_3, 0);
      FUN_00407000(&local_40);
      FUN_00409b60((uint32_t)param_3, *(uint32_t *)(param_2 + 8), 0);
      pvVar1 = *(void **)(param_2 + 4);
      if (pvVar1 == 0) {
        iVar3 = 0;
      } else {
        iVar3 = (*(int *)(param_2 + 8) - (int)pvVar1) >> 4;
      }
      if (pvVar1 != 0) {
        operator_delete(pvVar1);
      }
      *(uint32_t *)(param_2 + 0xc) = local_24 + (uint32_t)local_1c;
      *(void **)(param_2 + 8) = (void *)((param_1 + (uint32_t)iVar3) * 0x10 + (uint32_t)local_1c);
      *(void **)(param_2 + 4) = local_1c;
      return;
    }
    iVar3 = *(int *)(param_2 + 8);
    if ((uint32_t)(iVar3 - param_3) >> 4 < param_1) {
      local_18 = (int)(param_1 * 0x10);
      FUN_0040a670((uint32_t)param_3, (uint32_t)(local_18 + param_3), (uint32_t)param_2, 0);
      FUN_00407000(&local_40);
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + local_18;
    } else {
      local_18 = (int)(param_1 * 0x10);
      uVar4 = FUN_0040a670((uint32_t)(iVar3 + (int)param_1 * -0x10), (uint32_t)iVar3,
                           (uint32_t)param_2, 0);
      *(uint32_t *)(param_2 + 8) = uVar4;
      FUN_0045f050(0);
    }
    FUN_00465bc0();
  }
  return;
}
