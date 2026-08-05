// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume_00816be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00816be0
// Callee of Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume
// Address:   0x00816be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00816be0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume
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

void Named_CalleeOf_Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume_00816be0(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int *unaff_ESI;

  

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar1 != '\0') {

    if (unaff_ESI[0x205] == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = unaff_ESI[0x206] - unaff_ESI[0x205] >> 2;

    }

    if (in_EAX < iVar2) {

      (**(code **)(**(int **)(unaff_ESI[0x205] + in_EAX * 4) + 0x1d8))(param_1,1,1);

      (**(code **)(**(int **)(unaff_ESI[0x205] + in_EAX * 4) + 0x34c))();

    }

  }

  return;

}
