// =============================================================================
// Named_CalleeOf_Named_effVertexDecl_0044ca50
// -----------------------------------------------------------------------------
// Stable ID: aa_0044ca50
// Callee of Named_effVertexDecl
// Address:   0x0044ca50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effVertexDecl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00418130, FUN_00448e90, FUN_0044ca50.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_effVertexDecl
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

void __fastcall Named_CalleeOf_Named_effVertexDecl_0044ca50(int param_1,uint param_2)



{

  uint uVar1;

  void *pvVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd420;

  local_10 = ExceptionList;

  if (0x1fffffff < param_2) {

    ExceptionList = &local_10;

    FUN_00418130();

    return;

  }

  if (*(int *)(param_1 + 4) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) >> 3;

  }

  if (uVar1 < param_2) {

    ExceptionList = &local_10;

    pvVar2 = operator_new(param_2 * 8);

    local_8 = 0;

    FUN_00448e90(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),pvVar2);

    if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 4));

    }

    *(void **)(param_1 + 0xc) = (void *)(param_2 * 8 + (int)pvVar2);

    *(void **)(param_1 + 8) = pvVar2;

    *(void **)(param_1 + 4) = pvVar2;

  }

  ExceptionList = local_10;

  return;

}
