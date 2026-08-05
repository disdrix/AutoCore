// =============================================================================
// Named_CalleeOf_Client_ShowVendorBuyFailureMessage_00521ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00521ad0
// Callee of Client_ShowVendorBuyFailureMessage
// Address:   0x00521ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowVendorBuyFailureMessage: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005711c0×2, FUN_00521ad0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_ShowVendorBuyFailureMessage
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

void __fastcall Named_CalleeOf_Client_ShowVendorBuyFailureMessage_00521ad0(int param_1)



{

  int iVar1;

  char cVar2;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if (iVar1 == 0) {

    cVar2 = '\0';

  }

  else {

    cVar2 = *(char *)(iVar1 + 0xf5);

  }

  if ((*(int *)(param_1 + 0x250) != 0) && (*(int *)(*(int *)(param_1 + 0x250) + 0x2b0) != 0)) {

    FUN_005711c0(0x21a3,0);

  }

  if ((cVar2 != '\0') && (*(int *)(param_1 + 0xcbc) != 0)) {

    FUN_005711c0(0x21a3,0);

  }

  return;

}
