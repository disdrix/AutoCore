// =============================================================================
// FUN_004eb0f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004eb0f0
// Address:   0x004eb0f0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ FUN_004eb0f0(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint32_t /* width from decompiler */ *unaff_EDI;
  uint32_t /* width from decompiler */ uVar5;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a274d;
  local_c = ExceptionList;
  pcVar4 = (char *)*unaff_EDI;
  pcVar3 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    pcVar3 = PTR_DAT_00afa2bc;
  }
  pcVar1 = pcVar3 + 1;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  if (4 < (uint)((int)pcVar3 - (int)pcVar1)) {
    if (pcVar4 == (char *)0x0) {
      pcVar4 = PTR_DAT_00afa2bc;
    }
    uVar5 = 0xffffffff;
    ExceptionList = &local_c;
    FUN_007b6a20(pcVar4,0xffffffff);
    cVar2 = FUN_007b6730(pcVar4,uVar5);
    if (cVar2 != '\0') {
      cVar2 = FUN_0099bfc0(unaff_EDI);
      if (cVar2 == '\0') {
        FUN_00764030();
        local_4 = 0;
        FUN_00764830(unaff_EDI);
        local_4 = 0xffffffff;
        FUN_00763f60();
        ExceptionList = local_c;
        return 1;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}
