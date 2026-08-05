// =============================================================================
// FUN_005057c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005057c0
// Address:   0x005057c0  (autoassault.exe, image base 0x400000)
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

void __thiscall
FUN_005057c0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5
            ,uint32_t /* width from decompiler */ param_6)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x3c) + 0x18))();
    if (iVar1 == 6) {
      FUN_0053d970(0);
    }
    *(uint32_t /* width from decompiler */ *)(param_1 + 0x614) = 0;
    *(uint32_t /* width from decompiler */ *)(param_1 + 0x618) = 0;
    *(uint8_t *)(param_1 + 0x61c) = 1;
    VehicleEntity_PushDriveAxesToController();
    FUN_0053eec0(param_2,param_3,param_4,param_5,param_6);
  }
  return;
}
