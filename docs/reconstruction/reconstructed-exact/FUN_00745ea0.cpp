// =============================================================================
// FUN_00745ea0  — scaffold alias → NDResource_DecRef
// -----------------------------------------------------------------------------
// Stable ID: aa_00745ea0
// Address:   0x00745ea0 – 0x00745ed9  (autoassault.exe, image base 0x400000)
// System:    client resource / NDResource shell
// Generated: 2026-07-29 W21-N OWN-ONLY dual (decompile + read_memory)
// Exactness: Scaffold name retained; body matches NDResource_DecRef.cpp.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>
#include <windows.h>

uint32_t __fastcall FUN_00745ea0(void *param_1 /* ECX this */)
{
  uint32_t uVar1;

  if (*(char *)((char *)param_1 + 0x38) != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)((char *)param_1 + 0x20));
  }

  uVar1 = 0xffffffff;
  if (*(int *)((char *)param_1 + 0x10) != 0) {
    *(int *)((char *)param_1 + 0x10) =
        *(int *)((char *)param_1 + 0x10) + -1;
    uVar1 = 0;
  }

  if (*(char *)((char *)param_1 + 0x38) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)param_1 + 0x20));
  }

  return uVar1;
}
