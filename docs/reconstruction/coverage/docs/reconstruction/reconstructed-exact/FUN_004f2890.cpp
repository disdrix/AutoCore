// =============================================================================
// FUN_004f2890
// -----------------------------------------------------------------------------
// Stable ID: aa_004f2890
// Address:   0x004f2890  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall
FUN_004f2890(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5
            )

{
  int iVar1;
  char *pcVar2;
  uint32_t /* width from decompiler */ uVar3;
  uint3 uVar4;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = param_1;
  if (*(int *)(param_1 + 0x98) == 0) {
    iVar1 = *(int *)(param_1 + 0x3c);
    if (((iVar1 != 0) && (*(short *)(iVar1 + 0x40a) != 0)) && (*(short *)(iVar1 + 0x40c) != 0)) {
      pcVar2 = (char *)FUN_005de8f0((int)&uStack_4 + 3);
      if (*pcVar2 != '\0') {
        FUN_004f1180();
      }
    }
    if (*(int *)(param_1 + 0x98) == 0) {
      return 0;
    }
  }
  uVar4 = (uint3)((uint)param_4 >> 8);
  uVar3 = FUN_004ed470(param_1 + 0x90,param_2,0x3f800000,0x3f800000,
                       CONCAT31(uVar4 >> 1,
                                (char)(CONCAT31(uVar4,*(uint8_t *)
                                                       (*(int *)(param_1 + 0x3c) + 0x3f2)) >> 1)) &
                       0xffffff01,param_3,param_4,0,param_5);
  return uVar3;
}
