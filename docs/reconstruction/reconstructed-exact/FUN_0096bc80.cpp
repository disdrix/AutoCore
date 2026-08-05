// =============================================================================
// FUN_0096bc80
// -----------------------------------------------------------------------------
// Stable ID: aa_0096bc80
// Address:   0x0096bc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096bc80 @ 0x0096bc80
// Stable ID: aa_0096bc80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0043fd70, FUN_0046c1b0, FUN_00745ea0, FUN_0096bc80.
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

void __fastcall FUN_0096bc80(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = DAT_00d1f04c;

  if (DAT_00d1f04c != 0) {

    FUN_0046c1b0();

    if (local_4 != *(int *)(iVar1 + 8)) {

      FUN_0043fd70(local_4);

    }

  }

  if (*(int *)(param_1 + 0x48) != 0) {

    FUN_00745ea0();

    return;

  }

  if ((uint32_t /* width from decompiler */ *)(param_1 + -4) != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)(param_1 + -4))(1);

  }

  return;

}
