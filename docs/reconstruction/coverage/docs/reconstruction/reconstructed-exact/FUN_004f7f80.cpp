// =============================================================================
// FUN_004f7f80
// -----------------------------------------------------------------------------
// Stable ID: aa_004f7f80
// Address:   0x004f7f80  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004f7f80(int param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  uint32_t /* width from decompiler */ local_4;
  
  FUN_00512670();
  if (*(int *)(param_1 + 0x2b0) != 0) {
    local_4 = 0;
    local_8 = 0;
    FUN_005706d0();
    iVar2 = *(int *)(param_1 + 0x2b0);
    FUN_004294f0();
    iVar1 = FUN_004022a0(&local_4,&local_8);
    while (iVar1 == 0) {
      if (local_8 != 0) {
        FUN_00512670();
      }
      iVar1 = FUN_004022a0(&local_4,&local_8);
    }
    if (*(char *)(iVar2 + 0x54) != '\0') {
      *(uint8_t *)(iVar2 + 0x54) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x30));
    }
  }
  if (*(int *)(param_1 + 0x270) != 0) {
    FUN_00512670();
  }
  if (*(int *)(param_1 + 0x26c) != 0) {
    FUN_00512670();
  }
  iVar2 = 0;
  do {
    if (*(int *)(iVar2 + *(int *)(param_1 + 0x260)) != 0) {
      FUN_00512670();
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0xc);
  if (*(int *)(param_1 + 0x268) != 0) {
    FUN_00512670();
  }
  if (*(int *)(param_1 + 600) != 0) {
    FUN_00512670();
  }
  if (*(int *)(param_1 + 0x254) != 0) {
    FUN_00512670();
  }
  if (*(int *)(param_1 + 0x264) != 0) {
    FUN_00512670();
  }
  return;
}
