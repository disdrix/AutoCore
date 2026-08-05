// =============================================================================
// FUN_00523200
// -----------------------------------------------------------------------------
// Stable ID: aa_00523200
// Address:   0x00523200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00523200 @ 0x00523200
// Stable ID: aa_00523200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_00765550×7, FUN_00521130, FUN_00523200.
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

void __fastcall FUN_00523200(int param_1)



{

  if (*(int *)(param_1 + 0x48) != 0) {

    FUN_00521130();

    if (*(int *)(param_1 + 0x680) != 0) {

      FUN_00765550(3,*(int *)(param_1 + 0x680),1,1);

    }

    if (*(int *)(param_1 + 0x688) != 0) {

      FUN_00765550(4,*(int *)(param_1 + 0x688),1,1);

    }

    if (*(int *)(param_1 + 0x68c) != 0) {

      FUN_00765550(0x22,*(int *)(param_1 + 0x68c),1,1);

    }

    if (*(int *)(param_1 + 0x690) != 0) {

      FUN_00765550(0x21,*(int *)(param_1 + 0x690),1,1);

    }

    if (*(int *)(param_1 + 0x694) != 0) {

      FUN_00765550(0x29,*(int *)(param_1 + 0x694),1,1);

    }

    if (*(int *)(param_1 + 0x698) != 0) {

      FUN_00765550(0x28,*(int *)(param_1 + 0x698),1,1);

    }

    if (*(int *)(param_1 + 0x69c) != 0) {

      FUN_00765550(0x2a,*(int *)(param_1 + 0x69c),1,1);

    }

  }

  return;

}
