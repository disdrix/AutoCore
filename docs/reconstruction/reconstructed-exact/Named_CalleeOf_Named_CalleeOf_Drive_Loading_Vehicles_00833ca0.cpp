// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Loading_Vehicles_00833ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00833ca0
// Callee of Named_CalleeOf_Drive_Loading_Vehicles
// Address:   0x00833ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Loading_Vehicles: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0040d1a0, FUN_0076f5f0, FUN_00833390, FUN_00833ca0, fcos, fsin.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Loading_Vehicles
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Drive_Loading_Vehicles_00833ca0(void)



{

  int *piVar1;

  int unaff_ESI;

  float10 fVar2;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_1c = 0.0;

  local_18 = g_flOne;

  local_14 = 0.0;

  FUN_0076f5f0(&local_c,&local_1c);

  fVar2 = (float10)fsin((float10)_DAT_00aaa9e0);

  local_1c = (float)((float10)local_c * fVar2);

  local_18 = (float)((float10)local_8 * fVar2);

  local_14 = (float)((float10)local_4 * fVar2);

  fVar2 = (float10)fcos((float10)_DAT_00aaa9e0);

  local_10 = (float)fVar2;

  FUN_0040d1a0(&local_1c);

  if (*(int *)(unaff_ESI + 0x508) != 0) {

    piVar1 = *(int **)(*(int *)(unaff_ESI + 0x508) + 0x48);

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 0x14))(&local_1c);

    }

    (**(code **)(**(int **)(unaff_ESI + 0x508) + 0x44))();

    FUN_00833390();

  }

  return;

}
