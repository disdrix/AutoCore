// =============================================================================
// FUN_0058f700
// -----------------------------------------------------------------------------
// Stable ID: aa_0058f700
// Address:   0x0058f700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058f700 @ 0x0058f700
// Stable ID: aa_0058f700
// Embedded strings (evidence for future rename):
//   - "Translucent"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_0058f700, FUN_007522a0, FUN_0096fdf0.
//  - Strings: "Translucent".
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

void __fastcall FUN_0058f700(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  while( true ) {

    iVar1 = *(int *)(*(int *)(param_1 + 0x914) + 0xc0);

    if (iVar1 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(*(int *)(param_1 + 0x914) + 0xc4) - iVar1 >> 2;

    }

    if (iVar1 <= iVar2) break;

    FUN_0096fdf0();

    FUN_007522a0("Translucent");

    iVar2 = iVar2 + 1;

  }

  return;

}
