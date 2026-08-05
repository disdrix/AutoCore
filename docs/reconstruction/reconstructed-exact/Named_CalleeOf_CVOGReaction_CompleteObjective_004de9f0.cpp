// =============================================================================
// Named_CalleeOf_CVOGReaction_CompleteObjective_004de9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004de9f0
// Callee of CVOGReaction_CompleteObjective
// Address:   0x004de9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_CompleteObjective: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: CVOGObject_SetInteractSpecialFX, FUN_004dbef0, FUN_004de9f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_CompleteObjective
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

void __fastcall Named_CalleeOf_CVOGReaction_CompleteObjective_004de9f0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  piVar4 = *(int **)(param_1 + 0xe720);

  if (piVar4 != *(int **)(param_1 + 0xe724)) {

    do {

      iVar2 = *piVar4;

      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

      iVar1 = iVar3 + iVar2;

      if (((*(uint *)(iVar3 + 0x3c + iVar2) & *(uint *)(iVar3 + 0x40 + iVar2)) != 0xffffffff) &&

         (*(int *)(*(int *)(iVar1 + 0xac) + 0x38) != 0x36)) {

        if (*(int *)(iVar1 + 0x134) != 0) {

          CVOGObject_SetInteractSpecialFX((void *)(iVar1 + 4),(void *)0x0);

        }

        iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4);

        iVar3 = iVar1 + iVar2;

        FUN_004dbef0(iVar3 + 4,0,*(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x40 + iVar2)

                     ,0xffffffff);

      }

      piVar4 = piVar4 + 1;

    } while (piVar4 != *(int **)(param_1 + 0xe724));

  }

  return;

}
