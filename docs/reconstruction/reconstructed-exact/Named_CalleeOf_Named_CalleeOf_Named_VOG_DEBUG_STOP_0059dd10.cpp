// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dd10
// -----------------------------------------------------------------------------
// Stable ID: aa_0059dd10
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0059dd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, while×1.
//  - Notable callees: FUN_0059dd10.
//  - Return sites: 2.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dd10(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a5c9e;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if ((void *)*param_1 != (void *)0x0) {

    ExceptionList = &pvStack_c;

    operator_delete__((void *)*param_1);

  }

  *param_1 = 0;

  if ((void *)param_1[2] != (void *)0x0) {

    operator_delete__((void *)param_1[2]);

  }

  param_1[2] = 0;

  if ((void *)param_1[1] != (void *)0x0) {

    operator_delete__((void *)param_1[1]);

  }

  param_1[1] = 0;

  uVar3 = 0;

  while( true ) {

    iVar1 = param_1[0x56];

    if ((iVar1 == 0) || ((uint)(param_1[0x57] - iVar1 >> 2) <= uVar3)) break;

    puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + uVar3 * 4);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar2)(1);

    }

    uVar3 = uVar3 + 1;

  }

  if ((void *)param_1[0x56] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x56]);

  }

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  param_1[0x58] = 0;

  ExceptionList = pvStack_c;

  return;

}
