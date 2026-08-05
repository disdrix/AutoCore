// =============================================================================
// Named_CalleeOf_Named_VOGClient_004f70f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f70f0
// Callee of Named_VOGClient
// Address:   0x004f70f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004f5680, FUN_004f70f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOGClient
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOGClient_004f70f0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = FUN_004f5680(param_2,param_3);

  if (((((iVar2 == 0) &&

        (((iVar2 = *(int *)(param_1 + 0x270), iVar2 == 0 ||

          (iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4), *(int *)(iVar1 + 0x164 + iVar2) != param_2))

         || (*(int *)(iVar1 + 0x168 + iVar2) != param_3)))) &&

       (((iVar2 = *(int *)(param_1 + 0x26c), iVar2 == 0 ||

         (iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4), *(int *)(iVar1 + 0x164 + iVar2) != param_2)) ||

        (*(int *)(iVar1 + 0x168 + iVar2) != param_3)))) &&

      (((((iVar2 = *(int *)(param_1 + 0x268), iVar2 == 0 ||

          (iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4), *(int *)(iVar1 + 0x164 + iVar2) != param_2))

         || (*(int *)(iVar1 + 0x168 + iVar2) != param_3)) &&

        (((iVar2 = *(int *)(param_1 + 600), iVar2 == 0 ||

          (iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4), *(int *)(iVar1 + 0x164 + iVar2) != param_2))

         || (*(int *)(iVar1 + 0x168 + iVar2) != param_3)))) &&

       (((iVar2 = *(int *)(param_1 + 0x254), iVar2 == 0 ||

         (iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4), *(int *)(iVar1 + 0x164 + iVar2) != param_2)) ||

        (*(int *)(iVar1 + 0x168 + iVar2) != param_3)))))) &&

     (((iVar2 = *(int *)(param_1 + 0x264), iVar2 == 0 ||

       (iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4), *(int *)(iVar1 + 0x164 + iVar2) != param_2)) ||

      (*(int *)(iVar1 + 0x168 + iVar2) != param_3)))) {

    return 0;

  }

  return 1;

}
