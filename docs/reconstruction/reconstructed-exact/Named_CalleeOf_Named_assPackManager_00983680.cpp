// =============================================================================
// Named_CalleeOf_Named_assPackManager_00983680
// -----------------------------------------------------------------------------
// Stable ID: aa_00983680
// Callee of Named_assPackManager
// Address:   0x00983680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0044e8c0, FUN_00983680.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_assPackManager
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_assPackManager_00983680(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  int *unaff_retaddr;

  uint32_t /* width from decompiler */ *local_4;

  

  FUN_0044e8c0(&local_4);

  puVar4 = local_4;

  if ((local_4 != *(uint32_t /* width from decompiler */ **)(in_EAX + 8)) &&

     (puVar1 = local_4 + 3, puVar1 != (uint32_t /* width from decompiler */ *)0x0)) {

    piVar6 = (int *)local_4[9];

    if (param_3 != '\0') {

      piVar6 = piVar6 + 5;

    }

    puVar5 = operator_new(0x20);

    if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar5 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      uVar2 = puVar4[4];

      uVar3 = *puVar1;

      *puVar5 = &PTR_FUN_00aa6034;

      puVar5[1] = piVar6;

      puVar5[2] = uVar2;

      puVar5[3] = uVar3;

      *(uint8_t *)(puVar5 + 4) = 1;

      puVar5[5] = uVar3;

      puVar5[6] = 0;

      puVar5[7] = 0;

    }

    (**(code **)(*piVar6 + 4))(*puVar1,0);

    *local_4 = puVar4[4];

    *unaff_retaddr = (int)*(short *)(puVar4 + 8);

    return puVar5;

  }

  return (uint32_t /* width from decompiler */ *)0x0;

}
