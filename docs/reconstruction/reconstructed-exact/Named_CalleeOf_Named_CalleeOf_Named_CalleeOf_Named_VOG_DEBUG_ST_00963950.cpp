// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00963950
// -----------------------------------------------------------------------------
// Stable ID: aa_00963950
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00963950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_00448f50, FUN_00456960, FUN_00963950.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00963950(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  if (*(int *)(param_1 + 0xc) == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2;

  }

  uVar5 = 0;

  if (uVar6 != 0) {

    do {

      piVar1 = *(int **)(*(int *)(param_1 + 0xc) + uVar5 * 4);

      if (piVar1 != (int *)0x0) {

        uVar4 = (**(code **)(*piVar1 + 0x1c))();

        iVar2 = *(int *)(in_EAX + 4);

        if ((iVar2 == 0) ||

           ((uint)(*(int *)(in_EAX + 0xc) - iVar2 >> 2) <= (uint)(*(int *)(in_EAX + 8) - iVar2 >> 2)

           )) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(in_EAX + 8));

        }

        else {

          puVar7 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

          *puVar7 = uVar4;

          *(uint32_t /* width from decompiler */ **)(in_EAX + 8) = puVar7 + 1;

        }

      }

      uVar5 = uVar5 + 1;

    } while (uVar5 < uVar6);

  }

  FUN_00448f50();

  puVar3 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

  for (puVar7 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4); puVar7 != puVar3; puVar7 = puVar7 + 1) {

    (**(code **)(*(int *)*puVar7 + 0x20))(param_1 + 0x18);

  }

  return 0;

}
