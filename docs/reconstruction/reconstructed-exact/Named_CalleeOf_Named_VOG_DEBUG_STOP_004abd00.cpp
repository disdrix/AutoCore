// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004abd00
// -----------------------------------------------------------------------------
// Stable ID: aa_004abd00
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x004abd00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004aac50, FUN_004abd00, FUN_00764030, FUN_0096f510.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_004abd00(int param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a12f5;

  pvStack_c = ExceptionList;

  pvVar1 = *(void **)(param_1 + 0x394);

  if (pvVar1 != (void *)0x0) {

    ExceptionList = &pvStack_c;

    FUN_0096f510();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  ExceptionList = &pvStack_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x394) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x390) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x390))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x390) = 0;

  if (DAT_00b03e64 != '\0') {

    FUN_004aac50();

  }

  pvVar1 = operator_new(0x14c);

  uStack_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00764030();

  }

  *(int *)(param_1 + 0x390) = iVar2;

  *(uint8_t *)(iVar2 + 0x139) = 1;

  ExceptionList = pvStack_c;

  return;

}
