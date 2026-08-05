// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Loading_Vehicles_00833d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00833d50
// Callee of Named_CalleeOf_Drive_Loading_Vehicles (+1 other named callers)
// Address:   0x00833d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Loading_Vehicles: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Drive_Loading_Vehicles (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0076c4d0, FUN_00833d50, Vehicle_SetWheelset.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Loading_Vehicles (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Drive_Loading_Vehicles_00833d50(void)



{

  int iVar1;

  int unaff_EDI;

  undefined **local_8;

  int local_4;

  

  iVar1 = *(int *)(unaff_EDI + 0x2a8);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x50c) = 0;

  if (iVar1 != 0) {

    *(uint8_t *)(iVar1 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x40);

    FUN_0076c4d0();

    local_8 = &PTR_LAB_00a9f4d8;

    local_4 = iVar1;

    (**(code **)(**(int **)(iVar1 + 8) + 0x20))(&local_8);

    (**(code **)(**(int **)(iVar1 + 8) + 0x10))(0);

  }

  if (*(int *)(unaff_EDI + 0x508) != 0) {

    iVar1 = *(int *)(*(int *)(unaff_EDI + 0x508) + 600);

    if (iVar1 != 0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

      Vehicle_SetWheelset(0);

    }

    iVar1 = *(int *)(unaff_EDI + 0x508);

    if (iVar1 != 0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x508) = 0;

  }

  return;

}
