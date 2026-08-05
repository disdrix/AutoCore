// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj_00421aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00421aa0
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride
// Address:   0x00421aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0041d7b0×2, FUN_00421aa0, FUN_00437cd0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj_00421aa0(int *param_1,uint32_t /* width from decompiler */ param_2,uint8_t *param_3,int param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  int iVar2;

  int unaff_EBX;

  int iVar3;

  uint8_t local_4 [4];

  

  if (unaff_EBX != 0) {

    iVar3 = param_4;

    if (param_4 == 0) {

      iVar3 = 1;

    }

    FUN_00437cd0();

    iVar2 = (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x24))

                      (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x24),&DAT_00a860e8,&param_4);

    if (iVar2 < 0) {

      FUN_0041d7b0();

      return iVar2;

    }

    iVar3 = (**(code **)(*param_1 + 0x10))(param_1,iVar3);

    FUN_0041d7b0();

    if (iVar3 < 0) {

      return iVar3;

    }

  }

  if (param_3 == (uint8_t *)0x0) {

    param_3 = local_4;

  }

  iVar3 = (**(code **)(**(int **)(in_EAX + 0x24) + 0x10))

                    (*(int **)(in_EAX + 0x24),0,&DAT_00a8608c,param_2,param_3,param_1);

  if ((-1 < iVar3) && (puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x10), puVar1 != (uint32_t /* width from decompiler */ *)0x0)) {

    (**(code **)*puVar1)(puVar1,&DAT_00a860f8,in_EAX + 0x14);

  }

  return iVar3;

}
