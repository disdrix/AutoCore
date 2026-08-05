// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_00422d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00422d10
// Callee of Named_CalleeOf_Mission_bActiveObjectiveOverride
// Address:   0x00422d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0041d7b0, FUN_00422d10, FUN_00422d70, FUN_00437cd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_bActiveObjectiveOverride
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_00422d10(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ unaff_ESI;

  int *piVar2;

  uint32_t /* width from decompiler */ *local_4;

  

  local_4 = param_1;

  iVar1 = FUN_00422d70(in_EAX);

  if (-1 < iVar1) {

    FUN_00437cd0();

    piVar2 = (int *)&DAT_00a85fec;

    iVar1 = (*(code *)**(uint32_t /* width from decompiler */ **)*param_1)((uint32_t /* width from decompiler */ *)*param_1,&DAT_00a85fec,&local_4);

    if (-1 < iVar1) {

      iVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2,local_4,unaff_ESI);

    }

    FUN_0041d7b0();

  }

  return iVar1;

}
