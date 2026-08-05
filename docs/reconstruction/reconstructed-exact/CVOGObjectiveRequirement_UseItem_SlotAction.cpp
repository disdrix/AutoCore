// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, sprintf, strncat.
//  - Strings: "%s: %i / %i".
//  - Return sites: 1.

// =============================================================================
// CVOGObjectiveRequirement_UseItem_SlotAction
// -----------------------------------------------------------------------------
// Stable ID: aa_0060d060
// Address:   0x0060d060  (autoassault.exe, image base 0x400000)
// System:    missions-progression
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

int __thiscall

CVOGObjectiveRequirement_UseItem_SlotAction

          (int param_1,uint32_t /* width from decompiler */ param_2,int param_3,char *param_4,size_t param_5)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  char local_200 [512];

  

  FUN_007a69d0();

  uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

  iVar4 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

  uVar2 = FUN_007a6de0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),0xffffffff);

  sprintf(local_200,"%s: %i / %i",uVar2,iVar4,uVar5);

  strncat(param_4,local_200,param_5);

  pcVar3 = local_200;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  return (int)pcVar3 - (int)(local_200 + 1);

}
