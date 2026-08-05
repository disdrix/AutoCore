// =============================================================================
// FUN_00521230
// -----------------------------------------------------------------------------
// Stable ID: aa_00521230
// Address:   0x00521230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521230 @ 0x00521230
// Stable ID: aa_00521230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×4, switch×1.
//  - Notable callees: FUN_004c2ee0×4, FUN_004c2ef0×4, FUN_004c2f00×4, FUN_004c2f10×4, FUN_00521230.
//  - Return sites: 4.

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

void __fastcall FUN_00521230(int param_1)



{

  switch(*(uint8_t *)

          (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x531))

  {

  case 0:

    FUN_004c2ef0(0x14);

    FUN_004c2ee0(0x12);

    FUN_004c2f00(10);

    FUN_004c2f10(0xf);

    return;

  case 1:

    FUN_004c2ef0(10);

    FUN_004c2ee0(0x14);

    FUN_004c2f00(0x12);

    FUN_004c2f10(0xf);

    return;

  case 2:

    FUN_004c2ef0(0xf);

    FUN_004c2ee0(10);

    FUN_004c2f00(0x14);

    FUN_004c2f10(0x12);

    return;

  case 3:

    FUN_004c2ef0(0x12);

    FUN_004c2ee0(10);

    FUN_004c2f00(0xf);

    FUN_004c2f10(0x14);

  }

  return;

}
