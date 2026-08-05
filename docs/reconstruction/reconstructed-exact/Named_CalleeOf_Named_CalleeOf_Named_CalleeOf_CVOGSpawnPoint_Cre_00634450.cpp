// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_00634450
// -----------------------------------------------------------------------------
// Stable ID: aa_00634450
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature
// Address:   0x00634450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0055f4c0×2, FUN_0062d960×2, FUN_006cad30×2, FUN_005fff20, FUN_00634450, FUN_006caaa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_00634450(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t *puVar3;

  int local_2c;

  uint32_t /* width from decompiler */ local_28;

  int iStack_24;

  uint8_t local_14 [20];

  

  if (*(int *)(param_1 + 8) != 0) {

    FUN_0062d960(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x238));

    FUN_0062d960(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x238));

    if (param_1 == -0xc) {

      local_2c = 0;

    }

    else {

      local_2c = param_1 + 0x1c;

    }

    puVar3 = local_14;

    uVar2 = 1;

    (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0xc4) + 0x14))

              (&local_2c,param_2,1,puVar3,&local_28);

    if ((iStack_24 != 0) || (puVar3 != (uint8_t *)0x0)) {

      FUN_006cad30(local_28,iStack_24);

      FUN_006cad30(uVar2,puVar3);

      iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xd0);

      if (iVar1 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = iVar1 + 8;

      }

      FUN_006caaa0(local_28,iStack_24,uVar2,puVar3,iVar1);

      FUN_005fff20();

    }

    FUN_0055f4c0();

    FUN_0055f4c0();

  }

  return;

}
