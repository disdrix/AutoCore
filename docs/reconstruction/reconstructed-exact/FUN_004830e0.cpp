// =============================================================================
// FUN_004830e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004830e0
// Address:   0x004830e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004830e0 @ 0x004830e0
// Stable ID: aa_004830e0
// Embedded strings (evidence for future rename):
//   - " {0x%x, 0x%x}"
//   - "\n    combined CRCs: stored = 0x%x, computed = 0x%x"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×13, return×7, do×1, goto×1, while×1.
//  - Notable callees: fprintf×3, FUN_00482550, FUN_00482a50, FUN_004830e0, FUN_00485590.
//  - Strings: " {0x%x, 0x%x}"; "\n    combined CRCs: stored = 0x%x, computed = 0x%x".
//  - Return sites: 7.

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

int FUN_004830e0(void)



{

  int *piVar1;

  uint uVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  

  if (in_EAX == 0) {

    return -2;

  }

  piVar1 = *(int **)(in_EAX + 0x20);

  if ((piVar1 == (int *)0x0) || (*piVar1 != in_EAX)) {

    return -2;

  }

  iVar4 = piVar1[1];

  iVar3 = iVar4;

  do {

    if (iVar3 == 1) {

      return -1;

    }

    if (iVar4 == 2) {

      if ((char)piVar1[10] == '\0') {

        FUN_00482550();

      }

      else {

        FUN_00482a50(piVar1);

      }

      if ((piVar1[0x110] != piVar1[0x3e90] + 1) || (piVar1[3] != 0)) {

        return 0;

      }

      uVar2 = piVar1[0x318];

      piVar1[0x318] = ~uVar2;

      if (2 < piVar1[0xc]) {

        fprintf((FILE *)(_iob_exref + 0x40)," {0x%x, 0x%x}",piVar1[0x316],~uVar2);

      }

      if (1 < piVar1[0xc]) {

        fprintf((FILE *)(_iob_exref + 0x40),"]");

      }

      if (piVar1[0x318] != piVar1[0x316]) {

        return -4;

      }

      piVar1[0x319] = ((uint)piVar1[0x319] >> 0x1f | piVar1[0x319] * 2) ^ piVar1[0x318];

      piVar1[1] = 0xe;

LAB_004831cc:

      iVar3 = FUN_00485590(piVar1);

      if (iVar3 == 4) {

        if (2 < piVar1[0xc]) {

          fprintf((FILE *)(_iob_exref + 0x40),"\n    combined CRCs: stored = 0x%x, computed = 0x%x",

                  piVar1[0x317],piVar1[0x319]);

        }

        return (uint)(piVar1[0x319] == piVar1[0x317]) * 8 + -4;

      }

      iVar4 = piVar1[1];

      if (iVar4 != 2) {

        return iVar3;

      }

    }

    else if (9 < iVar4) goto LAB_004831cc;

    iVar3 = piVar1[1];

  } while( true );

}
