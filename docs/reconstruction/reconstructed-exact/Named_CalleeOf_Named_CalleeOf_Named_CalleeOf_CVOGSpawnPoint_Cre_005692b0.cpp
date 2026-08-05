// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_005692b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005692b0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature
// Address:   0x005692b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005690a0, FUN_005692b0.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_005692b0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3)



{

  bool bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar1 = true;

  if (*(char *)((int)puVar3[1] + 0x49) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      puVar3 = puVar2;

      bVar1 = *param_3 < (int)puVar3[3];

      if (bVar1) {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar3[2];

      }

    } while (*(char *)((int)puVar2 + 0x49) == '\0');

  }

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_005690a0(&param_3,bVar1,puVar3,param_3);

  *param_2 = *puVar3;

  *(uint8_t *)(param_2 + 1) = 1;

  return;

}
