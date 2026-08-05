// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00800d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00800d80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00800d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00411180, FUN_00800d80, FUN_0097a8e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00800d80(int param_1,int param_2)



{

  int iVar1;

  void *pvVar2;

  int unaff_EBX;

  int *piVar3;

  float10 fVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b805e;

  local_c = ExceptionList;

  piVar3 = (int *)0x0;

  if (((param_1 != 0) && (param_2 != 0)) && (*(int *)(unaff_EBX + 0xf40) != 0)) {

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x544);

    local_4 = 0;

    if (pvVar2 != (void *)0x0) {

      piVar3 = (int *)FUN_0097a8e0(pvVar2);

    }

    local_4 = 0xffffffff;

    (**(code **)(*piVar3 + 0x28))(param_1);

    if (**(int **)(unaff_EBX + 0xf40) != 0) {

      (**(code **)(*(int *)**(int **)(unaff_EBX + 0xf40) + 0xa8))(piVar3);

    }

    (**(code **)(*piVar3 + 0x43c))();

    iVar1 = *piVar3;

    fVar4 = (float10)(**(code **)(iVar1 + 0xf4))();

    (**(code **)(iVar1 + 0xfc))(1,(float)fVar4);

    (**(code **)(*piVar3 + 0x448))(param_2,1);

    FUN_00411180();

  }

  ExceptionList = local_c;

  return;

}
