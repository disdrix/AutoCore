// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_004bfd10
// -----------------------------------------------------------------------------
// Stable ID: aa_004bfd10
// Callee of Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect
// Address:   0x004bfd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×2, while×2.
//  - Notable callees: FUN_004bfd10, FUN_005c6720.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_004bfd10(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int *piVar3;

  uint uVar4;

  int *piVar5;

  

  uVar4 = 0;

  piVar3 = (int *)(param_1 + 8);

  do {

    if (piVar3[1] != 0) {

      piVar5 = *(int **)*piVar3;

      if (piVar5 != (int *)*piVar3) {

        do {

          puVar1 = (uint32_t /* width from decompiler */ *)piVar5[2];

          cVar2 = FUN_005c6720(param_2);

          if (cVar2 != '\0') {

            if (piVar5 == *(int **)(param_1 + 8 + uVar4 * 0xc)) {

              if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

                (**(code **)*puVar1)(1);

              }

              return 1;

            }

            *(int *)piVar5[1] = *piVar5;

            *(int *)(*piVar5 + 4) = piVar5[1];

                    /* WARNING: Subroutine does not return */

            operator_delete(piVar5);

          }

          piVar5 = (int *)*piVar5;

        } while (piVar5 != (int *)*piVar3);

      }

    }

    uVar4 = uVar4 + 1;

    piVar3 = piVar3 + 3;

  } while (uVar4 < 9);

  return 0;

}
