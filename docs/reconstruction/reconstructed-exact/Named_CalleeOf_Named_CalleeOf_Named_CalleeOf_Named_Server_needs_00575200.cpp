// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_00575200
// -----------------------------------------------------------------------------
// Stable ID: aa_00575200
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers)
// Address:   0x00575200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_00520330, FUN_00575200.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_00575200(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int *piVar3;

  int iVar4;

  

  piVar3 = (int *)(param_1 + 0x1a0);

  iVar4 = 4;

  do {

    if (*piVar3 != 0) {

      FUN_00520330(0);

    }

    *piVar3 = 0;

    piVar3[-2] = -1;

    piVar3[-1] = -1;

    piVar3 = piVar3 + 4;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  piVar3 = (int *)**(int **)(param_1 + 0x1e0);

  if (piVar3 != *(int **)(param_1 + 0x1e0)) {

    do {

      if (piVar3[4] != 0) {

        *(uint32_t /* width from decompiler */ *)(piVar3[4] + 0xcb4) = 0;

      }

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)*(int *)(param_1 + 0x1e0));

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1e0);

  pvVar2 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(int *)(*(int *)(param_1 + 0x1e0) + 4) = *(int *)(param_1 + 0x1e0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e4) = 0;

  if (pvVar2 != *(void **)(param_1 + 0x1e0)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = 0;

  *(uint8_t *)(param_1 + 0x1d8) = 0;

  return;

}
