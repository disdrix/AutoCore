// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0055b0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055b0e0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0055b0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×9, return×6, while×1, goto×1.
//  - Notable callees: FUN_0055a6f0, FUN_0055aec0, FUN_0055b0e0, FUN_0055c710.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0055b0e0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  int *piVar5;

  uint8_t local_48 [4];

  void *local_44;

  int local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint8_t local_38 [4];

  void *local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  float local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a48f0;

  local_c = ExceptionList;

  uVar4 = 0;

  local_34 = (void *)0x0;

  local_30 = 0;

  local_2c = 0;

  local_44 = (void *)0x0;

  local_40 = 0;

  local_3c = 0;

  local_4 = 1;

  ExceptionList = &local_c;

  cVar2 = FUN_0055aec0(param_2,local_38,local_48);

  pvVar1 = local_34;

  if (cVar2 == '\0') {

    if (local_44 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_44);

    }

    if (local_34 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_34);

    }

    ExceptionList = local_c;

    return 0;

  }

  piVar5 = (int *)((int)local_44 + 4);

  while( true ) {

    if (local_44 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = local_40 - (int)local_44 >> 2;

    }

    if (uVar3 / 3 <= uVar4) break;

    FUN_0055a6f0((void *)((int)pvVar1 + piVar5[-1] * 0xc),(void *)((int)pvVar1 + *piVar5 * 0xc),

                 (void *)((int)pvVar1 + piVar5[1] * 0xc));

    uVar4 = uVar4 + 1;

    piVar5 = piVar5 + 3;

  }

  if (*(int *)(param_1 + 0x18) != 0) {

    if ((*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)) / 0x1c != 0) goto LAB_0055b235;

  }

  local_20 = 0;

  local_24 = 0;

  local_28 = 0;

  local_1c = 0;

  local_18 = 0;

  local_14 = 0;

  local_10 = g_flOne;

  FUN_0055c710(&local_28);

LAB_0055b235:

  if (local_44 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_44);

  }

  if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  ExceptionList = local_c;

  return 1;

}
