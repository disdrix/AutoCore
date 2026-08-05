// =============================================================================
// FUN_004cda90  (scaffold twin — prefer Client_InitPalantirViewBundle_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cda90
// Address:   0x004cda90  (autoassault.exe, image base 0x400000)
// System:    client / Palantir view bundle factory
// Generated: 2026-07-29 W30-F (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: See Client_InitPalantirViewBundle_Inferred.cpp / function records.
// Named clean is authoritative; this twin keeps Ghidra symbol for grep stability.

#include <cstdint>

extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__fastcall FUN_0075ceb0(void *self);
extern "C" void  __thiscall FUN_0075b3b0(void *self, uint32_t a);
extern "C" void  __thiscall FUN_0075b390(void *self, uint32_t a);
extern "C" void *__thiscall FUN_00492dd0(void *self, uint32_t a, void *parent);
extern "C" void *__thiscall FUN_00496f70(void *self, void *parent);
extern "C" void  __thiscall FUN_0048fc90(void *self, uint32_t flag);
extern "C" void  FUN_0074e200(uint32_t enable);
extern "C" uint32_t DAT_00a0f520;
extern "C" uint32_t DAT_00aaaa90;
extern "C" uint32_t DAT_00afdef0;
extern "C" uint32_t DAT_00d1a54c;

uint32_t __fastcall FUN_004cda90(int param_1)
{
  int iVar1;
  void *pvVar2;
  uint32_t uVar3;

  pvVar2 = operator_new(0x150);
  if (pvVar2 == nullptr) {
    uVar3 = 0;
  } else {
    uVar3 = reinterpret_cast<uint32_t>(FUN_0075ceb0(pvVar2));
  }
  *reinterpret_cast<uint32_t *>(param_1 + 0xe890) = uVar3;
  FUN_0075b3b0(reinterpret_cast<void *>(uVar3), 0x3f000000);
  uVar3 = DAT_00a0f520;
  if (*reinterpret_cast<char *>(param_1 + 0x7d) == '\0') {
    uVar3 = DAT_00aaaa90;
  }
  FUN_0075b390(reinterpret_cast<void *>(*reinterpret_cast<uint32_t *>(param_1 + 0xe890)), uVar3);
  if (*reinterpret_cast<int *>(param_1 + 0xe89c) != 0) {
    *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(param_1 + 0xe89c) + 0x2e4) =
        *reinterpret_cast<uint32_t *>(param_1 + 0xe890);
    int *child = *reinterpret_cast<int **>(*reinterpret_cast<int *>(param_1 + 0xe89c) + 0x2c);
    auto **vt = reinterpret_cast<void **>(*child);
    using Fn = void(__thiscall *)(void *, uint32_t);
    reinterpret_cast<Fn>(vt[3])(child, *reinterpret_cast<uint32_t *>(param_1 + 0xe890));
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(child) + 0xc4) = DAT_00afdef0;
  }
  pvVar2 = operator_new(0x198);
  if (pvVar2 == nullptr) {
    uVar3 = 0;
  } else {
    uVar3 = reinterpret_cast<uint32_t>(FUN_00492dd0(pvVar2, 0, reinterpret_cast<void *>(param_1)));
  }
  *reinterpret_cast<uint32_t *>(param_1 + 0xe894) = uVar3;
  pvVar2 = operator_new(200);
  if (pvVar2 == nullptr) {
    uVar3 = 0;
  } else {
    uVar3 = reinterpret_cast<uint32_t>(FUN_00496f70(pvVar2, reinterpret_cast<void *>(param_1)));
  }
  *reinterpret_cast<uint32_t *>(param_1 + 0xe898) = uVar3;
  *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(param_1 + 0xe890) + 4) =
      *reinterpret_cast<uint32_t *>(param_1 + 0xe894);
  *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(param_1 + 0xe894) + 0xc0) =
      *reinterpret_cast<uint32_t *>(param_1 + 0xe890);
  FUN_0048fc90(reinterpret_cast<void *>(*reinterpret_cast<uint32_t *>(param_1 + 0xe894)), 1);
  iVar1 = *reinterpret_cast<int *>(*reinterpret_cast<int *>(param_1 + 0xe894) + 4);
  if (DAT_00d1a54c != 0) {
    FUN_0074e200(0);
  }
  if (iVar1 != 0) {
    FUN_0074e200(1);
  }
  DAT_00d1a54c = static_cast<uint32_t>(iVar1);
  return 1;
}
