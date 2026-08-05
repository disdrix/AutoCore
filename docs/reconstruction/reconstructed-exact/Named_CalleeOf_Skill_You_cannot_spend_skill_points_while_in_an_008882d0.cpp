// =============================================================================
// Named_CalleeOf_Skill_You_cannot_spend_skill_points_while_in_an_008882d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008882d0
// Callee of Skill_You_cannot_spend_skill_points_while_in_an_arena
// Address:   0x008882d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_You_cannot_spend_skill_points_while_in_an: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_008882d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_You_cannot_spend_skill_points_while_in_an_arena
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

void Named_CalleeOf_Skill_You_cannot_spend_skill_points_while_in_an_008882d0(char param_1)



{

  char cVar1;

  int *unaff_ESI;

  int unaff_EDI;

  

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if ((cVar1 != '\0') && ((param_1 != '\0' || (unaff_EDI != unaff_ESI[0x14b])))) {

    unaff_ESI[0x14b] = unaff_EDI;

    if (unaff_EDI == 0) {

      cVar1 = (**(code **)(*(int *)unaff_ESI[0x143] + 0x3d8))();

      if (cVar1 == '\0') {

        (**(code **)(*(int *)unaff_ESI[0x143] + 0x43c))();

        (**(code **)(*(int *)unaff_ESI[0x143] + 4))(1);

      }

      cVar1 = (**(code **)(*(int *)unaff_ESI[0x144] + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*(int *)unaff_ESI[0x144] + 4))(0);

        (**(code **)(*(int *)unaff_ESI[0x144] + 0x440))();

      }

    }

    else if (unaff_EDI == 1) {

      cVar1 = (**(code **)(*(int *)unaff_ESI[0x143] + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*(int *)unaff_ESI[0x143] + 4))(0);

        (**(code **)(*(int *)unaff_ESI[0x143] + 0x440))();

      }

      cVar1 = (**(code **)(*(int *)unaff_ESI[0x144] + 0x3d8))();

      if (cVar1 == '\0') {

        (**(code **)(*(int *)unaff_ESI[0x144] + 0x43c))();

                    /* WARNING: Could not recover jumptable at 0x00888368. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(*(int *)unaff_ESI[0x144] + 4))();

        return;

      }

    }

  }

  return;

}
