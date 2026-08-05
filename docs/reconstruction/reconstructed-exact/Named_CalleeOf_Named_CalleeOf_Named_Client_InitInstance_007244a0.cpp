// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_007244a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007244a0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x007244a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00480230, FUN_0071aef0, FUN_007242c0, FUN_007244a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

void Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_007244a0(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af11c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint8_t *)(unaff_EDI + 600) = 0;

  if (*(int *)(unaff_EDI + 0x30c) == 0) {

    pvVar2 = operator_new(0x24);

    local_4 = 0;

    if (pvVar2 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_00480230(pvVar2);

    }

    local_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x30c) = uVar3;

    cVar1 = FUN_0071aef0();

    if (cVar1 != '\0') {

      FUN_007242c0(param_1);

    }

  }

  ExceptionList = local_c;

  return;

}
