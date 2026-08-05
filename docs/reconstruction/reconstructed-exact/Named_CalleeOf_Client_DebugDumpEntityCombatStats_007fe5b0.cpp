// =============================================================================
// Named_CalleeOf_Client_DebugDumpEntityCombatStats_007fe5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe5b0
// Callee of Client_DebugDumpEntityCombatStats
// Address:   0x007fe5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_DebugDumpEntityCombatStats: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00419760, FUN_00419b40, FUN_007fe5b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_DebugDumpEntityCombatStats
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

void Named_CalleeOf_Client_DebugDumpEntityCombatStats_007fe5b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  

  if (*(int *)(param_1 + 0x3084) != 0) {

    iVar2 = FUN_00419b40(param_2,param_3);

    if (iVar2 == 0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = *(int **)(iVar2 + 0xc);

    }

    if (piVar3 != (int *)0x0) {

      cVar1 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*piVar3 + 0x440))();

      }

      if (piVar3[0xac] != 0) {

        (**(code **)(*(int *)piVar3[0xac] + 0xb0))(piVar3);

      }

      FUN_00419760(param_2,param_3);

    }

  }

  return;

}
