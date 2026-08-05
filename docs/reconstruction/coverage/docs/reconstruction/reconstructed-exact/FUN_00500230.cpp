// =============================================================================
// FUN_00500230
// -----------------------------------------------------------------------------
// Stable ID: aa_00500230
// Address:   0x00500230  (autoassault.exe, image base 0x400000)
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

undefined * __fastcall FUN_00500230(int param_1)

{
  char cVar1;
  int iVar2;
  uint32_t /* width from decompiler */ uVar3;
  char *pcVar4;
  undefined *puVar5;
  int local_88;
  char *local_84;
  char local_80 [128];
  
  local_88 = *(int *)(param_1 + -0x524);
  if (-1 < local_88) {
    iVar2 = FUN_0040b330(&local_88);
    local_84 = local_80;
    uVar3 = (*(code *)PTR_FUN_00af8c9c)();
    FUN_00403450(iVar2 + 0xf6,uVar3);
    pcVar4 = local_84;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)&DAT_00b040a8 - (int)local_84] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (local_84 != local_80) {
      free(local_84);
    }
    return &DAT_00b040a8;
  }
  puVar5 = (undefined *)FUN_005145b0();
  return puVar5;
}
