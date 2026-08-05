// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_0048c470
// -----------------------------------------------------------------------------
// Stable ID: aa_0048c470
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x0048c470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_0048b1c0, FUN_0048c020, FUN_0048c470, sscanf.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
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

byte Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_0048c470(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0668;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0048c020(param_1);

  iVar1 = FUN_0048b1c0(&param_1);

  if (iVar1 != 0) {

    iVar1 = sscanf((char *)(*(int *)(iVar1 + 0x18) + 8),"%d",param_2);

    local_4 = 0xffffffff;

    if (param_1 != &DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

      operator_delete(param_1);

    }

    ExceptionList = local_c;

    return -(iVar1 != 1) & 2;

  }

  local_4 = 0xffffffff;

  if (param_1 != &DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  ExceptionList = local_c;

  return 1;

}
