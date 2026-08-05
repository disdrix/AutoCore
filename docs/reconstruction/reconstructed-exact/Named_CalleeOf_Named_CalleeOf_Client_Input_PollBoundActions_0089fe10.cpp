// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_0089fe10
// -----------------------------------------------------------------------------
// Stable ID: aa_0089fe10
// Callee of Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x0089fe10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: CONCAT31, FUN_0089fe10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_PollBoundActions
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_0089fe10(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = (int *)(param_1 + 0x63c);

  while ((*piVar2 == 0 || (*(char *)(*piVar2 + 0x4fc) == '\0'))) {

    iVar1 = iVar1 + 1;

    piVar2 = piVar2 + 1;

    if (9 < iVar1) {

      return CONCAT31((int3)((uint)iVar1 >> 8),0xff);

    }

  }

  return iVar1;

}
