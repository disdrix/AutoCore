// =============================================================================
// FUN_00883340
// -----------------------------------------------------------------------------
// Stable ID: aa_00883340
// Address:   0x00883340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00883340 @ 0x00883340
// Stable ID: aa_00883340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00882da0, FUN_00883340.
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

void __fastcall FUN_00883340(int *param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    if ((DAT_00d1b6d8 == 0) || (*(char *)(DAT_00d1b644 + 0xf5) != '\0')) {

      param_1[0x146] = 0;

    }

    else {

      param_1[0x146] = *(int *)(DAT_00d1b6d8 + 0xd44);

    }

    iVar2 = 0;

    piVar3 = param_1 + 0x150;

    do {

      if (*piVar3 != 0) {

        if (iVar2 == param_1[0x146]) {

          (**(code **)(*(int *)*piVar3 + 0x3c8))(1);

        }

        else {

          (**(code **)(*(int *)*piVar3 + 0x3c8))(0,0);

        }

        (**(code **)(*(int *)*piVar3 + 0x34c))();

      }

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar2 < 4);

    FUN_00882da0();

  }

  return;

}
