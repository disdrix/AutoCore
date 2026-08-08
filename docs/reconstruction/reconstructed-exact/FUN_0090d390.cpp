// =============================================================================
// FUN_0090d390  (Ghidra twin of Client_Input_FindFirstActiveUiWindowTable5_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0090d390
// Address:   0x0090d390–0x0090d3c4 inclusive  (53 B / 0x35)
// Module:    autoassault.exe (image base 0x400000)
// System:    input-drive-control
// Generated: 2026-08-05 MEGA-096 dual seal
// Prefer:    Client_Input_FindFirstActiveUiWindowTable5_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime / differential: OPEN
// =============================================================================

// PURPOSE: Find first active UI window* in DAT_00d09a38[5] via vtbl+0x3d8.
// ABI: no stack args; plain RET; EAX = window* or 0.

uint32_t /* window* or 0 */ FUN_0090d390(void)
{
  char cVar1;
  int iVar2;

  iVar2 = 0;
  do {
    if ((&DAT_00d09a38)[iVar2] != 0) {
      cVar1 = (**(code **)(*(int *)(&DAT_00d09a38)[iVar2] + 0x3d8))();
      if (cVar1 != '\0') {
        return (&DAT_00d09a38)[iVar2];
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return 0;
}
