// =============================================================================
// FUN_0082fe20
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fe20
// Address:   0x0082fe20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082fe20 @ 0x0082fe20
// Stable ID: aa_0082fe20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_0082f810×2, FUN_0082f8d0×2, FUN_0082f9a0×2, FUN_0082fa60×2, FUN_0082fb30×2, FUN_0082fc40×2, FUN_0082fd50×2, FUN_0090d400×2.
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

void __fastcall FUN_0082fe20(int *param_1)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  

  if (param_1[0x130] != 0) {

    FUN_0082d2b0();

    if (((DAT_00d1b6d8 == 0) ||

        (piVar2 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x15e)), piVar2 == (int *)0x0)) ||

       (cVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                            0x298))(piVar2), cVar1 != '\0')) {

      if (param_1[0xac] != 0) {

        FUN_0090d400();

        return;

      }

    }

    else {

      iVar3 = (**(code **)(*piVar2 + 0x210))(0);

      if ((iVar3 == 0) || (iVar3 == DAT_00d1b6d8)) {

        if (param_1[0xac] != 0) {

          FUN_0090d400();

          return;

        }

      }

      else {

        iVar3 = (**(code **)(*param_1 + 0x478))();

        if (iVar3 == 0) {

          FUN_0082f8d0();

          FUN_0082f9a0();

          FUN_0082f810();

          FUN_0082fc40();

          FUN_0082fa60();

          FUN_0082fb30();

          FUN_0082fd50();

          return;

        }

        FUN_0082fd50();

        FUN_0082fb30();

        FUN_0082fa60();

        FUN_0082fc40();

        FUN_0082f810();

        FUN_0082f9a0();

        FUN_0082f8d0();

      }

    }

  }

  return;

}
