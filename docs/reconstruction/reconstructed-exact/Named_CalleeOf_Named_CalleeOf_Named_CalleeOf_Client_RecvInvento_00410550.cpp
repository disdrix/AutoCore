// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_00410550
// -----------------------------------------------------------------------------
// Stable ID: aa_00410550
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUseItemRespon
// Address:   0x00410550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUseItemRespon: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00410550.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUseItemRespon
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_00410550(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EDI;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 8);

  puVar3 = param_1;

  puVar2 = param_1;

  while (puVar2 = puVar2 + 2, puVar2 != puVar1) {

    *puVar3 = *puVar2;

    puVar3[1] = puVar2[1];

    puVar3 = puVar3 + 2;

  }

  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + -8;

  *in_EAX = param_1;

  return;

}
