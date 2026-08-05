// =============================================================================
// Named_CalleeOf_Named_phyCPDefinition_0044b0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b0b0
// Callee of Named_phyCPDefinition
// Address:   0x0044b0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_phyCPDefinition: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0044b0b0, FUN_009892d0, FUN_009895c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_phyCPDefinition
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_phyCPDefinition_0044b0b0(void)



{

  int *piVar1;

  int *piVar2;

  void *pvVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009befeb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar3 = operator_new(0x3c);

  local_4 = 0;

  if (pvVar3 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_009892d0(pvVar3);

  }

  local_4 = 0xffffffff;

  if (piVar4 != (int *)0x0) {

    piVar4[1] = piVar4[1] + 1;

    if (piVar4[1] == 1) {

      (**(code **)(*piVar4 + 4))();

    }

    piVar2 = (int *)*unaff_EDI;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *unaff_EDI = (int)piVar4;

    uVar5 = FUN_009895c0();

    ExceptionList = local_c;

    return uVar5;

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
