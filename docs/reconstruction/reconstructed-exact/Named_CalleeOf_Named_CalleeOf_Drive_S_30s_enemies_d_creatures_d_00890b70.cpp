// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_00890b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00890b70
// Callee of Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d
// Address:   0x00890b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00423fe0, FUN_00890710, FUN_00890b70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d
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

void Named_CalleeOf_Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_00890b70(void)



{

  char cVar1;

  int *in_EAX;

  int *unaff_ESI;

  

  if (unaff_ESI != (int *)0x0) {

    cVar1 = (**(code **)(*in_EAX + 0x3d8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*unaff_ESI + 0x440))();

      }

      (**(code **)(*in_EAX + 0xb0))();

    }

    FUN_00423fe0(unaff_ESI);

    FUN_00890710();

  }

  return;

}
