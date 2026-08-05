// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0046f810
// -----------------------------------------------------------------------------
// Stable ID: aa_0046f810
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0046f810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_0043c2e0×2, FUN_0044aa90, FUN_0046f810.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0046f810(uint32_t /* width from decompiler */ *param_1)



{

  bool bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *unaff_EBX;

  

  puVar2 = param_1;

  puVar4 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  bVar1 = true;

  if (*(char *)((int)puVar4[1] + 0x19) == '\0') {

    puVar3 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      puVar4 = puVar3;

      bVar1 = *unaff_EBX < (int)puVar4[3];

      if (bVar1) {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar4;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar4[2];

      }

    } while (*(char *)((int)puVar3 + 0x19) == '\0');

  }

  param_1 = puVar4;

  if (bVar1) {

    if (puVar4 == (uint32_t /* width from decompiler */ *)**(int **)(in_EAX + 4)) {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0043c2e0(&param_1,1,puVar4,unaff_EBX);

      *puVar2 = *puVar4;

      *(uint8_t *)(puVar2 + 1) = 1;

      return puVar2;

    }

    FUN_0044aa90();

  }

  if ((int)param_1[3] < *unaff_EBX) {

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_0043c2e0(&param_1,bVar1,puVar4,unaff_EBX);

    *puVar2 = *puVar4;

    *(uint8_t *)(puVar2 + 1) = 1;

    return puVar2;

  }

  *puVar2 = param_1;

  *(uint8_t *)(puVar2 + 1) = 0;

  return puVar2;

}
