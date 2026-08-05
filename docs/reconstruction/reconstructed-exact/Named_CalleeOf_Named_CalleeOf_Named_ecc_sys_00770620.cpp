// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770620
// -----------------------------------------------------------------------------
// Stable ID: aa_00770620
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00770620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_00770620.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770620(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  iVar1 = *param_2;

  if (iVar1 != 0) {

    iVar2 = iVar1 * 0x1c + -0x1c;

    for (uVar3 = *(uint *)(param_2[3] + -4 + iVar1 * 4); uVar3 != 0; uVar3 = uVar3 >> 1) {

      iVar2 = iVar2 + 1;

    }

    return iVar2;

  }

  return 0;

}
