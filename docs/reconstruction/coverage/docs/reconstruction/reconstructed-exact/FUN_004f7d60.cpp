// =============================================================================
// FUN_004f7d60
// -----------------------------------------------------------------------------
// Stable ID: aa_004f7d60
// Address:   0x004f7d60  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004f7d60(int param_1)

{
  int iVar1;
  uint32_t /* width from decompiler */ *puVar2;
  
  if (*(int *)(param_1 + 0x1a0) != 0) {
    iVar1 = *(int *)(param_1 + 8);
    puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x54);
    if ((puVar2 != (uint32_t /* width from decompiler */ *)0x0) &&
       (*(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1,
       *(short *)((int)puVar2 + 6) == 0)) {
      (**(code **)*puVar2)(1);
    }
    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x54) = 0;
    if (**(int **)(param_1 + 0x1a0) != 0) {
      FUN_0055df40(**(int **)(param_1 + 0x1a0));
      puVar2 = (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 0x1a0);
      *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;
      if (*(short *)((int)puVar2 + 6) == 0) {
        (**(code **)*puVar2)(1);
      }
    }
    puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x1a0) + 4);
    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;
    if (*(short *)((int)puVar2 + 6) == 0) {
      (**(code **)*puVar2)(1);
    }
    if (*(void **)(param_1 + 0x1a0) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(param_1 + 0x1a0));
    }
    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a0) = 0;
  }
  return;
}
