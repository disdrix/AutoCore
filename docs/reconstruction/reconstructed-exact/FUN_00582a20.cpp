// =============================================================================
// FUN_00582a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00582a20
// Address:   0x00582a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582a20 @ 0x00582a20
// Stable ID: aa_00582a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004a16d0, FUN_004b7e50, FUN_00512a20, FUN_00582a20.
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

void __fastcall FUN_00582a20(int param_1)



{

  int iVar1;

  

  FUN_00512a20();

  if ((*(int *)(param_1 + -0x7c) != 0) && (*(int *)(param_1 + -0x88) != 0)) {

    iVar1 = FUN_004a16d0(0,1,0xffffffff);

    if (iVar1 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0xf8))

                (iVar1,1,0);

      FUN_004b7e50(0,0,0,0,0,0);

    }

  }

  return;

}
