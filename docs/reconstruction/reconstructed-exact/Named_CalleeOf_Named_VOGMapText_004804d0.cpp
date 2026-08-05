// =============================================================================
// Named_CalleeOf_Named_VOGMapText_004804d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004804d0
// Callee of Named_VOGMapText
// Address:   0x004804d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGMapText: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004804d0, FUN_004805a0, FUN_004809b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOGMapText
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

void __thiscall Named_CalleeOf_Named_VOGMapText_004804d0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 200) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 200))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_004809b0(iVar1,1,param_2,param_1,param_2);

    *(int *)(param_1 + 8) = iVar1 + 200;

    return;

  }

  FUN_004805a0(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

  return;

}
