// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUseItemRespon_008bf020
// -----------------------------------------------------------------------------
// Stable ID: aa_008bf020
// Callee of Named_CalleeOf_Client_RecvInventoryUseItemResponse
// Address:   0x008bf020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryUseItemResponse: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_008bee80×2, FUN_00410550, FUN_008bf020.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryUseItemResponse
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUseItemRespon_008bf020(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 0x52c);

  if (iVar1 != *(int *)(unaff_ESI + 0x530)) {

    while (*(int *)(iVar1 + 4) != param_2) {

      iVar1 = iVar1 + 8;

      if (iVar1 == *(int *)(unaff_ESI + 0x530)) {

        FUN_008bee80(param_1);

        return;

      }

    }

    FUN_00410550(iVar1);

  }

  FUN_008bee80(param_1);

  return;

}
