// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0096d630
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d630
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFa
// Address:   0x0096d630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFa: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_0096d630×2, FUN_00456960.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFa
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0096d630(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  

  piVar1 = *(int **)(param_1 + 0x70);

  for (piVar4 = *(int **)(param_1 + 0x6c); piVar4 != piVar1; piVar4 = piVar4 + 1) {

    iVar2 = *(int *)(param_2 + 4);

    if ((iVar2 == 0) ||

       ((uint)(*(int *)(param_2 + 0xc) - iVar2 >> 2) <= (uint)(*(int *)(param_2 + 8) - iVar2 >> 2)))

    {

      FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_2 + 8));

    }

    else {

      puVar3 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

      *puVar3 = *(uint32_t /* width from decompiler */ *)(*piVar4 + 8);

      *(uint32_t /* width from decompiler */ **)(param_2 + 8) = puVar3 + 1;

    }

    Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0096d630(param_2);

  }

  return;

}
