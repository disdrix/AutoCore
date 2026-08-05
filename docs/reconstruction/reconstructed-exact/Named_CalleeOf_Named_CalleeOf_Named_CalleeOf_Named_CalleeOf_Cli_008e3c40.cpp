// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008e3c40
// -----------------------------------------------------------------------------
// Stable ID: aa_008e3c40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
// Address:   0x008e3c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0040ed60, FUN_008e3c40, Map_LowerBoundFindByIntKey.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008e3c40(void)



{

  int iVar1;

  int *extraout_EAX;

  int iVar2;

  int unaff_EBX;

  int *unaff_ESI;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ local_10 [2];

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if ((unaff_EDI != (int *)0x0) && (*(int *)(unaff_EDI[0x2a] + 0x38) == 0x1a)) {

    local_10[0] = *(uint32_t /* width from decompiler */ *)(unaff_EDI[0x2a] + 0x34);

    Map_LowerBoundFindByIntKey((void *)(unaff_EBX + 0x7f4),&local_8,local_10,unaff_ESI);

    iVar1 = *extraout_EAX;

    *(int *)(unaff_EBX + 0x800) = iVar1;

    if (iVar1 == *(int *)(unaff_EBX + 0x7f8)) {

      uStack_4 = (**(code **)(*unaff_EDI + 0x25c))();

      local_8 = *(uint32_t /* width from decompiler */ *)(unaff_EDI[0x2a] + 0x34);

      FUN_0040ed60(local_10,&local_8);

      return;

    }

    iVar2 = (**(code **)(*unaff_EDI + 0x25c))();

    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar2;

  }

  return;

}
