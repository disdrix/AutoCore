// =============================================================================
// FUN_00421240  (scaffold twin of OleDb_EnsureColumnInfoAndEnterBindings_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00421240
// Address:   0x00421240–0x00421358
// System:    COM / OLE DB accessor setup
// Generated: 2026-07-29 W25-C dual A/B seal
// Canonical: OleDb_EnsureColumnInfoAndEnterBindings_Inferred.cpp
// Exactness: Decompiler-shaped CF; named clean is authoritative for semantics.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void* operator_new__(unsigned size);
extern "C" int FUN_00421362(void);
extern "C" const char DAT_00a860ac[];
extern "C" const char DAT_00a85ffc[];

// Ghidra-shaped surface (SEH locals omitted). Success path is machine jmp into
// FUN_00421362 (shared frame); decompiler may render that join as a call.
int __thiscall FUN_00421240(uint32_t* param_1, int param_2)
{
  int iVar1;
  int* local_24;
  void* local_20;
  int* local_1c;

  local_1c = nullptr;

  // QI IID_IAccessor (DAT_00a860ac)
  iVar1 = (*(int(__stdcall**)(uint32_t*, const void*, int**))(*param_1))(
      param_1, &DAT_00a860ac, &local_1c);
  if (iVar1 < 0) {
    if (local_1c != nullptr) {
      (*(void(__stdcall**)(int*))(*(uint32_t*)local_1c + 8))(local_1c);
    }
    return iVar1;
  }

  if (*(int*)(param_2 + 0x14) != 0) {
    *(uint8_t*)(param_2 + 0x1c) = 1;
    goto LAB_0042132c;
  }

  local_24 = nullptr;
  // QI IID_IColumnsInfo (DAT_00a85ffc)
  iVar1 = (*(int(__stdcall**)(uint32_t*, const void*, int**))(*param_1))(
      param_1, &DAT_00a85ffc, &local_24);
  if (iVar1 >= 0) {
    // GetColumnInfo @ vtbl+0x0C
    iVar1 = (*(int(__stdcall**)(int*, int, int, int))(*(uint32_t*)local_24 + 0x0C))(
        local_24, param_2 + 0x0C, param_2 + 0x14, param_2 + 0x18);
    if (iVar1 >= 0) {
      *(uint8_t*)(param_2 + 0x1c) = 0;
      if (local_24 != nullptr) {
        (*(void(__stdcall**)(int*))(*(uint32_t*)local_24 + 8))(local_24);
      }
      goto LAB_0042132c;
    }
  }

  if (local_24 != nullptr) {
    (*(void(__stdcall**)(int*))(*(uint32_t*)local_24 + 8))(local_24);
  }
  if (local_1c == nullptr) {
    return iVar1;
  }
  (*(void(__stdcall**)(int*))(*(uint32_t*)local_1c + 8))(local_1c);
  return iVar1;

LAB_0042132c:
  // SEH try level = 2 on machine path
  local_20 = operator_new__(*(int*)(param_2 + 0x0C) * 0x34);
  (void)local_20;  // [ebp-0x1C] temp DBBINDING[colCount]
  // machine: jmp 0x00421362 (not call+ret)
  iVar1 = FUN_00421362();
  return iVar1;
}
