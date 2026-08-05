// =============================================================================
// FUN_00720670 / CSoundManager_RequestPlay
// -----------------------------------------------------------------------------
// Stable ID: aa_00720670
// Address:   0x00720670  (autoassault.exe, image base 0x400000)
// Body:      0x00720670 – 0x0072071a
// System:    client audio / CSoundManager
// Generated: 2026-07-29 W18-G dual seal
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// ABI: __thiscall ECX=CSoundManager*; stack SoundPlayRequest 0xC8 by value; ret 0xC8.
// Decompiler surfaces mode/flag as in_stack_000000bc / in_stack_000000c0 (entry ESP).
// Join always: FUN_004804d0 on vector at this+0x70 with &request (entry ESP+4).
// =============================================================================

#include <stdint.h>
#include <windows.h>

extern "C" void __fastcall FUN_00720090(void *self);
extern "C" void __thiscall FUN_004804d0(void *vec_at_70, void *req_ptr);

void __thiscall FUN_00720670(int param_1)
{
  int in_stack_000000bc;   /* entry ESP+0xBC = request+0xB8 mode */
  char in_stack_000000c0;  /* entry ESP+0xC0 = request+0xBC compactFlag */
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t *)0x009abd9c; /* LAB_009abd9c */
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x170));
  local_4 = 0;
  if (in_stack_000000c0 != '\0') {
    if (in_stack_000000bc == 1) {
      FUN_00720090((void *)param_1);
      *(uint8_t *)(param_1 + 0x13) = 1;
      goto LAB_007206f4;
    }
    if (in_stack_000000bc == 2) {
      FUN_00720090((void *)param_1);
      *(uint8_t *)(param_1 + 0x14) = 1;
      goto LAB_007206f4;
    }
  }
  if (in_stack_000000bc == 1) {
    *(uint8_t *)(param_1 + 0x13) = 1;
  } else if (in_stack_000000bc == 2) {
    *(uint8_t *)(param_1 + 0x14) = 1;
  } else if (in_stack_000000bc == 5) {
    *(uint8_t *)(param_1 + 0x15) = 1;
  }
LAB_007206f4:
  /* machine: lea eax, [esp+first_arg]; push eax; lea ecx, [esi+0x70]; call */
  FUN_004804d0((void *)(param_1 + 0x70), (void *)&in_stack_000000bc /* stands in for &req; real = entry ESP+4 */);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x170));
  ExceptionList = pvStack_c;
  return;
}
