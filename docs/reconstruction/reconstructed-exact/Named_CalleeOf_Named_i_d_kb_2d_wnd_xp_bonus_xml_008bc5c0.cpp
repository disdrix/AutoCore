// =============================================================================
// Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml_008bc5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008bc5c0
// Callee of Named_i_d_kb_2d_wnd_xp_bonus_xml
// Address:   0x008bc5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_i_d_kb_2d_wnd_xp_bonus_xml: progression/economy helper. Evidence string: "Killing Spree!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Killing Spree!"
//   - "Convoy - Killing Spree!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×1.
//  - Notable callees: CONCAT13×2, FUN_00574780×2, FUN_007a69d0×2, FUN_007a6de0×2, FUN_008bc5c0.
//  - Strings: "Killing Spree!"; "Convoy - Killing Spree!".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_i_d_kb_2d_wnd_xp_bonus_xml
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

void Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml_008bc5c0(void)



{

  int iVar1;

  int unaff_ESI;

  char *pcVar2;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  if ((*(int *)(unaff_ESI + 0x518) != 0) && (DAT_00d1b6d8 != 0)) {

    if (*(char *)(unaff_ESI + 0x514) != '\0') {

      if (*(int *)(DAT_00d1b6d8 + 0xcb0) == 0) {

LAB_008bc601:

        iVar1 = **(int **)(unaff_ESI + 0x518);

        uStack_c = 1;

        uStack_10 = 1;

        uStack_14 = 0xffffffff;

        pcVar2 = "Killing Spree!";

        FUN_007a69d0("Killing Spree!");

        uStack_14 = FUN_007a6de0(pcVar2);

        (**(code **)(iVar1 + 0x1d8))();

        iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x164))(1);

        uStack_14 = CONCAT13(*(uint8_t *)(iVar1 + 3),0xff8000);

        (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x15c))(1,&uStack_14);

        (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x34c))();

        *(uint8_t *)(unaff_ESI + 0x514) = 0;

        return;

      }

      uStack_c = 0x8bc5f8;

      iVar1 = FUN_00574780();

      if (iVar1 < 2) goto LAB_008bc601;

      if (*(char *)(unaff_ESI + 0x514) != '\0') {

        return;

      }

    }

    if (*(int *)(DAT_00d1b6d8 + 0xcb0) != 0) {

      uStack_c = 0x8bc6a6;

      iVar1 = FUN_00574780();

      if (1 < iVar1) {

        iVar1 = **(int **)(unaff_ESI + 0x518);

        uStack_c = 1;

        uStack_10 = 1;

        uStack_14 = 0xffffffff;

        pcVar2 = "Convoy - Killing Spree!";

        FUN_007a69d0("Convoy - Killing Spree!");

        uStack_14 = FUN_007a6de0(pcVar2);

        (**(code **)(iVar1 + 0x1d8))();

        iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x164))(1);

        uStack_14 = CONCAT13(*(uint8_t *)(iVar1 + 3),0xffe400);

        (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x15c))(1,&uStack_14);

        (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x34c))();

        *(uint8_t *)(unaff_ESI + 0x514) = 1;

      }

    }

  }

  return;

}
