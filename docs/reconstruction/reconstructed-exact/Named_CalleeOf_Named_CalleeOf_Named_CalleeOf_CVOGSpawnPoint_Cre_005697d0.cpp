// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_005697d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005697d0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature
// Address:   0x005697d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×2, do×1, while×1.
//  - Notable callees: FUN_00569560, FUN_005697d0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_005697d0(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t local_78 [4];

  uint32_t /* width from decompiler */ local_74 [14];

  int local_3c;

  uint32_t /* width from decompiler */ local_38 [14];

  

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar5[1] + 0x49) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar5[1];

    do {

      if ((int)puVar1[3] < *param_2) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar5 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x49) == '\0');

  }

  if ((puVar5 != *(uint32_t /* width from decompiler */ **)(param_1 + 4)) && ((int)puVar5[3] <= *param_2)) {

    return puVar5 + 4;

  }

  puVar1 = local_74;

  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

  }

  local_3c = *param_2;

  puVar1 = local_74;

  puVar2 = local_38;

  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar2 = *puVar1;

    puVar1 = puVar1 + 1;

    puVar2 = puVar2 + 1;

  }

  piVar3 = (int *)FUN_00569560(local_78,puVar5,&local_3c);

  return (uint32_t /* width from decompiler */ *)(*piVar3 + 0x10);

}
