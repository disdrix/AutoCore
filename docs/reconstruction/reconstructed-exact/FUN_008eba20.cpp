// =============================================================================
// FUN_008eba20
// -----------------------------------------------------------------------------
// Stable ID: aa_008eba20
// Address:   0x008eba20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008eba20 @ 0x008eba20
// Stable ID: aa_008eba20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×37, return×1.
//  - Notable callees: FUN_008eba20.
//  - Return sites: 1.

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

void FUN_008eba20(void)



{

  char cVar1;

  char unaff_BL;

  int *unaff_ESI;

  

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar1 != '\0') {

    if (unaff_ESI[0x19b] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x19b] + 4))();

    }

    if (unaff_ESI[0x19c] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x19c] + 4))();

    }

    if (unaff_ESI[0x19d] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x19d] + 4))(0);

    }

    if (unaff_ESI[0x19e] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x19e] + 4))();

    }

    if (unaff_ESI[0x199] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x199] + 4))();

    }

    if (unaff_ESI[0x165] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x165] + 4))();

    }

    if (unaff_ESI[0x19a] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x19a] + 4))();

    }

    if (unaff_ESI[0x166] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x166] + 4))();

    }

    if (unaff_ESI[0x17f] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x17f] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x180] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x180] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x181] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x181] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x182] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x182] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x183] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x183] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x184] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x184] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x185] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x185] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x186] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x186] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x187] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x187] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x188] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x188] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x189] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x189] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x18a] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x18a] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x18b] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x18b] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x18c] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x18c] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x18d] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x18d] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x18e] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x18e] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[399] != 0) {

      (**(code **)(*(int *)unaff_ESI[399] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[400] != 0) {

      (**(code **)(*(int *)unaff_ESI[400] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x191] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x191] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x192] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x192] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x193] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x193] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x194] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x194] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x195] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x195] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x196] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x196] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x197] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x197] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x198] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x198] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x163] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x163] + 4))(unaff_BL == '\0');

    }

    if (unaff_ESI[0x164] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x164] + 4))(unaff_BL == '\0');

    }

  }

  return;

}
