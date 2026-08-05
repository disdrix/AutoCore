// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffe_0073df30
// -----------------------------------------------------------------------------
// Stable ID: aa_0073df30
// Callee of Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer
// Address:   0x0073df30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00457040, FUN_0073d830, FUN_0073df30, FUN_00752a80, FUN_00752ba0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffe_0073df30(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_00457040();

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3[1] = 0;

    puVar3[2] = 0;

    *puVar3 = &PTR_FUN_00a9f9c4;

    puVar3[3] = 0;

    puVar3[4] = 0;

    puVar3[5] = 0;

    puVar3[6] = 0;

    *(uint16_t *)(puVar3 + 7) = 0xffff;

    *(uint16_t *)((int)puVar3 + 0x1e) = 0xffff;

    puVar3[8] = 0;

    iVar4 = *(int *)(param_2 + 8);

    if (iVar4 != 0) {

      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;

      if (*(int *)(iVar4 + 8) == 1) {

        (**(code **)(*(int *)(iVar4 + 4) + 4))();

      }

    }

    iVar2 = puVar3[2];

    if (iVar2 != 0) {

      piVar1 = (int *)(iVar2 + 8);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*(int *)(iVar2 + 4) + 8))();

      }

    }

    puVar3[2] = iVar4;

    iVar4 = FUN_00752ba0();

    if (-1 < iVar4) {

      puVar3[7] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

      puVar3[5] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

      puVar3[8] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

      FUN_00752a80();

    }

    FUN_0073d830(puVar3);

    return puVar3;

  }

  return (uint32_t /* width from decompiler */ *)0x0;

}
