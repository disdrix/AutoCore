// =============================================================================
// UiHost_FindTrackedPairNode_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00871690
// Address:   0x00871690  (autoassault.exe, image base 0x400000)
// System:    client UI / vehicle-garage host residual
// Generated: 2026-07-29 W21-R dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Tools: Ghidra decompile_function + read_memory (no disassemble_bytes).
// =============================================================================
//
// PURPOSE:
//   Walk the host's locked list at +0x628 and return the first node whose
//   key pair (node+8, node+0xc) matches (keyA, keyB). Unlocks the list CS on
//   all exits if TraversalLock held the flag at +0x650.
//
// ABI (byte-sealed):
//   __thiscall  ECX = host*
//   stack: keyA, keyB
//   returns: node* or NULL
//   RET 8
//
// Callers:
//   FUN_008718a0 UiHost_ClearTrackedPairAndRefresh_Inferred
//   FUN_008718d0, FUN_008719d0
//
// Callees:
//   FUN_004294f0 List_TraversalLock
//   FUN_004113b0 list iterate-next
//   LeaveCriticalSection
// =============================================================================

// Ghidra-faithful CF (authoritative raw aa_00871690):

int __thiscall UiHost_FindTrackedPairNode_Inferred(int param_1, int param_2, int param_3)
{
  int iVar1;
  int iVar2;
  int local_8;
  unsigned local_4;

  local_4 = 0;
  local_8 = 0;
  FUN_004294f0();                                 // this = list at param_1+0x628 (ECX)
  iVar2 = FUN_004113b0(param_1 + 0x628, &local_8);
  iVar1 = local_8;
  while (true) {
    local_8 = iVar1;
    if (iVar2 != 0) {
      if (*(char *)(param_1 + 0x650) != '\0') {
        *(unsigned char *)(param_1 + 0x650) = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x62c));
      }
      return 0;
    }
    if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_2))
        && (*(int *)(iVar1 + 0xc) == param_3)) {
      break;
    }
    iVar2 = FUN_004113b0(param_1 + 0x628, &local_8);
    iVar1 = local_8;
  }
  if (*(char *)(param_1 + 0x650) != '\0') {
    *(unsigned char *)(param_1 + 0x650) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x62c));
  }
  return iVar1;
}
