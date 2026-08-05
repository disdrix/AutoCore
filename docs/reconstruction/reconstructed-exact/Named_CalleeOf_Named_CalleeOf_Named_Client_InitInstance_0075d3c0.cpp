// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0075d3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d3c0
// Callee of Named_CalleeOf_Named_Client_InitInstance (+1 other named callers)
// Address:   0x0075d3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_Client_InitInstance (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0043e7f0, FUN_0043e8f0, FUN_0075d3c0, FUN_00970cf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0075d3c0(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009acd06;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x6c) == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x114);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_00970cf0();

    }

    local_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = uVar2;

    piVar3 = (int *)**(int **)(param_1 + 8);

    if (piVar3 != *(int **)(param_1 + 8)) {

      do {

        FUN_0043e8f0();

        FUN_0043e7f0();

        piVar3 = (int *)*piVar3;

      } while (piVar3 != (int *)*(int *)(param_1 + 8));

    }

  }

  ExceptionList = local_c;

  return;

}
