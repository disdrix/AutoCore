// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00986070
// -----------------------------------------------------------------------------
// Stable ID: aa_00986070
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00986070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00456780×2, FUN_004406e0, FUN_0074e380, FUN_00986070.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00986070(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_EBX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af9d3;

  local_c = ExceptionList;

  if ((*(int *)(unaff_EBX + 0x14) == 0) ||

     (*(int *)(unaff_EBX + 0x18) - *(int *)(unaff_EBX + 0x14) >> 2 == 0)) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x40);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0074e380(pvVar1);

    }

    local_4 = 0xffffffff;

  }

  else {

    uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBX + 0x18) + -4);

    if (*(int *)(unaff_EBX + 0x14) == 0) {

      ExceptionList = &local_c;

      FUN_00456780(0);

    }

    else {

      ExceptionList = &local_c;

      FUN_00456780(0);

    }

  }

  FUN_004406e0();

  ExceptionList = local_c;

  return uVar2;

}
