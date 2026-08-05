// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008cf850
// -----------------------------------------------------------------------------
// Stable ID: aa_008cf850
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008cf850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008cf850, ROUND.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
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

void __thiscall Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008cf850(int *param_1,int param_2)



{

  int iVar1;

  int *unaff_ESI;

  float10 fVar2;

  int iVar3;

  

  if ((param_1 != (int *)0x0) && (unaff_ESI != (int *)0x0)) {

    fVar2 = (float10)(**(code **)(*param_1 + 0x458))(param_1);

    iVar3 = (int)ROUND((float)(fVar2 * (float10)param_2 + (float10)DAT_00aaa664));

    iVar1 = (**(code **)(*unaff_ESI + 0x218))();

    if (iVar1 != iVar3) {

      (**(code **)(*unaff_ESI + 0x214))(iVar3);

      (**(code **)(*unaff_ESI + 0x34c))();

    }

  }

  return;

}
