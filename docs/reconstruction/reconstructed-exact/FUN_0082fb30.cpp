// =============================================================================
// FUN_0082fb30
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fb30
// Address:   0x0082fb30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082fb30 @ 0x0082fb30
// Stable ID: aa_0082fb30
// Embedded strings (evidence for future rename):
//   - "i_m_int_2d_btn_generic.xml"
//   - "Invite To Convoy"
//   - "Kick From Convoy"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00574880×2, FUN_005749d0, FUN_0082fb30.
//  - Strings: "i_m_int_2d_btn_generic.xml"; "Invite To Convoy"; "Kick From Convoy".
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

void __fastcall FUN_0082fb30(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  int *unaff_ESI;

  

  if ((*(int *)(param_2 + 0x6b4) < 1) || (0 < *(int *)(DAT_00d1b6d8 + 0x6b4))) {

    if ((*(int *)(DAT_00d1b6d8 + 0xcb0) == 0) || (cVar1 = FUN_005749d0(param_2), cVar1 == '\0')) {

      piVar2 = (int *)(**(code **)(*unaff_ESI + 0x444))

                                ("i_m_int_2d_btn_generic.xml",0,0x11171,0xffffffff);

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 0x1d8))("Invite To Convoy",1,1);

      }

      unaff_ESI[0x150] = (int)piVar2;

      if (((piVar2 != (int *)0x0) && (*(int *)(DAT_00d1b6d8 + 0xcb0) != 0)) &&

         (iVar3 = FUN_00574880(), iVar3 != DAT_00d1b6d8)) {

        (**(code **)(*(int *)unaff_ESI[0x150] + 0xd4))(0);

      }

    }

    else {

      piVar2 = (int *)(**(code **)(*unaff_ESI + 0x444))

                                ("i_m_int_2d_btn_generic.xml",0,0x11172,0xffffffff);

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 0x1d8))("Kick From Convoy",1,1);

      }

      unaff_ESI[0x151] = (int)piVar2;

      if ((piVar2 != (int *)0x0) && (iVar3 = FUN_00574880(), iVar3 != DAT_00d1b6d8)) {

        (**(code **)(*(int *)unaff_ESI[0x151] + 0xd4))(0);

        return;

      }

    }

  }

  return;

}
