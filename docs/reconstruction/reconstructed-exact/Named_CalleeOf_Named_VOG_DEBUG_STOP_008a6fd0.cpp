// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_008a6fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a6fd0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x008a6fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_008a6fd0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_008a6fd0(char param_1)



{

  int iVar1;

  int *piVar2;

  int *unaff_ESI;

  

  if (param_1 != '\0') {

    if (unaff_ESI[0x153] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x153] + 0xcc))(1);

    }

    if (unaff_ESI[0x152] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x152] + 0xcc))(1);

    }

    if (unaff_ESI[0xac] != 0) {

      iVar1 = (**(code **)(*(int *)unaff_ESI[0xac] + 0x34))();

      if (iVar1 != 0) {

        piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0xac] + 0x34))();

        (**(code **)(*piVar2 + 0x3bc))();

      }

    }

                    /* WARNING: Could not recover jumptable at 0x008a7045. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*unaff_ESI + 0x3bc))();

    return;

  }

  if (unaff_ESI[0x153] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x153] + 0xcc))(0);

  }

  if (unaff_ESI[0x152] != 0) {

                    /* WARNING: Could not recover jumptable at 0x008a707d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*(int *)unaff_ESI[0x152] + 0xcc))();

    return;

  }

  return;

}
