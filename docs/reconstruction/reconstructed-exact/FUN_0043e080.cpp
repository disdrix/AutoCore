// =============================================================================
// FUN_0043e080 / GuardedVector_InsertN_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e080
// Address:   0x0043e080–0x0043e37d  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-deque container
// Dual:      W32-F 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Twin clean: GuardedVector_InsertN_Thiscall.cpp

#include <cstdint>

// External callees (Ghidra names).
extern "C" void FUN_0043d670(const uint32_t* value /*ECX container*/);
extern "C" void FUN_0043e3d0(const uint32_t* value /*ECX container*/);
extern "C" void FUN_0043e910(int c1, int i1, int c2, int i2, uint32_t* fill);
extern "C" void FUN_0043ec50(void* out, int a, int b, int c, int d, int e, int f, uint32_t g);
extern "C" void FUN_0043ebb0(void* out, int a, int b, int c, int d, int e, int f, uint32_t g);

// SEH / FS symbols from image (not modeled).
extern "C" void* ExceptionList;
extern "C" uint8_t LAB_009bd5f0;

// Retail: ECX=container; stack seed/insert_at/N/fill*; RET 0x10
void __thiscall FUN_0043e080(int param_1, int param_2, uint32_t param_3,
                             uint32_t param_4, uint32_t* param_5)
{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  int local_24;
  int local_20;
  int local_1c;
  uint32_t local_18;
  uint8_t* local_14;
  void* local_10;
  uint8_t* puStack_c;
  uint32_t local_8;

  uVar3 = param_4;
  puStack_c = &LAB_009bd5f0;
  local_10 = ExceptionList;
  local_14 = reinterpret_cast<uint8_t*>(&local_14); // stack cookie placeholder
  local_24 = param_2;
  uVar4 = param_3 - *reinterpret_cast<int*>(param_1 + 0xc);
  local_20 = *reinterpret_cast<int*>(param_1 + 0x10);
  local_18 = static_cast<uint32_t>(local_20) - uVar4;
  param_3 = uVar4;
  local_1c = param_1;
  if (uVar4 < local_18) {
    local_8 = 0;
    ExceptionList = &local_10;
    if (uVar4 < param_4) {
      ExceptionList = &local_10;
      for (param_4 = param_4 - uVar4; uVar1 = uVar4, param_4 != 0; param_4 = param_4 - 1) {
        FUN_0043e3d0(param_5);
      }
      while (param_4 = uVar1, param_4 != 0) {
        uVar4 = *reinterpret_cast<int*>(param_1 + 0xc) + -1 + uVar3;
        uVar1 = uVar4 >> 2;
        iVar2 = static_cast<int>(uVar1) * -4;
        if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar1) {
          uVar1 = uVar1 - *reinterpret_cast<uint32_t*>(param_1 + 8);
        }
        FUN_0043e3d0(reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + uVar1 * 4) +
            (uVar4 + iVar2) * 4));
        uVar4 = param_3;
        uVar1 = param_4 - 1;
      }
      iVar2 = *reinterpret_cast<int*>(param_1 + 0xc) + static_cast<int>(uVar3);
      FUN_0043e910(param_1, iVar2, param_1, iVar2 + static_cast<int>(uVar4), param_5);
      ExceptionList = local_10;
      return;
    }
    for (; param_4 != 0; param_4 = param_4 - 1) {
      uVar4 = *reinterpret_cast<int*>(param_1 + 0xc) + -1 + uVar3;
      uVar1 = uVar4 >> 2;
      iVar2 = static_cast<int>(uVar1) * -4;
      if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar1) {
        uVar1 = uVar1 - *reinterpret_cast<uint32_t*>(param_1 + 8);
      }
      FUN_0043e3d0(reinterpret_cast<uint32_t*>(
          *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + uVar1 * 4) +
          (uVar4 + iVar2) * 4));
    }
    param_5 = reinterpret_cast<uint32_t*>(*param_5);
    iVar5 = *reinterpret_cast<int*>(param_1 + 0xc) + static_cast<int>(uVar3);
    FUN_0043ec50(&local_24, param_1, iVar5 + static_cast<int>(uVar3), param_1,
                 iVar5 + static_cast<int>(param_3), param_1, iVar5,
                 reinterpret_cast<uint32_t>(param_5));
    iVar5 = iVar5 + static_cast<int>(param_3);
    iVar2 = *reinterpret_cast<int*>(param_1 + 0xc) + static_cast<int>(param_3);
  } else {
    local_8 = 2;
    if (local_18 < param_4) {
      ExceptionList = &local_10;
      for (iVar2 = static_cast<int>(param_4 - local_18); iVar2 != 0; iVar2 = iVar2 - 1) {
        FUN_0043d670(param_5);
      }
      for (param_4 = 0; param_4 < local_18; param_4 = param_4 + 1) {
        uVar1 = *reinterpret_cast<int*>(param_1 + 0xc) + static_cast<int>(param_4) +
                static_cast<int>(uVar4);
        uVar3 = uVar1 >> 2;
        iVar2 = static_cast<int>(uVar3) * -4;
        if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar3) {
          uVar3 = uVar3 - *reinterpret_cast<uint32_t*>(param_1 + 8);
        }
        FUN_0043d670(reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + uVar3 * 4) +
            (uVar1 + iVar2) * 4));
      }
      iVar2 = *reinterpret_cast<int*>(param_1 + 0xc) + static_cast<int>(uVar4);
      FUN_0043e910(param_1, iVar2, param_1, iVar2 + static_cast<int>(local_18), param_5);
      ExceptionList = local_10;
      return;
    }
    ExceptionList = &local_10;
    for (param_4 = 0; param_4 < uVar3; param_4 = param_4 + 1) {
      uVar1 = *reinterpret_cast<int*>(param_1 + 0xc) +
              static_cast<int>((param_4 - uVar3) + local_18 + param_3);
      uVar4 = uVar1 >> 2;
      iVar2 = static_cast<int>(uVar4) * -4;
      if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar4) {
        uVar4 = uVar4 - *reinterpret_cast<uint32_t*>(param_1 + 8);
      }
      FUN_0043d670(reinterpret_cast<uint32_t*>(
          *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 4) + uVar4 * 4) +
          (uVar1 + iVar2) * 4));
    }
    iVar2 = *reinterpret_cast<int*>(param_1 + 0xc) + static_cast<int>(param_3);
    param_5 = reinterpret_cast<uint32_t*>(*param_5);
    param_2 = param_1;
    FUN_0043ebb0(&param_2, param_1, iVar2, param_1,
                 (iVar2 + static_cast<int>(local_18)) - static_cast<int>(uVar3), param_1,
                 iVar2 + static_cast<int>(local_18), reinterpret_cast<uint32_t>(param_5));
    iVar5 = iVar2 + static_cast<int>(uVar3);
  }
  FUN_0043e910(param_1, iVar2, param_1, iVar5, reinterpret_cast<uint32_t*>(&param_5));
  ExceptionList = local_10;
}
