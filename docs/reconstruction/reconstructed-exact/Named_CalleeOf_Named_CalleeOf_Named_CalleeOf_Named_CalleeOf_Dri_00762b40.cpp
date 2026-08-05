// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Dri_00762b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00762b40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle
// Address:   0x00762b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: memmove×2, FUN_00762b40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Dri_00762b40(int param_1,int param_2,char param_3,char param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int *piVar3;

  

  if ((param_3 != '\0') && (piVar2 = *(int **)(param_1 + 0xc0), piVar2 != *(int **)(param_1 + 0xc4))

     ) {

    piVar3 = piVar2 + 1;

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)*piVar2;

      if (puVar1[0x23] == param_2) {

        if (*(int *)(param_1 + 0x94) != 0) {

          (**(code **)(**(int **)(param_1 + 0x94) + 0x24))(puVar1);

        }

        (**(code **)*puVar1)(1);

        memmove(piVar2,piVar3,(*(int *)(param_1 + 0xc4) - (int)piVar3 >> 2) * 4);

        *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -4;

      }

      else {

        piVar2 = piVar2 + 1;

        piVar3 = piVar3 + 1;

      }

    } while (piVar2 != *(int **)(param_1 + 0xc4));

  }

  if ((param_4 != '\0') && (piVar2 = *(int **)(param_1 + 0xd0), piVar2 != *(int **)(param_1 + 0xd4))

     ) {

    piVar3 = piVar2 + 1;

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)*piVar2;

      if (puVar1[0x23] == param_2) {

        if (*(int *)(param_1 + 0x94) != 0) {

          (**(code **)(**(int **)(param_1 + 0x94) + 0x28))(puVar1);

        }

        (**(code **)*puVar1)(1);

        memmove(piVar2,piVar3,(*(int *)(param_1 + 0xd4) - (int)piVar3 >> 2) * 4);

        *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + -4;

      }

      else {

        piVar2 = piVar2 + 1;

        piVar3 = piVar3 + 1;

      }

    } while (piVar2 != *(int **)(param_1 + 0xd4));

  }

  return;

}
