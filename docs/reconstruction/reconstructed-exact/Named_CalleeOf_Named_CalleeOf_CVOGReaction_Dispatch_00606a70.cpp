// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00606a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00606a70
// Callee of Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x00606a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_00606a70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_Dispatch
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00606a70(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int *piVar2;

  uint uVar3;

  

  if ((-1 < param_2) && (param_2 < 4)) {

    param_1 = param_1 + param_2 * 0x48;

    for (uVar3 = 0;

        (iVar1 = *(int *)(param_1 + 0xe4), iVar1 != 0 &&

        (uVar3 < (uint)(*(int *)(param_1 + 0xe8) - iVar1 >> 3))); uVar3 = uVar3 + 1) {

      piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                                (0,*(uint32_t /* width from decompiler */ *)(iVar1 + uVar3 * 8),

                                 *(uint32_t /* width from decompiler */ *)(iVar1 + uVar3 * 8 + 4));

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 0x114))(param_3);

      }

    }

  }

  return;

}
