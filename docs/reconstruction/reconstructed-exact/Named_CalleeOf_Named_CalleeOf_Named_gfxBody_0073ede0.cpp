// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxBody_0073ede0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ede0
// Callee of Named_CalleeOf_Named_gfxBody
// Address:   0x0073ede0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: for×4, if×2, return×1.
//  - Notable callees: FUN_0073ecf0, FUN_0073ede0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxBody
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_gfxBody_0073ede0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  int iVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  if (*(int *)(unaff_EBX + 0xc) != 0) {

    puVar2 = operator_new(0x1c);

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2[1] = 0;

      puVar2[2] = 0;

      puVar2[3] = 0;

      puVar2[4] = 0;

      puVar2[5] = 0;

      *puVar2 = &PTR_FUN_00aa2f48;

      puVar2[6] = 0;

      puVar1 = puVar2;

    }

    FUN_0073ecf0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8));

    puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0xc);

    puVar5 = (uint32_t /* width from decompiler */ *)puVar1[3];

    for (uVar3 = *(uint *)(unaff_EBX + 0x14) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar5 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar5 = puVar5 + 1;

    }

    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {

      *(uint8_t *)puVar5 = *(uint8_t *)puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x10);

    puVar5 = (uint32_t /* width from decompiler */ *)puVar1[4];

    for (uVar3 = *(uint *)(unaff_EBX + 0x14) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar5 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar5 = puVar5 + 1;

    }

    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {

      *(uint8_t *)puVar5 = *(uint8_t *)puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

  }

  return puVar1;

}
