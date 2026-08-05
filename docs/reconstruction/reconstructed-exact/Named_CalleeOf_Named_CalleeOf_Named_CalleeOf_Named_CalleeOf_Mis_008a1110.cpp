// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_008a1110
// -----------------------------------------------------------------------------
// Stable ID: aa_008a1110
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
// Address:   0x008a1110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00826150, FUN_00828980, FUN_008a1110.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_008a1110(void)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *unaff_EDI;

  uint8_t auStack_20 [20];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b6114;

  local_c = ExceptionList;

  if (unaff_EDI[0x130] != 0) {

    iVar2 = 0;

    piVar3 = unaff_EDI + 399;

    ExceptionList = &local_c;

    do {

      (**(code **)(*unaff_EDI + 0xbc))(*piVar3);

      pvVar1 = operator_new(0x688);

      piVar4 = (int *)0x0;

      puStack_8 = (uint8_t *)0x0;

      if (pvVar1 != (void *)0x0) {

        piVar4 = (int *)FUN_00828980(pvVar1);

      }

      puStack_8 = (uint8_t *)0xffffffff;

      (**(code **)(*unaff_EDI + 0xa8))(piVar4);

      (**(code **)(*piVar4 + 0x74))(iVar2 + 0x9c48);

      (**(code **)(*piVar4 + 0x134))(auStack_20);

      (**(code **)(*piVar4 + 0x118))(&stack0xffffffd4);

      (**(code **)(*piVar4 + 0x43c))();

      FUN_00826150();

      piVar4[0x141] = unaff_EDI[0x143];

      (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

      *piVar3 = (int)piVar4;

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar2 < 10);

  }

  ExceptionList = local_c;

  return;

}
