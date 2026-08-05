// =============================================================================
// FUN_00804c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00804c20
// Address:   0x00804c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804c20 @ 0x00804c20
// Stable ID: aa_00804c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0048a16c, FUN_00804c20, InterlockedDecrement.
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

void __fastcall FUN_00804c20(int *param_1)



{

  LONG LVar1;

  

  (**(code **)(*param_1 + 0x84))(param_1[0x22]);

  (**(code **)(*param_1 + 0x88))(param_1[0x21]);

  LVar1 = InterlockedDecrement((LONG *)&DAT_00d17938);

  if (LVar1 == 0) {

    FUN_0048a16c();

    return;

  }

  return;

}
