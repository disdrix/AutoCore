// =============================================================================
// FUN_00915670
// -----------------------------------------------------------------------------
// Stable ID: aa_00915670
// Address:   0x00915670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00915670 @ 0x00915670
// Stable ID: aa_00915670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004f3700, FUN_005081d0, FUN_00915670, VehicleEntity_PushDriveAxesToController, VehicleEntity_SetHandbrake.
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

void FUN_00915670(void)



{

  int unaff_EDI;

  

  if (((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

     (*(char *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x101) == '\0')) {

    *(uint8_t *)(unaff_EDI + 0xa31) = 1;

    VehicleEntity_SetHandbrake(1);

    if ((DAT_00d1a860 == '\0') && (*(char *)(*(int *)(unaff_EDI + 0xc70) + 0x21) == '\0')) {

      FUN_005081d0();

    }

    FUN_004f3700();

    if ((DAT_00d1a860 == '\0') && (DAT_00d1d866 == '\0')) {

      *(uint8_t *)(unaff_EDI + 0xa32) = 0;

    }

    VehicleEntity_PushDriveAxesToController();

    return;

  }

  return;

}
