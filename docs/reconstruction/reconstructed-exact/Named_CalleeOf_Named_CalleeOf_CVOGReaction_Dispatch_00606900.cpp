// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00606900
// -----------------------------------------------------------------------------
// Stable ID: aa_00606900
// Callee of Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x00606900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_00606900.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00606900(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  uint uVar5;

  

  if ((-1 < param_2) && (param_2 < 4)) {

    iVar1 = param_1 + param_2 * 0x48;

    for (uVar5 = 0;

        (iVar3 = *(int *)(iVar1 + 0xb4), iVar3 != 0 &&

        (uVar5 < (uint)(*(int *)(iVar1 + 0xb8) - iVar3 >> 3))); uVar5 = uVar5 + 1) {

      iVar2 = uVar5 * 8;

      CVOGReaction_SpawnObject

                (*(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),

                 *(uint32_t /* width from decompiler */ *)(iVar3 + iVar2),*(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar2));

      if ((*(char *)(iVar1 + 0xf4) == '\0') &&

         ((piVar4 = (int *)CVOGReaction_ResolveObjectTarget

                                     (0,*(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xb4) + iVar2),

                                      *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xb4) + 4 + iVar2)),

          piVar4 != (int *)0x0 &&

          (piVar4 = (int *)(**(code **)(*piVar4 + 0x1ec))(), piVar4 != (int *)0x0)))) {

        iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);

        (**(code **)(*piVar4 + 0x48))

                  (*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + param_1),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + param_1)

                  );

      }

    }

    if (*(char *)(iVar1 + 0xf4) == '\0') {

      *(uint8_t *)(iVar1 + 0xf4) = 1;

    }

  }

  return;

}
