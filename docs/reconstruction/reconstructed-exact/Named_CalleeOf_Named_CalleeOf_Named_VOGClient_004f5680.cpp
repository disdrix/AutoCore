// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGClient_004f5680
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5680
// Callee of Named_CalleeOf_Named_VOGClient
// Address:   0x004f5680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: FUN_004f5680.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGClient
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOGClient_004f5680(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  char cVar3;

  

  cVar3 = '\0';

  while (((iVar1 = *(int *)(*(int *)(param_1 + 0x260) + cVar3 * 4), iVar1 == 0 ||

          (iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4), *(int *)(iVar2 + 0x164 + iVar1) != param_2))

         || (*(int *)(iVar2 + 0x168 + iVar1) != param_3))) {

    cVar3 = cVar3 + '\x01';

    if ('\x02' < cVar3) {

      return 0;

    }

  }

  return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x260) + cVar3 * 4);

}
