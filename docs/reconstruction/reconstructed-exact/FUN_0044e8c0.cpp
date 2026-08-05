// =============================================================================
// FUN_0044e8c0  — scaffold alias → HashMap_FindIterator_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e8c0
// Address:   0x0044e8c0 – 0x0044e945  (autoassault.exe, image base 0x400000)
// System:    hash map (ND resource cache + other name tables)
// Generated: 2026-07-29 W21-N OWN-ONLY dual (decompile + read_memory)
// Exactness: Scaffold preserves decompiler shape; register formals documented.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern uint32_t FUN_0043b870(void);

/*
 * Register formals (caller-set, not in Ghidra signature):
 *   EDI = map*
 *   EBX = key*
 * Stack: out_it*; ret 4; returns out_it*.
 */
uint32_t *FUN_0044e8c0(uint32_t *param_1)
{
  int *piVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int *piVar4;
  /* unaff_* are live formals sealed by bytes */
  uint32_t *unaff_EBX; /* key* in EBX */
  int unaff_EDI;       /* map* in EDI */

  uVar2 = *(uint32_t *)(unaff_EDI + 0x20);
  uVar3 = FUN_0043b870();
  uVar3 = uVar3 & uVar2;
  if (*(uint32_t *)(unaff_EDI + 0x24) <= uVar3) {
    uVar3 = uVar3 + (uint32_t)(-1 - (uVar2 >> 1));
  }
  piVar1 = (int *)(*(int *)(unaff_EDI + 0x14) + uVar3 * 4);
  piVar4 = (int *)*piVar1;
  if (piVar4 != (int *)piVar1[1]) {
    do {
      if (*unaff_EBX <= (uint32_t)piVar4[2]) {
        if ((uint32_t)piVar4[2] <= *unaff_EBX) {
          *param_1 = (uint32_t)piVar4;
          return param_1;
        }
        *param_1 = *(uint32_t *)(unaff_EDI + 8);
        return param_1;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)piVar1[1]);
  }
  *param_1 = *(uint32_t *)(unaff_EDI + 8);
  return param_1;
}
