// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_004f5c30
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5c30
// Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
// Address:   0x004f5c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004e9530, FUN_004f5c30, FUN_005a8650.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_004f5c30(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t auStack_20 [28];

  

  if ((*(int *)(param_1 + 600) != 0) && (piVar1 = *(int **)(param_1 + 0x48), piVar1 != (int *)0x0))

  {

    iVar3 = (**(code **)(*piVar1 + 0xc))();

    iVar4 = (**(code **)(*piVar1 + 0xc))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

    uVar5 = FUN_004e9530(auStack_20,iVar3 + 0x90);

    FUN_005a8650(uVar2,iVar4 + 0x80,uVar5);

  }

  return;

}
