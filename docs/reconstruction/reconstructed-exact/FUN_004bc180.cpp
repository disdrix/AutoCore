// =============================================================================
// FUN_004bc180  (scaffold alias → Object_RegisterListed)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc180
// Address:   0x004bc180  (autoassault.exe, image base 0x400000)
// System:    world object listing / mission notify hooks
// Generated: 2026-07-23 scaffold; dual-sealed 2026-07-29 W19-E
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Prefer:    reconstructed-exact/Object_RegisterListed.cpp
// =============================================================================

// PURPOSE: Register object into listing context. See Object_RegisterListed.cpp.
// Strings: "VOG_DEBUG_STOP" (invalid COID log only); "object %I64d (%d) is already listed"
// ABI: __thiscall, ret 4; returns 0 or throws HRESULT.

/* WARNING: Type propagation algorithm not settling */

#include <cstdint>

extern "C" void FUN_007a4480(int, const char*, ...);
extern "C" void _CxxThrowException(void*, void*);
extern "C" int FUN_004e77d0(int, int, void*, int);
extern "C" void* CNDHash_LookupByKey(void*, unsigned);
extern "C" void* operator_new(unsigned);
extern "C" int FUN_004bcb40();
extern "C" void FUN_004bd1d0(std::uint32_t, int, int);
extern "C" int FUN_004bc680(void*, int*);
extern "C" void CVOGReaction_FailMissionNotify(void*);
extern "C" char FUN_005130e0(int);
extern void* DAT_00acc430;

std::uint32_t __thiscall FUN_004bc180(int param_1, int* param_2)
{
  int* piVar1 = param_2;
  int iVar3 = param_2[0x59];

  if ((iVar3 < 1) && ((iVar3 < 0) || (param_2[0x58] == 0))) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    std::uint32_t local_28 = 0x80070057u;
    _CxxThrowException(&local_28, &DAT_00acc430);
  }
  if ((char)param_2[0x5a] == '\0') {
    if (*(char*)(param_1 + 0xd) == '\0') {
      std::uint32_t local_34 = 0x80070057u;
      _CxxThrowException(&local_34, &DAT_00acc430);
    }
  } else if (*(char*)(param_1 + 0xc) == '\0') {
    std::uint32_t local_28 = 0x80070057u;
    _CxxThrowException(&local_28, &DAT_00acc430);
  }

  iVar3 = FUN_004e77d0(param_2[0x58], iVar3, param_2, 0);
  if (iVar3 != 0) {
    FUN_007a4480(1, "object %I64d (%d) is already listed",
                 piVar1[0x58], piVar1[0x59],
                 *(std::uint32_t*)(piVar1[0x2a] + 0x34));
    return 0;
  }

  iVar3 = (**(int(**)())(*piVar1 + 0x208))();
  unsigned key = (iVar3 == 0) ? *(unsigned*)(piVar1[0x2a] + 0x38) : 0x30u;

  void* pvVar4 = CNDHash_LookupByKey(*(void**)(param_1 + 0x18), key);
  if (pvVar4 == nullptr) {
    pvVar4 = operator_new(0x2c);
    if ((pvVar4 == nullptr) || (iVar3 = FUN_004bcb40(), iVar3 == 0)) {
      std::uint32_t local_28 = 0x8007000Eu;
      _CxxThrowException(&local_28, &DAT_00acc430);
    }
    FUN_004bd1d0(*(std::uint32_t*)(piVar1[0x2a] + 0x38), iVar3, 0);
  }

  int handle = 0;
  FUN_004bc680(piVar1, &handle);
  piVar1[0x37] = handle;

  if ((*(int*)(piVar1[0x2a] + 0x38) == 0x12) ||
      (((*(int*)(piVar1[0x2a] + 0x38) == 0xe &&
         (iVar3 = (**(int(**)())(*piVar1 + 0x1d4))(), iVar3 != 0)) &&
        (iVar3 = (**(int(**)())(*piVar1 + 0x1d4))(),
         *(char*)(iVar3 + 0x2ac) == '\0')))) {
    int hr = FUN_004bc680(piVar1, &handle);
    if (hr < 0) _CxxThrowException(&hr, &DAT_00acc430);
    piVar1[0x34] = handle;
    CVOGReaction_FailMissionNotify(&param_2);
  } else if (*(int*)(piVar1[0x2a] + 0x38) == 0x14) {
    CVOGReaction_FailMissionNotify(&param_2);
  }

  if (FUN_005130e0(1) != '\0') {
    int hr = FUN_004bc680(piVar1, &handle);
    if (hr < 0) _CxxThrowException(&hr, &DAT_00acc430);
    piVar1[0x35] = handle;
  }
  if ((((unsigned)piVar1[0x5f] >> 5) & 1) != 0) {
    int hr = FUN_004bc680(piVar1, &handle);
    if (hr < 0) _CxxThrowException(&hr, &DAT_00acc430);
    piVar1[0x36] = handle;
    CVOGReaction_FailMissionNotify(&param_2);
  }
  return 0;
}
