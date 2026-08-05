// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxView_0043f410
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f410
// Callee of Named_CalleeOf_Named_gfxView
// Address:   0x0043f410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0043f410, FUN_0074f200.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxView
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxView_0043f410(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *in_EAX;

  int unaff_EBX;

  

  iVar2 = DAT_00d1f614;

  if (DAT_00d1f614 != 0) {

    piVar1 = (int *)(DAT_00d1f614 + 0xd4 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

    *piVar1 = *piVar1 + 1;

    piVar1 = (int *)(iVar2 + 0xd8 + *(int *)(iVar2 + 0xc4) * 0x4c);

    *piVar1 = *piVar1 + 1;

  }

  if (unaff_EBX == 0) {

    FUN_0074f200(*(uint32_t /* width from decompiler */ *)(*in_EAX + 0xc));

  }

  iVar2 = *(int *)(*in_EAX + 8);

  iVar3 = *(int *)(iVar2 + 0x28);

  if (-1 < *(int *)(&DAT_00afe00c + iVar3 * 0xc)) {

    (**(code **)(**(int **)(iVar2 + 0xc) + 0x108))(*(int **)(iVar2 + 0xc));

  }

  (**(code **)(**(int **)(iVar2 + 0xc) + 0x100))(*(int **)(iVar2 + 0xc));

  *(int *)(&DAT_00afe00c + iVar3 * 0xc) = unaff_EBX;

  return;

}
