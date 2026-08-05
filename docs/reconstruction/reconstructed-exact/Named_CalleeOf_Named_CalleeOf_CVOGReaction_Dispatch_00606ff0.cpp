// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00606ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00606ff0
// Callee of Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x00606ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_00606ff0.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00606ff0(int param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  uint uVar5;

  int local_4;

  

  if ((-1 < (int)param_2) && ((int)param_2 < 4)) {

    param_1 = param_1 + param_2 * 0x48;

    local_4 = 0;

    for (param_2 = 0;

        (iVar2 = *(int *)(param_1 + 0xd4), iVar2 != 0 &&

        (param_2 < (uint)(*(int *)(param_1 + 0xd8) - iVar2 >> 4))); param_2 = param_2 + 1) {

      if (*(char *)((uint32_t /* width from decompiler */ *)(iVar2 + local_4) + 3) == '\0') {

        for (uVar5 = 0;

            (iVar4 = *(int *)(param_1 + 0xb4), iVar4 != 0 &&

            (uVar5 < (uint)(*(int *)(param_1 + 0xb8) - iVar4 >> 3))); uVar5 = uVar5 + 1) {

          puVar1 = (uint32_t /* width from decompiler */ *)(iVar4 + uVar5 * 8);

          piVar3 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar1,puVar1[1]);

          if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x1ec))(), iVar4 != 0)) {

            (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x220))

                      (*(uint32_t /* width from decompiler */ *)(iVar2 + local_4),1);

          }

        }

      }

      local_4 = local_4 + 0x10;

    }

  }

  return;

}
