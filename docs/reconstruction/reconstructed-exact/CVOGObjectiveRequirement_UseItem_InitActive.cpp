// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_005310a0×2, FUN_007a4480×2, S×2, CVOGObjectiveRequirement_UseItem_InitActive.
//  - Return sites: 1.

// =============================================================================
// CVOGObjectiveRequirement_UseItem_InitActive
// -----------------------------------------------------------------------------
// Stable ID: aa_0060d540
// Address:   0x0060d540  (autoassault.exe, image base 0x400000)
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

void __thiscall CVOGObjectiveRequirement_UseItem_InitActive(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if (*(char *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0x7e) != '\0') {

    if ((*(int *)(param_1 + 0x18) != -1) && (*(char *)(param_1 + 0x24) != '\0')) {

      uVar4 = 1;

      if (*(char *)(param_1 + 0x25) == '\0') {

        uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

      }

      cVar3 = FUN_005310a0(*(int *)(param_1 + 0x18),uVar4);

      if (cVar3 == '\0') {

        puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0x14c);

        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

        FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",

                     *(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_2),

                     *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_2),

                     *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0x10),puVar1 + 1,*puVar1);

      }

    }

    if ((*(int *)(param_1 + 0x2c) != -1) && (*(char *)(param_1 + 0x31) != '\0')) {

      uVar4 = 1;

      if (*(char *)(param_1 + 0x32) == '\0') {

        uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

      }

      cVar3 = FUN_005310a0(*(int *)(param_1 + 0x2c),uVar4);

      if (cVar3 == '\0') {

        puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0x14c);

        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

        FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",

                     *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_2),

                     *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_2),

                     *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0x10),puVar1 + 1,*puVar1);

      }

    }

  }

  return;

}
