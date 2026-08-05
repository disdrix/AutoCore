// =============================================================================
// FUN_00426180
// -----------------------------------------------------------------------------
// Stable ID: aa_00426180
// Address:   0x00426180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00426180 @ 0x00426180
// Stable ID: aa_00426180
// Embedded strings (evidence for future rename):
//   - "LogConnectionProtocol"
//   - "send ping %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00424d10, FUN_00425890, FUN_00426180, FUN_004267c0, FUN_0042bc80, FUN_00783850, FUN_00783aa0, FUN_00783b60.
//  - Strings: "LogConnectionProtocol"; "send ping %d".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00426180(void)



{

  int unaff_EDI;

  

  FUN_00425890(unaff_EDI,1);

  if (*(int *)(unaff_EDI + 0x1b4) != 0) {

    FUN_00783850(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x94),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x8c),1,0);

    FUN_0042bc80(5,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1b4));

  }

  if ((_DAT_00d20c08 & 1) == 0) {

    _DAT_00d20c08 = _DAT_00d20c08 | 1;

    DAT_00d20c04 = FUN_00783b60("LogConnectionProtocol");

  }

  if (*(char *)(DAT_00d20c04 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20c04;

    FUN_00783aa0("send ping %d",*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x94));

    DAT_00d179a0 = 0;

  }

  FUN_004267c0();

  FUN_00424d10();

  return;

}
