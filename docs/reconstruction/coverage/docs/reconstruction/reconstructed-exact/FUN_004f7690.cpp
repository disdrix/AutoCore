// =============================================================================
// FUN_004f7690
// -----------------------------------------------------------------------------
// Stable ID: aa_004f7690
// Address:   0x004f7690  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __fastcall FUN_004f7690(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0xe4e8), iVar2 != 0)) {
    if (*(int *)(param_1 + 0x254) != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x254) + 4) + 4) + 4 +
                           *(int *)(param_1 + 0x254)) + 0x2a8))(iVar2);
    }
    iVar2 = *(int *)(param_1 + 600);
    if (iVar2 != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x2a8))
                (*(uint32_t /* width from decompiler */ *)
                  (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4e8));
    }
    iVar2 = *(int *)(param_1 + 0x264);
    if (iVar2 != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x2a8))
                (*(uint32_t /* width from decompiler */ *)
                  (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4e8));
    }
    if (*(int *)(param_1 + 0x268) != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x268) + 4) + 4) + 4 +
                           *(int *)(param_1 + 0x268)) + 0x2a8))
                (*(uint32_t /* width from decompiler */ *)
                  (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4e8));
    }
    if (*(int *)(param_1 + 0x26c) != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x26c) + 4) + 4) + 4 +
                           *(int *)(param_1 + 0x26c)) + 0x2a8))
                (*(uint32_t /* width from decompiler */ *)
                  (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4e8));
    }
    if (*(int *)(param_1 + 0x270) != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x270) + 4) + 4) + 4 +
                           *(int *)(param_1 + 0x270)) + 0x2a8))
                (*(uint32_t /* width from decompiler */ *)
                  (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4e8));
    }
    iVar2 = 0;
    do {
      iVar1 = *(int *)(iVar2 + *(int *)(param_1 + 0x260));
      if (iVar1 != 0) {
        (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x2a8))
                  (*(uint32_t /* width from decompiler */ *)
                    (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4e8));
      }
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0xc);
    return 1;
  }
  return 0;
}
