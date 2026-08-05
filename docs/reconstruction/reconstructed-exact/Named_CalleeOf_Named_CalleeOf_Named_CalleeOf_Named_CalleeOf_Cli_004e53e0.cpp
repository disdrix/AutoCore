// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004e53e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e53e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
// Address:   0x004e53e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00418130, FUN_004e53e0, FUN_006a2be0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004e53e0(int param_1,int param_2)



{

  uint uVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a2540;

  local_10 = ExceptionList;

  if (*(int *)(param_2 + 4) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 3;

  }

  ExceptionList = &local_10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  if (uVar1 != 0) {

    if (0x1fffffff < uVar1) {

      uVar1 = FUN_00418130();

    }

    pvVar2 = operator_new(uVar1 * 8);

    *(void **)(param_1 + 4) = pvVar2;

    *(void **)(param_1 + 8) = pvVar2;

    *(void **)(param_1 + 0xc) = (void *)(uVar1 * 8 + (int)pvVar2);

    local_8 = 0;

    uVar3 = FUN_006a2be0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),pvVar2,param_1,

                         param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

  }

  ExceptionList = local_10;

  return param_1;

}
