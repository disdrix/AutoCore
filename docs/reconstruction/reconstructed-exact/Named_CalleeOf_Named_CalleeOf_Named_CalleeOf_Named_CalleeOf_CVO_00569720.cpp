// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00569720
// -----------------------------------------------------------------------------
// Stable ID: aa_00569720
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre
// Address:   0x00569720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_00568bc0, FUN_005696d0, FUN_00569720.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00569720(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  if (param_2 != param_1) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

    puVar3 = (uint32_t /* width from decompiler */ *)*puVar1;

    puVar6 = (uint32_t /* width from decompiler */ *)*puVar2;

    while (puVar3 != puVar1) {

      if (puVar6 == puVar2) {

        return;

      }

      if (*(short *)(puVar6[2] + 4) < *(short *)(puVar3[2] + 4)) {

        puVar4 = (uint32_t /* width from decompiler */ *)*puVar6;

        FUN_00568bc0(1);

        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;

        *(uint32_t /* width from decompiler */ **)puVar6[1] = puVar4;

        *(uint32_t /* width from decompiler */ **)puVar4[1] = puVar3;

        *(uint32_t /* width from decompiler */ **)puVar3[1] = puVar6;

        uVar5 = puVar3[1];

        puVar3[1] = puVar4[1];

        puVar4[1] = puVar6[1];

        puVar6[1] = uVar5;

        puVar6 = puVar4;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

    }

    if (puVar6 != puVar2) {

      FUN_005696d0(puVar1,param_2,puVar6,puVar2,*(uint32_t /* width from decompiler */ *)(param_2 + 8));

    }

  }

  return;

}
