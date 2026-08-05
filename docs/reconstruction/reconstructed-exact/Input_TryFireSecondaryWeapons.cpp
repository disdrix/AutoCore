// =============================================================================
// Input_TryFireSecondaryWeapons
// -----------------------------------------------------------------------------
// Stable ID: aa_0091a550
// Address:   0x0091a550  (autoassault.exe, image base 0x400000)
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

void Input_TryFireSecondaryWeapons(void)

{
  char cVar1;
  
  if ((((DAT_00d1b6d8 != 0) &&
       ((*(byte *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xb8 + DAT_00d1b6d8) & 0xd2) == 0)) &&
      (g_pSectorNetConnection_INFERRED != (void *)0x0)) &&
     ((cVar1 = (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 8))(), cVar1 != '\0' &&
      (*(int *)(DAT_00d1b6d8 + 0x250) != 0)))) {
    cVar1 = FUN_004f52e0();
    if (cVar1 == '\0') {
      FUN_007a4480(0,"Failed to fire secondary weapons due to heat.\n");
      return;
    }
    FUN_004f5110();
    if (((*(char *)(DAT_00d1b6d8 + 0x6b8) != '\0') || (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0')) &&
       ((DAT_00d1b8f0 != (int *)0x0 &&
        (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 != '\0')))) {
      FUN_0089ff80();
    }
  }
  return;
}
