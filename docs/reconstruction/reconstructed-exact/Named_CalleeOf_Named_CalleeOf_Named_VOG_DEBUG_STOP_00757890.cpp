// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00757890
// -----------------------------------------------------------------------------
// Stable ID: aa_00757890
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00757890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_004148e0, FUN_00440230, FUN_00440450, FUN_00440560, FUN_00757050, FUN_00757890.
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

uint32_t /* width from decompiler */

Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00757890(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int *param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  int iVar2;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_1c;

  uint8_t local_18;

  uint8_t local_17;

  uint8_t local_16;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1bc2;

  pvStack_c = ExceptionList;

  local_1c = 0;

  local_18 = 0;

  local_17 = 0;

  local_16 = 0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  FUN_004148e0(param_5);

  iVar2 = *param_3;

  if (iVar2 != 0) {

    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;

    if (*(int *)(iVar2 + 8) == 1) {

      (**(code **)(*(int *)(iVar2 + 4) + 4))();

    }

  }

  if (local_14 != 0) {

    piVar1 = (int *)(local_14 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(local_14 + 4) + 8))();

    }

  }

  local_14 = iVar2;

  if (param_4 == 1) {

    iVar2 = FUN_00440560(unaff_EDI + 0x68);

  }

  else {

    iVar2 = unaff_EDI + 4;

  }

  FUN_00440450(iVar2);

  FUN_00757050(unaff_EDI,param_2);

  local_4 = 0xffffffff;

  FUN_00440230(&local_1c);

  ExceptionList = pvStack_c;

  return 0;

}
