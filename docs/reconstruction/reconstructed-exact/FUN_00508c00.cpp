// =============================================================================
// FUN_00508c00  (alias of HandlerTable54_FindById6c)
// -----------------------------------------------------------------------------
// Stable ID: aa_00508c00
// Address:   0x00508c00  (autoassault.exe, image base 0x400000)
// System:    status/hook handler table family (slot +0x54)
// Generated: 2026-07-29 W20-R dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: reconstructed-exact/HandlerTable54_FindById6c.cpp
// =============================================================================

#include <stdint.h>

extern int32_t DAT_00d02988;

// Ghidra symbol retained for xref continuity.
int __thiscall FUN_00508c00(int param_1, int param_2)
{
  int iVar1;
  int *piVar2;

  iVar1 = 0;
  if ((param_2 != -1) && (0 < DAT_00d02988)) {
    piVar2 = *(int **)(param_1 + 0x54);
    do {
      if (*(int *)(*piVar2 + 0x6c) == param_2) {
        return (*(int **)(param_1 + 0x54))[iVar1];
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < DAT_00d02988);
  }
  return 0;
}
