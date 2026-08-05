// =============================================================================
// Named_CalleeOf_CVOGCharacter_SearchAutoMissions_00786990
// -----------------------------------------------------------------------------
// Stable ID: aa_00786990
// Callee of CVOGCharacter_SearchAutoMissions
// Address:   0x00786990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCharacter_SearchAutoMissions: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007866e0×2, FUN_00780690, FUN_00786990, __alldiv.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGCharacter_SearchAutoMissions
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

void __fastcall Named_CalleeOf_CVOGCharacter_SearchAutoMissions_00786990(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (*(char *)(param_1 + 0x175) != '\0') {

    iVar1 = FUN_007866e0(param_1);

    iVar1 = *(int *)(*(int *)(param_1 + 0x4c) + 8 + iVar1 * 0xc);

    FUN_00780690();

    iVar2 = *(int *)(iVar1 + 4);

    iVar2 = __alldiv(*(uint32_t /* width from decompiler */ *)(iVar2 + 8),*(uint32_t /* width from decompiler */ *)(iVar2 + 0xc),

                     *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x14));

    *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + iVar2;

    iVar1 = *(int *)(iVar1 + 8);

    if (iVar1 != 0) {

      iVar2 = FUN_007866e0(param_1);

      *(int *)(*(int *)(param_1 + 0x4c) + iVar2 * 0xc + 8) = iVar1;

    }

  }

  return;

}
