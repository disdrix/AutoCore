// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0081e500
// -----------------------------------------------------------------------------
// Stable ID: aa_0081e500
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x0081e500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00816860, FUN_00816940, FUN_0081e500.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Attempting_to_open_null_dialog_i
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

void Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0081e500(int param_1)



{

  uint16_t uVar1;

  int *piVar2;

  char cVar3;

  uint uVar4;

  int *piVar5;

  uint local_4;

  

  local_4 = 0;

  piVar5 = (int *)(param_1 + 0xea0);

  do {

    piVar2 = (int *)*piVar5;

    if ((piVar2 != (int *)0x0) && ((byte)local_4 < 0x78)) {

      uVar4 = local_4 & 0xff;

      if ((&DAT_00d1bbee + uVar4 * 0x1a != (uint16_t *)0x0) &&

         (((&DAT_00d1bbf5)[uVar4 * 0x34] != '\0' && ((&DAT_00d1bbf4)[uVar4 * 0x34] == '\0')))) {

        uVar1 = (&DAT_00d1bc18)[uVar4 * 0x1a];

        *(uint16_t *)(piVar2 + 0x206) = (&DAT_00d1bbee)[uVar4 * 0x1a];

        *(uint16_t *)((int)piVar2 + 0x81a) = uVar1;

        cVar3 = (**(code **)(*piVar2 + 0x3d8))();

        if (cVar3 != '\0') {

          FUN_00816940();

        }

        piVar2 = (int *)*piVar5;

        uVar1 = (&DAT_00d1bc1a)[uVar4 * 0x1a];

        *(uint16_t *)(piVar2 + 0x207) = (&DAT_00d1bbf0)[uVar4 * 0x1a];

        *(uint16_t *)((int)piVar2 + 0x81e) = uVar1;

        cVar3 = (**(code **)(*piVar2 + 0x3d8))();

        if (cVar3 != '\0') {

          FUN_00816860();

        }

        (**(code **)(*(int *)*piVar5 + 0x34c))();

      }

    }

    local_4 = local_4 + 1;

    piVar5 = piVar5 + 1;

  } while ((int)local_4 < 0x78);

  return;

}
