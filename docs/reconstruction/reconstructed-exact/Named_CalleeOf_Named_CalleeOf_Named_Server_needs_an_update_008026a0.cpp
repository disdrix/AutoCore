// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_008026a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008026a0
// Callee of Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x008026a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, return×1.
//  - Notable callees: FUN_008026a0, FUN_0088b9e0, memmove.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Server_needs_an_update
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_008026a0(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  

  if ((DAT_00d1b778 != (int *)0x0) &&

     (cVar2 = (**(code **)(*DAT_00d1b778 + 0x3d8))(param_1), cVar2 != '\0')) {

    while ((piVar3 = DAT_00d1b778, DAT_00d1d898 != (uint32_t /* width from decompiler */ *)0x0 &&

           (DAT_00d1d89c - (int)DAT_00d1d898 >> 2 != 0))) {

      piVar3 = (int *)*DAT_00d1d898;

      memmove(DAT_00d1d898,DAT_00d1d898 + 1,(DAT_00d1d89c - (int)(DAT_00d1d898 + 1) >> 2) * 4);

      DAT_00d1d89c = DAT_00d1d89c + -4;

      (**(code **)(*piVar3 + 0x440))();

      (**(code **)(*DAT_00d1b778 + 0xbc))(piVar3);

    }

    while ((piVar3[0x328] != 0 && (piVar3[0x329] - piVar3[0x328] >> 2 != 0))) {

      piVar1 = *(int **)(piVar3[0x329] + -4);

      if ((piVar3[0x328] != 0) && (piVar3[0x329] - piVar3[0x328] >> 2 != 0)) {

        piVar3[0x329] = piVar3[0x329] + -4;

        piVar3 = DAT_00d1b778;

      }

      if (piVar1 != (int *)0x0) {

        cVar2 = (**(code **)(*piVar1 + 0x3d8))();

        if (cVar2 != '\0') {

          (**(code **)(*piVar1 + 0x440))();

        }

        (**(code **)(*DAT_00d1b778 + 0xb0))(piVar1);

        (**(code **)*piVar1)(1);

        piVar3 = DAT_00d1b778;

      }

    }

    if (DAT_00d1b938 != 0) {

      FUN_0088b9e0();

    }

  }

  return;

}
