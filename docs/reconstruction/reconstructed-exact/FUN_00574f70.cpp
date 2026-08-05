// =============================================================================
// FUN_00574f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00574f70
// Address:   0x00574f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00574f70 @ 0x00574f70
// Stable ID: aa_00574f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, goto×3, do×2, while×2.
//  - Notable callees: FUN_00785ca0×2, FUN_00517680, FUN_00574f70.
//  - Return sites: 3.

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

uint __fastcall FUN_00574f70(int param_1)



{

  uint uVar1;

  int *piVar2;

  uint uVar3;

  

  uVar3 = *(uint *)(param_1 + 0x194);

  if (((int)uVar3 < 0) || (0x2800 < (int)uVar3)) {

    return uVar3 & 0xffffff00;

  }

  uVar3 = 0;

  piVar2 = (int *)(param_1 + 0x1a0);

  do {

    if ((piVar2[-2] & piVar2[-1]) != 0xffffffff) {

      uVar1 = 0;

      if (*piVar2 == 0) goto LAB_00574ffa;

      uVar1 = FUN_00785ca0(*piVar2);

      if ((char)uVar1 != '\0') goto LAB_00574ffa;

    }

    uVar3 = uVar3 + 1;

    piVar2 = piVar2 + 4;

  } while (uVar3 < 4);

  piVar2 = (int *)**(int **)(param_1 + 0x1e0);

  if (piVar2 != *(int **)(param_1 + 0x1e0)) {

    do {

      if ((piVar2[2] & piVar2[3]) != 0xffffffff) {

        uVar1 = 0;

        if (piVar2[4] == 0) {

LAB_00574ffa:

          return uVar1 & 0xffffff00;

        }

        uVar1 = FUN_00785ca0(piVar2[4]);

        if ((char)uVar1 != '\0') goto LAB_00574ffa;

      }

      piVar2 = (int *)*piVar2;

    } while (piVar2 != (int *)*(int *)(param_1 + 0x1e0));

  }

  uVar3 = FUN_00517680();

  return uVar3;

}
