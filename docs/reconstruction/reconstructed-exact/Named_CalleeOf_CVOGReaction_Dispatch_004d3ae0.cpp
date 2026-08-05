// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_004d3ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3ae0
// Callee of CVOGReaction_Dispatch
// Address:   0x004d3ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004d3ae0, FUN_004e29c0, FUN_004e29f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch
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

void __thiscall Named_CalleeOf_CVOGReaction_Dispatch_004d3ae0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  

  if ((*(char *)(param_1 + 0x82) != '\0') && (param_2 != 0)) {

    local_20 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x160);

    local_1c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x164);

    if (param_3 == 0) {

      local_30 = DAT_009cbf68;

      local_2c = DAT_009cbf6c;

      local_24 = DAT_009cbf74;

      local_28 = DAT_009cbf70;

    }

    else {

      local_30 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x160);

      local_2c = *(uint32_t /* width from decompiler */ *)(param_3 + 0x164);

      local_24 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x16c);

      local_28 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x168);

    }

    iVar1 = *(int *)(param_1 + 0xe8e8);

    iVar2 = FUN_004e29c0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&local_30);

    FUN_004e29f0(1);

    *(int *)(iVar1 + 4) = iVar2;

    **(int **)(iVar2 + 4) = iVar2;

  }

  return;

}
