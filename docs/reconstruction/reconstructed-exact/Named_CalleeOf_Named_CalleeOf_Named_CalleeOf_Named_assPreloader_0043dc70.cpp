// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043dc70
// -----------------------------------------------------------------------------
// Stable ID: aa_0043dc70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assPreloader
// Address:   0x0043dc70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_0043ddf0×2, FUN_0043dc70, FUN_0044aa90.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_assPreloader
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043dc70(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint *unaff_EBX;

  bool bVar4;

  

  puVar1 = param_1;

  puVar3 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  bVar4 = true;

  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      puVar3 = puVar2;

      bVar4 = *unaff_EBX < (uint)puVar3[3];

      if (bVar4) {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar3[2];

      }

    } while (*(char *)((int)puVar2 + 0x19) == '\0');

  }

  param_1 = puVar3;

  if (bVar4) {

    if (puVar3 == (uint32_t /* width from decompiler */ *)**(int **)(in_EAX + 4)) {

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_0043ddf0(&param_1,1,puVar3,unaff_EBX);

      *puVar1 = *puVar3;

      *(uint8_t *)(puVar1 + 1) = 1;

      return puVar1;

    }

    FUN_0044aa90();

  }

  if ((uint)param_1[3] < *unaff_EBX) {

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0043ddf0(&param_1,bVar4,puVar3,unaff_EBX);

    *puVar1 = *puVar3;

    *(uint8_t *)(puVar1 + 1) = 1;

    return puVar1;

  }

  *puVar1 = param_1;

  *(uint8_t *)(puVar1 + 1) = 0;

  return puVar1;

}
