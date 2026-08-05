// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_008ce440
// -----------------------------------------------------------------------------
// Stable ID: aa_008ce440
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x008ce440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, do×1, while×1.
//  - Notable callees: FUN_00581730, FUN_008cd070, FUN_008cd200, FUN_008ce440, FUN_008d80c0.
//  - Return sites: 2.

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

void Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_008ce440(char param_1)



{

  int iVar1;

  int iVar2;

  int unaff_ESI;

  int *unaff_EDI;

  

  if (-1 < unaff_ESI) {

    if (unaff_EDI[unaff_ESI + 0x167] != 0) {

      (**(code **)(*(int *)unaff_EDI[unaff_ESI + 0x167] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)unaff_EDI[unaff_ESI + 0x167] + 0xcc))(0);

      (**(code **)(*(int *)unaff_EDI[unaff_ESI + 0x167] + 0x34c))();

    }

    if (unaff_EDI[unaff_ESI + 0x173] != 0) {

      (**(code **)(*(int *)unaff_EDI[unaff_ESI + 0x173] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)unaff_EDI[unaff_ESI + 0x173] + 0xcc))(0);

      (**(code **)(*(int *)unaff_EDI[unaff_ESI + 0x173] + 0x34c))();

    }

    if ((&DAT_00d1b6dc)[unaff_ESI] == 0) {

      return;

    }

    if ((unaff_EDI[0x151] != 0) && (unaff_EDI[0x151] == (&DAT_00d1b6dc)[unaff_ESI])) {

      FUN_008d80c0(unaff_EDI);

    }

    iVar1 = (&DAT_00d1b6dc)[unaff_ESI];

    if (iVar1 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xfc))();

      FUN_00581730(1);

      (**(code **)(*(int *)((&DAT_00d1b6dc)[unaff_ESI] + 0x40) + 4))();

    }

    if (param_1 != '\0') {

      (**(code **)(*(int *)(*(int *)(*(int *)((&DAT_00d1b6dc)[unaff_ESI] + 4) + 4) + 4 +

                           (&DAT_00d1b6dc)[unaff_ESI]) + 0x2a8))(DAT_00d1b574);

      iVar1 = (&DAT_00d1b6dc)[unaff_ESI];

      if (iVar1 != 0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

      }

      (&DAT_00d1b6dc)[unaff_ESI] = 0;

    }

    iVar2 = 0;

    iVar1 = 0;

    do {

      if ((&DAT_00d1b6dc)[iVar1] != 0) {

        if (iVar2 < iVar1) {

          (&DAT_00d1b6d8)[iVar1] = (&DAT_00d1b6dc)[iVar1];

          (&DAT_00d1b6dc)[iVar1] = 0;

        }

        iVar2 = iVar2 + 1;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < 0xc);

    DAT_00d1a984 = DAT_00d1a984 + -1;

    FUN_008cd200(unaff_EDI);

  }

  DAT_00d1a980 = 0;

  FUN_008cd070();

  (**(code **)(*unaff_EDI + 0x444))();

  return;

}
