// =============================================================================
// Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d_00803050
// -----------------------------------------------------------------------------
// Stable ID: aa_00803050
// Callee of Drive_S_30s_enemies_d_creatures_d_vehicles_d
// Address:   0x00803050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_S_30s_enemies_d_creatures_d_vehicles_d: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00803050, FUN_008908c0, FUN_00891da0, FUN_00892430.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_S_30s_enemies_d_creatures_d_vehicles_d
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

void Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d_00803050(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  

  piVar1 = *(int **)(in_EAX + 0x10ec);

  if (piVar1 != (int *)0x0) {

    FUN_00892430(piVar1,param_1,param_2,1);

    FUN_00891da0(param_1,param_2,param_3);

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 != '\0') {

      FUN_008908c0(piVar1);

    }

    (**(code **)(*piVar1 + 0x94))();

  }

  return;

}
