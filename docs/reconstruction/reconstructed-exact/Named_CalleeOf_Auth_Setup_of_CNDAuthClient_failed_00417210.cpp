// =============================================================================
// Named_CalleeOf_Auth_Setup_of_CNDAuthClient_failed_00417210
// -----------------------------------------------------------------------------
// Stable ID: aa_00417210
// Callee of Auth_Setup_of_CNDAuthClient_failed
// Address:   0x00417210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Auth_Setup_of_CNDAuthClient_failed: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00417210, FUN_00417340, FUN_004433a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Auth_Setup_of_CNDAuthClient_failed
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

void Named_CalleeOf_Auth_Setup_of_CNDAuthClient_failed_00417210(uint32_t /* width from decompiler */ param_1)



{

  uint in_EAX;

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  

  iVar2 = *(int *)(unaff_EDI + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = (*(int *)(unaff_EDI + 8) - iVar2) / 0x14;

  }

  if (uVar1 < in_EAX) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(unaff_EDI + 8) - iVar2) / 0x14;

    }

    FUN_00417340(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),in_EAX - iVar2,&param_1);

    return;

  }

  if (iVar2 != 0) {

    if ((in_EAX < (uint)((*(int *)(unaff_EDI + 8) - iVar2) / 0x14)) &&

       (iVar2 + in_EAX * 0x14 != *(int *)(unaff_EDI + 8))) {

      uVar3 = FUN_004433a0(param_1);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = uVar3;

    }

  }

  return;

}
