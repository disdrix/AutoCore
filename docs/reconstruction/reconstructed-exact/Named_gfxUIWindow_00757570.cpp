// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, for×1.
//  - Notable callees: FUN_00757570, FUN_009701d0, FUN_00989e00, vog_LogMessage.
//  - Strings: "PalUIDefault.fx"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp"; "Failed to create Effect for User Interface"; "WindowPosDepth".
//  - Return sites: 3.

// =============================================================================
// Named_gfxUIWindow_00757570
// -----------------------------------------------------------------------------
// Stable ID: aa_00757570
// Address:   0x00757570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxUIWindow"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxUIWindow_00757570(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint8_t local_4 [4];

  

  if (DAT_00d1ecac == 0) {

    FUN_00989e00(local_4,"PalUIDefault.fx");

    iVar3 = FUN_009701d0(local_4);

    iVar2 = DAT_00d1f05c;

    if (iVar3 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp",0x59d,3,

                     "Failed to create Effect for User Interface");

      return 0xffffffff;

    }

    if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

      DAT_00d0dfe0 = 0;

    }

    else {

      piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

      DAT_00d0dfe0 = (**(code **)(*piVar1 + 0x24))(piVar1,0,"WindowPosDepth");

    }

    if (*(int *)(*(int *)(iVar2 + 4) + 0xc) == 0) {

      DAT_00d0dfd4 = 0;

    }

    else {

      piVar1 = *(int **)(*(int *)(iVar2 + 4) + 0xc);

      DAT_00d0dfd4 = (**(code **)(*piVar1 + 0x24))(piVar1,0,"ViewSizeDepthScale");

    }

    if (*(int *)(*(int *)(iVar2 + 4) + 0xc) == 0) {

      DAT_00d0dfd8 = 0;

    }

    else {

      piVar1 = *(int **)(*(int *)(iVar2 + 4) + 0xc);

      DAT_00d0dfd8 = (**(code **)(*piVar1 + 0x24))(piVar1,0,"AlphaBlend");

    }

    if (*(int *)(*(int *)(iVar2 + 4) + 0xc) == 0) {

      DAT_00d0dfdc = 0;

      return 0;

    }

    piVar1 = *(int **)(*(int *)(iVar2 + 4) + 0xc);

    DAT_00d0dfdc = (**(code **)(*piVar1 + 0x24))(piVar1,0,"WriteMask");

  }

  return 0;

}
