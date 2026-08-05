// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_00423170
// -----------------------------------------------------------------------------
// Stable ID: aa_00423170
// Callee of Mission_bActiveObjectiveOverride (+10 other named callers)
// Address:   0x00423170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+10 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0041d7b0, FUN_00423170, FUN_00437cd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+10 other named callers)
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

void __fastcall Named_CalleeOf_Mission_bActiveObjectiveOverride_00423170(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  int *unaff_ESI;

  int *local_4;

  

  local_4 = param_1;

  if ((unaff_ESI[1] != 0) && (puVar1 = (uint32_t /* width from decompiler */ *)*unaff_ESI, puVar1 != (uint32_t /* width from decompiler */ *)0x0)) {

    FUN_00437cd0();

    iVar3 = (**(code **)*puVar1)(puVar1,&DAT_00a860ac,&local_4);

    if (-1 < iVar3) {

      (**(code **)(*local_4 + 0x18))(local_4,unaff_ESI[1],0);

      unaff_ESI[1] = 0;

    }

    FUN_0041d7b0();

  }

  piVar2 = (int *)*unaff_ESI;

  if (piVar2 != (int *)0x0) {

    *unaff_ESI = 0;

    (**(code **)(*piVar2 + 8))(piVar2);

  }

  return;

}
