// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster_00466df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00466df0
// Callee of Named_CalleeOf_Named_anmAnimMaster
// Address:   0x00466df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0045cce0, FUN_00466df0, FUN_00466ea0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_anmAnimMaster
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster_00466df0(uint param_1)



{

  int iVar1;

  uint uVar2;

  int unaff_EBX;

  

  iVar1 = *(int *)(unaff_EBX + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (*(int *)(unaff_EBX + 8) - iVar1) / 0x1c;

  }

  if (uVar2 < param_1) {

    FUN_00466ea0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&stack0x00000004);

    return;

  }

  if ((iVar1 != 0) && (param_1 < (uint)((*(int *)(unaff_EBX + 8) - iVar1) / 0x1c))) {

    FUN_0045cce0(unaff_EBX,&stack0x00000004,iVar1 + param_1 * 0x1c,*(int *)(unaff_EBX + 8));

  }

  return;

}
