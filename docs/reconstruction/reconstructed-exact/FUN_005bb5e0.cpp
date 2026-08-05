// =============================================================================
// FUN_005bb5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005bb5e0
// Address:   0x005bb5e0 – 0x005bb666  (autoassault.exe, image base 0x400000)
// System:    client object motion / reaction slot list
// Generated: 2026-07-29 W27-D dual seal (decompile + read_memory)
// Exactness: Decompiler-faithful outer CF. Named twin includes byte-sealed count--.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern uint32_t _DAT_00af3f68;
char __thiscall FUN_004b4620(void *slot, uint32_t flag, uint32_t dt_bits);
void FUN_005be2b0(int payload);
void operator_delete(void *p);

// ECX = motion host; ret 8; EAX = count at +0xA28
// NOTE: Ghidra falsely marks operator_delete noreturn and drops count--.
uint32_t __thiscall FUN_005bb5e0(int param_1, uint32_t *param_2, uint32_t param_3)
{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;

  _DAT_00af3f68 = *param_2;
  piVar3 = (int *)**(int **)(param_1 + 0xa24);
  if (piVar3 != *(int **)(param_1 + 0xa24)) {
    do {
      iVar1 = piVar3[2];
      cVar2 = FUN_004b4620(reinterpret_cast<void *>(iVar1), param_3, *param_2);
      if (cVar2 == '\0') {
        FUN_005be2b0(iVar1);
        piVar4 = (int *)*piVar3;
        if (piVar3 != *(int **)(param_1 + 0xa24)) {
          *(int **)piVar3[1] = piVar4;
          *(int *)(*piVar3 + 4) = piVar3[1];
          /* WARNING: Ghidra says does not return — FALSE; continues */
          operator_delete(piVar3);
          /* BYTE: *(param_1+0xa28)--  missing in raw decompile */
        }
      }
      else {
        piVar4 = (int *)*piVar3;
      }
      piVar3 = piVar4;
    } while (piVar4 != *(int **)(param_1 + 0xa24));
  }
  return *(uint32_t *)(param_1 + 0xa28);
}
