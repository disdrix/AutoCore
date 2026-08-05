// =============================================================================
// FUN_004fcb50
// -----------------------------------------------------------------------------
// Stable ID: aa_004fcb50
// Address:   0x004fcb50  (autoassault.exe, image base 0x400000)
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

uint FUN_004fcb50(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint32_t /* width from decompiler */ *puVar7;
  char *pcVar8;
  char local_130 [31];
  char cStack_111;
  char local_110 [2];
  uint32_t /* width from decompiler */ uStack_10e;
  
  uVar5 = 0;
  local_110[0] = '\0';
  local_110[1] = '\0';
  puVar7 = &uStack_10e;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(uint16_t *)puVar7 = 0;
  while( true ) {
    FUN_004fc4c0(local_110);
    if (uVar5 + 1 < 10) {
      pcVar8 = "_0%i_t";
    }
    else {
      pcVar8 = "_%i_t";
    }
    sprintf(local_130,pcVar8,uVar5 + 1);
    pcVar8 = local_130;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    uVar2 = (int)pcVar8 - (int)local_130;
    pcVar8 = &cStack_111;
    do {
      pcVar6 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = local_130;
    for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar8 = &cStack_111;
    do {
      pcVar6 = pcVar8;
      pcVar8 = pcVar6 + 1;
    } while (pcVar6[1] != '\0');
    pcVar8 = local_110;
    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = DAT_00a2c53c;
    pcVar6[5] = DAT_00a2c540;
    FUN_007b6a20(pcVar8);
    cVar1 = FUN_007b6770(pcVar8);
    if (cVar1 == '\0') break;
    uVar5 = (uint)(byte)((char)uVar5 + 1);
  }
  return uVar5;
}
