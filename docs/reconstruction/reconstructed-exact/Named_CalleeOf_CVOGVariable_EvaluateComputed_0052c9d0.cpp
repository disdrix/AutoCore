// =============================================================================
// Named_CalleeOf_CVOGVariable_EvaluateComputed_0052c9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052c9d0
// Callee of CVOGVariable_EvaluateComputed
// Address:   0x0052c9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGVariable_EvaluateComputed: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, do×1, while×1.
//  - Notable callees: CNDHash_LookupByKey×3, CVOGCharacter_HasCompletedMission, FUN_0052c9d0, FUN_0053fff0.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of CVOGVariable_EvaluateComputed
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

bool __thiscall Named_CalleeOf_CVOGVariable_EvaluateComputed_0052c9d0(void *param_1,uint param_2)



{

  uint *puVar1;

  int iVar2;

  uint uVar3;

  bool bVar4;

  int iVar5;

  void *pvVar6;

  void *pvVar7;

  void *pvVar8;

  int *piVar9;

  

  iVar5 = FUN_0053fff0();

  if (*(void **)(iVar5 + 4) != (void *)0x0) {

    pvVar6 = CNDHash_LookupByKey(*(void **)(iVar5 + 4),param_2);

    if (pvVar6 != (void *)0x0) {

      puVar1 = *(uint **)((int)pvVar6 + 0x14c);

      if (puVar1 == (uint *)0x0) {

        return false;

      }

      bVar4 = CVOGCharacter_HasCompletedMission(param_1,*puVar1);

      if (bVar4) {

        return true;

      }

      pvVar7 = CNDHash_LookupByKey(*(void **)((int)param_1 + 0x540),*puVar1);

      if (pvVar7 != (void *)0x0) {

        uVar3 = puVar1[0x4c];

        iVar5 = 0;

        if ((byte)uVar3 != 0) {

          pvVar7 = *(void **)((int)param_1 + 0x548);

          piVar9 = (int *)puVar1[0x4f];

          do {

            iVar2 = *piVar9;

            pvVar8 = CNDHash_LookupByKey(pvVar7,*(uint *)(iVar2 + 0x10));

            if (pvVar8 != (void *)0x0) {

              return *(byte *)((int)pvVar6 + 0x14) < *(byte *)(iVar2 + 0x14);

            }

            iVar5 = iVar5 + 1;

            piVar9 = piVar9 + 1;

          } while (iVar5 < (int)(uint)(byte)uVar3);

        }

      }

      return false;

    }

  }

  return false;

}
