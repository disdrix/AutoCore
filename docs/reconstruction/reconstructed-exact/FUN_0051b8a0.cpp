// =============================================================================
// FUN_0051b8a0  (scaffold twin — prefer ObjectCsList_ClearDestroy_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b8a0
// Address:   0x0051b8a0  (autoassault.exe, image base 0x400000)
// System:    object core / CS-list clear-destroy
// Generated: 2026-07-29 W30-F (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void *__cdecl _CxxThrowException(void *obj, void *info);
extern "C" void *DAT_00acc430;

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __fastcall FUN_0051b8a0(int param_1)
{
  uint32_t *puVar1;
  uint32_t local_18;

  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 4));
  puVar1 = *reinterpret_cast<uint32_t **>(param_1 + 0x1c);
  if (*reinterpret_cast<char *>(param_1 + 0x28) != '\0') {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 4));
    local_18 = 0x80070005;
    _CxxThrowException(&local_18, &DAT_00acc430);
  }
  while (puVar1 != nullptr) {
    *reinterpret_cast<uint32_t *>(param_1 + 0x1c) = puVar1[2];
    puVar1[1] = 0;
    using Fn = void(__thiscall *)(uint32_t *, int);
    reinterpret_cast<Fn>(*reinterpret_cast<void **>(puVar1))(puVar1, 1);
    puVar1 = *reinterpret_cast<uint32_t **>(param_1 + 0x1c);
  }
  *reinterpret_cast<uint32_t *>(param_1 + 0x24) = 0;
  *reinterpret_cast<uint32_t *>(param_1 + 0x20) = 0;
  *reinterpret_cast<uint32_t *>(param_1 + 0x1c) = 0;
  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 4));
}
