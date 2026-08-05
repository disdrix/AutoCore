// =============================================================================
// FUN_00914c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00914c20
// Address:   0x00914c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00914c20 @ 0x00914c20
// Stable ID: aa_00914c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005081d0, FUN_00914c20, VehicleEntity_SetLongitudinalInput.
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

void FUN_00914c20(void)



{

  int in_EAX;

  

  if ((DAT_00d1a860 != '\0') && (*(int *)(in_EAX + 0xc70) != 0)) {

    *(uint8_t *)(in_EAX + 0xa35) = 0;

    FUN_005081d0();

    if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {

      VehicleEntity_SetLongitudinalInput(0);

    }

  }

  return;

}
