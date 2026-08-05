// =============================================================================
// Named_CalleeOf_Named_EDIT_BOX_007932d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007932d0
// Callee of Named_EDIT_BOX
// Address:   0x007932d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_EDIT_BOX: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00428220, FUN_00428560, FUN_007932d0, FUN_0079c860, NDUIWindow_ApplyXmlNodeAttributes.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_EDIT_BOX
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

void Named_CalleeOf_Named_EDIT_BOX_007932d0(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b800d;

  local_c = ExceptionList;

  if (*(int *)(unaff_EDI + 0x4cc) != 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x4cc);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      piVar2 = (int *)0x0;

    }

    else {

      piVar2 = (int *)FUN_0079c860();

    }

    local_4 = 0xffffffff;

    NDUIWindow_ApplyXmlNodeAttributes(param_1,0,0);

    (**(code **)(*piVar2 + 0x28))(0);

    iVar3 = FUN_00428560(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x4cc),piVar2,0);

    if (-1 < iVar3) {

      *(int *)(unaff_EDI + 0x4ec) = *(int *)(unaff_EDI + 0x4ec) + 1;

    }

    iVar3 = FUN_00428220(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x4d8),piVar2,0);

    if (-1 < iVar3) {

      *(int *)(unaff_EDI + 0x4f8) = *(int *)(unaff_EDI + 0x4f8) + 1;

    }

  }

  ExceptionList = local_c;

  return;

}
