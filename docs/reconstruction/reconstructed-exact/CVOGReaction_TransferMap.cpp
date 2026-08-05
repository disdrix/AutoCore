// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGReaction_TransferMap, FUN_004025e0, FUN_004d2ac0.
//  - Return sites: 1.

// =============================================================================
// CVOGReaction_TransferMap
// -----------------------------------------------------------------------------
// Stable ID: aa_004d37f0
// Address:   0x004d37f0  (autoassault.exe, image base 0x400000)
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

void __thiscall CVOGReaction_TransferMap(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  

  if ((((*(char *)(param_1 + 0x7e) != '\0') && (param_2 != (int *)0x0)) &&

      (iVar2 = (**(code **)(*param_2 + 0x210))(0), iVar2 != 0)) &&

     ((*(char *)(iVar2 + 0x4f4) == '\0' &&

      (cVar1 = FUN_004d2ac0(iVar2,param_2,param_3), cVar1 != '\0')))) {

    *(uint8_t *)(iVar2 + 0x4f4) = 1;

    FUN_004025e0(&stack0xffffffd4);

  }

  return;

}
