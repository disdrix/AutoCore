// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFa_00755f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00755f10
// Callee of Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog
// Address:   0x00755f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_00755f10×2, FUN_0074e310, FUN_0096d630.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFa_00755f10(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t auStack_1c [4];

  uint32_t /* width from decompiler */ *puStack_18;

  uint32_t /* width from decompiler */ *puStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ada87;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar2 = (**(code **)(*param_1 + 4))();

  if (iVar2 == 0x474c5442) {

    FUN_0074e310(param_1[0x23]);

  }

  puStack_18 = (uint32_t /* width from decompiler */ *)0x0;

  puStack_14 = (uint32_t /* width from decompiler */ *)0x0;

  uStack_10 = 0;

  uStack_4 = 0;

  FUN_0096d630(auStack_1c);

  puVar1 = puStack_14;

  for (puVar3 = puStack_18; puVar3 != puVar1; puVar3 = puVar3 + 1) {

    Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFa_00755f10(*puVar3);

  }

  if (puStack_18 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puStack_18);

  }

  ExceptionList = pvStack_c;

  return;

}
