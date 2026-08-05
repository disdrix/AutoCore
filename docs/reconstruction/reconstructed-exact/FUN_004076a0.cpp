// =============================================================================
// FUN_004076a0  (canonical: LogicUiEventQueue_InsertN)
// -----------------------------------------------------------------------------
// Stable ID: aa_004076a0
// Address:   0x004076a0 – 0x00407991  (autoassault.exe, image base 0x400000)
// System:    client-logic-ui / event queue
// Generated: 2026-07-29 W23-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named plate: reconstructed-exact/LogicUiEventQueue_InsertN.cpp
// =============================================================================

// PURPOSE: MSVC-style vector insert-N for 0x138 Logic-UI event elements.
// Callers: LogicUiEventQueue_InsertOne_GrowPath (count=1); FUN_00406840 (append grow).
// Nested: construct FUN_00408880; throw FUN_00418130; move/fill/patch helpers.

#include <cstdint>

// SEH / CRT symbols (image)
extern void *ExceptionList;
extern std::uint8_t LAB_009be300;
// Max element count for stride 0x138 (Ghidra DAT_00d20d20 address used as integer)
extern std::uint8_t DAT_00d20d20;

void __thiscall FUN_00408880(void *dest /*ECX*/, std::uint32_t src);
void FUN_00418130(void);
int FUN_004059c0(void);
void *operator_new(std::uint32_t size);
void operator_delete(void *p);
std::uint32_t __thiscall FUN_00409a70(void *self, void *first, void *last, void *dest);
std::uint32_t __thiscall FUN_00406970(void *self, void *dest, std::uint32_t count, void *value);
void FUN_00409a90(void *first, void *last, void *value);
void FUN_00409ac0(void *first, void *mid, void *last);

void __thiscall FUN_004076a0(int param_1, int param_2, std::uint32_t param_3, std::uint32_t param_4)
{
  void *pvVar1;
  int iVar2;
  std::uint32_t uVar3;
  std::uint32_t extraout_ECX;
  std::uint8_t local_164[312];
  std::uint32_t local_2c;
  int local_28;
  int local_24;
  std::uint32_t local_20;
  void *local_1c;
  int local_18;
  std::uint8_t *local_14;
  void *local_10;
  std::uint8_t *puStack_c;
  std::uint32_t local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_009be300;
  local_10 = ExceptionList;
  local_14 = (std::uint8_t *)&local_10; // stack cookie placeholder; raw uses &stack0xfffffe90
  ExceptionList = &local_10;
  FUN_00408880(local_164, param_4);
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 0) {
    local_20 = 0;
  } else {
    local_20 = (std::uint32_t)((*(int *)(param_1 + 0xc) - iVar2) / 0x138);
  }
  if (param_3 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    } else {
      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x138;
    }
    if ((std::uint32_t)((int)&DAT_00d20d20 - iVar2) < param_3) {
      FUN_00418130();
      local_20 = extraout_ECX;
    }
    if (*(int *)(param_1 + 4) == 0) {
      iVar2 = 0;
    } else {
      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x138;
    }
    if (local_20 < (std::uint32_t)(iVar2 + (int)param_3)) {
      if ((int)&DAT_00d20d20 - (int)(local_20 >> 1) < (int)local_20) {
        local_20 = 0;
      } else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar2 = 0;
      } else {
        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x138;
      }
      if (local_20 < (std::uint32_t)(iVar2 + (int)param_3)) {
        iVar2 = FUN_004059c0();
        local_20 = (std::uint32_t)(iVar2 + (int)param_3);
      }
      local_20 = local_20 * 0x138;
      local_1c = operator_new(local_20);
      local_8 = 0;
      local_2c = FUN_00409a70((void *)param_1, *(void **)(param_1 + 4), (void *)param_2, local_1c);
      local_2c = FUN_00406970((void *)param_1, (void *)local_2c, param_3, local_164);
      FUN_00409a70((void *)param_1, (void *)param_2, *(void **)(param_1 + 8), (void *)local_2c);
      local_8 = 0xffffffff;
      pvVar1 = *(void **)(param_1 + 4);
      if (pvVar1 == (void *)0) {
        iVar2 = 0;
      } else {
        iVar2 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x138;
      }
      if (pvVar1 != (void *)0) {
        operator_delete(pvVar1);
      }
      *(std::uint32_t *)(param_1 + 0xc) = local_20 + (std::uint32_t)(int)local_1c;
      *(void **)(param_1 + 8) = (void *)((int)local_1c + (int)(param_3 + (std::uint32_t)iVar2) * 0x138);
      *(void **)(param_1 + 4) = local_1c;
      ExceptionList = local_10;
      return;
    }
    local_28 = *(int *)(param_1 + 8);
    local_24 = local_28 - param_2;
    if ((std::uint32_t)(local_24 / 0x138) < param_3) {
      local_18 = (int)(param_3 * 0x138);
      FUN_00409a70((void *)param_1, (void *)param_2, (void *)local_28, (void *)(local_18 + param_2));
      local_8 = 2;
      FUN_00406970((void *)param_1, *(void **)(param_1 + 8),
                   param_3 - (std::uint32_t)((*(int *)(param_1 + 8) - param_2) / 0x138), local_164);
      local_8 = 0xffffffff;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;
      FUN_00409a90((void *)param_2, (void *)(*(int *)(param_1 + 8) - local_18), local_164);
      ExceptionList = local_10;
      return;
    }
    local_18 = (int)(param_3 * 0x138);
    iVar2 = local_28 + (int)param_3 * -0x138;
    uVar3 = FUN_00409a70((void *)param_1, (void *)iVar2, (void *)local_28, (void *)local_28);
    *(std::uint32_t *)(param_1 + 8) = uVar3;
    FUN_00409ac0((void *)param_2, (void *)iVar2, (void *)local_28);
    FUN_00409a90((void *)param_2, (void *)(local_18 + param_2), local_164);
  }
  ExceptionList = local_10;
  return;
}
