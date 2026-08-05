// =============================================================================
// FUN_0082f8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0082f8d0
// Address:   0x0082f8d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082f8d0 @ 0x0082f8d0
// Stable ID: aa_0082f8d0
// Embedded strings (evidence for future rename):
//   - "i_m_int_2d_btn_generic.xml"
//   - "Remove from Ignore"
//   - "Add to Ignore"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00573af0, FUN_0082f8d0.
//  - Strings: "i_m_int_2d_btn_generic.xml"; "Remove from Ignore"; "Add to Ignore".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_0082f8d0(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *piVar3;

  int *unaff_EDI;

  

  if ((*(int *)(in_EAX + 0x6b4) < 1) || (0 < *(int *)(DAT_00d1b6d8 + 0x6b4))) {

    if (DAT_00d1da2c != 0) {

      uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x160))();

      iVar2 = FUN_00573af0(uVar1);

      if (iVar2 != 0) {

        piVar3 = (int *)(**(code **)(*unaff_EDI + 0x444))

                                  ("i_m_int_2d_btn_generic.xml",0,0x1117c,0xffffffff);

        if (piVar3 != (int *)0x0) {

          (**(code **)(*piVar3 + 0x1d8))("Remove from Ignore",1,1);

        }

        unaff_EDI[0x15b] = (int)piVar3;

        return;

      }

    }

    piVar3 = (int *)(**(code **)(*unaff_EDI + 0x444))

                              ("i_m_int_2d_btn_generic.xml",0,0x11179,0xffffffff);

    if (piVar3 != (int *)0x0) {

      (**(code **)(*piVar3 + 0x1d8))("Add to Ignore",1,1);

    }

    unaff_EDI[0x158] = (int)piVar3;

  }

  return;

}
