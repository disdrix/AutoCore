// =============================================================================
// FUN_004bc950  (alias of List_DestroyAll)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc950
// Address:   0x004bc950–0x004bca4a  (autoassault.exe, image base 0x400000)
// System:    client::list / inventory-transfer
// Generated: 2026-08-05 R10-028 dual seal (refresh of 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Preferred name: List_DestroyAll (product SEH string)
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void __stdcall _CxxThrowException(void*, void*);
extern uint8_t DAT_00acc430[];

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __fastcall FUN_004bc950(int param_1)
{
  uint32_t* puVar1;

  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 4));
  puVar1 = *reinterpret_cast<uint32_t**>(param_1 + 0x1c);
  if (*reinterpret_cast<char*>(param_1 + 0x28) != '\0') {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 4));
    uint32_t local_18 = 0x80070005u;
    _CxxThrowException(&local_18, reinterpret_cast<void*>(&DAT_00acc430));
  }
  while (puVar1 != nullptr) {
    *reinterpret_cast<uint32_t**>(param_1 + 0x1c) = reinterpret_cast<uint32_t*>(puVar1[2]);
    (**(void(__thiscall***)(uint32_t*, int))puVar1)(puVar1, 1);
    puVar1 = *reinterpret_cast<uint32_t**>(param_1 + 0x1c);
  }
  *reinterpret_cast<uint32_t*>(param_1 + 0x24) = 0;
  *reinterpret_cast<uint32_t*>(param_1 + 0x20) = 0;
  *reinterpret_cast<uint32_t*>(param_1 + 0x1c) = 0;
  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 4));
  return;
}
