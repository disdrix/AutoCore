// =============================================================================
// FUN_004ff6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ff6f0
// Address:   0x004ff6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_004ff6f0(uint param_1)

{
  void *pvVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint local_4;
  
  FUN_004fecb0();
  FUN_004fcc40();
  *(uint8_t *)(param_1 + 0x4a0) = 0;
  local_4 = param_1 & 0xffffff00;
  piVar4 = (int *)(param_1 + 0x300);
  piVar3 = (int *)(param_1 + 0x334);
  do {
    if (*piVar4 != 0) {
      FUN_00583f10(0,*piVar4,1,local_4);
    }
    if ((int *)*piVar3 != (int *)0x0) {
      (**(code **)(*(int *)*piVar3 + 0x1c))();
      if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {
        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);
      }
    }
    *piVar3 = 0;
    if ((uint32_t /* width from decompiler */ *)piVar3[-1] != (uint32_t /* width from decompiler */ *)0x0) {
      (*(code *)**(uint32_t /* width from decompiler */ **)piVar3[-1])(1);
    }
    pvVar1 = (void *)piVar3[-2];
    piVar3[-1] = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_0074ecf0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    iVar5 = *piVar4;
    piVar3[-2] = 0;
    if (iVar5 != 0) {
      pvVar1 = *(void **)(iVar5 + 0x78);
      if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      if ((uint32_t /* width from decompiler */ *)*piVar4 != (uint32_t /* width from decompiler */ *)0x0) {
        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar4)(1);
      }
    }
    cVar2 = (char)local_4 + '\x01';
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
    piVar3 = piVar3 + 3;
    local_4 = CONCAT31(local_4._1_3_,cVar2);
  } while (cVar2 < '\x03');
  piVar4 = (int *)(param_1 + 0x30c);
  iVar5 = 8;
  do {
    if ((uint32_t /* width from decompiler */ *)*piVar4 != (uint32_t /* width from decompiler */ *)0x0) {
      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar4)(1);
    }
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((*(int *)(param_1 + 0x360) != 0) &&
     (pvVar1 = *(void **)(*(int *)(param_1 + 0x360) + 0x78), pvVar1 != (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x360) != (uint32_t /* width from decompiler */ *)0x0) {
    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x360))(1);
  }
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x360) = 0;
  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x364) != (uint32_t /* width from decompiler */ *)0x0) {
    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x364))(1);
  }
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x364) = 0;
  thunk_FUN_00584290();
  return;
}
