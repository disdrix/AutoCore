// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00587970
// -----------------------------------------------------------------------------
// Stable ID: aa_00587970
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x00587970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_005142a0×2, CVOGCharacter_AddCredits, FUN_00513770, FUN_00587970.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00587970(void *param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  

  if ((param_1 != (void *)0x0) && (param_2 != (int *)0x0)) {

    cVar1 = FUN_00513770();

    if ((cVar1 != '\0') && (*(int *)((int)param_1 + 0x250) != 0)) {

      iVar2 = FUN_005142a0();

      if (iVar2 != 0) {

        iVar2 = (**(code **)(*param_2 + 0x25c))();

        iVar3 = FUN_005142a0();

        CVOGCharacter_AddCredits(param_1,(longlong)(iVar3 * iVar2));

        return 1;

      }

    }

  }

  return 0;

}
