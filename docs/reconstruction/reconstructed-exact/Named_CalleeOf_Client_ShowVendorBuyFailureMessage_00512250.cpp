// =============================================================================
// Named_CalleeOf_Client_ShowVendorBuyFailureMessage_00512250
// -----------------------------------------------------------------------------
// Stable ID: aa_00512250
// Callee of Client_ShowVendorBuyFailureMessage
// Address:   0x00512250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowVendorBuyFailureMessage: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00512250, __alldiv, __allmul, block.
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

/* WARNING: Removing unreachable block (ram,0x00512278) */



uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Client_ShowVendorBuyFailureMessage_00512250(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint64_t uVar3;

  longlong lVar4;

  

  iVar1 = (**(code **)(*param_1 + 0x168))();

  uVar3 = __allmul(iVar1,iVar1 >> 0x1f,3,0);

  lVar4 = __alldiv(uVar3,200,0);

  uVar2 = (uint32_t /* width from decompiler */)lVar4;

  if (lVar4 < 1) {

    uVar2 = 1;

  }

  return uVar2;

}
