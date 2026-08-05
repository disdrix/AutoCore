// =============================================================================
// Named_CalleeOf_Named_assCatalog_007450b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007450b0
// Callee of Named_assCatalog
// Address:   0x007450b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assCatalog: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×12, return×5, do×2, while×2.
//  - Notable callees: FUN_0043b9e0×2, FUN_0044db20×2, FUN_0044db40×2, FUN_0075d530×2, FUN_0044e1a0, FUN_00744d10, FUN_007450b0.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_assCatalog
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

void Named_CalleeOf_Named_assCatalog_007450b0(int param_1,int *param_2,int *param_3)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  uint8_t local_40 [8];

  uint8_t local_38 [56];

  

  FUN_0044db20(param_3);

  FUN_0044e1a0();

  FUN_0044db40(local_40);

  piVar2 = param_3;

  FUN_0044db20(param_2);

  FUN_0044db40(local_38);

  piVar4 = *(int **)(param_1 + 0x50);

  piVar1 = *(int **)(param_1 + 0x54);

  piVar3 = piVar4;

  if (piVar4 != piVar1) {

    do {

      if (*piVar3 == *param_2) break;

      piVar3 = piVar3 + 1;

    } while (piVar3 != piVar1);

  }

  if (piVar4 != piVar1) {

    do {

      if (*piVar4 == *piVar2) break;

      piVar4 = piVar4 + 1;

    } while (piVar4 != piVar1);

  }

  if (piVar3 != piVar1) {

    if (piVar4 == piVar1) {

      FUN_00744d10(&param_2,piVar3);

      return;

    }

    if (piVar3 != piVar1) {

      return;

    }

  }

  if (piVar4 == piVar1) {

    FUN_0043b9e0();

    if (DAT_00d1f050 != 0) {

      FUN_0075d530();

    }

  }

  else {

    if (piVar3 != piVar1) {

      return;

    }

    if (piVar4 == piVar1) {

      return;

    }

  }

  FUN_0043b9e0();

  if (DAT_00d1f050 != 0) {

    FUN_0075d530();

  }

  return;

}
