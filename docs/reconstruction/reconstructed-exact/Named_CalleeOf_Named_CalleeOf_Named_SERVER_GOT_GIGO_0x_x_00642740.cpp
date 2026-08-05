// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00642740
// -----------------------------------------------------------------------------
// Stable ID: aa_00642740
// Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
// Address:   0x00642740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0055fe50, FUN_005d69a0, FUN_00642740, FUN_00658bb0, FUN_00658bf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00642740(int param_1,uint8_t *param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  iVar1 = *(int *)(param_3 + 0x20);

  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x40) == '\0')) {

    FUN_005d69a0(*(int *)(iVar1 + 0x3c) + 0x80,param_5);

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x50,0x24);

    *(uint16_t *)(iVar2 + 4) = 0x50;

    uVar3 = FUN_00658bf0(&stack0xffffffd8,param_5,0x3f000000,0x3e99999a,0x3f733333,iVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar3;

    FUN_00658bb0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

    FUN_0055fe50(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

  }

  *param_2 = 1;

  return;

}
