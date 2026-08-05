// =============================================================================
// FUN_00871690  (scaffold alias — canonical: UiHost_FindTrackedPairNode_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00871690
// Address:   0x00871690  (autoassault.exe, image base 0x400000)
// System:    client UI / vehicle-garage host residual
// Generated: 2026-07-23 scaffold; plate strengthened 2026-07-29 W21-R
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Find locked-list node at host+0x628 matching (keyA@+8, keyB@+0xc).
// ABI: __thiscall ECX=host; stack keyA,keyB; returns node*|0; RET 8.
// See: reconstructed-exact/UiHost_FindTrackedPairNode_Inferred.cpp

int __thiscall FUN_00871690(int param_1, int param_2, int param_3)
{
  int iVar1;
  int iVar2;
  int local_8;
  uint32_t local_4;

  local_4 = 0;
  local_8 = 0;
  FUN_004294f0();
  iVar2 = FUN_004113b0(param_1 + 0x628, &local_8);
  iVar1 = local_8;
  while (true) {
    local_8 = iVar1;
    if (iVar2 != 0) {
      if (*(char *)(param_1 + 0x650) != '\0') {
        *(uint8_t *)(param_1 + 0x650) = 0;
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
    *(uint8_t *)(param_1 + 0x650) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x62c));
  }
  return iVar1;
}
