// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00756c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00756c90
// Callee of Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x00756c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1.
//  - Notable callees: FUN_00456960, FUN_00756c90, memmove.
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00756c90(void)



{

  int iVar1;

  int *_Dst;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 0x88);

  if (iVar1 == 0) {

    return 0xffffffff;

  }

  if ((*(int *)(iVar1 + 0x94) == 0) || (*(int *)(iVar1 + 0x98) - *(int *)(iVar1 + 0x94) >> 2 != 1))

  {

    for (_Dst = *(int **)(iVar1 + 0x94); _Dst != *(int **)(iVar1 + 0x98); _Dst = _Dst + 1) {

      if (*_Dst == unaff_EDI) {

        memmove(_Dst,_Dst + 1,(*(int *)(iVar1 + 0x98) - (int)(_Dst + 1) >> 2) * 4);

        *(int *)(iVar1 + 0x98) = *(int *)(iVar1 + 0x98) + -4;

        break;

      }

    }

    FUN_00456960(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x88) + 0x94));

  }

  return 0;

}
